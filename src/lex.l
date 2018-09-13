/* because I got this error: undefined reference to 'yywrap'
The scanner calls this function on end of file, so you can point it to another file and continue scanning its contents. If you don't need this, use
Although disabling yywrap is certainly the best option, it may also be possible to link with -lfl to use the default yywrap() function in the library fl (i.e. libfl.a) provided by flex. Posix requires that library to be available with the linker flag -ll and the default OS X install only provides that name.
*/
%option noyywrap

%{
	/* PRE-PROCESSOR SECTION */
	/* Everything listed here will be copied */
	#include <stdlib.h>
	#include <string.h>
	#include "../src/utils.h"
    #include "../src/ast.h"
    #include "../src/list.h"
	#include "grammar.tab.h"

	extern void yyerror (const char *s);
	static inline void value_token() { yylval.sval = strdup(yytext); }
%}

%option yylineno

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
alpha			[a-zA-Z]
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
<comm>\n 					/* discard new lines */
<comm>"*"+"/" 				BEGIN(INITIAL);

"//"						BEGIN(line_comm);
<line_comm>[^/\n]* 			/* if not a new line, discard everything */
<line_comm>\n				{BEGIN(INITIAL);}

"{"							{value_token(); return O_CURLY_BRACES;}
"}"							{value_token(); return C_CURLY_BRACES;}
"["							{value_token(); return O_SQUARE_BRACES;}
"]"							{value_token(); return C_SQUARE_BRACES;}
"("							{value_token(); return O_ROUND_BRACES;}
")"							{value_token(); return C_ROUND_BRACES;}

"."							{value_token(); return DOT;}
","							{value_token(); return COMMA;}
";"							{value_token(); return SEMICOLON;}
"&"							{value_token(); return E_COMM;}

"="							{value_token(); return ASSIGN;}

"++"						{yylval.operator = U_INC; return INCR;}
"--"						{yylval.operator = U_DEC; return INCR;}

"+"							{yylval.operator = B_ADD; return ADD;}
"-"							{yylval.operator = B_SUB; return SUB;}
"*"							{yylval.operator = B_MUL; return TIMES;}
"/"							{yylval.operator = B_DIV; return DIVIDE;}

"=="						{yylval.operator = B_EQ; return EQOP;}
"!="						{yylval.operator = B_NE; return EQOP;}
"<"							{yylval.operator = B_LT; return RELOP;}
"<="						{yylval.operator = B_LE; return RELOP;}
">"							{yylval.operator = B_GT; return RELOP;}
">="						{yylval.operator = B_GE; return RELOP;}

"&&"						{yylval.operator = B_AND; return AND;}
"||"						{yylval.operator = B_OR; return OR;}
"!"							{yylval.operator = U_NOT; return NOT;}

"char"						{yylval.value_type = T_CHAR; return CHAR;}
"else"						{value_token(); return ELSE;}
"float"						{yylval.value_type = T_FLOAT; return FLOAT;}
"for"						{value_token(); return FOR;}
"if"						{value_token(); return IF;}
"int"						{yylval.value_type = T_INT; return INT;}
"printf"					{yylval.builtin = F_PRINTF; return PRINTF;}
"return"					{value_token(); return RETURN;}
"scanf"						{yylval.builtin = F_SCANF; return SCANF;}
"struct"					{yylval.value_type = T_STRUCT; return STRUCT;}
"void"						{yylval.value_type = T_VOID; return VOID;}

{ws}						{/* ignore it */}
"\n"						{/* ignore it */}

{header}					{/* ignore it */}
{id}						{value_token(); return IDENTIFIER;}

{digit}+					{value_token(); return ICONST;}
{digit}+\.{digit}+			{value_token(); return FCONST;}
{digit}+(\.{digit}+)?{exp}	{value_token(); return FCONST;}
{char}						{value_token(); return CCONST;}
{string}					{value_token(); return STRCONST;}

.               			{yyerror("Unrecognized character");}

%%
