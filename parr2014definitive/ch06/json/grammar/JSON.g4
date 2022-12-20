grammar JSON;

json : object
    | array
    ;

object : '{' pair (',' pair)* '}'
    | '{' '}' // empty object
    ;

pair : name ':' value ;

name : STRING ;

array : '[' value (',' value)* ']'
    | '[' ']'
    ;

value : STRING
    | NUMBER
    | object
    | array
    | 'true'
    | 'false'
    | 'null'
    ;

STRING : '"' (ESC | ~["\\])* '"' ;

fragment ESC : '\\' (["\\/bfnrt] | UNICODE) ;
fragment UNICODE : 'u' HEX HEX HEX HEX ;
fragment HEX : [0-9a-fA-F] ;

NUMBER : '-'? INT '.' [0-9]+ EXP? // 1.35, 1.35E-9, 0.3, -4.5
    | '-'? INT EXP // 1e10, -3e4
    | '-'? INT // -1, 34
    ;

fragment INT : '0' | [1-9] [0-9]* ;
fragment EXP : [eE] [+\-]? INT ;

WHITESPACE : [ \t\n\r]+ -> skip ;
