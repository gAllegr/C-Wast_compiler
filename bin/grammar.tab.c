/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/grammar.y" /* yacc.c:339  */

	/* CONTENT TO BE COPIED AT THE BEGINNING */

	/* include directives */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../src/utils.h"
    #include "../src/ast.h"
    #include "../src/list.h"
    #include "../src/symtab.h"

	int yylex();
    void yyerror (const char *s);
    /* Variable needed for debugging */
//	int yydebug = 1;

    AST *ast;                       // Abstract Syntax Tree
    SymTab *symtab;                 // Symbol Table
    int declaration_state = -1;     // used for semantic check on assignment

#line 88 "grammar.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
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
    IFX = 295,
    REV = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "./src/grammar.y" /* yacc.c:355  */

    char *sval;
    List *list;
    AST *node;
    int operator;
    int builtin;
    int value_type;

#line 179 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "grammar.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    87,    95,    96,   103,   151,   178,   195,
     208,   215,   216,   220,   276,   282,   288,   296,   303,   309,
     318,   339,   317,   363,   364,   365,   372,   378,   386,   401,
     402,   402,   402,   406,   412,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   433,   471,   475,   481,   496,   500,
     504,   508,   516,   520,   524,   528,   532,   536,   537,   541,
     545,   549,   553,   557,   561,   562,   566,   573,   577,   584,
     590,   598,   605,   611,   622,   626,   633,   634,   643,   653,
     657,   663,   671,   677,   685,   689,   693,   701,   702,   703,
     704,   711,   715,   720,   773,   798,   802,   806,   813,   817,
     824,   828
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "O_CURLY_BRACES", "C_CURLY_BRACES",
  "O_SQUARE_BRACES", "C_SQUARE_BRACES", "O_ROUND_BRACES", "C_ROUND_BRACES",
  "DOT", "COMMA", "SEMICOLON", "E_COMM", "ASSIGN", "ADD", "SUB", "TIMES",
  "DIVIDE", "INCR", "EQOP", "RELOP", "AND", "OR", "NOT", "IF", "ELSE",
  "FOR", "PRINTF", "SCANF", "IDENTIFIER", "RETURN", "VOID", "INT", "FLOAT",
  "CHAR", "STRUCT", "ICONST", "FCONST", "CCONST", "STRCONST", "IFX", "REV",
  "$accept", "program", "declarations", "declaration", "var_decl",
  "simple_declaration", "struct_declaration", "inizialization_list",
  "functions", "func_definition", "@1", "$@2", "argument_list",
  "parameter_list", "parameter_declaration", "body", "$@3", "$@4",
  "statements", "statement", "func_call", "call_args", "assignment",
  "expr", "increment", "printf_stat", "printed_var", "scanf_stat",
  "retrieved_var", "if_stat", "block", "for_stat", "init_for", "incr_for",
  "return_stat", "var_type", "identifier", "const", "word", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -88

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     235,  -159,  -159,  -159,  -159,   -18,    14,   235,  -159,    17,
     240,  -159,   -18,  -159,   137,  -159,  -159,   240,  -159,  -159,
     -18,    57,  -159,  -159,    84,   235,    33,   -18,   104,   -18,
    -159,    99,    35,    50,   -18,    40,   114,  -159,  -159,   154,
      37,    88,    88,    88,  -159,  -159,  -159,  -159,  -159,   228,
    -159,    89,  -159,  -159,   244,   -18,  -159,  -159,    37,  -159,
    -159,  -159,  -159,    76,  -159,   186,   121,  -159,  -159,    88,
      88,    88,    88,    88,    88,    88,    88,   -18,  -159,    48,
    -159,    77,  -159,   -18,    91,    94,  -159,    37,  -159,   144,
     144,  -159,  -159,   245,   265,   172,   237,    80,   104,   100,
     240,   104,    37,  -159,  -159,   -18,   115,  -159,   125,   104,
     169,  -159,  -159,   127,   134,   149,   183,    23,   205,   235,
     169,  -159,   203,   213,   217,   218,   220,  -159,  -159,   226,
     214,    88,   -18,   207,   216,   104,  -159,  -159,   235,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   196,  -159,   215,   154,
     123,   253,   169,   155,   -18,    88,  -159,   -18,   252,   169,
     169,  -159,   258,  -159,   219,   143,   104,   -18,   161,   146,
     155,    88,  -159,   -18,   104,  -159,   272,  -159,  -159,   228,
     212,   104,   -18,   155,    88,   104,  -159,   228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    87,    88,    89,    90,     0,     0,     0,     4,     0,
       2,    18,    11,    91,     0,     1,     5,     3,     7,    19,
       0,     0,     8,     9,    12,     0,     0,     0,    20,    11,
       6,     0,     0,     0,    11,     0,     0,    94,    10,    12,
       0,     0,     0,     0,   100,   101,    98,    99,    51,    49,
      57,    65,    48,    64,    23,    11,    92,    93,     0,    95,
      96,    97,    15,     0,    14,     0,    65,    56,    62,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    66,    24,
      21,    25,    26,     0,    13,     0,    50,     0,    63,    52,
      53,    54,    55,    58,    59,    60,    61,     0,    46,     0,
       0,    28,     0,    17,    44,     0,     0,    27,    17,    47,
      30,    16,    35,     0,     0,     0,     0,    84,     0,     0,
      29,    33,     0,     0,     0,     0,     0,    41,    42,     0,
       0,     0,    79,     0,     0,    86,    85,    22,    31,    34,
      36,    37,    38,    39,    40,    43,     0,    80,     0,     0,
       0,     0,     0,     0,    79,     0,    67,     0,     0,    32,
       0,    76,    74,    81,     0,     0,    69,     0,     0,     0,
       0,     0,    68,     0,    72,    71,     0,    77,    75,    82,
       0,    70,     0,     0,     0,    73,    78,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,   -20,     6,   -10,  -159,  -159,   -49,   278,    53,
    -159,  -159,  -159,  -159,   187,  -159,  -159,  -159,  -109,  -112,
     255,  -159,   -11,   -39,  -104,  -159,  -159,  -159,  -159,  -159,
    -158,  -159,   135,  -159,  -159,    10,    -5,   171,  -159,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    21,    22,     9,    63,    10,    11,
      32,    99,    80,    81,    82,   118,   119,   152,   120,   121,
     122,    97,   123,    49,    50,   125,   165,   126,   168,   127,
     162,   128,   148,   180,   129,    34,    66,    64,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    23,    65,    67,    68,    33,   124,    24,   139,    85,
      12,    13,   178,    16,    15,    28,   124,    12,    23,    38,
      20,    36,    37,    23,    39,   186,    51,    20,    18,    39,
      89,    90,    91,    92,    93,    94,    95,    96,   103,    16,
      58,   161,    54,   159,    23,    84,    56,   139,   124,   124,
      39,   169,    13,   108,    55,   124,   124,   139,   161,    59,
      60,    61,    13,    19,    83,   124,   124,    29,    30,    35,
      19,   161,    98,    59,    60,    61,    62,   -87,   101,   124,
      86,     1,     2,     3,     4,     5,    87,   100,   104,    26,
     105,   -20,   146,    27,    26,    41,    77,    31,    27,   138,
     109,    29,    40,    42,   102,   130,    41,    78,   106,    26,
      83,    43,   135,    27,    42,   130,   164,    13,   110,    26,
      57,   147,    43,    27,    44,    45,    26,   149,    13,   111,
      27,   156,   179,   157,   131,    44,    45,    46,    47,    78,
      25,   132,    26,   147,    16,   187,    27,   130,   130,   149,
     177,   172,   166,   173,   130,   130,   133,   112,   160,    26,
      71,    72,   174,    27,   130,   130,   112,    31,   181,   175,
     113,   176,   114,   115,   116,    13,   117,   185,   130,   113,
     112,   114,   115,   116,    13,   117,    69,    70,    71,    72,
     134,    73,    74,   113,    88,   114,   115,   116,    13,   117,
      69,    70,    71,    72,   153,    73,    74,    75,    76,   137,
      69,    70,    71,    72,   140,    73,    74,    75,    76,    26,
     183,    77,   184,    27,   141,   154,   155,    31,   142,   143,
     171,   144,    78,    69,    70,    71,    72,   145,    73,    74,
      75,    76,    69,    70,    71,    72,   150,    73,    74,    75,
      76,    69,    70,    71,    72,   151,    73,    74,    75,    69,
      70,    71,    72,   158,   167,    74,     1,     2,     3,     4,
       5,     1,     2,     3,     4,    79,     2,     3,     4,    69,
      70,    71,    72,   170,   182,    17,    48,   107,   136,   163
};

