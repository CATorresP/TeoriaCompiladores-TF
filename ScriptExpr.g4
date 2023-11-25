grammar ScriptExpr;

script: line+;
block: line+;

line: statement (NEWLINE|SEMICOLON|NEWLINE SEMICOLON)
    | NEWLINE
    ;
statement
    : assignStatement           #AssignStat
    | ifStatement               #IfStat
    | forStatement              #ForStat
    | whileStatement            #WhileStat
    | untilStatement            #UntilStat
    | functionStatement         #FunctionStat
    | callfuncStatement         #CallFuncStat
    | cmdStatement              #CmdStat
    ;

assignStatement
    : ID ASSIGN '$' expression #expanAssign
    | ID ASSIGN primaryExpression   #AssignPrimary
    ;


expression
    : arithmExpression          #ArithmExpan
    | logicalExpression         #LogicalExpan
    | BRACEL NUMBER DOUBLEDOT NUMBER BRACER #RangeExpan
    | WILDCARD                  #WildcardExpan
    | ID                        #VarExpan
    ;


primaryExpression
    : NUMBER                    #NumExpr
    | ID                        #StrExpr
    ;

logicalExpression: DOUBLEBRACKETL logicalOperation DOUBLEBRACKETR ;

logicalOperation
    : logicalOperation op=(AND|OR) logicalOperation #AndOr
    | NEG logicalOperation     #Neg
    | logicalOperation op=(EQ|NE|GT|LT|GE|LE) logicalOperation #Compare
    | '@'TRUE                      #True
    | '@'FALSE                     #False
    |  ID                    #IdLogical
    | '$'NUMBER                    #NumberLogical
    | PARENL logicalOperation PARENR #ParenthesisLogical
    ;

arithmExpression: DOUBLEPARENL operation DOUBLEPARENR ;

operation
    : operation op=(MUL|DIV|MOD) operation  #MultDivMod
    | operation op=('+'|'-') operation      #PlusMinus
    | '$' NUMBER                                #Number
    | ID                                    #Id
    | PARENL operation PARENR               #Parenthesis
    ;

ifStatement: IF '[[' logicalExpression ']]' THEN (NEWLINE|SEMICOLON|NEWLINE SEMICOLON) block+ elifStatement* elseStatement? FI;

elseStatement: ELSE block+ ;

elifStatement: ELIF '[[' logicalExpression ']]' block+ elifStatement? ;

forStatement: FOR ID IN expression DO block+ 'done';

whileStatement: WHILE DOUBLEBRACKETL logicalExpression DOUBLEBRACKETR DO block+ DONE;

untilStatement
    : UNTIL '[[' logicalExpression ']]' DO block+ DONE;

functionStatement
    : ID '('')' '{' block+ returnStatement? '}';

returnStatement
    : RETURN expression
    ;

callfuncStatement: ID '('')' NEWLINE #CallFunc ;

cmdStatement
    : commandCall                       #CmdCall
    | commandCall (PIPE commandCall)+   #CmdPipe
    ;

commandCall
    : ID arg*                   #SysCmdCall
    | PATH                      #FileExec
    | CD arg*                   #CdCmdCall
    ;

arg
    : ID                        #ArgId
    | PATH                      #ArgPath
    | WILDCARD                  #ArgWildcard
    ;


/*TOKENS */



CD: 'cd';

IF:    'if';
THEN:  'then';
ELSE:  'else';
ELIF:  'elif';
FI:    'fi';
TRUE:  'true';
FALSE: 'false';
ECHO:  'echo';

ANCORE:    '@';
PARAMETER: '$';

DOUBLEBRACKETL: '[[';
DOUBLEBRACKETR: ']]';
DOUBLEPARENL:   '((';
DOUBLEPARENR:   '))';
DOUBLECURLYL:   '{{';
DOUBLECURLYR:   '}}';
BRACEL:     '{';
BRACER:     '}';
BRACKETL:   '[';
BRACKETR:   ']';
PARENL:     '(';
PARENR:     ')';
ASSIGN:     '=';
PIPE:       '|';
DOUBLEDOT: '..';

FOR:'for';
IN:'in';
DO:'do';
DONE:'done';
WHILE:'while';
UNTIL:'until';
RETURN:'return';

ADD: '+';
SUS: '-';
MUL: '*';
DIV: '/';
MOD: '%';

EQ:  '-eq';
NE:  '-ne';
GT:  '-gt';
LT:  '-lt';
GE:  '-ge';
LE:  '-le';
AND: '&&';
OR:  '||';
NEG: '!';

FILEEXISTS:       '-e';
FILEISFILE:       '-f';
FILEISDIR:        '-d';
FILEISREADABLE:   '-r';
FILEISWRITABLE:   '-w';
FILEISEXECUTABLE: '-x';
NEWLINE: '\r'?'\n';
SEMICOLON:';';


ID: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: [0-9]+;




WS: [ \t]+ -> skip;
COMENT : '#' .*? NEWLINE -> skip;

PATH:     '~' [./\-a-zA-Z0-9]* |
          [./\-a-zA-Z0-9]+
          ;
WILDCARD: [./\-a-zA-Z0-9*?]+ ;