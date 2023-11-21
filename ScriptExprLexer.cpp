
// Generated from ScriptExpr.g4 by ANTLR 4.13.1


#include "ScriptExprLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ScriptExprLexerStaticData final {
  ScriptExprLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ScriptExprLexerStaticData(const ScriptExprLexerStaticData&) = delete;
  ScriptExprLexerStaticData(ScriptExprLexerStaticData&&) = delete;
  ScriptExprLexerStaticData& operator=(const ScriptExprLexerStaticData&) = delete;
  ScriptExprLexerStaticData& operator=(ScriptExprLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag scriptexprlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ScriptExprLexerStaticData *scriptexprlexerLexerStaticData = nullptr;

void scriptexprlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (scriptexprlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(scriptexprlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ScriptExprLexerStaticData>(
    std::vector<std::string>{
      "T__0", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'cd'"
    },
    std::vector<std::string>{
      "", "", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,63,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,0,1,1,4,1,22,8,1,11,1,12,1,23,1,2,1,2,5,2,28,8,2,10,
  	2,12,2,31,9,2,1,3,4,3,34,8,3,11,3,12,3,35,1,4,4,4,39,8,4,11,4,12,4,40,
  	1,5,1,5,5,5,45,8,5,10,5,12,5,48,9,5,1,5,1,5,1,6,4,6,53,8,6,11,6,12,6,
  	54,1,7,4,7,58,8,7,11,7,12,7,59,1,7,1,7,1,46,0,8,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,1,0,7,1,0,48,57,2,0,65,90,97,122,3,0,48,57,65,90,97,122,3,
  	0,45,57,65,90,97,122,5,0,42,42,45,57,63,63,65,90,97,122,2,0,10,10,59,
  	59,3,0,9,9,13,13,32,32,69,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,
  	21,1,0,0,0,5,25,1,0,0,0,7,33,1,0,0,0,9,38,1,0,0,0,11,42,1,0,0,0,13,52,
  	1,0,0,0,15,57,1,0,0,0,17,18,5,99,0,0,18,19,5,100,0,0,19,2,1,0,0,0,20,
  	22,7,0,0,0,21,20,1,0,0,0,22,23,1,0,0,0,23,21,1,0,0,0,23,24,1,0,0,0,24,
  	4,1,0,0,0,25,29,7,1,0,0,26,28,7,2,0,0,27,26,1,0,0,0,28,31,1,0,0,0,29,
  	27,1,0,0,0,29,30,1,0,0,0,30,6,1,0,0,0,31,29,1,0,0,0,32,34,7,3,0,0,33,
  	32,1,0,0,0,34,35,1,0,0,0,35,33,1,0,0,0,35,36,1,0,0,0,36,8,1,0,0,0,37,
  	39,7,4,0,0,38,37,1,0,0,0,39,40,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,
  	10,1,0,0,0,42,46,5,34,0,0,43,45,9,0,0,0,44,43,1,0,0,0,45,48,1,0,0,0,46,
  	47,1,0,0,0,46,44,1,0,0,0,47,49,1,0,0,0,48,46,1,0,0,0,49,50,5,34,0,0,50,
  	12,1,0,0,0,51,53,7,5,0,0,52,51,1,0,0,0,53,54,1,0,0,0,54,52,1,0,0,0,54,
  	55,1,0,0,0,55,14,1,0,0,0,56,58,7,6,0,0,57,56,1,0,0,0,58,59,1,0,0,0,59,
  	57,1,0,0,0,59,60,1,0,0,0,60,61,1,0,0,0,61,62,6,7,0,0,62,16,1,0,0,0,8,
  	0,23,29,35,40,46,54,59,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  scriptexprlexerLexerStaticData = staticData.release();
}

}

ScriptExprLexer::ScriptExprLexer(CharStream *input) : Lexer(input) {
  ScriptExprLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *scriptexprlexerLexerStaticData->atn, scriptexprlexerLexerStaticData->decisionToDFA, scriptexprlexerLexerStaticData->sharedContextCache);
}

ScriptExprLexer::~ScriptExprLexer() {
  delete _interpreter;
}

std::string ScriptExprLexer::getGrammarFileName() const {
  return "ScriptExpr.g4";
}

const std::vector<std::string>& ScriptExprLexer::getRuleNames() const {
  return scriptexprlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ScriptExprLexer::getChannelNames() const {
  return scriptexprlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ScriptExprLexer::getModeNames() const {
  return scriptexprlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ScriptExprLexer::getVocabulary() const {
  return scriptexprlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ScriptExprLexer::getSerializedATN() const {
  return scriptexprlexerLexerStaticData->serializedATN;
}

const atn::ATN& ScriptExprLexer::getATN() const {
  return *scriptexprlexerLexerStaticData->atn;
}




void ScriptExprLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  scriptexprlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(scriptexprlexerLexerOnceFlag, scriptexprlexerLexerInitialize);
#endif
}