static const yytype_uint8 yycheck[] =
{
       5,    12,    41,    42,    43,    25,   110,    12,   120,    58,
       0,    29,   170,     7,     0,    20,   120,     7,    29,    29,
      10,    26,    27,    34,    29,   183,    31,    17,    11,    34,
      69,    70,    71,    72,    73,    74,    75,    76,    87,    33,
       3,   153,     7,   152,    55,    55,     6,   159,   152,   153,
      55,   160,    29,   102,     4,   159,   160,   169,   170,    36,
      37,    38,    29,    10,    54,   169,   170,    10,    11,    36,
      17,   183,    77,    36,    37,    38,    39,    29,    83,   183,
       4,    31,    32,    33,    34,    35,    10,    10,     8,     5,
      10,     7,   131,     9,     5,     7,     7,    13,     9,   119,
     105,    10,     3,    15,    10,   110,     7,    18,     8,     5,
     100,    23,   117,     9,    15,   120,   155,    29,     3,     5,
       6,   132,    23,     9,    36,    37,     5,   132,    29,     4,
       9,     8,   171,    10,     7,    36,    37,    38,    39,    18,
       3,     7,     5,   154,   138,   184,     9,   152,   153,   154,
       4,     8,   157,    10,   159,   160,     7,    11,     3,     5,
      16,    17,   167,     9,   169,   170,    11,    13,   173,     8,
      24,    10,    26,    27,    28,    29,    30,   182,   183,    24,
      11,    26,    27,    28,    29,    30,    14,    15,    16,    17,
       7,    19,    20,    24,     8,    26,    27,    28,    29,    30,
      14,    15,    16,    17,     8,    19,    20,    21,    22,     4,
      14,    15,    16,    17,    11,    19,    20,    21,    22,     5,
       8,     7,    10,     9,    11,    10,    11,    13,    11,    11,
      11,    11,    18,    14,    15,    16,    17,    11,    19,    20,
      21,    22,    14,    15,    16,    17,    39,    19,    20,    21,
      22,    14,    15,    16,    17,    39,    19,    20,    21,    14,
      15,    16,    17,    10,    12,    20,    31,    32,    33,    34,
      35,    31,    32,    33,    34,    31,    32,    33,    34,    14,
      15,    16,    17,    25,    12,     7,    31,   100,   117,   154
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    43,    44,    45,    48,
      50,    51,    77,    29,    78,     0,    45,    50,    11,    51,
      77,    46,    47,    64,    78,     3,     5,     9,    78,    10,
      11,    13,    52,    44,    77,    36,    78,    78,    46,    78,
       3,     7,    15,    23,    36,    37,    38,    39,    62,    65,
      66,    78,    80,    81,     7,     4,     6,     6,     3,    36,
      37,    38,    39,    49,    79,    65,    78,    65,    65,    14,
      15,    16,    17,    19,    20,    21,    22,     7,    18,    31,
      54,    55,    56,    77,    46,    49,     4,    10,     8,    65,
      65,    65,    65,    65,    65,    65,    65,    63,    78,    53,
      10,    78,    10,    49,     8,    10,     8,    56,    49,    78,
       3,     4,    11,    24,    26,    27,    28,    30,    57,    58,
      60,    61,    62,    64,    66,    67,    69,    71,    73,    76,
      78,     7,     7,     7,     7,    78,    79,     4,    44,    61,
      11,    11,    11,    11,    11,    11,    65,    64,    74,    78,
      39,    39,    59,     8,    10,    11,     8,    10,    10,    60,
       3,    61,    72,    74,    65,    68,    78,    12,    70,    60,
      25,    11,     8,    10,    78,     8,    10,     4,    72,    65,
      75,    78,    12,     8,    10,    78,    72,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    49,    49,    50,    50,
      52,    53,    51,    54,    54,    54,    55,    55,    56,    57,
      58,    59,    57,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    74,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     2,     1,     1,
       3,     0,     1,     6,     1,     1,     5,     3,     1,     2,
       0,     0,    10,     0,     1,     1,     1,     3,     2,     1,
       0,     0,     4,     1,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     4,     0,     1,     3,     3,     3,
       5,     3,     3,     3,     3,     3,     2,     1,     3,     3,
       3,     3,     2,     3,     1,     1,     2,     4,     6,     1,
       3,     6,     2,     4,     5,     7,     1,     3,     9,     0,
       1,     3,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     4,     4,     3,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 83 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root(list_new(), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1430 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root((yyvsp[-1].list), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1439 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.list) = list_merge((yyvsp[-1].list),(yyvsp[0].list));
                }
#line 1447 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "./src/grammar.y" /* yacc.c:1646  */
    {
                    // SEMANTIC CHECK: variable type
                    if((yyvsp[-2].value_type)==T_VOID)
                    {
                        yyerror("Variables cannot have void type");
                        YYABORT;  
                    } 

                    int size = list_length((yyvsp[-1].list)),i,pos,where;
                    AST *obj;
                    // update variable nodes with associated type
                    for(i=0;i<size;i++) {
                        obj = list_get((yyvsp[-1].list),i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                // SEMANTIC CHECK: variable redeclaration
                                check_redeclaration(symtab, obj->ast_variable->sym_variable->name, scope);

                                obj->ast_variable->sym_variable->type = (yyvsp[-2].value_type);
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_variable->sym_variable, scope);
                                break;
                            case N_ASSIGNMENT:
                                // SEMANTIC CHECK: variable redeclaration
                                check_redeclaration(symtab, obj->ast_assign->variable->ast_variable->sym_variable->name, scope);
                                
                                obj->ast_assign->variable->ast_variable->sym_variable->type = (yyvsp[-2].value_type);
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_assign->variable->ast_variable->sym_variable, scope);
                                break;
                        }
                        (yyvsp[-1].list)->items[i] = obj;
                    }

                    // SEMANTIC CHECK: variable content, if it's inizialized
                    for(i=0; i<list_length((yyvsp[-1].list));i++)
                    {
                        obj = list_get((yyvsp[-1].list),i);
                        if(obj->type == N_ASSIGNMENT)
                        {
                            check_decl_assignment(obj, symtab, scope);
                        }
                    }
                    
                    // associate updated list at head of rule
                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1499 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "./src/grammar.y" /* yacc.c:1646  */
    {
                    for(int i=0; i<list_length((yyvsp[-1].list));i++)
                    {
                        AST *obj = list_get((yyvsp[-1].list),i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                // SEMANTIC CHECK: variable redeclaration
                            //    check_redeclaration(symtab, obj->ast_variable->sym_variable->name, scope);

                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_variable->sym_variable, scope);
                                break;
                            case N_ASSIGNMENT:                            
                                // SEMANTIC CHECK: variable redeclaration
                            //    check_redeclaration(symtab, obj->ast_assign->variable->ast_variable->sym_variable->name, scope);
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_assign->variable->ast_variable->sym_variable, scope);
                                break;
                        }
                    }

                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1527 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 179 "./src/grammar.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].node) != NULL)
                {
                    // SEMANTIC CHECK: array variable dimension must be a constant
                    if ((yyvsp[0].node)->ast_variable->sym_variable->n == -2)
                    {
                        yyerror("Array dimension must be a constant");
                        YYABORT;
                    }

                    List *var_list = list_new();
                    list_append(var_list, (yyvsp[0].node));
                    (yyval.list) = var_list;
                }
                else (yyval.list) = NULL;
            }
