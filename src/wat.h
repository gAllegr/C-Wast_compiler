#include <stdio.h>
#include "list.h"
#include "ast.h"
#include "symtab.h"
#include "utils.h"

#ifndef WAT_H
#define WAT_H

FILE *fp;

/* Imports, to be written depending on flags */
extern char *imports[4];
extern int imports_flag[4];

/* List of data in memory */
List *data;
int data_index;

/* For-loop index */
int for_loop_index;

/* Function prototypes */
void code_generation(AST *ast, SymTab *symtab, char *filename);
char *indentation (int n);
char *convert_code (AST *ast, SymTab *symtab, char *scope, int indent);

/* Create auxiliary files */
void createAuxFiles(char *filename);
void wat2wasm(char *filename);
void createHTML();
void createCSS();
void createJS(char *filename);

#endif