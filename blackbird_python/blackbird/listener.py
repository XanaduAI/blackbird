# Copyright 2019 Xanadu Quantum Technologies Inc.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# pylint: disable=too-many-return-statements,too-many-branches,too-many-instance-attributes
"""
Python Blackbird Listener
=========================

**Module name:** `blackbird.listener`

.. currentmodule:: blackbird.listener

This module contains the main Blackbird listener,
:class:`~.BlackbirdListener`. It inherits from the class :class:`.blackbirdListener`
contained in the file ``blackbirdListener.py``, which is autogenerated
by ANTLR4.

In addition, a small utility function, which automates the parsing of a
Blackbird script and returns the completed listener, is included.

Summary
-------

.. autosummary::
    PYTHON_TYPES
    NUMPY_TYPES
    RegRefTransform
    BlackbirdListener
    parse

Code details
~~~~~~~~~~~~
"""
# pylint: disable=protected-access
import os
import warnings

import antlr4

import numpy as np
import sympy as sym

from .blackbirdLexer import blackbirdLexer
from .blackbirdParser import blackbirdParser
from .blackbirdListener import blackbirdListener

from .error import BlackbirdErrorListener, BlackbirdSyntaxError
from .auxiliary import _expression, _get_arguments, _literal, _VAR, _FORVAR, _PARAMS
from .program import BlackbirdProgram


PYTHON_TYPES = {
    "array": np.ndarray,
    "float": float,
    "complex": complex,
    "int": int,
    "str": str,
    "bool": bool,
    "par": sym.Symbol,
}
"""dict[str->type]: Mapping from the allowed Blackbird types
to the equivalent Python/NumPy types."""


NUMPY_TYPES = {
    "float": np.float64,
    "complex": np.complex128,
    "int": np.int64,
    "str": np.str,
    "bool": np.bool,
    "par": sym.Symbol,
}
"""dict[str->type]: Mapping from the allowed Blackbird array types
to the equivalent NumPy data types."""


class RegRefTransform:
    """Class to represent a classical register transform.

    Args:
        expr (sympy.Expr): a SymPy expression representing the RegRef transform
    """

    def __init__(self, expr):
        """After initialization, the RegRefTransform has three attributes
        which may be inspected to translate the Blackbird program to a
        simulator or quantum hardware:

        * :attr:`func`
        * :attr:`regrefs`
        * :attr:`func_str`
        """
        regref_symbols = list(expr.free_symbols)
        # get the Python function represented by the regref transform
        self.func = sym.lambdify(regref_symbols, expr)
        """function: Scalar function that takes one or more values corresponding
        to measurement results, and outputs a single numeric value."""

        # get the regrefs involved
        self.regrefs = [int(str(i)[1:]) for i in regref_symbols]
        """list[int]: List of integers corresponding to the modes that are measured
        and act as inputs to :attr:`func`. Note that the order of this list corresponds
        to the order that the measured mode results should be passed to the function."""

        self.func_str = str(expr)
        """str: String representation of the RegRefTransform function."""

    def __str__(self):
        """Print formatting"""
        return self.func_str

    __repr__ = __str__


