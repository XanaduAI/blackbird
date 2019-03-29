Blackbird Quantum Assembly Language
###################################

.. image:: https://img.shields.io/readthedocs/quantum-blackbird.svg?style=for-the-badge
    :alt: Read the Docs
    :target: https://quantum-blackbird.readthedocs.io


Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to program Xanadu's quantum photonics hardware and Strawberry Fields simulator.


Features
--------

Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to control (a) Xanadu's quantum photonics hardware, and (b) Xanadu's Strawberry Fields simulator.

This project contains the following folders:

* ``src``: The Blackbird grammar (both lexer and parser rules) in Extended Backus–Naur form.

* ``blackbird_python``: Python package containing a Python listener/parser for Blackbird files.

* ``blackbird_cpp``: C++ library ``libblackbird.so``, containing listener, visitor, and parser
  for Blackbird files.

* ``examples``: some example Blackbird programs (with file extension .xbb)

* ``apps``: some example applications, including a basic C++ Gaussian simulator
  that reads and then manipulate Blackbird programs, as well as a Python Strawberry Fields
  listener that reads in Blackbird programs and simulates them via Strawberry Fields.


Getting started
---------------

To get Blackbird installed and running on your system, begin at the `Python installation <https://quantum-blackbird.readthedocs.io/en/latest/blackbird_python/installing.html>`_ or `C++ installation <https://quantum-blackbird.readthedocs.io/en/latest/blackbird_cpp/installing.html>`_ sections, depending on which language you want to target.

Then, familiarize yourself with the Blackbird's `syntax and grammar <https://quantum-blackbird.readthedocs.io/en/latest/syntax.html>`_ for defining continuous-variable quantum circuits.


How to cite
-----------


If you are doing research using Blackbird, please cite

    Nathan Killoran, Josh Izaac, Nicolás Quesada, Ville Bergholm, Matthew Amy, and Christian Weedbrook.
    *Strawberry Fields: A Software Platform for Photonic Quantum Computing* 2018. `arXiv:1804.03159 <https://arxiv.org/abs/1804.03159>`_

Support
-------

- **Source Code:** https://github.com/XanaduAI/Blackbird
- **Issue Tracker:** https://github.com/XanaduAI/Blackbird/issues

If you are having issues, please let us know by posting the issue on our Github issue tracker.

License
-------

Blackbird is **free** and **open source**, released under the Apache License, Version 2.0.
