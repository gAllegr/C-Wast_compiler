#include "symboltable.h"
#include <stdio.h>

/* current scope */
int cur_scope = 0;

void init_variable_table()
{
	gvar_table = NULL;
}

void init_func_table()
{
	func_table = NULL;
}

void insert_var(char *name, token_class class, token_type type, int declared, int initialized, int size)
{
	struct variable_table *s;
	HASH_FIND_STR(*gvar_table, name, s);
	while ((s != NULL) && (strcmp(name, s->name) != 0))
		s = s->next;

	if (s == NULL)
	{
		s = malloc(sizeof(struct variable_table));
		strcpy(s->name, name);
		s->token = class;
		s->type = type;
		s->declared = declared;
		s->inizialized = initialized;
		s->scope = cur_scope;
		s->size = size;

		/* "name" corresponds to key field */
		HASH_ADD_KEYPTR(hh, *gvar_table, s->name, strlen(s->name), s);
	}
	else
	{
		s->scope = cur_scope;
		while (s->next != NULL)
			s = s->next;
		
		/* add linenumber to reference list */
//		s->next = (RefList *)malloc(sizeof(RefList));
//		s->next->lineno = lineno;
//		s->next->next = NULL;
//		printf("Found %s again at line %d!\n", name, lineno);
	}
}

void insert_func(char *name, token_type type, variable_table **table)
{
	struct function_table *s;

	if (s == NULL)
	{
		s = malloc(sizeof(struct function_table));
		strcpy(s->name, name);
		s->type = type;
		s->lvar_table = table;
		s->scope = cur_scope;

		/* "name" corresponds to key field */
		HASH_ADD_KEYPTR(hh, *func_table, s->name, strlen(s->name), s);
	}
	else
	{
		s->scope = cur_scope;
		while (s->next != NULL)
			s = s->next;
		
		/* add linenumber to reference list */
//		s->next = (RefList *)malloc(sizeof(RefList));
//		s->next->lineno = lineno;
//		s->next->next = NULL;
//		printf("Found %s again at line %d!\n", name, lineno);
	}
}

variable_table *findvar(char *name)
{ /* return symbol if found or NULL if not found */
	variable_table *s;
	HASH_FIND_STR(*gvar_table, name, s);
	while ((s != NULL) && (strcmp(name, s->name) != 0))
		s = s->next;
	return s; // NULL is not found
}

function_table *findfunc(char *name)
{ /* return symbol if found or NULL if not found */
	function_table *s;
	HASH_FIND_STR(*func_table, name, s);
	while ((s != NULL) && (strcmp(name, s->name) != 0))
		s = s->next;
	return s; // NULL is not found
}

// void incr_scope(){ /* go to next scope */
// 	cur_scope++;
// }
