Blackbird Quantum Assembly Language
###################################

Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to control (a) Xanadu's quantum photonics hardware, and (b) Xanadu's Strawberry Fields simulator.

For details on the structure of the Blackbird quantum assembly language, see the `syntax and grammar <doc/syntax.rst>`_ section of the documentation.

This repository contains:

* ``src``: The Blackbird grammar (both lexer and parser rules) in Extended Backus–Naur form. For details on how to use ANTLR4 to auto-generate a base parser for a specific programming language, see `installation <doc/installing.rst>`_.

* ``blackbird_python``: Python package containing a Python listener/parser for Blackbird files. For details on how to install and use the Python package, see the `Python installation <doc/blackbird_python/installing.rst>`_ section of the documentation.

* ``blackbird_cpp``: C++ library ``libblackbird.so``, containing listener, visitor, and parser for Blackbird files. For details on how to install and use the C++ library, see the `C++ installation <doc/blackbird_cpp/installing.rst>`_ section of the documentation.

* ``doc``: documentation (can be built using Sphinx).

* ``examples``: some example Blackbird programs (with file extension ``.xbb``).

* ``cpp_examples``: some example C++ applications, including a basic Gaussian simulator,
  that read and then manipulate Blackbird programs.

In addition, it currently also contains the file ``strawberry_fields_listener.py``, which sub-classes ``blackbird_python.BlackbirdListener``, and extends it to also *run* the Blackbird program using the Strawberry Fields listeners, as a proof of concept.