#line 1548 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 196 "./src/grammar.y" /* yacc.c:1646  */
    {
                // SEMANTIC CHECK: array variable dimension must be a constant
                if ((yyvsp[0].node)->ast_assign->variable->ast_variable->sym_variable->n == -2)
                {
                    yyerror("Array dimension must be a constant");
                    YYABORT;
                }

                List *var_list = list_new();
                list_append(var_list, (yyvsp[0].node));
                (yyval.list) = var_list;
            }
#line 1565 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 209 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 1573 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1579 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 221 "./src/grammar.y" /* yacc.c:1646  */
    {
                        if((yyvsp[0].list) != NULL)
                        {
                            int i,pos,where;
                            AST *a;
                            SymTab_Variables *v;

                            // SEMANTIC CHECK: struct elements cannot be inizialized
                            for(i=0;i<list_length((yyvsp[-2].list));i++)
                            {
                                a = list_get((yyvsp[-2].list),i);
                                if(a->type == N_ASSIGNMENT) 
                                {
                                    yyerror("Struct elements cannot be inizialized");
                                    YYABORT;
                                }
                            }

                            List *elements = convert((yyvsp[-2].list));
                            // delete struct elements from global or local variables in symbol table
                            for(i=0;i<list_length(elements);i++)
                            {
                                v = list_get(elements,i);
                                pos = lookup(symtab, v->name, scope, &where);
                                remove_symtab_variable(symtab, scope, pos);
                            }

                            for(i=0; i<list_length((yyvsp[0].list));i++)
                            {
                                a = list_get((yyvsp[0].list),i);
                                if(a->type == N_VARIABLE)
                                {
                                    int n = a->ast_variable->sym_variable->n;
                                    List *e = prepare_struct_elements(n, elements);

                                    a->ast_variable->sym_variable->s_info = new_struct_info((yyvsp[-4].node)->ast_variable->sym_variable->name, e);
                                    a->ast_variable->sym_variable->type = (yyvsp[-5].value_type);
                                }
                                
                                if(a->type == N_ASSIGNMENT)
                                {
                                    int n = a->ast_assign->variable->ast_variable->sym_variable->n;
                                    List *e = prepare_struct_elements(n, elements);

                                    a->ast_assign->variable->ast_variable->sym_variable->s_info = new_struct_info((yyvsp[-4].node)->ast_variable->sym_variable->name, e);
                                    a->ast_assign->variable->ast_variable->sym_variable->type = (yyvsp[-5].value_type);
                                }
                            }
                        }

                        (yyval.list) = (yyvsp[0].list);
                    }
