%{
	/* CONTENT TO BE COPIED AT THE BEGINNING */


	/* include directives */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../src/utils.h"
    #include "../src/ast.h"
    #include "../src/list.h"
    #include "../src/symtab.h"

	int yylex();
    void yyerror (const char *s);
    /* Variable needed for debugging */
//	int yydebug = 1;

    // Abstract Syntax Tree
    AST *ast;
%}

// Definition of possible rule types
%union {
    char *sval;
    List *list;
    AST *node;
    int operator;
    int builtin;
    int value_type;
}

/* BISON DECLARATION */
/* Braces declarations */
%token <sval> O_CURLY_BRACES C_CURLY_BRACES O_SQUARE_BRACES C_SQUARE_BRACES O_ROUND_BRACES C_ROUND_BRACES
/* Punctuation */
%token <sval> DOT COMMA SEMICOLON E_COMM ASSIGN
/* Mathematical operators */
%token <operator>  ADD SUB TIMES DIVIDE INCR
/* Relational and logical operators */
%token <operator> EQOP RELOP AND OR NOT
/* Flow modifier keywords */
%token <sval> IF ELSE FOR
/* I/O keywords */
%token <builtin> PRINTF SCANF
/* Function and variable keywords */
%token <sval> IDENTIFIER RETURN
%token <value_type> VOID INT FLOAT CHAR STRUCT
/* Value keywords */
%token <sval> ICONST FCONST CCONST STRCONST

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

%type <node> program body statement block
%type <node> simple_declaration  
%type <node> func_definition argument_list parameter_declaration func_call 
%type <node> assignment expr increment return_stat printf_stat scanf_stat if_stat for_stat
%type <node> identifier const word number
%type <list> declarations declaration var_decl struct_declaration inizialization_list
%type <list> functions parameter_list statements call_args printed_var retrieved_var incr_for init_for
%type <value_type> var_type

%start program

/* Translation rules */
%%
/* Stream identifies the whole C program submitted for compilation
C language is a procedural language, it only allows declarations and functions */
program: functions
            {
                ast = new_AST_Root(list_new(), $1);
                $$ = ast;
            }   
        | declarations functions
            {
                ast = new_AST_Root($1, $2);
                $$ = ast;
            }
        ;

/* Recursion allows sequences of declarations */
declarations: declaration
            | declarations declaration
                {
                    $$ = list_merge($1,$2);
                }
            ;

/* Variable declaration or struct declaration */
declaration: var_type var_decl SEMICOLON
                {
                    int size = list_length($2),i;
                    // update variable nodes with associated type
                    for(i=0;i<size;i++) {
                        AST *obj = list_get($2,i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                obj->ast_variable->sym_variable->type = $1;
                                break;
                            case N_ASSIGNMENT:
                                obj->ast_assign->variable->ast_variable->sym_variable->type = $1;
                                break;
                        }
                        $2->items[i] = obj;
                    }
                    // associate updated list at head of rule
                    $$ = $2;
                }
            | struct_declaration SEMICOLON
            ;

/* Recursion allows to define both simple declaration and declaration with assignment */
var_decl: simple_declaration
            {
                if($1 != NULL)
                {
                    List *var_list = list_new();
                    list_append(var_list, $1);
                    $$ = var_list;
                }
                else $$ = NULL;
            }
        | assignment
            {
                List *var_list = list_new();
                list_append(var_list, $1);
                $$ = var_list;
            }
        | var_decl COMMA var_decl
            {
                $$ = list_merge($1,$3);
            }
    ;

/* The empty rule is necessary for struct_declaration rule */
simple_declaration: /* empty */         { $$ = NULL; }
                    | identifier
                    ;

/* Declaration of a struct table */
struct_declaration: STRUCT identifier O_CURLY_BRACES declarations C_CURLY_BRACES var_decl
                    {
                        if($6 != NULL)
                        {
                            List *elements = convert($4);

                            AST *a;
                            for(int i=0; i<list_length($6);i++)
                            {
                                a = list_get($6,i);
                                if(a->type == N_VARIABLE)
                                {
                                    int n = a->ast_variable->sym_variable->n;
                                    List *e = prepare_struct_elements(n, elements);

                                    a->ast_variable->sym_variable->s_info = new_struct_info($2->ast_variable->sym_variable->name, e);
                                    a->ast_variable->sym_variable->type = $1;
                                }
                                
                                if(a->type == N_ASSIGNMENT)
                                {
                                    int n = a->ast_assign->variable->ast_variable->sym_variable->n;
                                    List *e = prepare_struct_elements(n, elements);

                                    a->ast_assign->variable->ast_variable->sym_variable->s_info = new_struct_info($2->ast_variable->sym_variable->name, e);
                                    a->ast_assign->variable->ast_variable->sym_variable->type = $1;
                                }
                            }
                        }

                        $$ = $6;
                    }
                  ;

