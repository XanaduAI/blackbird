# Generated from blackbird.g4 by ANTLR 4.7.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .blackbirdParser import blackbirdParser
else:
    from blackbirdParser import blackbirdParser

# This class defines a complete listener for a parse tree produced by blackbirdParser.
class blackbirdListener(ParseTreeListener):

    # Enter a parse tree produced by blackbirdParser#start.
    def enterStart(self, ctx:blackbirdParser.StartContext):
        pass

    # Exit a parse tree produced by blackbirdParser#start.
    def exitStart(self, ctx:blackbirdParser.StartContext):
        pass


    # Enter a parse tree produced by blackbirdParser#metadatablock.
    def enterMetadatablock(self, ctx:blackbirdParser.MetadatablockContext):
        pass

    # Exit a parse tree produced by blackbirdParser#metadatablock.
    def exitMetadatablock(self, ctx:blackbirdParser.MetadatablockContext):
        pass


    # Enter a parse tree produced by blackbirdParser#declarename.
    def enterDeclarename(self, ctx:blackbirdParser.DeclarenameContext):
        pass

    # Exit a parse tree produced by blackbirdParser#declarename.
    def exitDeclarename(self, ctx:blackbirdParser.DeclarenameContext):
        pass


    # Enter a parse tree produced by blackbirdParser#programname.
    def enterProgramname(self, ctx:blackbirdParser.ProgramnameContext):
        pass

    # Exit a parse tree produced by blackbirdParser#programname.
    def exitProgramname(self, ctx:blackbirdParser.ProgramnameContext):
        pass


    # Enter a parse tree produced by blackbirdParser#version.
    def enterVersion(self, ctx:blackbirdParser.VersionContext):
        pass

    # Exit a parse tree produced by blackbirdParser#version.
    def exitVersion(self, ctx:blackbirdParser.VersionContext):
        pass


    # Enter a parse tree produced by blackbirdParser#versionnumber.
    def enterVersionnumber(self, ctx:blackbirdParser.VersionnumberContext):
        pass

    # Exit a parse tree produced by blackbirdParser#versionnumber.
    def exitVersionnumber(self, ctx:blackbirdParser.VersionnumberContext):
        pass


    # Enter a parse tree produced by blackbirdParser#target.
    def enterTarget(self, ctx:blackbirdParser.TargetContext):
        pass

    # Exit a parse tree produced by blackbirdParser#target.
    def exitTarget(self, ctx:blackbirdParser.TargetContext):
        pass


    # Enter a parse tree produced by blackbirdParser#device.
    def enterDevice(self, ctx:blackbirdParser.DeviceContext):
        pass

    # Exit a parse tree produced by blackbirdParser#device.
    def exitDevice(self, ctx:blackbirdParser.DeviceContext):
        pass


    # Enter a parse tree produced by blackbirdParser#program.
    def enterProgram(self, ctx:blackbirdParser.ProgramContext):
        pass

    # Exit a parse tree produced by blackbirdParser#program.
    def exitProgram(self, ctx:blackbirdParser.ProgramContext):
        pass


    # Enter a parse tree produced by blackbirdParser#expressionvar.
    def enterExpressionvar(self, ctx:blackbirdParser.ExpressionvarContext):
        pass

    # Exit a parse tree produced by blackbirdParser#expressionvar.
    def exitExpressionvar(self, ctx:blackbirdParser.ExpressionvarContext):
        pass


    # Enter a parse tree produced by blackbirdParser#arrayvar.
    def enterArrayvar(self, ctx:blackbirdParser.ArrayvarContext):
        pass

    # Exit a parse tree produced by blackbirdParser#arrayvar.
    def exitArrayvar(self, ctx:blackbirdParser.ArrayvarContext):
        pass


    # Enter a parse tree produced by blackbirdParser#name.
    def enterName(self, ctx:blackbirdParser.NameContext):
        pass

    # Exit a parse tree produced by blackbirdParser#name.
    def exitName(self, ctx:blackbirdParser.NameContext):
        pass


    # Enter a parse tree produced by blackbirdParser#invalid.
    def enterInvalid(self, ctx:blackbirdParser.InvalidContext):
        pass

    # Exit a parse tree produced by blackbirdParser#invalid.
    def exitInvalid(self, ctx:blackbirdParser.InvalidContext):
        pass


    # Enter a parse tree produced by blackbirdParser#reserved.
    def enterReserved(self, ctx:blackbirdParser.ReservedContext):
        pass

    # Exit a parse tree produced by blackbirdParser#reserved.
    def exitReserved(self, ctx:blackbirdParser.ReservedContext):
        pass


    # Enter a parse tree produced by blackbirdParser#vartype.
    def enterVartype(self, ctx:blackbirdParser.VartypeContext):
        pass

    # Exit a parse tree produced by blackbirdParser#vartype.
    def exitVartype(self, ctx:blackbirdParser.VartypeContext):
        pass


    # Enter a parse tree produced by blackbirdParser#nonnumeric.
    def enterNonnumeric(self, ctx:blackbirdParser.NonnumericContext):
        pass

    # Exit a parse tree produced by blackbirdParser#nonnumeric.
    def exitNonnumeric(self, ctx:blackbirdParser.NonnumericContext):
        pass


    # Enter a parse tree produced by blackbirdParser#shape.
    def enterShape(self, ctx:blackbirdParser.ShapeContext):
        pass

    # Exit a parse tree produced by blackbirdParser#shape.
    def exitShape(self, ctx:blackbirdParser.ShapeContext):
        pass


    # Enter a parse tree produced by blackbirdParser#arrayval.
    def enterArrayval(self, ctx:blackbirdParser.ArrayvalContext):
        pass

    # Exit a parse tree produced by blackbirdParser#arrayval.
    def exitArrayval(self, ctx:blackbirdParser.ArrayvalContext):
        pass


    # Enter a parse tree produced by blackbirdParser#arrayrow.
    def enterArrayrow(self, ctx:blackbirdParser.ArrayrowContext):
        pass

    # Exit a parse tree produced by blackbirdParser#arrayrow.
    def exitArrayrow(self, ctx:blackbirdParser.ArrayrowContext):
        pass


    # Enter a parse tree produced by blackbirdParser#statement.
    def enterStatement(self, ctx:blackbirdParser.StatementContext):
        pass

    # Exit a parse tree produced by blackbirdParser#statement.
    def exitStatement(self, ctx:blackbirdParser.StatementContext):
        pass


    # Enter a parse tree produced by blackbirdParser#operation.
    def enterOperation(self, ctx:blackbirdParser.OperationContext):
        pass

    # Exit a parse tree produced by blackbirdParser#operation.
    def exitOperation(self, ctx:blackbirdParser.OperationContext):
        pass


    # Enter a parse tree produced by blackbirdParser#measure.
    def enterMeasure(self, ctx:blackbirdParser.MeasureContext):
        pass

    # Exit a parse tree produced by blackbirdParser#measure.
    def exitMeasure(self, ctx:blackbirdParser.MeasureContext):
        pass


    # Enter a parse tree produced by blackbirdParser#arguments.
    def enterArguments(self, ctx:blackbirdParser.ArgumentsContext):
        pass

    # Exit a parse tree produced by blackbirdParser#arguments.
    def exitArguments(self, ctx:blackbirdParser.ArgumentsContext):
        pass


    # Enter a parse tree produced by blackbirdParser#kwarg.
    def enterKwarg(self, ctx:blackbirdParser.KwargContext):
        pass

    # Exit a parse tree produced by blackbirdParser#kwarg.
    def exitKwarg(self, ctx:blackbirdParser.KwargContext):
        pass


    # Enter a parse tree produced by blackbirdParser#val.
    def enterVal(self, ctx:blackbirdParser.ValContext):
        pass

    # Exit a parse tree produced by blackbirdParser#val.
    def exitVal(self, ctx:blackbirdParser.ValContext):
        pass


    # Enter a parse tree produced by blackbirdParser#modes.
    def enterModes(self, ctx:blackbirdParser.ModesContext):
        pass

    # Exit a parse tree produced by blackbirdParser#modes.
    def exitModes(self, ctx:blackbirdParser.ModesContext):
        pass


    # Enter a parse tree produced by blackbirdParser#FunctionLabel.
    def enterFunctionLabel(self, ctx:blackbirdParser.FunctionLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#FunctionLabel.
    def exitFunctionLabel(self, ctx:blackbirdParser.FunctionLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#MulLabel.
    def enterMulLabel(self, ctx:blackbirdParser.MulLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#MulLabel.
    def exitMulLabel(self, ctx:blackbirdParser.MulLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#BracketsLabel.
    def enterBracketsLabel(self, ctx:blackbirdParser.BracketsLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#BracketsLabel.
    def exitBracketsLabel(self, ctx:blackbirdParser.BracketsLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#PowerLabel.
    def enterPowerLabel(self, ctx:blackbirdParser.PowerLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#PowerLabel.
    def exitPowerLabel(self, ctx:blackbirdParser.PowerLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#NumberLabel.
    def enterNumberLabel(self, ctx:blackbirdParser.NumberLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#NumberLabel.
    def exitNumberLabel(self, ctx:blackbirdParser.NumberLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#AddLabel.
    def enterAddLabel(self, ctx:blackbirdParser.AddLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#AddLabel.
    def exitAddLabel(self, ctx:blackbirdParser.AddLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#VariableLabel.
    def enterVariableLabel(self, ctx:blackbirdParser.VariableLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#VariableLabel.
    def exitVariableLabel(self, ctx:blackbirdParser.VariableLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#SignLabel.
    def enterSignLabel(self, ctx:blackbirdParser.SignLabelContext):
        pass

    # Exit a parse tree produced by blackbirdParser#SignLabel.
    def exitSignLabel(self, ctx:blackbirdParser.SignLabelContext):
        pass


    # Enter a parse tree produced by blackbirdParser#number.
    def enterNumber(self, ctx:blackbirdParser.NumberContext):
        pass

    # Exit a parse tree produced by blackbirdParser#number.
    def exitNumber(self, ctx:blackbirdParser.NumberContext):
        pass


    # Enter a parse tree produced by blackbirdParser#function.
    def enterFunction(self, ctx:blackbirdParser.FunctionContext):
        pass

    # Exit a parse tree produced by blackbirdParser#function.
    def exitFunction(self, ctx:blackbirdParser.FunctionContext):
        pass


