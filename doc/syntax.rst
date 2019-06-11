.. _syntax:

Syntax and grammar
==================


.. note::

    The Blackbird used *directly* inside a Strawberry Fields Engine context
    is a **superset** of the Blackbird quantum assembly language described here,
    as it is embedded in a Python environment.

    You can think of it as 'Python-enhanced Blackbird', as Python functions and constructs,
    can be used, even if they are not 'officially' part of the Blackbird spec.


Introduction
------------

In this section, we define the structure, syntax, and grammar of Blackbird code.

Philosophy
~~~~~~~~~~

Blackbird was designed from the ground up, adhering to the following philosophies:

**Encapsulate any universal photonic quantum computation.**

**Be clear, concise, and simple to read and follow.** This simplicity should allow for both

* **Human readability** - operations and expressions should correspond to
  existing conventions, and allude to common notation in quantum computing

* **Hardware execution** - code should be unambiguous, with one quantum operation per line

**Be easy to learn, using constructs and operators familiar in scientific computation**.

**A Blackbird script should contain only one quantum algorithm or simulation,
making it an ideal format for saving and loading photonic quantum computing algorithms.**


Similarity to Python
~~~~~~~~~~~~~~~~~~~~

To satisfy points 2 and 3, Blackbird is deliberately Python-like, inheriting
the following:

* Case sensitivity.

.. 

* ``#`` for line comments.

.. 

* Newlines indicate the end of a statement.

.. 

* Operators and literals are similar to their Python equivalents.

.. 

* The ``|`` operator is used to apply intrinsic quantum operations to quantum registers.

.. 

* After measurement, quantum modes are automatically and implicitly converted into
  classical registers.

.. 

* The resulting output is implicitly determined by the presence of measurement statements.

Differences to Python
~~~~~~~~~~~~~~~~~~~~~

Contrary to Python, however, we also introduce the following restrictions,
to enable Blackbird to function as a quantum assembly language across
a wide array of quantum hardware:


* Statically typed - you must declare the variable type, and variables
  and arguments of conflicting types are **not** automatically cast to the correct type.

.. 

* Array variables may be declared, but Blackbird does not support array manipulation.


Metadata
--------

All Blackbird programs must begin with a required metadata block as follows:

.. code-block:: python

    name progam_name
    version 1.0

The ``name`` and the ``version`` keywords must be given in the order above and
are *mandatory*. The name simply specifies the name of your Blackbird program,
while the version number is the version number of the Blackbird spec it is written
for.

In addition, you may specify an optional ``target`` keyword:

.. code-block:: python

    target chip0

This indicates the device or simulator the Blackbird program targets --- that is,
you are specifying that the contained Blackbird code is compiled for the targeted
device/simulator.

The target keyword also accepts keyword options, using the syntax
``(option1=0.32, option2=40)``. For example:


.. code-block:: python

    target chip0 (shots=100)


Variable declarations
---------------------

Variable may be optionally defined on any new line in the blackbird script.

The syntax for defining variables is as follows:

.. code-block:: python

  type name = expression

with the following types supported:

* ``int``: ``0``, ``1``, ``5``
* ``float``: ``8.0``, ``0.43``, ``-0.123``, ``89.23e-10``
* ``complex``: ``0+5j``, ``8.1-1j``, ``0.54+0.21j``
* ``bool``: ``True``, ``False``
* ``str``: any ASCII string surrounded by double quotation marks, ``"hello world"``

.. note::

    * When using a float, you must provide the full decimal. I.e., ``8`` and ``8.``
      are not valid floats, but ``8.0`` is.

    * When using a complex, you must provide both real and imaginary parts.
      I.e., ``8`` and ``2j`` are not valid complex literals, but ``8+0j`` is.

Examples:

.. code-block:: python

    int n = +5
    int k = n

    float m = -0.5432
    float alpha = 0.5432
    float x = 0.5+0.1
    float Delta = 0.543

    complex beta = 5.21
    complex y = -0.43e-4+0.912j
    complex z = +0.43e-4-0.912j

    bool flag = True
    str name = "program1"

.. warning::

    All variable names are allowed, *except* those consisting of a single 'q' followed
    by an integer, for example ``q0``, ``q1``, ``q2``, etc. These are reserved for
    quantum register references.

Operators
~~~~~~~~~

Blackbird allows expressions using the following operators:

* ``+``: addition, unary positive
* ``-``: subtraction, unary negation
* ``*``: multiplication
* ``/``: division
* ``**``: right-associative exponentiation.

.. 
    * Blackbird will attempt to dynamically cast variables where it makes sense.
      For example, consider the following:
      .. code-block:: python
        int n = 2
        float x = 5.0**n
      Blackbird will automatically cast variable ``n`` to a float to perform the calculation.
      However, note that literals will not be automatically cast - ``float x = 5**n`` would
      return an error, as ``5`` is an ``int`` and not a float.
    * No matrix operations are defined; if the expression includes arrays, these operators will act in an elementwise manner.

Functions
~~~~~~~~~

Blackbird also supports the intrinsic functions

