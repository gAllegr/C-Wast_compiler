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
	va_start(vl,token);

	char *concatenated = token;
	for(i=1; i<n_token; i++)
	{
		concatenated = strcat(strcat(concatenated,sep),va_arg(vl,char *));
	}

	va_end(vl);
	return concatenated;
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



