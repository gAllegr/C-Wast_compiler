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
    #include <libgen.h>
	#include "../src/utils.h"
    #include "../src/ast.h"
    #include "../src/list.h"
    #include "../src/symtab.h"
    #include "../src/wat.h"

	int yylex();
    void yyerror (const char *s);
    /* Variable needed for debugging */
//	int yydebug = 1;

    extern FILE *yyin;
    AST *ast;                       // Abstract Syntax Tree
    SymTab *symtab;                 // Symbol Table

#line 90 "grammar.tab.c" /* yacc.c:339  */

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
#line 27 "./src/grammar.y" /* yacc.c:355  */

    char *sval;
    List *list;
    AST *node;
    int operator;
    int builtin;
    int value_type;

#line 181 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "grammar.tab.c" /* yacc.c:358  */

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
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
       0,    84,    84,    89,    97,    98,   105,   170,   228,   245,
     258,   265,   266,   270,   326,   332,   338,   346,   353,   359,
     368,   389,   367,   414,   415,   416,   423,   429,   437,   452,
     453,   457,   463,   472,   473,   474,   492,   497,   498,   499,
     504,   505,   509,   547,   551,   557,   572,   576,   580,   584,
     592,   596,   600,   604,   608,   612,   613,   617,   621,   625,
     629,   633,   637,   638,   642,   649,   653,   660,   669,   680,
     687,   697,   712,   716,   723,   724,   733,   742,   761,   784,
     791,   800,   804,   808,   818,   819,   820,   821,   828,   832,
     837,   890,   915,   919,   923,   930,   934,   941,   945
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
  "parameter_list", "parameter_declaration", "body", "statements",
  "statement", "func_call", "call_args", "assignment", "expr", "increment",
  "printf_stat", "printed_var", "scanf_stat", "retrieved_var", "if_stat",
  "block", "for_stat", "init_for", "incr_for", "return_stat", "var_type",
  "identifier", "const", "word", "number", YY_NULLPTR
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

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,  -111,  -111,  -111,  -111,   -21,    25,   180,  -111,    17,
     257,  -111,   -21,  -111,    92,  -111,  -111,   257,  -111,  -111,
     -21,   226,  -111,  -111,   121,   180,    33,   -21,   102,   -21,
    -111,    38,    36,    48,   -21,    53,   190,  -111,  -111,   251,
      27,    81,    81,    81,  -111,  -111,  -111,  -111,  -111,   233,
    -111,    42,  -111,  -111,   261,   -21,  -111,  -111,    27,  -111,
    -111,  -111,  -111,   119,  -111,   202,    85,  -111,  -111,    81,
      81,    81,    81,    81,    81,    81,    81,   -21,  -111,    19,
    -111,    74,  -111,   -21,    89,    99,  -111,    27,  -111,     0,
       0,  -111,  -111,   267,   282,   260,   252,    60,   102,   106,
     257,   102,    27,  -111,  -111,   -21,   116,  -111,   118,   102,
     174,  -111,  -111,   170,   172,   179,   181,   135,   174,   193,
     109,  -111,   147,   183,   214,   219,   231,  -111,  -111,   240,
     136,    81,   -21,   220,   222,   102,  -111,   109,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,   212,  -111,   247,   251,
      79,   253,   154,   -21,    81,  -111,   -21,   250,   109,  -111,
     245,  -111,   224,   142,   102,   -21,   151,   163,   154,    81,
    -111,   -21,   102,  -111,   266,  -111,  -111,   233,   160,   102,
     -21,   154,    81,   102,  -111,   233
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    84,    85,    86,    87,     0,     0,     0,     4,     0,
       2,    18,    11,    88,     0,     1,     5,     3,     7,    19,
       0,     0,     8,     9,    12,     0,     0,     0,    20,    11,
       6,     0,     0,     0,    11,     0,     0,    91,    10,    12,
       0,     0,     0,     0,    97,    98,    95,    96,    49,    47,
      55,    63,    46,    62,    23,    11,    89,    90,     0,    92,
      93,    94,    15,     0,    14,     0,    63,    54,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    64,    24,
      21,    25,    26,     0,    13,     0,    48,     0,    61,    50,
      51,    52,    53,    56,    57,    58,    59,     0,    44,     0,
       0,    28,     0,    17,    42,     0,     0,    27,    17,    45,
       0,    16,    33,     0,     0,     0,     0,    81,     0,     0,
      29,    31,     0,     0,     0,     0,     0,    39,    40,     0,
       0,     0,     0,     0,     0,    83,    82,    30,    22,    32,
      34,    35,    36,    37,    38,    41,     0,    77,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    74,
      72,    78,     0,     0,    67,     0,     0,     0,     0,     0,
      66,     0,    70,    69,     0,    75,    73,    79,     0,    68,
       0,     0,     0,    71,    76,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   -19,     6,    -9,  -111,  -111,   -47,   258,    75,
    -111,  -111,  -111,  -111,   185,  -111,  -104,  -110,   255,  -111,
     -11,   -38,   -12,  -111,  -111,  -111,  -111,  -111,   -95,  -111,
    -111,  -111,  -111,     2,    -5,   184,  -111,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    21,    22,     9,    63,    10,    11,
      32,    99,    80,    81,    82,   119,   120,   121,   122,    97,
     123,    49,    50,   125,   163,   126,   166,   127,   160,   128,
     148,   178,   129,    34,    66,    64,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    23,    12,    65,    67,    68,    33,    24,    13,    12,
     139,    85,    20,    16,   137,    28,    71,    72,    23,    20,
      38,    36,    37,    23,    39,    15,    51,   139,    18,    39,
      58,    89,    90,    91,    92,    93,    94,    95,    96,    16,
     103,    40,   159,    54,    23,    41,    84,    26,   -84,    77,
      39,    27,    55,    42,   167,   108,    83,   139,   159,    56,
      78,    43,    13,    59,    60,    61,    62,    13,   104,    35,
     105,   159,    98,   176,    44,    45,    46,    47,   101,     1,
       2,     3,     4,     5,   100,    19,   184,   155,    41,   156,
      26,   118,    19,   146,    27,    25,    42,    26,   124,    29,
     109,    27,    83,    78,    43,   130,   124,    26,   124,   102,
      13,    27,   135,   130,   106,   130,   162,    44,    45,   110,
     112,   147,   111,    86,    16,   124,    26,   149,   -20,    87,
      27,   177,   130,   113,    31,   114,   115,   116,    13,   117,
     124,    26,   161,    77,   185,    27,   124,   130,   149,    31,
     170,   164,   171,   130,    78,   124,   124,   158,   140,   173,
     172,   174,   130,   130,    13,   112,   179,   175,   181,   124,
     182,    59,    60,    61,   112,   183,   130,   131,   113,   132,
     114,   115,   116,    13,   117,   112,   133,   113,   134,   114,
     115,   116,    13,   117,   141,    26,    57,   138,   113,    27,
     114,   115,   116,    13,   117,     1,     2,     3,     4,     5,
      88,     1,     2,     3,     4,     5,    69,    70,    71,    72,
     152,    73,    74,    75,    76,   142,    69,    70,    71,    72,
     143,    73,    74,    75,    76,   169,    29,    30,    69,    70,
      71,    72,   144,    73,    74,    75,    76,    69,    70,    71,
      72,   145,    73,    74,    75,    76,    26,   153,   154,   150,
      27,   151,   165,   157,    31,    17,    69,    70,    71,    72,
     168,    73,    74,    75,    69,    70,    71,    72,   180,    73,
      74,    69,    70,    71,    72,   107,    48,    74,     1,     2,
       3,     4,    79,     2,     3,     4,    69,    70,    71,    72,
       0,   136
};

