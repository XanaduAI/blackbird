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

* :mod:`blackbird.program`: the Blackbird program module. Contains
  the main Blackbird program class, used for encapsulating Blackbird
  programs in Python.

* :mod:`blackbird.listener`: the Blackbird listener module. Contains
  the main Blackbird listener class, as well as a class for encapsulating
  classical processing of measured modes as register transforms.

* :mod:`blackbird.error`: contains the error parser for
  returning useful syntax errors to the user.

* :mod:`blackbird.auxiliary`: auxiliary parsing functions.


Serializing and deserializing Blackbird
---------------------------------------

The following functions are provided to easily

* :func:`~.load`: a utility function that automates
  the de-serialization of the Blackbird script
  from a file (specified by file location),
  returning a :class:`~.BlackbirdProgram` object.

* :func:`~.loads`: a utility function that automates
  the de-serialization of the Blackbird script
  from a string, returning a :class:`~.BlackbirdProgram` object.

* :func:`~.dump`: a utility function that automates
  the serialization of a :class:`~.BlackbirdProgram` object
  to a `.write()`-supporting file-like object.

* :func:`~.dumps`: a utility function that automates
  the serialization of a :class:`~.BlackbirdProgram` object
  to a string.


Main classes
------------

* :class:`~.BlackbirdProgram`: a class that encapsulates a Blackbird
  program, using standard Python data structures accessible via attributes.

* :class:`~.BlackbirdListener`: the Python Blackbird listener,
  that traverses the abstract syntax tree using ANTLR4, evaluating expressions,
  extracting variables, and storing quantum program information.

  This class can be sub-classed, to create more advanced Blackbird listeners
  that perform actions (e.g., simulations) upon parsing the tree.

* :class:`~.RegRefTransform`: a class for representing classically processed
  measurement results as parameters for subsequent quantum operations.

  If the operation argument you are parsing is an instance of this class,
  that indicates that a register transform is required.


.. note::

  All the above classes/functions are importable from the top-level
  of the Blackbird Python package:

  .. code-block:: python

    from blackbird import BlackbirdListener, load, BlackbirdProgram

Summary
-------

.. autosummary::
    load
    loads
    dump
    dumps

Code details
^^^^^^^^^^^^
"""
import antlr4

from .listener import BlackbirdListener, RegRefTransform, parse
from .program import BlackbirdProgram
from ._version import __version__


def load(filename):
    """Deserialize a blackbird program from a file to a
    :class:`BlackbirdProgram` object.

    Args:
        filename (str): file location of a valid Blackbird program

    Returns:
        BlackbirdProgram: parsed representation of the program
    """
    data = antlr4.FileStream(filename)
    return parse(data)


def loads(string):
    """Deserialize a blackbird program from a string to a
    :class:`BlackbirdProgram` object.

    Args:
        string (str): string containing a valid Blackbird program

    Returns:
        BlackbirdProgram: parsed representation of the program
    """
    data = antlr4.InputStream(string)
    return parse(data)


def dump(blackbird, f):
    """Serialize a blackbird program to a `.write()`-supporting file-like object.

    Args:
        blackbird (BlackbirdProgram): a :class:`BlackbirdProgram` object
        f (file-like): a `.write()`-supporting file-like object.
    """
    text = blackbird.serialize()
    f.write(text)


def dumps(blackbird):
    """Serialize a blackbird program to a string.

    Args:
        blackbird (BlackbirdProgram): a :class:`BlackbirdProgram` object

    Returns:
        str: the serialized Blackbird program
    """
    return blackbird.serialize()
