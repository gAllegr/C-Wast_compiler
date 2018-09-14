#include "ast.h"
#include "list.h"
#include "symtab.h"

#ifndef UTILS_H
#define UTILS_H

/* ===== Concatenation of many strings ===== */
char* concat(int n_token, char *sep, char *token,...);     /* concat tokens of a rule */

/* ===== Convert list of AST into list of SymTab_Variables ===== */
List *convert(List *start);

/* ===== Prepare List *struct_element needed to create struct_info ===== */
List *prepare_struct_elements(int n, List *elements);

#endif