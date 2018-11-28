
// Generated from blackbird.g4 by ANTLR 4.7.1


#include "blackbirdListener.h"
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

std::vector<blackbirdParser::VariableContext *> blackbirdParser::StartContext::variable() {
  return getRuleContexts<blackbirdParser::VariableContext>();
}

blackbirdParser::VariableContext* blackbirdParser::StartContext::variable(size_t i) {
  return getRuleContext<blackbirdParser::VariableContext>(i);
}


size_t blackbirdParser::StartContext::getRuleIndex() const {
  return blackbirdParser::RuleStart;
}

void blackbirdParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void blackbirdParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
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
      setState(42);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case blackbirdParser::NEWLINE: {
          setState(40);
          match(blackbirdParser::NEWLINE);
          break;
        }

        case blackbirdParser::TYPE_ARRAY:
        case blackbirdParser::TYPE_FLOAT:
        case blackbirdParser::TYPE_COMPLEX:
        case blackbirdParser::TYPE_INT:
        case blackbirdParser::TYPE_STR:
        case blackbirdParser::TYPE_BOOL: {
          setState(41);
          variable();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(47);
    program();
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(48);
      match(blackbirdParser::NEWLINE);
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
    match(blackbirdParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

blackbirdParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t blackbirdParser::VariableContext::getRuleIndex() const {
  return blackbirdParser::RuleVariable;
}

void blackbirdParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionVariableLabelContext ------------------------------------------------------------------

blackbirdParser::VartypeContext* blackbirdParser::ExpressionVariableLabelContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

blackbirdParser::NameContext* blackbirdParser::ExpressionVariableLabelContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ExpressionVariableLabelContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ExpressionVariableLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

blackbirdParser::NonnumericContext* blackbirdParser::ExpressionVariableLabelContext::nonnumeric() {
  return getRuleContext<blackbirdParser::NonnumericContext>(0);
}

blackbirdParser::ExpressionVariableLabelContext::ExpressionVariableLabelContext(VariableContext *ctx) { copyFrom(ctx); }

void blackbirdParser::ExpressionVariableLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionVariableLabel(this);
}
void blackbirdParser::ExpressionVariableLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionVariableLabel(this);
}

antlrcpp::Any blackbirdParser::ExpressionVariableLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitExpressionVariableLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayVariableLabelContext ------------------------------------------------------------------

blackbirdParser::VartypeContext* blackbirdParser::ArrayVariableLabelContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayVariableLabelContext::TYPE_ARRAY() {
  return getToken(blackbirdParser::TYPE_ARRAY, 0);
}

blackbirdParser::NameContext* blackbirdParser::ArrayVariableLabelContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayVariableLabelContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

tree::TerminalNode* blackbirdParser::ArrayVariableLabelContext::NEWLINE() {
  return getToken(blackbirdParser::NEWLINE, 0);
}

blackbirdParser::ArrayvalContext* blackbirdParser::ArrayVariableLabelContext::arrayval() {
  return getRuleContext<blackbirdParser::ArrayvalContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayVariableLabelContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

blackbirdParser::ShapeContext* blackbirdParser::ArrayVariableLabelContext::shape() {
  return getRuleContext<blackbirdParser::ShapeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayVariableLabelContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}

blackbirdParser::ArrayVariableLabelContext::ArrayVariableLabelContext(VariableContext *ctx) { copyFrom(ctx); }

void blackbirdParser::ArrayVariableLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayVariableLabel(this);
}
void blackbirdParser::ArrayVariableLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayVariableLabel(this);
}

antlrcpp::Any blackbirdParser::ArrayVariableLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayVariableLabel(this);
  else
    return visitor->visitChildren(this);
}
blackbirdParser::VariableContext* blackbirdParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 2, blackbirdParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<blackbirdParser::ExpressionVariableLabelContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(56);
      vartype();
      setState(57);
      name();
      setState(58);
      match(blackbirdParser::ASSIGN);
      setState(61);
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
          setState(59);
          expression(0);
          break;
        }

        case blackbirdParser::STR:
        case blackbirdParser::BOOL: {
          setState(60);
          nonnumeric();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<blackbirdParser::ArrayVariableLabelContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(63);
      vartype();
      setState(64);
      match(blackbirdParser::TYPE_ARRAY);
      setState(65);
      name();
      setState(70);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == blackbirdParser::LSQBRAC) {
        setState(66);
        match(blackbirdParser::LSQBRAC);
        setState(67);
        shape();
        setState(68);
        match(blackbirdParser::RSQBRAC);
      }
      setState(72);
      match(blackbirdParser::ASSIGN);
      setState(73);
      match(blackbirdParser::NEWLINE);
      setState(74);
      arrayval();
      break;
    }

    }
   
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

void blackbirdParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void blackbirdParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any blackbirdParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NameContext* blackbirdParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 4, blackbirdParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
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

void blackbirdParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void blackbirdParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}


antlrcpp::Any blackbirdParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VartypeContext* blackbirdParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 6, blackbirdParser::RuleVartype);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
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

void blackbirdParser::NonnumericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonnumeric(this);
}

void blackbirdParser::NonnumericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonnumeric(this);
}


antlrcpp::Any blackbirdParser::NonnumericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNonnumeric(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NonnumericContext* blackbirdParser::nonnumeric() {
  NonnumericContext *_localctx = _tracker.createInstance<NonnumericContext>(_ctx, getState());
  enterRule(_localctx, 8, blackbirdParser::RuleNonnumeric);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
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

void blackbirdParser::ShapeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShape(this);
}

void blackbirdParser::ShapeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShape(this);
}


antlrcpp::Any blackbirdParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ShapeContext* blackbirdParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 10, blackbirdParser::RuleShape);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(blackbirdParser::INT);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(85);
      match(blackbirdParser::COMMA);
      setState(86);
      match(blackbirdParser::INT);
      setState(91);
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

void blackbirdParser::ArrayvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayval(this);
}

void blackbirdParser::ArrayvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayval(this);
}


antlrcpp::Any blackbirdParser::ArrayvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayval(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayvalContext* blackbirdParser::arrayval() {
  ArrayvalContext *_localctx = _tracker.createInstance<ArrayvalContext>(_ctx, getState());
  enterRule(_localctx, 12, blackbirdParser::RuleArrayval);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::TAB) {
      setState(92);
      match(blackbirdParser::TAB);
      setState(93);
      dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext = arrayrow();
      dynamic_cast<ArrayvalContext *>(_localctx)->row.push_back(dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext);
      setState(94);
      match(blackbirdParser::NEWLINE);
      setState(100);
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

void blackbirdParser::ArrayrowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayrow(this);
}

void blackbirdParser::ArrayrowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayrow(this);
}


antlrcpp::Any blackbirdParser::ArrayrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayrow(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayrowContext* blackbirdParser::arrayrow() {
  ArrayrowContext *_localctx = _tracker.createInstance<ArrayrowContext>(_ctx, getState());
  enterRule(_localctx, 14, blackbirdParser::RuleArrayrow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    expression(0);
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(102);
      match(blackbirdParser::COMMA);
      setState(103);
      expression(0);
      setState(108);
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

std::vector<blackbirdParser::StatementContext *> blackbirdParser::ProgramContext::statement() {
  return getRuleContexts<blackbirdParser::StatementContext>();
}

blackbirdParser::StatementContext* blackbirdParser::ProgramContext::statement(size_t i) {
  return getRuleContext<blackbirdParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ProgramContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ProgramContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}


size_t blackbirdParser::ProgramContext::getRuleIndex() const {
  return blackbirdParser::RuleProgram;
}

void blackbirdParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void blackbirdParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any blackbirdParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramContext* blackbirdParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 16, blackbirdParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(blackbirdParser::WITH);
    setState(110);
    device();
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(111);
      arguments();
    }
    setState(114);
    match(blackbirdParser::COLON);
    setState(115);
    match(blackbirdParser::NEWLINE);
    setState(122);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(120);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(116);
          statement();
          break;
        }

        case 2: {
          setState(117);
          match(blackbirdParser::NEWLINE);
          break;
        }

        case 3: {
          setState(118);
          match(blackbirdParser::TAB);
          setState(119);
          match(blackbirdParser::NEWLINE);
          break;
        }

        } 
      }
      setState(124);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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

void blackbirdParser::DeviceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDevice(this);
}

void blackbirdParser::DeviceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDevice(this);
}


