/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

	// this part is copied to the beginning of the parser 
	#include <stdio.h>
	#include "lang.h"
	#include "lexer.h"
	void yyerror(char *);
	int yylex(void);
        struct glob_item_list * root;

#line 81 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TM_NAT = 3,                     /* TM_NAT  */
  YYSYMBOL_TM_IDENT = 4,                   /* TM_IDENT  */
  YYSYMBOL_TM_LEFT_BRACE = 5,              /* TM_LEFT_BRACE  */
  YYSYMBOL_TM_RIGHT_BRACE = 6,             /* TM_RIGHT_BRACE  */
  YYSYMBOL_TM_LEFT_PAREN = 7,              /* TM_LEFT_PAREN  */
  YYSYMBOL_TM_RIGHT_PAREN = 8,             /* TM_RIGHT_PAREN  */
  YYSYMBOL_TM_SEMICOL = 9,                 /* TM_SEMICOL  */
  YYSYMBOL_TM_COMMA = 10,                  /* TM_COMMA  */
  YYSYMBOL_TM_TEMPLATE = 11,               /* TM_TEMPLATE  */
  YYSYMBOL_TM_TYPENAME = 12,               /* TM_TYPENAME  */
  YYSYMBOL_TM_VAR = 13,                    /* TM_VAR  */
  YYSYMBOL_TM_FUNC_DEF = 14,               /* TM_FUNC_DEF  */
  YYSYMBOL_TM_PROC_DEF = 15,               /* TM_PROC_DEF  */
  YYSYMBOL_TM_CONTINUE = 16,               /* TM_CONTINUE  */
  YYSYMBOL_TM_BREAK = 17,                  /* TM_BREAK  */
  YYSYMBOL_TM_RETURN = 18,                 /* TM_RETURN  */
  YYSYMBOL_TM_INT = 19,                    /* TM_INT  */
  YYSYMBOL_TM_IF = 20,                     /* TM_IF  */
  YYSYMBOL_TM_THEN = 21,                   /* TM_THEN  */
  YYSYMBOL_TM_ELSE = 22,                   /* TM_ELSE  */
  YYSYMBOL_TM_WHILE = 23,                  /* TM_WHILE  */
  YYSYMBOL_TM_DO = 24,                     /* TM_DO  */
  YYSYMBOL_TM_FOR = 25,                    /* TM_FOR  */
  YYSYMBOL_TM_ASGNOP = 26,                 /* TM_ASGNOP  */
  YYSYMBOL_TM_OR = 27,                     /* TM_OR  */
  YYSYMBOL_TM_AND = 28,                    /* TM_AND  */
  YYSYMBOL_TM_NOT = 29,                    /* TM_NOT  */
  YYSYMBOL_TM_LT = 30,                     /* TM_LT  */
  YYSYMBOL_TM_LE = 31,                     /* TM_LE  */
  YYSYMBOL_TM_GT = 32,                     /* TM_GT  */
  YYSYMBOL_TM_GE = 33,                     /* TM_GE  */
  YYSYMBOL_TM_EQ = 34,                     /* TM_EQ  */
  YYSYMBOL_TM_NE = 35,                     /* TM_NE  */
  YYSYMBOL_TM_PLUS = 36,                   /* TM_PLUS  */
  YYSYMBOL_TM_MINUS = 37,                  /* TM_MINUS  */
  YYSYMBOL_TM_MUL = 38,                    /* TM_MUL  */
  YYSYMBOL_TM_DIV = 39,                    /* TM_DIV  */
  YYSYMBOL_TM_MOD = 40,                    /* TM_MOD  */
  YYSYMBOL_TM_UMINUS = 41,                 /* TM_UMINUS  */
  YYSYMBOL_TM_DEREF = 42,                  /* TM_DEREF  */
  YYSYMBOL_TM_ADDR_OF = 43,                /* TM_ADDR_OF  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_NT_WHOLE = 45,                  /* NT_WHOLE  */
  YYSYMBOL_NT_GLOBAL_ITEM_LIST = 46,       /* NT_GLOBAL_ITEM_LIST  */
  YYSYMBOL_NT_PTR_NUM = 47,                /* NT_PTR_NUM  */
  YYSYMBOL_NT_TYPE_LIST = 48,              /* NT_TYPE_LIST  */
  YYSYMBOL_NT_TYPE = 49,                   /* NT_TYPE  */
  YYSYMBOL_NT_TYPE1 = 50,                  /* NT_TYPE1  */
  YYSYMBOL_NT_VAR_LIST = 51,               /* NT_VAR_LIST  */
  YYSYMBOL_NT_EXPR_LIST = 52,              /* NT_EXPR_LIST  */
  YYSYMBOL_NT_TYPENAME_LIST = 53,          /* NT_TYPENAME_LIST  */
  YYSYMBOL_NT_GLOBAL_ITEM = 54,            /* NT_GLOBAL_ITEM  */
  YYSYMBOL_NT_CMD = 55,                    /* NT_CMD  */
  YYSYMBOL_NT_EXPR0 = 56,                  /* NT_EXPR0  */
  YYSYMBOL_NT_EXPR1 = 57,                  /* NT_EXPR1  */
  YYSYMBOL_NT_EXPR = 58                    /* NT_EXPR  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    89,    93,   100,   104,   110,   114,   121,
     125,   132,   136,   140,   147,   151,   177,   181,   188,   192,
     199,   203,   207,   211,   215,   219,   223,   227,   231,   235,
     239,   243,   247,   254,   258,   262,   266,   270,   274,   278,
     282,   286,   290,   294,   298,   302,   306,   310,   314,   331,
     335,   339,   343,   347,   354,   358,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   402,   406,   410,   414,   418,
     422,   426,   430
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TM_NAT", "TM_IDENT",
  "TM_LEFT_BRACE", "TM_RIGHT_BRACE", "TM_LEFT_PAREN", "TM_RIGHT_PAREN",
  "TM_SEMICOL", "TM_COMMA", "TM_TEMPLATE", "TM_TYPENAME", "TM_VAR",
  "TM_FUNC_DEF", "TM_PROC_DEF", "TM_CONTINUE", "TM_BREAK", "TM_RETURN",
  "TM_INT", "TM_IF", "TM_THEN", "TM_ELSE", "TM_WHILE", "TM_DO", "TM_FOR",
  "TM_ASGNOP", "TM_OR", "TM_AND", "TM_NOT", "TM_LT", "TM_LE", "TM_GT",
  "TM_GE", "TM_EQ", "TM_NE", "TM_PLUS", "TM_MINUS", "TM_MUL", "TM_DIV",
  "TM_MOD", "TM_UMINUS", "TM_DEREF", "TM_ADDR_OF", "$accept", "NT_WHOLE",
  "NT_GLOBAL_ITEM_LIST", "NT_PTR_NUM", "NT_TYPE_LIST", "NT_TYPE",
  "NT_TYPE1", "NT_VAR_LIST", "NT_EXPR_LIST", "NT_TYPENAME_LIST",
  "NT_GLOBAL_ITEM", "NT_CMD", "NT_EXPR0", "NT_EXPR1", "NT_EXPR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,   -15,    78,    78,    21,    24,   -79,    74,    82,   -79,
     -79,    89,     9,    22,    66,   104,   100,   -79,    88,   116,
      95,   100,   -79,   -79,   136,   100,    19,   -79,    12,   -79,
     148,    -9,    29,    76,    -6,   155,    40,   157,   186,   -79,
      82,    78,   180,   217,   223,   229,   252,   150,   251,   264,
     276,   -79,    27,   290,   308,    78,   150,   293,   -79,   322,
     152,    71,   -79,   -79,   -79,   335,   369,   368,   372,   152,
     152,   152,   152,     5,   -79,   -79,   286,    78,   150,   125,
     371,   126,   128,   373,   103,   133,   150,    69,   375,   170,
     376,   377,    41,   152,   152,   150,   150,   -79,   -79,   -79,
     -79,   -79,   150,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   -79,   176,   -79,
     378,   172,   374,   379,   -79,   380,   -79,    78,   -79,   177,
     190,   381,   254,    85,   -79,   100,   100,   382,   184,   205,
     220,   222,   383,   300,   313,   324,   112,   112,   112,   112,
     112,   112,   269,   269,   -79,   -79,   -79,   -79,   -79,   385,
     386,   150,   388,   -79,   -79,   -79,   256,   152,   -79,   387,
      70,    62,   150,   364,   356,   384,   389,   150,   392,   257,
     150,   -79,   -79,   390,   391,   383,   395,   396,   397,   152,
     295,   150,   -79,   296,   398,   399,   150,   150,   152,   219,
     -79,   297,   -79,   291,   292,   359,   360,   240,   403,   -79,
     393,   401,   394,   402,   400,   -79,   -79,   150,   150,   404,
     150,   405,   406,   361,   383,   150,   383,   150,   150,   407,
     383,   383,   365,   150,   -79,   366,   -79
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     0,    13,
      12,     0,     9,     0,     9,     0,     0,     1,     0,     0,
       0,     0,    20,    11,     0,     0,     0,     5,     0,     3,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    49,    51,
       0,     0,    47,    46,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,    51,     0,
       0,     0,     9,     0,     0,     0,     0,    54,    57,    58,
      59,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    23,
       0,     0,     0,     0,    21,     0,    10,     0,    29,     0,
      52,     0,    17,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    39,    38,    72,    71,    65,    67,    66,    68,
      69,    70,    61,    62,    60,    63,    64,    32,    24,     0,
       0,     0,     0,    22,     7,    30,    53,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    53,     0,     0,    33,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      25,     0,    28,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    41,    43,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    34,     0,     0,     0,
      37,    35,     0,     0,    40,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   408,   -18,   -78,     7,    10,   -12,   -48,   409,
     -79,   -56,   -79,   -79,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    28,    83,    84,    14,    37,   131,    20,
       7,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   120,    44,    32,   125,    41,    42,    34,    89,    11,
      13,   101,    12,    22,   102,     8,    38,    97,    98,    99,
     100,    46,   118,     9,    17,    15,    24,    35,    16,    25,
     129,    80,    39,    43,    25,   132,    36,    44,    10,   140,
     141,   138,   139,    36,    48,   137,   142,    23,    52,   164,
      39,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   117,   184,    39,    91,   123,
      44,    92,    58,    88,   183,     9,    60,   130,    23,    23,
       9,   132,     9,    18,    45,   169,    90,    36,    58,    88,
      10,    36,    60,   168,    19,    10,    21,    10,    69,     1,
      39,     2,     3,     4,    23,   179,    70,    71,    39,   160,
      25,    26,    72,   127,    69,   132,   185,   170,   171,   181,
      30,   190,    70,    71,   193,   211,   213,    31,    72,     9,
       9,    36,     9,   119,   122,   201,   124,   199,    27,   128,
     205,   206,   102,    33,    10,    10,   207,    10,   112,   113,
     114,   115,   116,    58,    59,    58,    88,    60,    40,    60,
      47,   223,   224,    61,   226,    49,    62,    63,    64,   230,
      65,   231,   232,    66,    67,    68,     9,   235,   134,    69,
     159,    69,   157,   165,    53,   102,   102,    70,    71,    70,
      71,    10,   173,    72,    50,    72,   -44,   104,   105,   -44,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   104,   105,   174,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    54,   175,   208,   176,   102,
      55,   102,   104,   105,    56,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   104,   105,   216,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      57,    77,   -45,   192,   167,   -45,   102,   104,   105,    78,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   104,   105,    79,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     9,     9,    81,    86,   210,
     212,   200,   202,   209,   102,   102,   102,   114,   115,   116,
      10,    10,   103,   104,   105,    82,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   104,   105,    87,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   105,    93,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   214,   215,   229,   102,   102,
     102,   234,   236,    95,   102,   102,    94,    96,   121,   161,
     187,   126,   133,   135,   136,   186,   158,   162,   163,   166,
     177,   172,   102,   180,   178,   182,   189,   191,   194,   195,
     196,   197,   218,   220,   198,   203,   204,   188,   217,   219,
     221,   228,   233,   225,   227,     0,     0,     0,     0,     0,
       0,     0,   222,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
      56,    79,     8,    21,    82,    14,    15,    25,    60,     2,
       3,     6,     2,     4,     9,    30,     4,    69,    70,    71,
      72,    33,    78,     4,     0,     4,     4,     8,     7,     7,
      86,     4,    38,     4,     7,    87,    26,     8,    19,    95,
      96,    93,    94,    33,     4,     4,   102,    38,    41,   127,
      38,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    77,     4,    38,    61,    81,
       8,    61,     3,     4,     4,     4,     7,     8,    38,    38,
       4,   133,     4,     9,     8,   133,    15,    77,     3,     4,
      19,    81,     7,     8,    12,    19,     7,    19,    29,    11,
      38,    13,    14,    15,    38,   161,    37,    38,    38,   121,
       7,     7,    43,    10,    29,   167,   172,   135,   136,   167,
       4,   177,    37,    38,   180,   203,   204,    32,    43,     4,
       4,   121,     4,     8,     8,   191,     8,   189,    38,     6,
     196,   197,     9,     7,    19,    19,   198,    19,    36,    37,
      38,    39,    40,     3,     4,     3,     4,     7,    10,     7,
       5,   217,   218,    13,   220,     8,    16,    17,    18,   225,
      20,   227,   228,    23,    24,    25,     4,   233,     8,    29,
       8,    29,     6,     6,     4,     9,     9,    37,    38,    37,
      38,    19,     8,    43,     8,    43,     6,    27,    28,     9,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    27,    28,     8,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     8,     6,     8,     6,     9,
       7,     9,    27,    28,     5,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    27,    28,     8,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       8,    10,     6,     6,    10,     9,     9,    27,    28,     5,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    27,    28,     7,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     4,     4,     7,     5,     8,
       8,     6,     6,     6,     9,     9,     9,    38,    39,    40,
      19,    19,    26,    27,    28,     7,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    27,    28,     7,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    28,     7,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     6,     6,     6,     9,     9,
       9,     6,     6,     5,     9,     9,     7,     5,     7,     5,
      24,     8,     7,     7,     7,    21,     8,     8,     8,     8,
       5,     9,     9,     5,     8,     8,     7,     5,     8,     8,
       5,     5,     9,     9,     7,     7,     7,    23,     5,     8,
       8,     5,     5,     9,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    13,    14,    15,    45,    46,    54,    30,     4,
      19,    49,    50,    49,    50,     4,     7,     0,     9,    12,
      53,     7,     4,    38,     4,     7,     7,    38,    47,    46,
       4,    32,    47,     7,    47,     8,    50,    51,     4,    38,
      10,    14,    15,     4,     8,     8,    51,     5,     4,     8,
       8,    53,    49,     4,     8,     7,     5,     8,     3,     4,
       7,    13,    16,    17,    18,    20,    23,    24,    25,    29,
      37,    38,    43,    55,    56,    57,    58,    10,     5,     7,
       4,     7,     7,    48,    49,    55,     5,     7,     4,    58,
      15,    49,    50,     7,     7,     5,     5,    58,    58,    58,
      58,     6,     9,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    51,    55,     8,
      48,     7,     8,    51,     8,    48,     8,    10,     6,    55,
       8,    52,    58,     7,     8,     7,     7,     4,    58,    58,
      55,    55,    55,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,     6,     8,     8,
      51,     5,     8,     8,    48,     6,     8,    10,     8,    52,
      47,    47,     9,     8,     8,     6,     6,     5,     8,    55,
       5,    52,     8,     4,     4,    55,    21,    24,    23,     7,
      55,     5,     6,    55,     8,     8,     5,     5,     7,    58,
       6,    55,     6,     7,     7,    55,    55,    58,     8,     6,
       8,    48,     8,    48,     6,     6,     8,     5,     9,     8,
       9,     8,    22,    55,    55,     9,    55,     9,     5,     6,
      55,    55,    55,     5,     6,    55,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       7,     2,     1,     1,     4,     2,     3,     1,     4,     2,
       3,     8,     9,     7,     8,    12,    13,    11,    12,     8,
       9,     7,     8,     5,    10,    11,    10,    11,     3,     3,
      12,     8,    13,     8,     3,     4,     1,     1,     1,     1,
       3,     1,     3,     4,     2,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* NT_WHOLE: NT_GLOBAL_ITEM_LIST  */
