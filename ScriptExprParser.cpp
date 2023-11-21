
// Generated from ScriptExpr.g4 by ANTLR 4.13.1


#include "ScriptExprVisitor.h"

#include "ScriptExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ScriptExprParserStaticData final {
  ScriptExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ScriptExprParserStaticData(const ScriptExprParserStaticData&) = delete;
  ScriptExprParserStaticData(ScriptExprParserStaticData&&) = delete;
  ScriptExprParserStaticData& operator=(const ScriptExprParserStaticData&) = delete;
  ScriptExprParserStaticData& operator=(ScriptExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag scriptexprParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ScriptExprParserStaticData *scriptexprParserStaticData = nullptr;

void scriptexprParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (scriptexprParserStaticData != nullptr) {
    return;
  }
#else
  assert(scriptexprParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ScriptExprParserStaticData>(
    std::vector<std::string>{
      "program", "line", "cmd", "cmdCall", "arg"
    },
    std::vector<std::string>{
      "", "'|'", "'cd'", "'exit'"
    },
    std::vector<std::string>{
      "", "", "", "", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,10,53,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,0,1,0,3,0,
  	15,8,0,1,1,1,1,1,2,1,2,1,2,1,2,5,2,23,8,2,10,2,12,2,26,9,2,3,2,28,8,2,
  	1,3,1,3,5,3,32,8,3,10,3,12,3,35,9,3,1,3,1,3,1,3,5,3,40,8,3,10,3,12,3,
  	43,9,3,1,3,3,3,46,8,3,1,4,1,4,1,4,3,4,51,8,4,1,4,0,0,5,0,2,4,6,8,0,1,
  	1,1,9,9,57,0,14,1,0,0,0,2,16,1,0,0,0,4,27,1,0,0,0,6,45,1,0,0,0,8,50,1,
  	0,0,0,10,11,3,2,1,0,11,12,7,0,0,0,12,15,1,0,0,0,13,15,5,0,0,1,14,10,1,
  	0,0,0,14,13,1,0,0,0,15,1,1,0,0,0,16,17,3,4,2,0,17,3,1,0,0,0,18,28,3,6,
  	3,0,19,24,3,6,3,0,20,21,5,1,0,0,21,23,3,6,3,0,22,20,1,0,0,0,23,26,1,0,
  	0,0,24,22,1,0,0,0,24,25,1,0,0,0,25,28,1,0,0,0,26,24,1,0,0,0,27,18,1,0,
  	0,0,27,19,1,0,0,0,28,5,1,0,0,0,29,33,5,5,0,0,30,32,3,8,4,0,31,30,1,0,
  	0,0,32,35,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,46,1,0,0,0,35,33,1,0,
  	0,0,36,46,5,6,0,0,37,41,5,2,0,0,38,40,3,8,4,0,39,38,1,0,0,0,40,43,1,0,
  	0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,46,1,0,0,0,43,41,1,0,0,0,44,46,5,3,
  	0,0,45,29,1,0,0,0,45,36,1,0,0,0,45,37,1,0,0,0,45,44,1,0,0,0,46,7,1,0,
  	0,0,47,51,5,5,0,0,48,51,5,6,0,0,49,51,5,7,0,0,50,47,1,0,0,0,50,48,1,0,
  	0,0,50,49,1,0,0,0,51,9,1,0,0,0,7,14,24,27,33,41,45,50
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  scriptexprParserStaticData = staticData.release();
}

}

ScriptExprParser::ScriptExprParser(TokenStream *input) : ScriptExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ScriptExprParser::ScriptExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ScriptExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *scriptexprParserStaticData->atn, scriptexprParserStaticData->decisionToDFA, scriptexprParserStaticData->sharedContextCache, options);
}

ScriptExprParser::~ScriptExprParser() {
  delete _interpreter;
}

const atn::ATN& ScriptExprParser::getATN() const {
  return *scriptexprParserStaticData->atn;
}

std::string ScriptExprParser::getGrammarFileName() const {
  return "ScriptExpr.g4";
}

