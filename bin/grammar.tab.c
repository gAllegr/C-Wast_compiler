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

    AST *ast;               // Abstract Syntax Tree
    SymTab *symtab;         // Symbol Table

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
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       0,    80,    80,    85,    93,    94,   101,   124,   146,   156,
     162,   169,   170,   174,   209,   215,   221,   227,   235,   242,
     248,   257,   256,   278,   279,   280,   287,   293,   301,   306,
     314,   315,   319,   325,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   346,   355,   359,   365,   380,   384,   388,
     392,   400,   404,   408,   412,   416,   420,   421,   425,   429,
     433,   437,   441,   445,   446,   450,   457,   461,   468,   474,
     482,   489,   495,   506,   510,   517,   518,   527,   537,   541,
     547,   555,   561,   569,   573,   577,   585,   586,   587,   588,
     595,   599,   604,   610,   635,   639,   643,   650,   654,   661,
     665
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
  "functions", "func_definition", "@1", "argument_list", "parameter_list",
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

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     252,  -139,  -139,  -139,  -139,   -18,    19,   252,  -139,    17,
     268,  -139,   -18,  -139,    99,  -139,  -139,   268,  -139,  -139,
     -18,   117,  -139,  -139,   225,   252,    53,   -18,    83,   -18,
    -139,    84,    26,   112,   -18,    39,   183,  -139,  -139,    57,
      95,    42,    42,    42,  -139,  -139,  -139,  -139,  -139,   238,
    -139,    88,  -139,  -139,   257,   -18,  -139,  -139,    95,  -139,
    -139,  -139,  -139,   145,    83,  -139,   196,   151,  -139,  -139,
      42,    42,    42,    42,    42,    42,    42,    42,   -18,  -139,
      27,   -18,    61,    51,  -139,   -18,    62,    75,  -139,    95,
    -139,   219,   219,  -139,  -139,   262,   289,   255,   247,   102,
      83,    46,    91,   263,    83,    95,  -139,  -139,   -18,    83,
     167,  -139,   107,    83,  -139,   135,   152,   165,   175,   100,
     167,   115,   179,  -139,   208,   213,   236,   245,   254,  -139,
    -139,   282,   224,  -139,    42,   -18,   242,   123,    83,  -139,
     179,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   206,
    -139,   297,    57,   299,   265,   300,   147,   -18,    42,   -18,
    -139,   301,   179,  -139,   286,  -139,   229,   131,    83,   -18,
     155,   157,   147,    42,  -139,   -18,    83,  -139,   302,  -139,
    -139,   238,   231,    83,   -18,   147,    42,    83,  -139,   238
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    87,    88,    89,     0,     0,     0,     4,     0,
       2,    19,    11,    90,     0,     1,     5,     3,     7,    20,
       0,     0,     8,     9,    12,     0,     0,     0,    21,    11,
       6,     0,     0,     0,    11,     0,     0,    93,    10,    12,
       0,     0,     0,     0,    99,   100,    97,    98,    50,    48,
      56,    64,    47,    63,    23,    11,    91,    92,     0,    94,
      95,    96,    16,     0,    14,    15,     0,    64,    55,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    65,
      24,     0,     0,    25,    26,     0,    13,     0,    49,     0,
      62,    51,    52,    53,    54,    57,    58,    59,    60,     0,
      45,     0,     0,     0,    28,     0,    18,    43,     0,    29,
       0,    27,    18,    46,    34,     0,     0,     0,     0,    83,
       0,     0,    30,    32,     0,     0,     0,     0,     0,    40,
      41,     0,     0,    17,     0,    78,     0,     0,    85,    84,
      31,    22,    33,    35,    36,    37,    38,    39,    42,     0,
      79,     0,     0,    98,     0,     0,     0,    78,     0,     0,
      66,     0,     0,    75,    73,    80,     0,     0,    68,     0,
       0,     0,     0,     0,    67,     0,    71,    70,     0,    76,
      74,    81,     0,    69,     0,     0,     0,    72,    77,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   -24,    -2,   -25,  -139,  -139,   -31,   305,    73,
    -139,  -139,  -139,   212,  -139,  -103,  -104,   285,  -139,    -9,
     -33,  -108,  -139,  -139,  -139,  -139,  -139,  -138,  -139,   160,
    -139,  -139,     6,    -5,   199,   184,  -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    21,    22,     9,    63,    10,    11,
      32,    82,    83,    84,   121,   122,   123,   124,    99,   125,
      49,    50,   127,   167,   128,   170,   129,   164,   130,   151,
     182,   131,    34,    67,    65,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    33,   126,    23,    38,    16,    12,    24,    66,    68,
      69,    13,   126,    12,   126,    28,    20,   140,   142,    15,
      23,    36,    37,    20,    39,    23,    51,    87,    18,    39,
      86,    16,   126,    54,   180,    64,   142,    91,    92,    93,
      94,    95,    96,    97,    98,    56,    23,   188,   126,    41,
      39,    26,   163,    64,   126,    27,   -86,    42,   106,   171,
      85,   103,    26,   126,   126,    43,    27,   142,   163,   102,
      31,    13,    29,   100,   112,    13,   101,   126,    44,    45,
     104,   163,    13,    19,    64,   105,   120,    40,    26,    35,
      19,    41,    27,    26,   110,    78,   109,    27,    58,    42,
      64,   149,    25,   113,    26,   132,    79,    43,    27,    85,
     107,   133,   108,    13,   138,   132,    55,   132,    16,   141,
      44,    45,    46,    47,    13,   166,   150,    29,    30,    13,
     152,    59,    60,    61,    62,   132,    59,    60,    61,   174,
     181,   175,   134,     1,     2,     3,     4,     5,   150,    88,
     162,   132,   152,   189,   168,    89,    26,   132,   114,   135,
      27,   179,   155,   177,   176,   178,   132,   132,   114,    79,
     183,   115,   136,   116,   117,   118,    13,   119,   114,   187,
     132,   115,   137,   116,   117,   118,    13,   119,    26,    57,
     114,   115,    27,   116,   117,   118,    13,   119,     1,     2,
       3,     4,     5,   115,    90,   116,   117,   118,    13,   119,
      70,    71,    72,    73,   156,    74,    75,    76,    77,   143,
      70,    71,    72,    73,   144,    74,    75,    76,    77,    26,
      26,    78,   -21,    27,    27,    72,    73,    31,    31,   185,
     173,   186,    79,    70,    71,    72,    73,   145,    74,    75,
      76,    77,    70,    71,    72,    73,   146,    74,    75,    76,
      77,    70,    71,    72,    73,   147,    74,    75,    76,    70,
      71,    72,    73,   160,    74,    75,    70,    71,    72,    73,
      46,   153,    75,     1,     2,     3,     4,     5,    80,     2,
       3,     4,    81,   148,     1,     2,     3,     4,    81,     1,
       2,     3,     4,    70,    71,    72,    73,   157,   158,   159,
     161,   172,    17,   169,   184,   111,    48,   165,   139,     0,
     154
};