#line 1636 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 277 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1646 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 283 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, new_AST_Const(3,(yyvsp[0].sval)));
                            (yyval.list) = init_list;
                        }
#line 1656 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 289 "./src/grammar.y" /* yacc.c:1646  */
    {
                            list_merge((yyvsp[-3].list),(yyvsp[-1].list));
                            AST *init = new_AST_List((yyvsp[-3].list));
                            List *array_el = list_new();
                            list_append(array_el,init);
                            (yyval.list) = array_el;
                        }
#line 1668 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 297 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
                        }
#line 1676 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 304 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *func = list_new();
                list_append(func, (yyvsp[0].node));
                (yyval.list) = func;
            }
#line 1686 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 310 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1695 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 318 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].node)->ast_variable->sym_variable->type = (yyvsp[-1].value_type);
                    (yyval.node) = new_AST_Def_Function((yyvsp[0].node));

                    // SEMANTIC CHECK: function name is not already being used by a variable
                    int where, pos = lookup(symtab, (yyvsp[0].node)->ast_variable->sym_variable->name, scope, &where);
                    if(pos != -1)
                    {
                        char error[70];
                        char *function_name = concat(2, " ", "Function name",(yyvsp[0].node)->ast_variable->sym_variable->name);
                        sprintf(error,"%s can't be used, because it's already used somewhere else", strdup(function_name));
                        yyerror(error);
                        YYABORT; 
                    }

                    // Insert declared function in Symbol Table
                    insert_fun(symtab, (yyval.node)->ast_def_function->sym_function);
                    // Update scope
                    scope = (yyval.node)->ast_def_function->sym_function->func_name->name;
                 }
