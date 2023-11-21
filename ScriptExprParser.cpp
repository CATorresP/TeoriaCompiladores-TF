
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
      "script", "cmdCall", "arg"
    },
    std::vector<std::string>{
      "", "'cd'"
    },
    std::vector<std::string>{
      "", "", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,32,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,0,1,1,1,1,5,1,12,8,1,10,1,
  	12,1,15,9,1,1,1,1,1,1,1,5,1,20,8,1,10,1,12,1,23,9,1,3,1,25,8,1,1,2,1,
  	2,1,2,3,2,30,8,2,1,2,0,0,3,0,2,4,0,1,1,1,7,7,34,0,6,1,0,0,0,2,24,1,0,
  	0,0,4,29,1,0,0,0,6,7,3,2,1,0,7,8,7,0,0,0,8,1,1,0,0,0,9,13,5,3,0,0,10,
  	12,3,4,2,0,11,10,1,0,0,0,12,15,1,0,0,0,13,11,1,0,0,0,13,14,1,0,0,0,14,
  	25,1,0,0,0,15,13,1,0,0,0,16,25,5,4,0,0,17,21,5,1,0,0,18,20,3,4,2,0,19,
  	18,1,0,0,0,20,23,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,0,22,25,1,0,0,0,23,
  	21,1,0,0,0,24,9,1,0,0,0,24,16,1,0,0,0,24,17,1,0,0,0,25,3,1,0,0,0,26,30,
  	5,3,0,0,27,30,5,4,0,0,28,30,5,5,0,0,29,26,1,0,0,0,29,27,1,0,0,0,29,28,
  	1,0,0,0,30,5,1,0,0,0,4,13,21,24,29
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


//----------------- ScriptContext ------------------------------------------------------------------

ScriptExprParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ScriptExprParser::CmdCallContext* ScriptExprParser::ScriptContext::cmdCall() {
  return getRuleContext<ScriptExprParser::CmdCallContext>(0);
}

tree::TerminalNode* ScriptExprParser::ScriptContext::ENDL() {
  return getToken(ScriptExprParser::ENDL, 0);
}

tree::TerminalNode* ScriptExprParser::ScriptContext::EOF() {
  return getToken(ScriptExprParser::EOF, 0);
}


size_t ScriptExprParser::ScriptContext::getRuleIndex() const {
  return ScriptExprParser::RuleScript;
}


std::any ScriptExprParser::ScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ScriptExprVisitor*>(visitor))
    return parserVisitor->visitScript(this);
  else
    return visitor->visitChildren(this);
}

ScriptExprParser::ScriptContext* ScriptExprParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 0, ScriptExprParser::RuleScript);
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
    setState(6);
    cmdCall();
    setState(7);
    _la = _input->LA(1);
    if (!(_la == ScriptExprParser::EOF

    || _la == ScriptExprParser::ENDL)) {
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
  enterRule(_localctx, 2, ScriptExprParser::RuleCmdCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ScriptExprParser::ID: {
        _localctx = _tracker.createInstance<ScriptExprParser::SysCmdCallContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(9);
        match(ScriptExprParser::ID);
        setState(13);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 56) != 0)) {
          setState(10);
          arg();
          setState(15);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ScriptExprParser::PATH: {
        _localctx = _tracker.createInstance<ScriptExprParser::FileExecContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(16);
        match(ScriptExprParser::PATH);
        break;
      }

      case ScriptExprParser::T__0: {
        _localctx = _tracker.createInstance<ScriptExprParser::CdCmdCallContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(17);
        match(ScriptExprParser::T__0);
        setState(21);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 56) != 0)) {
          setState(18);
          arg();
          setState(23);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
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
  enterRule(_localctx, 4, ScriptExprParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(29);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ScriptExprParser::ID: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgIdContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(26);
        match(ScriptExprParser::ID);
        break;
      }

      case ScriptExprParser::PATH: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgPathContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(27);
        match(ScriptExprParser::PATH);
        break;
      }

      case ScriptExprParser::WILDCARD: {
        _localctx = _tracker.createInstance<ScriptExprParser::ArgWildcardContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(28);
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
