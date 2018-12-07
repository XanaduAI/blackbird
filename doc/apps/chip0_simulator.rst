C++ Chip0 simulator
===================

A basic C++ simulator for the Chip0 hardware device (capable of coherent sampling)
is also provided, as an example application of using the Blackbird C++ library
to build fast and easy simulators.

To compile this simulator (in addition to the other C++ examples), after you have
installed the Blackbird C++ library, simply run

.. code-block:: console

    $ make cpp-examples

from the top directory, the executable ``bin/chip0_simulator`` will be produced.

Then, run

.. code-block:: console

    $ bin/chip0_simulator examples/example_chip0.xbb

to see this simulator in action.

Source code
-----------

.. literalinclude :: ../../cpp_examples/chip0_simulator.cpp
   :language: cpp
