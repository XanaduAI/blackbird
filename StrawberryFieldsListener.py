"""Strawberry Fields Blackbird parser"""
import sys
import antlr4

import numpy as np

import strawberryfields as sf
import strawberryfields.ops as sfo

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


def _get_arguments(arguments):
    args = []
    kwargs = {}

    for arg in arguments.getChildren():
        if isinstance(arg, blackbirdParser.ValContext):
            if arg.expression():
                args.append(_expression(arg.expression()))
            elif arg.nonnumeric():
                args.append(_literal(arg.nonnumeric()))
            elif arg.NAME():
                args.append(_var[arg.NAME().getText()])

        elif isinstance(arg, blackbirdParser.KwargContext):
            name = arg.NAME().getText()
            if arg.val().expression():
                kwargs[name] = _expression(arg.val().expression())
            elif arg.val().nonnumeric():
                kwargs[name] = _literal(arg.val().nonnumeric())

    return args, kwargs


class StrawberryFieldsListener(blackbirdListener):
    """Listener to run a Blackbird program using Strawberry Fields"""
    def __init__(self):
        self.var = {}

        self.device = None
        self.device_args = []
        self.device_kwargs = {}

        self.queue = []

        self.q = None
        self.eng = None
        self.result = []

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
            raise TypeError("Var {} = {} is not of declared type {}".format(name, value, vartype)) from None

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
            raise TypeError("Array var {} is not of declared type {}".format(name, vartype)) from None

        if shape is not None:
            actual_shape = final_value.shape
            if actual_shape != shape:
                raise TypeError("Array var {} has declared shape {} but actual shape".format(name, shape, actual_shape)) from None

        _var[name] = final_value

    def exitProgram(self, ctx:blackbirdParser.ProgramContext):
        self.var.update(_var)
        self.device = ctx.device().getText()

        if ctx.arguments():
            self.device_args, self.device_kwargs = _get_arguments(ctx.arguments())

        if 'num_subsystems' not in self.device_kwargs:
            raise ValueError("Must specify the number of subsystems")

        self.eng, self.q = sf.Engine(
            self.device_kwargs['num_subsystems'],
            hbar=self.device_kwargs.get('hbar', 2)
        )

        self.device_kwargs.pop('num_subsystems')
        self.device_kwargs.pop('hbar', None)

        with self.eng:
            for op, modes in self.queue:
                op | [self.q[i] for i in modes]

        shots = self.device_kwargs.get('shots', 1)
        for i in range(shots):
            self.state = self.eng.run(self.device, *self.device_args, **self.device_kwargs)
            self.result.append([q.val for q in self.q])
            self.eng.reset(keep_history=True)

    def exitStatement(self, ctx:blackbirdParser.StatementContext):
        if ctx.operation():
            op = getattr(sfo, ctx.operation().getText())
        elif ctx.measure():
            op = getattr(sfo, ctx.measure().getText())

        if ctx.arguments():
            op_args, op_kwargs = _get_arguments(ctx.arguments())

        modes = [int(i) for i in ctx.modes().getText().split(',')]

        self.queue.append([op(*op_args, **op_kwargs), modes])


def main(argv):
    file = antlr4.FileStream(argv[1])
    lexer = blackbirdLexer(file)
    stream = antlr4.CommonTokenStream(lexer)
    parser = blackbirdParser(stream)
    tree = parser.start()

    blackbird = StrawberryFieldsListener()
    walker = antlr4.ParseTreeWalker()
    walker.walk(blackbird, tree)

    print(np.abs(_var['alpha']**2)**2)
    print(np.mean(blackbird.result))

if __name__ == '__main__':
    main(sys.argv)
