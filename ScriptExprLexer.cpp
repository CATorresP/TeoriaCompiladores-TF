
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
      "T__0", "T__1", "T__2", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'|'", "'cd'", "'exit'"
    },
    std::vector<std::string>{
      "", "", "", "", "INT", "ID", "PATH", "WILDCARD", "STR", "ENDL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,10,83,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,
  	4,3,33,8,3,11,3,12,3,34,1,4,1,4,5,4,39,8,4,10,4,12,4,42,9,4,1,5,1,5,5,
  	5,46,8,5,10,5,12,5,49,9,5,1,5,4,5,52,8,5,11,5,12,5,53,3,5,56,8,5,1,6,
  	4,6,59,8,6,11,6,12,6,60,1,7,1,7,5,7,65,8,7,10,7,12,7,68,9,7,1,7,1,7,1,
  	8,4,8,73,8,8,11,8,12,8,74,1,9,4,9,78,8,9,11,9,12,9,79,1,9,1,9,1,66,0,
  	10,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,1,0,7,1,0,48,57,2,0,
  	65,90,97,122,3,0,48,57,65,90,97,122,3,0,45,57,65,90,97,122,5,0,42,42,
  	45,57,63,63,65,90,97,122,2,0,10,10,59,59,3,0,9,9,13,13,32,32,91,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,1,21,1,0,0,0,3,23,1,
  	0,0,0,5,26,1,0,0,0,7,32,1,0,0,0,9,36,1,0,0,0,11,55,1,0,0,0,13,58,1,0,
  	0,0,15,62,1,0,0,0,17,72,1,0,0,0,19,77,1,0,0,0,21,22,5,124,0,0,22,2,1,
  	0,0,0,23,24,5,99,0,0,24,25,5,100,0,0,25,4,1,0,0,0,26,27,5,101,0,0,27,
  	28,5,120,0,0,28,29,5,105,0,0,29,30,5,116,0,0,30,6,1,0,0,0,31,33,7,0,0,
  	0,32,31,1,0,0,0,33,34,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,0,35,8,1,0,0,
  	0,36,40,7,1,0,0,37,39,7,2,0,0,38,37,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,
  	0,40,41,1,0,0,0,41,10,1,0,0,0,42,40,1,0,0,0,43,47,5,126,0,0,44,46,7,3,
  	0,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,56,1,0,
  	0,0,49,47,1,0,0,0,50,52,7,3,0,0,51,50,1,0,0,0,52,53,1,0,0,0,53,51,1,0,
  	0,0,53,54,1,0,0,0,54,56,1,0,0,0,55,43,1,0,0,0,55,51,1,0,0,0,56,12,1,0,
  	0,0,57,59,7,4,0,0,58,57,1,0,0,0,59,60,1,0,0,0,60,58,1,0,0,0,60,61,1,0,
  	0,0,61,14,1,0,0,0,62,66,5,34,0,0,63,65,9,0,0,0,64,63,1,0,0,0,65,68,1,
  	0,0,0,66,67,1,0,0,0,66,64,1,0,0,0,67,69,1,0,0,0,68,66,1,0,0,0,69,70,5,
  	34,0,0,70,16,1,0,0,0,71,73,7,5,0,0,72,71,1,0,0,0,73,74,1,0,0,0,74,72,
  	1,0,0,0,74,75,1,0,0,0,75,18,1,0,0,0,76,78,7,6,0,0,77,76,1,0,0,0,78,79,
  	1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,81,1,0,0,0,81,82,6,9,0,0,82,20,
  	1,0,0,0,10,0,34,40,47,53,55,60,66,74,79,1,6,0,0
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
