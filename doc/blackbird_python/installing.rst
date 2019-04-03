.. _python_installation:

Installation
============


.. note:: Update once uploaded to the PyPI repository


Installing the Python Parser
----------------------------

The Python Blackbird listener requires NumPy and the Python antlr4 runtime, which can be
installed via pip:

.. code-block:: console

    $ pip install numpy antlr4-python3-runtime>=4.7.1

Once this is installed, simply clone the Blackbird git repository, use pip to install:

.. code-block:: console

    $ git clone https://github.com/XanaduAI/Blackbird
    $ cd blackbird
    $ pip install -e .

