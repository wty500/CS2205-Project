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
  YYSYMBOL_TM_PROC_DEF = 14,               /* TM_PROC_DEF  */
  YYSYMBOL_TM_CONTINUE = 15,               /* TM_CONTINUE  */
  YYSYMBOL_TM_BREAK = 16,                  /* TM_BREAK  */
  YYSYMBOL_TM_RETURN = 17,                 /* TM_RETURN  */
  YYSYMBOL_TM_INT = 18,                    /* TM_INT  */
  YYSYMBOL_TM_IF = 19,                     /* TM_IF  */
  YYSYMBOL_TM_THEN = 20,                   /* TM_THEN  */
  YYSYMBOL_TM_ELSE = 21,                   /* TM_ELSE  */
  YYSYMBOL_TM_WHILE = 22,                  /* TM_WHILE  */
  YYSYMBOL_TM_DO = 23,                     /* TM_DO  */
  YYSYMBOL_TM_FOR = 24,                    /* TM_FOR  */
  YYSYMBOL_TM_ASGNOP = 25,                 /* TM_ASGNOP  */
  YYSYMBOL_TM_OR = 26,                     /* TM_OR  */
  YYSYMBOL_TM_AND = 27,                    /* TM_AND  */
  YYSYMBOL_TM_NOT = 28,                    /* TM_NOT  */
  YYSYMBOL_TM_LT = 29,                     /* TM_LT  */
  YYSYMBOL_TM_LE = 30,                     /* TM_LE  */
  YYSYMBOL_TM_GT = 31,                     /* TM_GT  */
  YYSYMBOL_TM_GE = 32,                     /* TM_GE  */
  YYSYMBOL_TM_EQ = 33,                     /* TM_EQ  */
  YYSYMBOL_TM_NE = 34,                     /* TM_NE  */
  YYSYMBOL_TM_PLUS = 35,                   /* TM_PLUS  */
  YYSYMBOL_TM_MINUS = 36,                  /* TM_MINUS  */
  YYSYMBOL_TM_MUL = 37,                    /* TM_MUL  */
  YYSYMBOL_TM_DIV = 38,                    /* TM_DIV  */
  YYSYMBOL_TM_MOD = 39,                    /* TM_MOD  */
  YYSYMBOL_TM_UMINUS = 40,                 /* TM_UMINUS  */
  YYSYMBOL_TM_DEREF = 41,                  /* TM_DEREF  */
  YYSYMBOL_TM_ADDR_OF = 42,                /* TM_ADDR_OF  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_NT_WHOLE = 44,                  /* NT_WHOLE  */
  YYSYMBOL_NT_GLOBAL_ITEM_LIST = 45,       /* NT_GLOBAL_ITEM_LIST  */
  YYSYMBOL_NT_PTR_NUM = 46,                /* NT_PTR_NUM  */
  YYSYMBOL_NT_TYPE_LIST = 47,              /* NT_TYPE_LIST  */
  YYSYMBOL_NT_TYPE = 48,                   /* NT_TYPE  */
  YYSYMBOL_NT_TYPE1 = 49,                  /* NT_TYPE1  */
  YYSYMBOL_NT_intTYPE = 50,                /* NT_intTYPE  */
  YYSYMBOL_NT_TTYPE = 51,                  /* NT_TTYPE  */
  YYSYMBOL_NT_VAR_LIST = 52,               /* NT_VAR_LIST  */
  YYSYMBOL_NT_EXPR_LIST = 53,              /* NT_EXPR_LIST  */
  YYSYMBOL_NT_TYPENAME_LIST = 54,          /* NT_TYPENAME_LIST  */
  YYSYMBOL_NT_GLOBAL_ITEM = 55,            /* NT_GLOBAL_ITEM  */
  YYSYMBOL_NT_CMD = 56,                    /* NT_CMD  */
  YYSYMBOL_NT_EXPR0 = 57,                  /* NT_EXPR0  */
  YYSYMBOL_NT_EXPR1 = 58,                  /* NT_EXPR1  */
  YYSYMBOL_NT_EXPR = 59                    /* NT_EXPR  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    90,    94,   101,   105,   111,   115,   122,
     126,   133,   137,   144,   148,   155,   159,   167,   171,   197,
     201,   208,   212,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   274,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   322,   326,
     330,   334,   351,   355,   359,   363,   367,   374,   378,   386,
     390,   394,   398,   402,   406,   410,   414,   418,   422,   426,
     430,   434,   438,   442,   446,   450
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
  "TM_PROC_DEF", "TM_CONTINUE", "TM_BREAK", "TM_RETURN", "TM_INT", "TM_IF",
  "TM_THEN", "TM_ELSE", "TM_WHILE", "TM_DO", "TM_FOR", "TM_ASGNOP",
  "TM_OR", "TM_AND", "TM_NOT", "TM_LT", "TM_LE", "TM_GT", "TM_GE", "TM_EQ",
  "TM_NE", "TM_PLUS", "TM_MINUS", "TM_MUL", "TM_DIV", "TM_MOD",
  "TM_UMINUS", "TM_DEREF", "TM_ADDR_OF", "$accept", "NT_WHOLE",
  "NT_GLOBAL_ITEM_LIST", "NT_PTR_NUM", "NT_TYPE_LIST", "NT_TYPE",
  "NT_TYPE1", "NT_intTYPE", "NT_TTYPE", "NT_VAR_LIST", "NT_EXPR_LIST",
  "NT_TYPENAME_LIST", "NT_GLOBAL_ITEM", "NT_CMD", "NT_EXPR0", "NT_EXPR1",
  "NT_EXPR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,  -133,   -22,    15,     9,  -133,    32,  -133,     5,  -133,
      17,    18,     6,    22,    71,   103,   121,   136,  -133,   138,
      93,  -133,  -133,    78,   145,   119,    93,    93,  -133,    77,
     120,  -133,    -2,  -133,   169,   123,    49,    12,   173,   176,
     189,   183,   193,   195,  -133,    22,   202,    99,   205,   231,
     168,   232,   269,   168,   270,    86,  -133,   272,   287,   312,
     319,  -133,   332,    98,   128,  -133,  -133,  -133,   372,   373,
     371,   376,    98,    98,    98,    98,   106,  -133,  -133,   266,
      86,   168,   112,   168,   374,   129,   190,   191,   302,   303,
      14,   377,   125,   378,   379,   383,    98,    98,   168,   168,
    -133,  -133,  -133,  -133,  -133,   168,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
    -133,   159,  -133,   164,  -133,    86,   384,   375,   385,   380,
    -133,   386,  -133,   387,   180,   388,   251,    72,  -133,    93,
      93,   382,   185,   199,   194,   234,   389,   298,   311,   322,
     279,   279,   279,   279,   279,   279,    60,    60,  -133,  -133,
    -133,  -133,  -133,  -133,   168,   392,   168,   394,  -133,  -133,
     238,    98,  -133,   393,    70,    36,   168,   390,   370,   381,
     395,   267,   168,   356,   168,  -133,  -133,   396,   397,   389,
     401,   402,   404,    98,  -133,   357,  -133,   358,   405,   406,
     168,   168,    98,   219,  -133,  -133,   304,   305,   362,   363,
     233,   403,   391,   407,   400,   408,   398,  -133,  -133,   168,
     168,   409,   168,   411,   412,   364,   389,   168,   389,   168,
     168,   416,   389,   389,   368,   168,  -133,   369,  -133
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,     0,     0,     0,    14,     0,     2,     0,     9,
      11,    12,     4,     0,     0,     0,     9,     0,     1,     0,
       0,    13,    15,     0,     0,     0,     0,     0,    23,     0,
       0,     5,     0,     3,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,    21,     0,     0,     0,
       0,    52,    54,     0,     0,    50,    49,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     9,     0,     0,     0,     0,
      57,    60,    61,    62,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,    32,     0,    10,     0,     0,     0,     0,     0,
      26,     0,    24,     0,    55,     0,    20,     0,    53,     0,
       0,     0,     0,     0,     0,     0,    42,    41,    75,    74,
      68,    70,    69,    71,    72,    73,    64,    65,    63,    66,
      67,    35,    33,     7,     0,     0,     0,     0,    27,    25,
      56,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    56,     0,     0,    36,
       0,     0,     0,     0,    30,     0,    28,     0,     0,     0,
       0,     0,     0,     0,    31,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    46,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    37,     0,
       0,     0,    40,    38,     0,     0,    43,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   399,   -23,   -87,     8,     7,  -133,  -133,    -3,
    -132,   347,  -133,   -53,  -133,  -133,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    32,    84,    85,     9,    10,    11,    40,
     135,    25,    12,    76,    77,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,   131,   133,    36,    37,   173,    43,    13,     8,    19,
      16,    15,    20,    17,    92,    23,    49,    61,    91,     1,
      43,    63,   134,   100,   101,   102,   103,    42,   121,    14,
     123,     8,    18,     5,    24,    44,    39,    39,   163,   185,
     188,   136,    72,    47,    43,   144,   145,   142,   143,    44,
      73,    74,   146,    48,    21,    22,    75,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    95,    94,    44,   187,    61,    91,   120,    26,    63,
     172,     1,     1,   127,   129,    38,    44,    39,   136,     2,
       1,     3,     4,    39,    39,     5,     5,   117,   118,   119,
      72,    61,    91,    58,     5,    63,    20,    44,    73,    74,
      27,   181,   104,   183,    75,   105,   174,   175,   122,   213,
     215,   105,   136,   189,     1,    28,    72,     1,    41,   195,
      31,   197,     1,   138,    73,    74,    20,    46,     5,   125,
      75,     5,    93,    29,   203,    30,     5,   208,   209,    34,
      35,   107,   108,   210,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   161,   225,   226,   105,   228,
     162,    61,    62,   105,   232,    63,   233,   234,    50,    45,
      51,    64,   237,    65,    66,    67,   -47,    68,    53,   -47,
      69,    70,    71,   177,     1,     1,    72,    52,   126,   128,
     179,    54,    55,   105,    73,    74,    57,   178,     5,     5,
      75,   107,   108,    59,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   107,   108,   211,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    60,
     180,   218,    80,   105,   -48,   107,   108,   -48,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   107,
     108,   171,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   194,    81,    83,   105,   107,   108,    86,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   106,   107,   108,    87,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     1,     1,     1,     1,
     130,   132,   212,   214,   115,   116,   117,   118,   119,    88,
       5,     5,     5,     5,   107,   108,    89,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   108,    90,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   196,   204,   205,   105,   105,   105,   216,   217,
     231,   105,   105,   105,   236,   238,    98,   105,   105,    96,
      97,    99,   124,   165,   137,   139,   140,   141,   167,   164,
     166,   176,    56,   191,   168,   169,   170,   182,   105,   184,
     220,   186,   193,   192,   198,   199,   200,   201,   219,   222,
     190,   202,   206,   207,     0,   221,   223,   230,   227,   224,
     229,   235,    33
};

static const yytype_int16 yycheck[] =
{
      53,    88,    89,    26,    27,   137,     8,    29,     0,     4,
       3,     3,     7,     4,    63,     9,     4,     3,     4,     4,
       8,     7,     8,    72,    73,    74,    75,    30,    81,    14,
      83,    23,     0,    18,    12,    37,    29,    30,   125,   171,
       4,    90,    28,    35,     8,    98,    99,    96,    97,    37,
      36,    37,   105,     4,    37,    37,    42,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    64,    64,    37,     4,     3,     4,    80,     7,     7,
       8,     4,     4,    86,    87,     8,    37,    80,   137,    11,
       4,    13,    14,    86,    87,    18,    18,    37,    38,    39,
      28,     3,     4,     4,    18,     7,     7,    37,    36,    37,
       7,   164,     6,   166,    42,     9,   139,   140,     6,   206,
     207,     9,   171,   176,     4,     4,    28,     4,     8,   182,
      37,   184,     4,     8,    36,    37,     7,    14,    18,    10,
      42,    18,    14,     7,   193,     7,    18,   200,   201,     4,
      31,    26,    27,   202,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     6,   219,   220,     9,   222,
       6,     3,     4,     9,   227,     7,   229,   230,     5,    10,
       4,    13,   235,    15,    16,    17,     6,    19,     5,     9,
      22,    23,    24,     8,     4,     4,    28,     8,     8,     8,
       6,     8,     7,     9,    36,    37,     4,     8,    18,    18,
      42,    26,    27,     8,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    26,    27,     8,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     8,
       6,     8,    10,     9,     6,    26,    27,     9,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    26,
      27,    10,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     6,     5,     5,     9,    26,    27,     7,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    25,    26,    27,     7,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     4,     4,     4,     4,
       8,     8,     8,     8,    35,    36,    37,    38,    39,     7,
      18,    18,    18,    18,    26,    27,     7,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    27,     7,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     6,     6,     6,     9,     9,     9,     6,     6,
       6,     9,     9,     9,     6,     6,     5,     9,     9,     7,
       7,     5,     8,     8,     7,     7,     7,     4,     8,     5,
       5,     9,    45,    23,     8,     8,     8,     5,     9,     5,
       9,     8,     7,    22,     8,     8,     5,     5,     5,     9,
      20,     7,     7,     7,    -1,     8,     8,     5,     9,    21,
       9,     5,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    11,    13,    14,    18,    44,    45,    48,    49,
      50,    51,    55,    29,    14,    48,    49,     4,     0,     4,
       7,    37,    37,     9,    12,    54,     7,     7,     4,     7,
       7,    37,    46,    45,     4,    31,    46,    46,     8,    49,
      52,     8,    52,     8,    37,    10,    14,    48,     4,     4,
       5,     4,     8,     5,     8,     7,    54,     4,     4,     8,
       8,     3,     4,     7,    13,    15,    16,    17,    19,    22,
      23,    24,    28,    36,    37,    42,    56,    57,    58,    59,
      10,     5,    56,     5,    47,    48,     7,     7,     7,     7,
       7,     4,    59,    14,    48,    49,     7,     7,     5,     5,
      59,    59,    59,    59,     6,     9,    25,    26,    27,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      52,    56,     6,    56,     8,    10,     8,    52,     8,    52,
       8,    47,     8,    47,     8,    53,    59,     7,     8,     7,
       7,     4,    59,    59,    56,    56,    56,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,     6,     6,    47,     5,     8,     5,     8,     8,     8,
       8,    10,     8,    53,    46,    46,     9,     8,     8,     6,
       6,    56,     5,    56,     5,    53,     8,     4,     4,    56,
      20,    23,    22,     7,     6,    56,     6,    56,     8,     8,
       5,     5,     7,    59,     6,     6,     7,     7,    56,    56,
      59,     8,     8,    47,     8,    47,     6,     6,     8,     5,
       9,     8,     9,     8,    21,    56,    56,     9,    56,     9,
       5,     6,    56,    56,    56,     5,     6,    56,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       7,     1,     1,     2,     1,     2,     1,     4,     2,     3,
       1,     4,     2,     3,     8,     9,     8,     9,    11,    12,
      11,    12,     7,     8,     7,     8,     5,    10,    11,    10,
      11,     3,     3,    12,     8,    13,     8,     3,     4,     1,
       1,     1,     1,     3,     1,     3,     4,     2,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
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
#line 83 "lang.y"
  {
    (yyval.gil) = ((yyvsp[0].gil));
    root = (yyval.gil);
  }
#line 1306 "parser.c"
    break;

  case 3: /* NT_GLOBAL_ITEM_LIST: NT_GLOBAL_ITEM TM_SEMICOL NT_GLOBAL_ITEM_LIST  */