static const yytype_int16 yycheck[] =
{
       5,    12,     0,    41,    42,    43,    25,    12,    29,     7,
     120,    58,    10,     7,   118,    20,    16,    17,    29,    17,
      29,    26,    27,    34,    29,     0,    31,   137,    11,    34,
       3,    69,    70,    71,    72,    73,    74,    75,    76,    33,
      87,     3,   152,     7,    55,     7,    55,     5,    29,     7,
      55,     9,     4,    15,   158,   102,    54,   167,   168,     6,
      18,    23,    29,    36,    37,    38,    39,    29,     8,    36,
      10,   181,    77,   168,    36,    37,    38,    39,    83,    31,
      32,    33,    34,    35,    10,    10,   181,     8,     7,    10,
       5,   110,    17,   131,     9,     3,    15,     5,   110,    10,
     105,     9,   100,    18,    23,   110,   118,     5,   120,    10,
      29,     9,   117,   118,     8,   120,   154,    36,    37,     3,
      11,   132,     4,     4,   118,   137,     5,   132,     7,    10,
       9,   169,   137,    24,    13,    26,    27,    28,    29,    30,
     152,     5,   153,     7,   182,     9,   158,   152,   153,    13,
       8,   156,    10,   158,    18,   167,   168,     3,    11,     8,
     165,    10,   167,   168,    29,    11,   171,     4,     8,   181,
      10,    36,    37,    38,    11,   180,   181,     7,    24,     7,
      26,    27,    28,    29,    30,    11,     7,    24,     7,    26,
      27,    28,    29,    30,    11,     5,     6,     4,    24,     9,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       8,    31,    32,    33,    34,    35,    14,    15,    16,    17,
       8,    19,    20,    21,    22,    11,    14,    15,    16,    17,
      11,    19,    20,    21,    22,    11,    10,    11,    14,    15,
      16,    17,    11,    19,    20,    21,    22,    14,    15,    16,
      17,    11,    19,    20,    21,    22,     5,    10,    11,    39,
       9,    39,    12,    10,    13,     7,    14,    15,    16,    17,
      25,    19,    20,    21,    14,    15,    16,    17,    12,    19,
      20,    14,    15,    16,    17,   100,    31,    20,    31,    32,
      33,    34,    31,    32,    33,    34,    14,    15,    16,    17,
      -1,   117
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    43,    44,    45,    48,
      50,    51,    75,    29,    76,     0,    45,    50,    11,    51,
      75,    46,    47,    62,    76,     3,     5,     9,    76,    10,
      11,    13,    52,    44,    75,    36,    76,    76,    46,    76,
       3,     7,    15,    23,    36,    37,    38,    39,    60,    63,
      64,    76,    78,    79,     7,     4,     6,     6,     3,    36,
      37,    38,    39,    49,    77,    63,    76,    63,    63,    14,
      15,    16,    17,    19,    20,    21,    22,     7,    18,    31,
      54,    55,    56,    75,    46,    49,     4,    10,     8,    63,
      63,    63,    63,    63,    63,    63,    63,    61,    76,    53,
      10,    76,    10,    49,     8,    10,     8,    56,    49,    76,
       3,     4,    11,    24,    26,    27,    28,    30,    44,    57,
      58,    59,    60,    62,    64,    65,    67,    69,    71,    74,
      76,     7,     7,     7,     7,    76,    77,    58,     4,    59,
      11,    11,    11,    11,    11,    11,    63,    62,    72,    76,
      39,    39,     8,    10,    11,     8,    10,    10,     3,    59,
      70,    62,    63,    66,    76,    12,    68,    58,    25,    11,
       8,    10,    76,     8,    10,     4,    70,    63,    73,    76,
      12,     8,    10,    76,    70,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    49,    49,    50,    50,
      52,    53,    51,    54,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    72,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     2,     1,     1,
       3,     0,     1,     6,     1,     1,     5,     3,     1,     2,
       0,     0,    10,     0,     1,     1,     1,     3,     2,     1,
       2,     1,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     2,     4,     0,     1,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       2,     3,     1,     1,     2,     4,     6,     1,     3,     6,
       2,     4,     5,     7,     1,     3,     9,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     4,
       4,     3,     1,     1,     1,     1,     1,     1,     1
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
#line 85 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root(list_new(), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1433 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root((yyvsp[-1].list), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1442 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.list) = list_merge((yyvsp[-1].list),(yyvsp[0].list));
                }
