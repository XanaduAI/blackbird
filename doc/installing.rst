.. _installation:

Installation
============


Installing the Python Parser
----------------------------

The Python Blackbird listener requires NumPy and the Python antlr4 runtime, which can be
installed via pip:

.. code-block:: console

    $ pip install numpy antlr4-python3-runtime>=4.7.1

Once this is installed, the Blackbird listener can be installed via

.. code-block:: console

    $ pip install -e .



Compiling the C++ Parser
------------------------

To compile the Blackbird visitor, you will need to have a C++ compiler that supports
C++11 (i.e. ``g++`` version 5 and above), and cmake version 2.8 or above,
as well as the UUID library (``sudo apt install uuid-dev`` on Ubuntu).

In addition, you will need to install the ANTLR C++ Runtime:

.. code-block:: console

    $ git clone https://github.com/antlr/antlr4.git
    $ cd antlr4/runtime/Cpp
    $ cmake -DCMAKE_INSTALL_PREFIX:PATH=$HOME/.local ..
    $ make
    $ make install

Once this is done, you can compile the Blackbird C++ visitor by simply running
``make blackbird-cpp`` from the Blackbird root directory.

**Note:** as the C++ visitor is intended to directly target our photonics hardware,
at the moment it only support the device ``Chip0``, with optional integer kwarg ``shots``,
as well as the operations:

* ``Coherent`` (accepts two float parameters)
* ``Interferometer`` (accepts one complex array parameter)
* ``MeasureIntensity`` (accepts no parameters)


Compiling the grammar
---------------------

.. note::

	This step is optional - Blackbird is packaged with the ANTLR grammar
	already pre-compiled, for both C++ and Python.

To compile the grammar, you will need to install ANTLR 4.7.1:

.. code-block:: console

    $ cd $HOME/.loca/.lib
    $ wget https://www.antlr.org/download/antlr-4.7.1-complete.jar
    $ export CLASSPATH=".:/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH"
    $ alias antlr4='java -jar /usr/local/lib/antlr-4.7.1-complete.jar'
    $ alias grun='java org.antlr.v4.gui.TestRig'

You can then compile the Python and C++ base listeners and visitors by navigating to the
Blackbird root directory, and running ``make grammar``.


Documentation
-------------

To build the documentation, the following additional packages are required:

* `Sphinx <http://sphinx-doc.org/>`_ >=1.5
* `sphinxcontrib-bibtex <https://sphinxcontrib-bibtex.readthedocs.io/en/latest/>`_ >=0.3.6

These can both be installed via ``pip``:

.. code-block:: console

	$ python3 -m pip install sphinx sphinxcontrib-bibtex

To build the HTML documentation, go to the top-level directory and run

.. code-block:: console

	$ make docs

The documentation can then be found in the :file:`doc/_build/html/` directory.
