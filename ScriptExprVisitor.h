
// Generated from ScriptExpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ScriptExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ScriptExprParser.
 */
class  ScriptExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ScriptExprParser.
   */
    virtual std::any visitScript(ScriptExprParser::ScriptContext *context) = 0;

    virtual std::any visitSysCmdCall(ScriptExprParser::SysCmdCallContext *context) = 0;

    virtual std::any visitFileExec(ScriptExprParser::FileExecContext *context) = 0;

    virtual std::any visitCdCmdCall(ScriptExprParser::CdCmdCallContext *context) = 0;

    virtual std::any visitArgId(ScriptExprParser::ArgIdContext *context) = 0;

    virtual std::any visitArgPath(ScriptExprParser::ArgPathContext *context) = 0;

    virtual std::any visitArgWildcard(ScriptExprParser::ArgWildcardContext *context) = 0;


};