#line 82 "lang.y"
  {
    (yyval.gil) = ((yyvsp[0].gil));
    root = (yyval.gil);
  }
#line 1308 "parser.c"
    break;

  case 3: /* NT_GLOBAL_ITEM_LIST: NT_GLOBAL_ITEM TM_SEMICOL NT_GLOBAL_ITEM_LIST  */
#line 90 "lang.y"
  {
    (yyval.gil) = (TGCons((yyvsp[-2].gi),(yyvsp[0].gil)));
  }
#line 1316 "parser.c"
    break;

  case 4: /* NT_GLOBAL_ITEM_LIST: NT_GLOBAL_ITEM  */
#line 94 "lang.y"
  {
    (yyval.gil) = (TGCons((yyvsp[0].gi),TGNil()));
  }
#line 1324 "parser.c"
    break;

  case 5: /* NT_PTR_NUM: TM_MUL  */
#line 101 "lang.y"
  {
  (yyval.pn) = (TPtr_num());
  }
#line 1332 "parser.c"
    break;

  case 6: /* NT_PTR_NUM: NT_PTR_NUM TM_MUL  */
#line 105 "lang.y"
  {
  (yyval.pn) = (TPtr_num_1((yyvsp[-1].pn)));
  }
#line 1340 "parser.c"
    break;

  case 7: /* NT_TYPE_LIST: NT_TYPE TM_COMMA NT_TYPE_LIST  */
