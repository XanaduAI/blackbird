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
Auxillary functions
===================

**Module name:** :mod:`blackbird.auxiliary`

.. currentmodule:: blackbird.auxiliary

This module contains a variety of auxiliary functions used by the main
:class:`blackbird.BlackbirdListener`.

Note that every auxiliary function in this module accepts a
:class:`blackbird.blackbirdParser` context as an argument.

Summary
-------

.. autosummary::
    _expression
    _func
    _get_arguments
    _literal
    _number
    _VAR

Code details
~~~~~~~~~~~~
"""
import cmath
import math

from sympy import Symbol

from .blackbirdParser import blackbirdParser
from .error import BlackbirdSyntaxError


_VAR = {}
""" dict[str->[int, float, complex, str, bool, numpy.ndarray]]: Mapping from the
variable names in the Blackbird script, to their declared values.

This dictionary is populated when parsing
:class:`blackbird.blackbirdParser.ExpressionvarContext` objects via
:class:`blackbird.BlackbirdListener.exitExpressionvar`, and accessed when
required by :func:`~._expression`.

"""


_PARAMS = []
""" list[Symbol]: list of free parameters in the Blackbird program
"""


def _literal(nonnumeric):
    """Convert a non-numeric blackbird literal to a Python literal.

    Args:
        nonnumeric (blackbirdParser.NonnumericContext): nonnumeric context
    Returns:
        str or bool
    """
    if nonnumeric.STR():
        return str(nonnumeric.getText().replace('"', ""))

    if nonnumeric.BOOL():
        val = nonnumeric.getText()
        if val == "True":
            return True

        if val == "False":
            return False

        raise ValueError("Unknown boolean value " + nonnumeric.getText())

    raise ValueError("Unknown value " + nonnumeric.getText())


def _number(number):
    """Convert a blackbird number to a Python number.

    Args:
        number (blackbirdParser.NumberContext): number context
    Returns:
        int or float or complex
    """
    if number.INT():
        return int(number.getText())

    if number.FLOAT():
        return float(number.getText())

    if number.COMPLEX():
        return complex(number.getText())

    if number.PI():
        return math.pi

    raise ValueError("Unknown number " + number.getText())


def _func(function, arg):
    """Apply a blackbird function to an Python argument.

    Args:
        function (blackbirdParser.FunctionContext): function context
        arg: expression
    Returns:
        int or float or complex
    """
    # exponential functions
    expr = _expression(arg)
    math_lib = math

    if isinstance(expr, list):
        if any(isinstance(i, complex) for row in expr for i in row):
            math_lib = cmath

        map_fn = lambda fn, val: [list(map(fn, row)) for row in val]
    else:
        if isinstance(expr, complex):
            math_lib = cmath

        map_fn = lambda fn, val: fn(val)

    if function.EXP():
        return map_fn(math_lib.exp, expr)

    if function.LOG():
        return map_fn(math_lib.log, expr)

    # trig functions
    if function.SIN():
        return map_fn(math_lib.sin, expr)

    if function.COS():
        print(expr)
        return map_fn(math_lib.cos, expr)

    if function.TAN():
        return map_fn(math_lib.tan, expr)

    # trig inverses
    if function.ARCSIN():
        return map_fn(math_lib.asin, expr)

    if function.ARCCOS():
        return map_fn(math_lib.acos, expr)

    if function.ARCTAN():
        return map_fn(math_lib.atan, expr)

    # hyperbolic trig
    if function.SINH():
        return map_fn(math_lib.sinh, expr)

    if function.COSH():
        return map_fn(math_lib.cosh, expr)

    if function.TANH():
        return map_fn(math_lib.tanh, expr)

    # hyperbolic trig inverses
    if function.ARCSINH():
        return map_fn(math_lib.asinh, expr)

    if function.ARCCOSH():
        return map_fn(math_lib.acosh, expr)

    if function.ARCTANH():
        return map_fn(math_lib.atanh, expr)

    # other
    if function.SQRT():
        return map_fn(math_lib.sqrt, expr)

    raise NameError("Unknown function " + function.getText())


def _expression(expr):
    """Evaluate a blackbird expression.

    This is a recursive function, that continually calls itself
    until the full expression has been evaluated.

    Args:
        expr: expression
    Returns:
        int or float or complex or str or bool
    """
    # pylint: disable=too-many-statements
    if isinstance(expr, blackbirdParser.NumberLabelContext):
        return _number(expr.number())

    if isinstance(expr, blackbirdParser.VariableLabelContext):
        if expr.REGREF():
            return Symbol(expr.getText())

        if expr.getText() not in _VAR:
            token = expr.start
            line = token.line
            col = token.column
            raise BlackbirdSyntaxError(
                "Blackbird SyntaxError (line {}:{}): name '{}' is not defined".format(
                    line, col, expr.getText()
                )
            )

        return _VAR[expr.getText()]

    if isinstance(expr, blackbirdParser.ParameterLabelContext):
        p = Symbol(expr.NAME().getText())
        _PARAMS.append(p)
        return p

    if isinstance(expr, blackbirdParser.BracketsLabelContext):
        return _expression(expr.expression())

    if isinstance(expr, blackbirdParser.SignLabelContext):
        a = expr.expression()
        if expr.PLUS():
            return _expression(a)
        if expr.MINUS():
            return -_expression(a)

    if isinstance(expr, blackbirdParser.AddLabelContext):
        a, b = expr.expression()
        a = _expression(a)
        b = _expression(b)

        if expr.PLUS():
            if isinstance(a, list) and isinstance(b, list):
                return [[i+j for i, j in zip(row_a, row_b)] for row_a, row_b in zip(a, b)]

            if isinstance(a, list) and not isinstance(b, list):
                return [[b+j for j in row_a] for row_a in a]

            if not isinstance(a, list) and isinstance(b, list):
                return [[a+j for j in row_b] for row_b in b]

            return a + b

        if expr.MINUS():
            if isinstance(a, list) and isinstance(b, list):
                return [[i-j for i, j in zip(row_a, row_b)] for row_a, row_b in zip(a, b)]

            if isinstance(a, list) and not isinstance(b, list):
                return [[j-b for j in row_a] for row_a in a]

            if not isinstance(a, list) and isinstance(b, list):
                return [[a-j for j in row_b] for row_b in b]

            return a - b

    if isinstance(expr, blackbirdParser.MulLabelContext):
        a, b = expr.expression()
        expr_a = _expression(a)
        expr_b = _expression(b)

        if expr.TIMES():
            if isinstance(expr_a, list) and isinstance(expr_b, list):
                return [[i*j for i, j in zip(row_a, row_b)] for row_a, row_b in zip(expr_a, expr_b)]

            if isinstance(expr_a, list) and not isinstance(expr_b, list):
                return [[expr_b*j for j in row_a] for row_a in expr_a]

            if not isinstance(expr_a, list) and isinstance(expr_b, list):
                return [[expr_a*j for j in row_b] for row_b in expr_b]

            return expr_a * expr_b

        if expr.DIVIDE():
            a = _expression(a)
            b = _expression(b)

            if isinstance(b, int):
                b = float(b)

            if isinstance(expr_a, list) and isinstance(expr_b, list):
                return [[i*pow(j, -1) for i, j in zip(row_a, row_b)] for row_a, row_b in zip(expr_a, expr_b)]

            if isinstance(expr_a, list) and not isinstance(expr_b, list):
                return [[j*pow(b, -1) for j in row_a] for row_a in expr_a]

            if not isinstance(expr_a, list) and isinstance(expr_b, list):
                return [[a*pow(j, -1) for j in row_b] for row_b in expr_b]

            return a * pow(b, -1)

    if isinstance(expr, blackbirdParser.PowerLabelContext):
        a, b = expr.expression()
        a = _expression(a)
        b = _expression(b)

        if isinstance(a, list) and isinstance(b, list):
            return [[pow(i, j) for i, j in zip(row_a, row_b)] for row_a, row_b in zip(a, b)]

        if isinstance(a, list) and not isinstance(b, list):
            return [[pow(j, b) for j in row_a] for row_a in a]

        if not isinstance(a, list) and isinstance(b, list):
            return [[pow(a, j) for j in row_b] for row_b in b]

        return pow(a, b)

    if isinstance(expr, blackbirdParser.FunctionLabelContext):
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
                    token = arg.start
                    line = token.line
                    col = token.column
                    raise BlackbirdSyntaxError(
                        "Blackbird SyntaxError (line {}:{}): name '{}' is not defined".format(
                            line, col, name
                        )
                    )

        elif isinstance(arg, blackbirdParser.KwargContext):
            name = arg.NAME().getText()
            if arg.val().expression():
                kwargs[name] = _expression(arg.val().expression())
            elif arg.val().nonnumeric():
                kwargs[name] = _literal(arg.val().nonnumeric())

    return args, kwargs
