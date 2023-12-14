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
     TM_TEMPLATE = 266,
     TM_TYPENAME = 267,
     TM_VAR = 268,
     TM_PROC_DEF = 269,
     TM_CONTINUE = 270,
     TM_BREAK = 271,
     TM_RETURN = 272,
     TM_INT = 273,
     TM_IF = 274,
     TM_THEN = 275,
     TM_ELSE = 276,
     TM_WHILE = 277,
     TM_DO = 278,
     TM_FOR = 279,
     TM_ASGNOP = 280,
     TM_OR = 281,
     TM_AND = 282,
     TM_NOT = 283,
     TM_LT = 284,
     TM_LE = 285,
     TM_GT = 286,
     TM_GE = 287,
     TM_EQ = 288,
     TM_NE = 289,
     TM_PLUS = 290,
     TM_MINUS = 291,
     TM_MUL = 292,
     TM_DIV = 293,
     TM_MOD = 294,
     TM_UMINUS = 295,
     TM_DEREF = 296,
     TM_ADDR_OF = 297
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
// struct temp_var_list * tvl;
struct ptr_num * pn;
struct expr_list * el;
struct var_list * vl;
struct type_name_list * tnl;
struct glob_item * gi;
struct glob_item_list * gil;
struct cmd * c;
void * none;


