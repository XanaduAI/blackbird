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
.. _utils:

Utilities
=========

**Module name:** `blackbird.utils`

.. currentmodule:: blackbird.utils

This module contains utility functions for Blackbird programs,
including generating directed acyclic graphs, and pattern matching
and Blackbird programs and templates.


Summary
-------

.. autosummary::
    TemplateError
    to_DiGraph
    match_template

Code details
~~~~~~~~~~~~
"""
from collections import namedtuple

import numpy as np
import sympy as sym
from sympy.solvers import solve

import networkx as nx
from networkx.algorithms import isomorphism


from .listener import RegRefTransform


Command = namedtuple('Command', ['name', 'args', 'kwargs', 'modes'])
"""namedtuple: encapsulate a specific quantum operation"""


class TemplateError(Exception):
    """Exception class for template related errors"""
    pass


def to_DiGraph(program):
    """Convert a Blackbird program to a directed acyclic graph.

    The resulting graph has nodes representing quantum operations,
    and edges representing dependent/successor operations.

    Each node is labelled by an integer; note attributes are used
    to store information about the node:

    * ``'name'`` *(str)*: name of the quantum operation (e.g., ``'S2gate'``)

    * ``'args'`` *(list)*: positional arguments of the operation

    * ``'kwargs'`` *(dict)*: keyword arguments of the operation

    * ``'modes'`` *(tuple[int])*: modes the operation acts on

    Args:
        program (blackbird.Program): a Blackbird program

    Returns:
        networkx.DiGraph: the directed acyclic graph representing
        the quantum program
    """
    grid = {}

    for idx, op in enumerate(program.operations):
        dependencies = set(op['modes'])

        if 'args' in op:

            for a in op['args']:
                if isinstance(a, RegRefTransform):
                    dependencies |= set(a.regrefs)

            for _, v in op['kwargs'].items():
                if isinstance(v, RegRefTransform):
                    dependencies |= set(v.regrefs)
        else:
            op['args'] = []
            op['kwargs'] = {}

        cmd = Command(name=op['op'], args=op['args'], kwargs=op['kwargs'], modes=tuple(op['modes']))

        for q in dependencies:
            # Add cmd to the grid to the end of the line r.ind.
            if q not in grid:
                # add a new line to the circuit
                grid[q] = []

            grid[q].append([idx, cmd])

    G = nx.DiGraph()

    for q, cmds in grid.items():
        if cmds:
            # add the first operation on the wire that does not depend on anything
            attrs = cmds[0][1]._asdict()
            G.add_node(cmds[0][0], **attrs)

        for i in range(1, len(cmds)):
            # add the edge between the operations, and the operation nodes themselves
            if cmds[i][0] not in G:
                attrs = cmds[i][1]._asdict()
                G.add_node(cmds[i][0], **attrs)

            G.add_edge(cmds[i-1][0], cmds[i][0])

    return G


def match_template(template, program):
    """Match a template against a Blackbird program, returning template
    parameter values.

    For example, consider the following template and program:

    .. code-block:: python

        template = blackbird.loads(\"\"\"\\
        name prog
        version 1.0

        Dgate(-{r}, 0.45) | 1
        Vac | 2
        Sgate({r}, 2*{phi}-1) | 0
        \"\"\")

        program = blackbird.loads(\"\"\"\\
        name prog
        version 1.0

        Sgate(0.543, -1.432*pi) | 0
        Dgate(-0.543, 0.45) | 1
        Vac | 2
        \"\"\")

    By applying the ``match_template`` function, we can match the template parameters:

    >>> res = match_template(template, program)
    >>> print(res)
    {'r': 0.543, 'phi': -1.74938033997029}

    Verifying this is correct:

    >>> print((-1.432*np.pi+1)/2)
    -1.7493803399702919

    .. note::

        The template and the Blackbird program to match must have the *same*
        version number and target, otherwise an :class:`TemplateError` will be raised.

    Args:
        template (blackbird.Program): the Blackbird template
        program (blackbird.Program): a Blackbird program to match against
            the template

    Returns:
        dict[str, Number]: mapping from the template parameter name
        to a numerical value.
    """

    # check template
    if not template.is_template():
        raise TemplateError("Argument 1 is not a template.")

    if program.is_template():
        raise TemplateError("Argument 2 cannot be a template.")

    if template.version != program.version:
        raise TemplateError("Mismatching Blackbird version between template and program")

    if template.target['name'] != program.target['name']:
        raise TemplateError("Mismatching target between template and program")

    G1 = to_DiGraph(template)
    G2 = to_DiGraph(program)

    def node_match(n1, n2):
        """Returns True if both nodes have the same name"""
        return n1['name'] == n2['name'] and n1['modes'] == n2['modes']

    GM = isomorphism.DiGraphMatcher(G1, G2, node_match)

    # check if topology matches
    if not GM.is_isomorphic():
        raise TemplateError("Not the same program.")

    G1nodes = G1.nodes().data()
    G2nodes = G2.nodes().data()

    argmatch = {}
    key = ""

    for n1, n2 in GM.mapping.items():
        for x, y in zip(G1nodes[n1]['args'], G2nodes[n2]['args']):
            if np.all(x != y):
                if isinstance(x, sym.Symbol):
                    key = str(x)
                    val = y

                elif isinstance(x, sym.Expr):
                    # need to symbolically solve for the symbol
                    var = x.free_symbols

                    if len(var) > 1:
                        raise TemplateError("Matching template parameters only supports "
                                            "one template parameter per gate argument.")

                    res = solve(x-y, var)
                    key = str(var)[1:-1]
                    val = float(res[-1])

                if key in argmatch:
                    if argmatch[key] != val:
                        raise TemplateError("Template parameter {} matches inconsistent values: "
                                            "{} and {}".format(key, val, argmatch[key]))

                if key != "":
                    argmatch[key] = val

    return argmatch
