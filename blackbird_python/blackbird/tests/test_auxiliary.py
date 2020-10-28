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

"""Tests for the auxiliary functions"""
# pylint: disable=too-many-ancestors,no-self-use,redefined-outer-name,too-many-arguments,no-value-for-parameter
import pytest

import numpy as np
import sympy as sym

from antlr4 import ParserRuleContext

import blackbird
from blackbird.blackbirdParser import blackbirdParser
from blackbird.auxiliary import _literal, _number, _func, _expression, _get_arguments
from blackbird.error import BlackbirdSyntaxError


test_ints = [('-3', -3), ('0', 0), ('4', 4), ('15', 15)]
test_floats = [('0.432', 0.432), ('-0.54321', -0.54321), ('32.432', 32.432), ('13.', 13), ('-1', -1), ('8.0', 8), ('89.23e-10', 8.923e-9)]
test_complex = [('0+5j', 0+5j), ('8-1j', 8-1j), ('0.54+0.21j', 0.54+0.21j), ('8', 8), ('2j', 2j)]
U = np.array([[3, 2], [1+1j, -0.5]])


class start:
    """Dummy location class for syntax errors"""
    column = 2
    line = 1


@pytest.fixture
def parser():
    """Returns a dummy/empty blackbird parser"""
    return blackbirdParser("")


@pytest.fixture
def ctx():
    """Returns a dummy rule context"""
    return ParserRuleContext()


@pytest.fixture
def num(parser, ctx):
    """Generates a blackbird number label that can be passed to the Blackbird parser.
    This is convenient when testing other functions that require numbers."""
    def _number_label(n, num_type='complex'):
        """Generate the blackbird number n"""
        class DummyNumberLabel(blackbirdParser.NumberLabelContext):
            """Dummy class"""
            def number(self):
                """The number method"""
                number = blackbirdParser.NumberContext(parser, ctx)

                if num_type == 'float':
                    number.FLOAT = lambda: True
                elif num_type == 'int':
                    number.INT = lambda: True
                else:
                    number.COMPLEX = lambda: True

                number.getText = lambda: n
                return number
        return DummyNumberLabel(parser, ctx)
    return _number_label


@pytest.fixture
def var(parser, ctx):
    """Generates a blackbird variable label"""
    def _var_label(key):
        """Generate a reference to blackbird variable key"""
        _var = blackbirdParser.VariableLabelContext(parser, ctx)
        _var.getText = lambda: key
        return _var
    return _var_label


class TestLiteral:
    """Tests for the _literal function"""
    def test_literal_string(self):
        """Test that a Blackbird string is properly converted to a Python type"""
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.STR = lambda: True
        nonnumeric.getText = lambda: "Test value"
        assert _literal(nonnumeric) == "Test value"

    def test_literal_bool_true(self):
        """Test that a Blackbird bool (True) is properly converted to a Python type"""
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.BOOL = lambda: True
        nonnumeric.getText = lambda: "True"
        assert _literal(nonnumeric)

    def test_literal_bool_false(self):
        """Test that a Blackbird bool (False) is properly converted to a Python type"""
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.BOOL = lambda: True
        nonnumeric.getText = lambda: "False"
        assert not _literal(nonnumeric)

    def test_literal_bool_invalid(self):
        """Test that an exception is raised if a Blackbird bool is invalid"""
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.BOOL = lambda: True
        nonnumeric.getText = lambda: "false"

        with pytest.raises(ValueError, match="Unknown boolean value"):
            _literal(nonnumeric)

    def test_literal_invalid(self):
        """Test that an exception is raised if a Blackbird literal is invalid"""
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.getText = lambda: ""

        with pytest.raises(ValueError, match="Unknown value"):
            _literal(nonnumeric)


