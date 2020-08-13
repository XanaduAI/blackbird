.. _python_installation:

Installation
============

Installing the Blackbird Python parser is easy; the parser and all
dependencies can be installed via ``pip``:

.. code-block:: console

    $ pip install quantum-blackbird


Alternatively, you can install the latest development version directly
from GitHub as follows. The Python Blackbird listener requires NumPy and the Python antlr4 runtime, which can be installed via pip:

.. code-block:: console

    $ pip install numpy antlr4-python3-runtime>=4.8

Once this is installed, simply clone the Blackbird git repository, use pip to install:

.. code-block:: console

    $ git clone https://github.com/XanaduAI/Blackbird
    $ cd blackbird
    $ pip install -e .

