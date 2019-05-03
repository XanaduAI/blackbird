Example
=======

This page contains a small guide demonstrating how to use the Python Blackbird parser
in your Python application, to enable the loading or saving of Blackbird scripts.


To start, simply import the Blackbird library into the Python module where it is
required:

.. code-block:: python

    import blackbird


Deserializing Blackbird
-----------------------

To parse and extract information from a Blackbird text file, with extension ``.xbb``,
simply use the :func:`~.load` function.

For example, consider the following Blackbird file:

.. code-block:: python

    name StateTeleportation
    version 1.0
    target gaussian (shots=1000)

    # state to be teleported:
    complex alpha = 1+0.5j
    Coherent(alpha) | 0

    # maximally entangled states
    Squeezed(-4) | 1
    Squeezed(4) | 2
    BSgate(pi/4, 0) | (1, 2)

    # Alice performs the joint measurement
    # in the maximally entangled basis
    BSgate(pi/4, 0) | (0, 1)
    MeasureX | 0
    MeasureP | 1

    # Bob conditionally displaces his mode
    # based on Alice's measurement result
    Xgate(sqrt(2)*q0) | 2
    Zgate(sqrt(2)*q1) | 2

    MeasureHeterodyne() | 2


To import this into our Python module:

.. code-block:: python

    bb = blackbird.load("example/state_teleportation.xbb')

The returned object ``bb`` is a :class:`~.BlackbirdProgram`, with various attributes
and properties that can be queried to return information about the program:

* :attr:`~.name`: name of the Blackbird program

* :attr:`~.version`: version of the Blackbird language the program targets

* :attr:`~.modes`: a set of non-negative integers specifying the mode numbers the
  program manipulates

* :attr:`~.target`: a dictionary containing information regarding the target device
  (i.e., the target device the Blackbird script is compiled for)

* :attr:`~.operations`: list of operations to apply to the device, in temporal
  order.


For example,

>>> bb.name
StateTeleportation
>>> bb.operations
[{'args': [(1+0.5j)], 'kwargs': {}, 'modes': [0], 'op': 'Coherent'},
{'args': [-4], 'kwargs': {}, 'modes': [1], 'op': 'Squeezed'},
{'args': [4], 'kwargs': {}, 'modes': [2], 'op': 'Squeezed'},
{'args': [0.7853981633974483, 0],'kwargs': {},'modes': [1, 2],'op': 'BSgate'},
{'args': [0.7853981633974483, 5],'kwargs': {},'modes': [0, 1],'op': 'BSgate'},
{'modes': [0], 'op': 'MeasureX'},
{'modes': [1], 'op': 'MeasureP'},
{'args': [1.4142135623731*q0], 'kwargs': {}, 'modes': [2], 'op': 'Xgate'},
{'args': [1.4142135623731*q1], 'kwargs': {}, 'modes': [2], 'op': 'Zgate'},
{'args': [], 'kwargs': {}, 'modes': [2], 'op': 'MeasureHeterodyne'}]


For more information, see the :class:`~.BlackbirdProgram` page.

.. note::

    If the Blackbird program to be deserialized is a Python string, not
    a filename, you can alternatively use the :func:`~.loads` function.


Serializing Blackbird
---------------------

A :class:`~.BlackbirdProgram` object that has been modified or constructed
can always be serialized back into a valid Blackbird script, via the
:func:`~.dump` and :func:`~.dumps` functions.

For example, to serialize to a string using :func:`~.dumps`:

>>> print(blackbird.dumps(bb))
name StateTeleportation
version 1.0
target gaussian (shots=1000)
|
Coherent(1.0+0.5j) | 0
Squeezed(-4) | 1
Squeezed(4) | 2
BSgate(0.7853981633974483, 0) | [1, 2]
BSgate(0.7853981633974483, 5) | [0, 1]
MeasureX | 0
MeasureP | 1
Xgate(1.4142135623731*q0) | 2
Zgate(1.4142135623731*q1) | 2
MeasureHeterodyne() | 2


Or, to serialize to a file or any 'file-like' object that supports the ``write`` method
using :func:`~.dump`:

.. code-block:: python

    with open('new_file.xbb', 'w') as f:
        blackbird.dump(bb, f)

