grammar blackbird;

/*
 * Parser Rules
 */

file                : (NEWLINE | variable)* program NEWLINE* EOF;

// Variable declaration

variable            : vartype name ASSIGN (expression | nonnumeric)
                    | vartype TYPE_ARRAY name (LSQBRAC shape RSQBRAC)? ASSIGN NEWLINE arrayval;

name                : NAME;

vartype             : (TYPE_ARRAY|TYPE_FLOAT|TYPE_COMPLEX|TYPE_INT|TYPE_STR|TYPE_BOOL);

nonnumeric          : (STR|BOOL);

shape               : INT (COMMA INT)*;

arrayval            : (TAB row NEWLINE)*;

row                 : ((INT|FLOAT|COMPLEX) (SPACE|TAB)*)*;

// Blackbird program

program             : WITH device COLON NEWLINE (statement | NEWLINE | TAB NEWLINE)*;

device              : NAME;    

statement           : TAB operation (LBRAC parameter* RBRAC)? APPLY (LBRAC|LSQBRAC)? modes (RBRAC|RSQBRAC)? NEWLINE;

operation           : (COHERENT | GATE | INTERFEROMETER | MEASURE );

parameter           : ((nonnumeric | NAME | expression) (COMMA)?);

modes               : INT (COMMA INT)*;

// Expressions

expression          : LBRAC expression RBRAC                    #BracketsLabel
                    | sign expression                           #SignLabel
                    | <assoc=right> expression PWR expression   #PowerLabel
                    | expression ( TIMES | DIVIDE ) expression  #MulLabel
                    | expression ( PLUS | MINUS ) expression    #AddLabel
                    | function LBRAC expression RBRAC           #FunctionLabel
                    | number                                    #NumberLabel
                    | NAME                                      #VariableLabel
                    ;

number              : (INT|FLOAT|COMPLEX|PI);

function            : (SIN | COS | SQRT | EXP);

sign                : (PLUS | MINUS);

/*
 * Lexer Rules
 */

// Literals
fragment DIGIT      : [0-9]+;
fragment REAL       : DIGIT ('.'DIGIT)? (('e'|'E')('+'|'-')?DIGIT)?;
fragment NUMBER     : (REAL | DIGIT);
fragment IMAG       : NUMBER [jJ];

INT                 : DIGIT;
FLOAT               : REAL;
COMPLEX             : (NUMBER('+'|'-'))? IMAG;
STR                 : '"' (~["\n\r])* '"';
BOOL                : ('True'|'False');
SEQUENCE            : NUMBER (','NUMBER)*;
PI                  : 'pi';

// Whitespace
NEWLINE             : ('\r\n' | 'r' | '\n') ;
TAB                 : ('\t'  | '    ') ;
SPACE               : [ \t]+ -> skip;

// Keywords
WITH                : 'with';

// Quantum operations
COHERENT            : 'Coherent';
GATE                : [A-Za-z]+'gate';
MEASURE             : 'Measure'+[A-Za-z]+;
INTERFEROMETER      : 'Interferometer';

// Functions
SQRT                : 'sqrt' ;
SIN                 : 'sin' ;
COS                 : 'cos' ;
EXP                 : 'exp' ;

// Operators
PLUS                : '+';
MINUS               : '-';
TIMES               : '*';
DIVIDE              : '/';
PWR                 : '**';
ASSIGN              : '=';

// Punctuation and delimeters
PERIOD              : '.' ;
COMMA               : ',' ;
COLON               : ':' ;
QUOTE               : '"' ;
LBRAC               : '(' ;
RBRAC               : ')' ;
LSQBRAC             : '[' ;
RSQBRAC             : ']' ;
APPLY               : '|' ;

// Type declarations
TYPE_ARRAY          : 'array';
TYPE_FLOAT          : 'float';
TYPE_COMPLEX        : 'complex';
TYPE_INT            : 'int';
TYPE_STR            : 'str';
TYPE_BOOL           : 'bool';

// Comments
COMMENT             : '#' ~[\r\n]* -> skip;

// Variable names
NAME                : [A-Za-z][0-9A-Za-z_]*;

// Invalid characters
ANY                 : . ;
