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
"""Tests for the utils module"""
from textwrap import dedent
from collections import OrderedDict

import pytest

import numpy as np
import sympy as sym

from blackbird import loads
from blackbird.listener import RegRefTransform
from blackbird.utils import to_DiGraph, match_template, TemplateError


class TestDiGraph:
    """Test conversion of programs to DAGs"""

    def test_no_args(self):
        """Test case where operations have no arguments"""
        program = loads(dedent(
            """\
            name prog
            version 0.0

            Vac | 0
            """
        ))

        res = to_DiGraph(program)
        assert len(res) == 1

        nodes = res.nodes().data()
        assert nodes[0]['name'] == 'Vac'
        assert nodes[0]['modes'] == (0,)
        assert nodes[0]['args'] == []
        assert nodes[0]['kwargs'] == {}

    def test_no_dependence(self):
        """Test case where operations do not depend on each other.
        This should result in a graph with no edges."""
        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.43) | 0
            Dgate(0.543) | 1
            """
        ))

        res = to_DiGraph(program)
        assert len(res) == 2

        nodes = res.nodes().data()
        assert len(res.edges()) == 0

    def test_args(self):
        """Test case where operations have arguments"""
        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.54) | 1
            BSgate(0.432, phi=0.54) | [1, 2]
            """
        ))

        res = to_DiGraph(program)
        assert len(res) == 2

        nodes = res.nodes().data()
        assert nodes[0]['name'] == 'Sgate'
        assert nodes[0]['modes'] == (1,)
        assert nodes[0]['args'] == [0.54]
        assert nodes[0]['kwargs'] == {}

        assert nodes[1]['name'] == 'BSgate'
        assert nodes[1]['modes'] == (1, 2)
        assert nodes[1]['args'] == [0.432]
        assert nodes[1]['kwargs'] == {'phi': 0.54}

        assert list(res.edges()) == [(0, 1)]

    def test_regrefs(self):
        """Test case where operations have regref arguments"""
        program = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.54) | 0
            MeasureX | 0
            Sgate(2*q0) | 1
            """
        ))

        res = to_DiGraph(program)
        assert len(res) == 3
        assert list(res.edges()) == [(0, 1), (1, 2)]

        nodes = res.nodes().data()
        assert isinstance(nodes[2]['args'][0], RegRefTransform)

    def test_regrefs_kwargs(self):
        """Test case where operations have regref keyword arguments"""
        program = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.54) | 0
            MeasureX | 0
            MeasureHomodyne(phi=0.54, select=2*q0) | 1
            """
        ))

        res = to_DiGraph(program)
        assert len(res) == 3
        assert list(res.edges()) == [(0, 1), (1, 2)]

        nodes = res.nodes().data()
        assert isinstance(nodes[2]['kwargs']['select'], RegRefTransform)


class TestTemplateMatching:
    """Test template matching working correctly"""

    def test_different_version(self):
        """Test exception raised if versions don't match"""
        template = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.1

            Sgate(0.543, pi) | 0
            """
        ))

        with pytest.raises(TemplateError, match="Mismatching Blackbird version"):
            match_template(template, program)

    def test_different_target(self):
        """Test exception raised if targets don't match"""
        template = loads(dedent(
            """\
            name prog
            version 0.0
            target dev1

            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0
            target dev2

            Sgate(0.543, pi) | 0
            """
        ))

        with pytest.raises(TemplateError, match="Mismatching target"):
            match_template(template, program)

    def test_match(self):
        """test a simple match"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 1
            Vac | 2
            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(0.543, 0.45) | 1
            Vac | 2
            """
        ))

        res = match_template(template, program)
        expected = {'r': 0.543, 'phi':-1.432*np.pi}
        assert res == expected

    def test_different_program(self):
        """test exception raised if template not the same program"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 0
            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(0.543, 0.45) | 0
            """
        ))

        with pytest.raises(TemplateError, match="Not the same program"):
            match_template(template, program)

    def test_not_template(self):
        """test exception raised if first argument is not a template"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 1
            Sgate(0.543, 0.123) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(0.543, 0.45) | 1
            """
        ))

        with pytest.raises(TemplateError, match="Argument 1 is not a template"):
            match_template(template, program)

    def test_not_program(self):
        """test exception raised if second argument is a template"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 0
            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate({alpha}, 0.45) | 0
            """
        ))

        with pytest.raises(TemplateError, match="Argument 2 cannot be a template"):
            match_template(template, program)

    def test_too_many_template_parameters(self):
        """test exception raised if gate contains multiple template parameters"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 1
            Sgate({r}+{s}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(0.543, 0.45) | 1
            """
        ))

        with pytest.raises(TemplateError, match="only supports one template parameter"):
            match_template(template, program)

    def test_implicit_variable_solving(self):
        """test solver is used for parameter arithmetic"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(0.543, 0.45) | 1
            Sgate(2*{r}, {phi}-1) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(0.412, 0.45) | 1
            """
        ))

        res = match_template(template, program)
        expected = {'r': 0.543/2, 'phi':-1.432*np.pi+1}
        assert np.allclose(res['r'], expected['r'])
        assert np.allclose(res['phi'], expected['phi'])

    def test_multiple_match(self):
        """test a match involving duplicated template parameters"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(-{r}, 0.45) | 1
            Vac | 2
            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(0.543, -1.432*pi) | 0
            Dgate(-0.543, 0.45) | 1
            Vac | 2
            """
        ))

        res = match_template(template, program)
        expected = {'r': 0.543, 'phi':-1.432*np.pi}
        assert res == expected

    def test_invalid_multiple_match(self):
        """test exception raised if match involving duplicated
        template parameters results in inconsistent values"""

        template = loads(dedent(
            """\
            name prog
            version 0.0

            Dgate(-{r}, 0.45) | 1
            Vac | 2
            Sgate({r}, {phi}) | 0
            """
        ))

        program = loads(dedent(
            """\
            name prog
            version 0.0

            Sgate(1.45, -1.432*pi) | 0
            Dgate(-0.543, 0.45) | 1
            Vac | 2
            """
        ))

        with pytest.raises(TemplateError, match="matches inconsistent values"):
            match_template(template, program)

    def test_multiple_match_tdm(self):
        """test a match involving duplicated template parameters with p-type variables"""

        template = loads(dedent(
            """\
            name template_td3_fake
            version 1.0
            target TD3_fake (shots=1)
            type tdm (temporal_modes=3, copies=1)

            Sgate({s}, 0.0) | 43
            Rgate({r}) | 43
            BSgate({bs}, 1.5707963267948966) | [42, 43]
            Rgate({offset}) | 43
            MeasureFock() | 0
            """
        ))

        program = loads(dedent(
            """\
            name None
            version 1.0
            target TD3_fake (shots=1)
            type tdm (temporal_modes=259)

            float array p0 =
                0.999, 0.965, 0.678
            float array p1 =
                0.211, 0.042, 0.347
            float array p2 =
                0.042, 0.673, 0.924
            int array p3 =
                4, 4, 4

            Sgate(p0, 0.0) | 43
            Rgate(p1) | 43
            BSgate(p2, 1.5707963267948966) | [42, 43]
            Rgate(p3) | 43
            MeasureFock() | 0
            """
        ))

        res = match_template(template, program)
        expected = {
            's': np.array([[0.999, 0.965, 0.678]]),
            'r': np.array([[0.211, 0.042, 0.347]]),
            'bs': np.array([[0.042, 0.673, 0.924]]),
            'offset': np.array([[4, 4, 4]])
        }

        assert res.keys() == expected.keys()
        assert all(np.allclose(r, e) for r, e in zip(res.values(), expected.values()))