antlrcpp::Any blackbirdParser::DeviceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDevice(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeviceContext* blackbirdParser::device() {
  DeviceContext *_localctx = _tracker.createInstance<DeviceContext>(_ctx, getState());
  enterRule(_localctx, 18, blackbirdParser::RuleDevice);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
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

void blackbirdParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void blackbirdParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any blackbirdParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::StatementContext* blackbirdParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, blackbirdParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(blackbirdParser::TAB);
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::NAME: {
        setState(128);
        operation();
        break;
      }

      case blackbirdParser::MEASURE: {
        setState(129);
        measure();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(132);
      arguments();
    }
    setState(135);
    match(blackbirdParser::APPLY);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC

    || _la == blackbirdParser::LSQBRAC) {
      setState(136);
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
    setState(139);
    modes();
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::RBRAC

    || _la == blackbirdParser::RSQBRAC) {
      setState(140);
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
    setState(143);
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

void blackbirdParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void blackbirdParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}


antlrcpp::Any blackbirdParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::OperationContext* blackbirdParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 22, blackbirdParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
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

void blackbirdParser::MeasureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMeasure(this);
}

void blackbirdParser::MeasureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMeasure(this);
}


antlrcpp::Any blackbirdParser::MeasureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMeasure(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::MeasureContext* blackbirdParser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 24, blackbirdParser::RuleMeasure);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
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

void blackbirdParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void blackbirdParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any blackbirdParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArgumentsContext* blackbirdParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 26, blackbirdParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(blackbirdParser::LBRAC);
    setState(158);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(150);
      val();
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(151);
        match(blackbirdParser::COMMA);
        setState(152);
        val();
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::NAME) {
      setState(160);
      kwarg();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(161);
        match(blackbirdParser::COMMA);
        setState(162);
        kwarg();
        setState(167);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(170);
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

void blackbirdParser::KwargContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKwarg(this);
}

void blackbirdParser::KwargContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKwarg(this);
}


antlrcpp::Any blackbirdParser::KwargContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitKwarg(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::KwargContext* blackbirdParser::kwarg() {
  KwargContext *_localctx = _tracker.createInstance<KwargContext>(_ctx, getState());
  enterRule(_localctx, 28, blackbirdParser::RuleKwarg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(blackbirdParser::NAME);
    setState(173);
    match(blackbirdParser::ASSIGN);
    setState(174);
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

void blackbirdParser::ValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVal(this);
}

void blackbirdParser::ValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVal(this);
}


antlrcpp::Any blackbirdParser::ValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVal(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ValContext* blackbirdParser::val() {
  ValContext *_localctx = _tracker.createInstance<ValContext>(_ctx, getState());
  enterRule(_localctx, 30, blackbirdParser::RuleVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(176);
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
        setState(177);
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

void blackbirdParser::ModesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModes(this);
}

void blackbirdParser::ModesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModes(this);
}


antlrcpp::Any blackbirdParser::ModesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitModes(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ModesContext* blackbirdParser::modes() {
  ModesContext *_localctx = _tracker.createInstance<ModesContext>(_ctx, getState());
  enterRule(_localctx, 32, blackbirdParser::RuleModes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(blackbirdParser::INT);
    setState(185);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(181);
      match(blackbirdParser::COMMA);
      setState(182);
      match(blackbirdParser::INT);
      setState(187);
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

void blackbirdParser::BracketsLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracketsLabel(this);
}
void blackbirdParser::BracketsLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracketsLabel(this);
}

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

void blackbirdParser::SignLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignLabel(this);
}
void blackbirdParser::SignLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignLabel(this);
}

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

void blackbirdParser::PowerLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerLabel(this);
}
void blackbirdParser::PowerLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerLabel(this);
}

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

void blackbirdParser::NumberLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberLabel(this);
}
void blackbirdParser::NumberLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberLabel(this);
}

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

void blackbirdParser::VariableLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableLabel(this);
}
void blackbirdParser::VariableLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableLabel(this);
}

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

void blackbirdParser::MulLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulLabel(this);
}
void blackbirdParser::MulLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulLabel(this);
}

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

void blackbirdParser::FunctionLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionLabel(this);
}
void blackbirdParser::FunctionLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionLabel(this);
}

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

