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
import copy
from typing import Iterable

import numpy as np
import sympy as sym


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

    def __init__(self, name="blackbird_program", version="1.0"):
        self._var = {}
        self._forvar = {}
        self._modes = set()

        # the following attributes fully describe a Blackbird program
        self._name = name
        self._version = version
        self._target = {"name": None, "options": dict()}
        self._type = {"name": None, "options": dict()}
        self._operations = []
        self._parameters = []

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
            str: version number
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
    def programtype(self):
        """Information regarding the type of program that is to be run on the device.

        Important keys include:

        * ``'name'`` (Union[str, None]): the name of the type of program that is to be run on the
            device (e.g. 'TDM'). If no type is requested, the returned value will be ``None``.
        * ``'options'`` (dict): a dictionary of keyword arguments for the type (e.g. 'copies')

        Returns:
            dict[str->[str, dict]]: type information
        """
        return self._type

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

    @property
    def parameters(self):
        """List of free parameters the Blackbird script depends on.

        Returns:
            List[str]: list of free parameter names
        """
        return set([str(i) for i in self._parameters])

    @property
    def variables(self):
        """List of variables in the Blackbird program.

        Returns:
            dict[str, float]: dictionary of variables
        """
        return self._var

    def is_template(self):
        """Returns ``True`` if there is at least one free parameter.

        Returns:
            bool: True if a template
        """
        return bool(self.parameters)

    def __call__(self, **kwargs):
        """Create a new Blackbird program, with all free parameters
        initialized to their passed values.

        Returns:
            Program:
        """
        if not self.parameters:
            raise ValueError("Program is not a template!")

        prog = copy.deepcopy(self)
        prog._parameters = [] # pylint: disable=protected-access

        # extract the values in any kwarg Iterables so that these correspond to
        # the single valued parsed parameters `parametername_i_j`
        new_kwargs = copy.deepcopy(kwargs)
        for k, v in kwargs.items():
            if isinstance(v, Iterable):
                if np.ndim(v) != 2:
                    raise ValueError("Invalid dim for free parameter provided. Must have dim 2.")

                added_kwargs = {
                    k + "_{}_{}".format(i, j): val
                    for i, row in enumerate(v)
                    for j, val in enumerate(row)
                }
                new_kwargs.update(added_kwargs)
                del new_kwargs[k]

        kwargs = new_kwargs

        # set values for args and kwargs in operations
        for op in prog._operations: # pylint: disable=protected-access
            if 'args' not in op:
                continue

            for idx, a in enumerate(op['args']):
                if isinstance(a, sym.Expr):
                    par = list(a.free_symbols)
                    func = sym.lambdify(par, a)

                    try:
                        vals = {str(p): kwargs[str(p)] for p in par}
                    except KeyError:
                        raise ValueError("Invalid value for free parameter provided")

                    op['args'][idx] = func(**vals)

            for k, v in op['kwargs'].items():
                if isinstance(v, sym.Expr):
                    par = list(v.free_symbols)
                    func = sym.lambdify(par, v)

                    try:
                        vals = {str(p): kwargs[str(p)] for p in par}
                    except KeyError:
                        raise ValueError("Invalid value for free parameter provided")

                    op['kwargs'][k] = func(**vals)

        # set values for variables and arrays
        for k, v in prog._var.items(): # pylint: disable=protected-access
            # it can either be an independent parameter for a variable
            if isinstance(v, sym.Expr):
                par = list(v.free_symbols)
                func = sym.lambdify(par, v)

                try:
                    vals = {str(p): kwargs[str(p)] for p in par}
                except KeyError:
                    raise ValueError("Invalid value for free parameter provided")

                prog._var[k] = func(**vals)
            # or encapsulated in an array
            elif isinstance(v, np.ndarray):
                # look through the array and, if there are any parameters,
                # replace them with their corresponding values from kwargs
                populated_array = copy.deepcopy(v)
                for i, j in np.ndindex(v.shape):
                    if isinstance(v[i][j], sym.Expr):
                        par = list(v[i][j].free_symbols)
                        func = sym.lambdify(par, v[i][j])

                        try:
                            vals = {str(p): kwargs[str(p)] for p in par}
                        except KeyError:
                            raise ValueError("Invalid value for free parameter provided")

                        populated_array[i][j] = func(**vals)

                    prog._var[k] = populated_array

        return prog

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
        # pylint: disable=too-many-statements
        # top level metadata
        var_count = 0
        array_insert = 3

        script = ["name {}".format(self.name), "version {}".format(self.version)]

        # add target and type to the script
        for name, data in [("target", self.target), ("type", self.programtype)]:
            if data["name"] is not None:
                array_insert += 1
                options = ""

                if data["options"]:
                    # if the target has options, compile them into
                    # the expected syntax
                    option_strings = []
                    for k, v in data["options"].items():
                        if not isinstance(v, str):
                            option_strings.append("{}={}".format(k, v))
                        else:
                            option_strings.append('{}="{}"'.format(k, v))

                    options = " ({})".format(", ".join(option_strings))

                # add metadata
                script.append("{} {}{}".format(name, data["name"], options))

        # line break
        script.append("")

        # add variables to the script
        if self.programtype["name"] == "tdm":
            from .listener import NUMPY_TYPES  # pylint:disable=import-outside-toplevel
            inv_type_map = {np.dtype(v).kind: k for k, v in NUMPY_TYPES.items()}

            for k, v in self._var.items():
                var_type = inv_type_map[np.array(v).dtype.kind]
                array_string = ""
                if isinstance(v, Iterable):
                    for row in v:
                        array_string += "\n    " + "".join("{}, ".format(i) for i in row)[:-2]
                    script.append("{} array {} ={}".format(var_type, k, array_string))
                else:
                    script.append("{} array {} =\n{}".format(var_type, k, v))


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
                        # argument is a string type; if a p-type parameter (e.g. p0),
                        # then simply add it as is
                        if self.programtype["name"] == "tdm" and v[0] == "p" and v[1:].isdigit():
                            args.append(v)
                        else:
                            args.append('"{}"'.format(v))

                    elif isinstance(v, complex):
                        # argument is a complex type
                        args.append("{}{}{}j".format(v.real, "+-"[int(v.imag < 0)], np.abs(v.imag)))

                    elif isinstance(v, sym.Expr):
                        # argument contains free parameters
                        res = str(v)
                        for p in v.free_symbols:
                            res = res.replace(str(p), "{"+str(p)+"}")

                        args.append(res)

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
                        # kwarg is a string type; if a p-type parameter (e.g. p0),
                        # then simply add it as is
                        if self.programtype["name"] == "tdm" and v[0] == "p" and v[1:].isdigit():
                            kwargs.append("{}={}".format(k, v))
                        else:
                            kwargs.append('{}="{}"'.format(k, v))

                    elif isinstance(v, complex):
                        kwargs.append(
                            "{}={}{}{}j".format(k, v.real, "+-"[int(v.imag < 0)], np.abs(v.imag))
                        )

                    else:
                        kwargs.append("{}={}".format(k, v))

                if args and kwargs:
                    arguments = "({}, {})".format(", ".join(args), ", ".join(kwargs))
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