#line 1450 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "./src/grammar.y" /* yacc.c:1646  */
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
                            // retrieve var_assign from symbol table
                            int where, pos = lookup(symtab, obj->ast_assign->variable->ast_variable->sym_variable->name, scope, &where);
                            SymTab_Variables *var_assign = get_symtab_var(symtab, scope, pos, where);
                            AST *expression = obj->ast_assign->expression;

                            int init = check_decl_assignment(var_assign, expression, symtab, scope);
                            if(init == 1)                   // types are the same
                            {
                                // update Symbol Table
	                            update_inizialization(symtab, var_assign->name, scope);
                            }
                            else                            // type mismatch
                            {
                                char error[80];
                                sprintf(error,"Mismatch type between inizialized variable %s and expression", var_assign->name);
                                yyerror(error);
                                exit(1); 
                            }
                        }
                    }
                    
                    // associate updated list at head of rule
                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1519 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 171 "./src/grammar.y" /* yacc.c:1646  */
    {
                    int i;
                    AST *obj;

                    for(i=0; i<list_length((yyvsp[-1].list));i++)
                    {
                        obj = list_get((yyvsp[-1].list),i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                // SEMANTIC CHECK: variable redeclaration
                                check_redeclaration(symtab, obj->ast_variable->sym_variable->name, scope);

                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_variable->sym_variable, scope);
                                break;
                            case N_ASSIGNMENT:                            
                                // SEMANTIC CHECK: variable redeclaration
                                check_redeclaration(symtab, obj->ast_assign->variable->ast_variable->sym_variable->name, scope);

                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_assign->variable->ast_variable->sym_variable, scope);
                                break;
                        }
                    }

                    // SEMANTIC CHECK: variable content, if it's inizialized
                    for(i=0; i<list_length((yyvsp[-1].list));i++)
                    {
                        obj = list_get((yyvsp[-1].list),i);
                        if(obj->type == N_ASSIGNMENT)
                        {
                            // retrieve var_assign from symbol table
                            int where, pos = lookup(symtab, obj->ast_assign->variable->ast_variable->sym_variable->name, scope, &where);
                            SymTab_Variables *var_assign = get_symtab_var(symtab, scope, pos, where);
                            AST *expression = obj->ast_assign->expression;

                            int init = check_decl_assignment(var_assign, expression, symtab, scope);
                            if(init == 1)                   // types are the same
                            {
                                // update Symbol Table
	                            update_inizialization(symtab, var_assign->name, scope);
                            }
                            else                            // type mismatch
                            {
                                char error[80];
                                sprintf(error,"Mismatch type between inizialized variable %s and expression", var_assign->name);
                                yyerror(error);
                                exit(1); 
                            }
                        }
                    }

                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1578 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 229 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1599 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 246 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1616 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 259 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 1624 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 265 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1630 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 271 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1687 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 327 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1697 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 333 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, new_AST_Const(3,(yyvsp[0].sval)));
                            (yyval.list) = init_list;
                        }