static const yytype_int16 yycheck[] =
{
       5,    25,   110,    12,    29,     7,     0,    12,    41,    42,
      43,    29,   120,     7,   122,    20,    10,   120,   122,     0,
      29,    26,    27,    17,    29,    34,    31,    58,    11,    34,
      55,    33,   140,     7,   172,    40,   140,    70,    71,    72,
      73,    74,    75,    76,    77,     6,    55,   185,   156,     7,
      55,     5,   156,    58,   162,     9,    29,    15,    89,   162,
      54,    10,     5,   171,   172,    23,     9,   171,   172,     8,
      13,    29,    10,    78,   105,    29,    81,   185,    36,    37,
      85,   185,    29,    10,    89,    10,   110,     3,     5,    36,
      17,     7,     9,     5,     3,     7,   101,     9,     3,    15,
     105,   134,     3,   108,     5,   110,    18,    23,     9,   103,
       8,     4,    10,    29,   119,   120,     4,   122,   120,     4,
      36,    37,    38,    39,    29,   158,   135,    10,    11,    29,
     135,    36,    37,    38,    39,   140,    36,    37,    38,     8,
     173,    10,     7,    31,    32,    33,    34,    35,   157,     4,
       3,   156,   157,   186,   159,    10,     5,   162,    11,     7,
       9,     4,    39,     8,   169,    10,   171,   172,    11,    18,
     175,    24,     7,    26,    27,    28,    29,    30,    11,   184,
     185,    24,     7,    26,    27,    28,    29,    30,     5,     6,
      11,    24,     9,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    24,     8,    26,    27,    28,    29,    30,
      14,    15,    16,    17,     8,    19,    20,    21,    22,    11,
      14,    15,    16,    17,    11,    19,    20,    21,    22,     5,
       5,     7,     7,     9,     9,    16,    17,    13,    13,     8,
      11,    10,    18,    14,    15,    16,    17,    11,    19,    20,
      21,    22,    14,    15,    16,    17,    11,    19,    20,    21,
      22,    14,    15,    16,    17,    11,    19,    20,    21,    14,
      15,    16,    17,     8,    19,    20,    14,    15,    16,    17,
      38,    39,    20,    31,    32,    33,    34,    35,    31,    32,
      33,    34,    35,    11,    31,    32,    33,    34,    35,    31,
      32,    33,    34,    14,    15,    16,    17,    10,    11,    10,
      10,    25,     7,    12,    12,   103,    31,   157,   119,    -1,
     136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    43,    44,    45,    48,
      50,    51,    74,    29,    75,     0,    45,    50,    11,    51,
      74,    46,    47,    61,    75,     3,     5,     9,    75,    10,
      11,    13,    52,    44,    74,    36,    75,    75,    46,    75,
       3,     7,    15,    23,    36,    37,    38,    39,    59,    62,
      63,    75,    77,    78,     7,     4,     6,     6,     3,    36,
      37,    38,    39,    49,    75,    76,    62,    75,    62,    62,
      14,    15,    16,    17,    19,    20,    21,    22,     7,    18,
      31,    35,    53,    54,    55,    74,    46,    49,     4,    10,
       8,    62,    62,    62,    62,    62,    62,    62,    62,    60,
      75,    75,     8,    10,    75,    10,    49,     8,    10,    75,
       3,    55,    49,    75,    11,    24,    26,    27,    28,    30,
      44,    56,    57,    58,    59,    61,    63,    64,    66,    68,
      70,    73,    75,     4,     7,     7,     7,     7,    75,    76,
      57,     4,    58,    11,    11,    11,    11,    11,    11,    62,
      61,    71,    75,    39,    77,    39,     8,    10,    11,    10,
       8,    10,     3,    58,    69,    71,    62,    65,    75,    12,
      67,    57,    25,    11,     8,    10,    75,     8,    10,     4,
      69,    62,    72,    75,    12,     8,    10,    75,    69,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    49,    49,    49,    50,
      50,    52,    51,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    60,    60,    60,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    64,    64,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    77,    77,    78,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     2,     1,     1,
       3,     0,     1,     6,     1,     1,     1,     5,     3,     1,
       2,     0,     9,     0,     1,     1,     1,     3,     2,     3,
       1,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     2,     4,     0,     1,     3,     3,     3,     5,
       3,     3,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     2,     3,     1,     1,     2,     4,     6,     1,     3,
       6,     2,     4,     5,     7,     1,     3,     9,     0,     1,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     4,     4,     3,     1,     1,     1,     1,     1,     1,
       1
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
#line 1437 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "./src/grammar.y" /* yacc.c:1646  */
    {
                ast = new_AST_Root((yyvsp[-1].list), (yyvsp[0].list));
                (yyval.node) = ast;
            }
#line 1446 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.list) = list_merge((yyvsp[-1].list),(yyvsp[0].list));
                }
