#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"
#include "symtab.h"

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
void update_node_type(AST *node, SymTab *symtab, int where, int pos)
{
	int f_pos;
	SymTab_Functions *f;
    SymTab_Variables *a;

	// update type in AST
	a = get_symtab_var(symtab, scope, pos, where);
	if(node->type == N_VARIABLE) node->ast_variable->sym_variable->type = a->type;
	else node->ast_assign->variable->ast_variable->sym_variable->type = a->type;
}

/* ===== Update inizialization flag of a variable in Symbol Table ===== */
void update_inizialization(SymTab *symtab, char *name, char *scope)
{
	int pos, where;

	int f_pos;
	SymTab_Functions *f;
    SymTab_Variables *a;

	// find the variable
	pos = lookup(symtab, name, scope, &where);

	// update variable's inizialization flag from Symbol Table
	switch(where)
	{
		case 0:     // variable is global
			a = list_get(symtab->global_variables,pos);
			a->inizialized = 1;
			symtab->global_variables->items[pos] = a;
			break;
		case 1:     // variable is a parameter
			f_pos = lookup(symtab, scope, "GLOBAL",&where);
			f = list_get(symtab->functions,f_pos);
			a = list_get(f->parameters,pos);
			a->inizialized = 1;
			f->parameters->items[pos] = a;
			symtab->functions->items[f_pos] = f;
		
			break;
		case 2:     // variable is local
			f_pos = lookup(symtab, scope, "GLOBAL",&where);
			f = list_get(symtab->functions,f_pos);
			a = list_get(f->local_variables,pos);
			a->inizialized = 1;
			f->local_variables->items[pos] = a;
			symtab->functions->items[f_pos] = f;
			break;
	}
}

/* ===== Update inizialization flag of a struct element variable in Symbol Table ===== */
// array_list is the index of which list of element must be consider (case of array variable of type struct)
void update_struct_element_init(SymTab *symtab, char *scope, char *var_name, int array_list, int pos_elem)
{
	int pos, where;

	int f_pos;
	SymTab_Functions *f;
    SymTab_Variables *a, *struct_element;
	List *elements;

	// find the variable
	pos = lookup(symtab, var_name, scope, &where);

	// update variable's inizialization flag from Symbol Table
	switch(where)
	{
		case 0:     // variable is global
			a = list_get(symtab->global_variables,pos);
			elements = a->s_info->struct_element->items[array_list];
			struct_element = elements->items[pos_elem];
			struct_element->inizialized = 1;
			elements->items[pos_elem] = struct_element;
			a->s_info->struct_element->items[array_list] = elements;
			symtab->global_variables->items[pos] = a;
			break;
		case 2:     // variable is local
			f_pos = lookup(symtab, scope, "GLOBAL",&where);
			f = list_get(symtab->functions,f_pos);
			a = list_get(f->local_variables,pos);
			elements = a->s_info->struct_element->items[array_list];
			struct_element = elements->items[pos_elem];
			struct_element->inizialized = 1;
			elements->items[pos_elem] = struct_element;
			a->s_info->struct_element->items[array_list] = elements;			
			f->local_variables->items[pos] = a;
			symtab->functions->items[f_pos] = f;
			break;
	}
}

