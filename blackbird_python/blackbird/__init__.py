# Copyright 2018 Xanadu Quantum Technologies Inc.

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

Modules
-------

* Blackbird parser class: :mod:`blackbird.listener`
* Auxiliary parsing functions: :mod:`blackbird.auxiliary`
* Syntax error class: :mod:`blackbird.error`

Main components
---------------

* :class:`~.BlackbirdListener`: the Python Blackbird parser,
  that parses the abstract syntax tree using ANTLR4, evaluating expressions,
  extracting variables, and storing quantum program information.

  This class can be sub-classed, to create more advanced Blackbird listeners
  that perform actions (i.e. such as simulations) upon parsing the tree.

* :class:`~.parse_blackbird`: a utility function that automates
  the parsing of the Blackbird abstract syntax tree. Use this function, either
  with the default parser :class:`~blackbird.BlackbirdListener` or a custom
  derived class, to parse arbitrary Blackbird code.

.. note::

	While both the above classes/functions are located in the :mod:`blackbird.listener`,
	they are both importable from the top-level of the Blackbird Python package:

	.. code-block:: python

		from blackbird import BlackbirdListener, parse_blackbird
"""

from .listener import BlackbirdListener, parse_blackbird
from ._version import __version__