#line 1454 "grammar.tab.c" /* yacc.c:1646  */
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
                                obj->ast_variable->sym_variable->type = (yyvsp[-2].value_type);
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_variable->sym_variable, scope);
                                break;
                            case N_ASSIGNMENT:
                                obj->ast_assign->variable->ast_variable->sym_variable->type = (yyvsp[-2].value_type);
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_assign->variable->ast_variable->sym_variable, scope);
                                break;
                        }
                        (yyvsp[-1].list)->items[i] = obj;
                    }
                    // associate updated list at head of rule
                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1481 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "./src/grammar.y" /* yacc.c:1646  */
    {
                    for(int i=0; i<list_length((yyvsp[-1].list));i++)
                    {
                        AST *obj = list_get((yyvsp[-1].list),i);
                        switch(obj->type) {
                            case N_VARIABLE:
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_variable->sym_variable, scope);
                                break;
                            case N_ASSIGNMENT:
                                // Insert declared variables in Symbol Table
                                insert_var(symtab, obj->ast_assign->variable->ast_variable->sym_variable, scope);
                                break;
                        }
                    }

                    (yyval.list) = (yyvsp[-1].list);
                }
#line 1504 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "./src/grammar.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].node) != NULL)
                {
                    List *var_list = list_new();
                    list_append(var_list, (yyvsp[0].node));
                    (yyval.list) = var_list;
                }
                else (yyval.list) = NULL;
            }
