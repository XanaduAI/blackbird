# Copyright 2018 Xanadu Quantum Technologies Inc.

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
"""Blackbird parser for Python"""
import sys
import antlr4

import numpy as np

from .blackbirdLexer import blackbirdLexer
from .blackbirdParser import blackbirdParser
from .blackbirdListener import blackbirdListener

_VAR = {}


PYTHON_TYPES = {
    'array': np.ndarray,
    'float': float,
    'complex': complex,
    'int': int,
    'str': str,
    'bool': bool
}


NUMPY_TYPES = {
    'float': np.float64,
    'complex': np.complex128,
    'int': np.int64,
    'str': np.str,
    'bool': np.bool
}


def _literal(nonnumeric):
    """Convert a non-numeric blackbird literal to a Python literal.

    Args:
        nonnumeric (blackbirdParser.NonnumericContext): nonnumeric context
    Returns:
        str or bool
    """
    if nonnumeric.STR():
        return str(nonnumeric.getText())
    elif nonnumeric.BOOL():
        return bool(nonnumeric.getText())
    else:
        raise ValueError("Unknown value: " + nonnumeric.getText())


def _number(number):
    """Convert a blackbird number to a Python number.

    Args:
        number (blackbirdParser.NumberContext): number context
    Returns:
        int or float or complex
    """
    if number.INT():
        return int(number.getText())
    elif number.FLOAT():
        return float(number.getText())
    elif number.COMPLEX():
        return complex(number.getText())
    elif number.PI:
        return np.pi
    else:
        raise ValueError("Unknown number: " + number.getText())


def _func(function, arg):
    """Apply a blackbird function to an Python argument.

    Args:
        function (blackbirdParser.FunctionContext): function context
        arg: expression
    Returns:
        int or float or complex
    """
    if function.EXP():
        return np.exp(_expression(arg))
    elif function.SIN():
        return np.sin(_expression(arg))
    elif function.COS():
        return np.cos(_expression(arg))
    elif function.SQRT():
        return np.sqrt(_expression(arg))
    else:
        raise NameError("Unknown function: " + function.getText())


def _expression(expr):
    """Evaluate a blackbird expression.

    This is a recursive function, that continually calls itself
    until the full expression has been evaluated.

    Args:
        expr: expression
    Returns:
        int or float or complex or str or bool
    """
    if isinstance(expr, blackbirdParser.NumberLabelContext):
        return _number(expr.number())

    elif isinstance(expr, blackbirdParser.VariableLabelContext):
        if expr.getText() not in _VAR:
            raise NameError("name '{}' is not defined".format(expr.getText()))

        return _VAR[expr.getText()]

    elif isinstance(expr, blackbirdParser.BracketsLabelContext):
        return _expression(expr.expression())

    elif isinstance(expr, blackbirdParser.SignLabelContext):
        a = expr.expression()
        if expr.PLUS():
            return _expression(a)
        elif expr.MINUS():
            return -_expression(a)

    elif isinstance(expr, blackbirdParser.AddLabelContext):
        a, b = expr.expression()
        if expr.PLUS():
            return np.sum([_expression(a), _expression(b)])
        elif expr.MINUS():
            return np.subtract([_expression(a), _expression(b)])

    elif isinstance(expr, blackbirdParser.MulLabelContext):
        a, b = expr.expression()
        if expr.TIMES():
            return np.prod([_expression(a), _expression(b)])
        elif expr.DIVIDE():
            return np.divide([_expression(a), _expression(b)])

    elif isinstance(expr, blackbirdParser.PowerLabelContext):
        a, b = expr.expression()
        return np.power(_expression(a), _expression(b))

    elif isinstance(expr, blackbirdParser.FunctionLabelContext):
        return _func(expr.function(), expr.expression())


def _get_arguments(arguments):
    """Parse blackbird positional and keyword arguments.

    In blackbird, all arguments occur between brackets (),
    and separated by commas. Positional arguments always come first,
    followed by keyword arguments of the form ``name=value``.

    Args:
        arguments (blackbirdParser.ArgumentsContext): arguments
    Returns:
        tuple[list, dict]: tuple containing the list of positional
        arguments, followed by the dictionary of keyword arguments
    """
    args = []
    kwargs = {}

    for arg in arguments.getChildren():
        if isinstance(arg, blackbirdParser.ValContext):
            if arg.expression():
                args.append(_expression(arg.expression()))
            elif arg.nonnumeric():
                args.append(_literal(arg.nonnumeric()))
            elif arg.NAME():
                name = arg.NAME().getText()
                if name in _VAR:
                    args.append(_VAR[name])
                else:
                    raise NameError("name '{}' is not defined".format(name))

        elif isinstance(arg, blackbirdParser.KwargContext):
            name = arg.NAME().getText()
            if arg.val().expression():
                kwargs[name] = _expression(arg.val().expression())
            elif arg.val().nonnumeric():
                kwargs[name] = _literal(arg.val().nonnumeric())

    return args, kwargs


