
// Generated from ScriptExpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ScriptExprVisitor.h"


/**
 * This class provides an empty implementation of ScriptExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ScriptExprBaseVisitor : public ScriptExprVisitor {
public:

  virtual std::any visitScript(ScriptExprParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSysCmdCall(ScriptExprParser::SysCmdCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFileExec(ScriptExprParser::FileExecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCdCmdCall(ScriptExprParser::CdCmdCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgId(ScriptExprParser::ArgIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgPath(ScriptExprParser::ArgPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgWildcard(ScriptExprParser::ArgWildcardContext *ctx) override {
    return visitChildren(ctx);
  }


};

