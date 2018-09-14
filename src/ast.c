#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"


/* ===== Functions to build AST nodes ===== */

AST *new_AST_Const(ValType type, char *value)
{
    AST_Const *ast_const = malloc(sizeof(AST_Const));
    ast_const->type = type;
    switch(type) {
        case T_INT:
            ast_const->ival = atoi(value);
            break;
        case T_FLOAT:
            ast_const->fval = atof(value);
            break;
        case T_CHAR:
            ast_const->sval = value;
            break;
    }

    AST *ast = malloc(sizeof(AST));
    ast->type = N_CONSTANT;
    ast->ast_constant = ast_const;

    return ast;
}

AST *new_AST_Variable (char *name, int n, ValType type, struct_info *s_info, int declared, int inizialized)
{
    AST_Variable *ast_variable = malloc(sizeof(AST_Variable));
    ast_variable->sym_variable = new_SymTab_Variables(name,n,type,s_info,declared,inizialized);
    

    AST *ast = malloc(sizeof(AST));
    ast->type = N_VARIABLE;
    ast->ast_variable = ast_variable;

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

AST *new_AST_Binary_Expr (BinaryExprType binary_type, AST *left, AST *right)
{
    AST_Binary_Expr *ast_binary_expr = malloc(sizeof(AST_Binary_Expr));
    ast_binary_expr->binary_type = binary_type;
    ast_binary_expr->left = left;
    ast_binary_expr->right = right;

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

AST *new_AST_For_Stat (List *init, AST *condition, List *increment, AST *loop)
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
    ast->ast_return_stat = ast_return;

    return ast;
}

AST *new_AST_Builtin_Stat (BuiltinFunction function, AST *content, List *variables)
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

AST *new_AST_List (List *list)
{
    AST_List *ast_list = malloc(sizeof(AST_List));
    ast_list->list = list;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_LIST;
    ast->ast_list = ast_list;

    return ast;
}

AST *new_AST_Def_Function (AST *func_name)
{
    AST_Def_Function *ast_def_func = malloc(sizeof(AST_Def_Function));
    ast_def_func->sym_function = new_SymTab_Functions(func_name->ast_variable->sym_variable);
    ast_def_func->body = NULL;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_DEF_FUNCTION;
    ast->ast_def_function = ast_def_func;

    return ast;
}

AST *new_AST_Call_Function (AST *func_name, List *arguments)
{
    AST_Call_Function *ast_call_func = malloc(sizeof(AST_Call_Function));
    ast_call_func->func_name = func_name;
    ast_call_func->arguments = arguments;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_CALL_FUNCTION;
    ast->ast_call_function = ast_call_func;

    return ast;
}

AST *new_AST_Body (List *declarations, List *statements)
{
    AST_Body *ast_body = malloc(sizeof(AST_Body));
    ast_body->declarations = declarations;
    ast_body->statements = statements;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_BODY;
    ast->ast_body = ast_body;

    return ast;
}

AST *new_AST_Root (List *global_declaration, List *functions)
{
    AST_Root *ast_root = malloc(sizeof(AST_Root));
    ast_root->global_declaration = global_declaration;
    ast_root->functions = functions;

    AST *ast = malloc(sizeof(AST));
    ast->type = N_ROOT;
    ast->ast_root = ast_root;

    return ast; 
}

/* ===== Function to get AST nodes types as string ===== */

char *ast_type_name(AST *ast)
{
    switch(ast->type) {
        case N_CONSTANT:
            switch(ast->ast_constant->type) {
                case T_INT:
                    return "INT_CONSTANT";
                case T_FLOAT:
                    return "FLOAT_CONSTANT";
                case T_CHAR:
                    return "CHAR_CONSTANT";
            }
            break;
        case N_VARIABLE:
            switch(ast->ast_variable->sym_variable->type) {
                case T_NULL:
                    return "VARIABLE (Unknown type)";
                    break;
                case T_VOID:
                    return "VARIABLE (VOID type)";
                    break;
                case T_INT:
                    return "VARIABLE (INT type)";
                    break;
                case T_FLOAT:
                    return "VARIABLE (FLOAT type)";
                    break;
                case T_CHAR:
                    return "VARIABLE (CHAR type)";
                    break;
                case T_STRUCT:
                    if(ast->ast_variable->sym_variable->s_info == NULL)
                        return "VARIABLE (STRUCT Unknown type)";
                    else
                    {
                        char r[50];
                        sprintf(r, "VARIABLE (STRUCT %s type)", ast->ast_variable->sym_variable->s_info->struct_name);
                        return strdup(r);
                    }
                    break;
            }
            break;
        case N_UNARY_EXPR:
            switch(ast->ast_unary_expr->unary_type)
            {
                case U_INC:
                    return "UnaryExpr (Increment)";
                    break;
                case U_DEC:
                    return "UnaryExpr (Decrement)";
                    break;
                case U_REV:
                    return "UnaryExpr (Reverse)";
                    break;
                case U_NOT:
                    return "UnaryExpr (Logical Not)";
                    break;
            }
            break;
        case N_BINARY_EXPR:
            switch(ast->ast_binary_expr->binary_type)
            {
                case B_ADD:
                    return "BinaryExpr (Addition)";
                    break;
                case B_SUB:
                    return "BinaryExpr (Subtraction)";
                    break;
                case B_MUL:
                    return "BinaryExpr (Multiplication)";
                    break;
                case B_DIV:
                    return "BinaryExpr (Division)";
                    break;
                case B_EQ:
                    return "BinaryExpr (Equal)";
                    break;
                case B_NE:
                    return "BinaryExpr (Not Equal)";
                    break;
                case B_LT:
                    return "BinaryExpr (Less Than)";
                    break;
                case B_LE:
                    return "BinaryExpr (Less or Equal Than)";
                    break;
                case B_GT:
                    return "BinaryExpr (Greater Than)";
                    break;
                case B_GE:
                    return "BinaryExpr (Greater or Equal Than)";
                    break;
                case B_AND:
                    return "BinaryExpr (Logical And)";
                    break;
                case B_OR:
                    return "BinaryExpr (Logical Or)";
                    break;
            }
            break;
        case N_ASSIGNMENT:
            return "Assignment";
            break;
        case N_IF_STATEMENT:
            return "If_Statement";
            break;
        case N_FOR_STATEMENT:
            return "For_Statement";
            break;
        case N_RETURN_STATEMENT:
            return "Return_Statement";
            break;
        case N_BUILTIN_STATEMENT:
            switch(ast->ast_builtin_stat->function) {
                case F_PRINTF:
                    return "Printf_Statement";
                case F_SCANF:
                    return "Scanf_Statement";
            }
            break;
        case N_LIST:
            return "List";
            break;
        case N_DEF_FUNCTION:
            return "Function Definition";
            break;
        case N_CALL_FUNCTION:
            return "Function Call";
            break;
        case N_BODY:
            return "Function Body";
            break;
        case N_ROOT:
            return "Program";
            break;
        default:
            return "Cannot find type of node!";
            break;
    }
}


/* ===== Functions to free AST nodes ===== */

void free_ast_list(List *ast_list)
{
    // if list empty
    if(ast_list == NULL) return;

    // if list has elements, free every element
    for(int i=0; i<list_length(ast_list); i++)
    {
        free_ast(list_get(ast_list,i));
    }

    // at the end, free the list itself
    free(ast_list);
}


void free_ast(AST *ast)
{
    // if node empty
    if(ast == NULL) return;

    switch(ast->type) {
        case N_CONSTANT:
//printf("I Const\n");
            if(ast->ast_constant->type == T_CHAR) free(ast->ast_constant->sval);
            free(ast->ast_constant);
//printf("F Const\n");
            break;
        case N_VARIABLE:
//printf("I Var\n");
            free(ast->ast_variable);
//printf("F Var\n");
            break;
        case N_UNARY_EXPR:
//printf("I unary\n");
            free_ast(ast->ast_unary_expr->expression);
            free(ast->ast_unary_expr);
//printf("F unary\n");            
            break;
        case N_BINARY_EXPR:
//printf("I binary\n");
            free_ast(ast->ast_binary_expr->left);
            free_ast(ast->ast_binary_expr->right);
            free(ast->ast_binary_expr);
//printf("F binary\n");            
            break;
        case N_ASSIGNMENT:
//printf("I assign\n");
            free_ast(ast->ast_assign->variable);
            free_ast(ast->ast_assign->expression);
            free(ast->ast_assign);
//printf("F assign\n");            
            break;
        case N_IF_STATEMENT:
//printf("I if\n");
            free_ast(ast->ast_if_stat->condition);
            free_ast(ast->ast_if_stat->then_branch);
            free_ast(ast->ast_if_stat->else_branch);
            free(ast->ast_if_stat);
//printf("F if\n");
            break;
        case N_FOR_STATEMENT:
//printf("I for\n");
            free_ast_list(ast->ast_for_stat->init);
            free_ast(ast->ast_for_stat->condition);
            free_ast_list(ast->ast_for_stat->increment);
            free_ast(ast->ast_for_stat->loop);
            free(ast->ast_for_stat);
//printf("F for\n");
            break;
        case N_RETURN_STATEMENT:
//printf("I return\n");
            free_ast(ast->ast_return_stat->expression);
            free(ast->ast_return_stat);
//printf("F return\n");
            break;
        case N_BUILTIN_STATEMENT:
//printf("I builtin\n");
            free_ast(ast->ast_builtin_stat->content);
            free_ast_list(ast->ast_builtin_stat->variables);
            free(ast->ast_builtin_stat);
//printf("F builtin\n");
            break;
        case N_LIST:
//printf("I list\n");
            free_ast_list(ast->ast_list->list);         // free elements' list
            free(ast->ast_list);
//printf("F List\n");
            break;
        case N_DEF_FUNCTION:
//printf("I def func\n");
            free_ast(ast->ast_def_function->body);
            free(ast->ast_def_function);
//printf("F def func\n");
            break;
        case N_CALL_FUNCTION:
//printf("I call func\n");
            free_ast(ast->ast_call_function->func_name);
            free_ast_list(ast->ast_call_function->arguments);
            free(ast->ast_call_function);
//printf("F call func\n");
            break;
        case N_BODY:
//printf("I body\n");
            free_ast_list(ast->ast_body->declarations);
            free_ast_list(ast->ast_body->statements);
            free(ast->ast_body);
//printf("F body\n");
            break;
        case N_ROOT:
//printf("I root\n");
            free_ast_list(ast->ast_root->global_declaration);
            free_ast_list(ast->ast_root->functions);
            free(ast->ast_root);
//printf("F root\n");
            break;
        default:
            printf("Could not free syntax tree with type: %s\n", ast_type_name(ast));
            exit(EXIT_FAILURE);
    }

    free(ast);
}

/* ===== Function to print AST nodes ===== */

void print_ast(AST *ast, int indent)
{
    // print indent
    for (int i = 0; i < indent; i++) { printf(" "); }

    if(ast == NULL) { printf("\n"); return; }

    switch(ast->type) {
        case N_CONSTANT:
            switch(ast->ast_constant->type) {
                case T_INT:
                    printf("%s %d\n", ast_type_name(ast), ast->ast_constant->ival);
                    break;
                case T_FLOAT:
                    printf("%s %f\n", ast_type_name(ast), ast->ast_constant->fval);
                    break;
                case T_CHAR:
                    printf("%s %s\n", ast_type_name(ast), ast->ast_constant->sval);
                    break;
            }
            break;
        case N_VARIABLE:
            if(ast->ast_variable->sym_variable->n==-1)
                printf("%s %s\n", ast_type_name(ast), ast->ast_variable->sym_variable->name);
            else
                printf("%s %s[%d]\n", ast_type_name(ast), ast->ast_variable->sym_variable->name, ast->ast_variable->sym_variable->n);
            
            if(ast->ast_variable->sym_variable->type == T_STRUCT && ast->ast_variable->sym_variable->s_info != NULL)
            {
                List *elements = ast->ast_variable->sym_variable->s_info->struct_element->items[0];
                for(int i=0; i<list_length(elements);i++)
                {
                    SymTab_Variables *s = list_get(elements,i);
                    print_ast(new_AST_Variable(s->name,s->n,s->type,s->s_info,s->declared,s->inizialized),indent+4);
                }
            }
            break;
        case N_UNARY_EXPR:
            printf("%s\n", ast_type_name(ast));
            print_ast(ast->ast_unary_expr->expression,indent+4);
            break;
        case N_BINARY_EXPR:
            printf("%s LEFT\n", ast_type_name(ast));
            print_ast(ast->ast_binary_expr->left,indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s RIGHT\n", ast_type_name(ast));            
            print_ast(ast->ast_binary_expr->right,indent+4);
            break;
        case N_ASSIGNMENT:
            printf("%s VARIABLE\n", ast_type_name(ast));
            print_ast(ast->ast_assign->variable,indent+4);
            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s EXPRESSION\n", ast_type_name(ast));
            print_ast(ast->ast_assign->expression,indent+4);
            break;
        case N_IF_STATEMENT:
            printf("%s CONDITION\n", ast_type_name(ast));
            print_ast(ast->ast_if_stat->condition,indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s THEN\n", ast_type_name(ast));
            print_ast(ast->ast_if_stat->then_branch,indent+4);

            if(ast->ast_if_stat->else_branch != NULL)
            {
                for (int i=0; i<indent; i++) { printf(" "); }
                printf("%s ELSE\n", ast_type_name(ast));
                print_ast(ast->ast_if_stat->else_branch,indent+4);
            }
            break;
        case N_FOR_STATEMENT:
            printf("%s INIZIALIZATION\n", ast_type_name(ast));
            List *init = ast->ast_for_stat->init;
            for(int i=0; i<list_length(init);i++)
            {
                print_ast(list_get(init,i), indent+4);
            }

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s CONDITION\n", ast_type_name(ast));
            print_ast(ast->ast_for_stat->condition,indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s INCREMENT\n", ast_type_name(ast));
            List *incr = ast->ast_for_stat->increment;
            for(int i=0; i<list_length(incr);i++)
            {
                print_ast(list_get(incr,i), indent+4);
            }

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s LOOP\n", ast_type_name(ast));
            print_ast(ast->ast_for_stat->loop,indent+4);

            break;
        case N_RETURN_STATEMENT:
            printf("%s\n", ast_type_name(ast));
            print_ast(ast->ast_return_stat->expression,indent+4);
            break;
        case N_BUILTIN_STATEMENT:
            printf("%s CONTENT\n", ast_type_name(ast));
            print_ast(ast->ast_builtin_stat->content,indent+4);

            if(ast->ast_builtin_stat->variables->items != NULL)
            {
                for (int i=0; i<indent; i++) { printf(" "); }
                printf("%s VARIABLES\n", ast_type_name(ast));
                List *vars = ast->ast_builtin_stat->variables;
                for(int i=0; i<list_length(vars);i++)
                {
                    print_ast(list_get(vars,i), indent+4);
                }
            }
            break;
        case N_LIST:
            printf("%s\n", ast_type_name(ast));
            List *list = ast->ast_list->list;
            for(int i=0; i<list_length(list);i++)
            {
                print_ast(list_get(list,i), indent+4);
            }
            break;
        case N_DEF_FUNCTION:
            printf("%s NAME\n", ast_type_name(ast));
            SymTab_Variables *f_name = ast->ast_def_function->sym_function->func_name;
            print_ast(new_AST_Variable(f_name->name,f_name->n,f_name->type,f_name->s_info,f_name->declared,f_name->inizialized),indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s PARAMETERS\n", ast_type_name(ast));
            List *f_param = ast->ast_def_function->sym_function->parameters;
            for(int i=0; i<list_length(f_param);i++)
            {
                SymTab_Variables *p = list_get(f_param,i);
                print_ast(new_AST_Variable(p->name,p->n,p->type,p->s_info,p->declared,p->inizialized),indent+4);
            }

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s BODY\n", ast_type_name(ast));
            print_ast(ast->ast_def_function->body,indent+4);

            break;
        case N_CALL_FUNCTION:
            printf("%s NAME\n", ast_type_name(ast));
            print_ast(ast->ast_call_function->func_name,indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s ARGUMENTS\n", ast_type_name(ast));            
            List *args = ast->ast_call_function->arguments;
            for(int i=0; i<list_length(args);i++)
            {
                print_ast(list_get(args,i), indent+4);
            }

            break;
        case N_BODY:
            printf("%s DECLARATIONS\n", ast_type_name(ast));
            List *decl = ast->ast_body->declarations;
            for(int i=0; i<list_length(decl);i++)
            {
                print_ast(list_get(decl,i), indent+4);
            }

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s STATEMENTS\n", ast_type_name(ast));
            List *stat = ast->ast_body->statements;
            for(int i=0; i<list_length(stat);i++)
            {
                print_ast(list_get(stat,i), indent+4);
            }

            break;
        case N_ROOT:
            printf("%s GLOBAL DECLARATIONS\n", ast_type_name(ast));
            List *glob_decl = ast->ast_root->global_declaration;
            for(int i=0; i<list_length(glob_decl);i++)
            {
                print_ast(list_get(glob_decl,i), indent+4);
            }

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s FUNCTIONS\n", ast_type_name(ast));
            List *func = ast->ast_root->functions;
            for(int i=0; i<list_length(func);i++)
            {
                print_ast(list_get(func,i), indent+4);
            }

            break;
        default:
            printf("Cannot decide what node must be printed\n");
            break;
    }
}