/* inizialization_list is used to inizializate an array or a struct */
inizialization_list: identifier
                        {
                            List *init_list = list_new();
                            list_append(init_list, $1);
                            $$ = init_list;
                        }
                   | const
                        {
                            List *init_list = list_new();
                            list_append(init_list, $1);
                            $$ = init_list;
                        }
                   | STRCONST
                        {
                            List *init_list = list_new();
                            list_append(init_list, $1);
                            $$ = init_list;
                        }
                   | O_CURLY_BRACES inizialization_list COMMA inizialization_list C_CURLY_BRACES
                        {
                            list_merge($2,$4);
                            AST *init = new_AST_List($2);
                            List *array_el = list_new();
                            list_append(array_el,init);
                            $$ = array_el;
                        }
                   | inizialization_list COMMA inizialization_list
                        {
                            $$ = list_merge($1,$3);
                        }
                    ;

/* List of functions */
functions: func_definition
            {
                List *func = list_new();
                list_append(func, $1);
                $$ = func;
            }
         | functions func_definition
            {
                list_append($1, $2);
                $$ = $1;
            }
         ;

/* Function definition */
func_definition: var_type identifier
                 {
                    $2->ast_variable->sym_variable->type = $1;
                    $<node>$ = new_AST_Def_Function($2);
                 }
                 O_ROUND_BRACES argument_list C_ROUND_BRACES O_CURLY_BRACES body C_CURLY_BRACES
                    {
                        if($5 != NULL) $<node>3->ast_def_function->sym_function->parameters = convert($5->ast_list->list);
                        $<node>3->ast_def_function->body = $8;
                        $$ = $<node>3;
                    }
               ;

/* Function can have an empty/void argument or a list of arguments */
argument_list: /* empty */        {$$ = NULL;}
             | VOID               {$$ = NULL;}
             | parameter_list
                {
                    $$ = new_AST_List($1);
                }       
             ;

/* Argument list can be composed of a single parameter or of a comma-separated list of parameters */
parameter_list: parameter_declaration
                {
                    List *param = list_new();
                    list_append(param, $1);
                    $$ = param;
                }
              | parameter_list COMMA parameter_declaration
                {
                    list_append($1, $3);
                    $$ = $1;
                }
              ;

/* Single parameter within definition can be a variable type, or a variable type followed by the identifier */
parameter_declaration: var_type identifier
                        {
                            $2->ast_variable->sym_variable->type = $1;
                            $$ = $2;
                        }
                     | STRUCT identifier identifier
                        {
                            $3->ast_variable->sym_variable->type = $1;
                            $3->ast_variable->sym_variable->s_info = new_struct_info($2->ast_variable->sym_variable->name, NULL);
                        }
                     ;

/* What is inside a function */
body: statements                    { $$ = new_AST_Body(list_new(),$1); }
    | declarations statements       { $$ = new_AST_Body($1,$2); }
    ;

/* List of statements */
statements: statement
            {
                List *stats = list_new();
                list_append(stats, $1);
                $$ = stats;
            }
          | statements statement
            {
                list_append($1, $2);
                $$ = $1;
            }
          ;

/* Statement is the single line instruction
- assignment rule covers both assignment and mathematical operation */
statement: SEMICOLON                    {$$ = NULL;}
         | func_call SEMICOLON
         | assignment SEMICOLON
         | increment SEMICOLON
         | printf_stat SEMICOLON
         | scanf_stat SEMICOLON
         | if_stat
         | for_stat
         | return_stat SEMICOLON
         ;

/* Function calling */
func_call: identifier O_ROUND_BRACES call_args C_ROUND_BRACES
            {
                $$ = new_AST_Call_Function ($1,$3);
            }
         ;

