#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "utils.h"

/* ===== Interface with lexer ===== */
extern char* yytext;
extern int yyparse();

int lineno = 1;

void yyerror (const char *s)
{
  fprintf(stderr, "Syntax error at line %d (token: %s)\n", lineno,yytext);
}

/* ===== Parser functions ===== */

int main (void)
{
	// initialize symbol table
//	init_hash_table();

	int result = yyparse();
	if(result==0) printf("\nCORRECT SYNTAX!\n");
	else printf("\nWRONG SYNTAX!\n");

	// symbol table dump
/*	yyout = fopen("symtab_dump.out w");
	symtab_dump(yyout);
	fclose(yyout);	
*/
    return result;
}

char* concat(int n_token, char *token,...)
{
	int i;
	char *concatenated = token;

	va_list vl;
	va_start(vl,token);

	for(i=1; i<n_token; i++)
	{
		concatenated = strcat(strcat(concatenated," "),va_arg(vl,char *));
	}

	va_end(vl);
	return concatenated;
}
