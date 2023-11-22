grammar zsh;
/*TOKENS */

IF:'if';
THEN:'then';
ELSE:'else';
ELIF:'elif';
FI:'fi';
TRUE:'true';
FALSE:'false';
ECHO:'echo';

PARAMETER:'$';
DUOUBLEBRACKET:'[[';
DUOUBLEBRACKETCLOSE:']]';
DOUBLEPARENTHESIS:'((';
DOUBLEPARENTHESISCLOSE:'))';
DOUBLEDOT:'..';
CURLY:'{';
CURLYCLOSE:'}';
DEFINE:'=';
PIPE:'|';

/*LOOP*/
FOR:'for';
IN:'in';
DO:'do';
DONE:'done';
WHILE:'while';
UNTIL:'until';
/*function*/
RETURN:'return';
/*MATHS*/
PLUS:'+';
MINUS:'-';
MULTIPLY:'*';
DIVIDE:'/';
MODULO:'%';
/*Operators*/
/*numeric*/
EQ:'-eq';
NE:'-ne';
GT:'-gt';
LT:'-lt';
GE:'-ge';
LE:'-le';
/*logic*/
AND:'&&';
OR:'||';
NEG:'!';
/*file*/
FILEEXISTS:'-e';
FILEISFILE:'-f';
FILEISDIR:'-d';
FILEISREADABLE:'-r';
FILEISWRITABLE:'-w';
FILEISEXECUTABLE:'-x';
NEWLINE:'\r'?'\n';
SEMICOLON:';';

ID: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: [0-9]+;
WS: [ \t]+ -> skip;
COMENT : '#' .*? NEWLINE -> skip;



/*RULES*/
start: statement+ ;
statement: mathExpression NEWLINE           #MathST
|logicalExpression NEWLINE                  #LogicalST
|ifStatement                                #IfST
|forStatement                               #ForST
|whileStatement                             #WhileST
|untilStatement                             #UntilST
|functionStatement                          #FunctionST
|callfuncStatement                          #CallFuncST
|echoStatement                              #EchoST
|ID DEFINE mathExpression NEWLINE         #DefineMathST
|ID DEFINE logicalExpression NEWLINE        #DefineLogicalST
|ID DEFINE '$' '(' ID ')' NEWLINE  #DefineCallFuncST
|NEWLINE   #Empty
;

logicalExpression:
logicalExpression op=(AND|OR) logicalExpression #AndOr
| NEG logicalExpression   #Neg
|logicalExpression op=(EQ|NE|GT|LT|GE|LE) logicalExpression #Compare
|TRUE        #True
|FALSE        #False
|'$' ID       #IdLogical
|NUMBER        #NumberLogical
|'(' logicalExpression ')'  #ParenthesisLogical
;

mathExpression:'$''((' operation '))' #Math;
operation: operation op=(MULTIPLY|DIVIDE|MODULO) operation  #MultDivMod
|operation op=(PLUS|MINUS) operation  #PlusMinus
|NUMBER  #Number
|ID     #Id
|'(' operation ')' #Parenthesis
;

/*if*/
ifStatement:
IF '[[' logicalExpression ']]' NEWLINE
THEN NEWLINE statement+ elifStatement*
elseStatement? FI NEWLINE #If;
elseStatement:
ELSE NEWLINE statement+ #Else;
elifStatement:
ELIF '[[' logicalExpression ']]' NEWLINE statement+ elifStatement? #Elif;
/*for*/
forStatement:
FOR ID IN CURLY NUMBER DOUBLEDOT NUMBER CURLYCLOSE  NEWLINE DO NEWLINE statement+ DONE NEWLINE #For;

/*while*/
whileStatement:
WHILE '[[' logicalExpression ']]'
NEWLINE DO NEWLINE
statement+
DONE NEWLINE #While;

/*until*/
untilStatement:
UNTIL '[[' logicalExpression ']]'
NEWLINE DO NEWLINE
statement+
DONE NEWLINE #Until;

/*function*/
functionStatement:
ID '('')'
'{' NEWLINE
statement+
returnStatement? '}'
NEWLINE #Function;
returnStatement:
RETURN mathExpression NEWLINE     #ReturnMath
|RETURN logicalExpression NEWLINE #ReturnLogical
| RETURN '$' ID NEWLINE #ReturnId;

callfuncStatement:
ID '('')' NEWLINE #CallFunc;

echoStatement:
ECHO ID NEWLINE #Echo;