#line 1707 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 339 "./src/grammar.y" /* yacc.c:1646  */
    {
                            list_merge((yyvsp[-3].list),(yyvsp[-1].list));
                            AST *init = new_AST_List((yyvsp[-3].list));
                            List *array_el = list_new();
                            list_append(array_el,init);
                            (yyval.list) = array_el;
                        }
#line 1719 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 347 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
                        }
#line 1727 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 354 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *func = list_new();
                list_append(func, (yyvsp[0].node));
                (yyval.list) = func;
            }
#line 1737 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 360 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1746 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 368 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1771 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 389 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1792 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 406 "./src/grammar.y" /* yacc.c:1646  */
    {
                        check_return((yyvsp[-9].value_type),(yyvsp[-1].node),symtab,scope);
                        (yyvsp[-7].node)->ast_def_function->body = (yyvsp[-1].node);
                        (yyval.node) = (yyvsp[-7].node);
                    }
#line 1802 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 414 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1808 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 415 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1814 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 417 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_List((yyvsp[0].list));
                }
#line 1822 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 424 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *param = list_new();
                    list_append(param, (yyvsp[0].node));
                    (yyval.list) = param;
                }
#line 1832 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 430 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list), (yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1841 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 438 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1857 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 452 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body(list_new(),(yyvsp[0].list)); }
#line 1863 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 453 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body((yyvsp[-1].list),(yyvsp[0].list)); }
#line 1869 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 458 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *stats = list_new();
                list_append(stats, (yyvsp[0].node));
                (yyval.list) = stats;
            }
