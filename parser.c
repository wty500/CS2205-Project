/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "lang.y"

	// this part is copied to the beginning of the parser 
	#include <stdio.h>
	#include "lang.h"
	#include "lexer.h"
	void yyerror(char *);
	int yylex(void);
        struct glob_item_list * root;

/* Line 371 of yacc.c  */
#line 78 "parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TM_NAT = 258,
     TM_IDENT = 259,
     TM_LEFT_BRACE = 260,
     TM_RIGHT_BRACE = 261,
     TM_LEFT_PAREN = 262,
     TM_RIGHT_PAREN = 263,
     TM_SEMICOL = 264,
     TM_COMMA = 265,
     TM_FUNC_DEF = 266,
     TM_PROC_DEF = 267,
     TM_CONTINUE = 268,
     TM_BREAK = 269,
     TM_RETURN = 270,
     TM_INT = 271,
     TM_IF = 272,
     TM_THEN = 273,
     TM_ELSE = 274,
     TM_WHILE = 275,
     TM_DO = 276,
     TM_FOR = 277,
     TM_ASGNOP = 278,
     TM_OR = 279,
     TM_AND = 280,
     TM_NOT = 281,
     TM_LT = 282,
     TM_LE = 283,
     TM_GT = 284,
     TM_GE = 285,
     TM_EQ = 286,
     TM_NE = 287,
     TM_PLUS = 288,
     TM_MINUS = 289,
     TM_MUL = 290,
     TM_DIV = 291,
     TM_MOD = 292,
     TM_UMINUS = 293,
     TM_DEREF = 294,
     TM_ADDR_OF = 295
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 11 "lang.y"

unsigned int n;
char * i;
struct expr * e;
struct type * t;
struct type_list * tl;
struct ptr_num * pn;
struct expr_list * el;
struct var_list * vl;
struct glob_item * gi;
struct glob_item_list * gil;
struct cmd * c;
void * none;