#line 111 "lang.y"
  {
    (yyval.tl) = (TTCons((yyvsp[-2].t),(yyvsp[0].tl)));
  }
#line 1348 "parser.c"
    break;

  case 8: /* NT_TYPE_LIST: NT_TYPE  */
#line 115 "lang.y"
  {
    (yyval.tl) = (TTCons((yyvsp[0].t),TTNil()));
  }
#line 1356 "parser.c"
    break;

  case 9: /* NT_TYPE: NT_TYPE1  */
#line 122 "lang.y"
  {
    (yyval.t) = ((yyvsp[0].t));
  }
#line 1364 "parser.c"
    break;

  case 10: /* NT_TYPE: NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 126 "lang.y"
  {
    (yyval.t) = (TPtr_func((yyvsp[-6].t),(yyvsp[-4].pn),(yyvsp[-1].tl)));
  }
#line 1372 "parser.c"
    break;

  case 11: /* NT_TYPE1: NT_TYPE1 TM_MUL  */
#line 133 "lang.y"
  {
    (yyval.t) = (TPtr_int_1((yyvsp[-1].t)));
  }
#line 1380 "parser.c"
    break;

  case 12: /* NT_TYPE1: TM_INT  */
#line 137 "lang.y"
  {
    (yyval.t) = (TPtr_int());
  }
