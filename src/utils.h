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

/* ===== Update node type in AST using Symbol Table ===== */
void update_node_type(AST *node, SymTab *symtab, int where, int pos);

/* ===== Update inizialization flag of a variable in Symbol Table ===== */
void update_inizialization(SymTab *symtab, char *name, char *scope);

/* ===== Update inizialization flag of a struct element variable in Symbol Table ===== */
void update_struct_element_init(SymTab *symtab, char *name, char *scope, int pos_elem);

/* ===== Evaluate type of expression rule ===== */
ValType evaluate_expression_type(AST *ast, SymTab *symtab, char *scope);

/* ===== Check type of inizialization list elements ===== */
ValType check_array_init_list(char *var_assign_name, List *list);

/* ===== Semantic check on variable assignment ===== */
int check_decl_assignment(SymTab_Variables *var_assign, AST *expression, SymTab *symtab, char *scope);

/* ===== Check matching between arguments and parameters ===== */
void check_args_params(SymTab *symtab, char *scope, char *function_name, List *args);

#endif