#line 91 "lang.y"
  {
    (yyval.gil) = (TGCons((yyvsp[-2].gi),(yyvsp[0].gil)));
  }
#line 1314 "parser.c"
    break;

  case 4: /* NT_GLOBAL_ITEM_LIST: NT_GLOBAL_ITEM  */
#line 95 "lang.y"
  {
    (yyval.gil) = (TGCons((yyvsp[0].gi),TGNil()));
  }
#line 1322 "parser.c"
    break;

  case 5: /* NT_PTR_NUM: TM_MUL  */
#line 102 "lang.y"
  {
  (yyval.pn) = (TPtr_num());
  }
#line 1330 "parser.c"
    break;

  case 6: /* NT_PTR_NUM: NT_PTR_NUM TM_MUL  */
#line 106 "lang.y"
  {
  (yyval.pn) = (TPtr_num_1((yyvsp[-1].pn)));
  }
#line 1338 "parser.c"
    break;

  case 7: /* NT_TYPE_LIST: NT_TYPE TM_COMMA NT_TYPE_LIST  */
#line 112 "lang.y"
  {
    (yyval.tl) = (TTCons((yyvsp[-2].t),(yyvsp[0].tl)));
  }
#line 1346 "parser.c"
    break;

  case 8: /* NT_TYPE_LIST: NT_TYPE  */