#line 1388 "parser.c"
    break;

  case 13: /* NT_TYPE1: TM_IDENT  */
#line 141 "lang.y"
  {
    (yyval.t) = (TIdent((yyvsp[0].i)));
  }
#line 1396 "parser.c"
    break;

  case 14: /* NT_VAR_LIST: NT_TYPE1 TM_IDENT TM_COMMA NT_VAR_LIST  */
#line 148 "lang.y"
  {
    (yyval.vl) = (TVCons((yyvsp[-3].t),(yyvsp[-2].i),(yyvsp[0].vl)));
  }
#line 1404 "parser.c"
    break;

  case 15: /* NT_VAR_LIST: NT_TYPE1 TM_IDENT  */
#line 152 "lang.y"
  {
    (yyval.vl) = (TVCons((yyvsp[-1].t),(yyvsp[0].i),TVNil()));
  }
#line 1412 "parser.c"
    break;

  case 16: /* NT_EXPR_LIST: NT_EXPR TM_COMMA NT_EXPR_LIST  */
#line 178 "lang.y"
  {
    (yyval.el) = (TECons((yyvsp[-2].e),(yyvsp[0].el)));
  }
#line 1420 "parser.c"
    break;

  case 17: /* NT_EXPR_LIST: NT_EXPR  */