/* ===== Evaluate type of expression rule ===== */
ValType evaluate_expression_type(AST *ast, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);

	int pos, where;
	SymTab_Variables *var;
	AST *l, *r;
	ValType l_type,r_type;

	switch(ast->type)
	{
		case N_CONSTANT:
			return ast->ast_constant->type;
			break;
		case N_VARIABLE:
			// check if variable has been declared
			pos = lookup(symtab, ast->ast_variable->sym_variable->name, scope, &where);
			if(pos == -1)
			{
				char error[50];
				sprintf(error,"Expression variable %s not declared",ast->ast_variable->sym_variable->name);
				yyerror(error);
				exit(1); 
			}
			else
			{
				if(where == 3)
				{
					// lookup discover argument has same name of a function
					char error[80];
					sprintf(error,"Variable %s has not been declared as variable, but it's a function", ast->ast_variable->sym_variable->name);
					yyerror(error);
					exit(1);  
				}				
			}

			// check if variable has been inizialized
			var = get_symtab_var(symtab, scope, pos, where);
			if(var->inizialized == 0)
			{
				char error[60];
				if(ast->ast_variable->sym_variable->n == -1)
					sprintf(error,"Inizialization variable %s has not been valorized",ast->ast_variable->sym_variable->name);
				else
					sprintf(error,"Inizialization variable %s[%d] has not been valorized",ast->ast_variable->sym_variable->name,ast->ast_variable->sym_variable->n);
				yyerror(error);
				exit(1); 
			}
			// update variable type in AST
			ast->ast_variable->sym_variable->type = var->type;

			return var->type;
			break;
		case N_UNARY_EXPR:
			l = ast->ast_unary_expr->expression;
			return evaluate_expression_type(l, symtab, scope);
			break;
		case N_BINARY_EXPR:
			l = ast->ast_binary_expr->left;
			r = ast->ast_binary_expr->right;
			l_type = evaluate_expression_type(l, symtab, scope);
			r_type = evaluate_expression_type(r, symtab, scope);
			
			// check if types match
			if(l_type != r_type)
			{
				yyerror("Mismatch type between first and second expression arguments");
				exit(1); 
			}

			return l_type;
			break;
	}
}

/* ===== Check type of inizialization list elements ===== */
ValType check_array_init_list(char *var_assign_name, List *list)
{
	extern void yyerror(const char *s);

    ValType t_elem;

	char error[100];

    // retrieve type of first element
    AST *element = list_get(list,0);

	// check that a char constant is not a string literal
	if(element->ast_constant->type == T_CHAR && strlen(element->ast_constant->sval)>3)
	{
		sprintf(error,"In array variable %s -> An array element cannot be a string literal", var_assign_name);
		yyerror(error);
		exit(1);
	}

	t_elem = element->ast_constant->type;

    // verify that type of other array element is the same of the first one
    for(int i=1; i<list_length(list);i++)
    {
        element = list_get(list,i);

		// check that a char constant is not a string literal
		if(element->ast_constant->type == T_CHAR && strlen(element->ast_constant->sval)>3)
		{
			sprintf(error,"In array variable %s -> An array element cannot be a string literal",var_assign_name);
			yyerror(error);
			exit(1);
		}

		// check that type is the same of the first element
		if(t_elem != element->ast_constant->type)
		{
			sprintf(error,"In array variable %s -> Array elements have different value types",var_assign_name);
			yyerror(error);
			exit(1); 
		}
    }

    return t_elem;
}