#line 1879 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 464 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1888 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 472 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1894 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 475 "./src/grammar.y" /* yacc.c:1646  */
    {
                    int init = check_assignment((yyvsp[-1].node), symtab, scope);
                    if(init == 1)
                    {
                        // update Symbol Table
                        update_inizialization(symtab, (yyvsp[-1].node)->ast_assign->variable->ast_variable->sym_variable->name, scope);
                    }
                    else                            // type mismatch
                    {
                        char error[80];
                        sprintf(error,"Mismatch type between inizialized variable %s and expression", (yyval.node)->ast_assign->variable->ast_variable->sym_variable->name);
                        yyerror(error);
                        exit(1); 
                    }

                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1916 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 493 "./src/grammar.y" /* yacc.c:1646  */
    {
                    evaluate_expression_type((yyvsp[-1].node), symtab, scope);
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1925 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 500 "./src/grammar.y" /* yacc.c:1646  */
    {
                    evaluate_expression_type((yyvsp[0].node)->ast_if_stat->condition, symtab, scope);
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1934 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 510 "./src/grammar.y" /* yacc.c:1646  */
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
#line 1971 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 547 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                (yyval.list) = call_arg;
            }
#line 1980 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 552 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                list_append(call_arg, (yyvsp[0].node));
                (yyval.list) = call_arg;
            }
#line 1990 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 558 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 1999 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 573 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2007 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 577 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2015 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 581 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-4].node), new_AST_List((yyvsp[-1].list)));
            }
#line 2023 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 585 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign ((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2031 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 593 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2039 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 597 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2047 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 601 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2055 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 605 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2063 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 609 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr (U_REV,(yyvsp[0].node));
        }
#line 2071 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 614 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2079 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 618 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2087 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 622 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2095 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 626 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2103 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 630 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 2111 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 634 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2119 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 643 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Unary_Expr ((yyvsp[0].operator),(yyvsp[-1].node));
            }
#line 2127 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 650 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-3].builtin), new_AST_Const(T_CHAR,(yyvsp[-1].sval)), list_new());
                }
#line 2135 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 654 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 2143 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 661 "./src/grammar.y" /* yacc.c:1646  */
    {
                    // check if variable has been declared
                    is_var_declared ((yyvsp[0].node), symtab, scope);

                    List *prin_var = list_new();
                    list_append(prin_var, (yyvsp[0].node));
                    (yyval.list) = prin_var;
                }
