#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>


#include "ScriptExprLexer.h"
#include "ScriptExprParser.h"
#include "ScriptExprBaseVisitor.h"


namespace fs = std::filesystem;

class Shell : ScriptExprBaseVisitor {

    class CommandArgs {
        char **args;
        int size;
    public:
        CommandArgs(const std::vector<std::string>&);
        ~CommandArgs();
        char** get();
    };

    fs::path home_path;
    void printCurrentPath();
private:
    // basic
    void commandExec(const std::vector<std::string>&);
    // visitor
    std::any visitProgram(ScriptExprParser::ProgramContext*);
    
    std::any visitCmdLine(ScriptExprParser::CmdLineContext*);
    
    std::any visitCmdCallLine(ScriptExprParser::CmdCallLineContext*);
    std::any visitCmdPipeLine(ScriptExprParser::CmdPipeLineContext*);

    std::any visitSysCmdCall(ScriptExprParser::SysCmdCallContext*);
    std::any visitCdCmdCall(ScriptExprParser::CdCmdCallContext*);
    
    std::any visitArgId(ScriptExprParser::ArgIdContext*);
    std::any visitArgPath(ScriptExprParser::ArgPathContext*);
    std::any visitArgWildcard(ScriptExprParser::ArgWildcardContext*);
    // wildcard
    std::vector<std::string> wildcardToArgs(std::string& wildcard);
public:
    Shell();
    ~Shell();
    void run();
    void errmessage(std::string message);
    int cd(const std::string);
    int commandCall(const std::vector<std::string>&);
    std::vector<std::string> getWildcard(std::string&);
};


//*****************************************************************
// SHELL
//*****************************************************************
Shell::Shell() {
    std::cout << "| ::::: ::   :: :::::: ::    ::    |" << std::endl;
    std::cout << "| ::    ::   :: ::     ::    ::    |" << std::endl;
    std::cout << "| ::::: ::::::: :::::: ::    ::    |" << std::endl;
    std::cout << "|    :: ::   :: ::     ::    ::    |" << std::endl;
    std::cout << "| ::::: ::   :: :::::: ::::: ::::: |" << "\n\n\n";

    const char* homeDir = getenv("HOME");
    if (homeDir == nullptr) {
        errmessage("HOME folder not found.");
    }
    else {
        this->home_path = (homeDir);
        fs::current_path(this->home_path);
    }
}

Shell::~Shell() { }

void Shell::run() {
    std::string command_line;

    while (true) {
        command_line = "";
        this->printCurrentPath();
        std::cout << " >>";
        std::getline(std::cin, command_line);
        if (command_line == "exit") {
            std::cout << "Termino el shell";
            break;
        }
        antlr4::ANTLRInputStream input(command_line);
        ScriptExprLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ScriptExprParser parser(&tokens);
        this->visitProgram(parser.program());
    }
}

void Shell::printCurrentPath() {
    std::string str_current_path = fs::current_path().string();
    if (str_current_path.find(this->home_path.string()) == 0) {
        std::cout << "~" << str_current_path.substr(this->home_path.string().size());
    } else {
        std::cout << str_current_path;
    }
}