class BlackbirdListener(blackbirdListener):
    """Listener to run a Blackbird program and extract the program queue and target information.

    On initialization, an empty :class:`~.BlackbirdProgram` object is initialized.
    Over the course of the parsing, the program details are filled in according to the
    parsed script.

    Once parsing is complete, the :class:`~.BlackbirdProgram` object can be returned
    via the :attr:`program` attribute.
    """

    def __init__(self, cwd=None):
        self._program = BlackbirdProgram()
        self._includes = {}
        self._cwd = cwd
        self._in_for = False

        if cwd is None:
            # assume the current directory
            self._cwd = os.getcwd()

    @property
    def program(self):
        """Returns the parsed blackbird program"""
        return self._program

    def exitDeclarename(self, ctx: blackbirdParser.DeclarenameContext):
        """Run after exiting program name metadata.

        Args:
            ctx: DeclarenameContext
        """
        self._program._name = ctx.programname().getText()

    def exitVersion(self, ctx: blackbirdParser.VersionContext):
        """Run after exiting version metadata.

        Args:
            ctx: VersionContext
        """
        self._program._version = ctx.versionnumber().getText()

    def exitTarget(self, ctx: blackbirdParser.TargetContext):
        """Run after exiting target metadata.

        Args:
            ctx: TargetContext
        """
        self._program._target["name"] = ctx.device().getText()

        kwargs = {}

        if ctx.arguments():
            args, kwargs = _get_arguments(ctx.arguments())

            if args:
                warnings.warn(
                    "Target devices only accept keyword options of the form "
                    "option=value. All positional arguments without a named "
                    "option will be ignored.",
                    SyntaxWarning,
                )

        self._program._target["options"] = kwargs

    def exitInclude(self, ctx: blackbirdParser.IncludeContext):
        """Run after exiting include statement.

        Args:
            ctx: IncludeContext
        """
        filename = os.path.join(self._cwd, ctx.STR().getText()[1:-1])

        # check if filename has already been included
        for _, f in self._includes.items():
            if f[0] == filename:
                return

        cwd = os.path.dirname(filename)
        data = antlr4.FileStream(filename)

        # parse the included file
        lexer = blackbirdLexer(data)
        stream = antlr4.CommonTokenStream(lexer)

        parser = blackbirdParser(stream)
        parser.removeErrorListeners()
        parser.addErrorListener(BlackbirdErrorListener())
        tree = parser.start()

        listener = BlackbirdListener(cwd=cwd)
        walker = antlr4.ParseTreeWalker()
        walker.walk(listener, tree)

        # add parsed blackbird program to the include
        # dictionary
        bb = listener.program
        self._includes[bb.name] = [filename, bb]

        # make sure to also add all nested includes
        # to the top level include dictionary
        self._includes.update(listener._includes)

    def exitExpressionvar(self, ctx: blackbirdParser.ExpressionvarContext):
        """Run after exiting an expression variable.

        Args:
            ctx: variable context
        """
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()

        if ctx.name().invalid():
            child = ctx.name().invalid()
            line = child.start.line
            col = child.start.column

            if child.REGREF():
                raise BlackbirdSyntaxError(
                    "Blackbird SyntaxError (line {}:{}): Variable name '{}' is reserved for register references".format(
                        line, col, name
                    )
                )
            if child.reserved():
                raise BlackbirdSyntaxError(
                    "Blackbird SyntaxError (line {}:{}): Variable name '{}' is a reserved Blackbird keyword".format(
                        line, col, name
                    )
                )

        if ctx.expression():
            value = _expression(ctx.expression())
        elif ctx.nonnumeric():
            value = _literal(ctx.nonnumeric())

        try:
            # assume all variables are scalar
            final_value = PYTHON_TYPES[vartype](value)
        except:
            try:
                # maybe one of the variables was a NumPy array?
                final_value = NUMPY_TYPES[vartype](value)
            except:
                # nope
                raise TypeError(
                    "Var {} = {} is not of declared type {}".format(name, value, vartype)
                ) from None

        _VAR[name] = final_value

    def exitArrayvar(self, ctx: blackbirdParser.ArrayvarContext):
        """Run after exiting an array variable.

        Args:
            ctx: array variable context
        """
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()

        if ctx.name().invalid():
            child = ctx.name().invalid()
            line = child.start.line
            col = child.start.column

            if child.REGREF():
                raise BlackbirdSyntaxError(
                    "Blackbird SyntaxError (line {}:{}): Variable name '{}' is reserved for register references".format(
                        line, col, name
                    )
                )
            if child.reserved():
                raise BlackbirdSyntaxError(
                    "Blackbird SyntaxError (line {}:{}): Variable name '{}' is a reserved Blackbird keyword".format(
                        line, col, name
                    )
                )

        shape = None
        if ctx.shape():
            shape = tuple([int(i) for i in ctx.shape().getText().split(",")])

        value = []
        # loop through all children of the 'arrayval' branch
        for i in ctx.arrayval().getChildren():
            # Check if the child is an array row (this is to
            # avoid the '\n' row delimiter)
            if isinstance(i, blackbirdParser.ArrayrowContext):
                value.append([])
                for j in i.getChildren():
                    # Check if the child is not the column delimiter ','
                    if j.getText() != ",":
                        value[-1].append(_expression(j))

        try:
            final_value = np.array(value, dtype=NUMPY_TYPES[vartype])
        except:
            line = ctx.start.line
            col = ctx.start.column
            raise BlackbirdSyntaxError(
                "Blackbird SyntaxError (line {}:{}): Array var {} is not of declared type {}".format(
                    line, col, name, vartype
                )
            )

        if shape is not None:
            actual_shape = final_value.shape
            if actual_shape != shape:
                line = ctx.start.line
                col = ctx.start.column
                raise BlackbirdSyntaxError(
                    "Blackbird SyntaxError (line {}:{}): Array var {} has declared shape {} "
                    "but actual shape {}".format(line, col, name, shape, actual_shape)
                )

        _VAR[name] = final_value

    def exitStatement(self, ctx: blackbirdParser.StatementContext):
        """Run after exiting a quantum statement.

        Args:
            ctx: statement context
        """
        if isinstance(ctx.parentCtx, blackbirdParser.ForloopContext):
            if self._in_for:
                return

        if ctx.operation():
            op = ctx.operation().getText()
        elif ctx.measure():
            op = ctx.measure().getText()

        # get modes; if variables, replace with corresponding values
        modes = ctx.arrayrow().getText().split(",")
        for i, m in enumerate(modes):
            try:
                modes[i] = int(m)
            except ValueError:
                m = m.strip()
                if m in _VAR.keys():
                    if isinstance(_VAR[m], int):
                        modes[i] = _VAR[m]
                    else:
                        raise ValueError(f"Mode must be of type int, not {type(_VAR[m])}")
                else:
                    raise ValueError(f"Variable {m} not declared")

        self._program._modes |= set(modes)

        if ctx.arguments():
            op_args, op_kwargs = _get_arguments(ctx.arguments())

            # convert any sympy expressions into regref transforms
            for idx, a in enumerate(op_args):
                if isinstance(a, sym.Expr):
                    if not set(a.free_symbols) <= set(_PARAMS):
                        # the symbols in the expression are not
                        # a subset of the template parameters
                        # Therefore, it includes a regref statement.
                        op_args[idx] = RegRefTransform(a)

            for k, v in op_kwargs.items():
                if isinstance(v, sym.Expr):
                    if not set(v.free_symbols) <= set(_PARAMS):
                        # the symbols in the expression are not
                        # a subset of the template parameters
                        # Therefore, it includes a regref statement.
                        op_kwargs[k] = RegRefTransform(v)

            operation = {"op": op, "args": op_args, "kwargs": op_kwargs, "modes": modes}
        else:
            operation = {"op": op, "modes": modes}

        # check if statement is included from another file
        if operation["op"] in self._includes:
            bb = self._includes[operation["op"]][1]

            # make sure modes match
            if len(operation["modes"]) != len(bb.modes):
                raise ValueError(
                    "Included operation {} acts on {} modes, "
                    "but {} modes provided".format(
                        operation["op"], len(bb.modes), len(operation["modes"])
                    )
                )

            if "kwargs" in operation:
                # operation is a template
                if not bb.is_template():
                    raise ValueError(
                        "Included operation {} does not accept arguments".format(operation["op"])
                    )

                if bb.parameters != set(operation["kwargs"]):
                    raise ValueError(
                        "Included operation {} must accept only keyword arguments {}".format(
                            operation["op"], bb.parameters
                        )
                    )

                # instantiate template
                bb = bb(**operation["kwargs"])

            else:
                # operation is not a template
                if bb.is_template():
                    raise ValueError(
                        "Included operation {} missing keyword arguments {}".format(
                            operation["op"], bb.parameters
                        )
                    )

            # mode mapping dictionary
            # maps the modes of the included program
            # to the modes it is applied to in the including program
            mode_map = dict(zip(bb.modes, operation["modes"]))

            for i in bb._operations:
                # for each operation in the included program,
                # update the applied mode to match the including
                # program
                i["modes"] = [mode_map[j] for j in i["modes"]]

            self._program._operations.extend(bb._operations)
        else:
            self._program._operations.append(operation)

    def enterForloop(self, ctx: blackbirdParser.ForloopContext):
        self._in_for = True

    def exitForloop(self, ctx: blackbirdParser.ForloopContext):
        self._in_for = False

        if ctx.rangeval():
            _FORVAR = range(*[
                int(c.getText()) for c in ctx.rangeval().getChildren()
                if c.getText() != ":"
            ])
        elif ctx.vallist():
            _FORVAR = [
                _expression(c.expression()) for c in ctx.vallist().getChildren()
                if isinstance(c, blackbirdParser.ValContext)
            ]

        for var in _FORVAR:
            if ctx.NAME():
                try:
                    new_var = PYTHON_TYPES[ctx.vartype().getText()](var)
                    if new_var != var:
                        raise ValueError
                except ValueError:
                    raise ValueError(f"invalid value {var}; must be {ctx.vartype().getText()}")

                _VAR[ctx.NAME().getText()] = new_var

            for statement in ctx.statement_list:
                self.exitStatement(statement)

        _FORVAR = []

    def exitProgram(self, ctx: blackbirdParser.ProgramContext):
        """Run after exiting the program block.

        Args:
            ctx: program context
        """
        self._program._var.update(_VAR)
        _VAR.clear()

        self._program._parameters.extend(_PARAMS)
        _PARAMS.clear()


def parse(data, listener=BlackbirdListener, cwd=None):
    """Parse a blackbird data stream.

    Args:
        data (antlr4.InputStream): ANTLR4 data stream of the Blackbird script
        Listener (BlackbirdListener): an Blackbird listener to use to walk the AST.
            By default, the basic :class:`~.BlackbirdListener` defined above
            is used.

    Returns:
        BlackbirdProgram: returns an instance of the :class:`BlackbirdProgram` class after
        parsing the abstract syntax tree
    """
    lexer = blackbirdLexer(data)
    stream = antlr4.CommonTokenStream(lexer)

    parser = blackbirdParser(stream)
    parser.removeErrorListeners()
    parser.addErrorListener(BlackbirdErrorListener())
    tree = parser.start()

    blackbird = listener(cwd=cwd)
    walker = antlr4.ParseTreeWalker()
    walker.walk(blackbird, tree)

    return blackbird.program