#line 1518 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *var_list = list_new();
                list_append(var_list, (yyvsp[0].node));
                (yyval.list) = var_list;
            }
#line 1528 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 163 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 1536 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1542 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 175 "./src/grammar.y" /* yacc.c:1646  */
    {
                        if((yyvsp[0].list) != NULL)
                        {
                            List *elements = convert((yyvsp[-2].list));

                            AST *a;
                            for(int i=0; i<list_length((yyvsp[0].list));i++)
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
#line 1578 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 210 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1588 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 216 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].node));
                            (yyval.list) = init_list;
                        }
#line 1598 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 222 "./src/grammar.y" /* yacc.c:1646  */
    {
                            List *init_list = list_new();
                            list_append(init_list, (yyvsp[0].sval));
                            (yyval.list) = init_list;
                        }
#line 1608 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 228 "./src/grammar.y" /* yacc.c:1646  */
    {
                            list_merge((yyvsp[-3].list),(yyvsp[-1].list));
                            AST *init = new_AST_List((yyvsp[-3].list));
                            List *array_el = list_new();
                            list_append(array_el,init);
                            (yyval.list) = array_el;
                        }
#line 1620 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 236 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
                        }
#line 1628 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *func = list_new();
                list_append(func, (yyvsp[0].node));
                (yyval.list) = func;
            }
#line 1638 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 249 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1647 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 257 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].node)->ast_variable->sym_variable->type = (yyvsp[-1].value_type);
                    (yyval.node) = new_AST_Def_Function((yyvsp[0].node));
                    // Insert declared function in Symbol Table
                    insert_fun(symtab, (yyval.node)->ast_def_function->sym_function);
                    // Update scope
                    scope = (yyval.node)->ast_def_function->sym_function->func_name->name;
                 }
#line 1660 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 266 "./src/grammar.y" /* yacc.c:1646  */
    {
                        if((yyvsp[-4].node) != NULL) 
                        {
                            (yyvsp[-6].node)->ast_def_function->sym_function->parameters = convert((yyvsp[-4].node)->ast_list->list);
                            update_par(symtab, (yyvsp[-6].node)->ast_def_function->sym_function->parameters, scope);
                        }
                        (yyvsp[-6].node)->ast_def_function->body = (yyvsp[-1].node);
                        (yyval.node) = (yyvsp[-6].node);
                    }
#line 1674 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 278 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1680 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 279 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1686 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 281 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_List((yyvsp[0].list));
                }
#line 1694 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 288 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *param = list_new();
                    list_append(param, (yyvsp[0].node));
                    (yyval.list) = param;
                }
#line 1704 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 294 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list), (yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1713 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 302 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node)->ast_variable->sym_variable->type = (yyvsp[-1].value_type);
                            (yyval.node) = (yyvsp[0].node);
                        }
#line 1722 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 307 "./src/grammar.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node)->ast_variable->sym_variable->type = (yyvsp[-2].value_type);
                            (yyvsp[0].node)->ast_variable->sym_variable->s_info = new_struct_info((yyvsp[-1].node)->ast_variable->sym_variable->name, NULL);
                        }
#line 1731 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 314 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body(list_new(),(yyvsp[0].list)); }
#line 1737 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "./src/grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_AST_Body((yyvsp[-1].list),(yyvsp[0].list)); }
#line 1743 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 320 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *stats = list_new();
                list_append(stats, (yyvsp[0].node));
                (yyval.list) = stats;
            }
#line 1753 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 326 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-1].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-1].list);
            }
#line 1762 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 334 "./src/grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1768 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 347 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Call_Function ((yyvsp[-3].node),(yyvsp[-1].list));
            }
#line 1776 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 355 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                (yyval.list) = call_arg;
            }
#line 1785 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 360 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *call_arg = list_new();
                list_append(call_arg, (yyvsp[0].node));
                (yyval.list) = call_arg;
            }
#line 1795 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 366 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 1804 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1812 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 385 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1820 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 389 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign((yyvsp[-4].node), new_AST_List((yyvsp[-1].list)));
            }
#line 1828 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 393 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Assign ((yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1836 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 401 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1844 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 405 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1852 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 409 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1860 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 413 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1868 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 417 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 1876 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 422 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1884 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 426 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1892 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 430 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1900 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Binary_Expr((yyvsp[-1].operator),(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1908 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 438 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Unary_Expr ((yyvsp[-1].operator),(yyvsp[0].node));
        }
