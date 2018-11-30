grammar blackbird;

/*
 * Parser Rules
 */

start               : varblock program NEWLINE* EOF;

// Variable declaration

varblock            : (NEWLINE | var_list+=expressionvar | array_list+=arrayvar)*;

expressionvar       : vartype name ASSIGN (expression | nonnumeric);

arrayvar            : vartype TYPE_ARRAY name (LSQBRAC shape RSQBRAC)? ASSIGN NEWLINE arrayval;

name                : NAME;

vartype             : (TYPE_ARRAY|TYPE_FLOAT|TYPE_COMPLEX|TYPE_INT|TYPE_STR|TYPE_BOOL);

nonnumeric          : (STR|BOOL);

shape               : INT (COMMA INT)*;

arrayval            : (TAB row_list+=arrayrow NEWLINE)*;

arrayrow            : expression (COMMA expression)*;

// Blackbird program

program             : WITH device arguments? COLON NEWLINE (statement_list+=statement | NEWLINE | TAB NEWLINE)*;

device              : (NAME|DEVICE);

statement           : TAB (operation | measure) arguments? APPLY (LBRAC|LSQBRAC)? modes (RBRAC|RSQBRAC)? NEWLINE;

operation           : NAME;

measure             : MEASURE;

// arguments           : (LBRAC (val|kwarg) (COMMA (val|kwarg))* RBRAC);
arguments           : (LBRAC (val_list+=val (COMMA val_list+=val)*)? (kwarg_list+=kwarg (COMMA kwarg_list+=kwarg)*)? RBRAC);

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
                    | NAME                                      #VariableLabel
                    ;

number              : (INT|FLOAT|COMPLEX|PI);

function            : (SIN | COS | SQRT | EXP);

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
NEWLINE             : ('\r\n' | 'r' | '\n') ;
TAB                 : ('\t'  | '    ') ;
SPACE               : [ \t]+ -> skip;

// Keywords
WITH                : 'with';

// Functions
SQRT                : 'sqrt' ;
SIN                 : 'sin' ;
COS                 : 'cos' ;
EXP                 : 'exp' ;

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

// Variable names
MEASURE             : 'Measure'[A-Za-z];
NAME                : [A-Za-z][0-9A-Za-z_]*;
DEVICE              : [0-9A-Za-z._]+;

// Comments
COMMENT             : '#' ~[\r\n]* -> skip;

// Invalid characters
ANY                 : . ;