* ``sqrt()``
* ``exp()``, ``log``
* ``sin()``, ``cos()``, ``tan()``
* ``arcsin()``, ``arccos()``, ``arctan()``
* ``sinh()``, ``cosh()``, ``tanh()``
* ``arcsinh()``, ``arccosh()``, ``arctanh()``

and the intrinsic constant

* ``pi``

You can also use previously defined variable names in your expressions:

.. code-block:: python

    float gamma = 2.0*cos(alpha*pi)
    float test = n**2.0

Arrays
~~~~~~

To define arrays, specify ``'array'`` after the variable type.
Each row of the array is then defined on an indented line, with
columns separated by commas.

.. code-block:: python

    float array A =
        -1.0, 2.0
        -0.1, 0.2

    complex array U[3, 3] =
        -0.23191638+0.17828953j,  0.58457815+0.41415933j, -0.05795454-0.46965132j
        +0.42259383+0.56368926j, -0.42219920+0.04735544j, -0.18902308-0.01590913j
        -0.02396850+0.64301446j,  0.09918161+0.36797446j,  0.26993055+0.30341975j


.. note::

    For additional array validation, you can specify the *shape* of the array using square
    brackets directly after the variable name (i.e., ``U[3, 3]``)
    but this is optional.

Quantum program
---------------

The ``|`` operator is used to apply intrinsic quantum operations to quantum registers.

For example:

.. code-block:: python

    # Statements have the following form:
    Operation(parameters) | modes

    # Depending on the operation, parameters may be optional
    # Parameters can be variables of literals or expressions
    complex alpha = 0.5+0.2
    float delta = 0.5423
    Coherent(alpha**2, Delta*sqrt(pi)) | 0

    # Multiple modes are specified by comma separated integers
    Interferometer(U) | [0, 1, 2, 3]

    # Finish with measurements
    MeasureFock() | 0

Currently, the device always accepts keyword arguments, and operations always accept
positional arguments.

To pass measured mode values to successive gate arguments, you may use the reserved
variables ``qX``, where ``X`` is an integer representing mode ``X``, as parameters:

.. code-block:: python

    S2gate(0.43, 0.12) | [0, 1]
    MeasureX | 0
    MeasureP | 1
    Xgate(sqrt(2)*q0+q1) | 2

After running a Blackbird program, the user should expect to receive the results
as an array:

* each column is a measurement result, corresponding to the measurements in the order
  they appear in the blackbird program

* each row represents a shot/run

Templates
---------

A Blackbird template is simply a Blackbird script that contains **template parameters**.

Template parameters use the syntax ``{parameter_name}``, and can be placed within any numeric expression.

For example, consider the following state teleportation template:

.. code-block:: python

    name StateTeleportation
    version 1.0

    # state to be teleported:
    Coherent({alpha}) | 0

    # teleportation algorithm
    Squeezed(-{sq}) | 1
    Squeezed({sq}) | 2
    BSgate(pi/4, 0) | (1, 2)
    BSgate(pi/4, 0) | (0, 1)
    MeasureX | 0
    MeasureP | 1
    Xgate(sqrt(2)*q0) | 2
    Zgate(sqrt(2)*q1) | 2

Here, the initial state preparation uses a template parameter ``{alpha}``,
while the squeezed resource states have magnitude given by parameter ``{sq}``.

The advantage of Blackbird templates is that a Blackbird script can encapsulate
a photonic quantum circuit with free parameters. A library that makes use
of the Blackbird quantum assembly language (such as Strawberry Fields) can
dynamically update template parameters without needing to recompile the program.


Including subroutines
---------------------

There may be the case where you have a Blackbird program or template representing
a circuit primitive that you may want to re-use across multiple Blackbird programs.

This is possible using the ``include`` statement. This has the following syntax:

.. code-block:: python

    include "path/to/filename.xbb"

where the file path is relative to the location of the current Blackbird script.
A Blackbird script may have multiple includes, and they must all be placed
after the metadata block, and before the quantum program/variables are defined.

The ``include`` statement allows the external Blackbird program to be used as
a subroutine within the existing script. This quantum subroutine is called
via the ``name`` of the included Blackbird script. For example, consider
a state teleportation template, ``state_teleportation.xbb``:

.. code-block:: python

    name StateTeleportation
    version 1.0

    # maximally entangled states
    Squeezed(-{sq}) | 1
    Squeezed({sq}) | 2
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

This template accepts the parameter ``sq`` (the squeezing magnitude of the
resource states), and acts on three modes, teleporting the state in mode 0
to mode 2.

Now, consider another file, ``example_include.xbb``, which includes the
above ``StateTeleportation`` operation imported from the ``state_teleportation.xbb``
template:


.. code-block:: python

    name ExampleInclude
    version 1.0
    target gaussian (shots=10)

    include "state_teleportation.xbb"

    float alpha = 0.3423

    Coherent(a=alpha) | 0
    Coherent(a=alpha) | 1
    StateTeleportation(sq=1) | [0, 2, 3]
    MeasureHeterodyne() | 3

We can now call the ``StateTeleportation`` subroutine, with ``sq=1``,
and apply it to modes 0, 2, and 3.

.. note:: Make sure to avoid **circular includes** when using the ``include`` statement.