#line 116 "lang.y"
  {
    (yyval.tl) = (TTCons((yyvsp[0].t),TTNil()));
  }
#line 1354 "parser.c"
    break;

  case 9: /* NT_TYPE: NT_TYPE1  */
#line 123 "lang.y"
  {
    (yyval.t) = ((yyvsp[0].t));
  }
#line 1362 "parser.c"
    break;

  case 10: /* NT_TYPE: NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 127 "lang.y"
  {
    (yyval.t) = (TPtr_func((yyvsp[-6].t),(yyvsp[-4].pn),(yyvsp[-1].tl)));
  }
#line 1370 "parser.c"
    break;

  case 11: /* NT_TYPE1: NT_intTYPE  */
#line 134 "lang.y"
  {
    (yyval.t) = ((yyvsp[0].t));
  }
#line 1378 "parser.c"
    break;

  case 12: /* NT_TYPE1: NT_TTYPE  */
#line 138 "lang.y"
  {
    (yyval.t) = ((yyvsp[0].t));
  }
#line 1386 "parser.c"
    break;

  case 13: /* NT_intTYPE: NT_intTYPE TM_MUL  */
#line 145 "lang.y"
  {
    (yyval.t) = (TPtr_int_1((yyvsp[-1].t)));
  }
#line 1394 "parser.c"
    break;

  case 14: /* NT_intTYPE: TM_INT  */