/* ===== Semantic check on variable assignment ===== */
int check_decl_assignment(SymTab_Variables *var_assign, AST *expression, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);
	
	SymTab_Variables *assignment_variable;
	AST *assignment_value;
	ValType assign_value_type;							// value type of expression branch

	int where, pos, i;
    SymTab_Variables *a;

	char error[120];

	if(var_assign->type != T_STRUCT)
	{
		// NOT STRUCT VARIABLE
		// variable is simple variable
		if(var_assign->n == -1)
		{
			switch(expression->type)
			{
				case N_CONSTANT:
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]!='\'')
					{
						sprintf(error,"Cannot assign a string to variable %s", var_assign->name);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					sprintf(error,"Cannot assign a variable to variable %s. Value must be constant", var_assign->name);
					yyerror(error);
					exit(1); 
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot assign a list of values! Variable %s is not an array", var_assign->name);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					assign_value_type = assignment_variable->type;
					break;
			}
		}

		// variable is an array and dimension is known
		if(var_assign->n > -1)
		{
			switch(expression->type)
			{
				case N_CONSTANT:
					if(expression->ast_constant->type == T_CHAR)
					{
						// this is the case of an array of char inizialized using a char/string
						// checked that array dimension is greater than char/string constant length
						// the -2 is necessary because char are saved with initial and final "
						if(var_assign->n > strlen(expression->ast_constant->sval)-2)
						{
							// check if it's a char constant (not a string literal)
							if(expression->ast_constant->sval[0]=='\'')
							{
								sprintf(error,"Cannot assign a constant value! Variable %s is an array", var_assign->name);
								yyerror(error);
								exit(1); 
							}

							assign_value_type = T_CHAR;
						} 
						else
						{
							sprintf(error,"Array variable %s is too small to save string %s", var_assign->name, expression->ast_constant->sval);
							yyerror(error);
							exit(1); 
						}						
					}
					else
					{
						sprintf(error,"Cannot assign a constant value! Variable %s is an array", var_assign->name);
						yyerror(error);
						exit(1); 
					}
					break;
				case N_VARIABLE:
					sprintf(error,"Cannot assign a variable to array %s[%d]. Value must be constant", var_assign->name, var_assign->n);
					yyerror(error);
					exit(1); 
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					sprintf(error, "Cannot inizialize array %s[%d] with an expression", var_assign->name, var_assign->n);
					yyerror(error);
					exit(1);
					break;
				case N_LIST:
					// check array and inizialization list dimension 
					// check if it's an array of char and array size and inizialization list size are equal
					if(var_assign->type==T_CHAR && list_length(expression->ast_list->list) == var_assign->n)
					{
						sprintf(error,"Char array dimension of %s is equal to number of elements of inizialization list", var_assign->name);
						yyerror(error);
						exit(1);
					}

					// check if it's an array of char and array size is smaller than inizialization list length
					if(var_assign->type==T_CHAR && var_assign->n < list_length(expression->ast_list->list))
					{
						sprintf(error,"Array dimension of %s is smaller than number of elements of inizialization list", var_assign->name);
						yyerror(error);
						exit(1);
					}

					// check if it's not a char array and list length is not equal to array dimension
					if(var_assign->type != T_CHAR && list_length(expression->ast_list->list) != var_assign->n)
					{
						sprintf(error,"Array dimension of %s and number of elements of inizialization list are different", var_assign->name);
						yyerror(error);
						exit(1);
					} 

					// check inizialization elements type
					assign_value_type = check_array_init_list(var_assign->name, expression->ast_list->list);
					break;
				case N_CALL_FUNCTION:
					sprintf(error, "Cannot inizialize array %s[%d] with a function", var_assign->name, var_assign->n);
					yyerror(error);
					exit(1);
					break;
			}
		}
	}
	else
	{
		// STRUCT VARIABLE
		switch(expression->type)
		{
			case N_CONSTANT:
				sprintf(error, "Cannot inizialize struct variable %s with a constant", var_assign->name);
				yyerror(error);
				exit(1);
				break;
			case N_VARIABLE:
				sprintf(error, "Cannot assign a variable to struct variable %s. Value must be constant", var_assign->name);
				yyerror(error);
				exit(1);
				break;
			case N_BINARY_EXPR:
			case N_UNARY_EXPR:
				sprintf(error, "Cannot inizialize struct variable %s with an expression", var_assign->name);
				yyerror(error);
				exit(1);
				break;
			case N_LIST:
				;
				List *struct_elements;

				// variable is simple variable
				if(var_assign->n == -1)
				{			
					struct_elements = var_assign->s_info->struct_element->items[0];
					if(list_length(struct_elements) != list_length(expression->ast_list->list))
					{
						sprintf(error,"Number of struct elements of variable %s and number of elements of inizialization list are different", var_assign->name);
						yyerror(error);
						exit(1);
					}

					int init;
					
					for(i=0; i<list_length(struct_elements);i++)
					{
						// retrieve elements of interest
						assignment_variable = list_get(struct_elements,i);
						assignment_value = list_get(expression->ast_list->list,i);
						// check assignment
						init = check_decl_assignment(assignment_variable, assignment_value, symtab, scope);
						if(init == 1)                   // types are the same
                            {
                                // update Symbol Table
	                            update_struct_element_init(symtab, scope, var_assign->name, 0, i);
                            }
                            else                            // type mismatch
                            {
                                sprintf(error,"Mismatch type between inizialized variable %s and expression", var_assign->name);
                                yyerror(error);
                                exit(1); 
                            }
					}
				}
				else
				{
					// variable is an array and dimension is known
					// check if inizialization elements have been provided for all array element of struct variable
					List *list_struct_elements = var_assign->s_info->struct_element;
					if(list_length(list_struct_elements) != list_length(expression->ast_list->list))
					{
						sprintf(error,"Struct variable %s is an array. To inizializate it, please provide all array element inizialization", var_assign->name);
						yyerror(error);
						exit(1);
					}
					
					// extract the single struct array element and inizialization list
					AST *ast_init_elements;
					List *init_elements;

					for(int j=0; j<list_length(list_struct_elements);j++)
					{
						// get lists to be compared
						struct_elements = list_get(list_struct_elements,j);
						ast_init_elements = list_get(expression->ast_list->list,j);			// AST_List that contains the list of elements
						init_elements = ast_init_elements->ast_list->list;

						if(list_length(struct_elements) != list_length(init_elements))
						{
							sprintf(error,"Number of struct elements of variable %s[%d] and number of elements of inizialization list are different", var_assign->name, j);
							yyerror(error);
							exit(1);
						}

						int init;
						
						for(i=0; i<list_length(struct_elements);i++)
						{
							// retrieve elements of interest
							assignment_variable = list_get(struct_elements,i);
							assignment_value = list_get(init_elements,i);
							// check assignment
							init = check_decl_assignment(assignment_variable, assignment_value, symtab, scope);
							if(init == 1)                   // types are the same
								{
									// update Symbol Table
									update_struct_element_init(symtab, scope, var_assign->name, j, i);
								}
								else                            // type mismatch
								{
									sprintf(error,"Mismatch type between inizialized variable %s and expression", var_assign->name);
									yyerror(error);
									exit(1); 
								}
						}
					}
				}

				assign_value_type = T_STRUCT;
				break;
			case N_CALL_FUNCTION:
				sprintf(error, "Cannot inizialize struct variable %s with a function", var_assign->name);
				yyerror(error);
				exit(1);
				break;
		}
	}

	// check if types are the same
	if(var_assign->type != assign_value_type) return 0;
	else return 1;

}

