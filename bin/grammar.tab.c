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

	int yylex();
    void yyerror (const char *s);
    /* Variable needed for debugging */
//	int yydebug = 1;

    // Abstract Syntax Tree
    AST *ast;

#line 87 "grammar.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
#line 23 "./src/grammar.y" /* yacc.c:355  */

    char *sval;
    List *list;
    AST *node;
    int operator;
    int builtin;
    int value_type;

#line 178 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "grammar.tab.c" /* yacc.c:358  */

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
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

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
       0,    80,    80,    85,    93,    94,   101,   120,   124,   134,
     140,   147,   148,   152,   175,   181,   187,   193,   201,   208,
     214,   222,   230,   231,   232,   239,   245,   253,   261,   262,
     266,   272,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   293,   302,   306,   312,   327,   331,   335,   339,   347,
     351,   355,   359,   363,   367,   368,   372,   376,   380,   384,
     388,   392,   393,   397,   404,   408,   415,   421,   429,   436,
     442,   453,   457,   464,   465,   474,   484,   488,   494,   502,
     508,   516,   520,   524,   533,   534,   535,   536,   537,   544,
     548,   553,   558,   583,   587,   591,   598,   602,   609,   613
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "functions", "func_definition", "argument_list", "parameter_list",
  "parameter_declaration", "body", "statements", "statement", "func_call",
  "call_args", "assignment", "expr", "increment", "printf_stat",
  "printed_var", "scanf_stat", "retrieved_var", "if_stat", "block",
  "for_stat", "init_for", "incr_for", "return_stat", "var_type",
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

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     198,  -157,  -157,  -157,  -157,   -14,    12,   198,  -157,     7,
     276,  -157,   -14,  -157,   123,  -157,  -157,   276,  -157,  -157,
    -157,   -14,    -7,  -157,  -157,   249,   198,    47,   -14,    73,
     -14,  -157,   281,   143,    58,   -14,    32,   136,  -157,  -157,
     147,    27,    77,    85,  -157,   -14,     8,   155,   155,   155,
    -157,  -157,  -157,  -157,  -157,   262,  -157,    92,  -157,  -157,
     -14,  -157,  -157,   100,   276,    34,     8,  -157,  -157,  -157,
    -157,    44,    34,  -157,   220,    89,  -157,  -157,   155,   155,
     155,   155,   155,   155,   155,   155,   -14,  -157,   107,   192,
    -157,   113,  -157,     8,  -157,   157,   157,  -157,  -157,   286,
     173,   279,   271,    69,    34,  -157,   118,   120,   127,   140,
      21,   192,   149,   109,  -157,   146,   148,   154,   158,   160,
    -157,  -157,   174,   248,     8,  -157,  -157,   -14,   155,   -14,
     156,   168,    34,  -157,   109,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,   193,    34,   230,  -157,   194,   147,   203,
     206,   205,  -157,   172,   -14,   155,   -14,  -157,   231,   109,
    -157,   223,  -157,   253,    94,    34,   -14,   101,   182,   172,
     155,  -157,   -14,    34,  -157,   247,  -157,  -157,   262,   106,
      34,   -14,   172,   155,    34,  -157,   262
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    84,    85,    86,    87,    88,     0,     0,     4,     0,
       2,    19,    11,    89,     0,     1,     5,     3,     7,    88,
      20,     0,     0,     8,     9,    12,     0,     0,     0,     0,
      11,     6,    22,     0,     0,    11,     0,     0,    92,    10,
      12,    23,     0,    24,    25,     0,     0,     0,     0,     0,
      98,    99,    96,    97,    48,    46,    54,    62,    45,    61,
      11,    90,    91,     0,     0,    27,     0,    93,    94,    95,
      16,     0,    14,    15,     0,    62,    53,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    63,    13,     0,
      26,     0,    47,     0,    60,    49,    50,    51,    52,    55,
      56,    57,    58,     0,    43,    32,     0,     0,     0,     0,
      81,     0,     0,    28,    30,     0,     0,     0,     0,     0,
      38,    39,     0,     0,     0,    18,    41,     0,     0,    76,
       0,     0,    83,    82,    29,    21,    31,    33,    34,    35,
      36,    37,    40,    18,    44,     0,    77,     0,     0,    97,
       0,     0,    17,     0,    76,     0,     0,    64,     0,     0,
      73,    71,    78,     0,     0,    66,     0,     0,     0,     0,
       0,    65,     0,    69,    68,     0,    74,    72,    79,     0,
      67,     0,     0,     0,    70,    75,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   -17,     1,   -24,  -157,  -157,   -64,   210,     4,
    -157,  -157,   196,  -157,  -106,   -82,   232,  -157,   -11,   -15,
     -38,  -157,  -157,  -157,  -157,  -157,  -156,  -157,   117,  -157,
    -157,    10,    -5,   153,   150,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    22,    23,     9,    71,    10,    11,
      42,    43,    44,   112,   113,   114,   115,   103,   116,    55,
      56,   118,   164,   119,   167,   120,   161,   121,   147,   179,
     122,    35,    75,    73,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    24,    91,    30,    31,   134,    39,    25,    16,    34,
      12,    66,    15,   177,    20,    13,    29,    12,    18,    24,
      21,    20,    37,    38,    24,    40,   185,    21,    57,   125,
      40,   136,    74,    76,    77,    16,    88,    13,    61,    27,
      65,    72,    45,    28,    67,    68,    69,    70,    92,    24,
      13,   117,   136,   168,    93,    40,   -84,    67,    68,    69,
     143,    72,    60,    95,    96,    97,    98,    99,   100,   101,
     102,   160,   111,   117,    45,   117,    13,   126,    27,   127,
      32,   104,    28,    36,   123,    63,   136,   160,    72,     1,
       2,     3,     4,     5,    27,    64,   117,    27,    28,    86,
     160,    28,   171,    89,   172,   132,   123,    87,   123,   174,
      87,   175,    16,   145,   182,   117,   183,    30,   146,    72,
     105,   117,   144,   124,   148,   128,    26,   129,    27,   123,
     117,   117,    28,   106,   130,   107,   108,   109,    13,   110,
     163,    27,    62,   146,   117,    28,    46,   131,   123,   148,
      47,   165,    27,   135,   123,   178,    28,   137,    48,   138,
      33,   173,    47,   123,   123,   139,    49,   180,   186,   140,
      48,   141,    13,    80,    81,   159,   184,   123,    49,    50,
      51,    52,    53,   105,    13,   142,   176,    78,    79,    80,
      81,    50,    51,   105,    52,   149,   106,   152,   107,   108,
     109,    13,   110,   105,   154,   155,   106,   151,   107,   108,
     109,    13,   110,   156,   157,   158,   106,    17,   107,   108,
     109,    13,   110,     1,     2,     3,     4,     5,    94,     1,
       2,     3,     4,     5,    78,    79,    80,    81,   153,    82,
      83,    84,    85,   166,    78,    79,    80,    81,   169,    82,
      83,    84,    85,    27,    27,    86,    32,    28,    28,   181,
      90,    33,    33,   133,   170,    54,    87,    78,    79,    80,
      81,   162,    82,    83,    84,    85,    78,    79,    80,    81,
     150,    82,    83,    84,    85,    78,    79,    80,    81,     0,
      82,    83,    84,    78,    79,    80,    81,     0,    82,    83,
      78,    79,    80,    81,     0,     0,    83,     1,     2,     3,
       4,    19,    41,     2,     3,     4,    19
};

