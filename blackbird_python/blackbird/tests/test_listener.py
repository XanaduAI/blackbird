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

"""Tests for the Blackbird parser/listener"""
# pylint: disable=too-many-ancestors,no-self-use,redefined-outer-name,no-value-for-parameter
import sys

import pytest

import numpy as np
import sympy as sym

import antlr4

from blackbird.blackbirdLexer import blackbirdLexer
from blackbird.blackbirdParser import blackbirdParser
from blackbird.listener import BlackbirdListener, RegRefTransform, parse_blackbird


test_file = """
# a test blackbird script
name test_name
version 1.0
target fock (num_subsystems=1, cutoff_dim=7, shots=10)

float alpha = 0.3423
Coherent(alpha, sqrt(pi)) | 0
MeasureFock() | 0
"""


@pytest.fixture
def parse_input():
    """Create a parser for the test"""
    def _parse_input(text):
        """The parser fixture accepts a blackbird string to parse"""
        lexer = blackbirdLexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = blackbirdParser(stream)

        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)
        return bb
    return _parse_input


@pytest.fixture
def parse_input_mocked_metadata(monkeypatch):
    """Create a parser for the test that mocks out the metadata"""
    def _parse_input(text):
        """The parser fixture accepts a blackbird string to parse"""
        text = "name mockname\nversion 1.0\n" + text
        lexer = blackbirdLexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = blackbirdParser(stream)

        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        return bb
    return _parse_input


class TestParsingVariables:
    """Tests for parsing variable declarations"""

    def test_invalid_regref(self, parse_input_mocked_metadata):
        """Test that a variable using the reserved name for regrefs returns an exception"""
        with pytest.raises(SystemExit, match="reserved for register references"):
            parse_input_mocked_metadata('float q0 = 5')

        with pytest.raises(SystemExit, match="reserved for register references"):
            parse_input_mocked_metadata("float array q4 =\n\t-0.1, 0.2")

    def test_invalid_variable_name(self, parse_input_mocked_metadata):
        """Test that a variable using the reserved name for a blackbird keyword returns an exception"""
        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float name = 5')

        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float target = 5')

        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float version = 5')

        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float array name =\n\t-0.1, 0.2')

        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float array target =\n\t-0.1, 0.2')

        with pytest.raises(SystemExit, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata('float array version =\n\t-0.1, 0.2')

    def test_integer_variable(self, parse_input_mocked_metadata):
        """Test that an integer variable is correctly parsed"""
        bb = parse_input_mocked_metadata('int n = 5')
        assert bb.var == {'n': 5}

    def test_float_variable(self, parse_input_mocked_metadata):
        """Test that a float variable is correctly parsed"""
        bb = parse_input_mocked_metadata("float alpha = -0.5432")
        assert bb.var == {'alpha': -0.5432}

    def test_float_exponent_variable(self, parse_input_mocked_metadata):
        """Test that a float variable with an exponent is correctly parsed"""
        bb = parse_input_mocked_metadata("float alpha = -9.54e-3")
        assert bb.var == {'alpha': -9.54e-3}

    def test_complex_variable(self, parse_input_mocked_metadata):
        """Test that a complex variable is correctly parsed"""
        bb = parse_input_mocked_metadata("complex Beta = -0.231+5.21j")
        assert bb.var == {'Beta': -0.231+5.21j}

    def test_complex_exponent_variable(self, parse_input_mocked_metadata):
        """Test that a complex variable with an exponent is correctly parsed"""
        bb = parse_input_mocked_metadata("complex Beta = -0.231e-6+5.21e-2j")
        assert bb.var == {'Beta': -0.231e-6+5.21e-2j}

    def test_pi_variable(self, parse_input_mocked_metadata):
        """Test that pi can be parsed"""
        bb = parse_input_mocked_metadata("float test = pi")
        assert bb.var == {'test': np.pi}

    def test_string_variable(self, parse_input_mocked_metadata):
        """Test that string can be parsed"""
        bb = parse_input_mocked_metadata('str username = "Josh"')
        assert bb.var == {'username': "Josh"}

    def test_bool_variable(self, parse_input_mocked_metadata):
        """Test that bool can be parsed"""
        bb = parse_input_mocked_metadata('bool b1 = True\n bool b2 = False')
        assert bb.var == {'b1': True, 'b2': False}

    def test_float_array_variable(self, parse_input_mocked_metadata):
        """Test that float array can be parsed"""
        bb = parse_input_mocked_metadata("float array C =\n\t-0.1, 0.2")
        assert np.all(bb.var['C'] == np.array([[-0.1, 0.2]]))

    def test_complex_array_variable(self, parse_input_mocked_metadata):
        """Test that complex array can be parsed"""
        bb = parse_input_mocked_metadata("complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j")
        assert np.all(bb.var['A'] == np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]]))

    def test_complex_array_shape_variable(self, parse_input_mocked_metadata):
        """Test that complex array with shape can be parsed"""
        bb = parse_input_mocked_metadata("complex array A[2, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j")
        assert np.all(bb.var['A'] == np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]]))

    def test_invalid_expression_type(self, parse_input_mocked_metadata):
        """Test exception is raised if the expression variable type is incorrect"""
        with pytest.raises(TypeError, match=r"not of declared type int"):
            parse_input_mocked_metadata("int Beta = -0.231e-6+5.21e-2j")

    def test_invalid_array_type(self, parse_input_mocked_metadata):
        """Test exception is raised if the array variable type is incorrect"""
        with pytest.raises(SystemExit, match=r"not of declared type float"):
            parse_input_mocked_metadata("float array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j")

    def test_invalid_array_shape(self, parse_input_mocked_metadata):
        """Test exception is raised if the array variable shape is incorrect"""
        with pytest.raises(SystemExit, match=r"has declared shape \(1, 2\) but actual shape \(2, 2\)"):
            parse_input_mocked_metadata("complex array A[1, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j")

    def test_variable_expression(self, parse_input_mocked_metadata):
        """Test that a variable expression is correctly parsed"""
        bb = parse_input_mocked_metadata("float alpha = 0.32\nfloat gamma = (2.0*cos(alpha*pi)+1)**2")
        assert bb.var['gamma'] == (2.0*np.cos(0.32*np.pi)+1)**2

    def test_array_variable_expression(self, parse_input_mocked_metadata):
        """Test that a variable expression containing arrays is correctly parsed"""
        bb = parse_input_mocked_metadata("complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j\ncomplex res = (2.0*cos(A*pi)+1)**2")
        A = np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]])
        assert np.all(bb.var['res'] == (2.0*np.cos(A*np.pi)+1)**2)


