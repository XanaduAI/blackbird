grammar blackbird;

/*
 * Parser Rules
 */

start               : NEWLINE* metadatablock NEWLINE* program NEWLINE* EOF;


// Metadata
metadatablock       : declarename NEWLINE+ version NEWLINE+ target? (NEWLINE | include_list+=include)*;

declarename         : PROGNAME programname;

programname         : NAME;

version             : VERSION versionnumber;

versionnumber       : FLOAT;

target              : TARGET device arguments?;

device              : (NAME | DEVICE);

include             : INCLUDE STR;



// Variable declaration

program             : (NEWLINE | var_list+=expressionvar | array_list+=arrayvar | statement_list+=statement)*;

expressionvar       : vartype name ASSIGN (expression | nonnumeric);

arrayvar            : vartype TYPE_ARRAY name (LSQBRAC shape RSQBRAC)? ASSIGN NEWLINE arrayval;

name                : (invalid | NAME);

invalid             : (REGREF | reserved);

reserved            : (PROGNAME | VERSION | TARGET);

vartype             : (TYPE_ARRAY|TYPE_FLOAT|TYPE_COMPLEX|TYPE_INT|TYPE_STR|TYPE_BOOL);

nonnumeric          : (STR|BOOL);

shape               : INT (COMMA INT)*;

arrayval            : (TAB row_list+=arrayrow NEWLINE)*;

arrayrow            : expression (COMMA expression)*;

statement           : (operation | measure) arguments? APPLY (LBRAC|LSQBRAC)? modes (RBRAC|RSQBRAC)? NEWLINE*;

operation           : NAME;

measure             : MEASURE;



//  function arguments

arguments           : (LBRAC (val_list+=val (COMMA val_list+=val)*)? COMMA? (kwarg_list+=kwarg (COMMA kwarg_list+=kwarg)*)? RBRAC);

kwarg               : NAME ASSIGN val;

val                 : (nonnumeric | expression);

modes               : INT (COMMA INT)*;



// Expressions

expression          : LBRAC expression RBRAC                    #BracketsLabel
                    | (PLUS | MINUS) expression                 #SignLabel
                    | <assoc=right> expression PWR expression   #PowerLabel
                    | expression ( TIMES | DIVIDE ) expression  #MulLabel
                    | expression ( PLUS | MINUS ) expression    #AddLabel
                    | function LBRAC expression RBRAC           #FunctionLabel
                    | number                                    #NumberLabel
                    | (REGREF | NAME)                           #VariableLabel
                    | LBRACE NAME RBRACE                        #ParameterLabel
                    ;

number              : (INT|FLOAT|COMPLEX|PI);

function            : SIN | COS | TAN
                    | ARCSIN | ARCCOS | ARCTAN
                    | SINH | COSH | TANH
                    | ARCSINH | ARCCOSH | ARCTANH
                    | SQRT
                    | LOG | EXP
                    ;

/*
 * Lexer Rules
 */

// Operators
PLUS                : '+';
MINUS               : '-';
TIMES               : '*';
DIVIDE              : '/';
PWR                 : '**';
ASSIGN              : '=';

// Literals
fragment DIGIT      : [0-9]+;
fragment REAL       : DIGIT ('.'DIGIT)? (('e'|'E')('+'|'-')?DIGIT)?;
fragment NUMBER     : (REAL | DIGIT);
fragment IMAG       : NUMBER [jJ];

INT                 : DIGIT;
FLOAT               : REAL;
COMPLEX             : ('+'|'-')?(NUMBER('+'|'-'))? IMAG;
STR                 : '"' (~["\n\r])* '"';
BOOL                : ('True'|'False');
SEQUENCE            : NUMBER (','NUMBER)*;
PI                  : 'pi';

// Whitespace
NEWLINE             : ('\r\n' | '\r' | '\n') ;
TAB                 : ('\t'  | '    ') ;
SPACE               : [ \t]+ -> skip;

// Keywords
PROGNAME            : 'name';
VERSION             : 'version';
TARGET              : 'target';
INCLUDE             : 'include';

// Functions
SQRT                : 'sqrt' ;
SIN                 : 'sin' ;
COS                 : 'cos' ;
TAN                 : 'tan' ;
ARCSIN              : 'arcsin' ;
ARCCOS              : 'arccos' ;
ARCTAN              : 'arctan' ;
SINH                : 'sinh' ;
COSH                : 'cosh' ;
TANH                : 'tanh' ;
ARCSINH             : 'arcsinh' ;
ARCCOSH             : 'arccosh' ;
ARCTANH             : 'arctanh' ;
EXP                 : 'exp' ;
LOG                 : 'log' ;

// Punctuation and delimeters
PERIOD              : '.' ;
COMMA               : ',' ;
COLON               : ':' ;
QUOTE               : '"' ;
LBRAC               : '(' ;
RBRAC               : ')' ;
LSQBRAC             : '[' ;
RSQBRAC             : ']' ;
LBRACE              : '{' ;
RBRACE              : '}' ;
APPLY               : '|' ;

// Type declarations
TYPE_ARRAY          : 'array';
TYPE_FLOAT          : 'float';
TYPE_COMPLEX        : 'complex';
TYPE_INT            : 'int';
TYPE_STR            : 'str';
TYPE_BOOL           : 'bool';

// Variable names
REGREF              : 'q' DIGIT;
MEASURE             : 'Measure'[A-Za-z]*;
NAME                : [A-Za-z][0-9A-Za-z_]*;
DEVICE              : [0-9A-Za-z._]+;

// Comments
COMMENT             : '#' ~[\r\n]* -> skip;

// Invalid characters
ANY                 : . ;