#line 149 "lang.y"
  {
    (yyval.t) = (TPtr_int());
  }
#line 1402 "parser.c"
    break;

  case 15: /* NT_TTYPE: NT_TTYPE TM_MUL  */
#line 156 "lang.y"
  {
    (yyval.t) = (TPtr_T_1((yyvsp[-1].t)));
  }
#line 1410 "parser.c"
    break;

  case 16: /* NT_TTYPE: TM_IDENT  */
#line 160 "lang.y"
  {
    (yyval.t) = (TPtr_T((yyvsp[0].i)));
  }
#line 1418 "parser.c"
    break;

  case 17: /* NT_VAR_LIST: NT_TYPE1 TM_IDENT TM_COMMA NT_VAR_LIST  */
#line 168 "lang.y"
  {
    (yyval.vl) = (TVCons((yyvsp[-3].t),(yyvsp[-2].i),(yyvsp[0].vl)));
  }
#line 1426 "parser.c"
    break;

  case 18: /* NT_VAR_LIST: NT_TYPE1 TM_IDENT  */
#line 172 "lang.y"
  {
    (yyval.vl) = (TVCons((yyvsp[-1].t),(yyvsp[0].i),TVNil()));
  }
#line 1434 "parser.c"
    break;

  case 19: /* NT_EXPR_LIST: NT_EXPR TM_COMMA NT_EXPR_LIST  */
