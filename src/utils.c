#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"

/* ===== Concatenation of many strings ===== */

char* concat(int n_token, char *sep, char *token,...)
{
	int i;
	va_list vl;
	char concatenated[200] = "", *ret;

	strcat(concatenated,token);
	va_start(vl,token);

	for(i=1; i<n_token; i++)
	{
		strcat(concatenated,sep);
		strcat(concatenated,va_arg(vl,char *));
	}

	va_end(vl);
	ret = concatenated;
	return ret;
}

/* ===== Convert list of AST into list of SymTab_Variables ===== */

List *convert(List *start)
{
	// start will contain a list of AST nodes (N_VARIABLE or N_ASSIGNMENT)

	List *final = list_new();

	AST *a;
	for(int i=0; i<list_length(start);i++)
	{
		a = list_get(start,i);
		switch(a->type)
		{
			case N_VARIABLE:
				list_append(final, a->ast_variable->sym_variable);
				break;
			case N_ASSIGNMENT:
					printf("Struct elements cannot be inizialized!!!\n\n");
					exit(EXIT_FAILURE);
				break;
		}
	}

	return final;
}

/* ===== Prepare List *struct_element needed to create struct_info ===== */
List *prepare_struct_elements(int n, List *elements)
{
	List *e = list_new();

	switch(n)
	{
		case -2:        // don't know array dimension
		case -1:        // simple variable
			list_append(e,elements);
			break;
		default:        // array variable with n elements
			for(int j=0; j<n; j++) list_append(e,elements);
			break;
	}

	return e;
}

/* ===== Update node type in AST using Symbol Table ===== */
void *update_node_type(AST *node, SymTab *symtab, int where, int pos)
{
	int f_pos;
	SymTab_Functions *f;
    SymTab_Variables *a;

	// retrieve variable type from Symbol Table
	switch(where)
	{
		case 0:     // variable is global
			a = list_get(symtab->global_variables,pos);
			break;
		case 1:     // variable is a parameter
			f_pos = lookup(symtab, scope, "GLOBAL",&where);
			f = symtab->functions->items[f_pos];
			a = list_get(f->parameters,pos);
			break;
		case 2:     // variable is local
			f_pos = lookup(symtab, scope, "GLOBAL",&where);
			f = symtab->functions->items[f_pos];
			a = list_get(f->local_variables,pos);
			break;
	}
	// update type in AST
	node->ast_variable->sym_variable->type = a->type;
}
