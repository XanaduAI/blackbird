
// Generated from blackbird.g4 by ANTLR 4.7.1


#include "blackbirdVisitor.h"

#include "blackbirdParser.h"


using namespace antlrcpp;
using namespace antlr4;

blackbirdParser::blackbirdParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

blackbirdParser::~blackbirdParser() {
  delete _interpreter;
}

std::string blackbirdParser::getGrammarFileName() const {
  return "blackbird.g4";
}

const std::vector<std::string>& blackbirdParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& blackbirdParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

blackbirdParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::VarblockContext* blackbirdParser::StartContext::varblock() {
  return getRuleContext<blackbirdParser::VarblockContext>(0);
}

blackbirdParser::ProgramContext* blackbirdParser::StartContext::program() {
  return getRuleContext<blackbirdParser::ProgramContext>(0);
}

tree::TerminalNode* blackbirdParser::StartContext::EOF() {
  return getToken(blackbirdParser::EOF, 0);
}

std::vector<tree::TerminalNode *> blackbirdParser::StartContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::StartContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}


size_t blackbirdParser::StartContext::getRuleIndex() const {
  return blackbirdParser::RuleStart;
}

antlrcpp::Any blackbirdParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::StartContext* blackbirdParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, blackbirdParser::RuleStart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    varblock();
    setState(45);
    program();
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(46);
      match(blackbirdParser::NEWLINE);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(blackbirdParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarblockContext ------------------------------------------------------------------

blackbirdParser::VarblockContext::VarblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::VarblockContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::VarblockContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<blackbirdParser::ExpressionvarContext *> blackbirdParser::VarblockContext::expressionvar() {
  return getRuleContexts<blackbirdParser::ExpressionvarContext>();
}

blackbirdParser::ExpressionvarContext* blackbirdParser::VarblockContext::expressionvar(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionvarContext>(i);
}

std::vector<blackbirdParser::ArrayvarContext *> blackbirdParser::VarblockContext::arrayvar() {
  return getRuleContexts<blackbirdParser::ArrayvarContext>();
}

blackbirdParser::ArrayvarContext* blackbirdParser::VarblockContext::arrayvar(size_t i) {
  return getRuleContext<blackbirdParser::ArrayvarContext>(i);
}


size_t blackbirdParser::VarblockContext::getRuleIndex() const {
  return blackbirdParser::RuleVarblock;
}

antlrcpp::Any blackbirdParser::VarblockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVarblock(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VarblockContext* blackbirdParser::varblock() {
  VarblockContext *_localctx = _tracker.createInstance<VarblockContext>(_ctx, getState());
  enterRule(_localctx, 2, blackbirdParser::RuleVarblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::NEWLINE)
      | (1ULL << blackbirdParser::TYPE_ARRAY)
      | (1ULL << blackbirdParser::TYPE_FLOAT)
      | (1ULL << blackbirdParser::TYPE_COMPLEX)
      | (1ULL << blackbirdParser::TYPE_INT)
      | (1ULL << blackbirdParser::TYPE_STR)
      | (1ULL << blackbirdParser::TYPE_BOOL))) != 0)) {
      setState(57);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(54);
        match(blackbirdParser::NEWLINE);
        break;
      }

      case 2: {
        setState(55);
        dynamic_cast<VarblockContext *>(_localctx)->expressionvarContext = expressionvar();
        dynamic_cast<VarblockContext *>(_localctx)->var_list.push_back(dynamic_cast<VarblockContext *>(_localctx)->expressionvarContext);
        break;
      }

      case 3: {
        setState(56);
        dynamic_cast<VarblockContext *>(_localctx)->arrayvarContext = arrayvar();
        dynamic_cast<VarblockContext *>(_localctx)->array_list.push_back(dynamic_cast<VarblockContext *>(_localctx)->arrayvarContext);
        break;
      }

      }
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionvarContext ------------------------------------------------------------------

blackbirdParser::ExpressionvarContext::ExpressionvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::VartypeContext* blackbirdParser::ExpressionvarContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

blackbirdParser::NameContext* blackbirdParser::ExpressionvarContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ExpressionvarContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ExpressionvarContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

blackbirdParser::NonnumericContext* blackbirdParser::ExpressionvarContext::nonnumeric() {
  return getRuleContext<blackbirdParser::NonnumericContext>(0);
}


size_t blackbirdParser::ExpressionvarContext::getRuleIndex() const {
  return blackbirdParser::RuleExpressionvar;
}

