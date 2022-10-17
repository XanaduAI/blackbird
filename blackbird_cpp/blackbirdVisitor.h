
// Generated from blackbird.g4 by ANTLR 4.9.2

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
    virtual antlrcpp::Any visitStart(blackbirdParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitMetadatablock(blackbirdParser::MetadatablockContext *context) = 0;

    virtual antlrcpp::Any visitDeclarename(blackbirdParser::DeclarenameContext *context) = 0;

    virtual antlrcpp::Any visitProgramname(blackbirdParser::ProgramnameContext *context) = 0;

    virtual antlrcpp::Any visitVersion(blackbirdParser::VersionContext *context) = 0;

    virtual antlrcpp::Any visitVersionnumber(blackbirdParser::VersionnumberContext *context) = 0;

    virtual antlrcpp::Any visitTarget(blackbirdParser::TargetContext *context) = 0;

    virtual antlrcpp::Any visitDevice(blackbirdParser::DeviceContext *context) = 0;

    virtual antlrcpp::Any visitDeclaretype(blackbirdParser::DeclaretypeContext *context) = 0;

    virtual antlrcpp::Any visitProgramtype(blackbirdParser::ProgramtypeContext *context) = 0;

    virtual antlrcpp::Any visitInclude(blackbirdParser::IncludeContext *context) = 0;

    virtual antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *context) = 0;

    virtual antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *context) = 0;

    virtual antlrcpp::Any visitName(blackbirdParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitInvalid(blackbirdParser::InvalidContext *context) = 0;

    virtual antlrcpp::Any visitReserved(blackbirdParser::ReservedContext *context) = 0;

    virtual antlrcpp::Any visitVartype(blackbirdParser::VartypeContext *context) = 0;

    virtual antlrcpp::Any visitNonnumeric(blackbirdParser::NonnumericContext *context) = 0;

    virtual antlrcpp::Any visitShape(blackbirdParser::ShapeContext *context) = 0;

    virtual antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *context) = 0;

    virtual antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *context) = 0;

    virtual antlrcpp::Any visitStatement(blackbirdParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitOperation(blackbirdParser::OperationContext *context) = 0;

    virtual antlrcpp::Any visitMeasure(blackbirdParser::MeasureContext *context) = 0;

    virtual antlrcpp::Any visitForloop(blackbirdParser::ForloopContext *context) = 0;

    virtual antlrcpp::Any visitArguments(blackbirdParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitKwarg(blackbirdParser::KwargContext *context) = 0;

    virtual antlrcpp::Any visitVal(blackbirdParser::ValContext *context) = 0;

    virtual antlrcpp::Any visitVallist(blackbirdParser::VallistContext *context) = 0;

    virtual antlrcpp::Any visitRangeval(blackbirdParser::RangevalContext *context) = 0;

    virtual antlrcpp::Any visitParameterLabel(blackbirdParser::ParameterLabelContext *context) = 0;

    virtual antlrcpp::Any visitBracketsLabel(blackbirdParser::BracketsLabelContext *context) = 0;

    virtual antlrcpp::Any visitSignLabel(blackbirdParser::SignLabelContext *context) = 0;

    virtual antlrcpp::Any visitPowerLabel(blackbirdParser::PowerLabelContext *context) = 0;

    virtual antlrcpp::Any visitNumberLabel(blackbirdParser::NumberLabelContext *context) = 0;

    virtual antlrcpp::Any visitVariableLabel(blackbirdParser::VariableLabelContext *context) = 0;

    virtual antlrcpp::Any visitArrayIdxLabel(blackbirdParser::ArrayIdxLabelContext *context) = 0;

    virtual antlrcpp::Any visitMulLabel(blackbirdParser::MulLabelContext *context) = 0;

    virtual antlrcpp::Any visitFunctionLabel(blackbirdParser::FunctionLabelContext *context) = 0;

    virtual antlrcpp::Any visitAddLabel(blackbirdParser::AddLabelContext *context) = 0;

    virtual antlrcpp::Any visitParameter(blackbirdParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitNumber(blackbirdParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitFunction(blackbirdParser::FunctionContext *context) = 0;


};

