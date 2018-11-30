
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "blackbirdParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by blackbirdParser.
 */
class  blackbirdListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(blackbirdParser::StartContext *ctx) = 0;
  virtual void exitStart(blackbirdParser::StartContext *ctx) = 0;

  virtual void enterVarblock(blackbirdParser::VarblockContext *ctx) = 0;
  virtual void exitVarblock(blackbirdParser::VarblockContext *ctx) = 0;

  virtual void enterExpressionvar(blackbirdParser::ExpressionvarContext *ctx) = 0;
  virtual void exitExpressionvar(blackbirdParser::ExpressionvarContext *ctx) = 0;

  virtual void enterArrayvar(blackbirdParser::ArrayvarContext *ctx) = 0;
  virtual void exitArrayvar(blackbirdParser::ArrayvarContext *ctx) = 0;

  virtual void enterName(blackbirdParser::NameContext *ctx) = 0;
  virtual void exitName(blackbirdParser::NameContext *ctx) = 0;

  virtual void enterVartype(blackbirdParser::VartypeContext *ctx) = 0;
  virtual void exitVartype(blackbirdParser::VartypeContext *ctx) = 0;

  virtual void enterNonnumeric(blackbirdParser::NonnumericContext *ctx) = 0;
  virtual void exitNonnumeric(blackbirdParser::NonnumericContext *ctx) = 0;

  virtual void enterShape(blackbirdParser::ShapeContext *ctx) = 0;
  virtual void exitShape(blackbirdParser::ShapeContext *ctx) = 0;

  virtual void enterArrayval(blackbirdParser::ArrayvalContext *ctx) = 0;
  virtual void exitArrayval(blackbirdParser::ArrayvalContext *ctx) = 0;

  virtual void enterArrayrow(blackbirdParser::ArrayrowContext *ctx) = 0;
  virtual void exitArrayrow(blackbirdParser::ArrayrowContext *ctx) = 0;

  virtual void enterProgram(blackbirdParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(blackbirdParser::ProgramContext *ctx) = 0;

  virtual void enterDevice(blackbirdParser::DeviceContext *ctx) = 0;
  virtual void exitDevice(blackbirdParser::DeviceContext *ctx) = 0;

  virtual void enterStatement(blackbirdParser::StatementContext *ctx) = 0;
  virtual void exitStatement(blackbirdParser::StatementContext *ctx) = 0;

  virtual void enterOperation(blackbirdParser::OperationContext *ctx) = 0;
  virtual void exitOperation(blackbirdParser::OperationContext *ctx) = 0;

  virtual void enterMeasure(blackbirdParser::MeasureContext *ctx) = 0;
  virtual void exitMeasure(blackbirdParser::MeasureContext *ctx) = 0;

  virtual void enterArguments(blackbirdParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(blackbirdParser::ArgumentsContext *ctx) = 0;

  virtual void enterKwarg(blackbirdParser::KwargContext *ctx) = 0;
  virtual void exitKwarg(blackbirdParser::KwargContext *ctx) = 0;

  virtual void enterVal(blackbirdParser::ValContext *ctx) = 0;
  virtual void exitVal(blackbirdParser::ValContext *ctx) = 0;

  virtual void enterModes(blackbirdParser::ModesContext *ctx) = 0;
  virtual void exitModes(blackbirdParser::ModesContext *ctx) = 0;

  virtual void enterBracketsLabel(blackbirdParser::BracketsLabelContext *ctx) = 0;
  virtual void exitBracketsLabel(blackbirdParser::BracketsLabelContext *ctx) = 0;

  virtual void enterSignLabel(blackbirdParser::SignLabelContext *ctx) = 0;
  virtual void exitSignLabel(blackbirdParser::SignLabelContext *ctx) = 0;

  virtual void enterPowerLabel(blackbirdParser::PowerLabelContext *ctx) = 0;
  virtual void exitPowerLabel(blackbirdParser::PowerLabelContext *ctx) = 0;

  virtual void enterNumberLabel(blackbirdParser::NumberLabelContext *ctx) = 0;
  virtual void exitNumberLabel(blackbirdParser::NumberLabelContext *ctx) = 0;

  virtual void enterVariableLabel(blackbirdParser::VariableLabelContext *ctx) = 0;
  virtual void exitVariableLabel(blackbirdParser::VariableLabelContext *ctx) = 0;

  virtual void enterMulLabel(blackbirdParser::MulLabelContext *ctx) = 0;
  virtual void exitMulLabel(blackbirdParser::MulLabelContext *ctx) = 0;

  virtual void enterFunctionLabel(blackbirdParser::FunctionLabelContext *ctx) = 0;
  virtual void exitFunctionLabel(blackbirdParser::FunctionLabelContext *ctx) = 0;

  virtual void enterAddLabel(blackbirdParser::AddLabelContext *ctx) = 0;
  virtual void exitAddLabel(blackbirdParser::AddLabelContext *ctx) = 0;

  virtual void enterNumber(blackbirdParser::NumberContext *ctx) = 0;
  virtual void exitNumber(blackbirdParser::NumberContext *ctx) = 0;

  virtual void enterFunction(blackbirdParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(blackbirdParser::FunctionContext *ctx) = 0;


};

