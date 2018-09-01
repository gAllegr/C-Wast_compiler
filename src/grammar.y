%{
	/* CONTENT TO BE COPIED AT THE BEGINNING */

    #define YYSTYPE char*

	/* include directives */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../src/utils.h"

	int yylex();
    /* Variable needed for debugging */
	//int yydebug = 1;
%}

/* BISON DECLARATION */
/* Braces declarations */
%token O_CURLY_BRACES C_CURLY_BRACES O_SQUARE_BRACES C_SQUARE_BRACES O_ROUND_BRACES C_ROUND_BRACES
/* Punctuation */
%token DOT COMMA SEMICOLON E_COMM
/* Mathematical operators */
%token ASSIGN
%token ADD SUB TIMES DIVIDE INCR
/* Relational and logical operators */
%token EQOP RELOP AND OR NOT
/* Flow modifier keywords */
%token IF ELSE FOR
/* I/O keywords */
%token PRINTF SCANF
/* Function and variable keywords */
%token IDENTIFIER RETURN VOID INT FLOAT CHAR STRUCT
/* Value keywords */
%token ICONST FCONST CCONST STRCONST

/* Precedence rules */
%nonassoc IFX
%nonassoc ELSE
%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQOP
%left RELOP
%left ADD SUB
%left TIMES DIVIDE
%right NOT E_COMM REV
%left DOT INCR O_ROUND_BRACES C_ROUND_BRACES O_SQUARE_BRACES C_SQUARE_BRACES

%start program

/* Translation rules */
%%
/* Stream identifies the whole C program submitted for compilation
C language is a procedural language, it only allows declarations and functions */
program: functions
            {
                printf("\n\n|%s|\n",$$);
            }   
        | declarations functions
            {
                $$ = concat(2,$1,$2);
                printf("\n\n|%s|\n",$$);
            }
        ;

/* Recursion allows sequences of declarations */
declarations: declaration
            | declarations declaration
                {
                    $$ = concat(2,$1,$2);
                }
            ;

/* Variable declaration or struct declaration */
declaration: var_type var_decl SEMICOLON
                {
                    $$ = concat(3,$1,$2,$3);
                }
            | struct_declaration SEMICOLON
                {
                    $$ = concat(2,$1,$2);
                }
             ;

/* Recursion allows to define both simple declaration and declaration with assignment */
var_decl: simple_declaration
        | assignment
        | var_decl COMMA var_decl
            {
                $$ = concat(3,$1,$2,$3);
            }
    ;

/* The empty rule is necessary for struct_declaration rule */
simple_declaration: /* empty */
                        {
                            $$ = "";
                        }
                    | identifier
                    ;

/* Declaration of a struct table */
struct_declaration: STRUCT identifier O_CURLY_BRACES declarations C_CURLY_BRACES var_decl
                    {
                        $$ = concat(6,$1,$2,$3,$4,$5,$6);
                    }
                  ;

/* inizialization_list is used to inizializate an array or a struct */
inizialization_list: identifier
                   | const
                   | STRCONST
                   | O_CURLY_BRACES inizialization_list COMMA inizialization_list C_CURLY_BRACES
                        {
                            $$ = concat(5,$1,$2,$3,$4,$5);
                        }
                   | inizialization_list COMMA inizialization_list
                        {
                            $$ = concat(3,$1,$2,$3);
                        }
                    ;

/* List of functions */
functions: func_definition
         | functions func_definition
            {
                $$ = concat(2,$1,$2);
            }
         ;

/* Function definition */
func_definition: var_type identifier O_ROUND_BRACES argument_list C_ROUND_BRACES O_CURLY_BRACES body C_CURLY_BRACES
                    {
                        $$ = concat(8,$1,$2,$3,$4,$5,$6,$7,$8);
                    }
               ;

/* Function can have an empty/void argument or a list of arguments */
argument_list: /* empty */
                {
                    $$ = "";
                }
             | VOID
             | parameter_list
             ;

/* Argument list can be composed of a single parameter or of a comma-separated list of parameters */
parameter_list: parameter_declaration
              | parameter_list COMMA parameter_declaration
                {
                    $$ = concat(3,$1,$2,$3);
                }
              ;

/* Single parameter within definition can be a variable type, or a variable type followed by the identifier */
parameter_declaration: var_type identifier
                        {
                            $$ = concat(2,$1,$2);
                        }
                     ;

/* What is inside a function */
body: statements
    | declarations statements
        {
            $$ = concat(2,$1,$2);
        }
    ;

/* List of statements */
statements: statement
          | statements statement
            {
                $$ = concat(2,$1,$2);
            }
          ;

/* Statement is the single line instruction
- assignment rule covers both assignment and mathematical operation */
statement: SEMICOLON
         | func_call SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         | assignment SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         | increment SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         | printf_stat SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         | scanf_stat SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         | if_stat
         | for_stat
         | return_stat SEMICOLON
            {
                $$ = concat(2,$1,$2);
            }
         ;

/* Function calling */
func_call: identifier O_ROUND_BRACES call_args C_ROUND_BRACES
            {
                $$ = concat(4,$1,$2,$3,$4);
            }
         | identifier ASSIGN identifier O_ROUND_BRACES call_args C_ROUND_BRACES
            {
                $$ = concat(6,$1,$2,$3,$4,$5,$6);
            }
         ;

/* List of argument to pass to function
Arguments can be passed only by value */
call_args: /* empty */
            {
                $$ = "";
            }
         | identifier
         | call_args COMMA identifier
            {
                $$ = concat(3,$1,$2,$3);
            }
         ;