void Shell::errmessage(std::string message) {
    std::cerr << "shell: " << message << std::endl;
}
int Shell::cd(const std::string cd_path) {
    if (!fs::exists(cd_path)) {
        std::cerr << "cd: no such file or directory: "  << cd_path  << std::endl; 
        return 1;
    } else if (!fs::is_directory(cd_path)) {
        std::cerr << "cd: not a directory: "  << cd_path  << std::endl;
        return 1;
    } else {
        fs::current_path(cd_path);
    }
    return 0;
}
void Shell::commandExec(const std::vector<std::string>& args) {
    static const char cmnd_home[] = "/usr/bin/";
    std::string file_path = cmnd_home + args[0];
    std::size_t size = args.size();
    char** cargs = new char*[size + 1];

    for (int i = 0; i < size; i++) {
        cargs[i] = const_cast<char*>(args[i].c_str());
    }
    cargs[size] = nullptr;

    int status_code = execvp(file_path.c_str(), cargs);
    delete[] cargs;
    exit(1);
    return;
}
int Shell::commandCall(const std::vector<std::string>& args) {
    pid_t pid;

    pid = fork();
    
    if (pid < 0) {
        this->errmessage("shell: couldn't init a new process.");
        exit(1);
    } else if (pid == 0) {
        commandExec(args);
        std::cout << "shell: command not found: " << args[0] << std::endl;
        exit(1);
    } else {
        int estado;
        waitpid(pid, &estado, 0);

        if (WIFEXITED(estado) && WEXITSTATUS(estado) == 0) {
        } else {
        }
        return 0;
    }
}
//----------------------------------------------------------
// wildcard
//----------------------------------------------------------
std::vector<std::string> Shell::wildcardToArgs(std::string& wildcard) {
    std::vector<std::string> args;
    std::string r = "";
    bool slash = false, recursive = false;
    
    for (char c : wildcard) {
        switch (c) {
            case '?':
                r += ".";
                break;
            case '*':
                if (slash) {
                    r += ".*";
                } else {
                    r += "\\*";
                    recursive = true;
                }
                break;
            case '[': case ']':
                r += c;
                break;
            case '/': 
                r += c;
                slash = true;
                break;
            default:
                r += "\\" + std::string(1, c); 
                slash = false;
                break;
        }
    }
    std::regex wildcard_regex(r); 
    if (recursive) {
        for (const auto& dir : fs::recursive_directory_iterator(fs::current_path().string())) {
            std::string name = dir.path().filename().string();
            if (std::regex_match(name, wildcard_regex)) {
                args.push_back(name);
            }
        }
    } else {
        for (const auto& dir : fs::directory_iterator(fs::current_path().string())) {
            std::string name = dir.path().filename().string();
            if (std::regex_match(name, wildcard_regex)) {
                args.push_back(name);
            }
        }
    }
    return args;
}
//*****************************************************************
// VISITOR
//*****************************************************************
std::any Shell::visitProgram(ScriptExprParser::ProgramContext* ctx) {
    visitChildren(ctx);
    return 0;
}

std::any Shell::visitCmdLine(ScriptExprParser::CmdLineContext* ctx) {
    int status;
    int pid = fork();
    
    if (pid < 0) {
        this->errmessage("shell: couldn't init a new process.");
        exit(1);
    } else if (pid == 0) {
        visit(ctx->cmd());
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
    return status;
}

std::any Shell::visitSysCmdCall(ScriptExprParser::SysCmdCallContext* ctx) {
    std::vector<std::string> args;
    args.push_back(ctx->ID()->getText());
    for (auto arg : ctx->arg()) {
        args.push_back(std::any_cast<std::string>(visit(arg)));
    }
    return this->commandCall(args);
}
std::any Shell::visitCdCmdCall(ScriptExprParser::CdCmdCallContext* ctx) {
    std::vector<std::string> args;
    for (auto arg : ctx->arg()) {
        args.push_back(std::any_cast<std::string>(visit(arg)));
    }
    if(args.size() == 0) {
        this->cd(home_path.c_str());
    } else if (args.size() > 1) {
        this->errmessage("cd: string not in pwd: " + args[0]);
    } else {
        this->cd(args[0]);
    }
    return 0;
}
std::any Shell::visitArgId(ScriptExprParser::ArgIdContext* ctx) {
    return ctx->ID()->getText();
}
std::any Shell::visitArgPath(ScriptExprParser::ArgPathContext* ctx) {
    return ctx->PATH()->getText();
}
std::any Shell::visitArgWildcard(ScriptExprParser::ArgWildcardContext* ctx) {
    std::string wildcard_re = ctx->WILDCARD()->getText();
    return this->wildcardToArgs(wildcard_re);
}
