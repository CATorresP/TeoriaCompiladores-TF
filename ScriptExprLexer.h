
// Generated from ScriptExpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  ScriptExprLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, INT = 4, ID = 5, PATH = 6, WILDCARD = 7, 
    STR = 8, ENDL = 9, WS = 10
  };

  explicit ScriptExprLexer(antlr4::CharStream *input);

  ~ScriptExprLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

