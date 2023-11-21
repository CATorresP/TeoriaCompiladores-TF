
// Generated from ScriptExpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  ScriptExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, INT = 4, ID = 5, PATH = 6, WILDCARD = 7, 
    STR = 8, ENDL = 9, WS = 10
  };

  enum {
    RuleProgram = 0, RuleLine = 1, RuleCmd = 2, RuleCmdCall = 3, RuleArg = 4
  };

  explicit ScriptExprParser(antlr4::TokenStream *input);

  ScriptExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ScriptExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class LineContext;
  class CmdContext;
  class CmdCallContext;
  class ArgContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LineContext *line();
    antlr4::tree::TerminalNode *ENDL();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LineContext() = default;
    void copyFrom(LineContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CmdLineContext : public LineContext {
  public:
    CmdLineContext(LineContext *ctx);

    CmdContext *cmd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LineContext* line();

  class  CmdContext : public antlr4::ParserRuleContext {
  public:
    CmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CmdContext() = default;
    void copyFrom(CmdContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CmdCallLineContext : public CmdContext {
  public:
    CmdCallLineContext(CmdContext *ctx);

    CmdCallContext *cmdCall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CmdPipeLineContext : public CmdContext {
  public:
    CmdPipeLineContext(CmdContext *ctx);

    std::vector<CmdCallContext *> cmdCall();
    CmdCallContext* cmdCall(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CmdContext* cmd();

  class  CmdCallContext : public antlr4::ParserRuleContext {
  public:
    CmdCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CmdCallContext() = default;
    void copyFrom(CmdCallContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExitCallContext : public CmdCallContext {
  public:
    ExitCallContext(CmdCallContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
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

