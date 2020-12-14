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

"""Tests for the program module"""
from textwrap import dedent
from collections import OrderedDict

import pytest

import numpy as np
import sympy as sym

from blackbird.program import BlackbirdProgram, numpy_to_blackbird
from blackbird import loads
from blackbird.error import BlackbirdSyntaxError


class TestNumPyToBlackbird:
    """Tests for the NumPy to Blackbird function"""

    def test_real_array(self):
        """Test real array is correctly formatted"""
        A = np.array([[0.453, 1, 0.213], [-0.543, 1.342, 1e-4]])
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = "float array A[2, 3] =\n    0.453, 1.0, 0.213\n    -0.543, 1.342, 0.0001\n"
        assert res == expected

    def test_int_array(self):
        """Test integer array is correctly formatted"""
        A = np.array([[1, -0, -15]])
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = "int array A[1, 3] =\n    1, 0, -15\n"
        assert res == expected

    def test_complex_array(self):
        """Test complex array is correctly formatted"""
        A = np.array([[0.453 - 0.543j, 1, 0.213 + 8j], [-0.543j, 1.342 + 0.5j, 1e-4 - 2e2j]])
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = dedent(
            """\
            complex array A[2, 3] =
                0.453-0.543j, 1.0+0.0j, 0.213+8.0j
                -0.0-0.543j, 1.342+0.5j, 0.0001-200.0j
            """
        )
        assert res == expected

    def test_unknown_array(self):
        """Test non-numeric array raises an exception"""
        A = np.array([True, False])

        with pytest.raises(ValueError, match="unsupported type"):
            numpy_to_blackbird(A, "A")


