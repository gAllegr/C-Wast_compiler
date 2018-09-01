#include "list.h"

#ifndef AST_H
#define AST_H

/* Enumeration of possible nodes in syntax tree*/
typedef enum SyntaxType {
    N_CONSTANT,
    N_VARIABLE,             /* variable usage */
    N_DEF_VARIABLE,         /* variable definition */
    N_UNARY_EXPR,
    N_BINARY_EXPR,
    N_ASSIGNMENT,
    N_IF_STATEMENT,
    N_FOR_STATEMENT,
    N_RETURN_STATEMENT,
    N_BUILTIN_STATEMENT,    /* printf/scanf functions */
    N_STATEMENTS,           /* sequence of statements */
    N_PARAMETERS,
    N_DEF_FUNCTION,         /* function definition */
    N_ARGUMENTS,
    N_CALL_FUNCTION,        /* function call */
    N_LIST_FUNCTION,        /* list of functions */
    N_LIST_DECLARATION,     /* list of declarations */
    N_BODY,                  /* body of program */
    N_ROOT                  /* list of global variables and functions */
};

/* Enumeration for unary expression */
typedef enum UnaryExprType {
    U_INC,
    U_DEC,
    U_REV,
    U_NOT
};

/* Enumeration for binary expression */
typedef enum BinaryExprType {
    B_ADD,
    B_SUB,
    B_MUL,
    B_DIV,
    B_EQ,
    B_NE,
    B_LT,
    B_LE,
    B_GT,
    B_GE,
    B_AND,
    B_OR
};

/* Enumeration for built-in function */
typedef enum BuiltinFunction {
    F_PRINTF,
    F_SCANF
};

/* Enumeration for value types */
typedef enum ValType {
    T_VOID,
    T_INT,
    T_FLOAT,
    T_CHAR,
    T_STRING
};

/* Declare Abstract Syntax Tree */
struct Syntax;
typedef struct Syntax AST;

/* Define all kinds of nodes */
typedef struct AST_Const {
    ValType type;
    union {
        int ival;
        float fval;
        char cval;
        char *sval;
    };
} AST_Const;

typedef struct AST_Variable {
    char *name;
    ValType type;
    int n;                  /* array index or array size (-1 if not array) */
} AST_Variable;

typedef struct AST_Def_Variable {
    AST_Variable *var_name;
    AST *init_value;        /* inizialization */
} AST_Def_Variable;

typedef struct AST_Unary_Expr {
    UnaryExprType unary_type;
    AST *expression;
} AST_Unary_Expr;

typedef struct AST_Binary_Expr {
    BinaryExprType binary_type;
    AST *right;
    AST *left;
} AST_Binary_Expr;

typedef struct AST_Assign {
    AST_Variable *variable;
    AST *expression;
} AST_Assign;

typedef struct AST_If_Stat {
    AST *condition;
    AST_Statements *then_branch;
    AST_Statements *else_branch;
} AST_If_Stat;

typedef struct AST_For_Stat {
    AST *init;
    AST *condition;
    AST *increment;
    AST_Statements *loop;          /* body of for-loop */
} AST_For_Stat;

typedef struct AST_Return_Stat {
    AST *expression;
} AST_Return_Stat;

typedef struct AST_Builtin_Stat {
    BuiltinFunction function;
    AST *content;
    AST *variables;
} AST_Builtin_Stat;

typedef struct AST_Parameters {
    List *parameters;
} AST_Parameters;

typedef struct AST_Statements {
    List *statements;
} AST_Statements;

typedef struct AST_Def_Function {
    AST_Variable *func_name;
    AST_Parameters *parameters;
    AST_Body *body;
} AST_Def_Function;

typedef struct AST_Arguments {
    List *arguments;
} AST_Arguments;

typedef struct AST_Call_Function {
    AST_Variable *func_name;
    AST_Arguments *arguments;
} AST_Call_Function;

typedef struct AST_List_Function {
    List *functions;
} AST_List_Function;

typedef struct AST_List_Declaration {
    List *declaration;
} AST_List_Declaration;

typedef struct AST_Body {
    AST_List_Declaration *declarations;
    AST_Statements *statements;
} AST_Body;

typedef struct AST_Root {
    AST_List_Declaration *global_declaration;
    AST_List_Function *functions;
} AST_Root;

/* Define Abstract Syntax Tree structure */
struct AST {
    SyntaxType type;
    union {
        AST_Const *ast_constant;
        AST_Variable *ast_variable;
        AST_Def_Variable *ast_def_variable;
        AST_Unary_Expr *ast_unary_expr;
        AST_Binary_Expr *ast_binary_expr;
        AST_Assign *ast_assign;
        AST_If_Stat *ast_if_stat; 
        AST_For_Stat *ast_for_stat;
        AST_Return_Stat *ast_return_stat;
        AST_Builtin_Stat *ast_builtin_stat;
        AST_Parameters *ast_parameters;
        AST_Statements *ast_statements;
        AST_Def_Function *ast_def_function;
        AST_Arguments *ast_arguments;
        AST_Call_Function *ast_call_function;
        AST_List_Function *ast_list_function;
        AST_List_Declaration *ast_list_declaration;
        AST_Root *ast_root;
    };
};

/* Functions */
AST *new_AST_Const(ValType type, char *value);
AST *new_AST_Variable(char *name, ValType type, int n);
AST *new_AST_Def_Variable (AST_Variable *var_name, AST *init_value);
AST *new_AST_Unary_Expr (UnaryExprType unary_type, AST *expression);
AST *new_AST_Binary_Expr (BinaryExprType binary_type, AST *right, AST *left);
AST *new_AST_Assign (AST_Variable *variable, AST *expression);
AST *new_AST_If_Stat (AST *condition, AST_Statements *then_branch, AST_Statements *else_branch);
AST *new_AST_For_Stat (AST *init, AST *condition, AST *increment, AST_Statements *loop);
AST *new_AST_Return_Stat (AST *expression);
AST *new_AST_Builtin_Stat (BuiltinFunction function, AST *content, AST *variables);
AST *new_AST_Parameters (List *parameters);
AST *new_AST_Statements (List *statements);
AST *new_AST_Def_Function (AST_Variable *func_name, AST_Parameters *parameters, AST_Body *body);
AST *new_AST_Arguments (List *arguments);
AST *new_AST_Call_Function (AST_Variable *func_name, AST_Arguments *arguments);
AST *new_AST_List_Function (List *functions);
AST *new_AST_List_Declaration (List *declaration);
AST *new_AST_Body (AST_List_Declaration *declarations, AST_Statements *statements);
AST *new_AST_Root (AST_List_Declaration *global_declaration, AST_List_Function *functions);

void syntax_free(AST *ast);
char *syntax_type_name(AST *ast);
void print_syntax(AST *ast);

#endif