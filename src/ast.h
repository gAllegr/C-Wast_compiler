#include "list.h"

#ifndef AST_H
#define AST_H

/* Enumeration of possible nodes in syntax tree*/
typedef enum AstType {
    N_CONSTANT,
    N_VARIABLE,
    N_STRUCT,               /* definiton of struct */
    N_VAR_STRUCT,           /* variable of type "struct identifier" */   
    N_UNARY_EXPR,
    N_BINARY_EXPR,
    N_ASSIGNMENT,
    N_IF_STATEMENT,
    N_FOR_STATEMENT,
    N_RETURN_STATEMENT,
    N_BUILTIN_STATEMENT,    /* printf/scanf functions */
    N_LIST,
    N_DEF_FUNCTION,         /* function definition */
    N_CALL_FUNCTION,        /* function call */
    N_BODY,                 /* body of program */
    N_ROOT                  /* list of global variables and functions */
} AstType;

/* Enumeration for unary expression */
typedef enum UnaryExprType {
    U_INC,
    U_DEC,
    U_REV,
    U_NOT
} UnaryExprType;

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
} BinaryExprType;

/* Enumeration for built-in function */
typedef enum BuiltinFunction {
    F_PRINTF,
    F_SCANF
} BuiltinFunction;

/* Enumeration for value types */
typedef enum ValType {
    T_VOID,
    T_INT,
    T_FLOAT,
    T_CHAR,
    T_STRUCT,
    T_NULL          /* to be used if we don't know type */
} ValType;

/* Declare Abstract Syntax Tree */
struct AST;
typedef struct AST AST;

/* Define all kinds of nodes */
typedef struct AST_Const {
    ValType type;
    union {
        int ival;
        float fval;
        char *sval;
    };
} AST_Const;

typedef struct AST_Variable {
    char *name;
    int n;              /* array index or array size (-1 if not array) */
    ValType type;
} AST_Variable;

typedef struct AST_Struct {
    char *name;
    ValType type;
    List *declarations;
} AST_Struct;

typedef struct AST_Var_Struct {
    AST *def_struct;
    char *name;         // name or element of struct variable
    int n;
} AST_Var_Struct;

typedef struct AST_Unary_Expr {
    UnaryExprType unary_type;
    AST *expression;
} AST_Unary_Expr;

typedef struct AST_Binary_Expr {
    BinaryExprType binary_type;
    AST *left;
    AST *right;
} AST_Binary_Expr;

typedef struct AST_Assign {
    AST *variable;          /* AST_Variable */
    AST *expression;
} AST_Assign;

typedef struct AST_If_Stat {
    AST *condition;
    AST *then_branch;          /* AST_Statements */
    AST *else_branch;          /* AST_Statements */
} AST_If_Stat;

typedef struct AST_For_Stat {
    List *init;
    AST *condition;
    List *increment;
    AST *loop;          /* body of for-loop, AST_Statements */
} AST_For_Stat;

typedef struct AST_Return_Stat {
    AST *expression;
} AST_Return_Stat;

typedef struct AST_Builtin_Stat {
    BuiltinFunction function;
    AST *content;
    List *variables;
} AST_Builtin_Stat;

typedef struct AST_List {
    List *list;
} AST_List;

typedef struct AST_Def_Function {
    AST *func_name;     /* AST_Variable */
    AST *parameters;    /* AST_List */
    AST *body;          /* AST_Body */
} AST_Def_Function;

typedef struct AST_Call_Function {
    AST *func_name;     /* AST_Variable */
    List *arguments;
} AST_Call_Function;

typedef struct AST_Body {
    List *declarations;
    List *statements;
} AST_Body;

typedef struct AST_Root {
    List *global_declaration;
    List *functions;
} AST_Root;

/* Define Abstract Syntax Tree structure */
struct AST {
    AstType type;
    union {
        AST_Const *ast_constant;
        AST_Variable *ast_variable;
        AST_Struct *ast_struct;
        AST_Var_Struct *ast_var_struct;
        AST_Unary_Expr *ast_unary_expr;
        AST_Binary_Expr *ast_binary_expr;
        AST_Assign *ast_assign;
        AST_If_Stat *ast_if_stat; 
        AST_For_Stat *ast_for_stat;
        AST_Return_Stat *ast_return_stat;
        AST_Builtin_Stat *ast_builtin_stat;
        AST_List *ast_list;
        AST_Def_Function *ast_def_function;
        AST_Call_Function *ast_call_function;
        AST_Body *ast_body;
        AST_Root *ast_root;
    };
};

/* Functions */
AST *new_AST_Const(ValType type, char *value);
AST *new_AST_Variable (char *name, int n, ValType type);
AST *new_AST_Struct (char *name, ValType type, List *declarations);
AST *new_AST_Var_Struct (AST *def_struct, char *name, int n);
AST *new_AST_Unary_Expr (UnaryExprType unary_type, AST *expression);
AST *new_AST_Binary_Expr (BinaryExprType binary_type, AST *right, AST *left);
AST *new_AST_Assign (AST *variable, AST *expression);
AST *new_AST_If_Stat (AST *condition, AST *then_branch, AST *else_branch);
AST *new_AST_For_Stat (List *init, AST *condition, List *increment, AST *loop);
AST *new_AST_Return_Stat (AST *expression);
AST *new_AST_Builtin_Stat (BuiltinFunction function, AST *content, List *variables);
AST *new_AST_List (List *list);
AST *new_AST_Def_Function (AST *func_name, AST *parameters, AST *body);
AST *new_AST_Call_Function (AST *func_name, List *arguments);
AST *new_AST_Body (List *declarations, List *statements);
AST *new_AST_Root (List *global_declaration, List *functions);

void free_ast(AST *ast);
void print_ast(AST *ast, int indent);

#endif