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

from blackbird.program import BlackbirdProgram, numpy_to_blackbird


class TestNumPyToBlackbird:
    """Tests for the NumPy to Blackbird function"""

    def test_real_array(self):
        """Test real array is correctly formatted"""
        A = np.array([[0.453, 1, 0.213], [-0.543, 1.342, 1e-4]])
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = (
            "float array A[2, 3] =\n    0.453, 1.0, 0.213\n    -0.543, 1.342, 0.0001\n"
        )
        assert res == expected

    def test_int_array(self):
        """Test integer array is correctly formatted"""
        A = np.array([[1, -0, -15]])
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = "int array A[1, 3] =\n    1, 0, -15\n"
        assert res == expected

    def test_complex_array(self):
        """Test complex array is correctly formatted"""
        A = np.array(
            [[0.453 - 0.543j, 1, 0.213 + 8j], [-0.543j, 1.342 + 0.5j, 1e-4 - 2e2j]]
        )
        res = "\n".join(numpy_to_blackbird(A, "A"))
        expected = dedent(
            """\
            complex array A[2, 3] =
                0.453-0.543j, 1.0+0.0j, 0.213+8.0j
                -0.0-0.543j, 1.342+0.5j, 0.0001-200.0j
            """
        )
        assert res == expected


class TestBlackbirdProgram:
    """Basic unit tests for the program class"""

    def test_initialization(self):
        """Test all attributes correctly initialized"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        assert not bb._var

        assert bb.name == "prog"
        assert bb.version == 1.0
        assert not bb.modes

        assert bb.target["name"] is None
        assert not bb.target["options"]
        assert not bb.operations

        assert not len(bb)

    def test_serialize_empty(self):
        """Test serialization of an empty program"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        res = bb.serialize()
        assert res == "name prog\nversion 1.0\n"

    def test_serialize_target(self):
        """Test target serialization"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._target["name"] = "chip0"
        res = bb.serialize()
        assert res == "name prog\nversion 1.0\ntarget chip0\n"

        bb._target["options"] = OrderedDict(
            [("shots", 100), ("hbar", 0.2), ("real", True), ("str", "hi")]
        )
        res = bb.serialize()
        assert res == dedent(
            """\
            name prog
            version 1.0
            target chip0 (shots=100, hbar=0.2, real=True, str="hi")
            """
        )

    def test_serialize_operation_no_args(self):
        """Test serialization of an operation with no args"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append({"op": "Vac", "modes": [0]})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Vac | 0
            """
        )
        assert res == expected

    def test_serialize_operation_args(self):
        """Test serialization of an operation with 1 arg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append(
            {"op": "Dgate", "modes": [0], "args": [0.43 - 0.543j], "kwargs": {}}
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Dgate(0.43-0.543j) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_args(self):
        """Test serialization of an operation with many args"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append(
            {"op": "Sgate", "modes": [0], "args": [0.43, 0.5432], "kwargs": {}}
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Sgate(0.43, 0.5432) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_kwargs(self):
        """Test serialization of an operation with a kwarg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append(
            {"op": "MeasureFock", "modes": [0], "args": [], "kwargs": {"select": 2}}
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            MeasureFock(select=2) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_kwargs(self):
        """Test serialization of an operation with many kwargs"""
        bb = BlackbirdProgram(name="prog", version=1.0)
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
            version 1.0

            Dgate(alpha=0.43-0.543j, phi=0.54) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_args_kwargs(self):
        """Test serialization of an operation with args and kwargs raises an error"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append(
            {
                "op": "Dgate",
                "modes": [0],
                "args": [0.54],
                "kwargs": {"alpha": 0.43 - 0.543j, "phi": 0.54},
            }
        )

        with pytest.raises(
            ValueError, match="contain both positional and keyword arguments"
        ):
            bb.serialize()

    def test_serialize_operation_multimode(self):
        """Test serialization of an operation on multiple modes"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append({"op": "Vac", "modes": [0, 1, 2]})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Vac | [0, 1, 2]
            """
        )
        assert res == expected

    def test_serialize_operation_array_arg(self):
        """Test serialization of an operation with an array arg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        U = np.identity(2)

        bb._operations.append(
            {"op": "Interferometer", "modes": [0], "args": [U], "kwargs": {}}
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            int array A0[2, 2] =
                1, 0
                0, 1

            Interferometer(A0) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_array_kwarg(self):
        """Test serialization of an operation with an array kwarg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        U = np.identity(2)

        bb._operations.append(
            {"op": "Interferometer", "modes": [0], "args": [], "kwargs": {"U": U}}
        )

        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            int array A0[2, 2] =
                1, 0
                0, 1

            Interferometer(U=A0) | 0
            """
        )
        assert res == expected

    def test_serialize_operation_string_arg(self):
        """Test serialization of an operation with a string arg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append({"op": "Dgate", "modes": [0], "args": ["hi"], "kwargs": {}})
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Dgate("hi") | 0
            """
        )
        assert res == expected

    def test_serialize_operation_string_kwarg(self):
        """Test serialization of an operation with a string kwarg"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        bb._operations.append(
            {"op": "Dgate", "modes": [0], "args": [], "kwargs": {"key": "val"}}
        )
        res = bb.serialize()
        expected = dedent(
            """\
            name prog
            version 1.0

            Dgate(key="val") | 0
            """
        )
        assert res == expected

    def test_serialize_operation_multiple_arrays(self):
        """Test serialization of an operation with multiple array args"""
        bb = BlackbirdProgram(name="prog", version=1.0)
        U = np.identity(2)
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
            version 1.0

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