/* Line 387 of yacc.c  */
#line 177 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 205 "parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    13,    16,    20,    22,
      24,    32,    35,    37,    42,    45,    49,    51,    54,    63,
      72,    80,    89,    97,   106,   111,   122,   133,   137,   141,
     154,   163,   177,   186,   190,   195,   197,   199,   201,   203,
     207,   209,   213,   218,   221,   223,   225,   228,   231,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    50,     9,    43,    -1,    50,
      -1,    35,    -1,    44,    35,    -1,    46,    10,    45,    -1,
      46,    -1,    47,    -1,    46,     7,    44,     8,     7,    45,
       8,    -1,    47,    35,    -1,    16,    -1,    47,     4,    10,
      48,    -1,    47,     4,    -1,    54,    10,    49,    -1,    54,
      -1,    47,     4,    -1,    46,     7,    44,     4,     8,     7,
      45,     8,    -1,    12,     7,    44,     4,     8,     7,    45,
       8,    -1,    46,     4,     7,     8,     5,    51,     6,    -1,
      46,     4,     7,    48,     8,     5,    51,     6,    -1,    12,
       4,     7,     8,     5,    51,     6,    -1,    12,     4,     7,
      48,     8,     5,    51,     6,    -1,    47,     4,     9,    51,
      -1,    46,     7,    44,     4,     8,     7,    45,     8,     9,
      51,    -1,    12,     7,    44,     4,     8,     7,    45,     8,
       9,    51,    -1,    54,    23,    54,    -1,    51,     9,    51,
      -1,    17,     7,    54,     8,    18,     5,    51,     6,    19,
       5,    51,     6,    -1,    20,     7,    54,     8,    21,     5,
      51,     6,    -1,    22,     5,    51,     6,     7,    54,     8,
       5,    51,     6,     5,    51,     6,    -1,    21,     5,    51,
       6,    20,     7,    54,     8,    -1,     4,     7,     8,    -1,
       4,     7,    49,     8,    -1,    14,    -1,    13,    -1,    15,
      -1,     3,    -1,     7,    54,     8,    -1,     4,    -1,     4,
       7,     8,    -1,     4,     7,    49,     8,    -1,    26,    54,
      -1,    52,    -1,    53,    -1,    34,    54,    -1,    35,    54,
      -1,    40,    54,    -1,    54,    35,    54,    -1,    54,    33,
      54,    -1,    54,    34,    54,    -1,    54,    36,    54,    -1,
      54,    37,    54,    -1,    54,    27,    54,    -1,    54,    29,
      54,    -1,    54,    28,    54,    -1,    54,    30,    54,    -1,
      54,    31,    54,    -1,    54,    32,    54,    -1,    54,    25,
      54,    -1,    54,    24,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    83,    87,    94,    98,   104,   108,   115,
     119,   126,   130,   139,   143,   150,   154,   161,   165,   169,
     173,   177,   181,   185,   192,   196,   200,   204,   208,   212,
     216,   220,   224,   228,   232,   236,   240,   244,   261,   265,
     269,   273,   277,   284,   288,   296,   300,   304,   308,   312,
     316,   320,   324,   328,   332,   336,   340,   344,   348,   352,
     356,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TM_NAT", "TM_IDENT", "TM_LEFT_BRACE",
  "TM_RIGHT_BRACE", "TM_LEFT_PAREN", "TM_RIGHT_PAREN", "TM_SEMICOL",
  "TM_COMMA", "TM_FUNC_DEF", "TM_PROC_DEF", "TM_CONTINUE", "TM_BREAK",
  "TM_RETURN", "TM_INT", "TM_IF", "TM_THEN", "TM_ELSE", "TM_WHILE",
  "TM_DO", "TM_FOR", "TM_ASGNOP", "TM_OR", "TM_AND", "TM_NOT", "TM_LT",
  "TM_LE", "TM_GT", "TM_GE", "TM_EQ", "TM_NE", "TM_PLUS", "TM_MINUS",
  "TM_MUL", "TM_DIV", "TM_MOD", "TM_UMINUS", "TM_DEREF", "TM_ADDR_OF",
  "$accept", "NT_WHOLE", "NT_GLOBAL_ITEM_LIST", "NT_PTR_NUM",
  "NT_TYPE_LIST", "NT_TYPE", "NT_TYPE1", "NT_VAR_LIST", "NT_EXPR_LIST",
  "NT_GLOBAL_ITEM", "NT_CMD", "NT_EXPR0", "NT_EXPR1", "NT_EXPR", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       7,     2,     1,     4,     2,     3,     1,     2,     8,     8,
       7,     8,     7,     8,     4,    10,    10,     3,     3,    12,
       8,    13,     8,     3,     4,     1,     1,     1,     1,     3,
       1,     3,     4,     2,     1,     1,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,     0,     2,     0,     9,     4,     0,     0,
       1,     0,     0,    17,    11,     0,     0,     5,     0,     0,
       0,     3,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,    38,
      40,     0,     0,    36,    35,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,     0,
      40,     0,     0,     0,     0,     0,     0,    43,    46,    47,
      48,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    20,     0,     0,    10,     0,     0,    41,     0,
      16,     0,    39,     0,     0,     0,     0,     0,     0,     0,
      28,    27,    61,    60,    54,    56,    55,    57,    58,    59,
      50,    51,    49,    52,    53,    23,    19,    21,    18,     0,
       7,    42,     0,    41,     0,     0,     0,     0,     0,     0,
       0,    24,    15,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    32,     0,     0,     0,     0,
       0,     0,    26,     0,     0,    25,     0,     0,    29,     0,
      31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    18,    66,    54,    55,    24,   109,     7,
      56,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
      -7,     3,   -60,    25,   -60,     7,     9,    17,    30,    12,
     -60,    54,    12,   -60,   -60,    -7,    13,   -60,    14,    79,
       4,   -60,    78,    16,    80,    95,   -60,    99,   110,   115,
     119,   117,   125,   131,   133,   117,   163,   143,   140,   -60,
     171,   168,   176,   -60,   -60,   -60,   177,   180,   183,   184,
     168,   168,   168,   168,   188,    19,    37,   -60,   -60,   280,
     140,   117,   140,    57,   117,   140,   182,    82,   161,   151,
     190,   185,    12,   168,   168,   117,   117,   -60,   -60,   -60,
     -60,    12,   189,   -60,   117,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   -60,
      84,   191,   -60,    96,   196,   -60,    12,   140,   102,   197,
     265,   166,   -60,    49,   199,   217,   104,   106,    24,   117,
     202,   294,   307,   318,    63,    63,    63,    63,    63,    63,
     145,   145,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    23,
     -60,   108,   168,   -60,   229,   230,   222,   248,   223,   263,
     264,   202,   -60,   -60,   281,   266,   282,   284,   168,   299,
     140,   117,   117,   168,   231,   140,   312,   113,   139,   249,
     328,   348,   349,   338,   -60,   -60,   117,   350,   117,   355,
     155,   117,   202,   117,   356,   202,   157,   117,   -60,   170,
     -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   347,    10,   -59,     2,     0,   -15,   -56,   -60,
     -34,   -60,   -60,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -35