#line 1720 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 339 "./src/grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].node) != NULL) 
                    {
                        List *list_parameters = convert((yyvsp[0].node)->ast_list->list);
                        SymTab_Variables *v;
                        // set all parameters as inizialized
                        for(int i=0; i<list_length(list_parameters);i++)
                        {
                            v = list_get(list_parameters,i);
                            v->inizialized = 1;
                            list_parameters->items[i] = v;
                        }
                        (yyvsp[-2].node)->ast_def_function->sym_function->parameters = list_parameters;
                        update_par(symtab, (yyvsp[-2].node)->ast_def_function->sym_function->parameters, scope);
                    }
                 }
#line 1741 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 356 "./src/grammar.y" /* yacc.c:1646  */
    {
                        (yyvsp[-7].node)->ast_def_function->body = (yyvsp[-1].node);
                        (yyval.node) = (yyvsp[-7].node);
                    }
#line 1750 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 363 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1756 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 364 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1762 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 366 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_List((yyvsp[0].list));
                }
#line 1770 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 373 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *param = list_new();
                    list_append(param, (yyvsp[0].node));
                    (yyval.list) = param;
                }
#line 1780 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 379 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list), (yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1789 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 387 "./src/grammar.y" /* yacc.c:1646  */
    {
                            // SEMANTIC CHECK: paramenters are variables, cannot have void type
                            if((yyvsp[-1].value_type)==T_VOID)
                            {
                                yyerror("Variables cannot have void type");
                                YYABORT;  
                            } 

                            (yyvsp[0].node)->ast_variable->sym_variable->type = (yyvsp[-1].value_type);
                            (yyval.node) = (yyvsp[0].node);
                        }
