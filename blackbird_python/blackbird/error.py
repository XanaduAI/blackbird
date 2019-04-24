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
Syntax errors
=============

**Module name:** :mod:`blackbird.error`

.. currentmodule:: blackbird.error

This module contains the class :class:`~.BlackbirdErrorListener`, which
inherits the standard ANTLR4 error listener, and overrides the default
``syntaxError`` method.

This custom listener enables us to:

1. Remove the extraneous Python traceback, which we generally do not
   want users to see.

2. Replace some common ANTLR error messages, which can be a bit obfuscating,
   with ones that are more informative.

Note that we do not try and replace *all* error messages, just the more
common ones that the user is likely to come across.

Summary
-------

.. autosummary::
   NoTraceBack
   BlackbirdSyntaxError
   BlackbirdErrorListener


Code details
~~~~~~~~~~~~
"""
# pylint: disable=too-many-statements, protected-access
import sys
import antlr4

from .blackbirdParser import blackbirdParser


class NoTraceBack(Exception):
    """A generic exception with no traceback provided"""

    def __init__(self, msg):
        """Method executed when the exception is called.

        Args:
            msg (str): message to be printed in the traceback
        """
        # pylint: disable=super-init-not-called,unused-argument
        try:
            _ = sys.exc_info()[-1].tb_lineno
        except AttributeError:
            pass
        sys.exit(self)


class BlackbirdSyntaxError(NoTraceBack):
    """Blackbird syntax error exception"""

    pass


class BlackbirdErrorListener(antlr4.error.ErrorListener.ErrorListener):
    """Custom error listener for Blackbird"""

    # At some point, it will be more scalable to introduce more parser rules
    # to explicitly match incorrect Blackbird code, to automate the exception handling.
    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        if e:
            ctx = e.ctx
        else:
            # if the parser is able to recover from the error inline, no exception
            # is returned from the parser. Instead, we can get the context from the parser itself.
            ctx = recognizer._ctx

        if offendingSymbol.text in {";", "[", "]", "\\", "$", "@", "&", "%", "~", "`", "?"}:
            # inform the user of invalid symbol usage
            error_msg = "Blackbird SyntaxError (line {}:{}): {} is not a valid Blackbird symbol."
            raise BlackbirdSyntaxError(
                error_msg.format(line, column + 1, offendingSymbol.text)
            ) from None

        if isinstance(ctx, blackbirdParser.ExpressionvarContext):
            # if we are in a variable declaration, inform the user which variable
            # has the syntax error, and what we are expecting
            var_name = ctx.name().getText()
            var_type = ctx.vartype().getText()

            if not ctx.ASSIGN():
                # equal sign was not found
                error_msg = "Blackbird SyntaxError (line {}:{}): variable {} missing an assignment."
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1, var_name)) from None

            if offendingSymbol.text == "\n":
                # expression terminated midway by a new line
                error_msg = "Blackbird SyntaxError (line {}:{}): variable {} has an incomplete value or expression"
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1, var_name)) from None

            # otherwise, return a more generic variable error
            syntax_msg = (
                "Blackbird SyntaxError (line {}:{}): variable {} contains the "
                "symbol {} which is not a valid {}."
            )
            raise BlackbirdSyntaxError(
                syntax_msg.format(line, column + 1, var_name, offendingSymbol.text, var_type)
            ) from None

        if isinstance(ctx, blackbirdParser.ArrayvarContext):
            # if we are in an array variable declaration
            var_name = ctx.name().getText()

            if "expecting NEWLINE" in msg:
                # and there is no newline after the equals sign, raise an error
                error_msg = (
                    "Blackbird SyntaxError (line {}:{}): array declaration requires a new line after '=', "
                    "followed by the indented and comma-separated array values."
                )
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1, var_name)) from None

        # iterate up through the tree, and determine if we are in an array declaration
        parent_ctx = ctx
        while parent_ctx:
            parent_ctx = dict(parent_ctx.__dict__.items())["parentCtx"]

            if isinstance(parent_ctx, blackbirdParser.ArrayvarContext):
                # if we are in an array declaration, inform the user which variable
                # has the syntax error, and what we are expecting
                var_type = parent_ctx.vartype().getText()
                var_name = parent_ctx.name().getText()
                syntax_msg = "Blackbird SyntaxError (line {}:{}): - array {} contains the symbol {} is not a valid {}."
                raise BlackbirdSyntaxError(
                    syntax_msg.format(line, column + 1, var_name, offendingSymbol.text, var_type)
                ) from None

        if isinstance(ctx, blackbirdParser.StatementContext):
            # we are in a statement context
            if ctx.operation():
                op_name = ctx.operation().NAME().getText()
            elif ctx.measure():
                op_name = ctx.measure().MEASURE().getText()

            if msg == "mismatched input '\\n' expecting {INT, '(', '['}":
                # there are no modes provided, raise an error
                error_msg = "Blackbird SyntaxError (line {}:{}): statement {} is missing modes."
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1, op_name)) from None

            if "expecting {NEWLINE, ')', ']'}" in msg:
                # there are additional integer mode numbers provided, but they are not comma separated,
                # or there are no matching brackets.
                error_msg = (
                    "Blackbird SyntaxError (line {}:{}): multiple modes must be separated by commas, "
                    "and optionally enclosed in either square [] or round () brackets."
                )
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1)) from None

        if isinstance(ctx, blackbirdParser.StartContext):
            if "expecting {NEWLINE, 'name'}" in msg:
                # no name metadata
                error_msg = (
                    "Blackbird SyntaxError (line {}:{}): blackbird 'name' statement is missing."
                )
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1)) from None

        if isinstance(ctx, blackbirdParser.MetadatablockContext):
            if "expecting {NEWLINE, 'version'}" in msg:
                # no name metadata
                error_msg = (
                    "Blackbird SyntaxError (line {}:{}): blackbird 'version' statement is missing."
                )
                raise BlackbirdSyntaxError(error_msg.format(line, column + 1)) from None

        # otherwise, return a general syntax error, and pass through the original ANTLR4 error message.
        error_msg = "Blackbird SyntaxError (line {}:{}): {}"
        raise BlackbirdSyntaxError(error_msg.format(line, column + 1, msg)) from None
