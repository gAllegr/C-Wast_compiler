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
    for(int i=0;i<60;i++) printf("~");
    printf("\n");
}

void print_symvar(SymTab_Variables *symvar,char *kind, List *struct_infos)
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
                    list_append(struct_infos, symvar->s_info);
                }
                break;
        }

    // convert dimension as string
    if(symvar->n == -2) strcpy(n,"Unknown");
    else if(symvar->n == -1) strcpy(n,"/");
         else sprintf(n,"%d",symvar->n);

    if(symvar->type == T_STRUCT) printf("%s\t\t%s\t\t%s\t%s\n",symvar->name,kind,type,n);
    else printf("%s\t\t%s\t\t%s\t\t%s\n",symvar->name,kind,type,n);
}

void print_struct_info(List *struct_infos)
{
    int i,j,flag;                // flag checks if a struct has already been printed
    SymTab_Variables *v;
    struct_info *s_info, *s_prec;

    // print struct components, if there are any struct variables
    if(list_length(struct_infos)!=0)
    {
        for(i=0;i<list_length(struct_infos);i++)
        {
            // extract one struct_info
            s_info = list_get(struct_infos,i);

            // check if that specific struct has already been printed
            flag = 0;
            for(j=0;j<i;j++)
            {
                s_prec = list_get(struct_infos,j);
                if(s_info->struct_name == s_prec->struct_name) flag = 1;
            }

            if(flag==0)         // struct has not been printed till now
            {
                // print struct content
                printf("STRUCT %s\n", s_info->struct_name);
                for(j=0;j<list_length(s_info->struct_element->items[0]);j++)
                {
                    v = list_get(s_info->struct_element->items[0],j);
                    print_symvar(v,"VAR",struct_infos);
                }
            }
        }
        print_tilde();
    }    
}

void print_symfun(SymTab_Functions *symfun)
{
    int i;
    char name[30];
    SymTab_Variables *v;
    List *struct_infos = list_new();

    // Convert to upper case
    strcpy(name,symfun->func_name->name);
    for(i=0; i<strlen(name);i++)
    {
        name[i] = toupper(name[i]);
    }

    // print header
    printf("%s SYMBOL TABLE\n", name);
    printf("Name\t\tKind\t\tType\t\tDimension\n");
    print_tilde();

    // print parameter variables
    for(i=0; i<list_length(symfun->parameters); i++)
    {
        v = list_get(symfun->parameters,i);
        print_symvar(v,"PAR",struct_infos);
    }
    if(list_length(symfun->parameters)!=0)
    {
        print_tilde();
        print_struct_info(struct_infos);
    }

    // print local variables
    for(i=0; i<list_length(symfun->local_variables); i++)
    {
        v = list_get(symfun->local_variables,i);
        print_symvar(v,"VAR",struct_infos);
    }
    if(list_length(symfun->local_variables)!=0)
    {
        print_tilde();
        print_struct_info(struct_infos);
    }
}

void print_symtab(SymTab *symtab)
{
    int i,j, flag;                // flag checks if a struct has already been printed
    SymTab_Variables *v;
    SymTab_Functions *f;
    List *struct_infos = list_new();
    struct_info *s_info, *s_prec;

    // print header
    printf("GLOBAL SYMBOL TABLE\n");
    printf("Name\t\tKind\t\tType\t\tDimension\n");
    print_tilde();

    // print global variables
    List *var = symtab->global_variables;
    for(i = 0; i<list_length(var); i++)
    {
        v = list_get(var,i);
        print_symvar(v,"VAR",struct_infos);
    }
    if(list_length(var)!=0) {
        print_tilde();
        print_struct_info(struct_infos);
    }

    // print functions
    List *fun = symtab->functions;
    for(i = 0; i<list_length(fun); i++)
    {
        f = list_get(fun,i);
        print_symvar(f->func_name,"FUN",struct_infos);
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

/* Lookup function returns both position and where the variable is within the Symbol Table */
int lookup(SymTab *symtab, char *name, char *scope)
{
    int i, pos=-1;
    SymTab_Variables *v;

    if(strcmp(scope,"GLOBAL") == 0)
    {
        for(i=0; i<list_length(symtab->global_variables);i++)
        {
            v = list_get(symtab->global_variables,i);

            if(name == v->name)
            {
                pos = i;
                break;
            }
        }
    }
    else
    {
        SymTab_Functions *f;
        for(int i=0; i<list_length(symtab->functions);i++)
        {
            f = list_get(symtab->functions,i);
            if(scope == f->func_name->name)
            {
                // check if name is a parameter name
                for(i=0; i<list_length(f->parameters);i++)
                {
                    v = list_get(f->parameters,i);

                    if(name == v->name)
                    {
                        pos = i;
                        break;
                    }
                }

                if(pos==-1)         // name is not a parameter
                {
                    // check if name is a local variable name
                    for(i=0; i<list_length(f->local_variables);i++)
                    {
                        v = list_get(f->local_variables,i);

                        if(name == v->name)
                        {
                            pos = i;
                            break;
                        }
                    }
                    
                    // name is not a local variable
                    if(pos==-1) pos=lookup(symtab, name, "GLOBAL");
                }
            }
        }
    }

    return pos;
}

/* Remove a specific SymTab_Variable from Symbol Table */
void remove_symtab_variable(SymTab *symtab, char *scope, int pos)
{
    int i;    

    if(strcmp(scope,"GLOBAL") == 0) list_remove(symtab->global_variables,pos);
    else
    {
        SymTab_Functions *f;
        for(int i=0; i<list_length(symtab->functions);i++)
        {
            f = list_get(symtab->functions,i);
            if(scope == f->func_name->name) list_remove(f->local_variables,pos);
        }
    }
}



