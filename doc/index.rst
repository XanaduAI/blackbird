.. role:: html(raw)
   :format: html

Blackbird Quantum Assembly Language
===================================

:Release: |release|
:Date: |today|

Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to program Xanadu's quantum photonics hardware and Strawberry Fields simulator.


Features
--------

Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to control (a) Xanadu's quantum photonics hardware, and (b) Xanadu's Strawberry Fields simulator :cite:`killoran2018strawberry`.

This project contains the following folders:

* ``src``: The Blackbird grammar (both lexer and parser rules) in Extended Backus–Naur form

* ``blackbird_python``: Python package containing a Python listener/parser for Blackbird files

* ``blackbird_cpp``: C++ package containing listener, visitor, and parser for Blackbird files

* ``examples``: some example Blackbird programs (with file extension .xbb)


Getting started
---------------

To get Blackbird installed and running on your system, begin at the :ref:`download and installation guide <installation>`. Then, familiarize yourself with the Blackbird's :ref:`syntax and grammar <syntax>` for machine learning on quantum circuits.


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

For more details on contributing or performing research with Blackbird, please see
:ref:`research`.

License
-------

Blackbird is **free** and **open source**, released under the Apache License, Version 2.0.


.. toctree::
   :maxdepth: 1
   :caption: Getting started
   :hidden:

   installing
   syntax
   research
   zreferences

.. toctree::
   :maxdepth: 1
   :caption: Python package
   :hidden:

   blackbird_python/init
   blackbird_python/installing
   blackbird_python/listener
   blackbird_python/auxiliary
   blackbird_python/error

.. toctree::
   :maxdepth: 1
   :caption: C++ library
   :hidden:

   blackbird_cpp/overview
   blackbird_cpp/installing


Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