class TestNumber:
    """Tests for the _number function"""

    @pytest.mark.parametrize('n, expected', test_ints)
    def test_number_int(self, parser, ctx, n, expected):
        """Test that a Blackbird int is properly converted to a Python type"""
        number = blackbirdParser.NumberContext(parser, ctx)
        number.INT = lambda: True
        number.getText = lambda: n
        assert _number(number) == expected

    @pytest.mark.parametrize('n, expected', test_floats)
    def test_number_float(self, parser, ctx, n, expected):
        """Test that a Blackbird float is properly converted to a Python type"""
        number = blackbirdParser.NumberContext(parser, ctx)
        number.FLOAT = lambda: True
        number.getText = lambda: n
        assert _number(number) == expected

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_number_complex(self, parser, ctx, n, expected):
        """Test that a Blackbird complex is properly converted to a Python type"""
        number = blackbirdParser.NumberContext(parser, ctx)
        number.COMPLEX = lambda: True
        number.getText = lambda: n
        assert _number(number) == expected

    def test_number_pi(self, parser, ctx):
        """Test that a Blackbird pi literal is properly converted to a Python type"""
        number = blackbirdParser.NumberContext(parser, ctx)
        number.PI = lambda: True
        assert _number(number) == np.pi

    def test_number_invalid(self, parser, ctx):
        """Test that an unknown number correctly raises and exception"""
        number = blackbirdParser.NumberContext(parser, ctx)
        number.getText = lambda: ""

        with pytest.raises(ValueError, match="Unknown number"):
            _number(number)


