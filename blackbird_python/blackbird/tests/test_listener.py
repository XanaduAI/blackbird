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
import textwrap

import pytest

import numpy as np
import sympy as sym

import antlr4

from blackbird.blackbirdLexer import blackbirdLexer
from blackbird.blackbirdParser import blackbirdParser
from blackbird.listener import BlackbirdListener, RegRefTransform, parse
from blackbird.error import BlackbirdSyntaxError


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

    def _parse_input(text, cwd=None):
        """The parser fixture accepts a blackbird string to parse"""
        lexer = blackbirdLexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = blackbirdParser(stream)

        tree = parser.start()

        bb = BlackbirdListener(cwd=cwd)
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)
        return bb.program

    return _parse_input


@pytest.fixture
def parse_input_mocked_metadata(monkeypatch):
    """Create a parser for the test that mocks out the metadata"""

    def _parse_input(text, cwd=None):
        """The parser fixture accepts a blackbird string to parse"""
        text = "name mockname\nversion 1.0\n" + text
        lexer = blackbirdLexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = blackbirdParser(stream)

        tree = parser.start()

        bb = BlackbirdListener(cwd=cwd)
        walker = antlr4.ParseTreeWalker()
        walker.walk(bb, tree)

        return bb.program

    return _parse_input


class TestParsingVariables:
    """Tests for parsing variable declarations"""

    def test_invalid_regref(self, parse_input_mocked_metadata):
        """Test that a variable using the reserved name for regrefs returns an exception"""
        with pytest.raises(BlackbirdSyntaxError, match="reserved for register references"):
            parse_input_mocked_metadata("float q0 = 5")

        with pytest.raises(BlackbirdSyntaxError, match="reserved for register references"):
            parse_input_mocked_metadata("float array q4 =\n\t-0.1, 0.2")

    def test_invalid_variable_name(self, parse_input_mocked_metadata):
        """Test that a variable using the reserved name for a blackbird keyword returns an exception"""
        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float name = 5")

        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float target = 5")

        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float version = 5")

        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float array name =\n\t-0.1, 0.2")

        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float array target =\n\t-0.1, 0.2")

        with pytest.raises(BlackbirdSyntaxError, match="reserved Blackbird keyword"):
            parse_input_mocked_metadata("float array version =\n\t-0.1, 0.2")

    def test_integer_variable(self, parse_input_mocked_metadata):
        """Test that an integer variable is correctly parsed"""
        bb = parse_input_mocked_metadata("int n = 5")
        assert bb._var == {"n": 5}

    def test_float_variable(self, parse_input_mocked_metadata):
        """Test that a float variable is correctly parsed"""
        bb = parse_input_mocked_metadata("float alpha = -0.5432")
        assert bb._var == {"alpha": -0.5432}

    def test_float_exponent_variable(self, parse_input_mocked_metadata):
        """Test that a float variable with an exponent is correctly parsed"""
        bb = parse_input_mocked_metadata("float alpha = -9.54e-3")
        assert bb._var == {"alpha": -9.54e-3}

    def test_complex_variable(self, parse_input_mocked_metadata):
        """Test that a complex variable is correctly parsed"""
        bb = parse_input_mocked_metadata("complex Beta = -0.231+5.21j")
        assert bb._var == {"Beta": -0.231 + 5.21j}

    def test_complex_exponent_variable(self, parse_input_mocked_metadata):
        """Test that a complex variable with an exponent is correctly parsed"""
        bb = parse_input_mocked_metadata("complex Beta = -0.231e-6+5.21e-2j")
        assert bb._var == {"Beta": -0.231e-6 + 5.21e-2j}

    def test_pi_variable(self, parse_input_mocked_metadata):
        """Test that pi can be parsed"""
        bb = parse_input_mocked_metadata("float test = pi")
        assert bb._var == {"test": np.pi}

    def test_string_variable(self, parse_input_mocked_metadata):
        """Test that string can be parsed"""
        bb = parse_input_mocked_metadata('str username = "Josh"')
        assert bb._var == {"username": "Josh"}

    def test_bool_variable(self, parse_input_mocked_metadata):
        """Test that bool can be parsed"""
        bb = parse_input_mocked_metadata("bool b1 = True\n bool b2 = False")
        assert bb._var == {"b1": True, "b2": False}

    def test_float_array_variable(self, parse_input_mocked_metadata):
        """Test that float array can be parsed"""
        bb = parse_input_mocked_metadata("float array C =\n\t-0.1, 0.2")
        assert np.all(bb._var["C"] == np.array([[-0.1, 0.2]]))

    def test_complex_array_variable(self, parse_input_mocked_metadata):
        """Test that complex array can be parsed"""
        bb = parse_input_mocked_metadata(
            "complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        )
        assert np.all(
            bb._var["A"] == np.array([[-1.0 + 1.0j, 2.7e5 + 0.2e-5j], [-0.1 - 2j, 0.2 - 0.1j]])
        )

    def test_complex_array_shape_variable(self, parse_input_mocked_metadata):
        """Test that complex array with shape can be parsed"""
        bb = parse_input_mocked_metadata(
            "complex array A[2, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
        )
        assert np.all(
            bb._var["A"] == np.array([[-1.0 + 1.0j, 2.7e5 + 0.2e-5j], [-0.1 - 2j, 0.2 - 0.1j]])
        )

    def test_invalid_expression_type(self, parse_input_mocked_metadata):
        """Test exception is raised if the expression variable type is incorrect"""
        with pytest.raises(TypeError, match=r"not of declared type int"):
            parse_input_mocked_metadata("int Beta = -0.231e-6+5.21e-2j")

    def test_invalid_array_type(self, parse_input_mocked_metadata):
        """Test exception is raised if the array variable type is incorrect"""
        with pytest.raises(BlackbirdSyntaxError, match=r"not of declared type float"):
            parse_input_mocked_metadata(
                "float array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
            )

    def test_invalid_array_shape(self, parse_input_mocked_metadata):
        """Test exception is raised if the array variable shape is incorrect"""
        with pytest.raises(
            BlackbirdSyntaxError, match=r"has declared shape \(1, 2\) but actual shape \(2, 2\)"
        ):
            parse_input_mocked_metadata(
                "complex array A[1, 2] =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j"
            )

    def test_variable_expression(self, parse_input_mocked_metadata):
        """Test that a variable expression is correctly parsed"""
        bb = parse_input_mocked_metadata(
            "float alpha = 0.32\nfloat gamma = (2.0*cos(alpha*pi)+1)**2"
        )
        assert bb._var["gamma"] == (2.0 * np.cos(0.32 * np.pi) + 1) ** 2

    def test_array_variable_expression(self, parse_input_mocked_metadata):
        """Test that a variable expression containing arrays is correctly parsed"""
        bb = parse_input_mocked_metadata(
            "complex array A =\n\t-1.0+1.0j, 2.7e5+0.2e-5j\n\t-0.1-2j, 0.2-0.1j\ncomplex res = (2.0*cos(A*pi)+1)**2"
        )
        A = np.array([[-1.0 + 1.0j, 2.7e5 + 0.2e-5j], [-0.1 - 2j, 0.2 - 0.1j]])
        assert np.all(bb._var["res"] == (2.0 * np.cos(A * np.pi) + 1) ** 2)


class TestParsingQuantumPrograms:
    """Tests for parsing quantum programs"""

    def test_operation_no_args(self, parse_input_mocked_metadata):
        """Test that an operation with no arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Vac | 0\n")
        assert bb.operations == [{"modes": [0], "op": "Vac"}]

    def test_measure_no_args(self, parse_input_mocked_metadata):
        """Test that a measurement with no args is correctly parsed"""
        bb = parse_input_mocked_metadata("Measure | 0\n")
        assert bb.operations == [{"modes": [0], "op": "Measure"}]

    @pytest.mark.parametrize("modes", ["[0, 1, 2, 5]", "0, 1, 2, 5"])
    def test_multiple_modes(self, parse_input_mocked_metadata, modes):
        """Test that multiple modes are correctly parsed"""
        bb = parse_input_mocked_metadata("Vac | {}\n".format(modes))
        assert bb.operations == [{"modes": [0, 1, 2, 5], "op": "Vac"}]

    @pytest.mark.parametrize("arg", ["-0.3+2j", "0", "1e-3"])
    def test_operation_single_arg(self, parse_input_mocked_metadata, arg):
        """Test that an operation with one argument is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent({}) | 0\n".format(arg))
        assert bb.operations == [
            {"modes": [0], "op": "Coherent", "args": [complex(arg)], "kwargs": {}}
        ]

    def test_operation_multiple_arg(self, parse_input_mocked_metadata):
        """Test that an operation with multiple arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent(-0.3+2j, 0, 1e-3) | 0\n")
        assert bb.operations == [
            {"modes": [0], "op": "Coherent", "args": [-0.3 + 2j, 0, 1e-3], "kwargs": {}}
        ]

    def test_operation_kwarg(self, parse_input_mocked_metadata):
        """Test that an operation with keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("Coherent(alpha=-0.3+2j) | 0\n")
        assert bb.operations == [
            {"modes": [0], "op": "Coherent", "args": [], "kwargs": {"alpha": -0.3 + 2j}}
        ]

    @pytest.mark.parametrize("dc", [[1, 3], 0, [1]])
    def test_operation_kwarglist(self, parse_input_mocked_metadata, dc):
        """Test that an operation with keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("MeasureFock(dark_counts={}) | [0, 1]\n".format(dc))

        # change element-type to int for comparison
        if isinstance(dc, list):
            dc = [int(i) for i in dc]
        else:
            dc = int(dc)

        assert bb.operations == [
            {"modes": [0, 1], "op": "MeasureFock", "args": [], "kwargs": {"dark_counts": dc}}
        ]

    @pytest.mark.parametrize("dc", [[]])
    def test_operation_empty_kwarglist(self, parse_input_mocked_metadata, dc):
        """Test that an operation with empty keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("MeasureFock(dark_counts={}) | [0, 1]\n".format(dc))

        # change element-type to int for comparison
        dc = [int(i) for i in dc]

        assert bb.operations == [
            {"modes": [0, 1], "op": "MeasureFock", "args": [], "kwargs": {}}
        ]

    def test_operation_multiple_kwarg(self, parse_input_mocked_metadata):
        """Test that an operation with multiple keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata("MeasureHomodyne(phi=0.23, b=1) | 0\n")
        assert bb.operations == [
            {"modes": [0], "op": "MeasureHomodyne", "args": [], "kwargs": {"phi": 0.23, "b": 1}}
        ]

    def test_operation_args_and_kwarg(self, parse_input_mocked_metadata):
        """Test that an operation with multiple args/keyword arguments is correctly parsed"""
        bb = parse_input_mocked_metadata('MeasureHomodyne(0.23, 0.54, select=0.41, hi="yes") | 0\n')
        assert bb.operations == [
            {
                "modes": [0],
                "op": "MeasureHomodyne",
                "args": [0.23, 0.54],
                "kwargs": {"select": 0.41, "hi": "yes"},
            }
        ]

    @pytest.mark.parametrize("dc", [[1, 3], [1], 0, [True, 0]])
    def test_operation_args_kwarg_kwarglist(self, parse_input_mocked_metadata, dc):
        """Test that an operation with multiple args/kwargs, with lists, is correctly parsed"""
        bb = parse_input_mocked_metadata(
            'MeasureHomodyne(0.23, 0.54, select={}, hi="yes") | 0\n'.format(dc)
            )
        assert bb.operations == [
            {
                "modes": [0],
                "op": "MeasureHomodyne",
                "args": [0.23, 0.54],
                "kwargs": {"select": dc, "hi": "yes"},
            }
        ]

    def test_operation_arg_expressions(self, parse_input_mocked_metadata):
        """Test that expressions inside arguments are properly evaluated"""
        bb = parse_input_mocked_metadata(
            "float alpha = 0.5\nfloat Delta=sqrt(2)\nCoherent(alpha**2.0, Delta*sqrt(pi), 0.2*10) | 0\n"
        )

        alpha = 0.5
        Delta = np.sqrt(2)
        expected = [alpha ** 2, Delta * np.sqrt(np.pi), 0.2 * 10]

        assert bb.operations == [{"modes": [0], "op": "Coherent", "args": expected, "kwargs": {}}]

    def test_operation_mode_expressions(self, parse_input_mocked_metadata):
        """Test that expressions inside modes are properly evaluated"""
        bb = parse_input_mocked_metadata(
            "int m = 4\nMZgate(0, 1) | [m*2, -1+m]"
        )
        assert bb.operations == [{'op': 'MZgate', 'args': [0, 1], 'kwargs': {}, 'modes': [8, 3]}]

    @pytest.mark.parametrize("arr", ["\t{phase_0}\n\t{phase_1}\n", "\t{phase_0}, {phase_1}\n"])
    def test_parameter_idx(self, arr, parse_input_mocked_metadata):
        """Test that parameter array indexing works inside arguments"""
        bb = parse_input_mocked_metadata(
            "par array phases =\n{}\nMZgate(phases[0], phases[1]) | [0, 1]".format(arr)
        )
        assert bb.operations == [
            {'op': 'MZgate', 'args': [sym.Symbol("phase_0"), sym.Symbol("phase_1")], 'kwargs': {}, 'modes': [0, 1]}
        ]

    @pytest.mark.parametrize("arr", ["\t1\n\t2\n\t3\n", "\t1, 2, 3\n", "\t1, 2\n\t3, 4\n"])
    def test_var_idx_in_modes(self, arr, parse_input_mocked_metadata):
        """Test that array indexing works inside modes"""
        bb = parse_input_mocked_metadata(
            "int array vars =\n{}\nMZgate(0, 1) | [vars[0], vars[1], vars[2]]".format(arr)
        )
        assert bb.operations == [
            {'op': 'MZgate', 'args': [0, 1], 'kwargs': {}, 'modes': [1, 2, 3]}
        ]

    def test_var_idx_in_args(self, parse_input_mocked_metadata):
        """Test that array indexing works inside arguments"""
        bb = parse_input_mocked_metadata(
            "float array vars =\n\t0.5, 1\n\nMZgate(vars[0], vars[1]) | [0, 1]"
        )
        assert bb.operations == [
            {'op': 'MZgate', 'args': [0.5, 1.0], 'kwargs': {}, 'modes': [0, 1]}
        ]

    def test_operation_arg_array(self, parse_input_mocked_metadata):
        """Test that arrays inside arguments are properly evaluated"""
        bb = parse_input_mocked_metadata("float array A =\n\t1, 5\nGaussian(means=A) | 0\n")
        assert np.all(bb.operations[0]["kwargs"]["means"] == np.array([[1, 5]]))

    def test_free_parameters(self, parse_input_mocked_metadata):
        """Test that free parameters are correctly extracted"""
        bb = parse_input_mocked_metadata(
            "float alpha = 0.5\nfloat Delta=sqrt(2)\nCoherent(alpha**{p}, Delta*sqrt(pi), 0.2*10) | 0\n"
        )

        p = sym.Symbol("p")
        alpha = 0.5
        Delta = np.sqrt(2)
        expected = [0.5 ** p, Delta * np.sqrt(np.pi), 0.2 * 10]

        assert bb.operations == [{"modes": [0], "op": "Coherent", "args": expected, "kwargs": {}}]

    def test_regref_transform(self, parse_input_mocked_metadata):
        """Test that regref transforms are correctly extracted"""
        bb = parse_input_mocked_metadata(
            "float alpha = 0.5\nfloat Delta=sqrt(2)\nCoherent(alpha*q0, Delta*sqrt(pi), 0.2*10) | 0\n"
        )

        p = sym.Symbol("q0")
        assert isinstance(bb.operations[0]["args"][0], RegRefTransform)
        assert bb.operations[0]["args"][0].func_str == str(0.5 * p)

    @pytest.mark.parametrize("m", [[3.5], ["4.2"], [1+2j], [True]])
    def test_non_integer_mode(self, m, parse_input_mocked_metadata):
        """Test that an error is used when setting non integer modes"""
        with pytest.raises(ValueError, match="Mode must be of type int, not"):
            bb = parse_input_mocked_metadata("MeasureFock() | {}".format(m))


class TestParsingMetadata:
    """Tests for parsing quantum devices"""

    def test_name(self, parse_input):
        """Test that device name is extracted"""
        bb = parse_input("name testname\nversion 1.0")
        assert bb.name == "testname"

    def test_version(self, parse_input):
        """Test that device name is extracted"""
        bb = parse_input("name testname\nversion 1.0")
        assert bb.version == "1.0"

        bb = parse_input("name testname\nversion 1.12")
        assert bb.version == "1.12"

    def test_target_name(self, parse_input):
        """Test that device name is extracted"""
        bb = parse_input("name testname\nversion 1.0\ntarget example")
        assert bb.target["name"] == "example"

    def test_target_kwarg(self, parse_input):
        """Test that an device with keyword arguments is correctly parsed"""
        bb = parse_input("name testname\nversion 1.0\ntarget example (shots=10, hbar=0.2)")
        assert bb.target["options"] == {"shots": 10, "hbar": 0.2}

    def test_target_arg(self, parse_input):
        """Test that an device with positional arguments raises a warning"""
        with pytest.warns(SyntaxWarning, match="only accept keyword options"):
            parse_input("name testname\nversion 1.0\ntarget example (6)")


class TestParsingInclude:
    """Tests for the `include` statement"""

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_include_program(self, parse_input, tmpdir):
        """Test including a non-templated program"""
        program = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            float alpha = 0.3423
            Coherent(alpha, sqrt(pi)) | 0
            MeasureFock() | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(program)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation | 1
            """
        ).format(filename)

        bb = parse_input(test_include, cwd=tmpdir)

        expected = [
            {"op": "Coherent", "args": [0.3423, np.sqrt(np.pi)], "kwargs": {}, "modes": [1]},
            {"op": "MeasureFock", "args": [], "kwargs": {}, "modes": [1]},
        ]

        assert bb.operations == expected

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_include_template(self, parse_input, tmpdir):
        """Test including a templated program"""
        template = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            BSgate({theta}, pi/2) | [0, 1]
            Rgate({phi}) | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(template)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation(theta=0.54, phi=0.1) | [2, 1]
            """
        ).format(filename)

        bb = parse_input(test_include, cwd=tmpdir)

        expected = [
            {"op": "BSgate", "args": [0.54, np.pi / 2], "kwargs": {}, "modes": [2, 1]},
            {"op": "Rgate", "args": [0.1], "kwargs": {}, "modes": [2]},
        ]

        assert bb.operations == expected

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_nested_include(self, parse_input, tmpdir):
        """Test nested includes"""
        template1 = textwrap.dedent(
            """
            name MachZehnder
            version 0.0
            BSgate({theta}, pi/2) | [0, 1]
            Rgate({phi}) | 0
            """
        )

        filename1 = tmpdir.join("mach_zehnder.xbb")

        with open(filename1, "w") as f:
            f.write(template1)

        template2 = textwrap.dedent(
            """
            name Chip15
            version 0.0
            include "{}"
            S2gate({{sq}}) | [0, 1]
            MachZehnder(theta={{theta}}, phi={{phi}}) | [1, 2]
            """
        ).format(filename1)

        filename2 = tmpdir.join("chip15.xbb")

        with open(filename2, "w") as f:
            f.write(template2)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            Chip15(sq=0.5, theta=0.54, phi=0.1) | [0, 2, 1]
            """
        ).format(filename2)

        bb = parse_input(test_include, cwd=tmpdir)

        expected = [
            {"op": "S2gate", "args": [0.5], "kwargs": {}, "modes": [0, 2]},
            {"op": "BSgate", "args": [0.54, np.pi / 2], "kwargs": {}, "modes": [2, 1]},
            {"op": "Rgate", "args": [0.1], "kwargs": {}, "modes": [2]},
        ]

        assert bb.operations == expected

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_multiple_nested_include(self, parse_input, tmpdir):
        """Same as the above, but tests the case where the same file
        might be imported multiple times in different places."""
        template1 = textwrap.dedent(
            """
            name MachZehnder
            version 0.0
            BSgate({theta}, pi/2) | [0, 1]
            Rgate({phi}) | 0
            """
        )

        filename1 = tmpdir.join("mach_zehnder.xbb")

        with open(filename1, "w") as f:
            f.write(template1)

        template2 = textwrap.dedent(
            """
            name Chip15
            version 0.0
            include "{}"
            S2gate({{sq}}) | [0, 1]
            MachZehnder(theta={{theta}}, phi={{phi}}) | [1, 2]
            """
        ).format(filename1)

        filename2 = tmpdir.join("chip15.xbb")

        with open(filename2, "w") as f:
            f.write(template2)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            include "{}"
            Chip15(sq=0.5, theta=0.54, phi=0.1) | [0, 2, 1]
            """
        ).format(filename2, filename1)

        bb = parse_input(test_include, cwd=tmpdir)

        expected = [
            {"op": "S2gate", "args": [0.5], "kwargs": {}, "modes": [0, 2]},
            {"op": "BSgate", "args": [0.54, np.pi / 2], "kwargs": {}, "modes": [2, 1]},
            {"op": "Rgate", "args": [0.1], "kwargs": {}, "modes": [2]},
        ]

        assert bb.operations == expected

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_mismatched_modes(self, parse_input, tmpdir):
        """Test exception raised if modes do not match between
        applied subroutine and the defined template"""
        program = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            float alpha = 0.3423
            Coherent(alpha, sqrt(pi)) | 0
            MeasureFock() | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(program)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation | [0, 1]
            """
        ).format(filename)

        with pytest.raises(
            ValueError, match="CustomOperation acts on 1 modes, but 2 modes provided"
        ):
            bb = parse_input(test_include, cwd=tmpdir)

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_too_many_arguments(self, parse_input, tmpdir):
        """Test exception raised if wrong number of arguments are
        passed to a custom subroutine"""
        program = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            float alpha = 0.3423
            Coherent(alpha, sqrt(pi)) | 0
            MeasureFock() | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(program)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation() | 0
            """
        ).format(filename)

        with pytest.raises(ValueError, match="CustomOperation does not accept arguments"):
            bb = parse_input(test_include, cwd=tmpdir)

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_no_arguments(self, parse_input, tmpdir):
        """Test exception raised if custom subroutine accepts
        arguments, but none are passed:"""
        program = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            float alpha = 0.3423
            Coherent({alpha}, sqrt(pi)) | 0
            MeasureFock() | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(program)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation | 0
            """
        ).format(filename)

        with pytest.raises(ValueError, match="CustomOperation missing keyword arguments"):
            bb = parse_input(test_include, cwd=tmpdir)

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_invalid_arguments(self, parse_input, tmpdir):
        """Test exception raised if wrong keyword arguments are passed to a subroutine"""
        program = textwrap.dedent(
            """
            name CustomOperation
            version 0.0
            float alpha = 0.3423
            Coherent({alpha}, sqrt(pi)) | 0
            MeasureFock() | 0
            """
        )

        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(program)

        test_include = textwrap.dedent(
            """
            name test_include
            version 0.0
            include "{}"
            CustomOperation(sq=0.5) | 0
            """
        ).format(filename)

        with pytest.raises(
            ValueError, match="CustomOperation must accept only keyword arguments {'alpha'}"
        ):
            bb = parse_input(test_include, cwd=tmpdir)


