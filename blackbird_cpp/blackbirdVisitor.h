
// Generated from blackbird.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "blackbirdParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by blackbirdParser.
 */
class  blackbirdVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by blackbirdParser.
   */
    virtual std::any visitStart(blackbirdParser::StartContext *context) = 0;

    virtual std::any visitMetadatablock(blackbirdParser::MetadatablockContext *context) = 0;

    virtual std::any visitDeclarename(blackbirdParser::DeclarenameContext *context) = 0;

    virtual std::any visitProgramname(blackbirdParser::ProgramnameContext *context) = 0;

    virtual std::any visitVersion(blackbirdParser::VersionContext *context) = 0;

    virtual std::any visitVersionnumber(blackbirdParser::VersionnumberContext *context) = 0;

    virtual std::any visitTarget(blackbirdParser::TargetContext *context) = 0;

    virtual std::any visitDevice(blackbirdParser::DeviceContext *context) = 0;

    virtual std::any visitDeclaretype(blackbirdParser::DeclaretypeContext *context) = 0;

    virtual std::any visitProgramtype(blackbirdParser::ProgramtypeContext *context) = 0;

    virtual std::any visitInclude(blackbirdParser::IncludeContext *context) = 0;

    virtual std::any visitProgram(blackbirdParser::ProgramContext *context) = 0;

    virtual std::any visitExpressionvar(blackbirdParser::ExpressionvarContext *context) = 0;

    virtual std::any visitArrayvar(blackbirdParser::ArrayvarContext *context) = 0;

    virtual std::any visitName(blackbirdParser::NameContext *context) = 0;

    virtual std::any visitInvalid(blackbirdParser::InvalidContext *context) = 0;

    virtual std::any visitReserved(blackbirdParser::ReservedContext *context) = 0;

    virtual std::any visitVartype(blackbirdParser::VartypeContext *context) = 0;

    virtual std::any visitNonnumeric(blackbirdParser::NonnumericContext *context) = 0;

    virtual std::any visitShape(blackbirdParser::ShapeContext *context) = 0;

    virtual std::any visitArrayval(blackbirdParser::ArrayvalContext *context) = 0;

    virtual std::any visitArrayrow(blackbirdParser::ArrayrowContext *context) = 0;

    virtual std::any visitStatement(blackbirdParser::StatementContext *context) = 0;

    virtual std::any visitOperation(blackbirdParser::OperationContext *context) = 0;

    virtual std::any visitMeasure(blackbirdParser::MeasureContext *context) = 0;

    virtual std::any visitForloop(blackbirdParser::ForloopContext *context) = 0;

    virtual std::any visitArguments(blackbirdParser::ArgumentsContext *context) = 0;

    virtual std::any visitKwarg(blackbirdParser::KwargContext *context) = 0;

    virtual std::any visitVal(blackbirdParser::ValContext *context) = 0;

    virtual std::any visitVallist(blackbirdParser::VallistContext *context) = 0;

    virtual std::any visitRangeval(blackbirdParser::RangevalContext *context) = 0;

    virtual std::any visitParameterLabel(blackbirdParser::ParameterLabelContext *context) = 0;

    virtual std::any visitBracketsLabel(blackbirdParser::BracketsLabelContext *context) = 0;

    virtual std::any visitSignLabel(blackbirdParser::SignLabelContext *context) = 0;

    virtual std::any visitPowerLabel(blackbirdParser::PowerLabelContext *context) = 0;

    virtual std::any visitNumberLabel(blackbirdParser::NumberLabelContext *context) = 0;

    virtual std::any visitVariableLabel(blackbirdParser::VariableLabelContext *context) = 0;

    virtual std::any visitArrayIdxLabel(blackbirdParser::ArrayIdxLabelContext *context) = 0;

    virtual std::any visitMulLabel(blackbirdParser::MulLabelContext *context) = 0;

    virtual std::any visitFunctionLabel(blackbirdParser::FunctionLabelContext *context) = 0;

    virtual std::any visitAddLabel(blackbirdParser::AddLabelContext *context) = 0;

    virtual std::any visitParameter(blackbirdParser::ParameterContext *context) = 0;

    virtual std::any visitNumber(blackbirdParser::NumberContext *context) = 0;

    virtual std::any visitFunction(blackbirdParser::FunctionContext *context) = 0;


};