const std::vector<std::string>& ScriptExprParser::getRuleNames() const {
  return scriptexprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ScriptExprParser::getVocabulary() const {
  return scriptexprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ScriptExprParser::getSerializedATN() const {
  return scriptexprParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

ScriptExprParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ScriptExprParser::LineContext* ScriptExprParser::ProgramContext::line() {
  return getRuleContext<ScriptExprParser::LineContext>(0);
}

tree::TerminalNode* ScriptExprParser::ProgramContext::ENDL() {
  return getToken(ScriptExprParser::ENDL, 0);
}

tree::TerminalNode* ScriptExprParser::ProgramContext::EOF() {
  return getToken(ScriptExprParser::EOF, 0);
}


size_t ScriptExprParser::ProgramContext::getRuleIndex() const {
  return ScriptExprParser::RuleProgram;
}


std::any ScriptExprParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ScriptExprParser::ProgramContext* ScriptExprParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ScriptExprParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(14);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ScriptExprParser::T__1:
      case ScriptExprParser::T__2:
      case ScriptExprParser::ID:
      case ScriptExprParser::PATH: {
        enterOuterAlt(_localctx, 1);
        setState(10);
        line();
        setState(11);
        _la = _input->LA(1);
        if (!(_la == ScriptExprParser::EOF

        || _la == ScriptExprParser::ENDL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case ScriptExprParser::EOF: {
        enterOuterAlt(_localctx, 2);
        setState(13);
        match(ScriptExprParser::EOF);
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

//----------------- LineContext ------------------------------------------------------------------

ScriptExprParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ScriptExprParser::LineContext::getRuleIndex() const {
  return ScriptExprParser::RuleLine;
}

void ScriptExprParser::LineContext::copyFrom(LineContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CmdLineContext ------------------------------------------------------------------

ScriptExprParser::CmdContext* ScriptExprParser::CmdLineContext::cmd() {
  return getRuleContext<ScriptExprParser::CmdContext>(0);
}

ScriptExprParser::CmdLineContext::CmdLineContext(LineContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::CmdLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitCmdLine(this);
  else
    return visitor->visitChildren(this);
}
ScriptExprParser::LineContext* ScriptExprParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, ScriptExprParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<ScriptExprParser::CmdLineContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(16);
    cmd();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmdContext ------------------------------------------------------------------

ScriptExprParser::CmdContext::CmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ScriptExprParser::CmdContext::getRuleIndex() const {
  return ScriptExprParser::RuleCmd;
}

void ScriptExprParser::CmdContext::copyFrom(CmdContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CmdCallLineContext ------------------------------------------------------------------

ScriptExprParser::CmdCallContext* ScriptExprParser::CmdCallLineContext::cmdCall() {
  return getRuleContext<ScriptExprParser::CmdCallContext>(0);
}

ScriptExprParser::CmdCallLineContext::CmdCallLineContext(CmdContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::CmdCallLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitCmdCallLine(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CmdPipeLineContext ------------------------------------------------------------------

std::vector<ScriptExprParser::CmdCallContext *> ScriptExprParser::CmdPipeLineContext::cmdCall() {
  return getRuleContexts<ScriptExprParser::CmdCallContext>();
}

ScriptExprParser::CmdCallContext* ScriptExprParser::CmdPipeLineContext::cmdCall(size_t i) {
  return getRuleContext<ScriptExprParser::CmdCallContext>(i);
}

ScriptExprParser::CmdPipeLineContext::CmdPipeLineContext(CmdContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::CmdPipeLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitCmdPipeLine(this);
  else
    return visitor->visitChildren(this);
}
ScriptExprParser::CmdContext* ScriptExprParser::cmd() {
  CmdContext *_localctx = _tracker.createInstance<CmdContext>(_ctx, getState());
  enterRule(_localctx, 4, ScriptExprParser::RuleCmd);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(27);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ScriptExprParser::CmdCallLineContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(18);
      cmdCall();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ScriptExprParser::CmdPipeLineContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(19);
      cmdCall();
      setState(24);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ScriptExprParser::T__0) {
        setState(20);
        match(ScriptExprParser::T__0);
        setState(21);
        cmdCall();
        setState(26);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmdCallContext ------------------------------------------------------------------

ScriptExprParser::CmdCallContext::CmdCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ScriptExprParser::CmdCallContext::getRuleIndex() const {
  return ScriptExprParser::RuleCmdCall;
}

void ScriptExprParser::CmdCallContext::copyFrom(CmdCallContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExitCallContext ------------------------------------------------------------------

ScriptExprParser::ExitCallContext::ExitCallContext(CmdCallContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::ExitCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitExitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FileExecContext ------------------------------------------------------------------

tree::TerminalNode* ScriptExprParser::FileExecContext::PATH() {
  return getToken(ScriptExprParser::PATH, 0);
}

ScriptExprParser::FileExecContext::FileExecContext(CmdCallContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::FileExecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitFileExec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CdCmdCallContext ------------------------------------------------------------------

std::vector<ScriptExprParser::ArgContext *> ScriptExprParser::CdCmdCallContext::arg() {
  return getRuleContexts<ScriptExprParser::ArgContext>();
}

ScriptExprParser::ArgContext* ScriptExprParser::CdCmdCallContext::arg(size_t i) {
  return getRuleContext<ScriptExprParser::ArgContext>(i);
}

ScriptExprParser::CdCmdCallContext::CdCmdCallContext(CmdCallContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::CdCmdCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitCdCmdCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SysCmdCallContext ------------------------------------------------------------------

tree::TerminalNode* ScriptExprParser::SysCmdCallContext::ID() {
  return getToken(ScriptExprParser::ID, 0);
}

std::vector<ScriptExprParser::ArgContext *> ScriptExprParser::SysCmdCallContext::arg() {
  return getRuleContexts<ScriptExprParser::ArgContext>();
}

ScriptExprParser::ArgContext* ScriptExprParser::SysCmdCallContext::arg(size_t i) {
  return getRuleContext<ScriptExprParser::ArgContext>(i);
}

ScriptExprParser::SysCmdCallContext::SysCmdCallContext(CmdCallContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::SysCmdCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitSysCmdCall(this);
  else
    return visitor->visitChildren(this);
}
ScriptExprParser::CmdCallContext* ScriptExprParser::cmdCall() {
  CmdCallContext *_localctx = _tracker.createInstance<CmdCallContext>(_ctx, getState());
  enterRule(_localctx, 6, ScriptExprParser::RuleCmdCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ScriptExprParser::ID: {
        _localctx = _tracker.createInstance<ScriptExprParser::SysCmdCallContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(29);
        match(ScriptExprParser::ID);
        setState(33);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 224) != 0)) {
          setState(30);
          arg();
          setState(35);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ScriptExprParser::PATH: {
        _localctx = _tracker.createInstance<ScriptExprParser::FileExecContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(36);
        match(ScriptExprParser::PATH);
        break;
      }

      case ScriptExprParser::T__1: {
        _localctx = _tracker.createInstance<ScriptExprParser::CdCmdCallContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(37);
        match(ScriptExprParser::T__1);
        setState(41);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 224) != 0)) {
          setState(38);
          arg();
          setState(43);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ScriptExprParser::T__2: {
        _localctx = _tracker.createInstance<ScriptExprParser::ExitCallContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(44);
        match(ScriptExprParser::T__2);
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

//----------------- ArgContext ------------------------------------------------------------------

ScriptExprParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ScriptExprParser::ArgContext::getRuleIndex() const {
  return ScriptExprParser::RuleArg;
}

void ScriptExprParser::ArgContext::copyFrom(ArgContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgPathContext ------------------------------------------------------------------

tree::TerminalNode* ScriptExprParser::ArgPathContext::PATH() {
  return getToken(ScriptExprParser::PATH, 0);
}

ScriptExprParser::ArgPathContext::ArgPathContext(ArgContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::ArgPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitArgPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgIdContext ------------------------------------------------------------------

tree::TerminalNode* ScriptExprParser::ArgIdContext::ID() {
  return getToken(ScriptExprParser::ID, 0);
}

ScriptExprParser::ArgIdContext::ArgIdContext(ArgContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::ArgIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitArgId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgWildcardContext ------------------------------------------------------------------

tree::TerminalNode* ScriptExprParser::ArgWildcardContext::WILDCARD() {
  return getToken(ScriptExprParser::WILDCARD, 0);
}

ScriptExprParser::ArgWildcardContext::ArgWildcardContext(ArgContext *ctx) { copyFrom(ctx); }


std::any ScriptExprParser::ArgWildcardContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitArgWildcard(this);
  else
    return visitor->visitChildren(this);
}
ScriptExprParser::ArgContext* ScriptExprParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 8, ScriptExprParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ScriptExprParser::ID: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgIdContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(47);
        match(ScriptExprParser::ID);
        break;
      }

      case ScriptExprParser::PATH: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgPathContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(48);
        match(ScriptExprParser::PATH);
        break;
      }

      case ScriptExprParser::WILDCARD: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgWildcardContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(49);
        match(ScriptExprParser::WILDCARD);
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

void ScriptExprParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  scriptexprParserInitialize();
#else
  ::antlr4::internal::call_once(scriptexprParserOnceFlag, scriptexprParserInitialize);
#endif
}