class TestRegRefTransform:
    """Tests for the RegRefTransform class"""

    def test_initialize(self):
        """Test initialization using a SymPy function"""
        q0 = sym.Symbol("q0")
        q2 = sym.Symbol("q2")
        f = (q0 - q2) / np.sqrt(2)

        rrt = RegRefTransform(f)

        assert rrt.func_str == "0.707106781186547*q0 - 0.707106781186547*q2"
        assert set(rrt.regrefs) == {0, 2}

        if rrt.regrefs == [0, 2]:
            assert np.allclose(rrt.func(0.543, -0.432), (0.543 + 0.432) / np.sqrt(2))

        # Note: the order in which SymPy returns the variables of a symbolic function are
        # stochastic and may change at runtime. In this particular case, sometimes it returns
        # (q[0], q[2]) as the free variables, other times it returns (q[2], q[0]).
        #
        # This is not an issue during usage, as the Blackbird parser will always know the
        # correct order to apply the register arguments, but must be taken into account
        # during test assertions.
        if rrt.regrefs == [2, 0]:
            assert np.allclose(rrt.func(0.543, -0.432), (-0.432 - 0.543) / np.sqrt(2))

    def test_str(self):
        """Test string representation of a RegRefTransform"""
        q0 = sym.Symbol("q0")
        q2 = sym.Symbol("q2")
        f = (q0 + q2) / np.sqrt(2)

        rrt = RegRefTransform(f)

        assert rrt.__str__() == "0.707106781186547*q0 + 0.707106781186547*q2"


