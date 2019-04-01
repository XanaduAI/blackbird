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
# pylint: disable=too-many-ancestors,no-self-use,redefined-outer-name,too-many-arguments,no-value-for-parameter,too-few-public-methods
import pytest

import numpy as np

import antlr4

from blackbird.blackbirdLexer import blackbirdLexer
from blackbird.blackbirdParser import blackbirdParser
from blackbird.listener import BlackbirdListener, parse_blackbird


test_file = """
# a test blackbird script

float alpha = 0.3423

with fock(num_subsystems=1, cutoff_dim=7, shots=10):
    Coherent(alpha, sqrt(pi)) | 0
    MeasureFock() | 0
"""


@pytest.fixture
def device():
    """Mock out the device inside the blackbird parser"""
    class DummyDeviceContext:
        """Dummy device context with mocked out device name"""
        getText = lambda self: "MockedDevice"
    return DummyDeviceContext


@pytest.fixture
def parser():
    """Create a parser for the test"""
    def _parser(text):
        """The parser fixture accepts a blackbird string to parse"""
        lexer = blackbirdLexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = blackbirdParser(stream)
        return parser
    return _parser


class TestParsingVariables:
    """Tests for parsing variable declarations"""

    def test_integer_variable(self, parser, device, monkeypatch):
        """Test that an integer variable is correctly parsed"""
        parser = parser("int n = 5")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'n': 5}

    def test_float_variable(self, parser, device, monkeypatch):
        """Test that a float variable is correctly parsed"""
        parser = parser("float alpha = -0.5432")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'alpha': -0.5432}

    def test_float_exponent_variable(self, parser, device, monkeypatch):
        """Test that a float variable with an exponent is correctly parsed"""
        parser = parser("float alpha = -9.54e-3")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'alpha': -9.54e-3}

    def test_complex_variable(self, parser, device, monkeypatch):
        """Test that a complex variable is correctly parsed"""
        parser = parser("complex Beta = -0.231+5.21j")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'Beta': -0.231+5.21j}

    def test_complex_exponent_variable(self, parser, device, monkeypatch):
        """Test that a complex variable with an exponent is correctly parsed"""
        parser = parser("complex Beta = -0.231e-6+5.21e-2j")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'Beta': -0.231e-6+5.21e-2j}

    def test_pi_variable(self, parser, device, monkeypatch):
        """Test that pi can be parsed"""
        parser = parser("float test = pi")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'test': np.pi}

    def test_string_variable(self, parser, device, monkeypatch):
        """Test that string can be parsed"""
        parser = parser('str name = "Josh"')
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'name': "Josh"}

    def test_bool_variable(self, parser, device, monkeypatch):
        """Test that bool can be parsed"""
        parser = parser('bool b1 = True\n bool b2 = False')
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var == {'b1': True, 'b2': False}

    def test_float_array_variable(self, parser, device, monkeypatch):
        """Test that float array can be parsed"""
        parser = parser("float array C =\n\t-0.1, 0.2")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert np.all(bb.var['C'] == np.array([[-0.1, 0.2]]))

    def test_complex_array_variable(self, parser, device, monkeypatch):
        """Test that complex array can be parsed"""
        text = "complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert np.all(bb.var['A'] == np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]]))

    def test_complex_array_shape_variable(self, parser, device, monkeypatch):
        """Test that complex array with shape can be parsed"""
        text = "complex array A[2, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert np.all(bb.var['A'] == np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]]))

    def test_invalid_expression_type(self, parser, device, monkeypatch):
        """Test exception is raised if the expression variable type is incorrect"""
        text = "int Beta = -0.231e-6+5.21e-2j"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            with pytest.raises(TypeError, match=r"not of declared type int"):
                walker.walk(bb, tree)

    def test_invalid_array_type(self, parser, device, monkeypatch):
        """Test exception is raised if the array variable type is incorrect"""
        text = "float array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            with pytest.raises(TypeError, match=r"not of declared type float"):
                walker.walk(bb, tree)

    def test_invalid_array_shape(self, parser, device, monkeypatch):
        """Test exception is raised if the array variable shape is incorrect"""
        text = "complex array A[1, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            with pytest.raises(TypeError, match=r"has declared shape \(1, 2\) but actual shape \(2, 2\)"):
                walker.walk(bb, tree)

    def test_variable_expression(self, parser, device, monkeypatch):
        """Test that a variable expression is correctly parsed"""
        text = "float alpha = 0.32\nfloat gamma = (2.0*cos(alpha*pi)+1)**2"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        assert bb.var['gamma'] == (2.0*np.cos(0.32*np.pi)+1)**2

    def test_array_variable_expression(self, parser, device, monkeypatch):
        """Test that a variable expression containing arrays is correctly parsed"""
        text = "complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j\ncomplex res = (2.0*cos(A*pi)+1)**2"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()

        with monkeypatch.context() as m:
            m.setattr("blackbird.blackbirdParser.blackbirdParser.ProgramContext.device", device)
            walker.walk(bb, tree)

        A = np.array([[-1.0+1.0j, 2.7e5+0.2e-5j], [-0.1-2j, 0.2-0.1j]])
        assert np.all(bb.var['res'] == (2.0*np.cos(A*np.pi)+1)**2)