static const yytype_int16 yycheck[] =
{
       5,    12,    66,    10,    11,   111,    30,    12,     7,    26,
       0,     3,     0,   169,    10,    29,    21,     7,    11,    30,
      10,    17,    27,    28,    35,    30,   182,    17,    33,    93,
      35,   113,    47,    48,    49,    34,    60,    29,     6,     5,
      45,    46,    32,     9,    36,    37,    38,    39,     4,    60,
      29,    89,   134,   159,    10,    60,    29,    36,    37,    38,
     124,    66,     4,    78,    79,    80,    81,    82,    83,    84,
      85,   153,    89,   111,    64,   113,    29,     8,     5,    10,
       7,    86,     9,    36,    89,     8,   168,   169,    93,    31,
      32,    33,    34,    35,     5,    10,   134,     5,     9,     7,
     182,     9,     8,     3,    10,   110,   111,    18,   113,     8,
      18,    10,   111,   128,     8,   153,    10,    10,   129,   124,
      11,   159,   127,    10,   129,     7,     3,     7,     5,   134,
     168,   169,     9,    24,     7,    26,    27,    28,    29,    30,
     155,     5,     6,   154,   182,     9,     3,     7,   153,   154,
       7,   156,     5,     4,   159,   170,     9,    11,    15,    11,
      13,   166,     7,   168,   169,    11,    23,   172,   183,    11,
      15,    11,    29,    16,    17,     3,   181,   182,    23,    36,
      37,    38,    39,    11,    29,    11,     4,    14,    15,    16,
      17,    36,    37,    11,    38,    39,    24,     4,    26,    27,
      28,    29,    30,    11,    10,    11,    24,    39,    26,    27,
      28,    29,    30,    10,     8,    10,    24,     7,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     8,    31,
      32,    33,    34,    35,    14,    15,    16,    17,     8,    19,
      20,    21,    22,    12,    14,    15,    16,    17,    25,    19,
      20,    21,    22,     5,     5,     7,     7,     9,     9,    12,
      64,    13,    13,   110,    11,    33,    18,    14,    15,    16,
      17,   154,    19,    20,    21,    22,    14,    15,    16,    17,
     130,    19,    20,    21,    22,    14,    15,    16,    17,    -1,
      19,    20,    21,    14,    15,    16,    17,    -1,    19,    20,
      14,    15,    16,    17,    -1,    -1,    20,    31,    32,    33,
      34,    35,    31,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    43,    44,    45,    48,
      50,    51,    73,    29,    74,     0,    45,    50,    11,    35,
      51,    73,    46,    47,    60,    74,     3,     5,     9,    74,
      10,    11,     7,    13,    44,    73,    36,    74,    74,    46,
      74,    31,    52,    53,    54,    73,     3,     7,    15,    23,
      36,    37,    38,    39,    58,    61,    62,    74,    76,    77,
       4,     6,     6,     8,    10,    74,     3,    36,    37,    38,
      39,    49,    74,    75,    61,    74,    61,    61,    14,    15,
      16,    17,    19,    20,    21,    22,     7,    18,    46,     3,
      54,    49,     4,    10,     8,    61,    61,    61,    61,    61,
      61,    61,    61,    59,    74,    11,    24,    26,    27,    28,
      30,    44,    55,    56,    57,    58,    60,    62,    63,    65,
      67,    69,    72,    74,    10,    49,     8,    10,     7,     7,
       7,     7,    74,    75,    56,     4,    57,    11,    11,    11,
      11,    11,    11,    49,    74,    61,    60,    70,    74,    39,
      76,    39,     4,     8,    10,    11,    10,     8,    10,     3,
      57,    68,    70,    61,    64,    74,    12,    66,    56,    25,
      11,     8,    10,    74,     8,    10,     4,    68,    61,    71,
      74,    12,     8,    10,    74,    68,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    49,    49,    49,    50,
      50,    51,    52,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    69,    70,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    75,    76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     2,     1,     1,
       3,     0,     1,     6,     1,     1,     1,     5,     3,     1,
       2,     8,     0,     1,     1,     1,     3,     2,     1,     2,
       1,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       2,     4,     0,     1,     3,     3,     3,     5,     3,     3,
       3,     3,     3,     2,     1,     3,     3,     3,     3,     2,
       3,     1,     1,     2,     4,     6,     1,     3,     6,     2,
       4,     5,     7,     1,     3,     9,     0,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     1,     1,     1,     1,     1,     1
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
#line 81 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root(list_new(), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1432 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root((yyvsp[-1].list), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1441 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.list) = list_merge((yyvsp[-1].list),(yyvsp[0].list));
                }