class TestParsingQuantumPrograms:
    """Tests for parsing quantum programs"""

    def test_operation_no_args(self, parse_input_mocked_metadata):
        """Test that an operation with no arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Vac | 0\n")
        assert bb.queue == [{'modes': [0], 'op': 'Vac'}]

    def test_measure_no_args(self, parse_input_mocked_metadata):
        """Test that a measurement with no args is correctly parsed"""
        bb = parse_input_mocked_metadata("Measure | 0\n")
        assert bb.queue == [{'modes': [0], 'op': 'Measure'}]

    @pytest.mark.parametrize('modes', ['[0, 1, 2, 5]', '0, 1, 2, 5'])
    def test_multiple_modes(self, parse_input_mocked_metadata, modes):
        """Test that multiple modes are correctly parsed"""
        bb = parse_input_mocked_metadata("Vac | {}\n".format(modes))
        assert bb.queue == [{'modes': [0, 1, 2, 5], 'op': 'Vac'}]

    @pytest.mark.parametrize('arg', ['-0.3+2j', '0', '1e-3'])
    def test_operation_single_arg(self, parse_input_mocked_metadata, arg):
        """Test that an operation with one argument is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent({}) | 0\n".format(arg))
        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [complex(arg)], 'kwargs': {}}]

    def test_operation_multiple_arg(self, parse_input_mocked_metadata):
        """Test that an operation with multiple arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent(-0.3+2j, 0, 1e-3) | 0\n")
        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [-0.3+2j, 0, 1e-3], 'kwargs': {}}]

    def test_operation_kwarg(self, parse_input_mocked_metadata):
        """Test that an operation with keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent(alpha=-0.3+2j) | 0\n")
        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [], 'kwargs': {'alpha':-0.3+2j}}]

    def test_operation_multiple_kwarg(self, parse_input_mocked_metadata):
        """Test that an operation with multiple keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("MeasureHomodyne(phi=0.23, b=1) | 0\n")
        assert bb.queue == [{'modes': [0], 'op': 'MeasureHomodyne', 'args': [], 'kwargs': {'phi':0.23, 'b':1}}]

    # @pytest.mark.skip()
    # def test_operation_args_and_kwarg(self, parse_input):
    #     """Test that an operation with multiple args/keyword arguments is correctly parsed
    #     NOTE: This is currently not supported by the parser."""
    #     bb = parse_input("MeasureHomodyne(0.23, post_select=0.41) | 0\n")
    #     assert bb.queue == [{'modes': [0], 'op': 'MeasureHomodyne', 'args': [0.23], 'kwargs': {'post_select':0.41}}]

    def test_operation_arg_expressions(self, parse_input_mocked_metadata):
        """Test that expressions inside arguments are properly evaluated"""
        bb = parse_input_mocked_metadata("float alpha = 0.5\nfloat Delta=sqrt(2)\nCoherent(alpha**2.0, Delta*sqrt(pi), 0.2*10) | 0\n")

        alpha = 0.5
        Delta = np.sqrt(2)
        expected = [alpha**2, Delta*np.sqrt(np.pi), 0.2*10]

        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': expected, 'kwargs': {}}]

    def test_operation_arg_array(self, parse_input_mocked_metadata):
        """Test that arrays inside arguments are properly evaluated"""
        bb = parse_input_mocked_metadata("float array A =\n\t1, 5\nGaussian(means=A) | 0\n")
        assert np.all(bb.queue[0]['kwargs']['means'] == np.array([[1, 5]]))


