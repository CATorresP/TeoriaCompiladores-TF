#include "zshLexer.h"
#include "zshParser.h"
#include "zshBaseVisitor.h"

#include <algorithm>
#include <any>
#include <iostream>
#include <map>
#include <string>
#include <functional>

#include <fstream>
#include <sstream>

#include <iostream>

class zshScripting : zshBaseVisitor
{
    std::map<std::string, std::any> memory;

public:
    // comenzar1
    std::any visitStart(zshParser::StartContext *ctx) override
    {
        for (auto statement : ctx->statement())
        {
            visit(statement);
        }
        return {};
    }

    std::any visitMath(zshParser::MathContext *ctx) override
    {
        return visit(ctx->operation());
    }

    // operaciones matematicas y logicas
    std::any visitMultDivMod(zshParser::MultDivModContext *ctx) override
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

    std::any visitPlusMinus(zshParser::PlusMinusContext *ctx) override
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

    std::any visitNumber(zshParser::NumberContext *ctx) override
    {
        int value = std::stoi(ctx->NUMBER()->getText());
        return std::any(value);
    }

    std::any visitId(zshParser::IdContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Unknown variable: " + id);
        }
        return std::any(memory[id]);
    }
    std::any visitParenthesis(zshParser::ParenthesisContext *ctx) override
    {
        return visit(ctx->operation());
    }
    // logical expression
    std::any visitAndOr(zshParser::AndOrContext *ctx) override
    {
        auto left = visit(ctx->logicalExpression(0));
        auto right = visit(ctx->logicalExpression(1));
        auto op = ctx->op->getText();

        if (op == "&&")
        {
            return std::any_cast<bool>(left) && std::any_cast<bool>(right);
        }
        else if (op == "||")
        {
            return std::any_cast<bool>(left) || std::any_cast<bool>(right);
        }
        else
        {
            throw std::runtime_error("Unknown operator: " + op);
        }
    }

    std::any visitCompare(zshParser::CompareContext *ctx) override
    {
        auto left = visit(ctx->logicalExpression(0));
        auto right = visit(ctx->logicalExpression(1));
        auto op = ctx->op->getText();

        if (op == "-eq")
        {
            return std::any_cast<int>(left) == std::any_cast<int>(right);
        }
        else if (op == "-ne")
        {
            return std::any_cast<int>(left) != std::any_cast<int>(right);
        }
        else if (op == "-gt")
        {
            return std::any_cast<int>(left) < std::any_cast<int>(right);
        }
        else if (op == "-lt")
        {
            return std::any_cast<int>(left) > std::any_cast<int>(right);
        }
        else if (op == "-le")
        {
            return std::any_cast<int>(left) <= std::any_cast<int>(right);
        }
        else if (op == "-ge")
        {
            return std::any_cast<int>(left) >= std::any_cast<int>(right);
        }
        else
        {
            throw std::runtime_error("Unknown operator: " + op);
        }
    }
    std::any visitNeg(zshParser::NegContext *ctx) override
    {
        auto value = visit(ctx->logicalExpression());
        return !std::any_cast<bool>(value);
    }
    std::any visitParenthesisLogical(zshParser::ParenthesisLogicalContext *ctx) override
    {
        return visit(ctx->logicalExpression());
    }
    std::any visitTrue(zshParser::TrueContext *ctx) override
    {
        return true;
    }
    std::any visitFalse(zshParser::FalseContext *ctx) override
    {
        return false;
    }
    std::any visitNumberLogical(zshParser::NumberLogicalContext *ctx) override
    {
        return std::stoi(ctx->NUMBER()->getText());
    }
    std::any visitIdLogical(zshParser::IdLogicalContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Unknown variable: " + id);
        }
        return memory[id];
    }
    std::any visitDefineMathST(zshParser::DefineMathSTContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        auto value = std::any_cast<int>(visit(ctx->mathExpression()));
        memory[id] = value;
        return {};
    }

    std::any visitDefineLogicalST(zshParser::DefineLogicalSTContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        auto value = visit(ctx->logicalExpression());
        memory[id] = value;
        return value;
    }

    std::any visitDefineCallFuncST(zshParser::DefineCallFuncSTContext *ctx) override
    {
        auto id = ctx->ID(0)->getText();
        auto value = visit(ctx->ID(1));
        memory[id] = value;
        return value;
    }

    std::any visitIf(zshParser::IfContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        bool executed = false;

        if (std::any_cast<bool>(condition))
        {
            for (auto statement : ctx->statement())
            {
                visit(statement);
            }
            executed = true;
        }
        else if (!executed)
        {
            for (auto elifStatement : ctx->elifStatement())
            {
                visit(elifStatement);
            }
        }

        if (!executed && ctx->elseStatement())
        {
            return visit(ctx->elseStatement());
        }

        return {};
    }
    std::any visitElif(zshParser::ElifContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());
        bool executed = false;

        if (std::any_cast<bool>(condition))
        {
            for (auto statement : ctx->statement())
            {
                visit(statement);
            }
            executed = true;
        }

        if (!executed && ctx->elifStatement())
        {
            return visit(ctx->elifStatement());
        }

        return {};
    }

    std::any visitElse(zshParser::ElseContext *ctx) override
    {
        for (auto statement : ctx->statement())
        {
            visit(statement);
        }
        return {};
    }

    std::any visitFor(zshParser::ForContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        auto start = visit(ctx->NUMBER(0));
        auto end = visit(ctx->NUMBER(1));

        for (int i = std::any_cast<int>(start); i < std::any_cast<int>(end); i += 1)
        {
            memory[id] = i;
            for (auto statement : ctx->statement())
            {
                visit(statement);
            }
        }

        return {};
    }

    std::any visitWhile(zshParser::WhileContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());

        while (std::any_cast<bool>(condition))
        {
            for (auto statement : ctx->statement())
            {
                visit(statement);
            }
        }

        return {};
    }

    std::any visitUntil(zshParser::UntilContext *ctx) override
    {
        auto condition = visit(ctx->logicalExpression());

        while (!std::any_cast<bool>(condition))
        {
            for (auto statement : ctx->statement())
            {
                visit(statement);
            }
        }
        return {};
    }

    std::any visitFunction(zshParser::FunctionContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        for (auto statement : ctx->statement())
        {
            visit(statement);
        }
        auto returnSt = ctx->returnStatement();
        if (returnSt)
        {
            return visit(returnSt);
        }

        return {};
    }

    std::any visitReturnMath(zshParser::ReturnMathContext *ctx) override
    {
        return visit(ctx->mathExpression());
    }

    std::any visitReturnLogical(zshParser::ReturnLogicalContext *ctx) override
    {
        return visit(ctx->logicalExpression());
    }

    std::any visitReturnId(zshParser::ReturnIdContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Unknown variable: " + id);
        }
        return memory[id];
    }

    std::any visitCallFunc(zshParser::CallFuncContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Unknown function: " + id);
        }

        auto func = std::any_cast<std::function<std::any()>>(memory[id]);
        return func();
    }
    std::any visitEcho(zshParser::EchoContext *ctx) override
    {
        auto id = ctx->ID()->getText();
        if (memory.find(id) == memory.end())
        {
            throw std::runtime_error("Unknown variable: " + id);
        }

        std::any value = memory[id];
        if (value.type() == typeid(int))
        {
            std::cout << std::any_cast<int>(value) << std::endl;
        }
        else if (value.type() == typeid(std::string))
        {
            std::cout << std::any_cast<std::string>(value) << std::endl;
        }
        else if (value.type() == typeid(bool))
        {
            std::cout << std::any_cast<bool>(value) << std::endl;
        }
        else
        {
            throw std::runtime_error("Unsupported type for echo: " + std::string(value.type().name()));
        }
        return {};
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
        zshLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        zshParser parser(&tokens);
        auto tree = parser.start();
        this->visitStart(tree);
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
        zshScripting script;
        script.run(filepath);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
