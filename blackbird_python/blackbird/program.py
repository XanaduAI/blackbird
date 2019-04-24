# Copyright 2019 Xanadu Quantum Technologies Inc.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# pylint: disable=too-many-return-statements,too-many-branches,too-many-instance-attributes
"""
Blackbird Program class
=======================

**Module name:** `blackbird.program`

.. currentmodule:: blackbird.program

This module contains a Python class representing a Blackbird
program using standard Python data types.

The functions :func:`~.load`, and :func:`~.loads` will read Blackbird scripts
and return an instance of the :class:`BlackbirdProgram` class.

Summary
-------

.. autosummary::
    numpy_to_blackbird
    BlackbirdProgram

Code details
~~~~~~~~~~~~
"""
import numpy as np


def numpy_to_blackbird(A, var_name):
    """Converts a numpy array to a Blackbird script array type.

    Args:
        A (array): 2-dimensional NumPy array
        var_name (str): the array variable name

    Returns:
        list[str]: list containing each line representing the
            Blackbird array variable declaration
    """

    if np.issubdtype(A.dtype, np.complexfloating):
        # complex array
        script = ["complex array {}[{}, {}] =".format(var_name, *A.shape)]
        for row in A:
            row_str = "    " + ", ".join(
                ["{0}{1}{2}j".format(n.real, "+-"[int(n.imag < 0)], abs(n.imag)) for n in row]
            )
            script.append(row_str)

    elif np.issubdtype(A.dtype, np.integer):
        # integer array
        script = ["int array {}[{}, {}] =".format(var_name, *A.shape)]
        for row in A:
            row_str = "    " + ", ".join(["{}".format(int(n)) for n in row])
            script.append(row_str)

    elif np.issubdtype(A.dtype, np.floating):
        # real array
        script = ["float array {}[{}, {}] =".format(var_name, *A.shape)]
        for row in A:
            row_str = "    " + ", ".join(["{}".format(n) for n in row])
            script.append(row_str)

    else:
        # unknown array type
        raise ValueError("Array {} is of unsupported type {}".format(A, A.dtype))

    script.append("")

    return script


class BlackbirdProgram:
    """Python representation of a Blackbird program."""

    def __init__(self, name="blackbird_program", version=1.0):
        self._var = {}
        self._modes = set()

        # the following attributes fully describe a Blackbird program
        self._name = name
        self._version = version
        self._target = {"name": None, "options": dict()}
        self._operations = []

    @property
    def name(self):
        """Name of the Blackbird program

        Returns:
            str: name
        """
        return self._name

    @property
    def version(self):
        """Version of the Blackbird parser the program targets

        Returns:
            float: version number
        """
        return self._version

    @property
    def modes(self):
        """A set of non-negative integers specifying the mode numbers the program manipulates.

        Returns:
            set[int]: mode numbers
        """
        return self._modes

    @property
    def target(self):
        """Contains information regarding the target device of the quantum
        program (i.e., the target device the Blackbird script is compiled for).

        Important keys include:

        * ``'name'`` (Union[str, None]): the name of the device the Blackbird script requests to be
            run on. If no target is requested, the returned value will be ``None``.
        * ``'options'`` (dict): a dictionary of keyword arguments for the target device

        Returns:
            dict[str->[str, dict]]: target information
        """
        return self._target

    @property
    def operations(self):
        """List of operations to apply to the device, in temporal order.

        Each operation is contained as a dictionary, with the following keys:

        * ``'op'`` (str): the name of the operation
        * ``'args'`` (list): a list of positional arguments for the operation
        * ``'kwargs'`` (dict): a dictionary of keyword arguments for the operation
        * ``'modes'`` (list[int]): modes the operation applies to

        Note that, depending on the operation, both ``'args'`` and ``'kwargs'``
        might be empty.

        Returns:
            list[dict]: operation information
        """
        return self._operations

    def __len__(self):
        """The length of the quantum program (i.e., the number of operations applied).

        Returns:
            int: program length
        """
        return len(self._operations)

    def serialize(self):
        """Serializes the blackbird program, returning a valid Blackbird script
        as a string.

        Returns:
            str: the blackbird script representing the BlackbirdProgram object
        """
        # top level metadata
        var_count = 0
        array_insert = 3

        script = ["name {}".format(self.name), "version {}".format(self.version)]

        if self.target["name"] is not None:
            array_insert += 1
            options = ""

            if self.target["options"]:
                # if the target has options, compile them into
                # the expected syntax
                option_strings = [
                    "{}={}".format(k, v) if not isinstance(v, str) else '{}="{}"'.format(k, v)
                    for k, v in self.target["options"].items()
                ]
                options = " ({})".format(", ".join(option_strings))

            # add target metadata
            script.append("target {}{}".format(self.target["name"], options))

        # line break
        script.append("")

        # loop through each quantum operation
        for op in self.operations:
            if len(op["modes"]) == 1:
                modes = op["modes"][0]
            else:
                modes = op["modes"]

            # check if the operation has any arguments
            if "args" in op:
                args = []
                kwargs = []

                # loop through position arguments
                for v in op["args"]:
                    # for each operation argument, format it
                    # correctly depending on its type
                    if isinstance(v, np.ndarray):
                        # create an array variable
                        var_name = "A{}".format(var_count)
                        args.append(var_name)
                        var_count += 1

                        # add array declaration to script after the metadata block
                        bb_array = numpy_to_blackbird(v, var_name)
                        for idx, line in enumerate(bb_array):
                            script.insert(array_insert + idx, line)

                        array_insert += len(bb_array)

                    elif isinstance(v, str):
                        # argument is a string type
                        args.append('"{}"'.format(v))

                    elif isinstance(v, complex):
                        # argument is a complex type
                        args.append("{}{}{}j".format(v.real, "+-"[int(v.imag < 0)], np.abs(v.imag)))

                    else:
                        # anything that doesn't need to be dealt with as a special case,
                        # i.e., booleans, ints, floats.
                        args.append("{}".format(v))

                # loop through keyword argument
                for k, v in op["kwargs"].items():
                    # for each operation argument, format it
                    # correctly depending on its type
                    if isinstance(v, np.ndarray):
                        # create an array variable
                        var_name = "A{}".format(var_count)
                        kwargs.append("{}={}".format(k, var_name))
                        var_count += 1

                        # add array declaration to script
                        bb_array = numpy_to_blackbird(v, var_name)
                        for idx, line in enumerate(bb_array):
                            script.insert(array_insert + idx, line)

                        array_insert += len(bb_array)

                    elif isinstance(v, str):
                        kwargs.append('{}="{}"'.format(k, v))

                    elif isinstance(v, complex):
                        kwargs.append(
                            "{}={}{}{}j".format(k, v.real, "+-"[int(v.imag < 0)], np.abs(v.imag))
                        )

                    else:
                        kwargs.append("{}={}".format(k, v))

                if args and kwargs:
                    # arguments = "({}, {})".format(", ".join(args), ", ".join(kwargs))
                    raise ValueError(
                        "Blackbird currently doesn't support operations "
                        "which contain both positional and keyword arguments. "
                        "\nPlease provide all operation arguments as keyword arguments for now."
                    )
                elif not kwargs:
                    arguments = "({})".format(", ".join(args))
                elif not args:
                    arguments = "({})".format(", ".join(kwargs))

                script.append("{}{} | {}".format(op["op"], arguments, modes))
            else:
                # operation has no arguments
                script.append("{} | {}".format(op["op"], modes))

        if script[-1] != "":
            # add a newline
            script.append("")

        return "\n".join(script)