class BlackbirdListener(blackbirdListener):
    """Listener to run a Blackbird program and extract the program queue and device information."""
    def __init__(self):
        self.var = {}
        self.device = None
        self.queue = []

    def exitExpressionVariableLabel(self, ctx: blackbirdParser.ExpressionVariableLabelContext):
        """Run after exiting an expression variable.

        Args:
            ctx: variable context
        """
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()

        if ctx.expression():
            value = _expression(ctx.expression())
        elif ctx.nonnumeric():
            value = _literal(ctx.nonnumeric())

        try:
            final_value = PYTHON_TYPES[vartype](value)
        except:
            raise TypeError("Var {} = {} is not of declared type {}".format(name, value, vartype)) from None

        _VAR[name] = final_value

    def exitArrayVariableLabel(self, ctx: blackbirdParser.ArrayVariableLabelContext):
        """Run after exiting an array variable.

        Args:
            ctx: array variable context
        """
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()

        shape = None
        if ctx.shape():
            shape = tuple([int(i) for i in ctx.shape().getText().split(',')])

        value = []
        # loop through all children of the 'arrayval' branch
        for i in ctx.arrayval().getChildren():
            # Check if the child is an array row (this is to
            # avoid the '\n' row delimiter)
            if isinstance(i, blackbirdParser.ArrayrowContext):
                value.append([])
                for j in i.getChildren():
                    # Check if the child is not the column delimiter ','
                    if j.getText() != ',':
                        value[-1].append(_expression(j))

        try:
            final_value = np.array(value, dtype=NUMPY_TYPES[vartype])
        except:
            raise TypeError("Array var {} is not of declared type {}".format(name, vartype)) from None

        if shape is not None:
            actual_shape = final_value.shape
            if actual_shape != shape:
                raise TypeError("Array var {} has declared shape {} "
                                " but actual shape {}".format(name, shape, actual_shape)) from None

        _VAR[name] = final_value

    def exitStatement(self, ctx: blackbirdParser.StatementContext):
        """Run after exiting a quantum statement.

        Args:
            ctx: statement context
        """
        if ctx.operation():
            op = ctx.operation().getText()
        elif ctx.measure():
            op = ctx.measure().getText()

        modes = [int(i) for i in ctx.modes().getText().split(',')]

        if ctx.arguments():
            op_args, op_kwargs = _get_arguments(ctx.arguments())
            self.queue.append({
                    'op': op,
                    'args': op_args,
                    'kwargs': op_kwargs,
                    'modes': modes
                })
        else:
            self.queue.append({'op': op, 'modes': modes})

    def exitProgram(self, ctx: blackbirdParser.ProgramContext):
        """Run after exiting the program block.

        Args:
            ctx: program context
        """
        self.var.update(_VAR)
        self.device = {'name': ctx.device().getText()}

        args = {}
        kwargs = {}

        if ctx.arguments():
            args, kwargs = _get_arguments(ctx.arguments())

        self.device['args'] = args
        self.device['kwargs'] = kwargs


def parse_blackbird(file, listener=BlackbirdListener):
    """Parse a blackbird program.

    Args:
        file (str): location of the .xbb blackbird file to run
        Listener (BlackbirdListener): an Blackbird listener to use to walk the AST.
            By default, the basic :class:`~.BlackbirdListener` defined above
            is used.

    Returns:
        BlackbirdListener: returns the Blackbird listener instance after
            parsing the abstract syntax tree
    """
    data = antlr4.FileStream(file)
    lexer = blackbirdLexer(data)
    stream = antlr4.CommonTokenStream(lexer)
    parser = blackbirdParser(stream)
    tree = parser.start()

    blackbird = listener()
    walker = antlr4.ParseTreeWalker()
    walker.walk(blackbird, tree)

    return blackbird
