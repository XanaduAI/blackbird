
// Generated from blackbird.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "blackbirdVisitor.h"


/**
 * This class provides an empty implementation of blackbirdVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  blackbirdBaseVisitor : public blackbirdVisitor {
public:

  virtual std::any visitStart(blackbirdParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadatablock(blackbirdParser::MetadatablockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarename(blackbirdParser::DeclarenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramname(blackbirdParser::ProgramnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion(blackbirdParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersionnumber(blackbirdParser::VersionnumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTarget(blackbirdParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDevice(blackbirdParser::DeviceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaretype(blackbirdParser::DeclaretypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramtype(blackbirdParser::ProgramtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(blackbirdParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(blackbirdParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayvar(blackbirdParser::ArrayvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitName(blackbirdParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvalid(blackbirdParser::InvalidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReserved(blackbirdParser::ReservedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVartype(blackbirdParser::VartypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonnumeric(blackbirdParser::NonnumericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShape(blackbirdParser::ShapeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayval(blackbirdParser::ArrayvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayrow(blackbirdParser::ArrayrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(blackbirdParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation(blackbirdParser::OperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeasure(blackbirdParser::MeasureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForloop(blackbirdParser::ForloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(blackbirdParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKwarg(blackbirdParser::KwargContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVal(blackbirdParser::ValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVallist(blackbirdParser::VallistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangeval(blackbirdParser::RangevalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterLabel(blackbirdParser::ParameterLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBracketsLabel(blackbirdParser::BracketsLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignLabel(blackbirdParser::SignLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowerLabel(blackbirdParser::PowerLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberLabel(blackbirdParser::NumberLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableLabel(blackbirdParser::VariableLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayIdxLabel(blackbirdParser::ArrayIdxLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulLabel(blackbirdParser::MulLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionLabel(blackbirdParser::FunctionLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddLabel(blackbirdParser::AddLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(blackbirdParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(blackbirdParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(blackbirdParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }


};

