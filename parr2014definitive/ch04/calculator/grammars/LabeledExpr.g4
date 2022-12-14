grammar LabeledExpr;

import CommonLexerRules;

prog : stat+ ;

stat : expr NEWLINE       #printStat
    | ID '=' expr NEWLINE #assignStat
    | NEWLINE             #blankStat
    | 'clear'             #clearStat
    ;

expr : expr op=('*' | '/') expr #multDivExpr
    | expr op=('+' | '-') expr  #addSubExpr
    | INT                    #intExpr
    | ID                     #idExpr
    | '(' expr ')'           #parenExpr
    ;