class TestParseFunction:
    """Tests for the `parse` convenience parsing function"""

    @pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
    def test_parse_file(self, tmpdir):
        """Test that device name is extracted"""
        filename = tmpdir.join("test.xbb")

        with open(filename, "w") as f:
            f.write(test_file)

        bb = parse(antlr4.FileStream(filename))

        assert bb._var == {"alpha": 0.3423}

        expected = {"name": "fock", "options": {"num_subsystems": 1, "cutoff_dim": 7, "shots": 10}}
        assert bb.target == expected

        expected = [
            {"op": "Coherent", "args": [0.3423, np.sqrt(np.pi)], "kwargs": {}, "modes": [0]},
            {"op": "MeasureFock", "args": [], "kwargs": {}, "modes": [0]},
        ]

        assert bb.operations == expected

    def test_parse_string(self):
        """Test that device name is extracted"""
        bb = parse(antlr4.InputStream(test_file))

        assert bb._var == {"alpha": 0.3423}

        expected = {"name": "fock", "options": {"num_subsystems": 1, "cutoff_dim": 7, "shots": 10}}
        assert bb.target == expected

        expected = [
            {"op": "Coherent", "args": [0.3423, np.sqrt(np.pi)], "kwargs": {}, "modes": [0]},
            {"op": "MeasureFock", "args": [], "kwargs": {}, "modes": [0]},
        ]

        assert bb.operations == expected