#line 1916 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 442 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1924 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 451 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Unary_Expr ((yyvsp[0].operator),(yyvsp[-1].node));
            }
#line 1932 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 458 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-3].builtin), (yyvsp[-1].node), list_new());
                }
#line 1940 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 462 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 1948 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 469 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *prin_var = list_new();
                    list_append(prin_var, (yyvsp[0].node));
                    (yyval.list) = prin_var;
                }
#line 1958 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 475 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-2].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-2].list);
                }
#line 1967 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 483 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Builtin_Stat((yyvsp[-5].builtin), new_AST_Const(T_CHAR,(yyvsp[-3].sval)), (yyvsp[-1].list));
                }
#line 1975 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 490 "./src/grammar.y" /* yacc.c:1646  */
    {
                    List *retr_var = list_new();
                    list_append(retr_var, (yyvsp[0].node));
                    (yyval.list) = retr_var;
                }
#line 1985 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 496 "./src/grammar.y" /* yacc.c:1646  */
    {
                    list_append((yyvsp[-3].list),(yyvsp[0].node));
                    (yyval.list) = (yyvsp[-3].list);
                }
#line 1994 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 507 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-2].node),(yyvsp[0].node),NULL);
            }
#line 2002 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 511 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_If_Stat((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 2010 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 519 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_List((yyvsp[-1].list));
        }
#line 2018 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 528 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_For_Stat((yyvsp[-6].list),(yyvsp[-4].node),(yyvsp[-2].list),(yyvsp[0].node));
            }
#line 2026 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 537 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                (yyval.list) = init_list;
            }
#line 2035 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 542 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *init_list = list_new();
                list_append(init_list, (yyvsp[0].node));
                (yyval.list) = init_list;
            }
#line 2045 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 548 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.list) = list_merge((yyvsp[-2].list),(yyvsp[0].list));
            }
#line 2053 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 556 "./src/grammar.y" /* yacc.c:1646  */
    {
                List *incr_list = list_new();
                list_append(incr_list, (yyvsp[0].node));
                (yyval.list) = incr_list;
            }
#line 2063 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 562 "./src/grammar.y" /* yacc.c:1646  */
    {
                list_append((yyvsp[-2].list), (yyvsp[0].node));
                (yyval.list) = (yyvsp[-2].list);
            }
#line 2072 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 570 "./src/grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_AST_Return_Stat(NULL);
                }
#line 2080 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 574 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2088 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 578 "./src/grammar.y" /* yacc.c:1646  */
    {
                   (yyval.node) = new_AST_Return_Stat((yyvsp[0].node));
               }
#line 2096 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 596 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyval.node) = new_AST_Variable((yyvsp[0].sval), -1, T_NULL, NULL, 0, 0);
            }
#line 2104 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 600 "./src/grammar.y" /* yacc.c:1646  */
    {
                (yyvsp[-3].node)->ast_variable->sym_variable->n = atoi((yyvsp[-1].sval));
                (yyval.node) = (yyvsp[-3].node);
            }
#line 2113 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 605 "./src/grammar.y" /* yacc.c:1646  */
    {
                // We don't save identifiers' value, so we don't know the array dimension
                (yyvsp[-3].node)->ast_variable->sym_variable->n = -2;
                (yyval.node) = (yyvsp[-3].node);
            }
#line 2123 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 611 "./src/grammar.y" /* yacc.c:1646  */
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
                (yyval.node) = new_AST_Variable (c1, (yyvsp[-2].node)->ast_variable->sym_variable->n, T_STRUCT, NULL, 0, 0);
            }
#line 2149 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 636 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2157 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 640 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2165 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 644 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2173 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 651 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2181 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 655 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(3,(yyvsp[0].sval));
        }
#line 2189 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 662 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(1,(yyvsp[0].sval));
        }
#line 2197 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 666 "./src/grammar.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_AST_Const(2,(yyvsp[0].sval));
        }
#line 2205 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 2209 "grammar.tab.c" /* yacc.c:1646  */
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
#line 671 "./src/grammar.y" /* yacc.c:1906  */

void yyerror (const char *s)
{
    extern int yylineno;
	extern char* yytext;
	fprintf(stderr, "Error: %s\nLine: %d\nSymbol: %s\n", s, yylineno, yytext);
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
        printf("Now I'll print the abstract syntax tree!\n\n");
        print_ast(ast,0); printf("\n");

        printf("Now I'll print the symbol table!\n\n");
        print_symtab(symtab); printf("\n");

        /* other stuff (code_gen) */

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
