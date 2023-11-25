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
#include <sstream>

#include "ScriptExprLexer.h"
#include "ScriptExprParser.h"
#include "ScriptExprBaseVisitor.h"


namespace fs = std::filesystem;

int CMD_STATUS;


class Shell : ScriptExprBaseVisitor {
    fs::path home_path;
    void printCurrentPath();
private:
    // basic
    void commandExec(const std::vector<std::string>&);
    // visitor
    std::any visitScript(ScriptExprParser::ScriptContext*);
    
    std::any visitCmdStat(ScriptExprParser::CmdStatContext*);
    
    std::any visitCmdCall(ScriptExprParser::CmdCallContext*);
    std::any visitCmdPipe(ScriptExprParser::CmdPipeContext*);

    std::any visitSysCmdCall(ScriptExprParser::SysCmdCallContext*);
    std::any visitCdCmdCall(ScriptExprParser::CdCmdCallContext*);
    
    std::any visitArgId(ScriptExprParser::ArgIdContext*);
    std::any visitArgPath(ScriptExprParser::ArgPathContext*);
    std::any visitArgWildcard(ScriptExprParser::ArgWildcardContext*);
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
        this->visitScript(parser.script());
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
}

int Shell::commandCall(const std::vector<std::string>& args) {
    int pid, p[2];
    if(pipe(p) == -1) {
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        this->errmessage("shell: couldn't init a new process.");
        exit(1);
    } else if (pid == 0) {
        close(p[0]);
        dup2(p[1], STDOUT_FILENO);
        commandExec(args);
        this->errmessage("shell: command not found: " + args[0] + "\n");
        exit(1);
    } else {
        close(p[1]);
        char buffer[4096];
        int estado;
        std::stringstream cmdout;
        ssize_t nbytes;

        while ((nbytes = read(p[0], buffer, sizeof(buffer))) > 0) {
            cmdout.write(buffer, nbytes);
        }

        waitpid(pid, &estado, 0);

        if (WIFEXITED(estado)) {
            CMD_STATUS =  WEXITSTATUS(estado);
            std::cout << cmdout.str();
        } else {
            std::cout << "shell: command execution error\n";
        }
        return 0;
    }
}
//*****************************************************************
// VISITOR
//*****************************************************************
std::any Shell::visitScript(ScriptExprParser::ScriptContext* ctx) {
    visitChildren(ctx);
    return 0;
}

std::any Shell::visitCmdStat(ScriptExprParser::CmdStatContext* ctx) {
    return visit(ctx->cmdStatement());
}

std::any Shell::visitCmdCall(ScriptExprParser::CmdCallContext* ctx) {
    return visit(ctx->commandCall());
}

std::any Shell::visitCmdPipe(ScriptExprParser::CmdPipeContext* ctx) {
    /*
    for (auto command: ctx->commandCall()) {

        for (auto arg: command->)
        std::vector<ScriptExprParser::CommandCallContext*> commands = ctx->commandCall();
    }
    std::size_t ncommands = commands.size();
    int pipes[2][ncommands];

    for (int i = 0; i < ncommands; ++i) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            return -1;
        }
    }

    int pid;
    pid = fork();
    if (pid < 0) {
        std::cerr << "shell: couldn't init a new process.";
        exit(-1);
    } else if (pid == 0) {
        for (int i = ncommands - 1; i >= 0; --i) {
            pid = fork();
            if (pid < 0) {
                std::cerr << "shell: couldn't init a new process.";
                exit(-1);
            } else if (pid == 0) {
                if (i == 1) {
                    for (int j = 1; j < ncommands; ++j) {
                        close(pipes[j][0]);
                        close(pipes[j][1]);
                    }
                    std::cout << i << "-> output -> 0 write\n";
                    close(pipes[0][0]);
                    dup2(pipes[0][1], STDOUT_FILENO);
                    commandExec(commands[i]);
                    perror("execvp");
                    exit(-1);
                }
            } else {
                for (int j = 0; j < ncommands; ++j) {
                    if (j != i - 1)
                        close(pipes[j][0]);
                    if (j != i)
                       close(pipes[j][1]);
                }
                std::cout << i << "<- input <- " << i - 1 << " read\n";
                std::cout << i << "-> output -> " << i << " write\n";
                dup2(pipes[i - 1][0], STDIN_FILENO);
                dup2(pipes[i][1], STDOUT_FILENO);

                std::cerr << commands[i][0] << std::endl;
                commandExec(commands[i]);
                perror("execvp");
                close(pipes[i - 1][0]);
                close(pipes[i][1]);

                std::cerr << "shell: command not found: " + commands[i][0] + "\n";
                exit(-1);
            }
        }
    }
    std::cout << "Terminaron iteraciones\n";
    const int* ret_pipe = pipes[ncommands - 1];
    close(ret_pipe[1]);
    char buffer[4096];
    int estado;
    std::stringstream cmdout;
    ssize_t nbytes;
    std::cout << "Leyendo...\n";

    while ((nbytes = read(ret_pipe[0], buffer, sizeof(buffer))) > 0) {
        cmdout.write(buffer, nbytes);
    }

    pid_t last_pid = waitpid(-1, &estado, 0);

    if (WIFEXITED(estado)) {
        CMD_STATUS =  WEXITSTATUS(estado);
        std::cout << "RETURN:\n" << cmdout.str() << "\n$() = " << CMD_STATUS << std::endl;
    } else {
        std::cout << "shell: command execution error\n";
    }
    return 0;*/
    return 0;
}

std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::any Shell::visitSysCmdCall(ScriptExprParser::SysCmdCallContext* ctx) {
    std::vector<std::string> args;
    args.push_back(ctx->ID()->getText());
    for (auto arg : ctx->arg()) {
        auto subargs = split(std::any_cast<std::string>(visit(arg)), ' ');
        args.insert(args.end(), subargs.begin(), subargs.end());
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
    std::string wildcard = ctx->WILDCARD()->getText();
    std::string args = "";
    std::string r = "";
    bool slash = false, recursive = false, prev_ast= false;
    
    for (char c : wildcard) {
        switch (c) {
            case '?':
                r += ".";
                break;
            case '*':
                r += ".*";
                break;
            case '[': case ']':
                r += c;
                break;
            case '.':
                r += "\\.";
                break;
            case '/': 
                r += c;
                slash = true;
                break;
            case '\\':
                r += "\\";
            default:
                r +=  c;
                slash = false;
                break;
        }
        if(c != '*') {
            prev_ast = false;
        }
    }
    //std::cout << "regex:" << r << std::endl << std::endl;
    std::regex wildcard_regex(r); 

    if (recursive) {
        for (const auto& dir : fs::recursive_directory_iterator(fs::current_path().string())) {
            std::string name = dir.path().filename().string();
            if (std::regex_match(name, wildcard_regex)) {
                args += name + " ";
            }
        }
    } else {
        for (const auto& dir : fs::directory_iterator(fs::current_path().string())) {
            std::string name = dir.path().filename().string();
            if (std::regex_match(name, wildcard_regex)) {
                args += name + " ";
            }
        }
    }

    return args;
}