#line 182 "lang.y"
  {
    (yyval.el) = (TECons((yyvsp[0].e),TENil()));
  }
#line 1428 "parser.c"
    break;

  case 18: /* NT_TYPENAME_LIST: TM_TYPENAME TM_IDENT TM_COMMA NT_TYPENAME_LIST  */
#line 189 "lang.y"
  {
    (yyval.tnl) = (TNLCons((yyvsp[-2].i),(yyvsp[0].tnl)));
  }
#line 1436 "parser.c"
    break;

  case 19: /* NT_TYPENAME_LIST: TM_TYPENAME TM_IDENT  */
#line 193 "lang.y"
  {
    (yyval.tnl) = (TNLCons((yyvsp[0].i),TNLNil()));
  }
#line 1444 "parser.c"
    break;

  case 20: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE1 TM_IDENT  */
#line 200 "lang.y"
  {
    (yyval.gi) = (TGlobVar((yyvsp[-1].t),(yyvsp[0].i)));
  }
#line 1452 "parser.c"
    break;

  case 21: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 204 "lang.y"
  {
    (yyval.gi) = (TGlobVar_1((yyvsp[-6].t),(yyvsp[-4].pn),TTNil(),(yyvsp[-3].i)));
  }
#line 1460 "parser.c"
    break;

  case 22: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 208 "lang.y"
  {
    (yyval.gi) = (TGlobVar_1((yyvsp[-7].t),(yyvsp[-5].pn),(yyvsp[-1].tl),(yyvsp[-4].i)));
  }
