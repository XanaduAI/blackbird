
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "blackbirdVisitor.h"


/**
 * This class provides an empty implementation of blackbirdVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  blackbirdBaseVisitor : public blackbirdVisitor {
public:

  virtual antlrcpp::Any visitStart(blackbirdParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarblock(blackbirdParser::VarblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(blackbirdParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVartype(blackbirdParser::VartypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonnumeric(blackbirdParser::NonnumericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShape(blackbirdParser::ShapeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDevice(blackbirdParser::DeviceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(blackbirdParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperation(blackbirdParser::OperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMeasure(blackbirdParser::MeasureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(blackbirdParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKwarg(blackbirdParser::KwargContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVal(blackbirdParser::ValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModes(blackbirdParser::ModesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracketsLabel(blackbirdParser::BracketsLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignLabel(blackbirdParser::SignLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerLabel(blackbirdParser::PowerLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberLabel(blackbirdParser::NumberLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableLabel(blackbirdParser::VariableLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulLabel(blackbirdParser::MulLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionLabel(blackbirdParser::FunctionLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddLabel(blackbirdParser::AddLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(blackbirdParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }


};