#line 1449 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "./src/grammar.y" /* yacc.c:1646  */
    {
                    int size = list_length((yyvsp[-1].list)),i;
                    // update variable nodes with associated type
                    for(i=0;i<size;i++) {
                        AST *obj = list_get((yyvsp[-1].list),i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                obj->ast_variable->type = (yyvsp[-2].value_type);
                                break;
                            case N_ASSIGNMENT:
                                obj->ast_assign->variable->ast_variable->type = (yyvsp[-2].value_type);
                                break;
                        }
                        (yyvsp[-1].list)->items[i] = obj;
                    }
                    // associate updated list at head of rule
                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1472 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 125 "./src/grammar.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].node) != NULL)
                {
                    List *var_list = list_new();
                    list_append(var_list, (yyvsp[0].node));
                    (yyval.list) = var_list;
                }
                else (yyval.list) = NULL;
            }
#line 1486 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *var_list = list_new();
                list_append(var_list, (yyvsp[0].node));
                (yyval.list) = var_list;
            }
#line 1496 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 1504 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1510 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "./src/grammar.y" /* yacc.c:1646  */
    {
                        if((yyvsp[0].list) != NULL)
                        {
                            AST *struct_def = new_AST_Struct ((yyvsp[-4].node)->ast_variable->name, (yyvsp[-5].value_type), (yyvsp[-2].list));

                            AST *a;
                            for(int i=0; i<list_length((yyvsp[0].list));i++)
                            {
                                a = list_get((yyvsp[0].list),i);
                                
                                if(a->type == N_VARIABLE)
                                    (yyvsp[0].list)->items[i] = new_AST_Var_Struct (struct_def, a->ast_variable->name, a->ast_variable->n);
                                
                                if(a->type == N_ASSIGNMENT)
                                    (yyvsp[0].list)->items[i] = new_AST_Var_Struct (struct_def, a->ast_assign->variable->ast_variable->name, a->ast_assign->variable->ast_variable->n);
                            }
                        }
                        (yyval.list) = (yyvsp[0].list);
                    }
