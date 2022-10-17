
// Generated from blackbird.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  blackbirdParser : public antlr4::Parser {
public:
  enum {
    PLUS = 1, MINUS = 2, TIMES = 3, DIVIDE = 4, PWR = 5, ASSIGN = 6, FOR = 7, 
    IN = 8, INT = 9, FLOAT = 10, COMPLEX = 11, STR = 12, BOOL = 13, SEQUENCE = 14, 
    PI = 15, NEWLINE = 16, TAB = 17, SPACE = 18, PROGNAME = 19, VERSION = 20, 
    TARGET = 21, PROGTYPE = 22, INCLUDE = 23, SQRT = 24, SIN = 25, COS = 26, 
    TAN = 27, ARCSIN = 28, ARCCOS = 29, ARCTAN = 30, SINH = 31, COSH = 32, 
    TANH = 33, ARCSINH = 34, ARCCOSH = 35, ARCTANH = 36, EXP = 37, LOG = 38, 
    PERIOD = 39, COMMA = 40, COLON = 41, QUOTE = 42, LBRAC = 43, RBRAC = 44, 
    LSQBRAC = 45, RSQBRAC = 46, LBRACE = 47, RBRACE = 48, APPLY = 49, TYPE_ARRAY = 50, 
    TYPE_FLOAT = 51, TYPE_COMPLEX = 52, TYPE_INT = 53, TYPE_STR = 54, TYPE_BOOL = 55, 
    REGREF = 56, MEASURE = 57, NAME = 58, DEVICE = 59, COMMENT = 60, ANY = 61
  };

  enum {
    RuleStart = 0, RuleMetadatablock = 1, RuleDeclarename = 2, RuleProgramname = 3, 
    RuleVersion = 4, RuleVersionnumber = 5, RuleTarget = 6, RuleDevice = 7, 
    RuleDeclaretype = 8, RuleProgramtype = 9, RuleInclude = 10, RuleProgram = 11, 
    RuleExpressionvar = 12, RuleArrayvar = 13, RuleName = 14, RuleInvalid = 15, 
    RuleReserved = 16, RuleVartype = 17, RuleNonnumeric = 18, RuleShape = 19, 
    RuleArrayval = 20, RuleArrayrow = 21, RuleStatement = 22, RuleOperation = 23, 
    RuleMeasure = 24, RuleForloop = 25, RuleArguments = 26, RuleKwarg = 27, 
    RuleVal = 28, RuleVallist = 29, RuleRangeval = 30, RuleExpression = 31, 
    RuleParameter = 32, RuleNumber = 33, RuleFunction = 34
  };

  explicit blackbirdParser(antlr4::TokenStream *input);
  ~blackbirdParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class MetadatablockContext;
  class DeclarenameContext;
  class ProgramnameContext;
  class VersionContext;
  class VersionnumberContext;
  class TargetContext;
  class DeviceContext;
  class DeclaretypeContext;
  class ProgramtypeContext;
  class IncludeContext;
  class ProgramContext;
  class ExpressionvarContext;
  class ArrayvarContext;
  class NameContext;
  class InvalidContext;
  class ReservedContext;
  class VartypeContext;
  class NonnumericContext;
  class ShapeContext;
  class ArrayvalContext;
  class ArrayrowContext;
  class StatementContext;
  class OperationContext;
  class MeasureContext;
  class ForloopContext;
  class ArgumentsContext;
  class KwargContext;
  class ValContext;
  class VallistContext;
  class RangevalContext;
  class ExpressionContext;
  class ParameterContext;
  class NumberContext;
  class FunctionContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadatablockContext *metadatablock();
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  MetadatablockContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::IncludeContext *includeContext = nullptr;
    std::vector<IncludeContext *> include_list;
    MetadatablockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarenameContext *declarename();
    VersionContext *version();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    TargetContext *target();
    DeclaretypeContext *declaretype();
    std::vector<IncludeContext *> include();
    IncludeContext* include(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadatablockContext* metadatablock();

  class  DeclarenameContext : public antlr4::ParserRuleContext {
  public:
    DeclarenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGNAME();
    ProgramnameContext *programname();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarenameContext* declarename();

  class  ProgramnameContext : public antlr4::ParserRuleContext {
  public:
    ProgramnameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramnameContext* programname();

  class  VersionContext : public antlr4::ParserRuleContext {
  public:
    VersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();
    VersionnumberContext *versionnumber();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionContext* version();

  class  VersionnumberContext : public antlr4::ParserRuleContext {
  public:
    VersionnumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionnumberContext* versionnumber();

  class  TargetContext : public antlr4::ParserRuleContext {
  public:
    TargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TARGET();
    DeviceContext *device();
    ArgumentsContext *arguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TargetContext* target();

  class  DeviceContext : public antlr4::ParserRuleContext {
  public:
    DeviceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *DEVICE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeviceContext* device();

  class  DeclaretypeContext : public antlr4::ParserRuleContext {
  public:
    DeclaretypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGTYPE();
    ProgramtypeContext *programtype();
    ArgumentsContext *arguments();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclaretypeContext* declaretype();

  class  ProgramtypeContext : public antlr4::ParserRuleContext {
  public:
    ProgramtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramtypeContext* programtype();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *STR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ForloopContext *forloopContext = nullptr;
    std::vector<ForloopContext *> for_list;
    blackbirdParser::ExpressionvarContext *expressionvarContext = nullptr;
    std::vector<ExpressionvarContext *> var_list;
    blackbirdParser::ArrayvarContext *arrayvarContext = nullptr;
    std::vector<ArrayvarContext *> array_list;
    blackbirdParser::StatementContext *statementContext = nullptr;
    std::vector<StatementContext *> statement_list;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ForloopContext *> forloop();
    ForloopContext* forloop(size_t i);
    std::vector<ExpressionvarContext *> expressionvar();
    ExpressionvarContext* expressionvar(size_t i);
    std::vector<ArrayvarContext *> arrayvar();
    ArrayvarContext* arrayvar(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ExpressionvarContext : public antlr4::ParserRuleContext {
  public:
    ExpressionvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    NonnumericContext *nonnumeric();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionvarContext* expressionvar();

  class  ArrayvarContext : public antlr4::ParserRuleContext {
  public:
    ArrayvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *TYPE_ARRAY();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *NEWLINE();
    ArrayvalContext *arrayval();
    ParameterContext *parameter();
    antlr4::tree::TerminalNode *LSQBRAC();
    ShapeContext *shape();
    antlr4::tree::TerminalNode *RSQBRAC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayvarContext* arrayvar();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InvalidContext *invalid();
    antlr4::tree::TerminalNode *NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  InvalidContext : public antlr4::ParserRuleContext {
  public:
    InvalidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REGREF();
    ReservedContext *reserved();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvalidContext* invalid();

  class  ReservedContext : public antlr4::ParserRuleContext {
  public:
    ReservedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGNAME();
    antlr4::tree::TerminalNode *VERSION();
    antlr4::tree::TerminalNode *TARGET();
    antlr4::tree::TerminalNode *PROGTYPE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReservedContext* reserved();

  class  VartypeContext : public antlr4::ParserRuleContext {
  public:
    VartypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_ARRAY();
    antlr4::tree::TerminalNode *TYPE_FLOAT();
    antlr4::tree::TerminalNode *TYPE_COMPLEX();
    antlr4::tree::TerminalNode *TYPE_INT();
    antlr4::tree::TerminalNode *TYPE_STR();
    antlr4::tree::TerminalNode *TYPE_BOOL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VartypeContext* vartype();

  class  NonnumericContext : public antlr4::ParserRuleContext {
  public:
    NonnumericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STR();
    antlr4::tree::TerminalNode *BOOL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonnumericContext* nonnumeric();

  class  ShapeContext : public antlr4::ParserRuleContext {
  public:
    ShapeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShapeContext* shape();

  class  ArrayvalContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ArrayrowContext *arrayrowContext = nullptr;
    std::vector<ArrayrowContext *> row_list;
    ArrayvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ArrayrowContext *> arrayrow();
    ArrayrowContext* arrayrow(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayvalContext* arrayval();

  class  ArrayrowContext : public antlr4::ParserRuleContext {
  public:
    ArrayrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayrowContext* arrayrow();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *APPLY();
    ArrayrowContext *arrayrow();
    OperationContext *operation();
    MeasureContext *measure();
    ArgumentsContext *arguments();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *LBRAC();
    antlr4::tree::TerminalNode *LSQBRAC();
    antlr4::tree::TerminalNode *RBRAC();
    antlr4::tree::TerminalNode *RSQBRAC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationContext* operation();

  class  MeasureContext : public antlr4::ParserRuleContext {
  public:
    MeasureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeasureContext* measure();

  class  ForloopContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::StatementContext *statementContext = nullptr;
    std::vector<StatementContext *> statement_list;
    ForloopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *IN();
    RangevalContext *rangeval();
    VallistContext *vallist();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *LBRAC();
    antlr4::tree::TerminalNode *LSQBRAC();
    antlr4::tree::TerminalNode *RBRAC();
    antlr4::tree::TerminalNode *RSQBRAC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForloopContext* forloop();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ValContext *valContext = nullptr;
    std::vector<ValContext *> val_list;
    blackbirdParser::KwargContext *kwargContext = nullptr;
    std::vector<KwargContext *> kwarg_list;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRAC();
    antlr4::tree::TerminalNode *RBRAC();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    std::vector<KwargContext *> kwarg();
    KwargContext* kwarg(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  KwargContext : public antlr4::ParserRuleContext {
  public:
    KwargContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ASSIGN();
    ValContext *val();
    antlr4::tree::TerminalNode *LSQBRAC();
    antlr4::tree::TerminalNode *RSQBRAC();
    VallistContext *vallist();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KwargContext* kwarg();

  class  ValContext : public antlr4::ParserRuleContext {
  public:
    ValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonnumericContext *nonnumeric();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValContext* val();

  class  VallistContext : public antlr4::ParserRuleContext {
  public:
    VallistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VallistContext* vallist();

  class  RangevalContext : public antlr4::ParserRuleContext {
  public:
    RangevalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangevalContext* rangeval();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParameterLabelContext : public ExpressionContext {
  public:
    ParameterLabelContext(ExpressionContext *ctx);

    ParameterContext *parameter();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BracketsLabelContext : public ExpressionContext {
  public:
    BracketsLabelContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LBRAC();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRAC();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SignLabelContext : public ExpressionContext {
  public:
    SignLabelContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PowerLabelContext : public ExpressionContext {
  public:
    PowerLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PWR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberLabelContext : public ExpressionContext {
  public:
    NumberLabelContext(ExpressionContext *ctx);

    NumberContext *number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableLabelContext : public ExpressionContext {
  public:
    VariableLabelContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *REGREF();
    antlr4::tree::TerminalNode *NAME();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayIdxLabelContext : public ExpressionContext {
  public:
    ArrayIdxLabelContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *LSQBRAC();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RSQBRAC();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulLabelContext : public ExpressionContext {
  public:
    MulLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIVIDE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionLabelContext : public ExpressionContext {
  public:
    FunctionLabelContext(ExpressionContext *ctx);

    FunctionContext *function();
    antlr4::tree::TerminalNode *LBRAC();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRAC();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddLabelContext : public ExpressionContext {
  public:
    AddLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *RBRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *COMPLEX();
    antlr4::tree::TerminalNode *PI();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIN();
    antlr4::tree::TerminalNode *COS();
    antlr4::tree::TerminalNode *TAN();
    antlr4::tree::TerminalNode *ARCSIN();
    antlr4::tree::TerminalNode *ARCCOS();
    antlr4::tree::TerminalNode *ARCTAN();
    antlr4::tree::TerminalNode *SINH();
    antlr4::tree::TerminalNode *COSH();
    antlr4::tree::TerminalNode *TANH();
    antlr4::tree::TerminalNode *ARCSINH();
    antlr4::tree::TerminalNode *ARCCOSH();
    antlr4::tree::TerminalNode *ARCTANH();
    antlr4::tree::TerminalNode *SQRT();
    antlr4::tree::TerminalNode *LOG();
    antlr4::tree::TerminalNode *EXP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

