/*
	Header file for symbol table
	https://troydhanson.github.io/uthash/userguide.html
 */

#include "uthash.h"

/* Type of token class for identifiers */
typedef enum token_class
{
	VAR = 1, // Variable
	PAR = 2  // Parameter
} token_class;

/* Type for variables and return type for functions */
typedef enum token_type
{
	VOID_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE,
	STRUCT_TYPE
} token_type;

/* Symbol table for variables, if an array saves array size */
struct variable_table
{
	char *name;
	token_class token;
	token_type type;
	int declared;
	int inizialized;
	int scope;

	int size; 							/* array dimension */

	struct variable_table *next; 		/* pointer to next item in the list */

	UT_hash_handle hh; 					/* makes this structure hashable */
};
typedef struct variable_table variable_table;

/* Symbol table for functions, contains a pointer to local variables symbol table */
struct function_table
{
	char *name;
	token_type type; 					/* return type */
	variable_table **lvar_table;
	int scope;

	struct function_table *next; 		/* pointer to next item in the list */

	UT_hash_handle hh; 					/* makes this structure hashable */
};
typedef struct function_table function_table;

/* hash tables declarations */
variable_table **gvar_table;
function_table **func_table;

/* Tables initialization */
void init_variable_table();
void init_func_table();

/* Insert entry to global table or local tables */
void insert_var(char *, token_class, token_type, int, int, int);

/*Insert entry to function tables */
void insert_func(char *, token_type, variable_table **);

variable_table *findvar(char *name);  	// search for variable entry
function_table *findfunc(char *name); 	// search for function entry

// void incr_scope(); // go to next scope
// void symtab_dump(FILE *of); // dump file