#line 1534 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 176 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1544 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1554 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].sval));
                            (yyval.list) = init_list;
                        }
#line 1564 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "./src/grammar.y" /* yacc.c:1646  */
    {
                            list_merge((yyvsp[-3].list),(yyvsp[-1].list));
                            AST *init = new_AST_List((yyvsp[-3].list));
                            List *array_el = list_new();
                            list_append(array_el,init);
                            (yyval.list) = array_el;
                        }
#line 1576 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 202 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
                        }
#line 1584 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 209 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *func = list_new();
                list_append(func, (yyvsp[0].node));
                (yyval.list) = func;
            }
#line 1594 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 215 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1603 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "./src/grammar.y" /* yacc.c:1646  */
    {
                        (yyvsp[-6].node)->ast_variable->type = (yyvsp[-7].value_type);
                        (yyval.node) = new_AST_Def_Function((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
                    }
#line 1612 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1618 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 231 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1624 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 233 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_List((yyvsp[0].list));
                }
#line 1632 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *param = list_new();
                    list_append(param, (yyvsp[0].node));
                    (yyval.list) = param;
                }
#line 1642 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 246 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list), (yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1651 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node)->ast_variable->type = (yyvsp[-1].value_type);
                            (yyval.node) = (yyvsp[0].node);
                        }
#line 1660 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 261 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body(list_new(),(yyvsp[0].list)); }
#line 1666 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 262 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body((yyvsp[-1].list),(yyvsp[0].list)); }
#line 1672 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 267 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *stats = list_new();
                list_append(stats, (yyvsp[0].node));
                (yyval.list) = stats;
            }
#line 1682 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 273 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1691 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 281 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1697 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 294 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Call_Function ((yyvsp[-3].node),(yyvsp[-1].list));
            }
#line 1705 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 302 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                (yyval.list) = call_arg;
            }
#line 1714 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 307 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                list_append(call_arg, (yyvsp[0].node));
                (yyval.list) = call_arg;
            }
#line 1724 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 313 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 1733 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 328 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1741 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 332 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1749 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 336 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-4].node), new_AST_List((yyvsp[-1].list)));
            }
#line 1757 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 340 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign ((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1765 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 348 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1773 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 352 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1781 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 356 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1789 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 360 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1797 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 364 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 1805 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 369 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1813 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 373 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1821 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 377 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1829 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 381 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1837 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 385 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 1845 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 389 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1853 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 398 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Unary_Expr ((yyvsp[0].operator),(yyvsp[-1].node));
            }