/* List of argument to pass to function
Arguments can be passed only by value */
call_args: /* empty */
            {
                List *call_arg = list_new();
                $$ = call_arg;
            }
         | identifier
            {
                List *call_arg = list_new();
                list_append(call_arg, $1);
                $$ = call_arg;
            }
         | call_args COMMA identifier
            {
                list_append($1, $3);
                $$ = $1;
            }
         ;

/* 
    ==== DECLARATION ====
    A simple identifier can be valorized by a constant or an expression
    An array can be valorized by an array content
    ==== FUNCTIONS ====
    Includes mathematical operations (2° rule)
    Includes assignment
*/
assignment: identifier ASSIGN word
            {
                $$ = new_AST_Assign($1,$3);
            }
          | identifier ASSIGN expr
            {
                $$ = new_AST_Assign($1,$3);
            }
          | identifier ASSIGN O_CURLY_BRACES inizialization_list C_CURLY_BRACES
            {
                $$ = new_AST_Assign($1, new_AST_List($4));
            }
          | identifier ASSIGN func_call
            {
                $$ = new_AST_Assign ($1,$3);
            }
          ;

/* Mathematical and relational expression
Identifiers must be integer or float type */
expr: expr ADD expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr SUB expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr TIMES expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr DIVIDE expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
    | SUB expr %prec REV
        {
            $$ = new_AST_Unary_Expr ($1,$2);
        }
    | increment
	| expr EQOP expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr RELOP expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr AND expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
	| expr OR expr
        {
            $$ = new_AST_Binary_Expr($2,$1,$3);
        }
    | NOT expr
        {
            $$ = new_AST_Unary_Expr ($1,$2);
        }
	| O_ROUND_BRACES expr C_ROUND_BRACES
        {
            $$ = $2;
        }
    | number
    | identifier
    ;

/* Increment covers both ++ and -- */
increment: identifier INCR
            {
                $$ = new_AST_Unary_Expr ($2,$1);
            }
         ;

/* Printf function, allows to print out more than one variable */
printf_stat: PRINTF O_ROUND_BRACES word C_ROUND_BRACES
                {
                    $$ = new_AST_Builtin_Stat($1, $3, list_new());
                }
            | PRINTF O_ROUND_BRACES STRCONST COMMA printed_var C_ROUND_BRACES
                {
                    $$ = new_AST_Builtin_Stat($1, new_AST_Const(T_CHAR,$3), $5);
                }
            ;

/* Recursion allows to print out many variables */
printed_var: identifier
                {
                    List *prin_var = list_new();
                    list_append(prin_var, $1);
                    $$ = prin_var;
                }
           | printed_var COMMA identifier
                {
                    list_append($1,$3);
                    $$ = $1;
                }
           ;

/* Scanf function allow MAX ONLY ONE variable to be scanned in */
scanf_stat: SCANF O_ROUND_BRACES STRCONST COMMA retrieved_var C_ROUND_BRACES
                {
                    $$ = new_AST_Builtin_Stat($1, new_AST_Const(T_CHAR,$3), $5);
                }
          ;

/* Recursion allows to retrieve more than one value with a single scanf instruction */
retrieved_var: E_COMM identifier
                {
                    List *retr_var = list_new();
                    list_append(retr_var, $2);
                    $$ = retr_var;
                }
              | retrieved_var COMMA E_COMM identifier
                {
                    list_append($1,$4);
                    $$ = $1;
                }
              ;

/* IF statements allows nested IF
IF statement supports :
- only then-branch with single/multiple instruction
- both then-branch and else-branch with single/multiple instruction */
if_stat: IF O_ROUND_BRACES expr C_ROUND_BRACES block %prec IFX
            {
                $$ = new_AST_If_Stat($3,$5,NULL);
            }
        | IF O_ROUND_BRACES expr C_ROUND_BRACES block ELSE block
            {
                $$ = new_AST_If_Stat($3,$5,$7);
            }
        ;

/* THEN-branch and ELSE-branch of IF statement can include a single statement or a sequence of statements */
block: statement
     | O_CURLY_BRACES statements C_CURLY_BRACES
        {
            $$ = new_AST_List($2);
        }
     ;

/* FOR loop rule
Condition must be checked to be a conditional statement, not a math expression
Condition cannot use comma to separate conditions */
for_stat: FOR O_ROUND_BRACES init_for SEMICOLON expr SEMICOLON incr_for C_ROUND_BRACES block
            {
                $$ = new_AST_For_Stat($3,$5,$7,$9);
            }
        ;

