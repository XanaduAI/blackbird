
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "blackbirdListener.h"


/**
 * This class provides an empty implementation of blackbirdListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  blackbirdBaseListener : public blackbirdListener {
public:

  virtual void enterStart(blackbirdParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(blackbirdParser::StartContext * /*ctx*/) override { }

  virtual void enterExpressionVariableLabel(blackbirdParser::ExpressionVariableLabelContext * /*ctx*/) override { }
  virtual void exitExpressionVariableLabel(blackbirdParser::ExpressionVariableLabelContext * /*ctx*/) override { }

  virtual void enterArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext * /*ctx*/) override { }
  virtual void exitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext * /*ctx*/) override { }

  virtual void enterName(blackbirdParser::NameContext * /*ctx*/) override { }
  virtual void exitName(blackbirdParser::NameContext * /*ctx*/) override { }

  virtual void enterVartype(blackbirdParser::VartypeContext * /*ctx*/) override { }
  virtual void exitVartype(blackbirdParser::VartypeContext * /*ctx*/) override { }

  virtual void enterNonnumeric(blackbirdParser::NonnumericContext * /*ctx*/) override { }
  virtual void exitNonnumeric(blackbirdParser::NonnumericContext * /*ctx*/) override { }

  virtual void enterShape(blackbirdParser::ShapeContext * /*ctx*/) override { }
  virtual void exitShape(blackbirdParser::ShapeContext * /*ctx*/) override { }

  virtual void enterArrayval(blackbirdParser::ArrayvalContext * /*ctx*/) override { }
  virtual void exitArrayval(blackbirdParser::ArrayvalContext * /*ctx*/) override { }

  virtual void enterArrayrow(blackbirdParser::ArrayrowContext * /*ctx*/) override { }
  virtual void exitArrayrow(blackbirdParser::ArrayrowContext * /*ctx*/) override { }

  virtual void enterProgram(blackbirdParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(blackbirdParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDevice(blackbirdParser::DeviceContext * /*ctx*/) override { }
  virtual void exitDevice(blackbirdParser::DeviceContext * /*ctx*/) override { }

  virtual void enterStatement(blackbirdParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(blackbirdParser::StatementContext * /*ctx*/) override { }

  virtual void enterOperation(blackbirdParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(blackbirdParser::OperationContext * /*ctx*/) override { }

  virtual void enterMeasure(blackbirdParser::MeasureContext * /*ctx*/) override { }
  virtual void exitMeasure(blackbirdParser::MeasureContext * /*ctx*/) override { }

  virtual void enterArguments(blackbirdParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(blackbirdParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterKwarg(blackbirdParser::KwargContext * /*ctx*/) override { }
  virtual void exitKwarg(blackbirdParser::KwargContext * /*ctx*/) override { }

  virtual void enterVal(blackbirdParser::ValContext * /*ctx*/) override { }
  virtual void exitVal(blackbirdParser::ValContext * /*ctx*/) override { }

  virtual void enterModes(blackbirdParser::ModesContext * /*ctx*/) override { }
  virtual void exitModes(blackbirdParser::ModesContext * /*ctx*/) override { }

  virtual void enterBracketsLabel(blackbirdParser::BracketsLabelContext * /*ctx*/) override { }
  virtual void exitBracketsLabel(blackbirdParser::BracketsLabelContext * /*ctx*/) override { }

  virtual void enterSignLabel(blackbirdParser::SignLabelContext * /*ctx*/) override { }
  virtual void exitSignLabel(blackbirdParser::SignLabelContext * /*ctx*/) override { }

  virtual void enterPowerLabel(blackbirdParser::PowerLabelContext * /*ctx*/) override { }
  virtual void exitPowerLabel(blackbirdParser::PowerLabelContext * /*ctx*/) override { }

  virtual void enterNumberLabel(blackbirdParser::NumberLabelContext * /*ctx*/) override { }
  virtual void exitNumberLabel(blackbirdParser::NumberLabelContext * /*ctx*/) override { }

  virtual void enterVariableLabel(blackbirdParser::VariableLabelContext * /*ctx*/) override { }
  virtual void exitVariableLabel(blackbirdParser::VariableLabelContext * /*ctx*/) override { }

  virtual void enterMulLabel(blackbirdParser::MulLabelContext * /*ctx*/) override { }
  virtual void exitMulLabel(blackbirdParser::MulLabelContext * /*ctx*/) override { }

  virtual void enterFunctionLabel(blackbirdParser::FunctionLabelContext * /*ctx*/) override { }
  virtual void exitFunctionLabel(blackbirdParser::FunctionLabelContext * /*ctx*/) override { }

  virtual void enterAddLabel(blackbirdParser::AddLabelContext * /*ctx*/) override { }
  virtual void exitAddLabel(blackbirdParser::AddLabelContext * /*ctx*/) override { }

  virtual void enterNumber(blackbirdParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(blackbirdParser::NumberContext * /*ctx*/) override { }

  virtual void enterFunction(blackbirdParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(blackbirdParser::FunctionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