class TestParsingMetadata:
    """Tests for parsing quantum devices"""

    def test_target_name(self, parse_input):
        """Test that device name is extracted"""
        bb = parse_input("name testname\nversion 1.0\ntarget example")
        assert bb.target['name'] == "example"

    def test_device_kwarg(self, parse_input):
        """Test that an device with keyword arguments is correctly parsed"""
        bb = parse_input("name testname\nversion 1.0\ntarget example (shots=10, hbar=0.2)")
        assert bb.target['options'] == {"shots": 10, "hbar": 0.2}


class TestRegRefTransform:
    """Tests for the RegRefTransform class"""

    def test_initialize(self):
        """Test initialization using a SymPy function"""
        q0 = sym.Symbol('q0')
        q2 = sym.Symbol('q2')
        f = (q0-q2)/np.sqrt(2)

        rrt = RegRefTransform(f)

        assert rrt.func_str == "0.707106781186547*q0 - 0.707106781186547*q2"
        assert set(rrt.regrefs) == {0, 2}

        if rrt.regrefs == [0, 2]:
            assert np.allclose(rrt.func(0.543, -0.432), (0.543+0.432)/np.sqrt(2))

        if rrt.regrefs == [2, 0]:
            assert np.allclose(rrt.func(0.543, -0.432), (-0.432-0.543)/np.sqrt(2))

    def test_str(self):
        """Test string representation of a RegRefTransform"""
        q0 = sym.Symbol('q0')
        q2 = sym.Symbol('q2')
        f = (q0+q2)/np.sqrt(2)

        rrt = RegRefTransform(f)

        assert rrt.__str__() == "0.707106781186547*q0 + 0.707106781186547*q2"


class TestParseFunction:
    """Tests for the `parse_blackbird` convenience parsing function"""

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_parse_file(self, tmpdir):
        """Test that device name is extracted"""
        filename = tmpdir.join('test.xbb')

        with open(filename, 'w') as f:
            f.write(test_file)

        bb = parse_blackbird(filename)

        assert bb.var == {"alpha": 0.3423}

        expected = {"name": 'fock', 'options': {'num_subsystems':1, 'cutoff_dim':7, 'shots':10}}
        assert bb.target == expected

        expected = [
            {'op': 'Coherent', 'args': [0.3423, np.sqrt(np.pi)], 'kwargs':{}, 'modes': [0]},
            {'op': 'MeasureFock', 'args': [], 'kwargs':{}, 'modes': [0]}
            ]

        assert bb.queue == expected
