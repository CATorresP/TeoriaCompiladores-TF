
// Generated from ScriptExpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  ScriptExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, INT = 2, ID = 3, PATH = 4, WILDCARD = 5, STR = 6, ENDL = 7, 
    WS = 8
  };

  enum {
    RuleScript = 0, RuleCmdCall = 1, RuleArg = 2
  };

  explicit ScriptExprParser(antlr4::TokenStream *input);

  ScriptExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ScriptExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ScriptContext;
  class CmdCallContext;
  class ArgContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CmdCallContext *cmdCall();
    antlr4::tree::TerminalNode *ENDL();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScriptContext* script();

  class  CmdCallContext : public antlr4::ParserRuleContext {
  public:
    CmdCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CmdCallContext() = default;
    void copyFrom(CmdCallContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FileExecContext : public CmdCallContext {
  public:
    FileExecContext(CmdCallContext *ctx);

    antlr4::tree::TerminalNode *PATH();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CdCmdCallContext : public CmdCallContext {
  public:
    CdCmdCallContext(CmdCallContext *ctx);

    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SysCmdCallContext : public CmdCallContext {
  public:
    SysCmdCallContext(CmdCallContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CmdCallContext* cmdCall();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArgContext() = default;
    void copyFrom(ArgContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArgPathContext : public ArgContext {
  public:
    ArgPathContext(ArgContext *ctx);

    antlr4::tree::TerminalNode *PATH();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgIdContext : public ArgContext {
  public:
    ArgIdContext(ArgContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgWildcardContext : public ArgContext {
  public:
    ArgWildcardContext(ArgContext *ctx);

    antlr4::tree::TerminalNode *WILDCARD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgContext* arg();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

