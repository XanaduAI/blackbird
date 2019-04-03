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
Blackbird for Python overview
=============================

The Python Blackbird package provides a Python parser class for parsing Blackbird code, as
well as a utility function for automating this procedure given a Blackbird filename.

Nomenclature
------------

Parser
  A software component that takes input data and builds a data structure.
  Examples include:

  * Parsing Blackbird text to form an `abstract syntax tree <https://en.wikipedia.org/wiki/abstract_syntax_tree>`_,
    a graph representation of the Blackbird code. This is performed automatically by the ANTLR library.

  * Parsing the abstract syntax tree (AST) to extract useful data and build a data structure
    for common applications, such as a Python dictionary. To do this, we must walk
    through the AST via a listener or a visitor.

Listener
  An ANTLR language pattern that automatically traverses the AST. By overwriting listener methods,
  you can store information depending on where you are in the tree.

Visitor
  Similar to a listener, but more flexible. In the visitor pattern, you control the traversal
  of the AST, must manually visit branches. This allows the use of loops and conditionals
  while traversing the tree.

The Python Blackbird parser is built using the ANTLR listener pattern.


Modules
-------

* Blackbird listener class: :mod:`blackbird.listener`
* Auxiliary parsing functions: :mod:`blackbird.auxiliary`
* Syntax error class: :mod:`blackbird.error`


Main components
---------------

* :class:`~.BlackbirdListener`: the Python Blackbird listener,
  that traverses the abstract syntax tree using ANTLR4, evaluating expressions,
  extracting variables, and storing quantum program information.

  This class can be sub-classed, to create more advanced Blackbird listeners
  that perform actions (i.e. such as simulations) upon parsing the tree.

* :func:`~.parse_blackbird`: a utility function that automates
  the parsing of the Blackbird abstract syntax tree. Use this function, either
  with the default parser :class:`~.BlackbirdListener` or a custom
  derived class, to parse arbitrary Blackbird code.

.. note::

	While both the above classes/functions are located in the :mod:`blackbird.listener`,
	they are both importable from the top-level of the Blackbird Python package:

	.. code-block:: python

		from blackbird import BlackbirdListener, parse_blackbird
"""

from .listener import BlackbirdListener, parse_blackbird
from ._version import __version__