/* ===== Check matching between arguments and parameters ===== */
void check_args_params (SymTab *symtab, char *scope, char *function_name, List *args)
{
	extern void yyerror(const char *s);

	AST *node;
	SymTab_Functions *f;
	SymTab_Variables *a, *p;
	int i, pos, where;

	// check if arguments have been defined and update their type in AST
	for(i=0; i<list_length(args);i++)
	{
		node = list_get(args,i);
		pos = lookup(symtab, node->ast_variable->sym_variable->name, scope, &where);
		if(pos == -1)
		{
			// argument variable not declared before
			char error[60];
			sprintf(error,"Argument variable n.%d has not been declared", i+1);
			yyerror(error);
			exit(1);  
		}
		else
		{
			if(where == 3)					
			{
				// lookup discover argument has same name of a function
				char error[90];
				sprintf(error,"Argument variable n.%d has not been declared as variable, but it's a function", i+1);
				yyerror(error);
				exit(1);  
			} 

			update_node_type(node, symtab, where, pos);
			args->items[i] = node;
		}
	}       

	// check if arguments and parameters have same number
	pos = lookup(symtab, function_name, scope, &where);
	if(where != 3)
	{
		// lookup didn't find function as a function
		char error[90];
		sprintf(error,"Can't find function %s among functions", function_name);
		yyerror(error);
		exit(1);  
	}

	f = symtab->functions->items[pos];
	List *par = f->parameters;
	List *arg = convert(args);
	if(list_length(arg)!=list_length(par))
	{
		yyerror("Number of arguments and parameters doesn't match");
		exit(1);  
	} 

	// check if arguments and parameters have same type
	for(int i=0;i<list_length(par);i++)
	{
		a = list_get(arg,i);
		p = list_get(par,i);

		if(a->type != p->type)
		{
			char error[60];
			sprintf(error,"Type of n.%d argument and parameter doesn't match", i+1);
			yyerror(error);
			exit(1);  
		} 
	}
}

