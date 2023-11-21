#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>


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
    // visitor
    std::any visitScript(ScriptExprParser::ScriptContext*);
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

    while (true) {

        std::string command_line;
        this->printCurrentPath();
        std::cout << " >>";
        std::getline(std::cin, command_line);
        
        // Lectura del visitor
        antlr4::ANTLRInputStream input(command_line);
        ScriptExprLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ScriptExprParser parser(&tokens);
        auto tree = parser.script();
        this->visitScript(tree);
        
        // Condiciones de continuar
        if (command_line == "exit")
            break;
        //std::cout << "Línea ingresada: " << command_line << std::endl;
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
int Shell::commandCall(const std::vector<std::string>& args) {
    static const char cmnd_home[] = "/usr/bin/";
    std::string file_path = cmnd_home + args[0];
    std::size_t size = args.size();
    char** cargs = new char*[size + 1];
    pid_t pid;

    for (int i = 0; i < size; i++) {
        cargs[i] = const_cast<char*>(args[i].c_str());
    }
    cargs[size] = nullptr;

    pid = fork();

    if (pid < 0) {
        this->errmessage("shell: couldn't init a new process.");
        exit(1);
    } else if (pid == 0) {
        int status_code = execvp(file_path.c_str(), cargs);
        std::cout << "shell: command not found: " << args[0];
        exit(1);
    } else {
        // El nodo padre recibe un pid positivo
        int estado;
        waitpid(pid, &estado, 0);
        /*if (pid != 0) {
            for (int i = 0; i < size; i++) {
                delete cargs[i];
                cargs[i] = nullptr;
            }
            delete[] cargs;
            cargs = nullptr;
        }*/

        if (WIFEXITED(estado) && WEXITSTATUS(estado) == 0) {
            std::cout << "Ok." << std::endl;
        } else {
            std::cerr << "Error en la ejecución." << std::endl;
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
// COMMAND ARGUMENTS
//*****************************************************************
Shell::CommandArgs::CommandArgs(const std::vector<std::string>& args) {
    this->size = args.size();
    this->args = new char*[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        this->args[i] = const_cast<char*>(args[i].c_str());
    }
    this->args[this->size] = nullptr;
}
Shell::CommandArgs::~CommandArgs() {
    for (int i = 0; i < this->size; i++) {
        delete this->args[i];
    }
    delete[] this->args;
}
char** Shell::CommandArgs::CommandArgs::get() {
    return args;
}
//*****************************************************************
// SCRIPT READER
//*****************************************************************
std::any Shell::visitScript(ScriptExprParser::ScriptContext* ctx) {
    visitChildren(ctx);
    return 0;
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
