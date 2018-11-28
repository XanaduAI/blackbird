Blackbird Quantum Assembly Language
###################################

Blackbird is a quantum assembly language for continuous-variable quantum computation, that can be used to control (a) Xanadu's quantum photonics hardware, and (b) Xanadu's Strawberry Fields simulator.

This repository contains:

* ``src``: The Blackbird grammar (both lexer and parser rules) in Extended Backus–Naur form

* ``blackbird_python``: Python package containing a Python listener/parser for Blackbird files

* ``blackbird_cpp``: C++ package containing listener, visitor, and parser for Blackbird files

* ``doc``: documentation (can be built using Sphinx)

* ``examples``: some example Blackbird programs (with file extension ``.xbb``)

Strawberry Fields Listener
==========================

In addition, it currently also contains the file ``strawberry_fields_listener.py``, which sub-classes ``blackbird_python.BlackbirdListener``, and extends it to also *run* the Blackbird program using the Strawberry Fields listeners, as a proof of concept.

For example, it can be applied to the provided example file ``example_gbs.xbb``,

.. code-block:: python

    float alpha = 0.3423

    complex array U4[4, 4] =
        -0.374559877614+0.1109693347j,   0.105835208525+0.395338593151j, -0.192128677443-0.326320923534j,  0.663459991938-0.310353146438j
        -0.380767811218+0.17264101141j,  0.420783417348-0.061064767156j, -0.492833372973+0.169005421785j, -0.049425295018+0.608714168654j
        -0.004575175084+0.710803957997j, 0.141905920779+0.230227449191j,  0.508526433013-0.297100053719j, -0.186799328386+0.19958273542j
        -0.390091516639-0.123154657531j, 0.220739102992-0.727908644677j,  0.235216128652-0.427737604015j, -0.002154245945-0.125674446672j

    with gaussian(num_subsystems=4, shots=10):
        Coherent(alpha, sqrt(pi)) | 0
        Interferometer(U4) | [0, 1, 2, 3]
        MeasureX | 0
        MeasureX | 1
        MeasureX | 2
        MeasureX | 3

by running the following line in your terminal:

.. code-block:: console

    python3 strawberry_fields_listener.py examples/example_gbs.xbb

producing the following output:

.. code-block:: console

    Program
    -------
    Run 0:
    Coherent(0.3423, 1.772) | (q[0])
    Rgate(-1.559) | (q[0])
    BSgate(0.4934, 0) | (q[0], q[1])
    Rgate(1.476) | (q[2])
    BSgate(1.094, 0) | (q[2], q[3])
    Rgate(1.787) | (q[1])
    BSgate(1.361, 0) | (q[1], q[2])
    Rgate(1.723) | (q[0])
    BSgate(1.003, 0) | (q[0], q[1])
    Rgate(2.704) | (q[0])
    Rgate(-1.571) | (q[1])
    Rgate(0.07864) | (q[2])
    Rgate(-2.444) | (q[3])
    BSgate(-1.082, 0) | (q[2], q[3])
    Rgate(0.1988) | (q[2])
    BSgate(-0.9824, 0) | (q[1], q[2])
    Rgate(-2.584) | (q[1])
    MeasureX | (q[0])
    MeasureX | (q[1])
    MeasureX | (q[2])
    MeasureX | (q[3])

    Results
    -------
    [0.78741742869032849, 0.4687548968197896, 0.24995884856075234, 0.26017773802799282]
    [-0.38611559831595721, 0.87013137205881896, -0.8637591428902387, 0.87987666305358891]
    [-0.90073440739802579, 0.6541730982429812, -0.17966121619754322, 0.7105191725142429]
    [2.2181871945635283, 0.90784717914877755, -0.14608293659572136, 1.3234082450308977]
    [0.26187400468879646, -0.24350554600924179, 0.15135585268536278, -1.3698092903244679]
    [0.62928125081235919, -2.1680158143971759, -0.99450040689765284, 1.8511289378967497]
    [1.9602717053077034, -1.8998580204278686, 0.23193528358577153, 1.5632428346967497]
    [0.34002902283984326, 0.99624604317845789, -0.32804961033646657, 0.89742913874610075]
    [-0.58834092978787944, -1.0543538025898438, 0.18153026050309107, 0.81751881123822168]
    [1.3795212337550613, -1.0187713250385, 0.50738610139349849, 0.25778266780662962]


Blackbird structure and syntax
==============================

* Blackbird is case sensitive.
* Newlines at the same indentation level indicate the end of a statement.
* Like Python, we use ``#`` for comments.


Variable declarations
---------------------

Variable are defined at the top of the file.

Format for defining variables:

.. code-block:: python

  type name = expression

Allowed literals:

* int: 0, 1, 5
* float: 0.43, -0.123, 89.23e-10
* complex: 5j, 8-1j, 0.54+0.21j
* bool: True, False
* str: any ASCII string surrounded by quotes, "sdfds"

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

Blackbird allows expressions using the operators

* ``+, -, *, /, **``

(``**`` indicates right-associative exponentiation), and the intrinsic functions:

* ``exp()``, ``sin()``, ``cos()``, ``sqrt()``

You can also use PI and previous variable names in your
expressions.

.. code-block:: python

    float gamma = 2*cos(alpha*pi)
    float test = n**2

We can also define arrays, by specifying 'array' after
the variable type.

Note: you can specify the *shape* of the array using square
brackets directly after the variable name (i.e. ``U4[4, 4]``))
but this is optional.

.. code-block:: python

    complex array A =
        -1+2j, 2+1j
        -0.1-0.1j, 0.2-2j

    complex array U4[4, 4] =
        -0.23191638+0.17828953j,  0.58457815+0.41415933j, -0.05795454-0.46965132j,  0.37146591+0.19811629j
        +0.42259383+0.56368926j, -0.42219920+0.04735544j, -0.18902308-0.01590913j,  0.33017685+0.42210731j
        -0.02396850+0.64301446j,  0.09918161+0.36797446j,  0.26993055+0.30341975j, -0.20673325-0.4827536j
        -0.03456721+0.05347453j, -0.01895343-0.40080457j,  0.75577423-0.06297101j,  0.50490422-0.06966875j


Quantum program
---------------

The ``with`` statement indicates the device to run the program on.
Inside the indented ``with`` block, all operations are queued
to be executed on the device, in the order they appear.

For example:

.. code-block:: python

    with fock(num_subsystems=1, cutoff_dim=7, shots=10000):
        # Statements within the 'with' block have the following form:
        Operation(parameters) | modes

        # Depending on the operation, parameters may be optional
        # Parameters can be variables of literals or expressions
        Coherent(alpha**2, Delta*sqrt(pi)) | 0

        # Multiple modes are specified by comma separated integers
        Interferometer(U4) | [0, 1, 2, 3]

        # Finish with measurements
        MeasureFock() | 0
