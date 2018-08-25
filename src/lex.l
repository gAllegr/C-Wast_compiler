/* because I got this error: undefined reference to 'yywrap'
The scanner calls this function on end of file, so you can point it to another file and continue scanning its contents. If you don't need this, use
Although disabling yywrap is certainly the best option, it may also be possible to link with -lfl to use the default yywrap() function in the library fl (i.e. libfl.a) provided by flex. Posix requires that library to be available with the linker flag -ll and the default OS X install only provides that name.
*/
%option noyywrap

%{
	/* PRE-PROCESSOR SECTION */

	#define YYSTYPE char*

	/* Everything listed here will be copied */
	#include "grammar.tab.h"
	#include <stdlib.h>
	#include <string.h>

	/* prints grammar violation message */
	void yyerror(const char *);

	/* variable counting lines */
	int lineno = 1;

	static inline void print_token() { printf("%s ", yytext); }
	static inline void value_token() { yylval = yytext; }
%}


/* TOKEN DEFINITION BY USING REGULAR EXPRESSION */
/* comment state definition */
%x comm
%x line_comm
/* whitespaces */
delim			[ \t]
ws 				{delim}+
/* numbers */
digit 			[0-9]
exp 			([Ee][+-]?{digit}*)
/* alphabetics */
alpha			[a-zA-z]
underscore		[_]
char			\".\"
string			\"(\\.|[^"\\])*\"
header			#include{ws}<{alpha}*(\.{alpha}*)?>
id				{alpha}({alpha}|{digit}|{underscore})*


/* LIST OF TOKENS AND ACTIONS */
%%
"/*" 						BEGIN(comm);
<comm>[^*/\n]* 				/* if not a '*' or new line, discard everything */
<comm>"*"+[^*/\n]* 			/* discard '*' not warning for comment end and all next characters */
<comm>\n 					{lineno += 1;} /* discard new lines */
<comm>"*"+"/" 				BEGIN(INITIAL);

"//"						BEGIN(line_comm);
<line_comm>[^/\n]* 			/* if not a new line, discard everything */
<line_comm>\n				{lineno += 1; BEGIN(INITIAL);}

"{"							{print_token(); value_token(); return O_CURLY_BRACES;}
"}"							{print_token(); value_token(); return C_CURLY_BRACES;}
"["							{print_token(); value_token(); return O_SQUARE_BRACES;}
"]"							{print_token(); value_token(); return C_SQUARE_BRACES;}
"("							{print_token(); value_token(); return O_ROUND_BRACES;}
")"							{print_token(); value_token(); return C_ROUND_BRACES;}

"."							{print_token(); value_token(); return DOT;}
","							{print_token(); value_token(); return COMMA;}
";"							{print_token(); value_token(); return SEMICOLON;}
"&"							{print_token(); value_token(); return E_COMM;}

"="							{print_token(); value_token(); return ASSIGN;}

"++"						{print_token(); value_token(); return INCR;}
"--"						{print_token(); value_token(); return INCR;}

"+"							{print_token(); value_token(); return ADD;}
"-"							{print_token(); value_token(); return SUB;}
"*"							{print_token(); value_token(); return TIMES;}
"/"							{print_token(); value_token(); return DIVIDE;}

"=="						{print_token(); value_token(); return EQOP;}
"!="						{print_token(); value_token(); return EQOP;}
"<"							{print_token(); value_token(); return RELOP;}
"<="						{print_token(); value_token(); return RELOP;}
">"							{print_token(); value_token(); return RELOP;}
">="						{print_token(); value_token(); return RELOP;}

"&&"						{print_token(); value_token(); return AND;}
"||"						{print_token(); value_token(); return OR;}
"!"							{print_token(); value_token(); return NOT;}

"char"						{print_token(); value_token(); return CHAR;}
"else"						{print_token(); value_token(); return ELSE;}
"float"						{print_token(); value_token(); return FLOAT;}
"for"						{print_token(); value_token(); return FOR;}
"if"						{print_token(); value_token(); return IF;}
"int"						{print_token(); value_token(); return INT;}
"printf"					{print_token(); value_token(); return PRINTF;}
"return"					{print_token(); value_token(); return RETURN;}
"scanf"						{print_token(); value_token(); return SCANF;}
"struct"					{print_token(); value_token(); return STRUCT;}
"void"						{print_token(); value_token(); return VOID;}

{ws}						{/* ignore it */}
"\n"						{print_token(); lineno += 1;}

{header}					{/* ignore it */}
{id}						{print_token(); value_token(); return IDENTIFIER;}

{digit}+					{print_token(); value_token(); return ICONST;}
{digit}+\.{digit}+			{print_token(); value_token(); return FCONST;}
{digit}+(\.{digit}+)?{exp}	{print_token(); value_token(); return FCONST;}
{char}						{print_token(); value_token(); return CCONST;}
{string}					{print_token(); value_token(); return STRCONST;}

.               			{yyerror("Unrecognized character");}

%%

void yyerror (const char *s)
{
  fprintf(stderr, "Syntax error at line %d (token: %s)\n", lineno,yytext);
}