#line 1861 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 405 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-3].builtin), (yyvsp[-1].node), list_new());
                }
#line 1869 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 409 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 1877 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 416 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *prin_var = list_new();
                    list_append(prin_var, (yyvsp[0].node));
                    (yyval.list) = prin_var;
                }
#line 1887 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 422 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1896 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 430 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 1904 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 437 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *retr_var = list_new();
                    list_append(retr_var, (yyvsp[0].node));
                    (yyval.list) = retr_var;
                }
#line 1914 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 443 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-3].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-3].list);
                }
#line 1923 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 454 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-2].node),(yyvsp[0].node),NULL);
            }
#line 1931 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 458 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1939 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 466 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_List((yyvsp[-1].list));
        }
#line 1947 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 475 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_For_Stat((yyvsp[-6].list),(yyvsp[-4].node),(yyvsp[-2].list),(yyvsp[0].node));
            }
#line 1955 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 484 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                (yyval.list) = init_list;
            }
#line 1964 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 489 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                list_append(init_list, (yyvsp[0].node));
                (yyval.list) = init_list;
            }
#line 1974 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 495 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 1982 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 503 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *incr_list = list_new();
                list_append(incr_list, (yyvsp[0].node));
                (yyval.list) = incr_list;
            }
#line 1992 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 509 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 2001 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 517 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Return_Stat(NULL);
                }
#line 2009 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 521 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2017 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 525 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2025 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 545 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Variable((yyvsp[0].sval), -1, T_NULL);
            }
#line 2033 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 549 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyvsp[-3].node)->ast_variable->n = atoi((yyvsp[-1].sval));
                (yyval.node) = (yyvsp[-3].node);
            }
#line 2042 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 554 "./src/grammar.y" /* yacc.c:1646  */
    {
                // Search $3 value in ST and save in "n" variable
                //$1->ast_variable->n = value_$3;
            }
#line 2051 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 559 "./src/grammar.y" /* yacc.c:1646  */
    {
                char c[50];
                char *c1,*c2;
                // name+dimension/index of first identifier
                if((yyvsp[-2].node)->ast_variable->n == -1) c1 = (yyvsp[-2].node)->ast_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", (yyvsp[-2].node)->ast_variable->name, (yyvsp[-2].node)->ast_variable->n);
                    c1 = c;
                }
                // name+dimension/index of second identifier
                if((yyvsp[0].node)->ast_variable->n == -1) c2 = (yyvsp[0].node)->ast_variable->name;
                else
                {
                    sprintf(c, "%s[%d]", (yyvsp[0].node)->ast_variable->name, (yyvsp[0].node)->ast_variable->n);
                    c2 = c;
                }
                // concat identifiers and use it as name for AST *var_struct
                c1 = concat(3, "", c1,(yyvsp[-1].sval),c2);
                (yyval.node) = new_AST_Var_Struct(new_AST_Struct(NULL, T_STRUCT, NULL), c1, (yyvsp[-2].node)->ast_variable->n);
            }
#line 2077 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 584 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2085 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 588 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2093 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 592 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2101 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 599 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2109 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 603 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2117 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 610 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2125 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 614 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2133 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 2137 "grammar.tab.c" /* yacc.c:1646  */
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
#line 619 "./src/grammar.y" /* yacc.c:1906  */

void yyerror (const char *s)
{
    extern int yylineno;
	extern char* yytext;
	fprintf(stderr, "Error: %s\nLine: %d\nSymbol: %s\n", s, yylineno, yytext);
}

int main (void)
{
	// initialize symbol table
    //	init_hash_table();

	int result = yyparse();
	if(result==0)
    {
        printf("\nCORRECT SYNTAX! \\^.^/ \n");
        printf("Now I'll print the abstract syntax tree! :P\n\n");
        print_ast(ast,0); printf("\n");

        /* other stuff must be added */

        printf("Now I'll free memory occupied by abstract syntax tree!\n");
        free_ast(ast);
        printf("Memory is free!\n\n");
    }
	else printf("\nWRONG SYNTAX! ç.ç\n");

	// symbol table dump
    /*	yyout = fopen("symtab_dump.out w");
	symtab_dump(yyout);
	fclose(yyout);	
    */

    return result;
}