#line 198 "lang.y"
  {
    (yyval.el) = (TECons((yyvsp[-2].e),(yyvsp[0].el)));
  }
#line 1442 "parser.c"
    break;

  case 20: /* NT_EXPR_LIST: NT_EXPR  */
#line 202 "lang.y"
  {
    (yyval.el) = (TECons((yyvsp[0].e),TENil()));
  }
#line 1450 "parser.c"
    break;

  case 21: /* NT_TYPENAME_LIST: TM_TYPENAME TM_IDENT TM_COMMA NT_TYPENAME_LIST  */
#line 209 "lang.y"
  {
    (yyval.tnl) = (TNLCons((yyvsp[-2].i),(yyvsp[0].tnl)));
  }
#line 1458 "parser.c"
    break;

  case 22: /* NT_TYPENAME_LIST: TM_TYPENAME TM_IDENT  */
#line 213 "lang.y"
  {
    (yyval.tnl) = (TNLCons((yyvsp[0].i),TNLNil()));
  }
#line 1466 "parser.c"
    break;

  case 23: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE1 TM_IDENT  */
#line 220 "lang.y"
  {
    (yyval.gi) = (TGlobVar((yyvsp[-1].t),(yyvsp[0].i)));
  }
#line 1474 "parser.c"
    break;

  case 24: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 224 "lang.y"
  {
    (yyval.gi) = (TGlobVar_1((yyvsp[-6].t),(yyvsp[-4].pn),TTNil(),(yyvsp[-3].i)));
  }
