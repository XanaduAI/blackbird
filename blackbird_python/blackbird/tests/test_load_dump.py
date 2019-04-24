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
"""Tests for the load(s) and dump(s) functions"""
import sys
from textwrap import dedent

import pytest

import numpy as np

from blackbird import load, loads, dump, dumps


test_script = """
# a test blackbird script
name test_name
version 1.0
target fock (num_subsystems=1, cutoff_dim=7, shots=10)

float alpha = 0.3423
Coherent(alpha, sqrt(pi)) | 0
MeasureFock() | 0
"""


@pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
def test_load( tmpdir):
    """Test that a Blackbird script is deserialized from a file"""
    filename = tmpdir.join('test.xbb')

    with open(filename, 'w') as f:
        f.write(test_script)

    bb = load(filename)

    assert bb._var == {"alpha": 0.3423}

    expected = {"name": 'fock', 'options': {'num_subsystems':1, 'cutoff_dim':7, 'shots':10}}
    assert bb.target == expected

    expected = [
        {'op': 'Coherent', 'args': [0.3423, np.sqrt(np.pi)], 'kwargs':{}, 'modes': [0]},
        {'op': 'MeasureFock', 'args': [], 'kwargs':{}, 'modes': [0]}
        ]

    assert bb.operations == expected


def test_loads():
    """Test that a Blackbird script is deserialized from a string"""
    bb = loads(test_script)

    assert bb._var == {"alpha": 0.3423}

    expected = {"name": 'fock', 'options': {'num_subsystems':1, 'cutoff_dim':7, 'shots':10}}
    assert bb.target == expected

    expected = [
        {'op': 'Coherent', 'args': [0.3423, np.sqrt(np.pi)], 'kwargs':{}, 'modes': [0]},
        {'op': 'MeasureFock', 'args': [], 'kwargs':{}, 'modes': [0]}
        ]

    assert bb.operations == expected


@pytest.mark.skipif(sys.version_info < (3, 6), reason="tmpdir fixture requires Python >=3.6")
def test_dump(tmpdir):
    """Test that a Blackbird script is serialized to a file"""
    bb = loads(test_script)
    filename = tmpdir.join('test.xbb')

    with open(filename, 'w') as f:
        dump(bb, f)

    # read from file
    with open(filename, 'r') as f:
        res = "".join(f.readlines())

    expected = dedent(
        """\
        name test_name
        version 1.0
        target fock (num_subsystems=1, cutoff_dim=7, shots=10)

        Coherent(0.3423, {}) | 0
        MeasureFock() | 0
        """.format(np.sqrt(np.pi))
    )

    assert res == expected


def test_dumps(tmpdir):
    """Test that a Blackbird script is serialized to a string"""
    bb = loads(test_script)
    res = dumps(bb)

    expected = dedent(
        """\
        name test_name
        version 1.0
        target fock (num_subsystems=1, cutoff_dim=7, shots=10)

        Coherent(0.3423, {}) | 0
        MeasureFock() | 0
        """.format(np.sqrt(np.pi))
    )

    assert res == expected
