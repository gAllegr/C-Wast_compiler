#include <stdlib.h>
#include <string.h>
#include "wat.h"

/* Imports, to be written depending on flags */
char *imports[4] = {
    "(import \"console\" \"int_log\" (func $int_log (param i32)))",
    "(import \"console\" \"float_log\" (func $float_log (param f32)))",
    "(import \"console\" \"str_log\" (func $str_log (param i32) (param i32)))",
    "(import \"js\" \"mem\" (memory 1))"
};
/* Flag to know what imports are needed */
int imports_flag[4] = {0,0,0,0};

void code_generation(AST *ast, SymTab *symtab)
{
    int i;

    // open file
    fp = fopen ("./output_code/code.wat", "w");
    if (fp==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    // initialize variables
    data = list_new();
    data_index = 0;
    for_loop_index = 0;
    scope = "GLOBAL";
    
    // convert code from ast and symbol table
    char *text = strdup(convert_code(ast, symtab, scope, 2));

    // generate imports
    char *temp;
    char *import = "";
    for(i=0; i<4; i++)
        if(imports_flag[i] == 1) 
        {
            temp = strdup(concat(2, "", indentation(2), imports[i]));
            import = strdup(concat(2, "\n", import, temp));
        }

    // generate data
    char *d = "";
    for(i=0; i<list_length(data); i++)
        {
            char *temp_data = list_get(data,i);
            temp = strdup(concat(2, "", indentation(2), temp_data));
            d = strdup(concat(2, "\n", d, strdup(temp)));
        }
    
    // generate final code
    text = strdup(concat(5, "\n", "(module", import, d, text, ")"));
    fprintf(fp, "%s", text);
    fclose(fp);

    createAuxFiles();
}

void createAuxFiles()
{
    wat2wasm();
    createHTML();
    createCSS();
    createJS();
}

void wat2wasm()
{
    char command[] = "wat2wasm ./output_code/code.wat -o ./output_code/code.wasm";
    system(command);
}

void createHTML()
{
    char *head = "\t<meta charset=\"utf-8\">\n\t<title>WebAssembly Testing Page</title>\n\t<script src=\"script.js\"></script>\n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">";
    char *body = "\t<h1>WebAssembly Testing Page</h1>\n\t<div id=\"output\"></div>\n\t<script>startWasm();</script>";
    char *html = strdup(concat(9,"\n", "<!doctype html>", "<html>", "<head>", head, "</head>", "<body>", body, "</body>", "</html>"));

    // open file
    FILE *fhtml = fopen ("./output_code/index.html", "w");
    if (fhtml==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    fprintf(fhtml, "%s", html);
    fclose(fhtml);
}

void createCSS()
{
    char *output_div = "#output {\n\tborder-style: solid;\n\tborder-width: 1px;\n\tvisibility: hidden;\n}";

    // open file
    FILE *fcss = fopen ("./output_code/style.css", "w");
    if (fcss==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    fprintf(fcss, "%s", output_div);
    fclose(fcss);
}

void createJS()
{
    char *js_code ="";
    char *functions[3] = {"","",""};
    char *memory = "";
    char *console_import = "";
    char *memory_import = "";
    char *import_object = "";
    char *show_div = "";
    char *webAssembly = "";

    // create integer printf function
    if(imports_flag[0] == 1)
    {
        functions[0] = "\t// integer printf function to import in WebAssembly code\n\tfunction consoleIntLog(intNumber)\n\t{\n\t\tvar paragraph = document.createElement(\"p\");\n\t\tparagraph.innerHTML = intNumber;\n\t\tdocument.getElementById(\"output\").appendChild(paragraph);\n\t}\n";
        console_import = strdup(concat(2, "\n", console_import, "\t\t\tint_log: consoleIntLog,"));
    }

    // create float printf function
    if(imports_flag[1] == 1)
    {
        functions[1] = "\t// float printf function to import in WebAssembly code\n\tfunction consoleFloatLog(floatNumber)\n\t{\n\t\tvar paragraph = document.createElement(\"p\");\n\t\tparagraph.innerHTML = floatNumber;\n\t\tdocument.getElementById(\"output\").appendChild(paragraph);\n\t}\n";
        console_import = strdup(concat(2, "\n", console_import, "\t\t\tfloat_log: consoleFloatLog,"));
    }

    // create string printf function
    if(imports_flag[2] == 1)
    {
        functions[2] = "\t// string printf function to import in WebAssembly code\n\tfunction consoleStringLog(offset, length)\n\t{\n\t\tvar bytes = new Uint8Array(memory.buffer, offset, length);\n\t\tvar string = new TextDecoder('utf8').decode(bytes);\n\t\tvar paragraph = document.createElement(\"p\");\n\t\tparagraph.innerHTML = string;\n\t\tdocument.getElementById(\"output\").appendChild(paragraph);\n\t}\n";
        console_import = strdup(concat(2, "\n", console_import, "\t\t\tstr_log: consoleStringLog,"));
    }

    // create memory
    if(imports_flag[3] == 1)
    {
        memory = "\t// memory will have one page (64KB)\n\tvar memory = new WebAssembly.Memory({ initial: 1 });\n";
        memory_import = "\t\tjs: {\n\t\t\tmem: memory\n\t\t}";
    }

    // create import_object
    if(console_import != "")
        console_import = strdup(concat(3, "\n", "\t\tconsole: {", console_import, "\t\t},"));

    import_object = strdup(concat(5, "\n", "\t// define importObject, to be passed to WebAssembly", "\tvar importObject = {", console_import, memory_import, "\t};\n"));

    // show div element
    show_div = strdup(concat(2, "\n", "\t// show div element", "\tdocument.getElementById(\"output\").style.visibility = 'visible';\n"));

    // instantiate a WebAssembly instance
    webAssembly = strdup(concat(5, "\n", "\t// instantiate a WebAssembly instance", "\tWebAssembly.instantiateStreaming(fetch('code.wasm'), importObject)", "\t\t.then(obj => {", "\t\t\tobj.instance.exports.main();", "\t\t});"));

    // concat everything to get code
    js_code = strdup(concat(10, "\n", "function startWasm()", "{", memory, functions[0], functions[1], functions[2], import_object, show_div, webAssembly, "}"));

    // open file
    FILE *fjs = fopen ("./output_code/script.js", "w");
    if (fjs==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    fprintf(fjs, "%s", js_code);
    fclose(fjs);
}

char *indentation (int n)
{
    char *text = "";

    // print indent
    for (int i = 0; i < n; i++) { text = strdup(concat(2,"",text," ")); }

    return strdup(text);
}

char *convert_code (AST *ast, SymTab *symtab, char *scope, int indent)
{
    char *text = "";
    if(ast == NULL) { return "\n"; }

    switch(ast->type) {
        case N_CONSTANT:
            ;
            char temp[30];
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
                    imports_flag[3] = 1;
                    char *str = ast->ast_constant->sval;
                    if(str[0] == '\'')
                    {
                        str[0] = '\"';
                        str[strlen(str)-1] = '\"';
                    }
                    // create data instruction
                    char data_str[100];
                    sprintf(data_str, "(data (i32.const %d) %s)", data_index, str);
                    list_append(data,strdup(data_str));

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
                printf("Sorry, struct cannot be directly converted in WebAssembly\n");
                exit(1);
            }

            int where, pos;
            pos = lookup(symtab, ast->ast_variable->sym_variable->name, scope, &where);
            SymTab_Variables *var = get_symtab_var(symtab, scope, pos, where);

            // check if is an array and it is not a string
            if(var->n != -1 && var->type != T_CHAR)
            {
                // array cannot be converted directly in webassembly
                printf("Sorry, array cannot be directly converted in WebAssembly\n");
                exit(1);
            }
        
            if(where == 0) text = strdup(concat(2,"", "global $", ast->ast_variable->sym_variable->name));
            else text = strdup(concat(2,"", "local $", ast->ast_variable->sym_variable->name));
            break;
        case N_UNARY_EXPR:
            text = strdup(convert_code(ast->ast_unary_expr->expression, symtab, scope, 0));
            ValType type = evaluate_expression_type(ast, symtab, scope);
            switch(ast->ast_unary_expr->unary_type)
            {
                case U_INC:
                    // Increment works only on variables
                    if(type==T_INT) text = strdup(concat(5, "", "(set_", text, " (i32.add (get_", text, ") (i32.const 1)))"));
                    else text = strdup(concat(5, "", "(set_", text, " (f32.add (get_", text, ") (f32.const 1.0)))"));
                    break;
                case U_DEC:
                    // Decrement works only on variables
                    if(type==T_INT) text = strdup(concat(5, "", "(set_", text, " (i32.sub (get_", text, ") (i32.const 1)))"));
                    else text = strdup(concat(5, "", "(set_", text, " (f32.sub (get_", text, ") (f32.const 1.0)))"));
                    break;
                case U_REV:
                    if(ast->ast_unary_expr->expression->type == N_VARIABLE)
                        if(type==T_INT) text = strdup(concat(3, "", "(i32.mul (get_", text, ") (i32.const -1))"));
                        else text = strdup(concat(3, "", "(f32.neg (get_", text, "))"));
                    else
                        if(type==T_INT) text = strdup(concat(3, "", "(i32.mul ", text, " (i32.const -1))"));
                        else text = strdup(concat(3, "", "(f32.neg ", text, ")"));
                    break;
                case U_NOT:
                    if(type == T_FLOAT)
                    {
                        // Not operation for float variables is not defined
                        printf("Sorry, cannot resolve NOT operation for float in WebAssembly");
                        exit(1);
                    }

                    if(ast->ast_unary_expr->expression->type == N_VARIABLE)
                        text = strdup(concat(3, "", "(i32.eqz (get_", text, "))"));
                    else
                        text = strdup(concat(3, "", "(i32.eqz ", text, ")"));
                    break;
            }
            break;
        case N_BINARY_EXPR:
            ;
            char *l_temp = strdup(convert_code(ast->ast_binary_expr->left, symtab, scope, 0));
            char *r_temp = strdup(convert_code(ast->ast_binary_expr->right, symtab, scope, 0));
            ValType expr_type = evaluate_expression_type(ast, symtab, scope);

            if(ast->ast_binary_expr->left->type == N_VARIABLE) l_temp = strdup(concat(3,"","(get_",l_temp,")"));
            if(ast->ast_binary_expr->right->type == N_VARIABLE) r_temp = strdup(concat(3,"","(get_",r_temp,")"));

            switch(ast->ast_binary_expr->binary_type)
            {
                case B_ADD:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.add ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.add ", l_temp, " ", r_temp, ")"));                    
                    break;
                case B_SUB:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.sub ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.sub ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_MUL:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.mul ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.mul ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_DIV:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.div_s ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.div ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_EQ:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.eq ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.eq ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_NE:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.ne ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.ne ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_LT:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.lt_s ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.lt ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_LE:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.le_s ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.le ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_GT:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.gt_s ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.gt ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_GE:
                    if(expr_type==T_INT) text = strdup(concat(5, "", "(i32.ge_s ", l_temp, " ", r_temp, ")"));
                    else text = strdup(concat(5, "", "(f32.ge ", l_temp, " ", r_temp, ")"));   
                    break;
                case B_AND:
                    if(expr_type == T_FLOAT)
                    {
                        // Not operation for float variables is not defined
                        printf("Sorry, cannot resolve AND operation for float in WebAssembly");
                        exit(1);
                    }
                    text = strdup(concat(5, "", "(i32.and ", l_temp, " ", r_temp, ")"));
                    break;
                case B_OR:
                    if(expr_type == T_FLOAT)
                    {
                        // Not operation for float variables is not defined
                        printf("Sorry, cannot resolve OR operation for float in WebAssembly");
                        exit(1);
                    }
                    text = strdup(concat(5, "", "(i32.or ", l_temp, " ", r_temp, ")"));
                    break;
            }
            break;
        case N_ASSIGNMENT:
            ;
            char *v = strdup(convert_code(ast->ast_assign->variable, symtab, scope, 0));
            char *e = strdup(convert_code(ast->ast_assign->expression, symtab, scope, 0));
            text = strdup(concat(5,"","(set_", v, " ", e, ")"));
            break;
        case N_IF_STATEMENT:
            ;
            char *cond = strdup(convert_code(ast->ast_if_stat->condition, symtab, scope, 0));
            cond = strdup(concat(2,"", "(if ", cond));
            char *then_branch = strdup(convert_code(ast->ast_if_stat->then_branch, symtab, scope, indent+4));
            then_branch = strdup(concat(7,"", indentation(indent+2), "(then\n", indentation(indent+4), then_branch, "\n", indentation(indent+2), ")"));
            if(ast->ast_if_stat->else_branch == NULL)
                text = strdup(concat(2,"\n", cond, then_branch));
            else
            {
                char *else_branch = strdup(convert_code(ast->ast_if_stat->else_branch, symtab, scope, indent+4));
                else_branch = strdup(concat(7,"", indentation(indent+2), "(else\n", indentation(indent+4), else_branch, "\n", indentation(indent+2), ")"));
                text = strdup(concat(3,"\n", cond, then_branch, else_branch));
            }
            text = strdup(concat(4,"", text, "\n", indentation(indent), ")"));
            break;
        case N_FOR_STATEMENT:
            ;
            /* Set a label for loop */
            char loop_name[10];
            sprintf(loop_name, "loop%d", for_loop_index);
            /* Initialization */
            List *init_list = ast->ast_for_stat->init;
            char *init = "";
            for(int i=0; i<list_length(init_list);i++)
            {
                char *assignment = strdup(convert_code(list_get(init_list,i), symtab, scope, indent));
                init = strdup(concat(4,"", init, "\n", indentation(indent), assignment));
            }
            /* Increment */
            List *incr_list = ast->ast_for_stat->increment;
            char *incr = "";
            for(int i=0; i<list_length(incr_list);i++)
            {
                char *expression = strdup(convert_code(list_get(incr_list,i), symtab, scope, indent+2));
                incr = strdup(concat(4,"", incr, "\n", indentation(indent+2), expression));
            }
            /* Condition */
            char *condition = strdup(convert_code(ast->ast_for_stat->condition, symtab, scope, indent+4));
            condition = strdup(concat(9, "", indentation(indent+2), "(br_if $", loop_name, "\n", indentation(indent+4), condition, "\n", indentation(indent+2), ")"));
            /* Loop */
            char *loop_body = strdup(convert_code(ast->ast_for_stat->loop, symtab, scope, indent+2));
            /* Put everything together */
            text = strdup(concat(14, "", init, "\n", indentation(indent), "(loop $", loop_name, "\n", loop_body, "\n", incr, "\n", condition, "\n", indentation(indent), ")"));
            for_loop_index++;
            break;
        case N_RETURN_STATEMENT:
            ;
            AST *expression = ast->ast_return_stat->expression;
            if(expression == NULL) text = "(return)";
            if(expression->type == N_CONSTANT)
            {
                text = strdup(convert_code(expression, symtab, scope, 0));
                text = strdup(concat(3, "", "(return ", text, ")"));
            }
            if(expression->type == N_VARIABLE)
            {
                text = strdup(convert_code(expression, symtab, scope, 0));
                text = strdup(concat(3, "", "(return (get_", text, "))"));
            }
            break;
        case N_BUILTIN_STATEMENT:
            if(ast->ast_builtin_stat->function == F_SCANF)
            {
                // WebAssembly doesn't allow interactivity
                printf("Sorry, cannot convert input operation (scanf) in WebAssembly\n");
                exit(1);
            }
            
            /* printf function */
            if(list_length(ast->ast_builtin_stat->variables) == 0)
            {
                // no variables, will print only a string
                imports_flag[2] = 1;            // enable str_log
                char temp[60];
                // get string length (-3 remove both "" and null-terminator)
                text = ast->ast_builtin_stat->content->ast_constant->sval;
                int l = strlen(text)-3;

                text = strdup(convert_code(ast->ast_builtin_stat->content, symtab, scope, 0));
                sprintf(temp, "(call $str_log\n%s%s\n%s(i32.const %d)\n%s)", indentation(indent+2),text,indentation(indent+2), l, indentation(indent));
                text = temp;
            }
            else
            {
                // there are variables to print
                char temp[60];
                List *var_list = ast->ast_builtin_stat->variables;
                for(int i=0; i<list_length(var_list);i++)
                {
                    AST *var = list_get(var_list,i);
                    text = strdup(convert_code(var, symtab, scope, 0));

                    if(var->ast_variable->sym_variable->type == T_INT)
                    {
                        imports_flag[0] = 1;            // enable int_log
                        text = strdup(concat(3, "", "(call $int_log (get_", text, "))"));
                    }

                    if(var->ast_variable->sym_variable->type == T_FLOAT)
                    {
                        imports_flag[1] = 1;            // enable float_log
                        text = strdup(concat(3, "", "(call $float_log (get_", text, "))"));
                    }

                    if(var->ast_variable->sym_variable->type == T_CHAR)
                    {
                        imports_flag[2] = 1;            // enable str_log
                        // string variable length is stored into symbol table
                        int where, pos;
                        pos = lookup(symtab, var->ast_variable->sym_variable->name, scope, &where);
                        SymTab_Variables *v = get_symtab_var(symtab, scope, pos, where);

                        sprintf(temp, "(call $str_log\n%s(get_%s)\n%s(i32.const %d)\n%s)", indentation(indent+2), text, indentation(indent+2), (v->n)-3, indentation(indent));
                        text = temp;
                    }
                }
            }
            break;
        case N_LIST:
            ;
            List *l = ast->ast_list->list;
            AST *a = list_get(l,0);
            if(a->type == N_CONSTANT)
            {
                // initialization of a string
                for(int i=0; i<list_length(l);i++)
                {
                    a = list_get(l, i);
                    text = strdup(concat(2,"",text,a->ast_constant->sval));
                }
                a = new_AST_Const(T_CHAR, text);
                text = strdup(convert_code(a, symtab, scope, 0));
            }
            else
            {
                // sequence of statements
                char *statements = "", *statement;
                for(int i=0; i<list_length(l);i++)
                {
                    statement = strdup(convert_code(list_get(l,i), symtab, scope, indent));
                    statements = strdup(concat(4, "", statements, "\n", indentation(indent), statement));
                }
                text = statements;
            }
            break;
        case N_DEF_FUNCTION:
            // update scope
            scope = ast->ast_def_function->sym_function->func_name->name;

            int i=0;
            /* Function name */
            char *func_name;
            if(strcmp(ast->ast_def_function->sym_function->func_name->name, "main") == 0)
                func_name = "(export \"main\")";
            else
                func_name = strdup(concat(2, "", "$", ast->ast_def_function->sym_function->func_name->name));
            
            text = strdup(concat(2, " ", "(func", func_name));

            /* Parameters */
            List *list = ast->ast_def_function->sym_function->parameters;
            for(i=0; i< list_length(list); i++)
            {
                SymTab_Variables *p = list_get(list,i);
                if(p->type != T_FLOAT)
                    text = strdup(concat(4,"", text, " (param $", p->name, " i32)"));
                else
                    text = strdup(concat(4,"", text, " (param $", p->name, " f32)"));
            }

            /* Return type */
            ValType return_type = ast->ast_def_function->sym_function->func_name->type;
            // if return type is void, there will be no (result) in .wat code
            if(return_type == T_INT || return_type == T_CHAR)
                text = strdup(concat(2, " ", text, "(result i32)"));
            if(return_type == T_FLOAT)
                text = strdup(concat(2, " ", text, "(result f32)"));       
            /* Body */
            char *body = strdup(convert_code(ast->ast_def_function->body, symtab, scope, indent+2));
            text = strdup(concat(2, "\n", text, body));
            text = strdup(concat(4, "", text, "\n", indentation(indent), ")"));
            break;
        case N_CALL_FUNCTION:
            ;
            /* Function name */
            char *f_name = ast->ast_call_function->func_name->ast_variable->sym_variable->name;
            text = strdup(concat(2, "", "(call $", f_name));
            /* Arguments */
            List *arguments = ast->ast_call_function->arguments;
            for(int i=0;i<list_length(arguments);i++)
            {
                AST *a = list_get(arguments,i);
                char *temp = strdup(convert_code(a, symtab, scope, indent));
                temp = strdup(concat(3,"","(get_",temp,")"));

                text = strdup(concat(2," ", text, temp));
            }

            text = strdup(concat(3,"", text, indentation(indent), ")"));
            break;
        case N_BODY:
            ;
            /* Local declaration and initialization */
            List *decl = ast->ast_body->declarations;
            List *local_var = list_new();
            List *init_var = list_new();
            char *t = "";
            for(i=0;i<list_length(decl);i++)
            {
                AST *a = list_get(decl, i);
                if(a->type == N_VARIABLE)
                {
                    t = strdup(convert_code(a, symtab, scope, 0));
                    if(a->ast_variable->sym_variable->type != T_FLOAT)
                        t = strdup(concat(4, "", indentation(indent), "(", t, " i32)"));
                    else t = strdup(concat(4, "", indentation(indent), "(", t, " f32)"));
                    list_append(local_var, t);
                }
                else    // initialization
                {
                    // first add declaration to local declaration list
                    t = strdup(convert_code(a->ast_assign->variable, symtab, scope, 0));
                    if(a->ast_assign->variable->ast_variable->sym_variable->type != T_FLOAT)
                        t = strdup(concat(4, "", indentation(indent), "(", t, " i32)"));
                    else t = strdup(concat(4, "", indentation(indent), "(", t, " f32)"));
                    list_append(local_var, t);
                    // then add initialization to init list
                    t = strdup(convert_code(a, symtab, scope, indent));
                    t = strdup(concat(2,"", indentation(indent), t));
                    list_append(init_var, t);
                }
            }

            // add declaration to text
            for(i=0;i<list_length(local_var);i++)
                text = strdup(concat(2, "\n", text, list_get(local_var, i)));
            // add initialization to text
            for(i=0;i<list_length(init_var);i++)
                text = strdup(concat(2, "\n", text, list_get(init_var, i)));

            /* Statements */
            List *stat = ast->ast_body->statements;
            for(i=0;i<list_length(stat);i++)
            {
                AST *a = list_get(stat,i);
                char *temp = strdup(convert_code(a, symtab, scope, indent));
                temp = strdup(concat(2,"", indentation(indent), temp));
                text = strdup(concat(2,"\n",text,temp));
            }
            break;
        case N_ROOT:
            ;
            /* Global declarations */
            List *global_var = ast->ast_root->global_declaration;
            char *tem = "";
            for(i=0;i<list_length(global_var);i++)
            {
                AST *a = list_get(global_var, i);
                if(a->type == N_VARIABLE)
                {
                    tem = strdup(convert_code(a, symtab, scope, 0));
                    if(a->ast_variable->sym_variable->type != T_FLOAT)
                        tem = strdup(concat(4, "", indentation(indent), "(", tem, " (mut i32) (i32.const 0))"));
                    else tem = strdup(concat(4, "", indentation(indent), "(", tem, " (mut f32) (f32.const 0.0))"));
                    text = strdup(concat(2,"\n", text, tem));
                }
                else    // initialization
                {
                    tem = strdup(convert_code(a->ast_assign->variable, symtab, scope, 0));
                    char *e = strdup(convert_code(a->ast_assign->expression, symtab, scope, indent));
                    if(a->ast_assign->variable->ast_variable->sym_variable->type != T_FLOAT)
                        tem = strdup(concat(6, "", indentation(indent), "(", tem, " (mut i32) ", e, ")"));
                    else tem = strdup(concat(6, "", indentation(indent), "(", tem, " (mut f32) ", e, ")"));
                    text = strdup(concat(2,"\n", text, tem));
                }
            }

            /* Functions */
            List *fun = ast->ast_root->functions;
            for(i=0;i<list_length(fun);i++)
            {
                AST *a = list_get(fun, i);
                tem = strdup(convert_code(a, symtab, scope, indent));
                text = strdup(concat(4,"", text, "\n", indentation(indent), tem));
            }
            break;
        default:
            return "Something went wrong\n";
            break;
    }
    return strdup(text);
}