#line 1805 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 401 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body(list_new(),(yyvsp[0].list)); }
#line 1811 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 402 "./src/grammar.y" /* yacc.c:1646  */
    {declaration_state=1;}
#line 1817 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 402 "./src/grammar.y" /* yacc.c:1646  */
    {declaration_state=-1;}
#line 1823 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 402 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body((yyvsp[-2].list),(yyvsp[0].list)); }
#line 1829 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 407 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *stats = list_new();
                list_append(stats, (yyvsp[0].node));
                (yyval.list) = stats;
            }
#line 1839 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 413 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1848 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 421 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1854 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 434 "./src/grammar.y" /* yacc.c:1646  */
    {
                int i, pos, where;
                AST *node;
                SymTab_Functions *f;
                SymTab_Variables *a, *p;

                // SEMANTIC CHECK: check if function has been defined and if it's really a function
                if(lookup(symtab, (yyvsp[-3].node)->ast_variable->sym_variable->name, scope ,&where) == -1)
                {
                    char error[50];
                    char *function_name = concat(2, " ", "FUNCTION",(yyvsp[-3].node)->ast_variable->sym_variable->name);
                    sprintf(error,"%s has not been defined", strdup(function_name));
                    yyerror(error);
                    YYABORT; 
                }
                else
                {
                    if(where != 3)
                    {
                        char error[50];
                        char *function_name = concat(2, " ", "FUNCTION",(yyvsp[-3].node)->ast_variable->sym_variable->name);
                        sprintf(error,"%s has not been defined as function", strdup(function_name));
                        yyerror(error);
                        YYABORT; 
                    }
                }

                // SEMANTIC CHECK: check matching between arguments and parameters
                check_args_params (symtab, scope, (yyvsp[-3].node)->ast_variable->sym_variable->name, (yyvsp[-1].list));

                (yyval.node) = new_AST_Call_Function ((yyvsp[-3].node),(yyvsp[-1].list));
            }
#line 1891 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 471 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                (yyval.list) = call_arg;
            }
#line 1900 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 476 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                list_append(call_arg, (yyvsp[0].node));
                (yyval.list) = call_arg;
            }
#line 1910 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 482 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 1919 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 497 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1927 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 501 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1935 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 505 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-4].node), new_AST_List((yyvsp[-1].list)));
            }
#line 1943 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 509 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign ((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1951 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 517 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1959 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 521 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1967 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 525 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1975 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 529 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1983 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 533 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 1991 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 538 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1999 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 542 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2007 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 546 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2015 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 550 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2023 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 554 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 2031 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 558 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2039 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 567 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Unary_Expr ((yyvsp[0].operator),(yyvsp[-1].node));
            }
#line 2047 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 574 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-3].builtin), new_AST_Const(T_CHAR,(yyvsp[-1].sval)), list_new());
                }
#line 2055 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 578 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 2063 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 585 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *prin_var = list_new();
                    list_append(prin_var, (yyvsp[0].node));
                    (yyval.list) = prin_var;
                }
#line 2073 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 591 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 2082 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 599 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 2090 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 606 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *retr_var = list_new();
                    list_append(retr_var, (yyvsp[0].node));
                    (yyval.list) = retr_var;
                }
#line 2100 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 612 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-3].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-3].list);
                }
#line 2109 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 623 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-2].node),(yyvsp[0].node),NULL);
            }
#line 2117 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 627 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2125 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 635 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_List((yyvsp[-1].list));
        }
#line 2133 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 644 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_For_Stat((yyvsp[-6].list),(yyvsp[-4].node),(yyvsp[-2].list),(yyvsp[0].node));
            }
#line 2141 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 653 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                (yyval.list) = init_list;
            }
#line 2150 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 658 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                list_append(init_list, (yyvsp[0].node));
                (yyval.list) = init_list;
            }
#line 2160 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 664 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 2168 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 672 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *incr_list = list_new();
                list_append(incr_list, (yyvsp[0].node));
                (yyval.list) = incr_list;
            }
#line 2178 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 678 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 2187 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 686 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Return_Stat(NULL);
                }
#line 2195 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 690 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2203 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 694 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2211 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 712 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Variable((yyvsp[0].sval), -1, T_NULL, NULL, 0);
            }
