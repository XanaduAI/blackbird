
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  blackbirdParser : public antlr4::Parser {
public:
  enum {
    PLUS = 1, MINUS = 2, TIMES = 3, DIVIDE = 4, PWR = 5, ASSIGN = 6, INT = 7, 
    FLOAT = 8, COMPLEX = 9, STR = 10, BOOL = 11, SEQUENCE = 12, PI = 13, 
    NEWLINE = 14, TAB = 15, SPACE = 16, WITH = 17, SQRT = 18, SIN = 19, 
    COS = 20, EXP = 21, PERIOD = 22, COMMA = 23, COLON = 24, QUOTE = 25, 
    LBRAC = 26, RBRAC = 27, LSQBRAC = 28, RSQBRAC = 29, APPLY = 30, TYPE_ARRAY = 31, 
    TYPE_FLOAT = 32, TYPE_COMPLEX = 33, TYPE_INT = 34, TYPE_STR = 35, TYPE_BOOL = 36, 
    MEASURE = 37, NAME = 38, DEVICE = 39, COMMENT = 40, ANY = 41
  };

  enum {
    RuleStart = 0, RuleVarblock = 1, RuleExpressionvar = 2, RuleArrayvar = 3, 
    RuleName = 4, RuleVartype = 5, RuleNonnumeric = 6, RuleShape = 7, RuleArrayval = 8, 
    RuleArrayrow = 9, RuleProgram = 10, RuleDevice = 11, RuleStatement = 12, 
    RuleOperation = 13, RuleMeasure = 14, RuleArguments = 15, RuleKwarg = 16, 
    RuleVal = 17, RuleModes = 18, RuleExpression = 19, RuleNumber = 20, 
    RuleFunction = 21
  };

  blackbirdParser(antlr4::TokenStream *input);
  ~blackbirdParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class VarblockContext;
  class ExpressionvarContext;
  class ArrayvarContext;
  class NameContext;
  class VartypeContext;
  class NonnumericContext;
  class ShapeContext;
  class ArrayvalContext;
  class ArrayrowContext;
  class ProgramContext;
  class DeviceContext;
  class StatementContext;
  class OperationContext;
  class MeasureContext;
  class ArgumentsContext;
  class KwargContext;
  class ValContext;
  class ModesContext;
  class ExpressionContext;
  class NumberContext;
  class FunctionContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarblockContext *varblock();
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  VarblockContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ExpressionvarContext *expressionvarContext = nullptr;;
    std::vector<ExpressionvarContext *> var_list;;
    blackbirdParser::ArrayvarContext *arrayvarContext = nullptr;;
    std::vector<ArrayvarContext *> array_list;;
    VarblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ExpressionvarContext *> expressionvar();
    ExpressionvarContext* expressionvar(size_t i);
    std::vector<ArrayvarContext *> arrayvar();
    ArrayvarContext* arrayvar(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarblockContext* varblock();

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
    antlr4::tree::TerminalNode *NAME();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

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
    blackbirdParser::ArrayrowContext *arrayrowContext = nullptr;;
    std::vector<ArrayrowContext *> row_list;;
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

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::StatementContext *statementContext = nullptr;;
    std::vector<StatementContext *> statement_list;;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    DeviceContext *device();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    ArgumentsContext *arguments();
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeviceContext : public antlr4::ParserRuleContext {
  public:
    DeviceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *DEVICE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeviceContext* device();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAB();
    antlr4::tree::TerminalNode *APPLY();
    ModesContext *modes();
    antlr4::tree::TerminalNode *NEWLINE();
    OperationContext *operation();
    MeasureContext *measure();
    ArgumentsContext *arguments();
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

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ValContext *valContext = nullptr;;
    std::vector<ValContext *> val_list;;
    blackbirdParser::KwargContext *kwargContext = nullptr;;
    std::vector<KwargContext *> kwarg_list;;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRAC();
    antlr4::tree::TerminalNode *RBRAC();
    std::vector<ValContext *> val();
    ValContext* val(size_t i);
    std::vector<KwargContext *> kwarg();
    KwargContext* kwarg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

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

  class  ModesContext : public antlr4::ParserRuleContext {
  public:
    ModesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModesContext* modes();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
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

    antlr4::tree::TerminalNode *NAME();
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
    antlr4::tree::TerminalNode *SQRT();
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