#line 1468 "parser.c"
    break;

  case 23: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 212 "lang.y"
  {
    (yyval.gi) = (TGlobVar_2((yyvsp[-4].pn),TTNil(),(yyvsp[-3].i)));
  }
#line 1476 "parser.c"
    break;

  case 24: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 216 "lang.y"
  {
    (yyval.gi) = (TGlobVar_2((yyvsp[-5].pn),(yyvsp[-1].tl),(yyvsp[-4].i)));
  }
#line 1484 "parser.c"
    break;

  case 25: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_FUNC_DEF NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 220 "lang.y"
  {
    (yyval.gi) = (TTemFuncDef((yyvsp[-9].tnl),(yyvsp[-6].t),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1492 "parser.c"
    break;

  case 26: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_FUNC_DEF NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 224 "lang.y"
  {
    (yyval.gi) = (TTemFuncDef((yyvsp[-10].tnl),(yyvsp[-7].t),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1500 "parser.c"
    break;

  case 27: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 228 "lang.y"
  {
    (yyval.gi) = (TTemProcDef((yyvsp[-8].tnl),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1508 "parser.c"
    break;

  case 28: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 232 "lang.y"
  {
    (yyval.gi) = (TTemProcDef((yyvsp[-9].tnl),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1516 "parser.c"
    break;

  case 29: /* NT_GLOBAL_ITEM: TM_FUNC_DEF NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 236 "lang.y"
  {
    (yyval.gi) = (TFuncDef((yyvsp[-6].t),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1524 "parser.c"
    break;

  case 30: /* NT_GLOBAL_ITEM: TM_FUNC_DEF NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 240 "lang.y"
  {
    (yyval.gi) = (TFuncDef((yyvsp[-7].t),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1532 "parser.c"
    break;

  case 31: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 244 "lang.y"
  {
    (yyval.gi) = (TProcDef((yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1540 "parser.c"
    break;

  case 32: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 248 "lang.y"
  {
    (yyval.gi) = (TProcDef((yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1548 "parser.c"
    break;

  case 33: /* NT_CMD: TM_VAR NT_TYPE1 TM_IDENT TM_SEMICOL NT_CMD  */
#line 255 "lang.y"
  {
    (yyval.c) = (TDecl((yyvsp[-3].t),(yyvsp[-2].i),(yyvsp[0].c)));
  }
#line 1556 "parser.c"
    break;

  case 34: /* NT_CMD: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 259 "lang.y"
  {
    (yyval.c) = (TDecl_1((yyvsp[-8].t),(yyvsp[-6].pn),TTNil(),(yyvsp[-5].i),(yyvsp[0].c)));
  }
#line 1564 "parser.c"
    break;

  case 35: /* NT_CMD: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 263 "lang.y"
  {
    (yyval.c) = (TDecl_1((yyvsp[-9].t),(yyvsp[-7].pn),(yyvsp[-3].tl),(yyvsp[-6].i),(yyvsp[0].c)));
  }
#line 1572 "parser.c"
    break;

  case 36: /* NT_CMD: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 267 "lang.y"
  {
    (yyval.c) = (TDecl_2((yyvsp[-6].pn),TTNil(),(yyvsp[-5].i),(yyvsp[0].c)));
  }
#line 1580 "parser.c"
    break;

  case 37: /* NT_CMD: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 271 "lang.y"
  {
    (yyval.c) = (TDecl_2((yyvsp[-7].pn),(yyvsp[-3].tl),(yyvsp[-6].i),(yyvsp[0].c)));
  }
#line 1588 "parser.c"
    break;

  case 38: /* NT_CMD: NT_EXPR TM_ASGNOP NT_EXPR  */
#line 275 "lang.y"
  {
    (yyval.c) = (TAsgn((yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1596 "parser.c"
    break;

  case 39: /* NT_CMD: NT_CMD TM_SEMICOL NT_CMD  */
#line 279 "lang.y"
  {
    (yyval.c) = (TSeq((yyvsp[-2].c),(yyvsp[0].c)));
  }
#line 1604 "parser.c"
    break;

  case 40: /* NT_CMD: TM_IF TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_THEN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_ELSE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 283 "lang.y"
  {
    (yyval.c) = (TIf((yyvsp[-9].e),(yyvsp[-5].c),(yyvsp[-1].c)));
  }
#line 1612 "parser.c"
    break;

  case 41: /* NT_CMD: TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 287 "lang.y"
  {
    (yyval.c) = (TWhile((yyvsp[-5].e),(yyvsp[-1].c)));
  }
#line 1620 "parser.c"
    break;

  case 42: /* NT_CMD: TM_FOR TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 291 "lang.y"
  {
    (yyval.c) = (TFor((yyvsp[-10].c),(yyvsp[-7].e),(yyvsp[-4].c),(yyvsp[-1].c)));
  }
#line 1628 "parser.c"
    break;

  case 43: /* NT_CMD: TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN  */
#line 295 "lang.y"
  {
    (yyval.c) = (TDoWhile((yyvsp[-5].c),(yyvsp[-1].e)));
  }
#line 1636 "parser.c"
    break;

  case 44: /* NT_CMD: TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 299 "lang.y"
  {
    (yyval.c) = (TProc((yyvsp[-1].none),TENil()));
  }
#line 1644 "parser.c"
    break;

  case 45: /* NT_CMD: TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN  */
#line 303 "lang.y"
  {
    (yyval.c) = (TProc((yyvsp[-2].none),(yyvsp[-1].el)));
  }
#line 1652 "parser.c"
    break;

  case 46: /* NT_CMD: TM_BREAK  */
#line 307 "lang.y"
  {
    (yyval.c) = (TBreak());
  }
#line 1660 "parser.c"
    break;

  case 47: /* NT_CMD: TM_CONTINUE  */
#line 311 "lang.y"
  {
    (yyval.c) = (TContinue());
  }
#line 1668 "parser.c"
    break;

  case 48: /* NT_CMD: TM_RETURN  */
#line 315 "lang.y"
  {
    (yyval.c) = (TReturn());
  }
#line 1676 "parser.c"
    break;

  case 49: /* NT_EXPR0: TM_NAT  */
#line 332 "lang.y"
  {
    (yyval.e) = (TConst((yyvsp[0].n)));
  }
#line 1684 "parser.c"
    break;

  case 50: /* NT_EXPR0: TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN  */
#line 336 "lang.y"
  {
    (yyval.e) = ((yyvsp[-1].e));
  }
#line 1692 "parser.c"
    break;

  case 51: /* NT_EXPR0: TM_IDENT  */
#line 340 "lang.y"
  {
    (yyval.e) = (TVar((yyvsp[0].i)));
  }
#line 1700 "parser.c"
    break;

  case 52: /* NT_EXPR0: TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 344 "lang.y"
  {
    (yyval.e) = (TFunc((yyvsp[-2].i),TENil()));
  }
#line 1708 "parser.c"
    break;

  case 53: /* NT_EXPR0: TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN  */
#line 348 "lang.y"
  {
    (yyval.e) = (TFunc((yyvsp[-3].i),(yyvsp[-1].el)));
  }
#line 1716 "parser.c"
    break;

  case 54: /* NT_EXPR1: TM_NOT NT_EXPR  */
#line 355 "lang.y"
  {
    (yyval.e) = (TUnOp(T_NOT,(yyvsp[0].e)));
  }
#line 1724 "parser.c"
    break;

  case 55: /* NT_EXPR1: NT_EXPR0  */
#line 359 "lang.y"
  {
    (yyval.e) = ((yyvsp[0].e));
  }
#line 1732 "parser.c"
    break;

  case 56: /* NT_EXPR: NT_EXPR1  */
#line 367 "lang.y"
  {
    (yyval.e) = ((yyvsp[0].e));
  }
#line 1740 "parser.c"
    break;

  case 57: /* NT_EXPR: TM_MINUS NT_EXPR  */
#line 371 "lang.y"
  {
    (yyval.e) = (TUnOp(T_UMINUS,(yyvsp[0].e)));
  }
#line 1748 "parser.c"
    break;

  case 58: /* NT_EXPR: TM_MUL NT_EXPR  */
#line 375 "lang.y"
  {
    (yyval.e) = (TDeref((yyvsp[0].e)));
  }
#line 1756 "parser.c"
    break;

  case 59: /* NT_EXPR: TM_ADDR_OF NT_EXPR  */
#line 379 "lang.y"
  {
    (yyval.e) = (TAddrOf((yyvsp[0].e)));
  }
#line 1764 "parser.c"
    break;

  case 60: /* NT_EXPR: NT_EXPR TM_MUL NT_EXPR  */
#line 383 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MUL,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1772 "parser.c"
    break;

  case 61: /* NT_EXPR: NT_EXPR TM_PLUS NT_EXPR  */
#line 387 "lang.y"
  {
    (yyval.e) = (TBinOp(T_PLUS,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1780 "parser.c"
    break;

  case 62: /* NT_EXPR: NT_EXPR TM_MINUS NT_EXPR  */
#line 391 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MINUS,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1788 "parser.c"
    break;

  case 63: /* NT_EXPR: NT_EXPR TM_DIV NT_EXPR  */
#line 395 "lang.y"
  {
    (yyval.e) = (TBinOp(T_DIV,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1796 "parser.c"
    break;

  case 64: /* NT_EXPR: NT_EXPR TM_MOD NT_EXPR  */
#line 399 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MOD,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1804 "parser.c"
    break;

  case 65: /* NT_EXPR: NT_EXPR TM_LT NT_EXPR  */
#line 403 "lang.y"
  {
    (yyval.e) = (TBinOp(T_LT,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1812 "parser.c"
    break;

  case 66: /* NT_EXPR: NT_EXPR TM_GT NT_EXPR  */
#line 407 "lang.y"
  {
    (yyval.e) = (TBinOp(T_GT,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1820 "parser.c"
    break;

  case 67: /* NT_EXPR: NT_EXPR TM_LE NT_EXPR  */
#line 411 "lang.y"
  {
    (yyval.e) = (TBinOp(T_LE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1828 "parser.c"
    break;

  case 68: /* NT_EXPR: NT_EXPR TM_GE NT_EXPR  */
#line 415 "lang.y"
  {
    (yyval.e) = (TBinOp(T_GE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1836 "parser.c"
    break;

  case 69: /* NT_EXPR: NT_EXPR TM_EQ NT_EXPR  */
#line 419 "lang.y"
  {
    (yyval.e) = (TBinOp(T_EQ,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1844 "parser.c"
    break;

  case 70: /* NT_EXPR: NT_EXPR TM_NE NT_EXPR  */
#line 423 "lang.y"
  {
    (yyval.e) = (TBinOp(T_NE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1852 "parser.c"
    break;

  case 71: /* NT_EXPR: NT_EXPR TM_AND NT_EXPR  */
#line 427 "lang.y"
  {
    (yyval.e) = (TBinOp(T_AND,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1860 "parser.c"
    break;

  case 72: /* NT_EXPR: NT_EXPR TM_OR NT_EXPR  */
#line 431 "lang.y"
  {
    (yyval.e) = (TBinOp(T_OR,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1868 "parser.c"
    break;


#line 1872 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 437 "lang.y"


void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