/* Line 387 of yacc.c  */
#line 181 "parser.c"
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
#line 209 "parser.c"

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    13,    16,    20,    22,
      24,    32,    40,    42,    44,    47,    49,    52,    54,    59,
      62,    66,    68,    73,    76,    80,    89,    99,   108,   118,
     130,   143,   155,   168,   176,   185,   193,   202,   208,   219,
     231,   242,   254,   258,   262,   275,   284,   298,   307,   311,
     316,   318,   320,   322,   324,   328,   330,   334,   339,   342,
     344,   346,   349,   352,   355,   359,   363,   367,   371,   375,
     379,   383,   387,   391,   395,   399,   403
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    55,     9,    45,    -1,    55,
      -1,    37,    -1,    46,    37,    -1,    48,    10,    47,    -1,
      48,    -1,    49,    -1,    48,     7,    46,     8,     7,    47,
       8,    -1,    14,     7,    46,     8,     7,    47,     8,    -1,
      50,    -1,    51,    -1,    50,    37,    -1,    18,    -1,    51,
      37,    -1,     4,    -1,    49,     4,    10,    52,    -1,    49,
       4,    -1,    59,    10,    53,    -1,    59,    -1,    12,     4,
      10,    54,    -1,    12,     4,    -1,    13,    49,     4,    -1,
      13,    48,     7,    46,     4,     8,     7,     8,    -1,    13,
      48,     7,    46,     4,     8,     7,    47,     8,    -1,    13,
      14,     7,    46,     4,     8,     7,     8,    -1,    13,    14,
       7,    46,     4,     8,     7,    47,     8,    -1,    11,    29,
      54,    31,    48,     4,     7,     8,     5,    56,     6,    -1,
      11,    29,    54,    31,    48,     4,     7,    52,     8,     5,
      56,     6,    -1,    11,    29,    54,    31,    14,     4,     7,
       8,     5,    56,     6,    -1,    11,    29,    54,    31,    14,
       4,     7,    52,     8,     5,    56,     6,    -1,    48,     4,
       7,     8,     5,    56,     6,    -1,    48,     4,     7,    52,
       8,     5,    56,     6,    -1,    14,     4,     7,     8,     5,
      56,     6,    -1,    14,     4,     7,    52,     8,     5,    56,
       6,    -1,    13,    49,     4,     9,    56,    -1,    13,    48,
       7,    46,     4,     8,     7,     8,     9,    56,    -1,    13,
      48,     7,    46,     4,     8,     7,    47,     8,     9,    56,
      -1,    13,    14,     7,    46,     4,     8,     7,     8,     9,
      56,    -1,    13,    14,     7,    46,     4,     8,     7,    47,
       8,     9,    56,    -1,    59,    25,    59,    -1,    56,     9,
      56,    -1,    19,     7,    59,     8,    20,     5,    56,     6,
      21,     5,    56,     6,    -1,    22,     7,    59,     8,    23,
       5,    56,     6,    -1,    24,     5,    56,     6,     7,    59,
       8,     5,    56,     6,     5,    56,     6,    -1,    23,     5,
      56,     6,    22,     7,    59,     8,    -1,     4,     7,     8,
      -1,     4,     7,    53,     8,    -1,    16,    -1,    15,    -1,
      17,    -1,     3,    -1,     7,    59,     8,    -1,     4,    -1,
       4,     7,     8,    -1,     4,     7,    53,     8,    -1,    28,
      59,    -1,    57,    -1,    58,    -1,    36,    59,    -1,    37,
      59,    -1,    42,    59,    -1,    59,    37,    59,    -1,    59,
      35,    59,    -1,    59,    36,    59,    -1,    59,    38,    59,
      -1,    59,    39,    59,    -1,    59,    29,    59,    -1,    59,
      31,    59,    -1,    59,    30,    59,    -1,    59,    32,    59,
      -1,    59,    33,    59,    -1,    59,    34,    59,    -1,    59,
      27,    59,    -1,    59,    26,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    90,    94,   101,   105,   111,   115,   122,
     126,   130,   137,   141,   148,   152,   159,   163,   171,   175,
     201,   205,   212,   216,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   322,   326,
     330,   334,   338,   355,   359,   363,   367,   371,   378,   382,
     390,   394,   398,   402,   406,   410,   414,   418,   422,   426,
     430,   434,   438,   442,   446,   450,   454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TM_NAT", "TM_IDENT", "TM_LEFT_BRACE",
  "TM_RIGHT_BRACE", "TM_LEFT_PAREN", "TM_RIGHT_PAREN", "TM_SEMICOL",
  "TM_COMMA", "TM_TEMPLATE", "TM_TYPENAME", "TM_VAR", "TM_PROC_DEF",
  "TM_CONTINUE", "TM_BREAK", "TM_RETURN", "TM_INT", "TM_IF", "TM_THEN",
  "TM_ELSE", "TM_WHILE", "TM_DO", "TM_FOR", "TM_ASGNOP", "TM_OR", "TM_AND",
  "TM_NOT", "TM_LT", "TM_LE", "TM_GT", "TM_GE", "TM_EQ", "TM_NE",
  "TM_PLUS", "TM_MINUS", "TM_MUL", "TM_DIV", "TM_MOD", "TM_UMINUS",
  "TM_DEREF", "TM_ADDR_OF", "$accept", "NT_WHOLE", "NT_GLOBAL_ITEM_LIST",
  "NT_PTR_NUM", "NT_TYPE_LIST", "NT_TYPE", "NT_TYPE1", "NT_intTYPE",
  "NT_TTYPE", "NT_VAR_LIST", "NT_EXPR_LIST", "NT_TYPENAME_LIST",
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       7,     7,     1,     1,     2,     1,     2,     1,     4,     2,
       3,     1,     4,     2,     3,     8,     9,     8,     9,    11,
      12,    11,    12,     7,     8,     7,     8,     5,    10,    11,
      10,    11,     3,     3,    12,     8,    13,     8,     3,     4,
       1,     1,     1,     1,     3,     1,     3,     4,     2,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,     0,     0,     0,    15,     0,     2,     0,     9,
      12,    13,     4,     0,     0,     0,     9,     0,     0,     1,
       0,     0,    14,    16,     0,     0,     0,     0,     0,    24,
       0,     5,     0,     0,     0,     3,    23,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,    53,    55,     0,     0,    51,
      50,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     9,     0,     0,     0,     0,    58,    61,    62,    63,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    11,     0,
      33,     0,    10,     0,     0,     0,     0,    27,     0,    25,
       0,    56,     0,    21,     0,    54,     0,     0,     0,     0,
       0,     0,     0,    43,    42,    76,    75,    69,    71,    70,
      72,    73,    74,    65,    66,    64,    67,    68,    36,     7,
      34,     0,     0,     0,     0,    28,    26,    57,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    57,     0,     0,    37,     0,     0,     0,
       0,    31,     0,    29,     0,     0,     0,     0,     0,     0,
       0,    32,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    47,     0,     0,     0,     0,
       0,     0,     0,    40,     0,    38,     0,     0,     0,    41,
      39,     0,     0,    44,     0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    32,    87,    88,     9,    10,    11,    42,
     142,    26,    12,    80,    81,    82,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -134
