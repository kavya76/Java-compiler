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
#line 1 "try_symb.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int yylex();
extern FILE *fp;
FILE * f1;
char temp[20];

char keywords[300][500];

int keycount=0;
typedef struct ident{
	
	char type[7];
	char idname[15];
	int line;

} token;

token identifier[20];

int identcount=0;

void insertidenttoken(char *a, char *b, int c){
	strcpy(identifier[identcount].type,a);

	strcpy(identifier[identcount].idname,b);
	identifier[identcount].line=c;	
	identcount++;

}

void displayidenttokens(){
	int i=0;
	for(i=0; i<identcount; i++){
		printf("Identifier, %s, %s, lineno: %d \n", identifier[i].type, identifier[i].idname, identifier[i].line);

	}

}
void keywordstable(char *a){
	
	//printf("\ncomes here : ");
	//printf("%s\n",a);
	strcpy(keywords[keycount++],a);

}

void displaykeywordtokens(){
	printf("******************************Symbol Table***********************************\n");
	int i=0;
    for(i=0;i<keycount;i++){
    	printf("< keyword, %s >\n",keywords[i]);
    }
}

#line 125 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    IMPORT = 259,
    STATIC = 260,
    PUBLIC = 261,
    CLASS = 262,
    ARGS = 263,
    MAIN = 264,
    SYSTEM = 265,
    OUT = 266,
    VOID = 267,
    PRINT = 268,
    UINT = 269,
    INT = 270,
    WHILE = 271,
    PRNSTR = 272,
    IF = 273,
    ELSE = 274,
    SWITCH = 275,
    CASE = 276,
    BREAK = 277,
    DEFAULT = 278,
    NUM = 279,
    ID = 280,
    INCLUDE = 281,
    ASGN = 282,
    LOR = 283,
    LAND = 284,
    BOR = 285,
    BXOR = 286,
    BAND = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    LT = 292,
    GT = 293,
    IFX = 294,
    IFX1 = 295
  };
#endif
/* Tokens.  */
#define STRING 258
#define IMPORT 259
#define STATIC 260
#define PUBLIC 261
#define CLASS 262
#define ARGS 263
#define MAIN 264
#define SYSTEM 265
#define OUT 266
#define VOID 267
#define PRINT 268
#define UINT 269
#define INT 270
#define WHILE 271
#define PRNSTR 272
#define IF 273
#define ELSE 274
#define SWITCH 275
#define CASE 276
#define BREAK 277
#define DEFAULT 278
#define NUM 279
#define ID 280
#define INCLUDE 281
#define ASGN 282
#define LOR 283
#define LAND 284
#define BOR 285
#define BXOR 286
#define BAND 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define LT 292
#define GT 293
#define IFX 294
#define IFX1 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "try_symb.y" /* yacc.c:355  */

	
	char *keyname;
	char *typename;
	char *idname;
	char *intval;
	char  *flotval;

#line 254 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      50,    51,    41,    39,    54,    40,    52,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,    44,     2,     2,     2,
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
      35,    36,    37,    38,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   100,   103,   106,   109,   109,   111,   112,
     115,   116,   117,   118,   119,   120,   121,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   142,   143,
     146,   149,   149,   151,   151,   151,   152,   155,   155,   157,
     158,   161,   161,   162,   164,   164,   165,   165,   168,   168,
     171,   171,   172,   176,   177,   181,   181,   181,   184,   185,
     189,   189,   189,   193,   194,   194,   198,   198,   198,   198,
     202,   203,   204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "IMPORT", "STATIC", "PUBLIC",
  "CLASS", "ARGS", "MAIN", "SYSTEM", "OUT", "VOID", "PRINT", "UINT", "INT",
  "WHILE", "PRNSTR", "IF", "ELSE", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "NUM", "ID", "INCLUDE", "ASGN", "LOR", "LAND", "BOR", "BXOR", "BAND",
  "EQ", "NE", "LE", "GE", "LT", "GT", "'+'", "'-'", "'*'", "'/'", "'@'",
  "'~'", "IFX", "IFX1", "';'", "'{'", "'}'", "'('", "')'", "'.'", "':'",
  "','", "$accept", "Start", "Here", "pgmstart", "STMTS", "STMT1", "STMT",
  "EXP", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "print_stmt", "STMT_IF",
  "$@16", "ELSESTMT", "$@17", "$@18", "STMT_SWITCH", "$@19", "SWITCHBODY",
  "CASES", "$@20", "BREAKSTMT", "$@21", "$@22", "DEFAULTSTMT", "$@23",
  "DE", "$@24", "SWITCHEXP", "STMT_WHILE", "$@25", "$@26", "WHILEBODY",
  "STMT_DECLARE", "$@27", "$@28", "IDS", "$@29", "STMT_ASSGN", "$@30",
  "$@31", "$@32", "TYPE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,    64,   126,   294,   295,    59,   123,   125,
      40,    41,    46,    58,    44
};
# endif