class TestBlackbirdProgram:
    """Basic unit tests for the program class"""

    def test_initialization(self):
        """Test all attributes correctly initialized"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        assert not bb._var

        assert bb.name == "prog"
        assert bb.version == 0.0
        assert not bb.modes

        assert bb.target["name"] is None
        assert not bb.target["options"]
        assert not bb.operations

        assert not len(bb)

        assert not bb.is_template()
        assert not bb.parameters

    def test_use_template(self):
        """Test templates can be initialized"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        x = sym.Symbol('x')
        hi = sym.Symbol('hi')
        bb._parameters = [str(x), str(hi)]
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [0.54/x**2], "kwargs": {'test': hi**4}})
        bb._operations.append({"op": "Sgate", "modes": [0], "args": [0.543], "kwargs": {}})
        bb._operations.append({"op": "Sgate", "modes": [0]})


        assert bb.parameters == {'x', 'hi'}
        assert bb.is_template()

        bb2 = bb(x=5, hi=2)
        assert not bb2.parameters
        assert not bb2.is_template()
        assert bb2.operations[0]["args"] == [0.54/5**2]
        assert bb2.operations[0]["kwargs"] == {'test': 2**4}
        assert bb.operations[1] == bb2.operations[1]

    def test_invalid_template_call_args(self):
        """Test templates raise exception if parameter operation argument values not passed"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        x = sym.Symbol('x')
        hi = sym.Symbol('hi')

        bb._parameters = [x, hi]
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [0.54/x**2], "kwargs": {'test': hi**4}})

        with pytest.raises(ValueError, match="Invalid value for free parameter provided"):
            bb(hi=4)

        with pytest.raises(ValueError, match="Invalid value for free parameter provided"):
            bb(x=4)

    def test_invalid_template_call_variables(self):
        """Test templates raise exception if parameter variable values not passed"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        y = sym.Symbol('y')
        bye = sym.Symbol('bye')

        bb._parameters = [y, bye]
        bb._var.update({"y": y, "bye": np.array([[1, 2, bye]])})

        with pytest.raises(ValueError, match="Invalid value for free parameter provided"):
            bb(bye=2)

        with pytest.raises(ValueError, match="Invalid value for free parameter provided"):
            bb(y=2)

    def test_not_template(self):
        """Test initializing a template fails if program is not a template"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [0.54/2**2], "kwargs": {'test': 1.0}})

        with pytest.raises(ValueError, match="Program is not a template"):
            bb()


class TestBlackbirdSerialize:
    """Test for serialization"""

    def test_serialize_empty(self):
        """Test serialization of an empty program"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        res = bb.serialize()
        assert res == "name prog\nversion 0.0\n"

    def test_serialize_target(self):
        """Test target serialization"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._target["name"] = "chip0"
        res = bb.serialize()
        assert res == "name prog\nversion 0.0\ntarget chip0\n"

        bb._target["options"] = OrderedDict(
            [("shots", 100), ("hbar", 0.2), ("real", True), ("str", "hi")]
        )
        res = bb.serialize()
        assert res == dedent(
            """\
            name prog
            version 0.0
            target chip0 (shots=100, hbar=0.2, real=True, str="hi")
            """
        )

    def test_serialize_operation_no_args(self):
        """Test serialization of an operation with no args"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Vac", "modes": [0]})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Vac | 0
            """
        )
        assert res == expected

    def test_serialize_operation_args(self):
        """Test serialization of an operation with 1 arg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [0.43 - 0.543j], "kwargs": {}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Dgate(0.43-0.543j) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_args(self):
        """Test serialization of an operation with many args"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Sgate", "modes": [0], "args": [0.43, 0.5432], "kwargs": {}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Sgate(0.43, 0.5432) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_kwargs(self):
        """Test serialization of an operation with a kwarg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append(
            {"op": "MeasureFock", "modes": [0], "args": [], "kwargs": {"select": 2}}
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            MeasureFock(select=2) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_kwargs(self):
        """Test serialization of an operation with many kwargs"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append(
            {
                "op": "Dgate",
                "modes": [0],
                "args": [],
                "kwargs": OrderedDict([("alpha", 0.43 - 0.543j), ("phi", 0.54)]),
            }
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Dgate(alpha=0.43-0.543j, phi=0.54) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_args_kwargs(self):
        """Test serialization of an operation with args and kwargs"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append(
            {
                "op": "MeasureHomodyne",
                "modes": [0],
                "args": [0.54, -1],
                "kwargs": OrderedDict([("select", 5.43), ("phi", 0.54)]),
            }
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            MeasureHomodyne(0.54, -1, select=5.43, phi=0.54) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multimode(self):
        """Test serialization of an operation on multiple modes"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Vac", "modes": [0, 1, 2]})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Vac | [0, 1, 2]
            """
        )
        assert res == expected

    def test_serialize_operation_array_arg(self):
        """Test serialization of an operation with an array arg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        U = np.int64(np.identity(2))

        bb._operations.append({"op": "Interferometer", "modes": [0], "args": [U], "kwargs": {}})

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            int array A0[2, 2] =
                1, 0
                0, 1

            Interferometer(A0) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_array_kwarg(self):
        """Test serialization of an operation with an array kwarg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        U = np.int64(np.identity(2))

        bb._operations.append(
            {"op": "Interferometer", "modes": [0], "args": [], "kwargs": {"U": U}}
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            int array A0[2, 2] =
                1, 0
                0, 1

            Interferometer(U=A0) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_string_arg(self):
        """Test serialization of an operation with a string arg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Dgate", "modes": [0], "args": ["hi"], "kwargs": {}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Dgate("hi") | 0
            """
        )
        assert res == expected

    def test_serialize_operation_string_kwarg(self):
        """Test serialization of an operation with a string kwarg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [], "kwargs": {"key": "val"}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Dgate(key="val") | 0
            """
        )
        assert res == expected

    def test_serialize_free_params(self):
        """Test serialization of an operation with a string kwarg"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        x = sym.Symbol('x')
        bb._operations.append({"op": "Dgate", "modes": [0], "args": [0.54/x**2], "kwargs": {}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            Dgate(0.54/{x}**2) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_arrays(self):
        """Test serialization of an operation with multiple array args"""
        bb = BlackbirdProgram(name="prog", version=0.0)
        U = np.int64(np.identity(2))
        U2 = np.array([[1, 2j], [-2j, 3]])

        bb._operations.extend(
            [
                {"op": "Interferometer", "modes": [0, 2], "args": [U], "kwargs": {}},
                {"op": "BSgate", "modes": [0, 1], "args": [0.543, -0.1231], "kwargs": {}},
                {"op": "GaussianTransform", "modes": [0, 2], "args": [U2], "kwargs": {}},
            ]
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 0.0

            int array A0[2, 2] =
                1, 0
                0, 1

            complex array A1[2, 2] =
                1.0+0.0j, 0.0+2.0j
                -0.0-2.0j, 3.0+0.0j

            Interferometer(A0) | [0, 2]
            BSgate(0.543, -0.1231) | [0, 1]
            GaussianTransform(A1) | [0, 2]
            """
        )
        assert res == expected

    def test_serialize_tdmprogram(self):
        """Test serialization of a tdm program"""
        bb = BlackbirdProgram(name="tdm", version=1.0)

        # OrderedDict needed for Python 3.5 support TODO
        bb._type = OrderedDict(
            [('name', 'tdm'), ('options', OrderedDict([('temporal_modes', 2), ('copies', 3)]))]
        )
        bb._var = OrderedDict(
            [('p0', np.array([[1, 2]])), ('p1', np.array([[3, 4]]))]
        )
        bb._operations.extend(
            [
                {'kwargs': {}, 'args': [0.7, 0], 'op': 'Sgate', 'modes': [1]},
                {'kwargs': {}, 'args': ['p0', 0.0], 'op': 'BSgate', 'modes': [0, 1]},
                {'kwargs': {'phi': 'p1'}, 'args': [], 'op': 'MeasureHomodyne', 'modes': [0]}
            ]
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name tdm
            version 1.0
            type tdm (temporal_modes=2, copies=3)

            int array p0 =
                1, 2
            int array p1 =
                3, 4

            Sgate(0.7, 0) | 1
            BSgate(p0, 0.0) | [0, 1]
            MeasureHomodyne(phi=p1) | 0
            """
        )
        assert res == expected


class TestProgramIntegration:
    """Integration tests for program module"""

    @pytest.mark.parametrize("iterable", [[[11, 12]], np.array([[11, 12]])])
    def test_template_with_arrays(self, iterable):
        """Test that templates can be initialized with parameters inside of arrays"""
        template = dedent(
            """\
            name template
            version 1.0

            float array one[1, 2] =
                {p_one}

            float array two[2, 3] =
                1, {p_two}, 3
                1, 2, {p_three}

            int four = {p_four}

            for int i in 0:2
                Sgate(two[i], 0) | 1
                BSgate(one[i]) | (1, 0)
                MeasureHomodyne(four) | 0
            """
        )

        bb = loads(template)

        assert bb.parameters == {
            'p_one_0_0', 'p_one_0_1', 'p_two', 'p_three', 'p_four'
        }

        assert bb.is_template()

        bb2 = bb(p_one=iterable, p_two=22, p_three=33, p_four=44)
        assert not bb2.parameters
        assert not bb2.is_template()

        expected = {'one': np.array([[11, 12]]), 'two': np.array([[1, 22, 3], [1, 2, 33]]), 'four': 44}

        assert np.all(np.all(v == expected[k]) for k, v in bb2._var.items())

        assert bb2.operations[0] == {'op': 'Sgate', 'args': [1, 0], 'kwargs': {}, 'modes': [1]}
        assert bb2.operations[1] == {'op': 'BSgate', 'args': [11], 'kwargs': {}, 'modes': [1, 0]}
        assert bb2.operations[2] == {'op': 'MeasureHomodyne', 'args': [44], 'kwargs': {}, 'modes': [0]}
        assert bb2.operations[3] == {'op': 'Sgate', 'args': [22, 0], 'kwargs': {}, 'modes': [1]}
        assert bb2.operations[4] == {'op': 'BSgate', 'args': [12], 'kwargs': {}, 'modes': [1, 0]}
        assert bb2.operations[5] == {'op': 'MeasureHomodyne', 'args': [44], 'kwargs': {}, 'modes': [0]}


    def test_invalid_dim_error(self):
        """Test that an error is raised when assigning a template array with an
        array with invalid dimension"""

        template = dedent(
            """\
            name template
            version 1.0

            float array one[1, 2] =
                {p_one}
            """
        )

        bb = loads(template)

        assert bb.is_template()

        with pytest.raises(ValueError, match="Invalid dim for free parameter provided"):
            bb2 = bb(p_one=[11, 12])

    @pytest.mark.parametrize("array", [[[2, 3, 4]], [[5, 6], [3, 4]]])
    def test_slicing_of_large_arrays(self, array):
        """Test that assigned template arrays are correctly sliced"""

        template = dedent(
            """\
            name template
            version 1.0

            float array one[1, 2] =
                {p_one}
            """
        )

        bb = loads(template)

        assert bb.is_template()

        bb2 = bb(p_one=array)
        assert np.all(bb2._var["one"] == np.array(array)[:1, :2])

    def test_error_no_shape_in_template_array(self):
        """Test that an error is raised when omitting shape when defining a template array."""

        template=dedent(
            """\
            name template
            version 1.0

            float array one =
                {p_one}
            """
        )

        with pytest.raises(BlackbirdSyntaxError, match="has no shape defined"):
            bb = loads(template)
