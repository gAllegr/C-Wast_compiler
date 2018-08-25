/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    O_CURLY_BRACES = 258,
    C_CURLY_BRACES = 259,
    O_SQUARE_BRACES = 260,
    C_SQUARE_BRACES = 261,
    O_ROUND_BRACES = 262,
    C_ROUND_BRACES = 263,
    DOT = 264,
    COMMA = 265,
    SEMICOLON = 266,
    E_COMM = 267,
    ASSIGN = 268,
    ADD = 269,
    SUB = 270,
    TIMES = 271,
    DIVIDE = 272,
    INCR = 273,
    EQOP = 274,
    RELOP = 275,
    AND = 276,
    OR = 277,
    NOT = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    PRINTF = 282,
    SCANF = 283,
    IDENTIFIER = 284,
    RETURN = 285,
    VOID = 286,
    INT = 287,
    FLOAT = 288,
    CHAR = 289,
    STRUCT = 290,
    ICONST = 291,
    FCONST = 292,
    CCONST = 293,
    STRCONST = 294,
    REV = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