static const yytype_int16 yytable[] =
{
       6,    63,     5,   101,    28,     1,   104,     8,    29,     2,
       9,    11,    30,    13,    12,     6,    23,     5,    25,    23,
      32,    22,    20,    82,    71,    10,    15,   100,   150,     2,
     103,    30,    30,    77,    78,    79,    80,    16,    68,    26,
      67,   116,   117,    83,    14,    99,    84,    17,   140,    26,
     120,    14,   110,   145,    14,   144,   114,   115,    26,    26,
      23,    19,    68,   102,    67,    68,    84,    67,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   113,    31,    26,   151,   152,    27,    33,   106,
     135,   118,   107,    84,   110,     2,    94,    95,    96,    97,
      98,   166,   137,    34,    35,    84,   171,    68,   -33,    67,
     148,   -33,   149,    84,   -34,    84,   139,   -34,    36,   173,
      39,    40,    84,    37,    41,   110,    38,   167,   168,    42,
      43,    44,    45,     2,    46,    60,    61,    47,    48,    49,
      62,   164,   180,    50,   182,   174,   169,   185,    84,   186,
      65,    51,    52,   189,    39,    70,     2,    53,    41,   108,
      68,   184,    67,   188,    84,    68,    84,    67,    64,    39,
      70,    39,    70,    41,   143,    41,   190,    50,    69,    84,
      96,    97,    98,    72,    73,    51,    52,    74,    75,    76,
     105,    53,    50,   112,    50,    81,    14,   111,   119,   136,
      51,    52,    51,    52,   138,   141,    53,   146,    53,    86,
      87,    84,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    86,    87,   147,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   153,   154,   170,
     155,    86,    87,   157,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    86,    87,   175,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   156,
     158,   161,   159,    86,    87,   142,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   162,   160,    86,
      87,   163,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    85,    86,    87,   165,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    86,    87,
     172,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    87,   176,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   177,   179,   178,   181,
     183,   187,    21
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       0,    35,     0,    62,    19,    12,    65,     4,     4,    16,
       7,     4,     8,     4,     7,    15,    16,    15,     4,    19,
       4,     8,    12,     4,    41,     0,     9,    61,     4,    16,
      64,     8,     8,    50,    51,    52,    53,     7,    38,    35,
      38,    75,    76,     6,    35,    60,     9,    35,   107,    35,
      84,    35,    69,     4,    35,   111,    73,    74,    35,    35,
      60,     7,    62,     6,    62,    65,     9,    65,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    72,     5,    35,   119,   142,     8,     8,     7,
       6,    81,    10,     9,   111,    16,    33,    34,    35,    36,
      37,   160,     6,     8,     5,     9,   165,   107,     6,   107,
       6,     9,     6,     9,     6,     9,   106,     9,     8,     6,
       3,     4,     9,     8,     7,   142,     7,   161,   162,    12,
      13,    14,    15,    16,    17,    10,     5,    20,    21,    22,
       7,   158,   176,    26,   178,     6,   163,   181,     9,   183,
       7,    34,    35,   187,     3,     4,    16,    40,     7,     8,
     160,     6,   160,     6,     9,   165,     9,   165,     5,     3,
       4,     3,     4,     7,     8,     7,     6,    26,     7,     9,
      35,    36,    37,     7,     7,    34,    35,     7,     5,     5,
       8,    40,    26,     8,    26,     7,    35,     7,     9,     8,
      34,    35,    34,    35,     8,     8,    40,     8,    40,    24,
      25,     9,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    24,    25,     8,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     8,     8,     8,
      18,    24,    25,    20,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    24,    25,     8,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    21,
       7,     5,     8,    24,    25,    10,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     5,     7,    24,
      25,     7,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    23,    24,    25,     7,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    24,    25,
       8,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    25,     5,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     8,    19,     9,     9,
       5,     5,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    16,    42,    43,    46,    47,    50,     4,     7,
       0,     4,     7,     4,    35,     9,     7,    35,    44,     7,
      44,    43,     8,    47,    48,     4,    35,     8,    48,     4,
       8,     5,     4,     8,     8,     5,     8,     8,     7,     3,
       4,     7,    12,    13,    14,    15,    17,    20,    21,    22,
      26,    34,    35,    40,    46,    47,    51,    52,    53,    54,
      10,     5,     7,    51,     5,     7,    45,    46,    47,     7,
       4,    54,     7,     7,     7,     5,     5,    54,    54,    54,
      54,     7,     4,     6,     9,    23,    24,    25,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    48,
      51,    45,     6,    51,    45,     8,     7,    10,     8,    49,
      54,     7,     8,    44,    54,    54,    51,    51,    44,     9,
      51,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,     6,     8,     6,     8,    44,
      45,     8,    10,     8,    49,     4,     8,     8,     6,     6,
       4,    51,    49,     8,     8,    18,    21,    20,     7,     8,
       7,     5,     5,     7,    54,     7,    45,    51,    51,    54,
       8,    45,     8,     6,     6,     8,     5,     8,     9,    19,
      51,     9,    51,     5,     6,    51,    51,     5,     6,    51,
       6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 76 "lang.y"
    {
    (yyval.gil) = ((yyvsp[(1) - (1)].gil));
    root = (yyval.gil);
  }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 84 "lang.y"
    {
    (yyval.gil) = (TGCons((yyvsp[(1) - (3)].gi),(yyvsp[(3) - (3)].gil)));
  }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 88 "lang.y"
    {
    (yyval.gil) = (TGCons((yyvsp[(1) - (1)].gi),TGNil()));
  }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 95 "lang.y"
    {
  (yyval.pn) = (TPtr_num());
  }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 99 "lang.y"
    {
  (yyval.pn) = (TPtr_num_1((yyvsp[(1) - (2)].pn)));
  }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 105 "lang.y"
    {
    (yyval.tl) = (TTCons((yyvsp[(1) - (3)].t),(yyvsp[(3) - (3)].tl)));
  }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 109 "lang.y"
    {
    (yyval.tl) = (TTCons((yyvsp[(1) - (1)].t),TTNil()));
  }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 116 "lang.y"
    {
    (yyval.t) = ((yyvsp[(1) - (1)].t));
  }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 120 "lang.y"
    {
    (yyval.t) = (TPtr_func((yyvsp[(1) - (7)].t),(yyvsp[(3) - (7)].pn),(yyvsp[(6) - (7)].tl)));
  }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 127 "lang.y"
    {
    (yyval.t) = (TPtr_int_1((yyvsp[(1) - (2)].t)));
  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 131 "lang.y"
    {
    (yyval.t) = (TPtr_int());
  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 140 "lang.y"
    {
    (yyval.vl) = (TVCons((yyvsp[(1) - (4)].t),(yyvsp[(2) - (4)].i),(yyvsp[(4) - (4)].vl)));
  }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 144 "lang.y"
    {
    (yyval.vl) = (TVCons((yyvsp[(1) - (2)].t),(yyvsp[(2) - (2)].i),TVNil()));
  }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 151 "lang.y"
    {
    (yyval.el) = (TECons((yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].el)));
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 155 "lang.y"
    {
    (yyval.el) = (TECons((yyvsp[(1) - (1)].e),TENil()));
  }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 162 "lang.y"
    {
    (yyval.gi) = (TGlobVar((yyvsp[(1) - (2)].t),(yyvsp[(2) - (2)].i)));
  }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 166 "lang.y"
    {
    (yyval.gi) = (TGlobVar_1((yyvsp[(1) - (8)].t),(yyvsp[(3) - (8)].pn),(yyvsp[(7) - (8)].tl),(yyvsp[(4) - (8)].i)));
  }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 170 "lang.y"
    {
    (yyval.gi) = (TGlobVar_2((yyvsp[(3) - (8)].pn),(yyvsp[(7) - (8)].tl),(yyvsp[(4) - (8)].i)));
  }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 174 "lang.y"
    {
    (yyval.gi) = (TFuncDef((yyvsp[(1) - (7)].t),(yyvsp[(2) - (7)].i),TVNil(),(yyvsp[(6) - (7)].c)));
  }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 178 "lang.y"
    {
    (yyval.gi) = (TFuncDef((yyvsp[(1) - (8)].t),(yyvsp[(2) - (8)].i),(yyvsp[(4) - (8)].vl),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 182 "lang.y"
    {
    (yyval.gi) = (TProcDef((yyvsp[(2) - (7)].i),TVNil(),(yyvsp[(6) - (7)].c)));
  }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 186 "lang.y"
    {
    (yyval.gi) = (TProcDef((yyvsp[(2) - (8)].i),(yyvsp[(4) - (8)].vl),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 193 "lang.y"
    {
    (yyval.c) = (TDecl((yyvsp[(1) - (4)].t),(yyvsp[(2) - (4)].i),(yyvsp[(4) - (4)].c)));
  }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 197 "lang.y"
    {
    (yyval.c) = (TDecl_1((yyvsp[(1) - (10)].t),(yyvsp[(3) - (10)].pn),(yyvsp[(7) - (10)].tl),(yyvsp[(4) - (10)].i),(yyvsp[(10) - (10)].c)));
  }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 201 "lang.y"
    {
    (yyval.c) = (TDecl_2((yyvsp[(3) - (10)].pn),(yyvsp[(7) - (10)].tl),(yyvsp[(4) - (10)].i),(yyvsp[(10) - (10)].c)));
  }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 205 "lang.y"
    {
    (yyval.c) = (TAsgn((yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 209 "lang.y"
    {
    (yyval.c) = (TSeq((yyvsp[(1) - (3)].c),(yyvsp[(3) - (3)].c)));
  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 213 "lang.y"
    {
    (yyval.c) = (TIf((yyvsp[(3) - (12)].e),(yyvsp[(7) - (12)].c),(yyvsp[(11) - (12)].c)));
  }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 217 "lang.y"
    {
    (yyval.c) = (TWhile((yyvsp[(3) - (8)].e),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 221 "lang.y"
    {
    (yyval.c) = (TFor((yyvsp[(3) - (13)].c),(yyvsp[(6) - (13)].e),(yyvsp[(9) - (13)].c),(yyvsp[(12) - (13)].c)));
  }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 225 "lang.y"
    {
    (yyval.c) = (TDoWhile((yyvsp[(3) - (8)].c),(yyvsp[(7) - (8)].e)));
  }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 229 "lang.y"
    {
    (yyval.c) = (TProc((yyvsp[(2) - (3)].none),TENil()));
  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 233 "lang.y"
    {
    (yyval.c) = (TProc((yyvsp[(2) - (4)].none),(yyvsp[(3) - (4)].el)));
  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 237 "lang.y"
    {
    (yyval.c) = (TBreak());
  }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 241 "lang.y"
    {
    (yyval.c) = (TContinue());
  }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 245 "lang.y"
    {
    (yyval.c) = (TReturn());
  }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 262 "lang.y"
    {
    (yyval.e) = (TConst((yyvsp[(1) - (1)].n)));
  }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 266 "lang.y"
    {
    (yyval.e) = ((yyvsp[(2) - (3)].e));
  }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 270 "lang.y"
    {
    (yyval.e) = (TVar((yyvsp[(1) - (1)].i)));
  }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 274 "lang.y"
    {
    (yyval.e) = (TFunc((yyvsp[(1) - (3)].i),TENil()));
  }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 278 "lang.y"
    {
    (yyval.e) = (TFunc((yyvsp[(1) - (4)].i),(yyvsp[(3) - (4)].el)));
  }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 285 "lang.y"
    {
    (yyval.e) = (TUnOp(T_NOT,(yyvsp[(2) - (2)].e)));
  }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 289 "lang.y"
    {
    (yyval.e) = ((yyvsp[(1) - (1)].e));
  }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 297 "lang.y"
    {
    (yyval.e) = ((yyvsp[(1) - (1)].e));
  }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 301 "lang.y"
    {
    (yyval.e) = (TUnOp(T_UMINUS,(yyvsp[(2) - (2)].e)));
  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 305 "lang.y"
    {
    (yyval.e) = (TDeref((yyvsp[(2) - (2)].e)));
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 309 "lang.y"
    {
    (yyval.e) = (TAddrOf((yyvsp[(2) - (2)].e)));
  }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 313 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MUL,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 317 "lang.y"
    {
    (yyval.e) = (TBinOp(T_PLUS,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 321 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MINUS,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 325 "lang.y"
    {
    (yyval.e) = (TBinOp(T_DIV,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 329 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MOD,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 333 "lang.y"
    {
    (yyval.e) = (TBinOp(T_LT,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 337 "lang.y"
    {
    (yyval.e) = (TBinOp(T_GT,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 341 "lang.y"
    {
    (yyval.e) = (TBinOp(T_LE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 345 "lang.y"
    {
    (yyval.e) = (TBinOp(T_GE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 349 "lang.y"
    {
    (yyval.e) = (TBinOp(T_EQ,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 353 "lang.y"
    {
    (yyval.e) = (TBinOp(T_NE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 357 "lang.y"
    {
    (yyval.e) = (TBinOp(T_AND,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 361 "lang.y"
    {
    (yyval.e) = (TBinOp(T_OR,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;


/* Line 1792 of yacc.c  */
#line 2060 "parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 367 "lang.y"


void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
