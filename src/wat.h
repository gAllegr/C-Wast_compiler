#include <stdio.h>
#include "list.h"
#include "ast.h"
#include "symtab.h"
#include "utils.h"

#ifndef WAT_H
#define WAT_H

FILE *fp;

/* Imports, to be written depending on flags */
extern char *imports[3];
extern int import_flag[3];

/* List of data in memory */
List *data;
int data_index;

/* Functions */
char *function;
/* Variables */
char *glob_var;
char *local_var;
char *init;         // inizialization for local variables
char *instr;

/* Function prototypes */
void code_generation(AST *ast, SymTab *symtab);
char *convert_code (AST *ast, SymTab *symtab, char *scope, int indent);

#endif