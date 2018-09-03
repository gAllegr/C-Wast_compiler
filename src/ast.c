#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "list.h"

AST *new_AST_Const(ValType type, char *value)
{
    AST_Const *ast_const = malloc(sizeof(AST_Const));
    ast_const->type = type;
    switch(type) {
        case T_VOID:
            p_error("Constants cannot be void! ");
            exit(EXIT_FAILURE);
            break;
        case T_INT:
            ast_const->ival = atoi(value);
            break;
        case T_FLOAT:
            ast_const->fval = atof(value);
            break;
        case T_CHAR:
            ast_const->cval = value;
            break;
    }

    AST *ast = malloc(sizeof(AST));
    ast->type = N_CONSTANT;
    ast->ast_constant = ast_const;

    return ast;
}

AST *new_AST_Variable(char *name, int n)
{
    AST_Variable *ast_variable = malloc(sizeof(AST_Variable));
    ast_variable->name = name;
    ast_variable->n = n;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_VARIABLE;
    ast->ast_variable = ast_variable;

    return ast;
}

AST *new_AST_Dec_Variable (char *name, int n, ValType type, AST *init_value)
{
    AST_Dec_Variable *ast_dec_variable = malloc(sizeof(AST_Dec_Variable));
    ast_dec_variable->var_name = new_AST_Variable(name,n);
    ast_dec_variable->type = type;
    ast_dec_variable->init_value = init_value;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_DEC_VARIABLE;
    ast->ast_dec_variable = ast_dec_variable;

    return ast;
}

AST *new_AST_Unary_Expr (UnaryExprType unary_type, AST *expression)
{
    AST_Unary_Expr *ast_unary_expr = malloc(sizeof(AST_Unary_Expr));
    ast_unary_expr->unary_type = unary_type;
    ast_unary_expr->expression = expression;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_UNARY_EXPR;
    ast->ast_unary_expr = ast_unary_expr;

    return ast;
}

AST *new_AST_Binary_Expr (BinaryExprType binary_type, AST *right, AST *left)
{
    AST_Binary_Expr *ast_binary_expr = malloc(sizeof(AST_Binary_Expr));
    ast_binary_expr->binary_type = binary_type;
    ast_binary_expr->right = right;
    ast_binary_expr->left = left;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_BINARY_EXPR;
    ast->ast_binary_expr = ast_binary_expr;

    return ast;
}

AST *new_AST_Assign (AST *variable, AST *expression)
{
    AST_Assign *ast_assign = malloc(sizeof(AST_Assign));
    ast_assign->variable = variable;
    ast_assign->expression = expression;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_ASSIGNMENT;
    ast->ast_assign = ast_assign;

    return ast;    
}

AST *new_AST_If_Stat (AST *condition, AST *then_branch, AST *else_branch)
{
    AST_If_Stat *ast_if = malloc(sizeof(AST_If_Stat));
    ast_if->condition = condition;
    ast_if->then_branch = then_branch;
    ast_if->else_branch = else_branch;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_IF_STATEMENT;
    ast->ast_if_stat = ast_if;

    return ast;
}

AST *new_AST_For_Stat (AST *init, AST *condition, AST *increment, AST *loop)
{
    AST_For_Stat *ast_for = malloc(sizeof(AST_For_Stat));
    ast_for->init = init;
    ast_for->condition = condition;
    ast_for->increment = increment;
    ast_for->loop = loop;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_FOR_STATEMENT;
    ast->ast_for_stat = ast_for;

    return ast;
}

AST *new_AST_Return_Stat (AST *expression)
{
    AST_Return_Stat *ast_return = malloc(sizeof(AST_Return_Stat));
    ast_return->expression = expression;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_RETURN_STATEMENT;
    ast->ast_return_stat = expression;

    return ast;
}

AST *new_AST_Builtin_Stat (BuiltinFunction function, AST *content, AST *variables)
{
    AST_Builtin_Stat *ast_builtin = malloc(sizeof(AST_Builtin_Stat));
    ast_builtin->function = function;
    ast_builtin->content = content;
    ast_builtin->variables = variables;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_BUILTIN_STATEMENT;
    ast->ast_builtin_stat = ast_builtin;

    return ast;
}

AST *new_AST_Parameters (List *parameters)
{
    AST_Parameters *ast_param = malloc(sizeof(AST_Parameters));
    ast_param->parameters = parameters;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_PARAMETERS;
    ast->ast_parameters = parameters;

    return ast;
}

AST *new_AST_Statements (List *statements)
{
    AST_Statements *ast_statements = malloc(sizeof(AST_Statements));
    ast_statements->statements = statements;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_STATEMENTS;
    ast->ast_statements = statements;

    return ast;
}

AST *new_AST_Def_Function (AST *func_name, AST *parameters, AST *body)
{
    AST_Def_Function *ast_def_func = malloc(sizeof(AST_Def_Function));
    ast_def_func->func_name = func_name;
    ast_def_func->parameters = parameters;
    ast_def_func->body = body;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_DEF_FUNCTION;
    ast->ast_def_function = ast_def_func;

    return ast;
}

AST *new_AST_Arguments (List *arguments)
{
    AST_Arguments *ast_args = malloc(sizeof(AST_Arguments));
    ast_args->arguments = arguments;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_ARGUMENTS;
    ast->ast_arguments = ast_args;

    return ast;
}

AST *new_AST_Call_Function (AST *func_name, AST *arguments)
{
    AST_Call_Function *ast_call_func = malloc(sizeof(AST_Call_Function));
    ast_call_func->func_name = func_name;
    ast_call_func->arguments = arguments;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_CALL_FUNCTION;
    ast->ast_call_function = ast_call_func;

    return ast;
}

AST *new_AST_List_Function (List *functions)
{
    AST_List_Function *ast_list_func = malloc(sizeof(AST_List_Function));
    ast_list_func->functions = functions;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_LIST_FUNCTION;
    ast->ast_list_function = ast_list_func;

    return ast;
}

AST *new_AST_List_Declaration (List *declaration)
{
    AST_List_Declaration *ast_list_decl = malloc(sizeof(AST_List_Declaration));
    ast_list_decl->declaration = declaration;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_LIST_DECLARATION;
    ast->ast_list_declaration;

    return ast;
}

AST *new_AST_Body (AST *declarations, AST *statements)
{
    AST_Body *ast_body = malloc(sizeof(AST_Body));
    ast_body->declarations = declarations;
    ast_body->statements = statements;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_BODY;
    ast->ast_body = ast_body;

    return ast;
}

AST *new_AST_Root (AST *global_declaration, AST *functions)
{
    AST_Root *ast_root = malloc(sizeof(AST_Root));
    ast_root->global_declaration = global_declaration;
    ast_root->functions = functions;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_ROOT;
    ast->ast_root = ast_root;

    return ast; 
}