/* Inizialization of for loop can be :
- empty (variable is inizializated to 0)
- a comma-separated list of inizialited variables */
init_for: /* empty */
            {
                List *init_list = list_new();
                $$ = init_list;
            }
        | assignment
            {
                List *init_list = list_new();
                list_append(init_list, $1);
                $$ = init_list;
            }
        | init_for COMMA init_for
            {
                $$ = list_merge($1,$3);
            }
        ;

/* Increment of conditional variables used in for loop.
It can be a comma-separated list of incrementation statements */
incr_for: expr
            {
                List *incr_list = list_new();
                list_append(incr_list, $1);
                $$ = incr_list;
            }
        | incr_for COMMA expr
            {
                list_append($1, $3);
                $$ = $1;
            }
        ;

/* Return statement */
return_stat: RETURN
                {
                    $$ = new_AST_Return_Stat(NULL);
                }
           | RETURN const
               {
                   $$ = new_AST_Return_Stat($2);
               }
           | RETURN identifier
               {
                   $$ = new_AST_Return_Stat($2);
               }
           ;

/* Variables can be of integer, float or char type
Functions can be also void */
var_type: VOID
        | INT
        | FLOAT
        | CHAR
        ;

/* The identifier can be :
- a simple identifier for usual variables
- an array with definied dimension
- a dotted identifier for struct variables */
identifier: IDENTIFIER
            {
                $$ = new_AST_Variable($1, -1, T_NULL, NULL, 0, 0);
            }
          | identifier O_SQUARE_BRACES ICONST C_SQUARE_BRACES
            {
                $1->ast_variable->sym_variable->n = atoi($3);
                $$ = $1;
            }
          | identifier O_SQUARE_BRACES identifier C_SQUARE_BRACES
            {
                // We don't save identifiers' value, so we don't know the array dimension
                $1->ast_variable->sym_variable->n = -2;
                $$ = $1;
            }
          | identifier DOT identifier
            {
                char c[50];
                char *c1,*c2;
                // name+dimension/index of first identifier
                if($1->ast_variable->sym_variable->n == -1) c1 = $1->ast_variable->sym_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", $1->ast_variable->sym_variable->name, $1->ast_variable->sym_variable->n);
                    c1 = c;
                }
                // name+dimension/index of second identifier
                if($3->ast_variable->sym_variable->n == -1) c2 = $3->ast_variable->sym_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", $3->ast_variable->sym_variable->name, $3->ast_variable->sym_variable->n);
                    c2 = c;
                }
                // concat identifiers and use it as name for AST *var_struct
                c1 = concat(3, "", c1,$2,c2);
                $$ = new_AST_Variable (c1, $1->ast_variable->sym_variable->n, T_STRUCT, NULL, 0, 0);
            }
          ;

/* Basic constant */
const: ICONST
        {
            $$ = new_AST_Const(1,$1);
        }
     | FCONST
        {
            $$ = new_AST_Const(2,$1);
        }
     | CCONST
        {
            $$ = new_AST_Const(3,$1);
        }
     ;

/* Char and String constants */
word: CCONST
        {
            $$ = new_AST_Const(3,$1);
        }
    | STRCONST
        {
            $$ = new_AST_Const(3,$1);
        }
    ;

/* Integer and float constant */
number: ICONST
        {
            $$ = new_AST_Const(1,$1);
        }
      | FCONST
        {
            $$ = new_AST_Const(2,$1);
        }
      ;

%%
void yyerror (const char *s)
{
    extern int yylineno;
	extern char* yytext;
	fprintf(stderr, "Error: %s\nLine: %d\nSymbol: %s\n", s, yylineno, yytext);
}

int main (void)
{
	// initialize symbol table
    //	init_hash_table();

	int result = yyparse();
	if(result==0)
    {
        printf("\nCORRECT SYNTAX! \\^.^/ \n");
        printf("Now I'll print the abstract syntax tree!\n\n");
        print_ast(ast,0); printf("\n");

        /* other stuff must be added */

        printf("Now I'll free memory occupied by abstract syntax tree!\n");
        free_ast(ast);
        printf("Memory is free!\n\n");
    }
	else printf("\nWRONG SYNTAX! ç.ç\n");

	// symbol table dump
    /*	yyout = fopen("symtab_dump.out w");
	symtab_dump(yyout);
	fclose(yyout);	
    */

    return result;
}