#line 2219 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 716 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyvsp[-3].node)->ast_variable->sym_variable->n = atoi((yyvsp[-1].sval));
                (yyval.node) = (yyvsp[-3].node);
            }
#line 2228 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 721 "./src/grammar.y" /* yacc.c:1646  */
    {
                // We don't save identifiers' value, so we don't know the array dimension
                (yyvsp[-3].node)->ast_variable->sym_variable->n = -2;

                // SEMANTIC CHECK
                // check that identifier that specify dimension has been declared
                int where, pos = lookup(symtab, (yyvsp[-1].node)->ast_variable->sym_variable->name, scope, &where);
                if(pos == -1)
                {
                    char error[60];
                    sprintf(error, "Variable %s has not been declared",(yyvsp[-1].node)->ast_variable->sym_variable->name);
                    yyerror(error);
                    YYABORT;
                }
                else
                {
                    if(where == 3)
                    {
                        // lookup discover argument has same name of a function
                        char error[80];
                        sprintf(error,"Variable %s has not been declared as variable, but it's a function", (yyvsp[-1].node)->ast_variable->sym_variable->name);
                        yyerror(error);
                        exit(1);  
                    }
                }

                // check that identifier that specify dimension is an int, is not an array and has been inizialized
                SymTab_Variables *a = get_symtab_var(symtab, scope, pos, where);
                if(a->type != T_INT)
                {
                    char error[60];
                    sprintf(error, "Variable %s is not an integer variable",(yyvsp[-1].node)->ast_variable->sym_variable->name);
                    yyerror(error);
                    YYABORT;
                }
                if(a->n != -1)
                {
                    char error[60];
                    sprintf(error, "Variable %s is an array. Must be a simple variable",(yyvsp[-1].node)->ast_variable->sym_variable->name);
                    yyerror(error);
                    YYABORT;
                }
                if(a->inizialized==0)
                {
                    char error[60];
                    sprintf(error, "Variable %s has not been inizialized",(yyvsp[-1].node)->ast_variable->sym_variable->name);
                    yyerror(error);
                    YYABORT;
                }

                (yyval.node) = (yyvsp[-3].node);
            }
#line 2285 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 774 "./src/grammar.y" /* yacc.c:1646  */
    {
                char c[50];
                char *c1,*c2;
                // name+dimension/index of first identifier
                if((yyvsp[-2].node)->ast_variable->sym_variable->n == -1) c1 = (yyvsp[-2].node)->ast_variable->sym_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", (yyvsp[-2].node)->ast_variable->sym_variable->name, (yyvsp[-2].node)->ast_variable->sym_variable->n);
                    c1 = c;
                }
                // name+dimension/index of second identifier
                if((yyvsp[0].node)->ast_variable->sym_variable->n == -1) c2 = (yyvsp[0].node)->ast_variable->sym_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", (yyvsp[0].node)->ast_variable->sym_variable->name, (yyvsp[0].node)->ast_variable->sym_variable->n);
                    c2 = c;
                }
                // concat identifiers and use it as name for AST *var_struct
                c1 = concat(3, "", c1,(yyvsp[-1].sval),c2);
                (yyval.node) = new_AST_Variable (c1, (yyvsp[-2].node)->ast_variable->sym_variable->n, T_STRUCT, NULL, 0);
            }
#line 2311 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 799 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2319 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 803 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2327 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 807 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2335 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 814 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2343 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 818 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2351 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 825 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2359 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 829 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2367 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 2371 "grammar.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 834 "./src/grammar.y" /* yacc.c:1906  */

void yyerror (const char *s)
{
    extern int yylineno;
	fprintf(stderr, "Error: %s\nLine: %d\n", s, yylineno);
}

int main (void)
{
	// initialize symbol table
    symtab = init_symtab();
    scope = "GLOBAL";

	int result = yyparse();
	if(result==0)
    {
        printf("\nCORRECT SYNTAX! \\^.^/ \n");
        printf("\n\nNow I'll print the abstract syntax tree!\n\n");
        print_ast(ast,0); printf("\n");

        printf("\n\nNow I'll print the symbol table!\n\n");
        print_symtab(symtab);

        /* other stuff (code_gen) */

        printf("Now I'll free memory occupied by abstract syntax tree!\n");
        free_ast(ast);
        printf("Memory is free!\n\n");
    }
	else printf("\nWRONG SYNTAX! ç.ç\n");

    return result;
}