#define YYPACT_NINF -149

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-149)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -14,     5,     4,  -149,   -30,    -5,  -149,    12,   -26,
    -149,    20,    27,   -16,    38,  -149,    50,    11,    61,    57,
      16,    21,    64,  -149,    18,  -149,  -149,  -149,    25,    31,
    -149,  -149,    22,    64,  -149,  -149,  -149,  -149,    67,  -149,
    -149,  -149,    66,   -22,   -22,    58,  -149,  -149,    36,    62,
      39,  -149,  -149,   -22,    89,   112,  -149,   -22,  -149,    75,
     135,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,    65,    63,    60,    68,    69,  -149,   -22,   158,
     -41,    44,  -149,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,    21,   -22,   -22,   -22,   -22,   -22,    49,
     181,  -149,  -149,    73,  -149,    83,    97,    97,    -3,    -3,
      -3,    -3,   -34,   -34,  -149,  -149,    85,   261,   246,   231,
     216,   201,    81,    59,    48,  -149,    54,  -149,  -149,    84,
     106,    86,  -149,  -149,  -149,  -149,   -41,   109,    21,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,   104,   105,  -149,     9,
       9,  -149,  -149,    88,    90,  -149,  -149,    81,  -149,  -149,
     113,  -149,   114,    81,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     0,     1,     0,     0,
       2,     0,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     7,     9,     5,     0,    91,    92,    90,     0,     0,
      86,    16,     0,     9,    15,    12,    14,    13,     0,    10,
      11,    80,     0,     0,     0,     0,     6,     8,     0,     0,
       0,    49,    48,     0,    37,    37,    87,     0,    81,     0,
      37,    27,    25,    19,    23,    17,    21,    29,    31,    33,
      35,    51,     0,     0,     0,     0,     0,    57,     0,    37,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
      37,    76,    83,     0,    82,     0,    28,    26,    20,    24,
      18,    22,    30,    32,    34,    36,    56,    38,    40,    42,
      44,    46,    63,     0,     7,    84,     0,    53,    52,     0,
       0,    59,    89,    78,    79,    77,     0,     0,     7,    61,
      58,    68,    60,    85,    50,    54,     0,     0,    55,     7,
       7,    73,    74,    66,    72,    64,    62,    63,    70,    69,
       0,    67,     0,    63,    71,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,    99,  -149,  -149,   -21,    80,  -119,   -43,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -148,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,   -36,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   -20,
    -149,  -149,  -149,  -149,  -149,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    13,   151,    32,    33,    54,    87,    85,
      88,    86,    84,    83,    89,    90,    91,    92,    72,    73,
      74,    75,    76,    34,    35,    93,   128,   138,   148,    36,
      99,   130,   131,   146,   156,   160,   157,   142,   147,   159,
     162,   153,    37,    38,   124,   135,    39,    49,    80,   104,
     136,    40,    45,    78,   123,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    55,    51,    52,     7,   134,   102,    69,    70,   161,
      60,     5,     6,   103,    79,   165,     1,     8,     2,    24,
       9,    25,    11,    26,    27,   -75,    12,    28,    53,    29,
     152,   152,    14,    15,    30,   100,    67,    68,    69,    70,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      16,   117,   118,   119,   120,   121,    31,    22,    24,    17,
      25,    18,    26,    27,    19,    20,    28,    21,    29,    22,
      42,    46,   116,    30,    24,    43,    25,    50,    26,    27,
     -75,    44,    28,    48,    29,    56,    57,    58,    81,    30,
      96,    59,    95,    94,   105,    31,    22,   122,   125,    97,
     126,    98,   129,   133,   127,   137,   132,    10,   139,   141,
     155,    31,   158,    47,   154,     0,   143,   145,   -39,   -41,
     -43,   -45,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   -39,   -41,   -43,   -45,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   140,   144,   149,   150,     0,
     163,   164,     0,    77,   -39,   -41,   -43,   -45,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,    82,   -39,   -41,   -43,
     -45,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     -39,   -41,   -43,   -45,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,   -88,   -37,
     -39,   -41,   -43,   -45,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   -37,   -39,   -41,   -43,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   -37,
     -39,   -41,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   -37,   -39,     0,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   -37,
       0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      21,    44,    24,    25,     0,   124,    47,    41,    42,   157,
      53,    25,     7,    54,    57,   163,     4,    47,     6,    10,
      25,    12,    48,    14,    15,    16,     6,    18,    50,    20,
     149,   150,     5,    49,    25,    78,    39,    40,    41,    42,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      12,    94,    95,    96,    97,    98,    47,    48,    10,     9,
      12,    50,    14,    15,     3,     8,    18,    51,    20,    48,
      52,    49,    93,    25,    10,    50,    12,    11,    14,    15,
      16,    50,    18,    16,    20,    27,    50,    25,    13,    25,
      30,    52,    29,    28,    50,    47,    48,    48,    25,    31,
      17,    32,    21,   124,    19,    51,    47,     8,    24,    23,
      22,    47,    22,    33,   150,    -1,   136,   138,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    35,    36,    37,    38,    39,    40,    41,    42,
      51,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    49,    47,    53,    53,    -1,
      47,    47,    -1,    51,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    28,    29,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,    56,    57,    25,     7,     0,    47,    25,
      56,    48,     6,    58,     5,    49,    12,     9,    50,     3,
       8,    51,    48,    59,    10,    12,    14,    15,    18,    20,
      25,    47,    60,    61,    78,    79,    84,    97,    98,   101,
     106,   110,    52,    50,    50,   107,    49,    60,    16,   102,
      11,    24,    25,    50,    62,    62,    27,    50,    25,    52,
      62,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    51,    73,    74,    75,    76,    77,    51,   108,    62,
     103,    13,    51,    68,    67,    64,    66,    63,    65,    69,
      70,    71,    72,    80,    28,    29,    30,    31,    32,    85,
      62,    51,    47,    54,   104,    50,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    59,    62,    62,    62,
      62,    62,    48,   109,    99,    25,    17,    19,    81,    21,
      86,    87,    47,    59,    61,   100,   105,    51,    82,    24,
      49,    23,    92,   104,    47,    59,    88,    93,    83,    53,
      53,    59,    61,    96,    96,    22,    89,    91,    22,    94,
      90,    87,    95,    47,    47,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    63,    62,    64,
      62,    65,    62,    66,    62,    67,    62,    68,    62,    69,
      62,    70,    62,    71,    62,    72,    62,    73,    62,    74,
      62,    75,    62,    76,    62,    77,    62,    62,    62,    62,
      78,    80,    79,    82,    83,    81,    81,    85,    84,    86,
      86,    88,    87,    87,    90,    89,    91,    89,    93,    92,
      95,    94,    94,    96,    96,    98,    99,    97,   100,   100,
     102,   103,   101,   104,   105,   104,   107,   108,   109,   106,
     110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     6,     9,     3,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     3,     1,     1,
       9,     0,     7,     0,     0,     4,     0,     0,     8,     1,
       2,     0,     6,     0,     0,     4,     0,     2,     0,     5,
       0,     3,     0,     1,     1,     0,     0,     7,     1,     1,
       0,     0,     5,     1,     0,     4,     0,     0,     0,     7,
       1,     1,     1
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
#line 99 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-3].keyname));keywordstable((yyvsp[-2].idname));}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-5].keyname));keywordstable((yyvsp[-4].keyname));}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-8].keyname));keywordstable((yyvsp[-7].keyname));keywordstable((yyvsp[-6].keyname));keywordstable((yyvsp[-5].keyname));}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 126 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 126 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 127 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 127 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 128 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 128 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 129 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 129 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 130 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 131 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 131 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 132 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "try_symb.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 133 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 133 "try_symb.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 134 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "try_symb.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 135 "try_symb.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 136 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 137 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 137 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 138 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 138 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 139 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 140 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 140 "try_symb.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "try_symb.y" /* yacc.c:1646  */
    {check();push();}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 143 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 146 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-8].keyname));keywordstable((yyvsp[-6].keyname));keywordstable((yyvsp[-4].keyname));}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "try_symb.y" /* yacc.c:1646  */
    {if_label1();}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 149 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-6].keyname));}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 151 "try_symb.y" /* yacc.c:1646  */
    {if_label2();}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 151 "try_symb.y" /* yacc.c:1646  */
    {if_label3();}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 151 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-3].keyname));}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 152 "try_symb.y" /* yacc.c:1646  */
    {if_label3();}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 155 "try_symb.y" /* yacc.c:1646  */
    {switch_start();}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 155 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-7].keyname));}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 157 "try_symb.y" /* yacc.c:1646  */
    {switch_end();}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 158 "try_symb.y" /* yacc.c:1646  */
    {switch_end();}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 161 "try_symb.y" /* yacc.c:1646  */
    {switch_case();}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 161 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-5].keyname));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 164 "try_symb.y" /* yacc.c:1646  */
    {switch_break();}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 164 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-3].keyname));}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 165 "try_symb.y" /* yacc.c:1646  */
    {switch_nobreak();}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "try_symb.y" /* yacc.c:1646  */
    {switch_default();}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 168 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-4].keyname));}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 171 "try_symb.y" /* yacc.c:1646  */
    {switch_break();}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 171 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-2].keyname));}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 181 "try_symb.y" /* yacc.c:1646  */
    {while_start();}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 181 "try_symb.y" /* yacc.c:1646  */
    {while_rep();}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 181 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[-5].keyname));}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 184 "try_symb.y" /* yacc.c:1646  */
    {while_end();}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 185 "try_symb.y" /* yacc.c:1646  */
    {while_end();}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 189 "try_symb.y" /* yacc.c:1646  */
    {setType();}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 189 "try_symb.y" /* yacc.c:1646  */
    {STMT_DECLARE();}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 194 "try_symb.y" /* yacc.c:1646  */
    {STMT_DECLARE();}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 198 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 198 "try_symb.y" /* yacc.c:1646  */
    {push();}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 198 "try_symb.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 202 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[0].typename));}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 203 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[0].keyname));}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 204 "try_symb.y" /* yacc.c:1646  */
    {keywordstable((yyvsp[0].typename));}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1914 "y.tab.c" /* yacc.c:1646  */
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
#line 207 "try_symb.y" /* yacc.c:1906  */


