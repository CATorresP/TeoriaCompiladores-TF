#include "ScriptExprLexer.h"
#include "ScriptExprParser.h"
#include "ScriptExprBaseVisitor.h"

#include <algorithm>
#include <any>
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <iostream>

enum class Type
{
    INT,
    STRING,
    BOOL,
    VOID,
    FUNCTION
};

class Scripting : public ScriptExprBaseVisitor
{
    std::map<std::string, std::any> memory;
    std::map<std::string, std::function<std::any(std::vector<std::any>)>> functions;
    std::map<std::string, std::vector<std::string>> functionParams;
    std::map<std::string, std::vector<std::string>> functionBody;
    std::map<std::string, std::vector<std::string>> functionArgs;
    std::map<std::string, Type> functionTypes;

public:
    std::any visitScript(ScriptExprParser::ScriptContext *ctx) override
    {
        for (auto line : ctx->line())
        {
            visitLine(line);
        }
        return {};
    }

    std::any visitAssignStat(ScriptExprParser::AssignStatContext *ctx) override
    {
        visit(ctx->assignStatement());
        return {};
    }

    std::any visitExpanAssign(ScriptExprParser::ExpanAssignContext *ctx) override
    {
        std::string varName = ctx->ID()->getText();
        auto varValue = visit(ctx->expression());
        memory[varName] = varValue;
        return {};
    }

    std::any visitAssignPrimary(ScriptExprParser::AssignPrimaryContext *ctx) override
    {
        std::string varName = ctx->ID()->getText();
        auto varValue = visit(ctx->primaryExpression());

        memory[varName] = varValue;
        return {};
    }

    std::any visitNumExpr(ScriptExprParser::NumExprContext *ctx) override
    {
        return std::stoi(ctx->NUMBER()->getText());
    }

    std::any visitStrExpr(ScriptExprParser::StrExprContext *ctx) override
    {
        std::string id = ctx->ID()->getText();

        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Variable " + id + " not found.");
        }

