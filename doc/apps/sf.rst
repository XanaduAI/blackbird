Strawberry Fields Listener
==========================

The Strawberry Fields listener :download:`strawberry_fields_listener.py <../../apps/strawberry_fields_listener.py>` is an
example program that uses the Blackbird Python parser to read a Blackbird script,
and automatically run it using a local Strawberry Fields installation.

To test the Strawberry Fields Listener, create the Blackbird program ``example_gbs.xbb``,

.. code-block:: python

    name CoherentSampling
    version 1.0
    target gaussian (shots=10)

    float alpha = 0.3423

    complex array U4[4, 4] =
        -0.374559877614+0.1109693347j,   0.105835208525+0.395338593151j, -0.192128677443-0.326320923534j,  0.663459991938-0.310353146438j
        -0.380767811218+0.17264101141j,  0.420783417348-0.061064767156j, -0.492833372973+0.169005421785j, -0.049425295018+0.608714168654j
        -0.004575175084+0.710803957997j, 0.141905920779+0.230227449191j,  0.508526433013-0.297100053719j, -0.186799328386+0.19958273542j
        -0.390091516639-0.123154657531j, 0.220739102992-0.727908644677j,  0.235216128652-0.427737604015j, -0.002154245945-0.125674446672j

    Coherent(alpha, sqrt(pi)) | 0
    Interferometer(U4) | [0, 1, 2, 3]
    MeasureX | 0
    MeasureX | 1
    MeasureX | 2
    MeasureX | 3

Then, run the following line in your terminal:

.. code-block:: console

    python3 apps/strawberry_fields_listener.py example_gbs.xbb

The program should produce output of the following form:

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
    [-0.17006682173581544, -0.09825970340668835, 0.44794947054926926, -0.052141596937362866]
    [1.3597317092891867, -0.6293160070092271, 0.04519790741364871, -1.8873553605171045]
    [-1.1013278108973397, -0.7114743288391043, -0.8531760815336981, -0.5480510054544384]
    [0.752548787373888, -0.28145115083954964, 0.025837409928979538, -0.3876104080308481]
    [-0.3950863408984888, -0.10666861383940199, -1.0859313861107587, 1.1460402566515573]
    [-0.14219579976428415, -0.8073492686514543, -0.2680357733457276, 1.2094804424717647]
    [1.448440271857404, -0.910255465637305, -0.6277964002917744, 0.7318466771766851]
    [0.04867173005302908, -0.06002034383841427, -0.3508878249063201, -0.4967925510880631]
    [0.3176843381426753, -1.162220958492132, -0.3853901767570399, -0.3913219425517237]
    [2.072597223449096, -0.030247777077356014, 0.3279580729444779, -1.6905388925113236]

.. note::

    As the measurements performed in this program are stochastic, the result values will change
    with every program run!
