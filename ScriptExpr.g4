grammar ScriptExpr;

script
    : cmdCall (ENDL|EOF);

cmdCall
    : ID arg*       #SysCmdCall
    | PATH          #FileExec
    | 'cd' arg*     #CdCmdCall
    | 'exit'        #ExitCall
    ;

arg
    : ID            #ArgId
    | PATH          #ArgPath
    | WILDCARD      #ArgWildcard
    ;

INT:      [0-9]+ ;
ID:       [a-zA-Z][a-zA-Z0-9]* ;
PATH:     [./\-a-zA-Z0-9]+ ;
WILDCARD: [./\-a-zA-Z0-9*?]+ ;
STR:      '"' .*? '"' ;
ENDL:     [\n;]+ ;
WS:       [ \t\r]+ -> skip;