static const yytype_int16 yypact[] =
{
       1,  -134,   -16,     3,    98,  -134,    24,  -134,   103,  -134,
     -11,     6,    35,    39,    48,    50,    63,    61,    36,  -134,
      65,    36,  -134,  -134,     1,    87,    78,    36,    36,  -134,
      90,  -134,    -5,   107,    -2,  -134,    82,    38,    12,    23,
     112,   114,   130,   115,  -134,   137,   138,   141,    39,   132,
     150,   152,   153,   171,   156,   162,   127,   171,   186,   127,
    -134,   185,   193,   204,   235,  -134,   238,   161,   145,  -134,
    -134,  -134,   269,   277,   200,   274,   161,   161,   161,   161,
     167,  -134,  -134,   285,     0,   171,   291,   201,   194,   237,
     171,   305,   322,   323,    85,   129,    93,   325,   188,   331,
     337,   273,   161,   161,   171,   171,  -134,  -134,  -134,  -134,
    -134,   171,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,  -134,   241,  -134,   127,
    -134,   272,  -134,   352,   320,   400,   401,  -134,   402,  -134,
     403,   327,   404,   270,   116,  -134,    36,    36,   399,   202,
     222,   328,   379,   405,   316,   329,   340,   345,   345,   345,
     345,   345,   345,   144,   144,  -134,  -134,  -134,  -134,  -134,
    -134,   171,   408,   171,   410,  -134,  -134,   380,   161,  -134,
     409,    26,    58,   171,   396,   395,   406,   412,   381,   171,
     385,   171,  -134,  -134,   413,   414,   405,   415,   418,   417,
     161,  -134,   386,  -134,   387,   419,   420,   171,   171,   161,
     236,  -134,  -134,   198,   321,   391,   392,   256,   424,   416,
     422,   423,   425,   421,  -134,  -134,   171,   171,   426,   171,
     427,   429,   393,   405,   171,   405,   171,   171,   432,   405,
     405,   397,   171,  -134,   398,  -134
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   407,   -19,   -58,    22,    20,  -134,  -134,   -23,
    -133,   390,  -134,   -57,  -134,  -134,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      89,    91,    34,    43,     1,     1,    47,     1,    38,    39,
      46,   180,     2,    13,     3,     4,    51,    14,     5,     5,
      43,     5,     8,    16,    19,    15,    22,    52,   127,    98,
     194,    47,    44,   131,    43,    44,   138,   140,   106,   107,
     108,   109,     1,    23,    24,   192,     8,   151,   152,    44,
      41,    25,    49,    41,   153,    27,     5,    28,   143,    50,
      44,   126,   195,    44,   149,   150,    47,    29,    30,   134,
     136,   169,    33,    31,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   101,     1,
     100,    36,    48,   137,     1,    44,    65,    97,    40,    86,
      67,   141,    17,     5,    41,    18,   143,    20,     5,    37,
      21,     1,    41,    41,   188,    45,   190,    53,    54,    65,
      97,    76,    56,    67,   179,     5,   196,   181,   182,    77,
      78,     1,   202,     1,   204,    79,    61,   139,    55,    18,
     143,    86,    57,    86,    76,     5,    58,     5,    59,     1,
     215,   216,    77,    78,    62,   220,   222,    21,    79,    99,
      63,    64,   210,     5,    65,    97,    84,    85,    67,   232,
     233,   217,   235,   110,    65,    66,   111,   239,    67,   240,
     241,   123,   124,   125,    68,   244,    69,    70,    71,    76,
      72,    90,    92,    73,    74,    75,   145,    77,    78,    76,
      93,    21,     1,    79,   129,   104,   219,    77,    78,   128,
     184,    94,    86,    79,   113,   114,     5,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   113,   114,
     185,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    95,   130,   218,    96,   111,   168,   113,   114,
     111,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   113,   114,   225,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   102,   148,   170,   105,
     178,   111,   113,   114,   103,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   113,   114,    18,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     112,   113,   114,   132,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     1,     1,     1,   172,   221,
     133,   135,   144,   -48,   186,    86,   -48,   111,   146,     5,
       5,     5,   113,   114,   147,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   114,   171,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     121,   122,   123,   124,   125,   187,   -49,   201,   111,   -49,
     111,   203,   211,   212,   111,   111,   111,   223,   224,   238,
     111,   111,   111,   243,   245,   173,   111,   111,   183,   174,
     175,   176,   177,   189,   111,   191,   197,   193,   198,   200,
     207,   205,   206,   208,   209,   227,   213,   214,   199,   226,
     228,    35,   229,   230,   237,   234,   236,   242,    60,     0,
       0,     0,   231
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      57,    59,    21,     8,     4,     4,     8,     4,    27,    28,
      33,   144,    11,    29,    13,    14,     4,    14,    18,    18,
       8,    18,     0,     3,     0,     3,    37,     4,    85,    67,
       4,     8,    37,    90,     8,    37,    94,    95,    76,    77,
      78,    79,     4,    37,     9,   178,    24,   104,   105,    37,
      30,    12,    14,    33,   111,     7,    18,     7,    96,    37,
      37,    84,     4,    37,   102,   103,     8,     4,     7,    92,
      93,   129,     7,    37,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    68,     4,
      68,     4,    10,     8,     4,    37,     3,     4,     8,    14,
       7,     8,     4,    18,    84,     7,   144,     4,    18,    31,
       7,     4,    92,    93,   171,     8,   173,     5,     4,     3,
       4,    28,     7,     7,     8,    18,   183,   146,   147,    36,
      37,     4,   189,     4,   191,    42,     4,     8,     8,     7,
     178,    14,     5,    14,    28,    18,     8,    18,     7,     4,
     207,   208,    36,    37,     4,   213,   214,     7,    42,    14,
       8,     8,   200,    18,     3,     4,    10,     5,     7,   226,
     227,   209,   229,     6,     3,     4,     9,   234,     7,   236,
     237,    37,    38,    39,    13,   242,    15,    16,    17,    28,
      19,     5,     7,    22,    23,    24,     8,    36,    37,    28,
       7,     7,     4,    42,    10,     5,     8,    36,    37,     8,
       8,     7,    14,    42,    26,    27,    18,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    26,    27,
       8,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     7,     6,     8,     7,     9,     6,    26,    27,
       9,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    26,    27,     8,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     7,     4,     6,     5,
      10,     9,    26,    27,     7,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    26,    27,     7,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      25,    26,    27,     8,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     4,     4,     4,     8,     8,
       8,     8,     7,     6,     6,    14,     9,     9,     7,    18,
      18,    18,    26,    27,     7,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    27,     5,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      35,    36,    37,    38,    39,     6,     6,     6,     9,     9,
       9,     6,     6,     6,     9,     9,     9,     6,     6,     6,
       9,     9,     9,     6,     6,     5,     9,     9,     9,     8,
       8,     8,     8,     5,     9,     5,    20,     8,    23,     7,
       5,     8,     8,     5,     7,     9,     7,     7,    22,     5,
       8,    24,     9,     8,     5,     9,     9,     5,    48,    -1,
      -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    11,    13,    14,    18,    44,    45,    48,    49,
      50,    51,    55,    29,    14,    48,    49,     4,     7,     0,
       4,     7,    37,    37,     9,    12,    54,     7,     7,     4,
       7,    37,    46,     7,    46,    45,     4,    31,    46,    46,
       8,    49,    52,     8,    37,     8,    52,     8,    10,    14,
      48,     4,     4,     5,     4,     8,     7,     5,     8,     7,
      54,     4,     4,     8,     8,     3,     4,     7,    13,    15,
      16,    17,    19,    22,    23,    24,    28,    36,    37,    42,
      56,    57,    58,    59,    10,     5,    14,    47,    48,    56,
       5,    47,     7,     7,     7,     7,     7,     4,    59,    14,
      48,    49,     7,     7,     5,     5,    59,    59,    59,    59,
       6,     9,    25,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    52,    56,     8,    10,
       6,    56,     8,     8,    52,     8,    52,     8,    47,     8,
      47,     8,    53,    59,     7,     8,     7,     7,     4,    59,
      59,    56,    56,    56,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,     6,    47,
       6,     5,     8,     5,     8,     8,     8,     8,    10,     8,
      53,    46,    46,     9,     8,     8,     6,     6,    56,     5,
      56,     5,    53,     8,     4,     4,    56,    20,    23,    22,
       7,     6,    56,     6,    56,     8,     8,     5,     5,     7,
      59,     6,     6,     7,     7,    56,    56,    59,     8,     8,
      47,     8,    47,     6,     6,     8,     5,     9,     8,     9,
       8,    21,    56,    56,     9,    56,     9,     5,     6,    56,
      56,    56,     5,     6,    56,     6
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
#line 83 "lang.y"
    {
    (yyval.gil) = ((yyvsp[(1) - (1)].gil));
    root = (yyval.gil);
  }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 91 "lang.y"
    {
    (yyval.gil) = (TGCons((yyvsp[(1) - (3)].gi),(yyvsp[(3) - (3)].gil)));
  }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 95 "lang.y"
    {
    (yyval.gil) = (TGCons((yyvsp[(1) - (1)].gi),TGNil()));
  }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 102 "lang.y"
    {
  (yyval.pn) = (TPtr_num());
  }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 106 "lang.y"
    {
  (yyval.pn) = (TPtr_num_1((yyvsp[(1) - (2)].pn)));
  }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 112 "lang.y"
    {
    (yyval.tl) = (TTCons((yyvsp[(1) - (3)].t),(yyvsp[(3) - (3)].tl)));
  }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 116 "lang.y"
    {
    (yyval.tl) = (TTCons((yyvsp[(1) - (1)].t),TTNil()));
  }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 123 "lang.y"
    {
    (yyval.t) = ((yyvsp[(1) - (1)].t));
  }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 127 "lang.y"
    {
    (yyval.t) = (TPtr_func((yyvsp[(1) - (7)].t),(yyvsp[(3) - (7)].pn),(yyvsp[(6) - (7)].tl)));
  }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 131 "lang.y"
    {
    (yyval.t) = (TPtr_proc((yyvsp[(3) - (7)].pn),(yyvsp[(6) - (7)].tl)));
  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 138 "lang.y"
    {
    (yyval.t) = ((yyvsp[(1) - (1)].t));
  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 142 "lang.y"
    {
    (yyval.t) = ((yyvsp[(1) - (1)].t));
  }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 149 "lang.y"
    {
    (yyval.t) = (TPtr_int_1((yyvsp[(1) - (2)].t)));
  }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 153 "lang.y"
    {
    (yyval.t) = (TPtr_int());
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 160 "lang.y"
    {
    (yyval.t) = (TPtr_T_1((yyvsp[(1) - (2)].t)));
  }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 164 "lang.y"
    {
    (yyval.t) = (TPtr_T((yyvsp[(1) - (1)].i)));
  }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 172 "lang.y"
    {
    (yyval.vl) = (TVCons((yyvsp[(1) - (4)].t),(yyvsp[(2) - (4)].i),(yyvsp[(4) - (4)].vl)));
  }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 176 "lang.y"
    {
    (yyval.vl) = (TVCons((yyvsp[(1) - (2)].t),(yyvsp[(2) - (2)].i),TVNil()));
  }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 202 "lang.y"
    {
    (yyval.el) = (TECons((yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].el)));
  }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 206 "lang.y"
    {
    (yyval.el) = (TECons((yyvsp[(1) - (1)].e),TENil()));
  }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 213 "lang.y"
    {
    (yyval.tnl) = (TNLCons((yyvsp[(2) - (4)].i),(yyvsp[(4) - (4)].tnl)));
  }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 217 "lang.y"
    {
    (yyval.tnl) = (TNLCons((yyvsp[(2) - (2)].i),TNLNil()));
  }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 224 "lang.y"
    {
    (yyval.gi) = (TGlobVar((yyvsp[(2) - (3)].t),(yyvsp[(3) - (3)].i)));
  }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 228 "lang.y"
    {
    (yyval.gi) = (TGlobVar_1((yyvsp[(2) - (8)].t),(yyvsp[(4) - (8)].pn),TTNil(),(yyvsp[(5) - (8)].i)));
  }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 232 "lang.y"
    {
    (yyval.gi) = (TGlobVar_1((yyvsp[(2) - (9)].t),(yyvsp[(4) - (9)].pn),(yyvsp[(8) - (9)].tl),(yyvsp[(5) - (9)].i)));
  }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 236 "lang.y"
    {
    (yyval.gi) = (TGlobVar_2((yyvsp[(4) - (8)].pn),TTNil(),(yyvsp[(5) - (8)].i)));
  }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 240 "lang.y"
    {
    (yyval.gi) = (TGlobVar_2((yyvsp[(4) - (9)].pn),(yyvsp[(8) - (9)].tl),(yyvsp[(5) - (9)].i)));
  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 244 "lang.y"
    {
    (yyval.gi) = (TTemFuncDef((yyvsp[(3) - (11)].tnl),(yyvsp[(5) - (11)].t),(yyvsp[(6) - (11)].i),TVNil(),(yyvsp[(10) - (11)].c)));
  }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 248 "lang.y"
    {
    (yyval.gi) = (TTemFuncDef((yyvsp[(3) - (12)].tnl),(yyvsp[(5) - (12)].t),(yyvsp[(6) - (12)].i),(yyvsp[(8) - (12)].vl),(yyvsp[(11) - (12)].c)));
  }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 252 "lang.y"
    {
    (yyval.gi) = (TTemProcDef((yyvsp[(3) - (11)].tnl),(yyvsp[(6) - (11)].i),TVNil(),(yyvsp[(10) - (11)].c)));
  }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 256 "lang.y"
    {
    (yyval.gi) = (TTemProcDef((yyvsp[(3) - (12)].tnl),(yyvsp[(6) - (12)].i),(yyvsp[(8) - (12)].vl),(yyvsp[(11) - (12)].c)));
  }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 260 "lang.y"
    {
    (yyval.gi) = (TFuncDef((yyvsp[(1) - (7)].t),(yyvsp[(2) - (7)].i),TVNil(),(yyvsp[(6) - (7)].c)));
  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 264 "lang.y"
    {
    (yyval.gi) = (TFuncDef((yyvsp[(1) - (8)].t),(yyvsp[(2) - (8)].i),(yyvsp[(4) - (8)].vl),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 268 "lang.y"
    {
    (yyval.gi) = (TProcDef((yyvsp[(2) - (7)].i),TVNil(),(yyvsp[(6) - (7)].c)));
  }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 272 "lang.y"
    {
    (yyval.gi) = (TProcDef((yyvsp[(2) - (8)].i),(yyvsp[(4) - (8)].vl),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 279 "lang.y"
    {
    (yyval.c) = (TDecl((yyvsp[(2) - (5)].t),(yyvsp[(3) - (5)].i),(yyvsp[(5) - (5)].c)));
  }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 283 "lang.y"
    {
    (yyval.c) = (TDecl_1((yyvsp[(2) - (10)].t),(yyvsp[(4) - (10)].pn),TTNil(),(yyvsp[(5) - (10)].i),(yyvsp[(10) - (10)].c)));
  }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 287 "lang.y"
    {
    (yyval.c) = (TDecl_1((yyvsp[(2) - (11)].t),(yyvsp[(4) - (11)].pn),(yyvsp[(8) - (11)].tl),(yyvsp[(5) - (11)].i),(yyvsp[(11) - (11)].c)));
  }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 291 "lang.y"
    {
    (yyval.c) = (TDecl_2((yyvsp[(4) - (10)].pn),TTNil(),(yyvsp[(5) - (10)].i),(yyvsp[(10) - (10)].c)));
  }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 295 "lang.y"
    {
    (yyval.c) = (TDecl_2((yyvsp[(4) - (11)].pn),(yyvsp[(8) - (11)].tl),(yyvsp[(5) - (11)].i),(yyvsp[(11) - (11)].c)));
  }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 299 "lang.y"
    {
    (yyval.c) = (TAsgn((yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 303 "lang.y"
    {
    (yyval.c) = (TSeq((yyvsp[(1) - (3)].c),(yyvsp[(3) - (3)].c)));
  }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 307 "lang.y"
    {
    (yyval.c) = (TIf((yyvsp[(3) - (12)].e),(yyvsp[(7) - (12)].c),(yyvsp[(11) - (12)].c)));
  }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 311 "lang.y"
    {
    (yyval.c) = (TWhile((yyvsp[(3) - (8)].e),(yyvsp[(7) - (8)].c)));
  }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 315 "lang.y"
    {
    (yyval.c) = (TFor((yyvsp[(3) - (13)].c),(yyvsp[(6) - (13)].e),(yyvsp[(9) - (13)].c),(yyvsp[(12) - (13)].c)));
  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 319 "lang.y"
    {
    (yyval.c) = (TDoWhile((yyvsp[(3) - (8)].c),(yyvsp[(7) - (8)].e)));
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 323 "lang.y"
    {
    (yyval.c) = (TProc((yyvsp[(2) - (3)].none),TENil()));
  }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 327 "lang.y"
    {
    (yyval.c) = (TProc((yyvsp[(2) - (4)].none),(yyvsp[(3) - (4)].el)));
  }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 331 "lang.y"
    {
    (yyval.c) = (TBreak());
  }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 335 "lang.y"
    {
    (yyval.c) = (TContinue());
  }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 339 "lang.y"
    {
    (yyval.c) = (TReturn());
  }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 356 "lang.y"
    {
    (yyval.e) = (TConst((yyvsp[(1) - (1)].n)));
  }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 360 "lang.y"
    {
    (yyval.e) = ((yyvsp[(2) - (3)].e));
  }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 364 "lang.y"
    {
    (yyval.e) = (TVar((yyvsp[(1) - (1)].i)));
  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 368 "lang.y"
    {
    (yyval.e) = (TFunc((yyvsp[(1) - (3)].i),TENil()));
  }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 372 "lang.y"
    {
    (yyval.e) = (TFunc((yyvsp[(1) - (4)].i),(yyvsp[(3) - (4)].el)));
  }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 379 "lang.y"
    {
    (yyval.e) = (TUnOp(T_NOT,(yyvsp[(2) - (2)].e)));
  }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 383 "lang.y"
    {
    (yyval.e) = ((yyvsp[(1) - (1)].e));
  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 391 "lang.y"
    {
    (yyval.e) = ((yyvsp[(1) - (1)].e));
  }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 395 "lang.y"
    {
    (yyval.e) = (TUnOp(T_UMINUS,(yyvsp[(2) - (2)].e)));
  }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 399 "lang.y"
    {
    (yyval.e) = (TDeref((yyvsp[(2) - (2)].e)));
  }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 403 "lang.y"
    {
    (yyval.e) = (TAddrOf((yyvsp[(2) - (2)].e)));
  }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 407 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MUL,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 411 "lang.y"
    {
    (yyval.e) = (TBinOp(T_PLUS,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 415 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MINUS,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 419 "lang.y"
    {
    (yyval.e) = (TBinOp(T_DIV,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 423 "lang.y"
    {
    (yyval.e) = (TBinOp(T_MOD,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 427 "lang.y"
    {
    (yyval.e) = (TBinOp(T_LT,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 431 "lang.y"
    {
    (yyval.e) = (TBinOp(T_GT,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 435 "lang.y"
    {
    (yyval.e) = (TBinOp(T_LE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 439 "lang.y"
    {
    (yyval.e) = (TBinOp(T_GE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 443 "lang.y"
    {
    (yyval.e) = (TBinOp(T_EQ,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 447 "lang.y"
    {
    (yyval.e) = (TBinOp(T_NE,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 451 "lang.y"
    {
    (yyval.e) = (TBinOp(T_AND,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 455 "lang.y"
    {
    (yyval.e) = (TBinOp(T_OR,(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e)));
  }
    break;


/* Line 1792 of yacc.c  */
#line 2232 "parser.c"
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
#line 461 "lang.y"


void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
