#include <stdlib.h>
#include <stdio.h>
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

/*
SymTab *init_sym_tab()
{
    SymTab *sym_tab = malloc(sizeof(SymTab));
    sym_tab->global_variables = NULL;
    sym_tab->functions = NULL;

    return sym_tab;
}
*/