/* ===== Semantic check on Assignment Node ===== */
int check_assignment(AST *ast_assignment, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);
	
	AST *variable = ast_assignment->ast_assign->variable;
	AST *expression = ast_assignment->ast_assign->expression;
	SymTab_Variables *var_assign = variable->ast_variable->sym_variable;

	SymTab_Variables *assignment_variable;				// struct element to which assign value
	AST *assignment_value;								// value to assign to struct element (assignment_variable)

	ValType variable_type;
	ValType assign_value_type;							// value type of expression branch

	int where, pos, i;
    SymTab_Variables *a;

	char error[120];

	// check assignment
	if(var_assign->type != T_STRUCT)
	{
		// NOT STRUCT VARIABLE

		// check if variable on the left of assignment has been declared
		pos = lookup(symtab, var_assign->name, scope, &where);

		if(pos == -1)
		{
			sprintf(error,"Assignment variable %s not declared",var_assign->name);
			yyerror(error);
			exit(1); 
		}
		// retrieve variable from symbol table and update variable type in AST
		a = get_symtab_var(symtab, scope, pos, where);
		variable->ast_variable->sym_variable->type = a->type;
		ast_assignment->ast_assign->variable = variable;

		variable_type = var_assign->type;

		// variable is simple variable
		if(var_assign->n == -1)
		{
			switch(expression->type)
			{
				case N_CONSTANT:
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]!='\'')
					{
						sprintf(error,"Cannot assign a string to variable %s", var_assign->name);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot assign a list of values! Variable %s is not an array", var_assign->name);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}

		// variable is an array and index is known
		if(var_assign->n > -1)
		{
			// array variable with integer index specified -> check index is lower than array dimension
			if(var_assign->n >= a->n)
			{
				sprintf(error,"Array index out of range for variable %s", var_assign->name);
				yyerror(error);
				exit(1); 
			}

			switch(expression->type)
			{
				case N_CONSTANT:
					// check if it's a string literal
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]=='\"')
					{
						sprintf(error,"Cannot assign a string! Variable %s[%d] is an element of an array", var_assign->name, var_assign->n);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index of expression array variable is out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot inizialize array element %s[%d] with a list", var_assign->name, var_assign->n);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}

		// variable is an array and index is unknown
		if(var_assign->n == -2)
		{
			// array variable with integer index not specified -> can't check index is lower than array dimension

			switch(expression->type)
			{
				case N_CONSTANT:
					// check if it's a string literal
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]=='\"')
					{
						sprintf(error,"Cannot assign a string! Variable %s[%d] is an element of an array", var_assign->name, var_assign->n);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index of expression array variable is out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot inizialize array element %s[%d] with a list", var_assign->name, var_assign->n);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}
	}
	else
	{
		// check if variable on the left of assignment has been declared
		char str[15] = "";
		strcpy(str, var_assign->name);
		char *name = strtok(str, ".");
		int s_pos = lookup(symtab, name, scope, &where);

		if(s_pos == -1)
		{
			sprintf(error,"Assignment variable %s not declared",var_assign->name);
			yyerror(error);
			exit(1); 
		}
		// retrieve variable from symbol table
		a = get_symtab_var(symtab, scope, s_pos, where);
		

		// find element inside variable
		SymTab_Variables *e;
		char *element_name = strtok(NULL, ".");			// get name of the interested struct element
		int e_pos = -1;
		List *l =a->s_info->struct_element->items[0];
		for(i=0; i<list_length(l);i++)
		{
			e = list_get(l,i);
			if(strcmp(e->name,element_name)==0) e_pos = i;
		}
		if(e_pos == -1)
		{
			sprintf(error,"Struct %s has no field %s", a->name, element_name);
			yyerror(error);
			exit(1);
		}
		// retrieve element from variable
		e = list_get(a->s_info->struct_element->items[0],e_pos);

		variable_type = e->type;

		// variable is simple variable
		if(e->n == -1)
		{
			switch(expression->type)
			{
				case N_CONSTANT:
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]!='\'')
					{
						sprintf(error,"Cannot assign a string to variable %s", e->name);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot assign a list of values! Variable %s is not an array", e->name);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}

		// variable is an array and index is known
		if(e->n > -1)
		{
			// array variable with integer index specified -> check index is lower than array dimension
			if(e->n >= a->n)
			{
				sprintf(error,"Array index out of range for variable %s", e->name);
				yyerror(error);
				exit(1); 
			}

			switch(expression->type)
			{
				case N_CONSTANT:
					// check if it's a string literal
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]=='\"')
					{
						sprintf(error,"Cannot assign a string! Variable %s[%d] is an element of an array", e->name, e->n);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index of expression array variable is out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot inizialize array element %s[%d] with a list", e->name, e->n);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}

		// variable is an array and index is unknown
		if(e->n == -2)
		{
			// array variable with integer index not specified -> can't check index is lower than array dimension

			switch(expression->type)
			{
				case N_CONSTANT:
					// check if it's a string literal
					if(expression->ast_constant->type == T_CHAR && expression->ast_constant->sval[0]=='\"')
					{
						sprintf(error,"Cannot assign a string! Variable %s[%d] is an element of an array", e->name, e->n);
						yyerror(error);
						exit(1); 
					}

					assign_value_type = expression->ast_constant->type;
					break;
				case N_VARIABLE:
					;
					// check if variable has been declared
					char *name;

					if(expression->ast_variable->sym_variable->type == T_STRUCT)
					{
						char str[15];
						strcpy(str, expression->ast_variable->sym_variable->name);
						name = strtok(str, ".");
						pos = lookup(symtab, name, scope, &where);
					}
					else name = expression->ast_variable->sym_variable->name;

					pos = lookup(symtab, name, scope, &where);
					if(pos == -1)
					{
						sprintf(error,"Inizialization variable %s not declared",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// retrieve variable from symbol table
					assignment_variable = get_symtab_var(symtab, scope, pos, where);
					// check if variable has been valorized
					if(assignment_variable->inizialized == 0)
					{
						sprintf(error,"Inizialization variable %s has not been inizialized",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					
					// update variable type in AST
					expression->ast_variable->sym_variable->type = assignment_variable->type;
					ast_assignment->ast_assign->expression = expression;

					// other checks depending on kind of variable
					// simple variable -> check it's not an array instead
					if(expression->ast_variable->sym_variable->n==-1 && assignment_variable->n != -1)
					{
						sprintf(error,"Inizialization variable %s is an array",expression->ast_variable->sym_variable->name);
						yyerror(error);
						exit(1); 
					}
					/* array variable with unknown index value -> index variable has been declared
																  index variable has been inizializated
						There 2 checks are done within grammar, inside "identifier" rule */
					// array variable with integer index specified -> check index is lower than array dimension
					if(expression->ast_variable->sym_variable->n > 0 && expression->ast_variable->sym_variable->n >= assignment_variable->n)
					{
						yyerror("Array index of expression array variable is out of range");
						exit(1); 
					}

					assign_value_type = assignment_variable->type;
					break;
				case N_BINARY_EXPR:
				case N_UNARY_EXPR:
					assign_value_type = evaluate_expression_type(expression, symtab, scope);
					break;
				case N_LIST:
					sprintf(error,"Cannot inizialize array element %s[%d] with a list", e->name, e->n);
					yyerror(error);
					exit(1); 
					break;
				case N_CALL_FUNCTION:
					assignment_variable = expression->ast_call_function->func_name->ast_variable->sym_variable;
					// check of function definition is done inside func_call rule
					
					// retrieve variable from symbol table and update variable type in AST
					a = get_symtab_var(symtab, scope, pos, where);
					assignment_variable->type = a->type;
					expression->ast_call_function->func_name->ast_variable->sym_variable = assignment_variable;

					assign_value_type = assignment_variable->type;
					break;
			}
		}

	}

	// check if types are the same
	if(variable_type != assign_value_type) return 0;
	else return 1;

}

/* ===== Check if variable is found in Symbol Table ===== */
void is_var_declared (AST *ast, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);

	int pos, where;
	char error[50];

	if(ast->ast_variable->sym_variable->type != T_STRUCT)
	{
		// NOT STRUCT VARIABLE
		pos = lookup(symtab, ast->ast_variable->sym_variable->name, scope, &where);

		if(pos == -1)
		{
			sprintf(error,"Variable %s not declared",ast->ast_variable->sym_variable->name);
			yyerror(error);
			exit(1); 
		}
		else
		{
			// update type in AST
			SymTab_Variables *a = get_symtab_var(symtab, scope, pos, where);
			ast->ast_variable->sym_variable->type = a->type;
		}
	}
	else
	{
		// check if variable on the left of assignment has been declared
		char str[15] = "";
		strcpy(str, ast->ast_variable->sym_variable->name);
		char *name = strtok(str, ".");
		pos = lookup(symtab, name, scope, &where);

		if(pos == -1)
		{
			sprintf(error,"Variable %s not declared",ast->ast_variable->sym_variable->name);
			yyerror(error);
			exit(1); 
		}
		// retrieve variable from symbol table
		SymTab_Variables *a = get_symtab_var(symtab, scope, pos, where);
		
		// find element inside variable
		SymTab_Variables *e;
		char *element_name = strtok(NULL, ".");			// get name of the interested struct element
		int e_pos = -1;
		List *l =a->s_info->struct_element->items[0];
		for(int i=0; i<list_length(l);i++)
		{
			e = list_get(l,i);
			if(strcmp(e->name,element_name)==0) e_pos = i;
		}
		if(e_pos == -1)
		{
			sprintf(error,"Struct %s has no field %s", a->name, element_name);
			yyerror(error);
			exit(1);
		}
	}
}

/* ===== Verify return identifier's type ===== */
void verify_return_id_type (AST *ast, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);

	SymTab_Variables *a;
	int pos, where;
	char error[50];

	if(ast->ast_variable->sym_variable->type != T_STRUCT)
	{
		// NOT STRUCT VARIABLE
		pos = lookup(symtab, ast->ast_variable->sym_variable->name, scope, &where);

		// retrieve variable from Symbol Table
		a = get_symtab_var(symtab, scope, pos, where);
		// check if variable seems a simple varable, but actually it's an array
		if(ast->ast_variable->sym_variable->n == -1 && a->n != -1)
		{
			sprintf(error,"Variable %s is an array!",ast->ast_variable->sym_variable->name);
			yyerror(error);
			exit(1); 
		}
		
	}
	else
	{
		// STRUCT VARIABLE
		// check if point character is contained inside variable name
		char* pPosition = strchr(ast->ast_variable->sym_variable->name, '.');
		if(pPosition == NULL)
		{
			sprintf(error,"Variable %s is a struct!",ast->ast_variable->sym_variable->name);
			yyerror(error);
			exit(1); 
		}

		// char pointer is contained inside variable name. variable is kind of "structname"."elementname"
		// check if variable on the left of assignment has been declared
		char str[15] = "";
		strcpy(str, ast->ast_variable->sym_variable->name);
		char *name = strtok(str, ".");
		pos = lookup(symtab, name, scope, &where);
		// retrieve variable from symbol table
		a = get_symtab_var(symtab, scope, pos, where);
		
		// find element inside variable
		SymTab_Variables *e;
		char *element_name = strtok(NULL, ".");			// get name of the interested struct element
		int e_pos = -1;
		List *l =a->s_info->struct_element->items[0];
		for(int i=0; i<list_length(l);i++)
		{
			e = list_get(l,i);
			if(strcmp(e->name,element_name)==0) e_pos = i;
		}
		
		// verify if element is of a valide type (not struct)
		if(e->type == T_STRUCT)
		{
			sprintf(error,"Element %s is a struct!",ast->ast_variable->sym_variable->name);
			yyerror(error);
			exit(1); 
		}
	}
}

/* ===== Verify return statement ===== */
void check_return(ValType func_type, AST *body, SymTab *symtab, char *scope)
{
	extern void yyerror(const char *s);

	List *returns = list_new();						// will contain all return statements found
	List *statements = body->ast_body->statements;
	AST *statement;
	ValType ret_type;
	int i;

	char error[90];

	// loop over all statements to populate List *returns
	for(i=0;i<list_length(statements);i++)
	{
		statement = list_get(statements,i);
		// statement could be null if empty statement is found (;)
		if(statement!=NULL && statement->type == N_RETURN_STATEMENT) list_append(returns,statement);
	}

	// made checks based on function return type
	if(func_type==T_VOID)
	{
		if(list_length(returns) != 0)
			for(i=0;i<list_length(returns);i++)
			{
				statement = list_get(returns,i);
				if(statement->ast_return_stat->expression != NULL)
					yyerror("WARNING: 'return' with a value, in function returning void");
			}
	}
	else
	{
		// gcc don't give error if return statement is missing
		for(i=0;i<list_length(returns);i++)
		{
			statement = list_get(returns,i);
			if(statement->ast_return_stat->expression == NULL)
				yyerror("WARNING: 'return' with no value, in function returning non-void");
			else
			{
				ret_type = evaluate_expression_type(statement->ast_return_stat->expression, symtab, scope);
				if(func_type != ret_type)
				{
					// gcc do nothing in this case
					yyerror("WARNING: 'return' with value type different from function-returning type");
				}
			}
		}
	}
}
