
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
    MEASURE = 37, OPERATION = 38, NAME = 39, DEVICE = 40, COMMENT = 41, 
    ANY = 42
  };

  enum {
    RuleStart = 0, RuleVariable = 1, RuleName = 2, RuleVartype = 3, RuleNonnumeric = 4, 
    RuleShape = 5, RuleArrayval = 6, RuleArrayrow = 7, RuleProgram = 8, 
    RuleDevice = 9, RuleStatement = 10, RuleOperation = 11, RuleMeasure = 12, 
    RuleArguments = 13, RuleKwarg = 14, RuleVal = 15, RuleModes = 16, RuleExpression = 17, 
    RuleNumber = 18, RuleFunction = 19
  };

  blackbirdParser(antlr4::TokenStream *input);
  ~blackbirdParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class VariableContext;
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
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariableContext() : antlr4::ParserRuleContext() { }
    void copyFrom(VariableContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpressionVariableLabelContext : public VariableContext {
  public:
    ExpressionVariableLabelContext(VariableContext *ctx);

    VartypeContext *vartype();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    NonnumericContext *nonnumeric();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ArrayVariableLabelContext : public VariableContext {
  public:
    ArrayVariableLabelContext(VariableContext *ctx);

    VartypeContext *vartype();
    antlr4::tree::TerminalNode *TYPE_ARRAY();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *NEWLINE();
    ArrayvalContext *arrayval();
    antlr4::tree::TerminalNode *LSQBRAC();
    ShapeContext *shape();
    antlr4::tree::TerminalNode *RSQBRAC();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  VariableContext* variable();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VartypeContext* vartype();

  class  NonnumericContext : public antlr4::ParserRuleContext {
  public:
    NonnumericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STR();
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ShapeContext* shape();

  class  ArrayvalContext : public antlr4::ParserRuleContext {
  public:
    blackbirdParser::ArrayrowContext *arrayrowContext = nullptr;;
    std::vector<ArrayrowContext *> row;;
    ArrayvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ArrayrowContext *> arrayrow();
    ArrayrowContext* arrayrow(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayrowContext* arrayrow();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    DeviceContext *device();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    ArgumentsContext *arguments();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  DeviceContext : public antlr4::ParserRuleContext {
  public:
    DeviceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *DEVICE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPERATION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OperationContext* operation();

  class  MeasureContext : public antlr4::ParserRuleContext {
  public:
    MeasureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MeasureContext* measure();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();

  class  KwargContext : public antlr4::ParserRuleContext {
  public:
    KwargContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ASSIGN();
    ValContext *val();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  KwargContext* kwarg();

  class  ValContext : public antlr4::ParserRuleContext {
  public:
    ValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonnumericContext *nonnumeric();
    antlr4::tree::TerminalNode *NAME();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SignLabelContext : public ExpressionContext {
  public:
    SignLabelContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PowerLabelContext : public ExpressionContext {
  public:
    PowerLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PWR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumberLabelContext : public ExpressionContext {
  public:
    NumberLabelContext(ExpressionContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VariableLabelContext : public ExpressionContext {
  public:
    VariableLabelContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MulLabelContext : public ExpressionContext {
  public:
    MulLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIVIDE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FunctionLabelContext : public ExpressionContext {
  public:
    FunctionLabelContext(ExpressionContext *ctx);

    FunctionContext *function();
    antlr4::tree::TerminalNode *LBRAC();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRAC();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AddLabelContext : public ExpressionContext {
  public:
    AddLabelContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