        return memory[id];
    }
    void run(const std::string &filepath)
    {

        std::ifstream file(filepath);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filepath);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string script = buffer.str();

        std::string command_line = script;
        antlr4::ANTLRInputStream input(command_line);
        ScriptExprLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ScriptExprParser parser(&tokens);
        auto tree = parser.script();
        this->visitScript(tree);
    }

    std::any visitArithmExpan(ScriptExprParser::ArithmExpanContext *ctx) override
    {
        auto value = visit(ctx->arithmExpression());
        return value;
    }

    std::any visitLogicalExpan(ScriptExprParser::LogicalExpanContext *ctx) override
    {
        auto value = visit(ctx->logicalExpression());
        return value;
    }

    std::any visitLogicalExpression(ScriptExprParser::LogicalExpressionContext *ctx) override
    {
        return visit(ctx->logicalOperation());
    }

    std::any visitRangeExpan(ScriptExprParser::RangeExpanContext *ctx) override
    {
        std::vector<std::any> values;

        auto start = std::stoi(ctx->NUMBER(0)->getText());
        auto end = std::stoi(ctx->NUMBER(1)->getText());

        if (start > end)
        {
            throw std::runtime_error("Start value cannot be greater than end value.");
        }

        for (int i = start; i <= end; i++)
        {
            values.push_back(i);
        }

        return values;
    }

    std::any visitVarExpan(ScriptExprParser::VarExpanContext *ctx) override
    {
        std::string id = ctx->ID()->getText();

        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Variable " + id + " not found.");
        }

        return memory[id];
    }

    std::any visitAndOr(ScriptExprParser::AndOrContext *ctx) override
    {
        auto left = visit(ctx->logicalOperation(0));
        auto right = visit(ctx->logicalOperation(1));

        if (ctx->AND())
        {
            return std::any_cast<bool>(left) && std::any_cast<bool>(right);
        }
        else if (ctx->OR())
        {
            return std::any_cast<bool>(left) || std::any_cast<bool>(right);
        }

        return {};
    }

    std::any visitNeg(ScriptExprParser::NegContext *ctx) override
    {
        auto value = visit(ctx->logicalOperation());
        return !std::any_cast<bool>(value);
    }
    std::any visitCompare(ScriptExprParser::CompareContext *ctx) override
    {
        auto left = visit(ctx->logicalOperation(0));
        auto right = visit(ctx->logicalOperation(1));
        auto op = ctx->op->getText();

        if (op == "-gt")
        {
            return std::any_cast<int>(left) > std::any_cast<int>(right);
        }
        else if (op == "-lt")
        {
            return std::any_cast<int>(left) < std::any_cast<int>(right);
        }
        else if (op == "-ge")
        {
            return std::any_cast<int>(left) >= std::any_cast<int>(right);
        }
        else if (op == "-le")
        {
            return std::any_cast<int>(left) <= std::any_cast<int>(right);
        }
        else if (op == "-eq")
        {
            return std::any_cast<int>(left) == std::any_cast<int>(right);
        }
        else if (op == "-ne")
        {
            return std::any_cast<int>(left) != std::any_cast<int>(right);
        }
        else
        {
            throw std::runtime_error("Unknown operator: " + op);
        }

        return {};
    }

    std::any visitTrue(ScriptExprParser::TrueContext *ctx) override
    {
        return true;
    }
    std::any visitFalse(ScriptExprParser::FalseContext *ctx) override
    {
        return false;
    }

    std::any visitIdLogical(ScriptExprParser::IdLogicalContext *ctx) override
    {
        std::string id = ctx->ID()->getText();

        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Variable " + id + " not found.");
        }

        return memory[id];
    }

    std::any visitNumberLogical(ScriptExprParser::NumberLogicalContext *ctx) override
    {
        return std::stoi(ctx->NUMBER()->getText());
    }

    std::any visitParenthesisLogical(ScriptExprParser::ParenthesisLogicalContext *ctx) override
    {
        return visit(ctx->logicalOperation());
    }

    //**********************************************************************************************************************
    std::any visitArithmExpression(ScriptExprParser::ArithmExpressionContext *ctx) override
    {
        return visit(ctx->operation());
    }

    std::any visitMultDivMod(ScriptExprParser::MultDivModContext *ctx) override
    {
        auto left = visit(ctx->operation(0));
        auto right = visit(ctx->operation(1));
        auto op = ctx->op->getText();

        if (op == "*")
        {
            return std::any_cast<int>(left) * std::any_cast<int>(right);
        }
        else if (op == "/")
        {
            return std::any_cast<int>(left) / std::any_cast<int>(right);
        }
        else if (op == "%")
        {
            return std::any_cast<int>(left) % std::any_cast<int>(right);
        }
        else
        {
            throw std::runtime_error("Unknown operator: " + op);
        }
    }

    std::any visitPlusMinus(ScriptExprParser::PlusMinusContext *ctx) override
    {
        auto left = visit(ctx->operation(0));
        auto right = visit(ctx->operation(1));
        auto op = ctx->op->getText();

        if (op == "+")
        {
            return std::any_cast<int>(left) + std::any_cast<int>(right);
        }
        else if (op == "-")
        {
            return std::any_cast<int>(left) - std::any_cast<int>(right);
        }
        else
        {
            throw std::runtime_error("Unknown operator: " + op);
        }
    }

    std::any visitParenthesis(ScriptExprParser::ParenthesisContext *ctx) override
    {
        return visit(ctx->operation());
    }

    std::any visitNumber(ScriptExprParser::NumberContext *ctx) override
    {
        int value = std::stoi(ctx->NUMBER()->getText());
        return std::any(value);
    }
    std::any visitId(ScriptExprParser::IdContext *ctx) override
    {
        std::string id = ctx->ID()->getText();

        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Variable " + id + " not found.");
        }

        return memory[id];
    }
    //**********************************************************************************************************************
    std::any visitIfStat(ScriptExprParser::IfStatContext *ctx) override
    {
        return visit(ctx->ifStatement());
    }

    std::any visitIfStatement(ScriptExprParser::IfStatementContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        bool doelse = true;
        if (std::any_cast<bool>(condition))
        {
            for (auto line : ctx->block())
            {
                visit(line);
            }
        }
        else if (ctx->elifStatement().size() > 0)
        {
            for (auto elif : ctx->elifStatement())
            {
                auto elifcon = visit(elif);
                if (std::any_cast<bool>(elifcon))
                {
                    doelse = false;
                    break;
                }
            }
        }
        if (ctx->elseStatement() && doelse)
        {
            visit(ctx->elseStatement());
        }

        return {};
    }

    std::any visitElifStatement(ScriptExprParser::ElifStatementContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        if (std::any_cast<bool>(condition))
        {
            for (auto line : ctx->block())
            {
                visit(line);
            }
        }
        return condition;
    }

    std::any visitElseStatement(ScriptExprParser::ElseStatementContext *ctx) override
    {
        for (auto line : ctx->block())
        {
            visit(line);
        }
        return {};
    }

    //**********************************************************************************************************************
    // while
    std::any visitWhileStat(ScriptExprParser::WhileStatContext *ctx) override
    {
        return visit(ctx->whileStatement());
    }

    std::any visitWhileStatement(ScriptExprParser::WhileStatementContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        while (std::any_cast<bool>(condition))
        {
            for (auto line : ctx->block())
            {
                visit(line);
            }
            condition = visit(ctx->logicalExpression());
        }
        return {};
    }

    std::any visitUntilStat(ScriptExprParser::UntilStatContext *ctx) override
    {
        return visit(ctx->untilStatement());
    }

    std::any visitUntilStatement(ScriptExprParser::UntilStatementContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        while (!std::any_cast<bool>(condition))
        {
            for (auto line : ctx->block())
            {
                visit(line);
            }
            condition = visit(ctx->logicalExpression());
        }
        return {};
    }

    //**********************************************************************************************************************
    void printMemory()
    {
        for (auto &pair : memory)
        {
            // if int
            if (pair.second.type() == typeid(int))
            {
                std::cout << pair.first << " = " << std::any_cast<int>(pair.second) << std::endl;
            }
            // if bool
            else if (pair.second.type() == typeid(bool))
            {
                std::cout << pair.first << " = " << std::any_cast<bool>(pair.second) << std::endl;
            }
            // type unknown
            else
            {
                std::cout << pair.first << " = "
                          << "unknown" << std::endl;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./program <filename.zsh>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    std::string extension = filepath.substr(filepath.find_last_of(".") + 1);
    if (extension != "zsh")
    {
        std::cout << "Invalid file extension. Only .zsh files are supported." << std::endl;
        return 1;
    }

    try
    {
        Scripting script;
        script.run(filepath);
        script.printMemory();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}