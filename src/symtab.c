#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "symtab.h"

SymTab_Variables *new_SymTab_Variables (char *name, int n, ValType type, struct_info *s_info, int declared, int inizialized)
{
    SymTab_Variables *sym_variable = malloc(sizeof(SymTab_Variables));
    sym_variable->name = name;
    sym_variable->n = n;
    sym_variable->type = type;
    sym_variable->s_info = s_info;
    sym_variable->declared = declared;
    sym_variable->inizialized = inizialized;

    return sym_variable;
}

SymTab_Functions *new_SymTab_Functions (SymTab_Variables *func_name)
{
    SymTab_Functions *symtab_func = malloc(sizeof(SymTab_Functions));
    symtab_func->func_name = func_name;
    symtab_func->parameters = list_new();
    symtab_func->local_variables = list_new();

    return symtab_func;
}

struct_info *new_struct_info (char *name, List *elements)
{
    struct_info *s = malloc(sizeof(struct_info));
    s->struct_name = name;
    s->struct_element = elements;

    return s;
}

SymTab *init_symtab()
{
    SymTab *sym_tab = malloc(sizeof(SymTab));
    sym_tab->global_variables = list_new();
    sym_tab->functions = list_new();

    return sym_tab;
}

void insert_var(SymTab *symtab, SymTab_Variables *sym_var, char *scope)
{
    if(strcmp(scope,"GLOBAL") == 0)
    {
        list_append(symtab->global_variables, sym_var);
    } 
    else
    {
        for(int i=0; i<list_length(symtab->functions);i++)
        {
            SymTab_Functions *f = list_get(symtab->functions,i);
            if(scope == f->func_name->name)
            {
                list_append(f->local_variables, sym_var);
                symtab->functions->items[i] = f;
                break;
            }
        }
    }

}

void insert_fun(SymTab *symtab, SymTab_Functions *sym_fun)
{
    list_append(symtab->functions, sym_fun);
}

void update_par(SymTab *symtab, List *parameters, char *scope)
{
    for(int i=0; i<list_length(symtab->functions);i++)
    {
        SymTab_Functions *f = list_get(symtab->functions,i);
        if(scope == f->func_name->name)
        {
            f->parameters = parameters;
            symtab->functions->items[i] = f;
            break;
        }
    }
}

void print_tilde()
{
    for(int i=0;i<35;i++) printf("~");
    printf("\n");
}

void print_symvar(SymTab_Variables *symvar,char *kind)
{
    char type[30]="", n[10];

    // convert symvar type as string
    switch(symvar->type) {
            case T_NULL:
                strcpy(type,"NULL");
                break;
            case T_VOID:
                strcpy(type,"VOID");
                break;
            case T_INT:
                strcpy(type,"INT");
                break;
            case T_FLOAT:
                strcpy(type,"FLOAT");
                break;
            case T_CHAR:
                strcpy(type,"CHAR");
                break;
            case T_STRUCT:
                if(symvar->s_info == NULL) strcpy(type,"STRUCT Unknown");
                else
                {
                    strcpy(type,"STRUCT ");
                    strcat(type, symvar->s_info->struct_name);
                }
                break;
        }

    // convert dimension as string
    if(symvar->n == -2) strcpy(n,"Unknown");
    else if(symvar->n == -1) strcpy(n,"/");
         else sprintf(n,"%d",symvar->n);

    printf("%s\t%s\t%s\t%s\n",symvar->name,kind,type,n);
}

void print_symfun(SymTab_Functions *symfun)
{
    int i;
    char name[30];
    SymTab_Variables *v;

    // Convert to upper case
    strcpy(name,symfun->func_name->name);
    for(i=0; i<strlen(name);i++)
    {
        name[i] = toupper(name[i]);
    }

    // print header
    printf("%s SYMBOL TABLE\n", name);
    printf("Name\tKind\tType\tDimension\n");
    print_tilde();

    // print parameter variables
    for(i=0; i<list_length(symfun->parameters); i++)
    {
        v = list_get(symfun->parameters,i);
        print_symvar(v,"PAR");
    }
    if(list_length(symfun->parameters)!=0) print_tilde();

    // print local variables
    for(i=0; i<list_length(symfun->local_variables); i++)
    {
        v = list_get(symfun->local_variables,i);
        print_symvar(v,"VAR");
    }
}

void print_symtab(SymTab *symtab)
{
    int i;
    SymTab_Variables *v;
    SymTab_Functions *f;

    // print header
    printf("GLOBAL SYMBOL TABLE\n");
    printf("Name\tKind\tType\tDimension\n");
    print_tilde();

    // print global variables
    List *var = symtab->global_variables;
    for(i = 0; i<list_length(var); i++)
    {
        v = list_get(var,i);
        print_symvar(v,"VAR");
    }
    if(list_length(var)!=0) print_tilde();

    // print functions
    List *fun = symtab->functions;
    for(i = 0; i<list_length(fun); i++)
    {
        f = list_get(fun,i);
        print_symvar(f->func_name,"FUN");
    }
    printf("\n\n\n");

    // print function symbol table
    for(i=0; i<list_length(fun); i++)
    {
        f = list_get(fun,i);
        print_symfun(f);
        printf("\n\n\n");
    }
}