#line 1482 "parser.c"
    break;

  case 25: /* NT_GLOBAL_ITEM: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 228 "lang.y"
  {
    (yyval.gi) = (TGlobVar_1((yyvsp[-7].t),(yyvsp[-5].pn),(yyvsp[-1].tl),(yyvsp[-4].i)));
  }
#line 1490 "parser.c"
    break;

  case 26: /* NT_GLOBAL_ITEM: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 232 "lang.y"
  {
    (yyval.gi) = (TGlobVar_2((yyvsp[-4].pn),TTNil(),(yyvsp[-3].i)));
  }
#line 1498 "parser.c"
    break;

  case 27: /* NT_GLOBAL_ITEM: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN  */
#line 236 "lang.y"
  {
    (yyval.gi) = (TGlobVar_2((yyvsp[-5].pn),(yyvsp[-1].tl),(yyvsp[-4].i)));
  }
#line 1506 "parser.c"
    break;

  case 28: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 240 "lang.y"
  {
    (yyval.gi) = (TTemFuncDef((yyvsp[-8].tnl),(yyvsp[-6].t),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1514 "parser.c"
    break;

  case 29: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 244 "lang.y"
  {
    (yyval.gi) = (TTemFuncDef((yyvsp[-9].tnl),(yyvsp[-7].t),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1522 "parser.c"
    break;

  case 30: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 248 "lang.y"
  {
    (yyval.gi) = (TTemProcDef((yyvsp[-8].tnl),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1530 "parser.c"
    break;

  case 31: /* NT_GLOBAL_ITEM: TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 252 "lang.y"
  {
    (yyval.gi) = (TTemProcDef((yyvsp[-9].tnl),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1538 "parser.c"
    break;

  case 32: /* NT_GLOBAL_ITEM: NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 256 "lang.y"
  {
    (yyval.gi) = (TFuncDef((yyvsp[-6].t),(yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1546 "parser.c"
    break;

  case 33: /* NT_GLOBAL_ITEM: NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 260 "lang.y"
  {
    (yyval.gi) = (TFuncDef((yyvsp[-7].t),(yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1554 "parser.c"
    break;

  case 34: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 264 "lang.y"
  {
    (yyval.gi) = (TProcDef((yyvsp[-5].i),TVNil(),(yyvsp[-1].c)));
  }
#line 1562 "parser.c"
    break;

  case 35: /* NT_GLOBAL_ITEM: TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 268 "lang.y"
  {
    (yyval.gi) = (TProcDef((yyvsp[-6].i),(yyvsp[-4].vl),(yyvsp[-1].c)));
  }
#line 1570 "parser.c"
    break;

  case 36: /* NT_CMD: TM_VAR NT_TYPE1 TM_IDENT TM_SEMICOL NT_CMD  */
#line 275 "lang.y"
  {
    (yyval.c) = (TDecl((yyvsp[-3].t),(yyvsp[-2].i),(yyvsp[0].c)));
  }
#line 1578 "parser.c"
    break;

  case 37: /* NT_CMD: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 279 "lang.y"
  {
    (yyval.c) = (TDecl_1((yyvsp[-8].t),(yyvsp[-6].pn),TTNil(),(yyvsp[-5].i),(yyvsp[0].c)));
  }
#line 1586 "parser.c"
    break;

  case 38: /* NT_CMD: TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 283 "lang.y"
  {
    (yyval.c) = (TDecl_1((yyvsp[-9].t),(yyvsp[-7].pn),(yyvsp[-3].tl),(yyvsp[-6].i),(yyvsp[0].c)));
  }
#line 1594 "parser.c"
    break;

  case 39: /* NT_CMD: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 287 "lang.y"
  {
    (yyval.c) = (TDecl_2((yyvsp[-6].pn),TTNil(),(yyvsp[-5].i),(yyvsp[0].c)));
  }
#line 1602 "parser.c"
    break;

  case 40: /* NT_CMD: TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD  */
#line 291 "lang.y"
  {
    (yyval.c) = (TDecl_2((yyvsp[-7].pn),(yyvsp[-3].tl),(yyvsp[-6].i),(yyvsp[0].c)));
  }
#line 1610 "parser.c"
    break;

  case 41: /* NT_CMD: NT_EXPR TM_ASGNOP NT_EXPR  */
#line 295 "lang.y"
  {
    (yyval.c) = (TAsgn((yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1618 "parser.c"
    break;

  case 42: /* NT_CMD: NT_CMD TM_SEMICOL NT_CMD  */
#line 299 "lang.y"
  {
    (yyval.c) = (TSeq((yyvsp[-2].c),(yyvsp[0].c)));
  }
#line 1626 "parser.c"
    break;

  case 43: /* NT_CMD: TM_IF TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_THEN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_ELSE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 303 "lang.y"
  {
    (yyval.c) = (TIf((yyvsp[-9].e),(yyvsp[-5].c),(yyvsp[-1].c)));
  }
#line 1634 "parser.c"
    break;

  case 44: /* NT_CMD: TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 307 "lang.y"
  {
    (yyval.c) = (TWhile((yyvsp[-5].e),(yyvsp[-1].c)));
  }
#line 1642 "parser.c"
    break;

  case 45: /* NT_CMD: TM_FOR TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE  */
#line 311 "lang.y"
  {
    (yyval.c) = (TFor((yyvsp[-10].c),(yyvsp[-7].e),(yyvsp[-4].c),(yyvsp[-1].c)));
  }
#line 1650 "parser.c"
    break;

  case 46: /* NT_CMD: TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN  */
#line 315 "lang.y"
  {
    (yyval.c) = (TDoWhile((yyvsp[-5].c),(yyvsp[-1].e)));
  }
#line 1658 "parser.c"
    break;

  case 47: /* NT_CMD: TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 319 "lang.y"
  {
    (yyval.c) = (TProc((yyvsp[-1].none),TENil()));
  }
#line 1666 "parser.c"
    break;

  case 48: /* NT_CMD: TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN  */
#line 323 "lang.y"
  {
    (yyval.c) = (TProc((yyvsp[-2].none),(yyvsp[-1].el)));
  }
#line 1674 "parser.c"
    break;

  case 49: /* NT_CMD: TM_BREAK  */
#line 327 "lang.y"
  {
    (yyval.c) = (TBreak());
  }
#line 1682 "parser.c"
    break;

  case 50: /* NT_CMD: TM_CONTINUE  */
#line 331 "lang.y"
  {
    (yyval.c) = (TContinue());
  }
#line 1690 "parser.c"
    break;

  case 51: /* NT_CMD: TM_RETURN  */
#line 335 "lang.y"
  {
    (yyval.c) = (TReturn());
  }
#line 1698 "parser.c"
    break;

  case 52: /* NT_EXPR0: TM_NAT  */
#line 352 "lang.y"
  {
    (yyval.e) = (TConst((yyvsp[0].n)));
  }
#line 1706 "parser.c"
    break;

  case 53: /* NT_EXPR0: TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN  */
#line 356 "lang.y"
  {
    (yyval.e) = ((yyvsp[-1].e));
  }
#line 1714 "parser.c"
    break;

  case 54: /* NT_EXPR0: TM_IDENT  */
#line 360 "lang.y"
  {
    (yyval.e) = (TVar((yyvsp[0].i)));
  }
#line 1722 "parser.c"
    break;

  case 55: /* NT_EXPR0: TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN  */
#line 364 "lang.y"
  {
    (yyval.e) = (TFunc((yyvsp[-2].i),TENil()));
  }
#line 1730 "parser.c"
    break;

  case 56: /* NT_EXPR0: TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN  */
#line 368 "lang.y"
  {
    (yyval.e) = (TFunc((yyvsp[-3].i),(yyvsp[-1].el)));
  }
#line 1738 "parser.c"
    break;

  case 57: /* NT_EXPR1: TM_NOT NT_EXPR  */
#line 375 "lang.y"
  {
    (yyval.e) = (TUnOp(T_NOT,(yyvsp[0].e)));
  }
#line 1746 "parser.c"
    break;

  case 58: /* NT_EXPR1: NT_EXPR0  */
#line 379 "lang.y"
  {
    (yyval.e) = ((yyvsp[0].e));
  }
#line 1754 "parser.c"
    break;

  case 59: /* NT_EXPR: NT_EXPR1  */
#line 387 "lang.y"
  {
    (yyval.e) = ((yyvsp[0].e));
  }
#line 1762 "parser.c"
    break;

  case 60: /* NT_EXPR: TM_MINUS NT_EXPR  */
#line 391 "lang.y"
  {
    (yyval.e) = (TUnOp(T_UMINUS,(yyvsp[0].e)));
  }
#line 1770 "parser.c"
    break;

  case 61: /* NT_EXPR: TM_MUL NT_EXPR  */
#line 395 "lang.y"
  {
    (yyval.e) = (TDeref((yyvsp[0].e)));
  }
#line 1778 "parser.c"
    break;

  case 62: /* NT_EXPR: TM_ADDR_OF NT_EXPR  */
#line 399 "lang.y"
  {
    (yyval.e) = (TAddrOf((yyvsp[0].e)));
  }
#line 1786 "parser.c"
    break;

  case 63: /* NT_EXPR: NT_EXPR TM_MUL NT_EXPR  */
#line 403 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MUL,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1794 "parser.c"
    break;

  case 64: /* NT_EXPR: NT_EXPR TM_PLUS NT_EXPR  */
#line 407 "lang.y"
  {
    (yyval.e) = (TBinOp(T_PLUS,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1802 "parser.c"
    break;

  case 65: /* NT_EXPR: NT_EXPR TM_MINUS NT_EXPR  */
#line 411 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MINUS,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1810 "parser.c"
    break;

  case 66: /* NT_EXPR: NT_EXPR TM_DIV NT_EXPR  */
#line 415 "lang.y"
  {
    (yyval.e) = (TBinOp(T_DIV,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1818 "parser.c"
    break;

  case 67: /* NT_EXPR: NT_EXPR TM_MOD NT_EXPR  */
#line 419 "lang.y"
  {
    (yyval.e) = (TBinOp(T_MOD,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1826 "parser.c"
    break;

  case 68: /* NT_EXPR: NT_EXPR TM_LT NT_EXPR  */
#line 423 "lang.y"
  {
    (yyval.e) = (TBinOp(T_LT,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1834 "parser.c"
    break;

  case 69: /* NT_EXPR: NT_EXPR TM_GT NT_EXPR  */
#line 427 "lang.y"
  {
    (yyval.e) = (TBinOp(T_GT,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1842 "parser.c"
    break;

  case 70: /* NT_EXPR: NT_EXPR TM_LE NT_EXPR  */
#line 431 "lang.y"
  {
    (yyval.e) = (TBinOp(T_LE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1850 "parser.c"
    break;

  case 71: /* NT_EXPR: NT_EXPR TM_GE NT_EXPR  */
#line 435 "lang.y"
  {
    (yyval.e) = (TBinOp(T_GE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1858 "parser.c"
    break;

  case 72: /* NT_EXPR: NT_EXPR TM_EQ NT_EXPR  */
#line 439 "lang.y"
  {
    (yyval.e) = (TBinOp(T_EQ,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1866 "parser.c"
    break;

  case 73: /* NT_EXPR: NT_EXPR TM_NE NT_EXPR  */
#line 443 "lang.y"
  {
    (yyval.e) = (TBinOp(T_NE,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1874 "parser.c"
    break;

  case 74: /* NT_EXPR: NT_EXPR TM_AND NT_EXPR  */
#line 447 "lang.y"
  {
    (yyval.e) = (TBinOp(T_AND,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1882 "parser.c"
    break;

  case 75: /* NT_EXPR: NT_EXPR TM_OR NT_EXPR  */
#line 451 "lang.y"
  {
    (yyval.e) = (TBinOp(T_OR,(yyvsp[-2].e),(yyvsp[0].e)));
  }
#line 1890 "parser.c"
    break;


#line 1894 "parser.c"

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

#line 457 "lang.y"


void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