class TestFunction:
    """Tests for the _func function"""

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_exp(self, parser, ctx, n, expected, num):
        """Test that a Blackbird exp function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.EXP = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.exp(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_log(self, parser, ctx, n, expected, num):
        """Test that a Blackbird log function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.LOG = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.log(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_sin(self, parser, ctx, n, expected, num):
        """Test that a Blackbird sin function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.SIN = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.sin(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_cos(self, parser, ctx, n, expected, num):
        """Test that a Blackbird cos function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.COS = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.cos(expected)

    @pytest.mark.parametrize('n, expected', test_floats)
    def test_function_tan(self, parser, ctx, n, expected, num):
        """Test that a Blackbird tan function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.TAN = lambda: True
        expression = num(n, num_type='float')
        assert _func(func, expression) == np.tan(expected)

    def test_function_arcsin(self, parser, ctx, num):
        """Test that a Blackbird arcsin function is properly called"""
        n = "0.543"
        expected = float(n)

        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCSIN = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.arcsin(expected)

    def test_function_arccos(self, parser, ctx, num):
        """Test that a Blackbird arccos function is properly called"""
        n = "0.543"
        expected = float(n)

        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCCOS = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.arccos(expected)

    def test_function_arctan(self, parser, ctx, num):
        """Test that a Blackbird arctan function is properly called"""
        n = "0.543"
        expected = float(n)

        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCTAN = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.arctan(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_sinh(self, parser, ctx, n, expected, num):
        """Test that a Blackbird sinh function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.SINH = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.sinh(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_cosh(self, parser, ctx, n, expected, num):
        """Test that a Blackbird cosh function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.COSH = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.cosh(expected)

    def test_function_tanh(self, parser, ctx, num):
        """Test that a Blackbird tanh function is properly called"""
        n = "0.543"
        expected = float(n)

        func = blackbirdParser.FunctionContext(parser, ctx)
        func.TANH = lambda: True
        expression = num(n, num_type='float')
        assert _func(func, expression) == np.tanh(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_arcsinh(self, parser, ctx, n, expected, num):
        """Test that a Blackbird arcsinh function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCSINH = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.arcsinh(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_arccosh(self, parser, ctx, n, expected, num):
        """Test that a Blackbird arccosh function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCCOSH = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.arccosh(expected)

    def test_function_arctanh(self, parser, ctx, num):
        """Test that a Blackbird arctanh function is properly called"""
        n = "0.543"
        expected = float(n)

        func = blackbirdParser.FunctionContext(parser, ctx)
        func.ARCTANH = lambda: True
        expression = num(n, num_type='float')
        assert _func(func, expression) == np.arctanh(expected)

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_function_sqrt(self, parser, ctx, n, expected, num):
        """Test that a Blackbird sqrt function is properly called"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.SQRT = lambda: True
        expression = num(n)
        assert _func(func, expression) == np.sqrt(expected)

    def test_function_invalid(self, parser, ctx):
        """Test that an invalid Blackbird function raises the correct exception"""
        func = blackbirdParser.FunctionContext(parser, ctx)
        func.getText = lambda: "Hello"

        with pytest.raises(NameError, match="Unknown function Hello"):
            _func(func, None)


class TestExpression:
    """Tests for the _expression function"""

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_number(self, n, expected, num):
        """Test that a Blackbird expression containing numbers evaluates"""
        expr = num(n)
        assert _expression(expr) == expected

    def test_variable(self, parser, ctx, monkeypatch):
        """Test that a Blackbird expression containing variables evaluates"""
        expr = blackbirdParser.VariableLabelContext(parser, ctx)
        expr.getText = lambda: "var1"

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"var1": 5})
            assert _expression(expr) == 5

    def test_variable_invalid(self, parser, ctx, monkeypatch):
        """Test that an error is raised if the variable does not exist"""
        expr = blackbirdParser.VariableLabelContext(parser, ctx)
        expr.getText = lambda: "var2"
        expr.start = start()

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"var1": 5})
            with pytest.raises(BlackbirdSyntaxError, match="name 'var2' is not defined"):
                _expression(expr)

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_brackets(self, parser, num, n1, n2, ctx):
        """Test that brackets are correctly parsed"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (num(n1[0]), num(n2[0]))

        class DummyBracketsLabel(blackbirdParser.BracketsLabelContext):
            """Dummy brackets"""
            def expression(self):
                """Returns a Blackbird abstract syntax tree section corresponding to an expression"""
                e = DummyAddLabel(parser, ctx)
                e.PLUS = lambda: True
                return e

        class DummyPowerLabel(blackbirdParser.PowerLabelContext):
            """Dummy power"""
            expression = lambda self: (DummyBracketsLabel(parser, ctx), num(2))

        expr = DummyPowerLabel(parser, ctx)
        assert _expression(expr) == (n1[1]+n2[1])**2


    @pytest.mark.parametrize('n, expected', test_complex)
    def test_negation(self, parser, ctx, n, expected, num):
        """Test negation of an expression"""

        class DummySignLabel(blackbirdParser.SignLabelContext):
            """Dummy sign label"""
            expression = lambda self: num(n)

        expr = DummySignLabel(parser, ctx)
        expr.MINUS = lambda: True
        assert _expression(expr) == -expected

    @pytest.mark.parametrize('n, expected', test_complex)
    def test_unary_plus(self, parser, ctx, n, expected, num):
        """Test unary plus of an expression"""

        class DummySignLabel(blackbirdParser.SignLabelContext):
            """Dummy sign label"""
            expression = lambda self: num(n)

        expr = DummySignLabel(parser, ctx)
        expr.PLUS = lambda: True
        assert _expression(expr) == expected

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_plus(self, parser, ctx, n1, n2, num):
        """Test addition of two numbers"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (num(n1[0]), num(n2[0]))

        expr = DummyAddLabel(parser, ctx)
        expr.PLUS = lambda: True
        assert _expression(expr) == n1[1] + n2[1]

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_minus(self, parser, ctx, n1, n2, num):
        """Test subtraction of two numbers"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (num(n1[0]), num(n2[0]))

        expr = DummyAddLabel(parser, ctx)
        expr.MINUS = lambda: True
        assert _expression(expr) == n1[1] - n2[1]

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_multiply(self, parser, ctx, n1, n2, num):
        """Test multiplication of two numbers"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (num(n1[0]), num(n2[0]))

        expr = DummyMulLabel(parser, ctx)
        expr.TIMES = lambda: True
        assert _expression(expr) == n1[1]*n2[1]

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_divide(self, parser, ctx, n1, n2, num):
        """Test division of two numbers"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (num(n1[0], num_type='complex'), num(n2[0], num_type='float'))

        expr = DummyMulLabel(parser, ctx)
        expr.DIVIDE = lambda: True
        assert np.allclose(_expression(expr), n1[1]/n2[1])

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_ints)
    def test_divide_by_integer(self, parser, ctx, n1, n2, num):
        """Test division of a number by an integer"""
        if n2[1] == 0:
            pytest.skip("Cannot divide by zero")

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (num(n1[0]), num(n2[0], num_type='int'))

        expr = DummyMulLabel(parser, ctx)
        expr.DIVIDE = lambda: True
        assert np.allclose(_expression(expr), n1[1]/n2[1])

    @pytest.mark.parametrize('n1', test_complex)
    @pytest.mark.parametrize('n2', test_floats)
    def test_power(self, parser, ctx, n1, n2, num):
        """Test power of two numbers"""

        class DummyPowerLabel(blackbirdParser.PowerLabelContext):
            """Dummy power label"""
            expression = lambda self: (num(n1[0], num_type='complex'), num(n2[0], num_type='float'))

        expr = DummyPowerLabel(parser, ctx)
        assert np.allclose(_expression(expr), n1[1]**n2[1])

    @pytest.mark.parametrize('n1', test_complex)
    def test_function(self, parser, ctx, n1, num):
        """Test function is properly called"""

        class DummySin(blackbirdParser.FunctionContext):
            """Dummy sin label"""
            SIN = lambda self: True

        class DummyFunctionLabel(blackbirdParser.FunctionLabelContext):
            """Dummy function label"""
            expression = lambda self: num(n1[0])
            function = lambda self: DummySin(parser, ctx)

        expr = DummyFunctionLabel(parser, ctx)
        assert np.allclose(_expression(expr), np.sin(n1[1]))

    def test_regref_transform(self, parser, ctx, monkeypatch):
        """Test that a Blackbird expression containing register references evaluates"""
        expr = blackbirdParser.VariableLabelContext(parser, ctx)
        expr.getText = lambda: "q2"
        expr.REGREF = lambda: True

        assert isinstance(_expression(expr), sym.Symbol)
        assert str(_expression(expr)) == "q2"

    def test_p_parameter_type_error(self, parser, ctx, monkeypatch):
        """Test that an error is raised if the variable does not exist"""
        expr = blackbirdParser.VariableLabelContext(parser, ctx)
        expr.getText = lambda: "p0"
        expr.start = start()

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"p0": 13})
            m.setattr(blackbird.auxiliary, "_PARAMS", ["p0"])
            with pytest.raises(TypeError, match="Invalid type for parameter."):
                _expression(expr)

class TestExpressionArray:
    """Tests for the _expression function involving arrays"""

    @pytest.mark.parametrize('n1', test_complex)
    def test_plus_scalar_array(self, parser, ctx, n1, num, var, monkeypatch):
        """Test addition of a number and an array"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (num(n1[0]), var("U"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U": U})

            expr = DummyAddLabel(parser, ctx)
            expr.PLUS = lambda: True
            assert np.all(_expression(expr) == n1[1] + U)

    def test_plus_array(self, parser, ctx, var, monkeypatch):
        """Test addition of two arrays"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (var("U1"), var("U2"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U1": U*5, "U2": np.cos(U)})

            expr = DummyAddLabel(parser, ctx)
            expr.PLUS = lambda: True
            assert np.allclose(_expression(expr), U*5+np.cos(U))

    @pytest.mark.parametrize('n1', test_complex)
    def test_minus_scalar_array(self, parser, ctx, n1, num, var, monkeypatch):
        """Test subtraction of a number and an array"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (num(n1[0]), var("U"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U": U})

            expr = DummyAddLabel(parser, ctx)
            expr.MINUS = lambda: True
            assert np.all(_expression(expr) == n1[1] - U)

    def test_minus_array(self, parser, ctx, var, monkeypatch):
        """Test subtraction of two arrays"""

        class DummyAddLabel(blackbirdParser.AddLabelContext):
            """Dummy add label"""
            expression = lambda self: (var("U1"), var("U2"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U1": U*5, "U2": np.cos(U)})

            expr = DummyAddLabel(parser, ctx)
            expr.MINUS = lambda: True
            assert np.allclose(_expression(expr), U*5-np.cos(U))

    @pytest.mark.parametrize('n1', test_complex)
    def test_multiply_scalar_array(self, parser, ctx, n1, num, var, monkeypatch):
        """Test multiplication of a number and an array"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (num(n1[0]), var("U"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U": U})

            expr = DummyMulLabel(parser, ctx)
            expr.TIMES = lambda: True
            assert np.all(_expression(expr) == n1[1]*U)

    def test_multiply_array_element(self, parser, ctx, var, monkeypatch):
        """Test multiplication of two arrays"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (var("U1"), var("U2"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U1": U*5, "U2": np.cos(U)})

            expr = DummyMulLabel(parser, ctx)
            expr.TIMES = lambda: True
            assert np.allclose(_expression(expr), U*5*np.cos(U))

    @pytest.mark.parametrize('n1', test_complex)
    def test_divide_scalar_array(self, parser, ctx, n1, num, var, monkeypatch):
        """Test division of a number and an array"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (num(n1[0]), var("U"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U": U})

            expr = DummyMulLabel(parser, ctx)
            expr.DIVIDE = lambda: True
            assert np.all(_expression(expr) == n1[1]/U)

    def test_divide_array_element(self, parser, ctx, var, monkeypatch):
        """Test division of two arrays"""

        class DummyMulLabel(blackbirdParser.MulLabelContext):
            """Dummy mul label"""
            expression = lambda self: (var("U1"), var("U2"))

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U1": U*5, "U2": np.cos(U)})

            expr = DummyMulLabel(parser, ctx)
            expr.DIVIDE = lambda: True
            assert np.allclose(_expression(expr), U*5/np.cos(U))


class TestArguments:
    """Test for the _get_arguments function"""

    def test_positional_expression(self, parser, ctx, num):
        """Test a positional expression is correctly extracted"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)

        arg1.expression = lambda: num(5)
        args.getChildren = lambda: [arg1]
        assert _get_arguments(args) == ([5], {})

    def test_positional_string(self, parser, ctx):
        """Test a positional string is correctly extracted"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)

        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)
        nonnumeric.STR = lambda: True
        nonnumeric.getText = lambda: "Test value"

        arg1.nonnumeric = lambda: nonnumeric
        args.getChildren = lambda: [arg1]
        assert _get_arguments(args) == (["Test value"], {})

    def test_positional_var(self, parser, ctx, var, monkeypatch):
        """Test a positional variable is correctly extracted"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)

        arg1.NAME = lambda: var('U')
        args.getChildren = lambda: [arg1]

        with monkeypatch.context() as m:
            m.setattr(blackbird.auxiliary, "_VAR", {"U": U})
            assert _get_arguments(args) == ([U], {})

    def test_positional_invalid_var(self, parser, ctx, var):
        """Test exception raised if variable not found"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)

        arg1.NAME = lambda: var('U')
        arg1.start = start()
        args.getChildren = lambda: [arg1]

        with pytest.raises(BlackbirdSyntaxError, match="name 'U' is not defined"):
            _get_arguments(args)

    def test_keyword_expression(self, parser, ctx, num):
        """Test a keyword expression is correctly extracted"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        kwarg1 = blackbirdParser.KwargContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)
        name = blackbirdParser.NameContext(parser, ctx)

        name.getText = lambda: "test_kwarg"
        kwarg1.val = lambda: arg1
        kwarg1.NAME = lambda: name
        arg1.expression = lambda: num(5)
        args.getChildren = lambda: [kwarg1]
        assert _get_arguments(args) == ([], {"test_kwarg": 5})

    def test_keyword_nonnumeric(self, parser, ctx):
        """Test a keyword nonnumeric is correctly extracted"""
        args = blackbirdParser.ArgumentsContext(parser, ctx)
        kwarg1 = blackbirdParser.KwargContext(parser, ctx)
        arg1 = blackbirdParser.ValContext(parser, ctx)
        name = blackbirdParser.NameContext(parser, ctx)
        nonnumeric = blackbirdParser.NonnumericContext(parser, ctx)

        nonnumeric.STR = lambda: True
        nonnumeric.getText = lambda: "Test value"

        name.getText = lambda: "test_kwarg"
        kwarg1.val = lambda: arg1
        kwarg1.NAME = lambda: name
        arg1.nonnumeric = lambda: nonnumeric
        args.getChildren = lambda: [kwarg1]
        assert _get_arguments(args) == ([], {"test_kwarg": "Test value"})
