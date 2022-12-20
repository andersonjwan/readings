grammar DOT;

graph : STRICT? (GRAPH | DIGRAPH) id? '{' stmtList '}' ;

stmtList : (stmt ';'?)* ;
stmt : nodeStmt
    | edgeStmt
    | attrStmt
    | id '=' id
    | subgraph
    ;

attrStmt : (GRAPH | NODE | EDGE) attrList ;
attrList : ('[' aList? ']')+ ;
aList : (id ('=' id)? ','?) ;

edgeStmt : (nodeId | subgraph) edgeRHS attrList? ;
edgeRHS : (edgeOp (nodeId | subgraph))+ ;
edgeOp : '->' | '--' ;

nodeStmt : nodeId attrList? ;
nodeId : id port? ;
port : ':' id (':' id)? ;

subgraph : (SUBGRAPH id?)? '{' stmtList '}' ;
id : ID
    | STRING
    | HTML_STRING
    | NUMBER
    ;

STRICT : [Ss] [Tt] [Rr] [Ii] [Cc] [Tt] ;
GRAPH : [Gg] [Rr] [Aa] [Pp] [Hh] ;
DIGRAPH : [Dd] [Ii] [Gg] [Rr] [Aa] [Pp] [Hh] ;
NODE : [Nn] [Oo] [Dd] [Ee] ;
EDGE : [Ee] [Dd] [Gg] [Ee] ;
SUBGRAPH : [Ss] [Uu] [Bb] [Gg] [Rr] [Aa] [Pp] [Hh] ;

ID : LETTER (LETTER | DIGIT)* ;
fragment LETTER : [a-zA-Z\u0080-\u00FF_] ;

NUMBER : '-'? ('.' DIGIT+ | DIGIT+ ('.' DIGIT*)?) ;
fragment DIGIT : [0-9] ;

STRING : '"' ('\\"' | .)*? '"' ;

HTML_STRING : '<' (TAG | ~[<>])* '>' ;
fragment TAG : '<' .*? '>' ;

PREPROCESSOR : '#' .*? '\n' -> skip ;

WHITESPACE : [ \t\r\n] -> skip;
