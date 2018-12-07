.. _installation:

Installation
============

.. note::

    See the individual installation details for :ref:`installing the Python <python_installation>`
    and :ref:`compiling and installing the C++ library <cpp_installation>`.

.. _compiling_grammar:

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