class TestParsingForLoops:
    """Tests for parsing for-loops correctly"""

    @pytest.mark.parametrize("modes", [[1, 2, 3], [1+2**2, -1+4, 4/2]])
    def test_for_loop(self, modes, parse_input_mocked_metadata):
        """Test that a for-loop over a list is parsed correctly"""
        bb = parse_input_mocked_metadata(
            "for int m in {}\n\tMeasureFock() | m".format(modes)
        )
        assert np.all(
            bb._forvar["m"] == np.array(modes)
        )
        assert bb.operations == [
            {'op': 'MeasureFock', 'args': [], 'kwargs': {}, 'modes': [modes[0]]},
            {'op': 'MeasureFock', 'args': [], 'kwargs': {}, 'modes': [modes[1]]},
            {'op': 'MeasureFock', 'args': [], 'kwargs': {}, 'modes': [modes[2]]}
        ]

    @pytest.mark.parametrize("rnge", ["2:10:3", "3:6"])
    def test_for_range(self, rnge, parse_input_mocked_metadata):
        """Test that a for-loop over a range is parsed correctly"""
        bb = parse_input_mocked_metadata(
            "for float m in {}\n\tMZgate(m, m/2) | [0, 1]".format(rnge)
        )
        # create a list out of the `rnge` string
        rnge_list = np.array(
            range(*np.array(rnge.split(":"), dtype=int)),
            dtype=float
        )

        assert np.all(bb._forvar["m"] == rnge_list)
        assert bb.operations == [
            {'op': 'MZgate', 'args': [rnge_list[0], rnge_list[0]/2], 'kwargs': {}, 'modes': [0, 1]},
            {'op': 'MZgate', 'args': [rnge_list[1], rnge_list[1]/2], 'kwargs': {}, 'modes': [0, 1]},
            {'op': 'MZgate', 'args': [rnge_list[2], rnge_list[2]/2], 'kwargs': {}, 'modes': [0, 1]}
        ]

    def test_wrong_type_error(self, parse_input_mocked_metadata):
        """Test that error is raised when using mixed types in for-loop list"""
        with pytest.raises(ValueError, match="invalid value"):
            bb = parse_input_mocked_metadata(
                "for int m in [1, 4.2, 9]\n\tMZgate(0, 1) | [0, 1]"
            )