class TestParsingQuantumPrograms:
    """Tests for parsing quantum programs"""

    def test_operation_no_args(self, parser):
        """Test that an operation with no arguments is correctly parsed"""
        parser = parser("with device:\n\tVac | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'Vac'}]

    def test_measure_no_args(self, parser):
        """Test that a measurement with no args is correctly parsed"""
        parser = parser("with device:\n\tMeasure | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'Measure'}]

    @pytest.mark.parametrize('modes', ['[0, 1, 2, 5]', '0, 1, 2, 5'])
    def test_multiple_modes(self, parser, modes):
        """Test that multiple modes are correctly parsed"""
        parser = parser("with device:\n\tVac | {}\n".format(modes))
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0, 1, 2, 5], 'op': 'Vac'}]

    @pytest.mark.parametrize('arg', ['-0.3+2j', '0', '1e-3'])
    def test_operation_single_arg(self, parser, arg):
        """Test that an operation with one argument is correctly parsed"""
        parser = parser("with device:\n\tCoherent({}) | 0\n".format(arg))
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [complex(arg)], 'kwargs': {}}]

    def test_operation_multiple_arg(self, parser):
        """Test that an operation with multiple arguments is correctly parsed"""
        parser = parser("with device:\n\tCoherent(-0.3+2j, 0, 1e-3) | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [-0.3+2j, 0, 1e-3], 'kwargs': {}}]

    def test_operation_kwarg(self, parser):
        """Test that an operation with keyword arguments is correctly parsed"""
        parser = parser("with device:\n\tCoherent(alpha=-0.3+2j) | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': [], 'kwargs': {'alpha':-0.3+2j}}]

    def test_operation_multiple_kwarg(self, parser):
        """Test that an operation with multiple keyword arguments is correctly parsed"""
        parser = parser("with device:\n\tMeasureHomodyne(phi=0.23, b=1) | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.queue == [{'modes': [0], 'op': 'MeasureHomodyne', 'args': [], 'kwargs': {'phi':0.23, 'b':1}}]

    # @pytest.mark.skip()
    # def test_operation_args_and_kwarg(self, parser):
    #     """Test that an operation with multiple args/keyword arguments is correctly parsed
    #     NOTE: This is currently not supported by the parser."""
    #     parser = parser("with device:\n\tMeasureHomodyne(0.23, post_select=0.41) | 0\n")
    #     tree = parser.start()

    #     bb = BlackbirdListener()
    #     walker = antlr4.ParseTreeWalker()
    #     walker.walk(bb, tree)

    #     assert bb.queue == [{'modes': [0], 'op': 'MeasureHomodyne', 'args': [0.23], 'kwargs': {'post_select':0.41}}]

    def test_operation_arg_expressions(self, parser):
        """Test that expressions inside arguments are properly evaluated"""
        text = "float alpha = 0.5\nfloat Delta=sqrt(2)\nwith device:\n\tCoherent(alpha**2.0, Delta*sqrt(pi), 0.2*10) | 0\n"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        alpha = 0.5
        Delta = np.sqrt(2)
        expected = [alpha**2, Delta*np.sqrt(np.pi), 0.2*10]

        assert bb.queue == [{'modes': [0], 'op': 'Coherent', 'args': expected, 'kwargs': {}}]

    def test_operation_arg_array(self, parser):
        """Test that arrays inside arguments are properly evaluated"""
        text = "float array A =\n\t1, 5\nwith device:\n\tGaussian(means=A) | 0\n"
        parser = parser(text)
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert np.all(bb.queue[0]['kwargs']['means'] == np.array([[1, 5]]))


class TestParsingDevice:
    """Tests for parsing quantum devices"""

    def test_device_name(self, parser):
        """Test that device name is extracted"""
        parser = parser("with example:\n\tVac | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.device['name'] == "example"

    def test_device_kwarg(self, parser):
        """Test that an device with keyword arguments is correctly parsed"""
        parser = parser("with example(shots=10, hbar=0.2):\n\tVac | 0\n")
        tree = parser.start()

        bb = BlackbirdListener()
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        assert bb.device['kwargs'] == {"shots": 10, "hbar": 0.2}


class TestParseFunction:
    """Tests for parsing function"""

    def test_parse_file(self, tmpdir):
        """Test that device name is extracted"""
        filename = tmpdir.join('test.xbb')

        with open(filename, 'w') as f:
            f.write(test_file)

        bb = parse_blackbird(filename)

        assert bb.var == {"alpha": 0.3423}

        expected = {"name": 'fock', 'kwargs': {'num_subsystems':1, 'cutoff_dim':7, 'shots':10}, 'args':[]}
        assert bb.device == expected

        expected = [
            {'op': 'Coherent', 'args': [0.3423, np.sqrt(np.pi)], 'kwargs':{}, 'modes': [0]},
            {'op': 'MeasureFock', 'args': [], 'kwargs':{}, 'modes': [0]}
            ]

        assert bb.queue == expected