antlrcpp::Any blackbirdParser::ExpressionvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitExpressionvar(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ExpressionvarContext* blackbirdParser::expressionvar() {
  ExpressionvarContext *_localctx = _tracker.createInstance<ExpressionvarContext>(_ctx, getState());
  enterRule(_localctx, 4, blackbirdParser::RuleExpressionvar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    vartype();
    setState(63);
    name();
    setState(64);
    match(blackbirdParser::ASSIGN);
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::EXP:
      case blackbirdParser::LBRAC:
      case blackbirdParser::NAME: {
        setState(65);
        expression(0);
        break;
      }

      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(66);
        nonnumeric();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayvarContext ------------------------------------------------------------------

blackbirdParser::ArrayvarContext::ArrayvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::VartypeContext* blackbirdParser::ArrayvarContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::TYPE_ARRAY() {
  return getToken(blackbirdParser::TYPE_ARRAY, 0);
}

blackbirdParser::NameContext* blackbirdParser::ArrayvarContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::NEWLINE() {
  return getToken(blackbirdParser::NEWLINE, 0);
}

blackbirdParser::ArrayvalContext* blackbirdParser::ArrayvarContext::arrayval() {
  return getRuleContext<blackbirdParser::ArrayvalContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

blackbirdParser::ShapeContext* blackbirdParser::ArrayvarContext::shape() {
  return getRuleContext<blackbirdParser::ShapeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::ArrayvarContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayvar;
}

antlrcpp::Any blackbirdParser::ArrayvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayvar(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayvarContext* blackbirdParser::arrayvar() {
  ArrayvarContext *_localctx = _tracker.createInstance<ArrayvarContext>(_ctx, getState());
  enterRule(_localctx, 6, blackbirdParser::RuleArrayvar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    vartype();
    setState(70);
    match(blackbirdParser::TYPE_ARRAY);
    setState(71);
    name();
    setState(76);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LSQBRAC) {
      setState(72);
      match(blackbirdParser::LSQBRAC);
      setState(73);
      shape();
      setState(74);
      match(blackbirdParser::RSQBRAC);
    }
    setState(78);
    match(blackbirdParser::ASSIGN);
    setState(79);
    match(blackbirdParser::NEWLINE);
    setState(80);
    arrayval();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

blackbirdParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::NameContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::NameContext::getRuleIndex() const {
  return blackbirdParser::RuleName;
}

antlrcpp::Any blackbirdParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NameContext* blackbirdParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 8, blackbirdParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

blackbirdParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_ARRAY() {
  return getToken(blackbirdParser::TYPE_ARRAY, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_FLOAT() {
  return getToken(blackbirdParser::TYPE_FLOAT, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_COMPLEX() {
  return getToken(blackbirdParser::TYPE_COMPLEX, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_INT() {
  return getToken(blackbirdParser::TYPE_INT, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_STR() {
  return getToken(blackbirdParser::TYPE_STR, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_BOOL() {
  return getToken(blackbirdParser::TYPE_BOOL, 0);
}


size_t blackbirdParser::VartypeContext::getRuleIndex() const {
  return blackbirdParser::RuleVartype;
}

antlrcpp::Any blackbirdParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VartypeContext* blackbirdParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 10, blackbirdParser::RuleVartype);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::TYPE_ARRAY)
      | (1ULL << blackbirdParser::TYPE_FLOAT)
      | (1ULL << blackbirdParser::TYPE_COMPLEX)
      | (1ULL << blackbirdParser::TYPE_INT)
      | (1ULL << blackbirdParser::TYPE_STR)
      | (1ULL << blackbirdParser::TYPE_BOOL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonnumericContext ------------------------------------------------------------------

blackbirdParser::NonnumericContext::NonnumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::NonnumericContext::STR() {
  return getToken(blackbirdParser::STR, 0);
}

tree::TerminalNode* blackbirdParser::NonnumericContext::BOOL() {
  return getToken(blackbirdParser::BOOL, 0);
}


size_t blackbirdParser::NonnumericContext::getRuleIndex() const {
  return blackbirdParser::RuleNonnumeric;
}

antlrcpp::Any blackbirdParser::NonnumericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNonnumeric(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NonnumericContext* blackbirdParser::nonnumeric() {
  NonnumericContext *_localctx = _tracker.createInstance<NonnumericContext>(_ctx, getState());
  enterRule(_localctx, 12, blackbirdParser::RuleNonnumeric);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!(_la == blackbirdParser::STR

    || _la == blackbirdParser::BOOL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShapeContext ------------------------------------------------------------------

blackbirdParser::ShapeContext::ShapeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ShapeContext::INT() {
  return getTokens(blackbirdParser::INT);
}

tree::TerminalNode* blackbirdParser::ShapeContext::INT(size_t i) {
  return getToken(blackbirdParser::INT, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ShapeContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ShapeContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ShapeContext::getRuleIndex() const {
  return blackbirdParser::RuleShape;
}

antlrcpp::Any blackbirdParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ShapeContext* blackbirdParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 14, blackbirdParser::RuleShape);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(blackbirdParser::INT);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(89);
      match(blackbirdParser::COMMA);
      setState(90);
      match(blackbirdParser::INT);
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayvalContext ------------------------------------------------------------------

blackbirdParser::ArrayvalContext::ArrayvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayvalContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ArrayvalContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayvalContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ArrayvalContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<blackbirdParser::ArrayrowContext *> blackbirdParser::ArrayvalContext::arrayrow() {
  return getRuleContexts<blackbirdParser::ArrayrowContext>();
}

blackbirdParser::ArrayrowContext* blackbirdParser::ArrayvalContext::arrayrow(size_t i) {
  return getRuleContext<blackbirdParser::ArrayrowContext>(i);
}


size_t blackbirdParser::ArrayvalContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayval;
}

antlrcpp::Any blackbirdParser::ArrayvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayval(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayvalContext* blackbirdParser::arrayval() {
  ArrayvalContext *_localctx = _tracker.createInstance<ArrayvalContext>(_ctx, getState());
  enterRule(_localctx, 16, blackbirdParser::RuleArrayval);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::TAB) {
      setState(96);
      match(blackbirdParser::TAB);
      setState(97);
      dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext = arrayrow();
      dynamic_cast<ArrayvalContext *>(_localctx)->row_list.push_back(dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext);
      setState(98);
      match(blackbirdParser::NEWLINE);
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayrowContext ------------------------------------------------------------------

blackbirdParser::ArrayrowContext::ArrayrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::ArrayrowContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::ArrayrowContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayrowContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ArrayrowContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ArrayrowContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayrow;
}

antlrcpp::Any blackbirdParser::ArrayrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayrow(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayrowContext* blackbirdParser::arrayrow() {
  ArrayrowContext *_localctx = _tracker.createInstance<ArrayrowContext>(_ctx, getState());
  enterRule(_localctx, 18, blackbirdParser::RuleArrayrow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    expression(0);
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(106);
      match(blackbirdParser::COMMA);
      setState(107);
      expression(0);
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

blackbirdParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ProgramContext::WITH() {
  return getToken(blackbirdParser::WITH, 0);
}

blackbirdParser::DeviceContext* blackbirdParser::ProgramContext::device() {
  return getRuleContext<blackbirdParser::DeviceContext>(0);
}

tree::TerminalNode* blackbirdParser::ProgramContext::COLON() {
  return getToken(blackbirdParser::COLON, 0);
}

std::vector<tree::TerminalNode *> blackbirdParser::ProgramContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

blackbirdParser::ArgumentsContext* blackbirdParser::ProgramContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::ProgramContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ProgramContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}

std::vector<blackbirdParser::StatementContext *> blackbirdParser::ProgramContext::statement() {
  return getRuleContexts<blackbirdParser::StatementContext>();
}

blackbirdParser::StatementContext* blackbirdParser::ProgramContext::statement(size_t i) {
  return getRuleContext<blackbirdParser::StatementContext>(i);
}


size_t blackbirdParser::ProgramContext::getRuleIndex() const {
  return blackbirdParser::RuleProgram;
}

antlrcpp::Any blackbirdParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramContext* blackbirdParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 20, blackbirdParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(blackbirdParser::WITH);
    setState(114);
    device();
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(115);
      arguments();
    }
    setState(118);
    match(blackbirdParser::COLON);
    setState(119);
    match(blackbirdParser::NEWLINE);
    setState(126);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(124);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(120);
          dynamic_cast<ProgramContext *>(_localctx)->statementContext = statement();
          dynamic_cast<ProgramContext *>(_localctx)->statement_list.push_back(dynamic_cast<ProgramContext *>(_localctx)->statementContext);
          break;
        }

        case 2: {
          setState(121);
          match(blackbirdParser::NEWLINE);
          break;
        }

        case 3: {
          setState(122);
          match(blackbirdParser::TAB);
          setState(123);
          match(blackbirdParser::NEWLINE);
          break;
        }

        } 
      }
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeviceContext ------------------------------------------------------------------

blackbirdParser::DeviceContext::DeviceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeviceContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::DeviceContext::DEVICE() {
  return getToken(blackbirdParser::DEVICE, 0);
}


size_t blackbirdParser::DeviceContext::getRuleIndex() const {
  return blackbirdParser::RuleDevice;
}

antlrcpp::Any blackbirdParser::DeviceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDevice(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeviceContext* blackbirdParser::device() {
  DeviceContext *_localctx = _tracker.createInstance<DeviceContext>(_ctx, getState());
  enterRule(_localctx, 22, blackbirdParser::RuleDevice);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _la = _input->LA(1);
    if (!(_la == blackbirdParser::NAME

    || _la == blackbirdParser::DEVICE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

blackbirdParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::StatementContext::TAB() {
  return getToken(blackbirdParser::TAB, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::APPLY() {
  return getToken(blackbirdParser::APPLY, 0);
}

blackbirdParser::ModesContext* blackbirdParser::StatementContext::modes() {
  return getRuleContext<blackbirdParser::ModesContext>(0);
}

tree::TerminalNode* blackbirdParser::StatementContext::NEWLINE() {
  return getToken(blackbirdParser::NEWLINE, 0);
}

blackbirdParser::OperationContext* blackbirdParser::StatementContext::operation() {
  return getRuleContext<blackbirdParser::OperationContext>(0);
}

blackbirdParser::MeasureContext* blackbirdParser::StatementContext::measure() {
  return getRuleContext<blackbirdParser::MeasureContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::StatementContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}

tree::TerminalNode* blackbirdParser::StatementContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::StatementContext::getRuleIndex() const {
  return blackbirdParser::RuleStatement;
}

antlrcpp::Any blackbirdParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::StatementContext* blackbirdParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, blackbirdParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(blackbirdParser::TAB);
    setState(134);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::NAME: {
        setState(132);
        operation();
        break;
      }

      case blackbirdParser::MEASURE: {
        setState(133);
        measure();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(136);
      arguments();
    }
    setState(139);
    match(blackbirdParser::APPLY);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC

    || _la == blackbirdParser::LSQBRAC) {
      setState(140);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::LBRAC

      || _la == blackbirdParser::LSQBRAC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(143);
    modes();
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::RBRAC

    || _la == blackbirdParser::RSQBRAC) {
      setState(144);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::RBRAC

      || _la == blackbirdParser::RSQBRAC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(147);
    match(blackbirdParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

blackbirdParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::OperationContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::OperationContext::getRuleIndex() const {
  return blackbirdParser::RuleOperation;
}

antlrcpp::Any blackbirdParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::OperationContext* blackbirdParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 26, blackbirdParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureContext ------------------------------------------------------------------

blackbirdParser::MeasureContext::MeasureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::MeasureContext::MEASURE() {
  return getToken(blackbirdParser::MEASURE, 0);
}


size_t blackbirdParser::MeasureContext::getRuleIndex() const {
  return blackbirdParser::RuleMeasure;
}

antlrcpp::Any blackbirdParser::MeasureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMeasure(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::MeasureContext* blackbirdParser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 28, blackbirdParser::RuleMeasure);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(blackbirdParser::MEASURE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

blackbirdParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

std::vector<blackbirdParser::ValContext *> blackbirdParser::ArgumentsContext::val() {
  return getRuleContexts<blackbirdParser::ValContext>();
}

blackbirdParser::ValContext* blackbirdParser::ArgumentsContext::val(size_t i) {
  return getRuleContext<blackbirdParser::ValContext>(i);
}

std::vector<blackbirdParser::KwargContext *> blackbirdParser::ArgumentsContext::kwarg() {
  return getRuleContexts<blackbirdParser::KwargContext>();
}

blackbirdParser::KwargContext* blackbirdParser::ArgumentsContext::kwarg(size_t i) {
  return getRuleContext<blackbirdParser::KwargContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArgumentsContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ArgumentsContext::getRuleIndex() const {
  return blackbirdParser::RuleArguments;
}

antlrcpp::Any blackbirdParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArgumentsContext* blackbirdParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 30, blackbirdParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(blackbirdParser::LBRAC);
    setState(162);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(154);
      dynamic_cast<ArgumentsContext *>(_localctx)->valContext = val();
      dynamic_cast<ArgumentsContext *>(_localctx)->val_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->valContext);
      setState(159);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(155);
        match(blackbirdParser::COMMA);
        setState(156);
        dynamic_cast<ArgumentsContext *>(_localctx)->valContext = val();
        dynamic_cast<ArgumentsContext *>(_localctx)->val_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->valContext);
        setState(161);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::NAME) {
      setState(164);
      dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
      dynamic_cast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext);
      setState(169);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(165);
        match(blackbirdParser::COMMA);
        setState(166);
        dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
        dynamic_cast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext);
        setState(171);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(174);
    match(blackbirdParser::RBRAC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KwargContext ------------------------------------------------------------------

blackbirdParser::KwargContext::KwargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::KwargContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::KwargContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

blackbirdParser::ValContext* blackbirdParser::KwargContext::val() {
  return getRuleContext<blackbirdParser::ValContext>(0);
}


size_t blackbirdParser::KwargContext::getRuleIndex() const {
  return blackbirdParser::RuleKwarg;
}

antlrcpp::Any blackbirdParser::KwargContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitKwarg(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::KwargContext* blackbirdParser::kwarg() {
  KwargContext *_localctx = _tracker.createInstance<KwargContext>(_ctx, getState());
  enterRule(_localctx, 32, blackbirdParser::RuleKwarg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(blackbirdParser::NAME);
    setState(177);
    match(blackbirdParser::ASSIGN);
    setState(178);
    val();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValContext ------------------------------------------------------------------

blackbirdParser::ValContext::ValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::NonnumericContext* blackbirdParser::ValContext::nonnumeric() {
  return getRuleContext<blackbirdParser::NonnumericContext>(0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ValContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}


size_t blackbirdParser::ValContext::getRuleIndex() const {
  return blackbirdParser::RuleVal;
}

antlrcpp::Any blackbirdParser::ValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVal(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ValContext* blackbirdParser::val() {
  ValContext *_localctx = _tracker.createInstance<ValContext>(_ctx, getState());
  enterRule(_localctx, 34, blackbirdParser::RuleVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(180);
        nonnumeric();
        break;
      }

      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::EXP:
      case blackbirdParser::LBRAC:
      case blackbirdParser::NAME: {
        setState(181);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModesContext ------------------------------------------------------------------

blackbirdParser::ModesContext::ModesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ModesContext::INT() {
  return getTokens(blackbirdParser::INT);
}

tree::TerminalNode* blackbirdParser::ModesContext::INT(size_t i) {
  return getToken(blackbirdParser::INT, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ModesContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ModesContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ModesContext::getRuleIndex() const {
  return blackbirdParser::RuleModes;
}

antlrcpp::Any blackbirdParser::ModesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitModes(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ModesContext* blackbirdParser::modes() {
  ModesContext *_localctx = _tracker.createInstance<ModesContext>(_ctx, getState());
  enterRule(_localctx, 36, blackbirdParser::RuleModes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(blackbirdParser::INT);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(185);
      match(blackbirdParser::COMMA);
      setState(186);
      match(blackbirdParser::INT);
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

blackbirdParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t blackbirdParser::ExpressionContext::getRuleIndex() const {
  return blackbirdParser::RuleExpression;
}

void blackbirdParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BracketsLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::BracketsLabelContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::BracketsLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::BracketsLabelContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

blackbirdParser::BracketsLabelContext::BracketsLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::BracketsLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitBracketsLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignLabelContext ------------------------------------------------------------------

blackbirdParser::ExpressionContext* blackbirdParser::SignLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::SignLabelContext::PLUS() {
  return getToken(blackbirdParser::PLUS, 0);
}

tree::TerminalNode* blackbirdParser::SignLabelContext::MINUS() {
  return getToken(blackbirdParser::MINUS, 0);
}

blackbirdParser::SignLabelContext::SignLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::SignLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitSignLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::PowerLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::PowerLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::PowerLabelContext::PWR() {
  return getToken(blackbirdParser::PWR, 0);
}

blackbirdParser::PowerLabelContext::PowerLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::PowerLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitPowerLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberLabelContext ------------------------------------------------------------------

blackbirdParser::NumberContext* blackbirdParser::NumberLabelContext::number() {
  return getRuleContext<blackbirdParser::NumberContext>(0);
}

blackbirdParser::NumberLabelContext::NumberLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::NumberLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNumberLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::VariableLabelContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

blackbirdParser::VariableLabelContext::VariableLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::VariableLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVariableLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::MulLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::MulLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::MulLabelContext::TIMES() {
  return getToken(blackbirdParser::TIMES, 0);
}

tree::TerminalNode* blackbirdParser::MulLabelContext::DIVIDE() {
  return getToken(blackbirdParser::DIVIDE, 0);
}

blackbirdParser::MulLabelContext::MulLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::MulLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMulLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionLabelContext ------------------------------------------------------------------

blackbirdParser::FunctionContext* blackbirdParser::FunctionLabelContext::function() {
  return getRuleContext<blackbirdParser::FunctionContext>(0);
}

tree::TerminalNode* blackbirdParser::FunctionLabelContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::FunctionLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::FunctionLabelContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

blackbirdParser::FunctionLabelContext::FunctionLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::FunctionLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitFunctionLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::AddLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::AddLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::AddLabelContext::PLUS() {
  return getToken(blackbirdParser::PLUS, 0);
}

tree::TerminalNode* blackbirdParser::AddLabelContext::MINUS() {
  return getToken(blackbirdParser::MINUS, 0);
}

blackbirdParser::AddLabelContext::AddLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any blackbirdParser::AddLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitAddLabel(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ExpressionContext* blackbirdParser::expression() {
   return expression(0);
}

blackbirdParser::ExpressionContext* blackbirdParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  blackbirdParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  blackbirdParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, blackbirdParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::LBRAC: {
        _localctx = _tracker.createInstance<BracketsLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(193);
        match(blackbirdParser::LBRAC);
        setState(194);
        expression(0);
        setState(195);
        match(blackbirdParser::RBRAC);
        break;
      }

      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS: {
        _localctx = _tracker.createInstance<SignLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(197);
        _la = _input->LA(1);
        if (!(_la == blackbirdParser::PLUS

        || _la == blackbirdParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(198);
        expression(7);
        break;
      }

      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::EXP: {
        _localctx = _tracker.createInstance<FunctionLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(199);
        function();
        setState(200);
        match(blackbirdParser::LBRAC);
        setState(201);
        expression(0);
        setState(202);
        match(blackbirdParser::RBRAC);
        break;
      }

      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::PI: {
        _localctx = _tracker.createInstance<NumberLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(204);
        number();
        break;
      }

      case blackbirdParser::NAME: {
        _localctx = _tracker.createInstance<VariableLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(205);
        match(blackbirdParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(217);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(208);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(209);
          match(blackbirdParser::PWR);
          setState(210);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(212);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::TIMES

          || _la == blackbirdParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(213);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(215);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::PLUS

          || _la == blackbirdParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(216);
          expression(5);
          break;
        }

        } 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

blackbirdParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::NumberContext::INT() {
  return getToken(blackbirdParser::INT, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::FLOAT() {
  return getToken(blackbirdParser::FLOAT, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::COMPLEX() {
  return getToken(blackbirdParser::COMPLEX, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::PI() {
  return getToken(blackbirdParser::PI, 0);
}


size_t blackbirdParser::NumberContext::getRuleIndex() const {
  return blackbirdParser::RuleNumber;
}

antlrcpp::Any blackbirdParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NumberContext* blackbirdParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, blackbirdParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::INT)
      | (1ULL << blackbirdParser::FLOAT)
      | (1ULL << blackbirdParser::COMPLEX)
      | (1ULL << blackbirdParser::PI))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

blackbirdParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::FunctionContext::SIN() {
  return getToken(blackbirdParser::SIN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::COS() {
  return getToken(blackbirdParser::COS, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::SQRT() {
  return getToken(blackbirdParser::SQRT, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::EXP() {
  return getToken(blackbirdParser::EXP, 0);
}


size_t blackbirdParser::FunctionContext::getRuleIndex() const {
  return blackbirdParser::RuleFunction;
}

antlrcpp::Any blackbirdParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::FunctionContext* blackbirdParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 42, blackbirdParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::SQRT)
      | (1ULL << blackbirdParser::SIN)
      | (1ULL << blackbirdParser::COS)
      | (1ULL << blackbirdParser::EXP))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool blackbirdParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool blackbirdParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> blackbirdParser::_decisionToDFA;
atn::PredictionContextCache blackbirdParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN blackbirdParser::_atn;
std::vector<uint16_t> blackbirdParser::_serializedATN;

std::vector<std::string> blackbirdParser::_ruleNames = {
  "start", "varblock", "expressionvar", "arrayvar", "name", "vartype", "nonnumeric", 
  "shape", "arrayval", "arrayrow", "program", "device", "statement", "operation", 
  "measure", "arguments", "kwarg", "val", "modes", "expression", "number", 
  "function"
};

std::vector<std::string> blackbirdParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'", "'**'", "'='", "", "", "", "", "", "", 
  "'pi'", "", "", "", "'with'", "'sqrt'", "'sin'", "'cos'", "'exp'", "'.'", 
  "','", "':'", "'\"'", "'('", "')'", "'['", "']'", "'|'", "'array'", "'float'", 
  "'complex'", "'int'", "'str'", "'bool'"
};

std::vector<std::string> blackbirdParser::_symbolicNames = {
  "", "PLUS", "MINUS", "TIMES", "DIVIDE", "PWR", "ASSIGN", "INT", "FLOAT", 
  "COMPLEX", "STR", "BOOL", "SEQUENCE", "PI", "NEWLINE", "TAB", "SPACE", 
  "WITH", "SQRT", "SIN", "COS", "EXP", "PERIOD", "COMMA", "COLON", "QUOTE", 
  "LBRAC", "RBRAC", "LSQBRAC", "RSQBRAC", "APPLY", "TYPE_ARRAY", "TYPE_FLOAT", 
  "TYPE_COMPLEX", "TYPE_INT", "TYPE_STR", "TYPE_BOOL", "MEASURE", "NAME", 
  "DEVICE", "COMMENT", "ANY"
};

dfa::Vocabulary blackbirdParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> blackbirdParser::_tokenNames;

blackbirdParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0xe5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3c, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x3f, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x46, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4f, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0x5e, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x61, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x67, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6a, 
    0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x6f, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0x72, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x77, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x7, 0xc, 0x7f, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x82, 0xb, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x89, 0xa, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x8c, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x90, 
    0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x94, 0xa, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xa0, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0xa3, 0xb, 0x11, 0x5, 0x11, 0xa5, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x7, 0x11, 0xaa, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xad, 0xb, 0x11, 
    0x5, 0x11, 0xaf, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xb9, 0xa, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xbe, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0xc1, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xd1, 0xa, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xdc, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
    0xdf, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x2, 0x3, 0x28, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2, 0xb, 0x3, 0x2, 0x21, 0x26, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 
    0x28, 0x29, 0x4, 0x2, 0x1c, 0x1c, 0x1e, 0x1e, 0x4, 0x2, 0x1d, 0x1d, 
    0x1f, 0x1f, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x4, 0x2, 0x9, 0xb, 
    0xf, 0xf, 0x3, 0x2, 0x14, 0x17, 0x2, 0xec, 0x2, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x40, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0xa, 0x54, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x68, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x73, 0x3, 0x2, 0x2, 0x2, 0x18, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x85, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x26, 0xba, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0x4, 
    0x3, 0x2, 0x2f, 0x33, 0x5, 0x16, 0xc, 0x2, 0x30, 0x32, 0x7, 0x10, 0x2, 
    0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0x7, 0x2, 0x2, 0x3, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3c, 0x7, 
    0x10, 0x2, 0x2, 0x39, 0x3c, 0x5, 0x6, 0x4, 0x2, 0x3a, 0x3c, 0x5, 0x8, 
    0x5, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
    0x5, 0xc, 0x7, 0x2, 0x41, 0x42, 0x5, 0xa, 0x6, 0x2, 0x42, 0x45, 0x7, 
    0x8, 0x2, 0x2, 0x43, 0x46, 0x5, 0x28, 0x15, 0x2, 0x44, 0x46, 0x5, 0xe, 
    0x8, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x7, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x5, 0xc, 0x7, 0x2, 
    0x48, 0x49, 0x7, 0x21, 0x2, 0x2, 0x49, 0x4e, 0x5, 0xa, 0x6, 0x2, 0x4a, 
    0x4b, 0x7, 0x1e, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x10, 0x9, 0x2, 0x4c, 0x4d, 
    0x7, 0x1f, 0x2, 0x2, 0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x7, 0x8, 0x2, 0x2, 0x51, 0x52, 0x7, 0x10, 0x2, 
    0x2, 0x52, 0x53, 0x5, 0x12, 0xa, 0x2, 0x53, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x7, 0x28, 0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x57, 0x9, 0x2, 0x2, 0x2, 0x57, 0xd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x9, 0x3, 0x2, 0x2, 0x59, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5f, 0x7, 
    0x9, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x19, 0x2, 0x2, 0x5c, 0x5e, 0x7, 0x9, 
    0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x11, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x63, 0x7, 0x11, 0x2, 0x2, 0x63, 0x64, 0x5, 0x14, 0xb, 0x2, 0x64, 0x65, 
    0x7, 0x10, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x70, 0x5, 0x28, 0x15, 0x2, 
    0x6c, 0x6d, 0x7, 0x19, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0x28, 0x15, 0x2, 0x6e, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x13, 
    0x2, 0x2, 0x74, 0x76, 0x5, 0x18, 0xd, 0x2, 0x75, 0x77, 0x5, 0x20, 0x11, 
    0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x1a, 0x2, 0x2, 0x79, 
    0x80, 0x7, 0x10, 0x2, 0x2, 0x7a, 0x7f, 0x5, 0x1a, 0xe, 0x2, 0x7b, 0x7f, 
    0x7, 0x10, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x11, 0x2, 0x2, 0x7d, 0x7f, 0x7, 
    0x10, 0x2, 0x2, 0x7e, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x17, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x84, 0x9, 0x4, 0x2, 0x2, 0x84, 0x19, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 
    0x7, 0x11, 0x2, 0x2, 0x86, 0x89, 0x5, 0x1c, 0xf, 0x2, 0x87, 0x89, 0x5, 
    0x1e, 0x10, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x20, 0x11, 
    0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x7, 0x20, 0x2, 0x2, 0x8e, 
    0x90, 0x9, 0x5, 0x2, 0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x5, 
    0x26, 0x14, 0x2, 0x92, 0x94, 0x9, 0x6, 0x2, 0x2, 0x93, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0x10, 0x2, 0x2, 0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0x28, 0x2, 0x2, 0x98, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0x27, 0x2, 0x2, 0x9a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9b, 0xa4, 
    0x7, 0x1c, 0x2, 0x2, 0x9c, 0xa1, 0x5, 0x24, 0x13, 0x2, 0x9d, 0x9e, 0x7, 
    0x19, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0x24, 0x13, 0x2, 0x9f, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa5, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xae, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xab, 
    0x5, 0x22, 0x12, 0x2, 0xa7, 0xa8, 0x7, 0x19, 0x2, 0x2, 0xa8, 0xaa, 0x5, 
    0x22, 0x12, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x1d, 0x2, 0x2, 0xb1, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x28, 0x2, 0x2, 0xb3, 0xb4, 0x7, 
    0x8, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x24, 0x13, 0x2, 0xb5, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb9, 0x5, 0xe, 0x8, 0x2, 0xb7, 0xb9, 0x5, 0x28, 0x15, 
    0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0x25, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbf, 0x7, 0x9, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0x19, 0x2, 0x2, 0xbc, 0xbe, 0x7, 0x9, 0x2, 0x2, 0xbd, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x8, 0x15, 0x1, 
    0x2, 0xc3, 0xc4, 0x7, 0x1c, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x28, 0x15, 0x2, 
    0xc5, 0xc6, 0x7, 0x1d, 0x2, 0x2, 0xc6, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc8, 0x9, 0x7, 0x2, 0x2, 0xc8, 0xd1, 0x5, 0x28, 0x15, 0x9, 0xc9, 0xca, 
    0x5, 0x2c, 0x17, 0x2, 0xca, 0xcb, 0x7, 0x1c, 0x2, 0x2, 0xcb, 0xcc, 0x5, 
    0x28, 0x15, 0x2, 0xcc, 0xcd, 0x7, 0x1d, 0x2, 0x2, 0xcd, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xd1, 0x5, 0x2a, 0x16, 0x2, 0xcf, 0xd1, 0x7, 0x28, 0x2, 
    0x2, 0xd0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 
    0xc, 0x8, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x7, 0x2, 0x2, 0xd4, 0xdc, 0x5, 
    0x28, 0x15, 0x8, 0xd5, 0xd6, 0xc, 0x7, 0x2, 0x2, 0xd6, 0xd7, 0x9, 0x8, 
    0x2, 0x2, 0xd7, 0xdc, 0x5, 0x28, 0x15, 0x8, 0xd8, 0xd9, 0xc, 0x6, 0x2, 
    0x2, 0xd9, 0xda, 0x9, 0x7, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x28, 0x15, 0x7, 
    0xdb, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xd8, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x9, 0x9, 
    0x2, 0x2, 0xe1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x9, 0xa, 0x2, 
    0x2, 0xe3, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x33, 0x3b, 0x3d, 0x45, 0x4e, 
    0x5f, 0x68, 0x70, 0x76, 0x7e, 0x80, 0x88, 0x8b, 0x8f, 0x93, 0xa1, 0xa4, 
    0xab, 0xae, 0xb8, 0xbf, 0xd0, 0xdb, 0xdd, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

blackbirdParser::Initializer blackbirdParser::_init;