#line 2156 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 670 "./src/grammar.y" /* yacc.c:1646  */
    {
                    // check if variable has been declared
                    is_var_declared ((yyvsp[0].node), symtab, scope);

                    list_append((yyvsp[-2].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 2168 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 681 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 2176 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 688 "./src/grammar.y" /* yacc.c:1646  */
    {
                    // check if variable has been declared and update inizialization flag
                    is_var_declared ((yyvsp[0].node), symtab, scope);
                    update_inizialization(symtab, (yyvsp[0].node)->ast_variable->sym_variable->name, scope);

                    List *retr_var = list_new();
                    list_append(retr_var, (yyvsp[0].node));
                    (yyval.list) = retr_var;
                }
#line 2190 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 698 "./src/grammar.y" /* yacc.c:1646  */
    {
                    // check if variable has been declared and update inizialization flag
                    is_var_declared ((yyvsp[0].node), symtab, scope);
                    update_inizialization(symtab, (yyvsp[0].node)->ast_variable->sym_variable->name, scope);

                    list_append((yyvsp[-3].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-3].list);
                }
#line 2203 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 713 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-2].node),(yyvsp[0].node),NULL);
            }
#line 2211 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 717 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2219 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 725 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_List((yyvsp[-1].list));
        }
#line 2227 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 734 "./src/grammar.y" /* yacc.c:1646  */
    {
                evaluate_expression_type((yyvsp[-4].node), symtab, scope);
                (yyval.node) = new_AST_For_Stat((yyvsp[-6].list),(yyvsp[-4].node),(yyvsp[-2].list),(yyvsp[0].node));
            }
#line 2236 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 743 "./src/grammar.y" /* yacc.c:1646  */
    {
                int init = check_assignment((yyvsp[0].node), symtab, scope);
                if(init == 1)                   // types are the same
                {
                    // update Symbol Table
                    update_inizialization(symtab, (yyvsp[0].node)->ast_assign->variable->ast_variable->sym_variable->name, scope);
                }
                else                            // type mismatch
                {
                    char error[80];
                    sprintf(error,"Mismatch type between inizialized variable %s and expression", (yyvsp[0].node)->ast_assign->variable->ast_variable->sym_variable->name);
                    yyerror(error);
                    exit(1); 
                }
                List *init_list = list_new();
                list_append(init_list, (yyvsp[0].node));
                (yyval.list) = init_list;
            }
#line 2259 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 762 "./src/grammar.y" /* yacc.c:1646  */
    {
                int init = check_assignment((yyvsp[0].node), symtab, scope);
                if(init == 1)                   // types are the same
                {
                    // update Symbol Table
                    update_inizialization(symtab, (yyvsp[0].node)->ast_assign->variable->ast_variable->sym_variable->name, scope);
                }
                else                            // type mismatch
                {
                    char error[80];
                    sprintf(error,"Mismatch type between inizialized variable %s and expression", (yyvsp[0].node)->ast_assign->variable->ast_variable->sym_variable->name);
                    yyerror(error);
                    exit(1); 
                }

                list_append((yyvsp[-2].list),(yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 2282 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 785 "./src/grammar.y" /* yacc.c:1646  */
    {
                evaluate_expression_type((yyvsp[0].node), symtab, scope);
                List *incr_list = list_new();
                list_append(incr_list, (yyvsp[0].node));
                (yyval.list) = incr_list;
            }
#line 2293 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 792 "./src/grammar.y" /* yacc.c:1646  */
    {
                evaluate_expression_type((yyvsp[0].node), symtab, scope);
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 2303 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 801 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Return_Stat(NULL);
                }
#line 2311 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 805 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2319 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 809 "./src/grammar.y" /* yacc.c:1646  */
    {
                   is_var_declared ((yyvsp[0].node), symtab, scope);
                   verify_return_id_type ((yyvsp[0].node), symtab, scope);
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2329 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 829 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Variable((yyvsp[0].sval), -1, T_NULL, NULL, 0);
            }
#line 2337 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 833 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyvsp[-3].node)->ast_variable->sym_variable->n = atoi((yyvsp[-1].sval));
                (yyval.node) = (yyvsp[-3].node); 
            }
#line 2346 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 838 "./src/grammar.y" /* yacc.c:1646  */
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
#line 2403 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 891 "./src/grammar.y" /* yacc.c:1646  */
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
                c1 = strdup(concat(3, "", c1,(yyvsp[-1].sval),c2));
                (yyval.node) = new_AST_Variable(c1, (yyvsp[-2].node)->ast_variable->sym_variable->n, T_STRUCT, NULL, 0);
            }
#line 2429 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 916 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2437 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 920 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2445 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 924 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2453 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 931 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2461 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 935 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2469 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 942 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2477 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 946 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2485 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 2489 "grammar.tab.c" /* yacc.c:1646  */
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
#line 951 "./src/grammar.y" /* yacc.c:1906  */

void yyerror (const char *s)
{
    extern int yylineno;
	fprintf(stderr, "Error: %s\nLine: %d\n", s, yylineno);
}

int main (int argc, char *argv[])
{
	// initialize symbol table
    symtab = init_symtab();
    scope = "GLOBAL";

    yyin = fopen(argv[1],"r");
    char *filename = strtok(basename(argv[1]),".");

	int result = yyparse();
    fclose(yyin);

	if(result==0)
    {
        printf("\nCORRECT SYNTAX! \\^.^/ \n");
        printf("\n\nNow I'll print the abstract syntax tree!\n\n");
        print_ast(ast,0); printf("\n");

        printf("\n\nNow I'll print the symbol table!\n\n");
        print_symtab(symtab);

        code_generation(ast, symtab, filename);

        printf("Now I'll free memory occupied by abstract syntax tree!\n");
        free_ast(ast);
        printf("Memory is free!\n\n");

        printf("Converted file (code.wat) could be found into main folder\n");
    }
	else printf("\nWRONG SYNTAX! ç.ç\n");

    return result;
}