#include <ctype.h>
#include"lex.yy.c"
int count=0;

char st[1000][10];
int top=0;
int i=0;
char tmp[2]="t";

int label[200];
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];
struct Table
{
	char id[20];
	char type[10];
}table[10000];
int tableCount=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	f1=fopen("output","w");
	
   if(!yyparse())
		printf("\n\n\nParsing Successfull\n\n");
	else
	{
		printf("\nParsing failed\n");
		exit(0);
	}
	
	fclose(yyin);
	fclose(f1);
	displaykeywordtokens();
    	displayidenttokens();
	intermediateCode();
    return 0;
}
         
int yyerror(const char *msg)
{
	printf("\n\n\n\n\nParsing Failed\nLine Number: %d  : %s\n",yylineno,msg);
//	success = 0;
	return 0;

}
    
push()
{
  	strcpy(st[++top],yytext);
}

codegen_logical()
{
 	sprintf(tmp,"$t%d",i);
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",tmp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],tmp);
 	i++;
}

codegen_algebric()
{
 	sprintf(tmp,"$t%d",i); // converts tmp to reqd format
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",tmp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],tmp);
 	i++;
}
codegen_assign()
{
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
 	top-=3;
}
 
if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	label[++ltop]=lnum;
}

if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	top--;
}
while_start()
{
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
}

