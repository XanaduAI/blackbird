"""Strawberry Fields Blackbird parser"""
import sys
import antlr4

import numpy as np

import strawberryfields as sf
from strawberryfields.ops import *

from blackbird_python.blackbirdLexer import blackbirdLexer
from blackbird_python.blackbirdParser import blackbirdParser
from blackbird_python.blackbirdListener import blackbirdListener

_var = {}

python_types = {
    'array': np.ndarray,
    'float': float,
    'complex': complex,
    'int': int,
    'str': str,
    'bool': bool
}

numpy_types = {
    'float': np.float64,
    'complex': np.complex128,
    'int': np.int64,
    'str': np.str,
    'bool': np.bool
}

def _literal(nonnumeric):
    if nonnumeric.STR():
        return str(nonnumeric.getText())
    elif nonnumeric.BOOL():
        return bool(nonnumeric.getText())
    else:
        raise ValueError("Unknown value: " + nonnumeric.getText())


def _number(number):
    if number.INT():
        return int(number.getText())
    elif number.FLOAT():
        return float(number.getText())
    elif number.COMPLEX():
        return complex(number.getText())
    elif number.PI:
        return np.pi
    else:
        raise ValueError("Unknown number: " + number.getText())


def _func(function, arg):
    if function.EXP():
        return np.exp(_expression(arg))
    elif function.SIN():
        return np.sin(_expression(arg))
    elif function.COS():
        return np.cos(_expression(arg))
    elif function.SQRT():
        return np.sqrt(_expression(arg))
    else:
        raise NameError("Unknown function: " + function.getText())


def _expression(expr):
    if isinstance(expr, blackbirdParser.NumberLabelContext):
        return _number(expr.number())

    elif isinstance(expr, blackbirdParser.VariableLabelContext):
        if expr.getText() not in _var:
            raise NameError("name '{}' is not defined".format(expr.getText()))
        return _var[expr.getText()]

    elif isinstance(expr, blackbirdParser.BracketsLabelContext):
        return _expression(exp.expression())

    elif isinstance(expr, blackbirdParser.SignLabelContext):
        a = expr.expression()
        if expr.PLUS():
            return _expression(a)
        elif expr.MINUS():
            return -_expression(a)

    elif isinstance(expr, blackbirdParser.AddLabelContext):
        a, b = expr.expression()
        if expr.PLUS():
            return np.sum([_expression(a), _expression(b)])
        elif expr.MINUS():
            return np.subtract([_expression(a), _expression(b)])

    elif isinstance(expr, blackbirdParser.MulLabelContext):
        a, b = expr.expression()
        if expr.TIMES():
            return np.prod([_expression(a), _expression(b)])
        elif expr.DIVIDE():
            return np.divide([_expression(a), _expression(b)])

    elif isinstance(expr, blackbirdParser.PowerLabelContext):
        a, b = expr.expression()
        return np.power(_expression(a), _expression(b))

    elif isinstance(expr, blackbirdParser.FunctionLabelContext):
        return _func(expr.function(), expr.expression())


class StrawberryFieldsListener(blackbirdListener):
    """Listener to run a Blackbird program using Strawberry Fields"""
    def exitExpressionVariableLabel(self, ctx:blackbirdParser.ExpressionVariableLabelContext):
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()
        
        if ctx.expression():
            value = _expression(ctx.expression())
        elif ctx.nonnumeric():
            value = _literal(ctx.nonnumeric())
 
        try:
            final_value = python_types[vartype](value)
        except:
            raise TypeError("Var {} = {} is not of declared type {}".format(name, value, vartype))
        
        _var[name] = final_value
    
    def exitArrayVariableLabel(self, ctx:blackbirdParser.ArrayVariableLabelContext):
        name = ctx.name().getText()
        vartype = ctx.vartype().getText()

        shape = None
        if ctx.shape():
            shape = tuple([int(i) for i in ctx.shape().getText().split(',')])

        value = []
        for i in ctx.arrayval().getChildren():
            if isinstance(i, blackbirdParser.ArrayrowContext):
                value.append([])
                for j in i.getChildren():
                    if j.getText() != ',':
                        value[-1].append(_expression(j))

        try:
            final_value = np.array(value, dtype=numpy_types[vartype])
        except:
            raise TypeError("Array var {} is not of declared type {}".format(name, vartype))

        if shape is not None:
            actual_shape = final_value.shape
            if actual_shape != shape:
                raise TypeError("Array var {} has declared shape {} but actual shape".format(name, shape, actual_shape))

        _var[name] = final_value

    def exitProgram(self, ctx:blackbirdParser.ProgramContext):
        device = ctx.device().getText()



def main(argv):
    file = antlr4.FileStream(argv[1])
    lexer = blackbirdLexer(file)
    stream = antlr4.CommonTokenStream(lexer)
    parser = blackbirdParser(stream)
    tree = parser.start()
    
    blackbird = StrawberryFieldsListener()
    walker = antlr4.ParseTreeWalker()
    walker.walk(blackbird, tree)

    print(_var)

if __name__ == '__main__':
    main(sys.argv)
