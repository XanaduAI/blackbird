
// Generated from blackbird.g4 by ANTLR 4.7.1

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

    virtual antlrcpp::Any visitVarblock(blackbirdParser::VarblockContext *context) = 0;

    virtual antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *context) = 0;

    virtual antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *context) = 0;

    virtual antlrcpp::Any visitName(blackbirdParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitVartype(blackbirdParser::VartypeContext *context) = 0;

    virtual antlrcpp::Any visitNonnumeric(blackbirdParser::NonnumericContext *context) = 0;

    virtual antlrcpp::Any visitShape(blackbirdParser::ShapeContext *context) = 0;

    virtual antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *context) = 0;

    virtual antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *context) = 0;

    virtual antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitDevice(blackbirdParser::DeviceContext *context) = 0;

    virtual antlrcpp::Any visitStatement(blackbirdParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitOperation(blackbirdParser::OperationContext *context) = 0;

    virtual antlrcpp::Any visitMeasure(blackbirdParser::MeasureContext *context) = 0;

    virtual antlrcpp::Any visitArguments(blackbirdParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitKwarg(blackbirdParser::KwargContext *context) = 0;

    virtual antlrcpp::Any visitVal(blackbirdParser::ValContext *context) = 0;

    virtual antlrcpp::Any visitModes(blackbirdParser::ModesContext *context) = 0;

    virtual antlrcpp::Any visitBracketsLabel(blackbirdParser::BracketsLabelContext *context) = 0;

    virtual antlrcpp::Any visitSignLabel(blackbirdParser::SignLabelContext *context) = 0;

    virtual antlrcpp::Any visitPowerLabel(blackbirdParser::PowerLabelContext *context) = 0;

    virtual antlrcpp::Any visitNumberLabel(blackbirdParser::NumberLabelContext *context) = 0;

    virtual antlrcpp::Any visitVariableLabel(blackbirdParser::VariableLabelContext *context) = 0;

    virtual antlrcpp::Any visitMulLabel(blackbirdParser::MulLabelContext *context) = 0;

    virtual antlrcpp::Any visitFunctionLabel(blackbirdParser::FunctionLabelContext *context) = 0;

    virtual antlrcpp::Any visitAddLabel(blackbirdParser::AddLabelContext *context) = 0;

    virtual antlrcpp::Any visitNumber(blackbirdParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitFunction(blackbirdParser::FunctionContext *context) = 0;


};

