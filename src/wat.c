#include <stdlib.h>
#include <string.h>
#include "wat.h"

/* Imports, to be written depending on flags */
char *imports[3] = {
    "(import \"console\" \"log\" (func $log (param i32)))",
    "(import \"console\" \"str_log\" (func $str_log (param i32) (param i32)))",
    "(import \"js\" \"mem\" (memory 1))"
};
/* Flag to know what imports are needed */
int imports_flag[3] = {0,0,0};

void code_generation(AST *ast, SymTab *symtab)
{
    // open file
    fp = fopen ("../code.wat", "w");
    if (fp==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    // set data to an empty list
    data = list_new();
    /* Initialize variables */
    data_index = 0;
    function = "";
    glob_var = "";
    local_var = "";
    init = "";
    instr = "";

    scope = "GLOBAL";
    
    // extract code from ast and symbol table
    char *text = extract_code(ast, symtab, scope, 2);


    fclose(fp);
}

char *convert_code (AST *ast, SymTab *symtab, char *scope, int indent)
{
    char *text = NULL;

    // print indent
    for (int i = 0; i < indent; i++) { printf(" "); }

    if(ast == NULL) { return "\n"; }

    switch(ast->type) {
        case N_CONSTANT:
            char temp[20];
            switch(ast->ast_constant->type) {
                case T_INT:
                    sprintf(temp, "(i32.const %d)", ast->ast_constant->ival);
                    text = temp;
                    break;
                case T_FLOAT:
                    sprintf(temp, "(f32.const %f)", ast->ast_constant->fval);
                    text = temp;
                    break;
                case T_CHAR:
                    // there are char inside program, memory will be necessary
                    imports_flag[2] = 1;
                    char *str = ast->ast_constant->sval;
                    if(strcmp(str[0],'\'') == 0)
                    {
                        str[0] = "\"";
                        str[strlen(str)] = "\"";
                    }
                    // create data instruction
                    char data_str[100];
                    sprintf(data_str, "(data (i32.const %d) %s)\n", data_index, str);
                    list_append(data,data_str);
                    // create constant
                    sprintf(temp, "(i32.const %d)", data_index);
                    text = temp;
                    // update index
                    data_index = data_index + strlen(str)-2;
                    break;
            }
            break;
        case N_VARIABLE:
            if(ast->ast_variable->sym_variable->type == T_STRUCT)
            {
                // struct cannot be converted directly in webassembly
                printf("Sorry, struct cannot be directly converted in WebAssembly");
                exit(1);
            }

            if(ast->ast_variable->sym_variable->n != -1)
            {
                // array cannot be converted directly in webassembly
                printf("Sorry, array cannot be directly converted in WebAssembly");
                exit(1);
            }
        
            int where;
            lookup(symtab, ast->ast_variable->sym_variable->name, scope, where);
            if(where == 0)
                sprintf(temp, "global $%s", ast->ast_variable->sym_variable->name);
            else
                sprintf(temp, "local $%s", ast->ast_variable->sym_variable->name);
            text = temp;
            break;
        case N_UNARY_EXPR:
            switch(ast->ast_unary_expr->unary_type)
            {
                case U_INC:
                    // Increment works only on variables
                    text = extract_code(ast->ast_unary_expr->expression, symtab, 0);
                    text = concat(3, "", "(i32.add (get_", text, ") (i32.const 1))");
                    break;
                case U_DEC:
                    // Decrement works only on variables
                    text = extract_code(ast->ast_unary_expr->expression, symtab, 0);
                    text = concat(3, "", "(i32.sub (get_", text, ") (i32.const 1))");
                    break;
                case U_REV:
                    text = extract_code(ast->ast_unary_expr->expression, symtab, 0);
                    if(ast->ast_unary_expr->expression->type == N_VARIABLE)
                        text = concat(3, "", "(i32.mul (get_", text, ") (i32.const -1))");
                    else
                        text = concat(3, "", "(i32.mul ", text, " (i32.const -1))");
                    break;
                case U_NOT:
                    text = extract_code(ast->ast_unary_expr->expression, symtab, 0);
                    if(ast->ast_unary_expr->expression->type == N_VARIABLE)
                        text = concat(3, "", "(i32.eqz (get_", text, "))");
                    else
                        text = concat(3, "", "(i32.eqz ", text, ")");
                    break;
            }
            break;
        case N_BINARY_EXPR:
            char *l_temp, *r_temp;
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
            print_ast(new_AST_Variable(f_name->name,f_name->n,f_name->type,f_name->s_info,f_name->inizialized),indent+4);

            for (int i=0; i<indent; i++) { printf(" "); }
            printf("%s PARAMETERS\n", ast_type_name(ast));
            List *f_param = ast->ast_def_function->sym_function->parameters;
            for(int i=0; i<list_length(f_param);i++)
            {
                SymTab_Variables *p = list_get(f_param,i);
                print_ast(new_AST_Variable(p->name,p->n,p->type,p->s_info,p->inizialized),indent+4);
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
            return "Something went wrong\n";
            break;
    }

    return text;
}