/* 
    ==== DECLARATION ====
    A simple identifier can be valorized by a constant or an expression
    An array can be valorized by an array content
    ==== FUNCTIONS ====
    Includes mathematical operations (2° rule)
    Includes assignment
    ==== FOR ====
    Assignment can be empty for for-instruction
*/
assignment: identifier ASSIGN word
            {
                $$ = concat(3,$1,$2,$3);
            }
          | identifier ASSIGN expr
            {
                $$ = concat(3,$1,$2,$3);
            }
          | identifier ASSIGN O_CURLY_BRACES inizialization_list C_CURLY_BRACES
            {
                $$ = concat(5,$1,$2,$3,$4,$5);
            }
          ;

/* Mathematical and relational expression
Identifiers must be integer or float type */
expr: expr ADD expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr SUB expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr TIMES expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr DIVIDE expr
        {
            $$ = concat(3,$1,$2,$3);
        }
    | SUB expr %prec REV
        {
            $$ = concat(2,$1,$2);
        }
    | increment
	| expr EQOP expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr RELOP expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr AND expr
        {
            $$ = concat(3,$1,$2,$3);
        }
	| expr OR expr
        {
            $$ = concat(3,$1,$2,$3);
        }
    | NOT expr
        {
            $$ = concat(2,$1,$2);
        }
	| O_ROUND_BRACES expr C_ROUND_BRACES
        {
            $$ = concat(3,$1,$2,$3);
        }
    | number
    | identifier
    ;

/* Increment covers both ++ and -- */
increment: identifier INCR
            {
                $$ = concat(2,$1,$2);
            }
         ;

/* Printf function, allows to print out more than one variable */
printf_stat: PRINTF O_ROUND_BRACES word C_ROUND_BRACES
                {
                    $$ = concat(4,$1,$2,$3,$4);
                }
            | PRINTF O_ROUND_BRACES STRCONST COMMA printed_var C_ROUND_BRACES
                {
                    $$ = concat(6,$1,$2,$3,$4,$5,$6);
                }
            ;

/* Recursion allows to print out many variables */
printed_var: identifier
           | printed_var COMMA printed_var
                {
                    $$ = concat(3,$1,$2,$3);
                }
           ;

/* Scanf function allow MAX ONLY ONE variable to be scanned in */
scanf_stat: SCANF O_ROUND_BRACES STRCONST COMMA retrieved_var C_ROUND_BRACES
                {
                    $$ = concat(6,$1,$2,$3,$4,$5,$6);
                }
          ;

/* Recursion allows to retrieve more than one value with a single scanf instruction */
retrieved_var: E_COMM identifier
                {
                    $$ = concat(2,$1,$2);
                }
              | retrieved_var COMMA retrieved_var
                {
                    $$ = concat(3,$1,$2,$3);
                }
              ;

/* IF statements allows nested IF
IF statement supports :
- only then-branch with single/multiple instruction
- both then-branch and else-branch with single/multiple instruction */
if_stat: IF O_ROUND_BRACES expr C_ROUND_BRACES block %prec IFX
            {
                $$ = concat(5,$1,$2,$3,$4,$5);
            }
        | IF O_ROUND_BRACES expr C_ROUND_BRACES block ELSE block
            {
                $$ = concat(7,$1,$2,$3,$4,$5,$6,$7);
            }
        ;

/* THEN-branch and ELSE-branch of IF statement can include a single statement or a sequence of statements */
block: statement
     | O_CURLY_BRACES statements C_CURLY_BRACES
        {
            $$ = concat(3,$1,$2,$3);
        }
     ;

/* FOR loop rule
Condition must be checked to be a conditional statement, not a math expression
Condition cannot use comma to separate conditions */
for_stat: FOR O_ROUND_BRACES init_for SEMICOLON expr SEMICOLON incr_for C_ROUND_BRACES block
            {
                $$ = concat(9,$1,$2,$3,$4,$5,$6,$7,$8,$9);
            }
        ;

/* Inizialization of for loop can be :
- empty (variable is inizializated to 0)
- a comma-separated list of inizialited variables */
init_for: /* empty */
            {
                $$ = "";
            }
        | assignment
        | init_for COMMA init_for
            {
                $$ = concat(3,$1,$2,$3);
            }
        ;

/* Increment of conditional variables used in for loop.
It can be a comma-separated list of incrementation statements */
incr_for: expr
        | incr_for COMMA incr_for
            {
                $$ = concat(3,$1,$2,$3);
            }
        ;

/* Return statement */
return_stat: RETURN
           | RETURN const
               {
                   $$ = concat(2,$1,$2);
               }
           | RETURN identifier
               {
                   $$ = concat(2,$1,$2);
               }
           ;

/* Variables can be of integer, float or char type
Functions can be also void
For variables defined starting from a struct, there is another type */
var_type: VOID
        | INT
        | FLOAT
        | CHAR
        | STRUCT identifier
            {
                $$ = concat(2,$1,$2);
            }
        ;

/* The identifier can be :
- a simple identifier for usual variables
- an array with definied dimension
- a dotted identifier for struct variables */
identifier: IDENTIFIER
          | identifier O_SQUARE_BRACES ICONST C_SQUARE_BRACES
            {
                $$ = concat(4,$1,$2,$3,$4);
            }
          | identifier O_SQUARE_BRACES identifier C_SQUARE_BRACES
            {
                $$ = concat(4,$1,$2,$3,$4);
            }
          | identifier DOT identifier
            {
                $$ = concat(3,$1,$2,$3);
            }
          ;

/* Basic constant */
const: ICONST
     | FCONST
     | CCONST
     ;

/* Char and String constants */
word: CCONST
    | STRCONST
    ;

/* Integer and float constant */
number: ICONST
      | FCONST
      ;

%%