void blackbirdParser::AddLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddLabel(this);
}
void blackbirdParser::AddLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddLabel(this);
}

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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, blackbirdParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(202);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::LBRAC: {
        _localctx = _tracker.createInstance<BracketsLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(189);
        match(blackbirdParser::LBRAC);
        setState(190);
        expression(0);
        setState(191);
        match(blackbirdParser::RBRAC);
        break;
      }

      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS: {
        _localctx = _tracker.createInstance<SignLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(193);
        _la = _input->LA(1);
        if (!(_la == blackbirdParser::PLUS

        || _la == blackbirdParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(194);
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
        setState(195);
        function();
        setState(196);
        match(blackbirdParser::LBRAC);
        setState(197);
        expression(0);
        setState(198);
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
        setState(200);
        number();
        break;
      }

      case blackbirdParser::NAME: {
        _localctx = _tracker.createInstance<VariableLabelContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(201);
        match(blackbirdParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(215);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(213);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(204);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(205);
          match(blackbirdParser::PWR);
          setState(206);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(207);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(208);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::TIMES

          || _la == blackbirdParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(209);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(210);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(211);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::PLUS

          || _la == blackbirdParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          expression(5);
          break;
        }

        } 
      }
      setState(217);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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

void blackbirdParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void blackbirdParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any blackbirdParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NumberContext* blackbirdParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 36, blackbirdParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
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

void blackbirdParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void blackbirdParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<blackbirdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


antlrcpp::Any blackbirdParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::FunctionContext* blackbirdParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 38, blackbirdParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
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
    case 17: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
  "start", "variable", "name", "vartype", "nonnumeric", "shape", "arrayval", 
  "arrayrow", "program", "device", "statement", "operation", "measure", 
  "arguments", "kwarg", "val", "modes", "expression", "number", "function"
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
    0x3, 0x2b, 0xe1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x2d, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x30, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x40, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x49, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4f, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x5d, 
    0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x63, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x66, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x7, 0x9, 0x6b, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x6e, 0xb, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x73, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x7b, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0x7e, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x85, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0x88, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x8c, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x90, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x9c, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x9f, 0xb, 0xf, 0x5, 0xf, 0xa1, 0xa, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xa6, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa9, 
    0xb, 0xf, 0x5, 0xf, 0xab, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xb5, 0xa, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xba, 0xa, 0x12, 0xc, 
    0x12, 0xe, 0x12, 0xbd, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xcd, 0xa, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xd8, 0xa, 0x13, 0xc, 0x13, 0xe, 
    0x13, 0xdb, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x2, 0x3, 0x24, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2, 0xb, 0x3, 0x2, 0x21, 0x26, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0x28, 
    0x29, 0x4, 0x2, 0x1c, 0x1c, 0x1e, 0x1e, 0x4, 0x2, 0x1d, 0x1d, 0x1f, 
    0x1f, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x4, 0x2, 0x9, 0xb, 0xf, 
    0xf, 0x3, 0x2, 0x14, 0x17, 0x2, 0xea, 0x2, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x50, 0x3, 0x2, 0x2, 0x2, 0x8, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x54, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x64, 0x3, 0x2, 0x2, 0x2, 0x10, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x81, 0x3, 0x2, 0x2, 0x2, 0x18, 0x93, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xcc, 0x3, 0x2, 0x2, 0x2, 0x26, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xde, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x7, 0x10, 0x2, 
    0x2, 0x2b, 0x2d, 0x5, 0x4, 0x3, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x35, 0x5, 
    0x12, 0xa, 0x2, 0x32, 0x34, 0x7, 0x10, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x8, 0x5, 0x2, 0x3b, 0x3c, 
    0x5, 0x6, 0x4, 0x2, 0x3c, 0x3f, 0x7, 0x8, 0x2, 0x2, 0x3d, 0x40, 0x5, 
    0x24, 0x13, 0x2, 0x3e, 0x40, 0x5, 0xa, 0x6, 0x2, 0x3f, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x42, 0x5, 0x8, 0x5, 0x2, 0x42, 0x43, 0x7, 0x21, 0x2, 0x2, 
    0x43, 0x48, 0x5, 0x6, 0x4, 0x2, 0x44, 0x45, 0x7, 0x1e, 0x2, 0x2, 0x45, 
    0x46, 0x5, 0xc, 0x7, 0x2, 0x46, 0x47, 0x7, 0x1f, 0x2, 0x2, 0x47, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x44, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x8, 
    0x2, 0x2, 0x4b, 0x4c, 0x7, 0x10, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0xe, 0x8, 
    0x2, 0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x7, 0x28, 0x2, 0x2, 0x51, 0x7, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x9, 0x2, 0x2, 0x2, 0x53, 0x9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x9, 
    0x3, 0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5b, 0x7, 0x9, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x19, 0x2, 0x2, 0x58, 0x5a, 0x7, 0x9, 0x2, 
    0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 
    0x7, 0x11, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x10, 0x9, 0x2, 0x60, 0x61, 0x7, 
    0x10, 0x2, 0x2, 0x61, 0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6c, 0x5, 0x24, 0x13, 0x2, 0x68, 
    0x69, 0x7, 0x19, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x24, 0x13, 0x2, 0x6a, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x13, 0x2, 
    0x2, 0x70, 0x72, 0x5, 0x14, 0xb, 0x2, 0x71, 0x73, 0x5, 0x1c, 0xf, 0x2, 
    0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x1a, 0x2, 0x2, 0x75, 0x7c, 
    0x7, 0x10, 0x2, 0x2, 0x76, 0x7b, 0x5, 0x16, 0xc, 0x2, 0x77, 0x7b, 0x7, 
    0x10, 0x2, 0x2, 0x78, 0x79, 0x7, 0x11, 0x2, 0x2, 0x79, 0x7b, 0x7, 0x10, 
    0x2, 0x2, 0x7a, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 
    0x9, 0x4, 0x2, 0x2, 0x80, 0x15, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x7, 
    0x11, 0x2, 0x2, 0x82, 0x85, 0x5, 0x18, 0xd, 0x2, 0x83, 0x85, 0x5, 0x1a, 
    0xe, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x5, 0x1c, 0xf, 0x2, 
    0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x7, 0x20, 0x2, 0x2, 0x8a, 0x8c, 
    0x9, 0x5, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0x22, 
    0x12, 0x2, 0x8e, 0x90, 0x9, 0x6, 0x2, 0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x92, 0x7, 0x10, 0x2, 0x2, 0x92, 0x17, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0x94, 0x7, 0x28, 0x2, 0x2, 0x94, 0x19, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 
    0x7, 0x27, 0x2, 0x2, 0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x97, 0xa0, 0x7, 
    0x1c, 0x2, 0x2, 0x98, 0x9d, 0x5, 0x20, 0x11, 0x2, 0x99, 0x9a, 0x7, 0x19, 
    0x2, 0x2, 0x9a, 0x9c, 0x5, 0x20, 0x11, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa7, 0x5, 
    0x1e, 0x10, 0x2, 0xa3, 0xa4, 0x7, 0x19, 0x2, 0x2, 0xa4, 0xa6, 0x5, 0x1e, 
    0x10, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 0x1d, 0x2, 0x2, 0xad, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x28, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x8, 
    0x2, 0x2, 0xb0, 0xb1, 0x5, 0x20, 0x11, 0x2, 0xb1, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb5, 0x5, 0xa, 0x6, 0x2, 0xb3, 0xb5, 0x5, 0x24, 0x13, 0x2, 
    0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xbb, 0x7, 0x9, 0x2, 0x2, 0xb7, 0xb8, 
    0x7, 0x19, 0x2, 0x2, 0xb8, 0xba, 0x7, 0x9, 0x2, 0x2, 0xb9, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x8, 0x13, 0x1, 0x2, 
    0xbf, 0xc0, 0x7, 0x1c, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x24, 0x13, 0x2, 0xc1, 
    0xc2, 0x7, 0x1d, 0x2, 0x2, 0xc2, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 
    0x9, 0x7, 0x2, 0x2, 0xc4, 0xcd, 0x5, 0x24, 0x13, 0x9, 0xc5, 0xc6, 0x5, 
    0x28, 0x15, 0x2, 0xc6, 0xc7, 0x7, 0x1c, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x24, 
    0x13, 0x2, 0xc8, 0xc9, 0x7, 0x1d, 0x2, 0x2, 0xc9, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xcd, 0x5, 0x26, 0x14, 0x2, 0xcb, 0xcd, 0x7, 0x28, 0x2, 0x2, 
    0xcc, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0xc, 
    0x8, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x7, 0x2, 0x2, 0xd0, 0xd8, 0x5, 0x24, 
    0x13, 0x8, 0xd1, 0xd2, 0xc, 0x7, 0x2, 0x2, 0xd2, 0xd3, 0x9, 0x8, 0x2, 
    0x2, 0xd3, 0xd8, 0x5, 0x24, 0x13, 0x8, 0xd4, 0xd5, 0xc, 0x6, 0x2, 0x2, 
    0xd5, 0xd6, 0x9, 0x7, 0x2, 0x2, 0xd6, 0xd8, 0x5, 0x24, 0x13, 0x7, 0xd7, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x9, 0x9, 0x2, 
    0x2, 0xdd, 0x27, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x9, 0xa, 0x2, 0x2, 
    0xdf, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x2c, 0x2e, 0x35, 0x3f, 0x48, 
    0x4e, 0x5b, 0x64, 0x6c, 0x72, 0x7a, 0x7c, 0x84, 0x87, 0x8b, 0x8f, 0x9d, 
    0xa0, 0xa7, 0xaa, 0xb4, 0xbb, 0xcc, 0xd7, 0xd9, 
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
