#include "list.h"

#ifndef SYMTAB_H
#define SYMTAB_H

char *scope;

/* Enumeration for value types */
typedef enum ValType {
    T_VOID,
    T_INT,
    T_FLOAT,
    T_CHAR,
    T_STRUCT,
    T_NULL          /* to be used if we don't know type */
} ValType;

/* Struct information */
typedef struct struct_info {
    char *struct_name;
    List *struct_element;       // list of list of SymTab_Variables 
                                // this list will have only one list inside if n=-1, otherwise will have n lists inside
} struct_info;

/* Symbol Table for all variables */
typedef struct SymTab_Variables {
    char *name;
    int n;                          // array dimension, -1 for simple variables and -2 if we can't get array dimension
    ValType type;
    struct_info *s_info;            // !NULL only if variable is a struct

    int declared;
    int inizialized;    
} SymTab_Variables;

/* Symbol Table for functions */
typedef struct SymTab_Functions {
    SymTab_Variables *func_name;
    List *parameters;               // list of SymTab_Variables
    List *local_variables;          // list of SymTab_Variables
} SymTab_Functions;

/* Symbol Table of whole program */
typedef struct SymTab {
    List *global_variables;         // list of SymTab_Variables
    List *functions;                // list of SymTab_Functions
} SymTab;

/* Functions */
SymTab_Variables *new_SymTab_Variables (char *name, int n, ValType type, struct_info *s_info, int declared, int inizialized);
SymTab_Functions *new_SymTab_Functions (SymTab_Variables *func_name);
struct_info *new_struct_info (char *name, List *elements);

SymTab *init_symtab();

void insert_var(SymTab *symtab, SymTab_Variables *sym_var, char *scope);
void insert_fun(SymTab *symtab, SymTab_Functions *sym_fun);
void update_par(SymTab *symtab, List *parameters, char *scope);

void print_symtab(SymTab *symtab);
void print_symfun(SymTab_Functions* symfun);
void print_symvar(SymTab_Variables *symvar,char *kind, List *struct_infos);
void print_struct_info(List *struct_infos);

int lookup(SymTab *symtab, char *name, char *scope, int *where);
void remove_symtab_variable(SymTab *symtab, char *scope, int pos);

#endif