.. _cpp_installation:

Installation and usage
======================

Compiling the library
---------------------

To compile the Blackbird visitor, you will need to have a C++ compiler that supports
C++11 (i.e., ``g++`` version 5 and above), and cmake version 2.8 or above,
as well as the UUID library (``sudo apt install uuid-dev`` on Ubuntu).

In addition, you will need to install the ANTLR C++ Runtime:

.. code-block:: console

    $ git clone https://github.com/antlr/antlr4.git
    $ cd antlr4/runtime/Cpp
    $ cmake ..
    $ make
    $ sudo make install

Once this is done, you can compile and install the Blackbird C++ library by simply running

.. code-block:: console

    $ make blackbird-cpp
    $ sudo make install

from the Blackbird root directory.

.. note::

    By default, the Blackbird C++ library will attempt to install itself in the relevent
    system directories (i.e., ``/usr/local/lib``). To change this behaviour, you can pass
    the preferred installation directory using the ``PREFIX`` environment variable.

    For example, to install the library and header files locally,

    .. code-block:: console

        $ PREFIX=../ make blackbird-cpp
        $ make install

    This will install the library and public headers in the directories ``lib`` and ``include``,
    respectively, in the current directory.


Usage
-----

The following is a simple C++ file that uses the Blackbird C++ library to parse Blackbird code:

.. code-block:: cpp

    #include <iostream>
    #include "Blackbird.h"

    int main(int argc, const char* argv[])
    {
        std::ifstream stream;
        stream.open(argv[1]);

        // parse the Blackbird script
        blackbird::Program* program = blackbird::parse_blackbird(stream);

        // print device info
        std::cout << std::endl;
        program->print_device_info();
        // print operations
        std::cout << std::endl;
        program->print_operations();

        return 0;
    }

This simple program does the following:

1. It reads in a filename from the command line, and opens it as a file stream.

2. We use the function :cpp:func:`parse_blackbird`, provided by the included
   ``Blackbird.h`` header, to parse the Blackbird script, and store the results
   in a :cpp:class:`Program` class object ``program``.

3. The :cpp:class:`Program` class contains various members and functions for viewing
   and manipulating the resulting Blackbird quantum program. For example, it contains
   the name of the hardware/simulator device, and other device parameters such as
   number of shots, etc.

   In addition, it also includes the member :cpp:member:`operations`, a
   :cpp:expr:`std::vector<Operation*>` object which contains the queued Blackbird
   operations, as well as all their parameters.

In this case, we simply use the member functions :cpp:func:`print_device_info`
and :cpp:func:`print_operations` to output to the console information about the program.


Compiling your code
-------------------

Your C++ program which uses the Blackbird library can then be compiled by linking to the Blackbird
and altr4-runtime libraries, and pointing your C++ compiler to the installed header files. For
example, using ``g++``:

.. code-block:: console

    $ g++ main.cpp -o main \
        -I/path/to/blackbird/include \
        -I/path/to/antlr4/include \
        -L/path/to/blackbird/lib \
        -lantlr4-runtime -lblackbird

