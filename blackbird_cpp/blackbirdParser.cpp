
// Generated from blackbird.g4 by ANTLR 4.9.2


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

blackbirdParser::MetadatablockContext* blackbirdParser::StartContext::metadatablock() {
  return getRuleContext<blackbirdParser::MetadatablockContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(70);
      match(blackbirdParser::NEWLINE);
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    metadatablock();
    setState(80);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(77);
        match(blackbirdParser::NEWLINE); 
      }
      setState(82);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(83);
    program();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(84);
      match(blackbirdParser::NEWLINE);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(blackbirdParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetadatablockContext ------------------------------------------------------------------

blackbirdParser::MetadatablockContext::MetadatablockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::DeclarenameContext* blackbirdParser::MetadatablockContext::declarename() {
  return getRuleContext<blackbirdParser::DeclarenameContext>(0);
}

blackbirdParser::VersionContext* blackbirdParser::MetadatablockContext::version() {
  return getRuleContext<blackbirdParser::VersionContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::MetadatablockContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::MetadatablockContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

blackbirdParser::TargetContext* blackbirdParser::MetadatablockContext::target() {
  return getRuleContext<blackbirdParser::TargetContext>(0);
}

blackbirdParser::DeclaretypeContext* blackbirdParser::MetadatablockContext::declaretype() {
  return getRuleContext<blackbirdParser::DeclaretypeContext>(0);
}

std::vector<blackbirdParser::IncludeContext *> blackbirdParser::MetadatablockContext::include() {
  return getRuleContexts<blackbirdParser::IncludeContext>();
}

blackbirdParser::IncludeContext* blackbirdParser::MetadatablockContext::include(size_t i) {
  return getRuleContext<blackbirdParser::IncludeContext>(i);
}


size_t blackbirdParser::MetadatablockContext::getRuleIndex() const {
  return blackbirdParser::RuleMetadatablock;
}


antlrcpp::Any blackbirdParser::MetadatablockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMetadatablock(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::MetadatablockContext* blackbirdParser::metadatablock() {
  MetadatablockContext *_localctx = _tracker.createInstance<MetadatablockContext>(_ctx, getState());
  enterRule(_localctx, 2, blackbirdParser::RuleMetadatablock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(92);
    declarename();
    setState(94); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(93);
      match(blackbirdParser::NEWLINE);
      setState(96); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == blackbirdParser::NEWLINE);
    setState(98);
    version();
    setState(105);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(100); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(99);
        match(blackbirdParser::NEWLINE);
        setState(102); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == blackbirdParser::NEWLINE);
      setState(104);
      target();
      break;
    }

    default:
      break;
    }
    setState(113);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(108); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(107);
        match(blackbirdParser::NEWLINE);
        setState(110); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == blackbirdParser::NEWLINE);
      setState(112);
      declaretype();
      break;
    }

    default:
      break;
    }
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(117);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case blackbirdParser::NEWLINE: {
            setState(115);
            match(blackbirdParser::NEWLINE);
            break;
          }

          case blackbirdParser::INCLUDE: {
            setState(116);
            dynamic_cast<MetadatablockContext *>(_localctx)->includeContext = include();
            dynamic_cast<MetadatablockContext *>(_localctx)->include_list.push_back(dynamic_cast<MetadatablockContext *>(_localctx)->includeContext);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarenameContext ------------------------------------------------------------------

blackbirdParser::DeclarenameContext::DeclarenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeclarenameContext::PROGNAME() {
  return getToken(blackbirdParser::PROGNAME, 0);
}

blackbirdParser::ProgramnameContext* blackbirdParser::DeclarenameContext::programname() {
  return getRuleContext<blackbirdParser::ProgramnameContext>(0);
}


size_t blackbirdParser::DeclarenameContext::getRuleIndex() const {
  return blackbirdParser::RuleDeclarename;
}


antlrcpp::Any blackbirdParser::DeclarenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDeclarename(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeclarenameContext* blackbirdParser::declarename() {
  DeclarenameContext *_localctx = _tracker.createInstance<DeclarenameContext>(_ctx, getState());
  enterRule(_localctx, 4, blackbirdParser::RuleDeclarename);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(blackbirdParser::PROGNAME);
    setState(123);
    programname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramnameContext ------------------------------------------------------------------

blackbirdParser::ProgramnameContext::ProgramnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ProgramnameContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::ProgramnameContext::getRuleIndex() const {
  return blackbirdParser::RuleProgramname;
}


antlrcpp::Any blackbirdParser::ProgramnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgramname(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramnameContext* blackbirdParser::programname() {
  ProgramnameContext *_localctx = _tracker.createInstance<ProgramnameContext>(_ctx, getState());
  enterRule(_localctx, 6, blackbirdParser::RuleProgramname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

blackbirdParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VersionContext::VERSION() {
  return getToken(blackbirdParser::VERSION, 0);
}

blackbirdParser::VersionnumberContext* blackbirdParser::VersionContext::versionnumber() {
  return getRuleContext<blackbirdParser::VersionnumberContext>(0);
}


size_t blackbirdParser::VersionContext::getRuleIndex() const {
  return blackbirdParser::RuleVersion;
}


antlrcpp::Any blackbirdParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VersionContext* blackbirdParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 8, blackbirdParser::RuleVersion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(blackbirdParser::VERSION);
    setState(128);
    versionnumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionnumberContext ------------------------------------------------------------------

blackbirdParser::VersionnumberContext::VersionnumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VersionnumberContext::FLOAT() {
  return getToken(blackbirdParser::FLOAT, 0);
}


size_t blackbirdParser::VersionnumberContext::getRuleIndex() const {
  return blackbirdParser::RuleVersionnumber;
}


antlrcpp::Any blackbirdParser::VersionnumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVersionnumber(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VersionnumberContext* blackbirdParser::versionnumber() {
  VersionnumberContext *_localctx = _tracker.createInstance<VersionnumberContext>(_ctx, getState());
  enterRule(_localctx, 10, blackbirdParser::RuleVersionnumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(blackbirdParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

blackbirdParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::TargetContext::TARGET() {
  return getToken(blackbirdParser::TARGET, 0);
}

blackbirdParser::DeviceContext* blackbirdParser::TargetContext::device() {
  return getRuleContext<blackbirdParser::DeviceContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::TargetContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}


size_t blackbirdParser::TargetContext::getRuleIndex() const {
  return blackbirdParser::RuleTarget;
}


antlrcpp::Any blackbirdParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::TargetContext* blackbirdParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 12, blackbirdParser::RuleTarget);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(blackbirdParser::TARGET);
    setState(133);
    device();
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(134);
      arguments();
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
  enterRule(_localctx, 14, blackbirdParser::RuleDevice);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
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

//----------------- DeclaretypeContext ------------------------------------------------------------------

blackbirdParser::DeclaretypeContext::DeclaretypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeclaretypeContext::PROGTYPE() {
  return getToken(blackbirdParser::PROGTYPE, 0);
}

blackbirdParser::ProgramtypeContext* blackbirdParser::DeclaretypeContext::programtype() {
  return getRuleContext<blackbirdParser::ProgramtypeContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::DeclaretypeContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}


size_t blackbirdParser::DeclaretypeContext::getRuleIndex() const {
  return blackbirdParser::RuleDeclaretype;
}


antlrcpp::Any blackbirdParser::DeclaretypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDeclaretype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeclaretypeContext* blackbirdParser::declaretype() {
  DeclaretypeContext *_localctx = _tracker.createInstance<DeclaretypeContext>(_ctx, getState());
  enterRule(_localctx, 16, blackbirdParser::RuleDeclaretype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(blackbirdParser::PROGTYPE);
    setState(140);
    programtype();
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(141);
      arguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramtypeContext ------------------------------------------------------------------

blackbirdParser::ProgramtypeContext::ProgramtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ProgramtypeContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::ProgramtypeContext::getRuleIndex() const {
  return blackbirdParser::RuleProgramtype;
}


antlrcpp::Any blackbirdParser::ProgramtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgramtype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramtypeContext* blackbirdParser::programtype() {
  ProgramtypeContext *_localctx = _tracker.createInstance<ProgramtypeContext>(_ctx, getState());
  enterRule(_localctx, 18, blackbirdParser::RuleProgramtype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

blackbirdParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::IncludeContext::INCLUDE() {
  return getToken(blackbirdParser::INCLUDE, 0);
}

tree::TerminalNode* blackbirdParser::IncludeContext::STR() {
  return getToken(blackbirdParser::STR, 0);
}


size_t blackbirdParser::IncludeContext::getRuleIndex() const {
  return blackbirdParser::RuleInclude;
}


antlrcpp::Any blackbirdParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::IncludeContext* blackbirdParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 20, blackbirdParser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(blackbirdParser::INCLUDE);
    setState(147);
    match(blackbirdParser::STR);
   
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

std::vector<tree::TerminalNode *> blackbirdParser::ProgramContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<blackbirdParser::ForloopContext *> blackbirdParser::ProgramContext::forloop() {
  return getRuleContexts<blackbirdParser::ForloopContext>();
}

blackbirdParser::ForloopContext* blackbirdParser::ProgramContext::forloop(size_t i) {
  return getRuleContext<blackbirdParser::ForloopContext>(i);
}

std::vector<blackbirdParser::ExpressionvarContext *> blackbirdParser::ProgramContext::expressionvar() {
  return getRuleContexts<blackbirdParser::ExpressionvarContext>();
}

blackbirdParser::ExpressionvarContext* blackbirdParser::ProgramContext::expressionvar(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionvarContext>(i);
}

std::vector<blackbirdParser::ArrayvarContext *> blackbirdParser::ProgramContext::arrayvar() {
  return getRuleContexts<blackbirdParser::ArrayvarContext>();
}

blackbirdParser::ArrayvarContext* blackbirdParser::ProgramContext::arrayvar(size_t i) {
  return getRuleContext<blackbirdParser::ArrayvarContext>(i);
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
  enterRule(_localctx, 22, blackbirdParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(154);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(149);
          match(blackbirdParser::NEWLINE);
          break;
        }

        case 2: {
          setState(150);
          dynamic_cast<ProgramContext *>(_localctx)->forloopContext = forloop();
          dynamic_cast<ProgramContext *>(_localctx)->for_list.push_back(dynamic_cast<ProgramContext *>(_localctx)->forloopContext);
          break;
        }

        case 3: {
          setState(151);
          dynamic_cast<ProgramContext *>(_localctx)->expressionvarContext = expressionvar();
          dynamic_cast<ProgramContext *>(_localctx)->var_list.push_back(dynamic_cast<ProgramContext *>(_localctx)->expressionvarContext);
          break;
        }

        case 4: {
          setState(152);
          dynamic_cast<ProgramContext *>(_localctx)->arrayvarContext = arrayvar();
          dynamic_cast<ProgramContext *>(_localctx)->array_list.push_back(dynamic_cast<ProgramContext *>(_localctx)->arrayvarContext);
          break;
        }

        case 5: {
          setState(153);
          dynamic_cast<ProgramContext *>(_localctx)->statementContext = statement();
          dynamic_cast<ProgramContext *>(_localctx)->statement_list.push_back(dynamic_cast<ProgramContext *>(_localctx)->statementContext);
          break;
        }

        default:
          break;
        } 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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
  enterRule(_localctx, 24, blackbirdParser::RuleExpressionvar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    vartype();
    setState(160);
    name();
    setState(161);
    match(blackbirdParser::ASSIGN);
    setState(164);
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
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(162);
        expression(0);
        break;
      }

      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(163);
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

blackbirdParser::ParameterContext* blackbirdParser::ArrayvarContext::parameter() {
  return getRuleContext<blackbirdParser::ParameterContext>(0);
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
  enterRule(_localctx, 26, blackbirdParser::RuleArrayvar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    vartype();
    setState(167);
    match(blackbirdParser::TYPE_ARRAY);
    setState(168);
    name();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LSQBRAC) {
      setState(169);
      match(blackbirdParser::LSQBRAC);
      setState(170);
      shape();
      setState(171);
      match(blackbirdParser::RSQBRAC);
    }
    setState(175);
    match(blackbirdParser::ASSIGN);
    setState(176);
    match(blackbirdParser::NEWLINE);
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::EOF:
      case blackbirdParser::FOR:
      case blackbirdParser::NEWLINE:
      case blackbirdParser::TAB:
      case blackbirdParser::TYPE_ARRAY:
      case blackbirdParser::TYPE_FLOAT:
      case blackbirdParser::TYPE_COMPLEX:
      case blackbirdParser::TYPE_INT:
      case blackbirdParser::TYPE_STR:
      case blackbirdParser::TYPE_BOOL:
      case blackbirdParser::MEASURE:
      case blackbirdParser::NAME: {
        setState(177);
        arrayval();
        break;
      }

      case blackbirdParser::LBRACE: {
        setState(178);
        parameter();
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

//----------------- NameContext ------------------------------------------------------------------

blackbirdParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::InvalidContext* blackbirdParser::NameContext::invalid() {
  return getRuleContext<blackbirdParser::InvalidContext>(0);
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
  enterRule(_localctx, 28, blackbirdParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PROGNAME:
      case blackbirdParser::VERSION:
      case blackbirdParser::TARGET:
      case blackbirdParser::PROGTYPE:
      case blackbirdParser::REGREF: {
        setState(181);
        invalid();
        break;
      }

      case blackbirdParser::NAME: {
        setState(182);
        match(blackbirdParser::NAME);
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

//----------------- InvalidContext ------------------------------------------------------------------

blackbirdParser::InvalidContext::InvalidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::InvalidContext::REGREF() {
  return getToken(blackbirdParser::REGREF, 0);
}

blackbirdParser::ReservedContext* blackbirdParser::InvalidContext::reserved() {
  return getRuleContext<blackbirdParser::ReservedContext>(0);
}


size_t blackbirdParser::InvalidContext::getRuleIndex() const {
  return blackbirdParser::RuleInvalid;
}


antlrcpp::Any blackbirdParser::InvalidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitInvalid(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::InvalidContext* blackbirdParser::invalid() {
  InvalidContext *_localctx = _tracker.createInstance<InvalidContext>(_ctx, getState());
  enterRule(_localctx, 30, blackbirdParser::RuleInvalid);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::REGREF: {
        setState(185);
        match(blackbirdParser::REGREF);
        break;
      }

      case blackbirdParser::PROGNAME:
      case blackbirdParser::VERSION:
      case blackbirdParser::TARGET:
      case blackbirdParser::PROGTYPE: {
        setState(186);
        reserved();
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

//----------------- ReservedContext ------------------------------------------------------------------

blackbirdParser::ReservedContext::ReservedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ReservedContext::PROGNAME() {
  return getToken(blackbirdParser::PROGNAME, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::VERSION() {
  return getToken(blackbirdParser::VERSION, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::TARGET() {
  return getToken(blackbirdParser::TARGET, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::PROGTYPE() {
  return getToken(blackbirdParser::PROGTYPE, 0);
}


size_t blackbirdParser::ReservedContext::getRuleIndex() const {
  return blackbirdParser::RuleReserved;
}


antlrcpp::Any blackbirdParser::ReservedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitReserved(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ReservedContext* blackbirdParser::reserved() {
  ReservedContext *_localctx = _tracker.createInstance<ReservedContext>(_ctx, getState());
  enterRule(_localctx, 32, blackbirdParser::RuleReserved);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::PROGNAME)
      | (1ULL << blackbirdParser::VERSION)
      | (1ULL << blackbirdParser::TARGET)
      | (1ULL << blackbirdParser::PROGTYPE))) != 0))) {
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
  enterRule(_localctx, 34, blackbirdParser::RuleVartype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
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
  enterRule(_localctx, 36, blackbirdParser::RuleNonnumeric);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
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
  enterRule(_localctx, 38, blackbirdParser::RuleShape);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(blackbirdParser::INT);
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(196);
      match(blackbirdParser::COMMA);
      setState(197);
      match(blackbirdParser::INT);
      setState(202);
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
  enterRule(_localctx, 40, blackbirdParser::RuleArrayval);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::TAB) {
      setState(203);
      match(blackbirdParser::TAB);
      setState(204);
      dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext = arrayrow();
      dynamic_cast<ArrayvalContext *>(_localctx)->row_list.push_back(dynamic_cast<ArrayvalContext *>(_localctx)->arrayrowContext);
      setState(205);
      match(blackbirdParser::NEWLINE);
      setState(211);
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
  enterRule(_localctx, 42, blackbirdParser::RuleArrayrow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    expression(0);
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(213);
      match(blackbirdParser::COMMA);
      setState(214);
      expression(0);
      setState(219);
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

//----------------- StatementContext ------------------------------------------------------------------

blackbirdParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::StatementContext::APPLY() {
  return getToken(blackbirdParser::APPLY, 0);
}

blackbirdParser::ArrayrowContext* blackbirdParser::StatementContext::arrayrow() {
  return getRuleContext<blackbirdParser::ArrayrowContext>(0);
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

std::vector<tree::TerminalNode *> blackbirdParser::StatementContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::StatementContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
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
  enterRule(_localctx, 44, blackbirdParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::NAME: {
        setState(220);
        operation();
        break;
      }

      case blackbirdParser::MEASURE: {
        setState(221);
        measure();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(224);
      arguments();
    }
    setState(227);
    match(blackbirdParser::APPLY);
    setState(229);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(228);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::LBRAC

      || _la == blackbirdParser::LSQBRAC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
    setState(231);
    arrayrow();
    setState(233);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::RBRAC

    || _la == blackbirdParser::RSQBRAC) {
      setState(232);
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
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(235);
        match(blackbirdParser::NEWLINE); 
      }
      setState(240);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
   
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
  enterRule(_localctx, 46, blackbirdParser::RuleOperation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
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
  enterRule(_localctx, 48, blackbirdParser::RuleMeasure);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(blackbirdParser::MEASURE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForloopContext ------------------------------------------------------------------

blackbirdParser::ForloopContext::ForloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ForloopContext::FOR() {
  return getToken(blackbirdParser::FOR, 0);
}

blackbirdParser::VartypeContext* blackbirdParser::ForloopContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::IN() {
  return getToken(blackbirdParser::IN, 0);
}

blackbirdParser::RangevalContext* blackbirdParser::ForloopContext::rangeval() {
  return getRuleContext<blackbirdParser::RangevalContext>(0);
}

blackbirdParser::VallistContext* blackbirdParser::ForloopContext::vallist() {
  return getRuleContext<blackbirdParser::VallistContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::ForloopContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ForloopContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ForloopContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ForloopContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}

std::vector<blackbirdParser::StatementContext *> blackbirdParser::ForloopContext::statement() {
  return getRuleContexts<blackbirdParser::StatementContext>();
}

blackbirdParser::StatementContext* blackbirdParser::ForloopContext::statement(size_t i) {
  return getRuleContext<blackbirdParser::StatementContext>(i);
}

tree::TerminalNode* blackbirdParser::ForloopContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::ForloopContext::getRuleIndex() const {
  return blackbirdParser::RuleForloop;
}


antlrcpp::Any blackbirdParser::ForloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitForloop(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ForloopContext* blackbirdParser::forloop() {
  ForloopContext *_localctx = _tracker.createInstance<ForloopContext>(_ctx, getState());
  enterRule(_localctx, 50, blackbirdParser::RuleForloop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(blackbirdParser::FOR);
    setState(246);
    vartype();
    setState(247);
    match(blackbirdParser::NAME);
    setState(248);
    match(blackbirdParser::IN);
    setState(257);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(249);
      rangeval();
      break;
    }

    case 2: {
      setState(251);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
      case 1: {
        setState(250);
        _la = _input->LA(1);
        if (!(_la == blackbirdParser::LBRAC

        || _la == blackbirdParser::LSQBRAC)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      default:
        break;
      }
      setState(253);
      vallist();
      setState(255);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == blackbirdParser::RBRAC

      || _la == blackbirdParser::RSQBRAC) {
        setState(254);
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
      break;
    }

    default:
      break;
    }
    setState(262); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(259);
              match(blackbirdParser::NEWLINE);
              setState(260);
              match(blackbirdParser::TAB);
              setState(261);
              dynamic_cast<ForloopContext *>(_localctx)->statementContext = statement();
              dynamic_cast<ForloopContext *>(_localctx)->statement_list.push_back(dynamic_cast<ForloopContext *>(_localctx)->statementContext);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(264); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

std::vector<tree::TerminalNode *> blackbirdParser::ArgumentsContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
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
  enterRule(_localctx, 52, blackbirdParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(blackbirdParser::LBRAC);
    setState(275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(267);
      dynamic_cast<ArgumentsContext *>(_localctx)->valContext = val();
      dynamic_cast<ArgumentsContext *>(_localctx)->val_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->valContext);
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(268);
          match(blackbirdParser::COMMA);
          setState(269);
          dynamic_cast<ArgumentsContext *>(_localctx)->valContext = val();
          dynamic_cast<ArgumentsContext *>(_localctx)->val_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->valContext); 
        }
        setState(274);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }
      break;
    }

    default:
      break;
    }
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::COMMA) {
      setState(277);
      match(blackbirdParser::COMMA);
    }
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::NAME) {
      setState(280);
      dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
      dynamic_cast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext);
      setState(285);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(281);
        match(blackbirdParser::COMMA);
        setState(282);
        dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
        dynamic_cast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(dynamic_cast<ArgumentsContext *>(_localctx)->kwargContext);
        setState(287);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(290);
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

tree::TerminalNode* blackbirdParser::KwargContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::KwargContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}

blackbirdParser::VallistContext* blackbirdParser::KwargContext::vallist() {
  return getRuleContext<blackbirdParser::VallistContext>(0);
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
  enterRule(_localctx, 54, blackbirdParser::RuleKwarg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(blackbirdParser::NAME);
    setState(293);
    match(blackbirdParser::ASSIGN);
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::STR:
      case blackbirdParser::BOOL:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(294);
        val();
        break;
      }

      case blackbirdParser::LSQBRAC: {
        setState(295);
        match(blackbirdParser::LSQBRAC);
        setState(297);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << blackbirdParser::PLUS)
          | (1ULL << blackbirdParser::MINUS)
          | (1ULL << blackbirdParser::INT)
          | (1ULL << blackbirdParser::FLOAT)
          | (1ULL << blackbirdParser::COMPLEX)
          | (1ULL << blackbirdParser::STR)
          | (1ULL << blackbirdParser::BOOL)
          | (1ULL << blackbirdParser::PI)
          | (1ULL << blackbirdParser::SQRT)
          | (1ULL << blackbirdParser::SIN)
          | (1ULL << blackbirdParser::COS)
          | (1ULL << blackbirdParser::TAN)
          | (1ULL << blackbirdParser::ARCSIN)
          | (1ULL << blackbirdParser::ARCCOS)
          | (1ULL << blackbirdParser::ARCTAN)
          | (1ULL << blackbirdParser::SINH)
          | (1ULL << blackbirdParser::COSH)
          | (1ULL << blackbirdParser::TANH)
          | (1ULL << blackbirdParser::ARCSINH)
          | (1ULL << blackbirdParser::ARCCOSH)
          | (1ULL << blackbirdParser::ARCTANH)
          | (1ULL << blackbirdParser::EXP)
          | (1ULL << blackbirdParser::LOG)
          | (1ULL << blackbirdParser::LBRAC)
          | (1ULL << blackbirdParser::LBRACE)
          | (1ULL << blackbirdParser::REGREF)
          | (1ULL << blackbirdParser::NAME))) != 0)) {
          setState(296);
          vallist();
        }
        setState(299);
        match(blackbirdParser::RSQBRAC);
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
  enterRule(_localctx, 56, blackbirdParser::RuleVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(302);
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
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(303);
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

//----------------- VallistContext ------------------------------------------------------------------

blackbirdParser::VallistContext::VallistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<blackbirdParser::ValContext *> blackbirdParser::VallistContext::val() {
  return getRuleContexts<blackbirdParser::ValContext>();
}

blackbirdParser::ValContext* blackbirdParser::VallistContext::val(size_t i) {
  return getRuleContext<blackbirdParser::ValContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::VallistContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::VallistContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::VallistContext::getRuleIndex() const {
  return blackbirdParser::RuleVallist;
}


antlrcpp::Any blackbirdParser::VallistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVallist(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VallistContext* blackbirdParser::vallist() {
  VallistContext *_localctx = _tracker.createInstance<VallistContext>(_ctx, getState());
  enterRule(_localctx, 58, blackbirdParser::RuleVallist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    val();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(307);
      match(blackbirdParser::COMMA);
      setState(308);
      val();
      setState(313);
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

//----------------- RangevalContext ------------------------------------------------------------------

blackbirdParser::RangevalContext::RangevalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::RangevalContext::INT() {
  return getTokens(blackbirdParser::INT);
}

tree::TerminalNode* blackbirdParser::RangevalContext::INT(size_t i) {
  return getToken(blackbirdParser::INT, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::RangevalContext::COLON() {
  return getTokens(blackbirdParser::COLON);
}

tree::TerminalNode* blackbirdParser::RangevalContext::COLON(size_t i) {
  return getToken(blackbirdParser::COLON, i);
}


size_t blackbirdParser::RangevalContext::getRuleIndex() const {
  return blackbirdParser::RuleRangeval;
}


antlrcpp::Any blackbirdParser::RangevalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitRangeval(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::RangevalContext* blackbirdParser::rangeval() {
  RangevalContext *_localctx = _tracker.createInstance<RangevalContext>(_ctx, getState());
  enterRule(_localctx, 60, blackbirdParser::RuleRangeval);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(blackbirdParser::INT);
    setState(315);
    match(blackbirdParser::COLON);
    setState(316);
    match(blackbirdParser::INT);
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::COLON) {
      setState(317);
      match(blackbirdParser::COLON);
      setState(318);
      match(blackbirdParser::INT);
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

//----------------- ParameterLabelContext ------------------------------------------------------------------

blackbirdParser::ParameterContext* blackbirdParser::ParameterLabelContext::parameter() {
  return getRuleContext<blackbirdParser::ParameterContext>(0);
}

blackbirdParser::ParameterLabelContext::ParameterLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any blackbirdParser::ParameterLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitParameterLabel(this);
  else
    return visitor->visitChildren(this);
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

tree::TerminalNode* blackbirdParser::VariableLabelContext::REGREF() {
  return getToken(blackbirdParser::REGREF, 0);
}

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
//----------------- ArrayIdxLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ArrayIdxLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}

blackbirdParser::ArrayIdxLabelContext::ArrayIdxLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any blackbirdParser::ArrayIdxLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayIdxLabel(this);
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
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, blackbirdParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BracketsLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(322);
      match(blackbirdParser::LBRAC);
      setState(323);
      expression(0);
      setState(324);
      match(blackbirdParser::RBRAC);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SignLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(326);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::PLUS

      || _la == blackbirdParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(327);
      expression(9);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(328);
      function();
      setState(329);
      match(blackbirdParser::LBRAC);
      setState(330);
      expression(0);
      setState(331);
      match(blackbirdParser::RBRAC);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NumberLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(333);
      number();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VariableLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(334);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::REGREF

      || _la == blackbirdParser::NAME)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayIdxLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(335);
      match(blackbirdParser::NAME);
      setState(336);
      match(blackbirdParser::LSQBRAC);
      setState(337);
      expression(0);
      setState(338);
      match(blackbirdParser::RSQBRAC);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParameterLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(340);
      parameter();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(354);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(352);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(343);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(344);
          match(blackbirdParser::PWR);
          setState(345);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(346);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(347);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::TIMES

          || _la == blackbirdParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(348);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(349);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(350);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::PLUS

          || _la == blackbirdParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(351);
          expression(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

blackbirdParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ParameterContext::LBRACE() {
  return getToken(blackbirdParser::LBRACE, 0);
}

tree::TerminalNode* blackbirdParser::ParameterContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ParameterContext::RBRACE() {
  return getToken(blackbirdParser::RBRACE, 0);
}


size_t blackbirdParser::ParameterContext::getRuleIndex() const {
  return blackbirdParser::RuleParameter;
}


antlrcpp::Any blackbirdParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ParameterContext* blackbirdParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 64, blackbirdParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(blackbirdParser::LBRACE);
    setState(358);
    match(blackbirdParser::NAME);
    setState(359);
    match(blackbirdParser::RBRACE);
   
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
  enterRule(_localctx, 66, blackbirdParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
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

tree::TerminalNode* blackbirdParser::FunctionContext::TAN() {
  return getToken(blackbirdParser::TAN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCSIN() {
  return getToken(blackbirdParser::ARCSIN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCCOS() {
  return getToken(blackbirdParser::ARCCOS, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCTAN() {
  return getToken(blackbirdParser::ARCTAN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::SINH() {
  return getToken(blackbirdParser::SINH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::COSH() {
  return getToken(blackbirdParser::COSH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::TANH() {
  return getToken(blackbirdParser::TANH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCSINH() {
  return getToken(blackbirdParser::ARCSINH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCCOSH() {
  return getToken(blackbirdParser::ARCCOSH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCTANH() {
  return getToken(blackbirdParser::ARCTANH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::SQRT() {
  return getToken(blackbirdParser::SQRT, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::LOG() {
  return getToken(blackbirdParser::LOG, 0);
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
  enterRule(_localctx, 68, blackbirdParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << blackbirdParser::SQRT)
      | (1ULL << blackbirdParser::SIN)
      | (1ULL << blackbirdParser::COS)
      | (1ULL << blackbirdParser::TAN)
      | (1ULL << blackbirdParser::ARCSIN)
      | (1ULL << blackbirdParser::ARCCOS)
      | (1ULL << blackbirdParser::ARCTAN)
      | (1ULL << blackbirdParser::SINH)
      | (1ULL << blackbirdParser::COSH)
      | (1ULL << blackbirdParser::TANH)
      | (1ULL << blackbirdParser::ARCSINH)
      | (1ULL << blackbirdParser::ARCCOSH)
      | (1ULL << blackbirdParser::ARCTANH)
      | (1ULL << blackbirdParser::EXP)
      | (1ULL << blackbirdParser::LOG))) != 0))) {
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
    case 31: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool blackbirdParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);

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
  "start", "metadatablock", "declarename", "programname", "version", "versionnumber", 
  "target", "device", "declaretype", "programtype", "include", "program", 
  "expressionvar", "arrayvar", "name", "invalid", "reserved", "vartype", 
  "nonnumeric", "shape", "arrayval", "arrayrow", "statement", "operation", 
  "measure", "forloop", "arguments", "kwarg", "val", "vallist", "rangeval", 
  "expression", "parameter", "number", "function"
};

std::vector<std::string> blackbirdParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'", "'**'", "'='", "'for'", "'in'", "", "", 
  "", "", "", "", "'pi'", "", "", "", "'name'", "'version'", "'target'", 
  "'type'", "'include'", "'sqrt'", "'sin'", "'cos'", "'tan'", "'arcsin'", 
  "'arccos'", "'arctan'", "'sinh'", "'cosh'", "'tanh'", "'arcsinh'", "'arccosh'", 
  "'arctanh'", "'exp'", "'log'", "'.'", "','", "':'", "'\"'", "'('", "')'", 
  "'['", "']'", "'{'", "'}'", "'|'", "'array'", "'float'", "'complex'", 
  "'int'", "'str'", "'bool'"
};

std::vector<std::string> blackbirdParser::_symbolicNames = {
  "", "PLUS", "MINUS", "TIMES", "DIVIDE", "PWR", "ASSIGN", "FOR", "IN", 
  "INT", "FLOAT", "COMPLEX", "STR", "BOOL", "SEQUENCE", "PI", "NEWLINE", 
  "TAB", "SPACE", "PROGNAME", "VERSION", "TARGET", "PROGTYPE", "INCLUDE", 
  "SQRT", "SIN", "COS", "TAN", "ARCSIN", "ARCCOS", "ARCTAN", "SINH", "COSH", 
  "TANH", "ARCSINH", "ARCCOSH", "ARCTANH", "EXP", "LOG", "PERIOD", "COMMA", 
  "COLON", "QUOTE", "LBRAC", "RBRAC", "LSQBRAC", "RSQBRAC", "LBRACE", "RBRACE", 
  "APPLY", "TYPE_ARRAY", "TYPE_FLOAT", "TYPE_COMPLEX", "TYPE_INT", "TYPE_STR", 
  "TYPE_BOOL", "REGREF", "MEASURE", "NAME", "DEVICE", "COMMENT", "ANY"
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x3f, 0x170, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x7, 0x2, 0x4a, 0xa, 0x2, 
       0xc, 0x2, 0xe, 0x2, 0x4d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
       0x51, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x54, 0xb, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x7, 0x2, 0x58, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x5b, 0xb, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x61, 0xa, 0x3, 
       0xd, 0x3, 0xe, 0x3, 0x62, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x67, 0xa, 
       0x3, 0xd, 0x3, 0xe, 0x3, 0x68, 0x3, 0x3, 0x5, 0x3, 0x6c, 0xa, 0x3, 
       0x3, 0x3, 0x6, 0x3, 0x6f, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x70, 0x3, 
       0x3, 0x5, 0x3, 0x74, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x78, 
       0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x7b, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x8a, 0xa, 
       0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
       0x91, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x9d, 
       0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xa0, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xa7, 0xa, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
       0xf, 0xb0, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
       0xf, 0xb6, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xba, 0xa, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xbe, 0xa, 0x11, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xc9, 0xa, 0x15, 0xc, 0x15, 0xe, 
       0x15, 0xcc, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x7, 0x16, 0xd2, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0xd5, 0xb, 0x16, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0xda, 0xa, 0x17, 0xc, 
       0x17, 0xe, 0x17, 0xdd, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
       0xe1, 0xa, 0x18, 0x3, 0x18, 0x5, 0x18, 0xe4, 0xa, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x5, 0x18, 0xe8, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
       0x18, 0xec, 0xa, 0x18, 0x3, 0x18, 0x7, 0x18, 0xef, 0xa, 0x18, 0xc, 
       0x18, 0xe, 0x18, 0xf2, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1b, 0x5, 0x1b, 0xfe, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 
       0x1b, 0x102, 0xa, 0x1b, 0x5, 0x1b, 0x104, 0xa, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x109, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 
       0x10a, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x111, 
       0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x114, 0xb, 0x1c, 0x5, 0x1c, 0x116, 
       0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x119, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x11e, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
       0x121, 0xb, 0x1c, 0x5, 0x1c, 0x123, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
       0x12c, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x12f, 0xa, 0x1d, 0x3, 0x1e, 
       0x3, 0x1e, 0x5, 0x1e, 0x133, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x7, 0x1f, 0x138, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x13b, 0xb, 
       0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
       0x20, 0x142, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x158, 0xa, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x163, 0xa, 0x21, 
       0xc, 0x21, 0xe, 0x21, 0x166, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x2, 0x3, 0x40, 0x25, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
       0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
       0x3e, 0x40, 0x42, 0x44, 0x46, 0x2, 0xd, 0x3, 0x2, 0x3c, 0x3d, 0x3, 
       0x2, 0x15, 0x18, 0x3, 0x2, 0x34, 0x39, 0x3, 0x2, 0xe, 0xf, 0x4, 0x2, 
       0x2d, 0x2d, 0x2f, 0x2f, 0x4, 0x2, 0x2e, 0x2e, 0x30, 0x30, 0x3, 0x2, 
       0x3, 0x4, 0x4, 0x2, 0x3a, 0x3a, 0x3c, 0x3c, 0x3, 0x2, 0x5, 0x6, 0x4, 
       0x2, 0xb, 0xd, 0x11, 0x11, 0x3, 0x2, 0x1a, 0x28, 0x2, 0x181, 0x2, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7c, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x81, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x84, 0x3, 0x2, 0x2, 0x2, 0xe, 0x86, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8d, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x92, 0x3, 0x2, 0x2, 0x2, 0x16, 0x94, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0xa8, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x20, 0xbd, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x24, 0xc1, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc5, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xd6, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf3, 0x3, 0x2, 0x2, 0x2, 
       0x32, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x34, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x36, 
       0x10c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x126, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x132, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x3e, 
       0x13c, 0x3, 0x2, 0x2, 0x2, 0x40, 0x157, 0x3, 0x2, 0x2, 0x2, 0x42, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x44, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x46, 
       0x16d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x7, 0x12, 0x2, 0x2, 0x49, 
       0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x3, 
       0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x52, 0x5, 0x4, 
       0x3, 0x2, 0x4f, 0x51, 0x7, 0x12, 0x2, 0x2, 0x50, 0x4f, 0x3, 0x2, 
       0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 
       0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x5, 0x18, 0xd, 0x2, 
       0x56, 0x58, 0x7, 0x12, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 
       0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 
       0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x2, 0x2, 0x3, 0x5d, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x6, 0x4, 0x2, 0x5f, 0x61, 0x7, 0x12, 
       0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 
       0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x6b, 0x5, 0xa, 0x6, 0x2, 0x65, 
       0x67, 0x7, 0x12, 0x2, 0x2, 0x66, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 
       0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x5, 
       0xe, 0x8, 0x2, 0x6b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x73, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0x12, 
       0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 
       0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 
       0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x5, 0x12, 0xa, 0x2, 
       0x73, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 
       0x79, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x7, 0x12, 0x2, 0x2, 0x76, 
       0x78, 0x5, 0x16, 0xc, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 
       0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 
       0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x15, 
       0x2, 0x2, 0x7d, 0x7e, 0x5, 0x8, 0x5, 0x2, 0x7e, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x7f, 0x80, 0x7, 0x3c, 0x2, 0x2, 0x80, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x81, 0x82, 0x7, 0x16, 0x2, 0x2, 0x82, 0x83, 0x5, 0xc, 0x7, 0x2, 
       0x83, 0xb, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0xc, 0x2, 0x2, 0x85, 
       0xd, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x17, 0x2, 0x2, 0x87, 0x89, 
       0x5, 0x10, 0x9, 0x2, 0x88, 0x8a, 0x5, 0x36, 0x1c, 0x2, 0x89, 0x88, 
       0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0x8b, 0x8c, 0x9, 0x2, 0x2, 0x2, 0x8c, 0x11, 0x3, 0x2, 
       0x2, 0x2, 0x8d, 0x8e, 0x7, 0x18, 0x2, 0x2, 0x8e, 0x90, 0x5, 0x14, 
       0xb, 0x2, 0x8f, 0x91, 0x5, 0x36, 0x1c, 0x2, 0x90, 0x8f, 0x3, 0x2, 
       0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x92, 0x93, 0x7, 0x3c, 0x2, 0x2, 0x93, 0x15, 0x3, 0x2, 0x2, 
       0x2, 0x94, 0x95, 0x7, 0x19, 0x2, 0x2, 0x95, 0x96, 0x7, 0xe, 0x2, 
       0x2, 0x96, 0x17, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9d, 0x7, 0x12, 0x2, 
       0x2, 0x98, 0x9d, 0x5, 0x34, 0x1b, 0x2, 0x99, 0x9d, 0x5, 0x1a, 0xe, 
       0x2, 0x9a, 0x9d, 0x5, 0x1c, 0xf, 0x2, 0x9b, 0x9d, 0x5, 0x2e, 0x18, 
       0x2, 0x9c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x98, 0x3, 0x2, 0x2, 0x2, 
       0x9c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x19, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x24, 
       0x13, 0x2, 0xa2, 0xa3, 0x5, 0x1e, 0x10, 0x2, 0xa3, 0xa6, 0x7, 0x8, 
       0x2, 0x2, 0xa4, 0xa7, 0x5, 0x40, 0x21, 0x2, 0xa5, 0xa7, 0x5, 0x26, 
       0x14, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa5, 0x3, 0x2, 
       0x2, 0x2, 0xa7, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x24, 
       0x13, 0x2, 0xa9, 0xaa, 0x7, 0x34, 0x2, 0x2, 0xaa, 0xaf, 0x5, 0x1e, 
       0x10, 0x2, 0xab, 0xac, 0x7, 0x2f, 0x2, 0x2, 0xac, 0xad, 0x5, 0x28, 
       0x15, 0x2, 0xad, 0xae, 0x7, 0x30, 0x2, 0x2, 0xae, 0xb0, 0x3, 0x2, 
       0x2, 0x2, 0xaf, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 
       0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x8, 0x2, 0x2, 
       0xb2, 0xb5, 0x7, 0x12, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x2a, 0x16, 0x2, 
       0xb4, 0xb6, 0x5, 0x42, 0x22, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 
       0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb7, 
       0xba, 0x5, 0x20, 0x11, 0x2, 0xb8, 0xba, 0x7, 0x3c, 0x2, 0x2, 0xb9, 
       0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x7, 0x3a, 0x2, 0x2, 0xbc, 0xbe, 
       0x5, 0x22, 0x12, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 
       0x3, 0x2, 0x2, 0x2, 0xbe, 0x21, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x9, 
       0x3, 0x2, 0x2, 0xc0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x9, 0x4, 
       0x2, 0x2, 0xc2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x5, 0x2, 
       0x2, 0xc4, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xca, 0x7, 0xb, 0x2, 0x2, 
       0xc6, 0xc7, 0x7, 0x2a, 0x2, 0x2, 0xc7, 0xc9, 0x7, 0xb, 0x2, 0x2, 
       0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xca, 
       0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 
       0x13, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x2c, 0x17, 0x2, 0xcf, 0xd0, 0x7, 
       0x12, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcd, 0x3, 
       0x2, 0x2, 0x2, 0xd2, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 
       0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x2b, 0x3, 0x2, 0x2, 
       0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xdb, 0x5, 0x40, 0x21, 
       0x2, 0xd7, 0xd8, 0x7, 0x2a, 0x2, 0x2, 0xd8, 0xda, 0x5, 0x40, 0x21, 
       0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 
       0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe1, 
       0x5, 0x30, 0x19, 0x2, 0xdf, 0xe1, 0x5, 0x32, 0x1a, 0x2, 0xe0, 0xde, 
       0x3, 0x2, 0x2, 0x2, 0xe0, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe3, 0x3, 
       0x2, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x36, 0x1c, 0x2, 0xe3, 0xe2, 0x3, 
       0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 
       0x2, 0x2, 0xe5, 0xe7, 0x7, 0x33, 0x2, 0x2, 0xe6, 0xe8, 0x9, 0x6, 
       0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 
       0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x2c, 0x17, 
       0x2, 0xea, 0xec, 0x9, 0x7, 0x2, 0x2, 0xeb, 0xea, 0x3, 0x2, 0x2, 0x2, 
       0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xed, 
       0xef, 0x7, 0x12, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 
       0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 
       0x3, 0x2, 0x2, 0x2, 0xf1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 
       0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x3c, 0x2, 0x2, 0xf4, 0x31, 0x3, 
       0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x3b, 0x2, 0x2, 0xf6, 0x33, 0x3, 
       0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x9, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x24, 
       0x13, 0x2, 0xf9, 0xfa, 0x7, 0x3c, 0x2, 0x2, 0xfa, 0x103, 0x7, 0xa, 
       0x2, 0x2, 0xfb, 0x104, 0x5, 0x3e, 0x20, 0x2, 0xfc, 0xfe, 0x9, 0x6, 
       0x2, 0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 
       0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x5, 0x3c, 0x1f, 
       0x2, 0x100, 0x102, 0x9, 0x7, 0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 
       0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 0x3, 0x2, 0x2, 
       0x2, 0x103, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x103, 0xfd, 0x3, 0x2, 0x2, 
       0x2, 0x104, 0x108, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x12, 0x2, 
       0x2, 0x106, 0x107, 0x7, 0x13, 0x2, 0x2, 0x107, 0x109, 0x5, 0x2e, 
       0x18, 0x2, 0x108, 0x105, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 
       0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
       0x2, 0x2, 0x10b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x115, 0x7, 0x2d, 
       0x2, 0x2, 0x10d, 0x112, 0x5, 0x3a, 0x1e, 0x2, 0x10e, 0x10f, 0x7, 
       0x2a, 0x2, 0x2, 0x10f, 0x111, 0x5, 0x3a, 0x1e, 0x2, 0x110, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 
       0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10d, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x7, 0x2a, 0x2, 0x2, 0x118, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x11f, 0x5, 0x38, 0x1d, 0x2, 0x11b, 0x11c, 
       0x7, 0x2a, 0x2, 0x2, 0x11c, 0x11e, 0x5, 0x38, 0x1d, 0x2, 0x11d, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 
       0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x2e, 0x2, 0x2, 0x125, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x3c, 0x2, 0x2, 0x127, 0x12e, 
       0x7, 0x8, 0x2, 0x2, 0x128, 0x12f, 0x5, 0x3a, 0x1e, 0x2, 0x129, 0x12b, 
       0x7, 0x2f, 0x2, 0x2, 0x12a, 0x12c, 0x5, 0x3c, 0x1f, 0x2, 0x12b, 0x12a, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12f, 0x7, 0x30, 0x2, 0x2, 0x12e, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x5, 0x26, 0x14, 0x2, 0x131, 0x133, 
       0x5, 0x40, 0x21, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x139, 
       0x5, 0x3a, 0x1e, 0x2, 0x135, 0x136, 0x7, 0x2a, 0x2, 0x2, 0x136, 0x138, 
       0x5, 0x3a, 0x1e, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x7, 0xb, 0x2, 0x2, 0x13d, 0x13e, 
       0x7, 0x2b, 0x2, 0x2, 0x13e, 0x141, 0x7, 0xb, 0x2, 0x2, 0x13f, 0x140, 
       0x7, 0x2b, 0x2, 0x2, 0x140, 0x142, 0x7, 0xb, 0x2, 0x2, 0x141, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x8, 0x21, 0x1, 0x2, 0x144, 0x145, 
       0x7, 0x2d, 0x2, 0x2, 0x145, 0x146, 0x5, 0x40, 0x21, 0x2, 0x146, 0x147, 
       0x7, 0x2e, 0x2, 0x2, 0x147, 0x158, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 
       0x9, 0x8, 0x2, 0x2, 0x149, 0x158, 0x5, 0x40, 0x21, 0xb, 0x14a, 0x14b, 
       0x5, 0x46, 0x24, 0x2, 0x14b, 0x14c, 0x7, 0x2d, 0x2, 0x2, 0x14c, 0x14d, 
       0x5, 0x40, 0x21, 0x2, 0x14d, 0x14e, 0x7, 0x2e, 0x2, 0x2, 0x14e, 0x158, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x158, 0x5, 0x44, 0x23, 0x2, 0x150, 0x158, 
       0x9, 0x9, 0x2, 0x2, 0x151, 0x152, 0x7, 0x3c, 0x2, 0x2, 0x152, 0x153, 
       0x7, 0x2f, 0x2, 0x2, 0x153, 0x154, 0x5, 0x40, 0x21, 0x2, 0x154, 0x155, 
       0x7, 0x30, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 0x158, 
       0x5, 0x42, 0x22, 0x2, 0x157, 0x143, 0x3, 0x2, 0x2, 0x2, 0x157, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x157, 0x14f, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x150, 0x3, 0x2, 0x2, 0x2, 0x157, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x164, 
       0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0xc, 0xa, 0x2, 0x2, 0x15a, 0x15b, 
       0x7, 0x7, 0x2, 0x2, 0x15b, 0x163, 0x5, 0x40, 0x21, 0xa, 0x15c, 0x15d, 
       0xc, 0x9, 0x2, 0x2, 0x15d, 0x15e, 0x9, 0xa, 0x2, 0x2, 0x15e, 0x163, 
       0x5, 0x40, 0x21, 0xa, 0x15f, 0x160, 0xc, 0x8, 0x2, 0x2, 0x160, 0x161, 
       0x9, 0x8, 0x2, 0x2, 0x161, 0x163, 0x5, 0x40, 0x21, 0x9, 0x162, 0x159, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x162, 0x15f, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 
       0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 
       0x7, 0x31, 0x2, 0x2, 0x168, 0x169, 0x7, 0x3c, 0x2, 0x2, 0x169, 0x16a, 
       0x7, 0x32, 0x2, 0x2, 0x16a, 0x43, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 
       0x9, 0xb, 0x2, 0x2, 0x16c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 
       0x9, 0xc, 0x2, 0x2, 0x16e, 0x47, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x4b, 
       0x52, 0x59, 0x62, 0x68, 0x6b, 0x70, 0x73, 0x77, 0x79, 0x89, 0x90, 
       0x9c, 0x9e, 0xa6, 0xaf, 0xb5, 0xb9, 0xbd, 0xca, 0xd3, 0xdb, 0xe0, 
       0xe3, 0xe7, 0xeb, 0xf0, 0xfd, 0x101, 0x103, 0x10a, 0x112, 0x115, 
       0x118, 0x11f, 0x122, 0x12b, 0x12e, 0x132, 0x139, 0x141, 0x157, 0x162, 
       0x164, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

blackbirdParser::Initializer blackbirdParser::_init;