while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}
while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	top--;
}
switch_start()
{
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
}
switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
 	}
}
switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
}
switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
}
switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	top--;
	stop--;
}


/* for symbol table*/

check()
{
	char tmp[20];
	strcpy(tmp,yytext);
	int flag=0;
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,tmp))
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		yyerror("Variable not declard");
		exit(0);
	}
}

setType()
{
	strcpy(type,yytext);
}


STMT_DECLARE()
{
	char tmp[20];
	int i,flag;
	flag=0;
	strcpy(tmp,yytext);
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,tmp))
			{
			flag=1;
			break;
				}
	}
	if(flag)
	{
		yyerror("reSTMT_DECLARE of ");
		exit(0);
	}
	else
	{
		strcpy(table[tableCount].id,tmp);
		strcpy(table[tableCount].type,type);
		tableCount++;
	}
}

intermediateCode()
{
	int Labels[100000];
	char buf[100];
	f1=fopen("output","r");
	int flag=0,lineno=1;
	memset(Labels,0,sizeof(Labels));
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			int k=atoi(&buf[3]);
			//printf("hi %d\n",k);
			Labels[k]=lineno;
		}
		else
		{
			lineno++;
		}
	}
	fclose(f1);
	f1=fopen("output","r");
	lineno=0;

	printf("\n\n\n*********************InterMediate Code***************************\n\n");
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			;
		}
		else
		{
			flag=0;
			lineno++;
			printf("%3d:\t",lineno);
			int len=strlen(buf),i,flag1=0;
			for(i=len-3;i>=0;i--)
			{
				if(buf[i]=='$'&&buf[i+1]=='$'&&buf[i+2]=='L')
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				buf[i]=='\0';
				int k=atoi(&buf[i+3]),j;
				//printf("%s",buf);
				for(j=0;j<i;j++)
					printf("%c",buf[j]);
				printf(" %d\n",Labels[k]);
			}
			else printf("%s",buf);
		}
	}
	printf("%3d:\tend\n",++lineno);
	fclose(f1);
}
