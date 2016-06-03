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
#line 1 "syntax.y" /* yacc.c:339  */

#include "common.h"
#include <stdio.h>
#include <stdlib.h>
int DEBUG = 1;
NODE* ROOT;


#line 75 "yy.tab.cpp" /* yacc.c:339  */

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
   by #include "yy.tab.hpp".  */
#ifndef YY_YY_YY_TAB_HPP_INCLUDED
# define YY_YY_YY_TAB_HPP_INCLUDED
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
    TK_AND = 258,
    TK_ARRAY = 259,
    TK_ASSIGN = 260,
    TK_CASE = 261,
    TK_TYPE = 262,
    TK_SYS_TYPE = 263,
    TK_COLON = 264,
    TK_COMMA = 265,
    TK_CONST = 266,
    TK_DIGITS = 267,
    TK_DIV = 268,
    TK_DO = 269,
    TK_DOT = 270,
    TK_DOTDOT = 271,
    TK_DOWNTO = 272,
    TK_ELSE = 273,
    TK_END = 274,
    TK_EQUAL = 275,
    TK_FOR = 276,
    TK_FUNCTION = 277,
    TK_GE = 278,
    TK_GOTO = 279,
    TK_GT = 280,
    TK_ID = 281,
    TK_IF = 282,
    TK_IN = 283,
    TK_LB = 284,
    TK_LE = 285,
    TK_LP = 286,
    TK_LT = 287,
    TK_MINUS = 288,
    TK_MOD = 289,
    TK_UNEQUAL = 290,
    TK_OF = 291,
    TK_OR = 292,
    TK_OTHERWISE = 293,
    TK_BEGIN = 294,
    TK_PLUS = 295,
    TK_PROCEDURE = 296,
    TK_PROGRAM = 297,
    TK_RB = 298,
    TK_REAL = 299,
    TK_RECORD = 300,
    TK_REPEAT = 301,
    TK_RP = 302,
    TK_SYS_PROC = 303,
    TK_READ = 304,
    TK_SEMI = 305,
    TK_MUL = 306,
    TK_THEN = 307,
    TK_NOT = 308,
    TK_TO = 309,
    TK_UNTIL = 310,
    TK_UPARROW = 311,
    TK_VAR = 312,
    TK_WHILE = 313,
    TK_SET = 314,
    TK_STARSTAR = 315,
    TK_CHAR = 316,
    TK_STRING = 317,
    TK_INTEGER = 318,
    TK_SYS_CON = 319,
    TK_SYS_FUNCT = 320,
    TK_WITH = 321,
    TK_NIL = 322,
    ERROR = 323,
    TK_PROGRAM_HEAD = 324,
    TK_ROUTINE = 325,
    TK_ROUTINE_HEAD = 326,
    TK_ROUTINE_BODY = 327,
    TK_CONST_PART = 328,
    TK_TYPE_PART = 329,
    TK_VAR_PART = 330,
    TK_ROUTINE_PART = 331,
    TK_STMT_LIST = 332,
    TK_STMT = 333,
    TK_CP_STMT = 334,
    TK_VAL_PARA_LIST = 335,
    TK_NON_LABEL_STMT = 336,
    TK_EXP_LIST = 337,
    TK_EXP = 338,
    TK_TERM = 339,
    TK_FACTOR_ID = 340,
    TK_FACTOR_ID_ARGS = 341,
    TK_FACTOR_SYS_FUNCT = 342,
    TK_FACTOR_CONST = 343,
    TK_FACTOR_EXP = 344,
    TK_FACTOR_NOT = 345,
    TK_FACTOR_MINUS = 346,
    TK_FACTOR_ID_EXP = 347,
    TK_FACTOR_DD = 348,
    TK_ARGS_LIST = 349,
    TK_CONST_EL = 350,
    TK_TYPE_DL = 351,
    TK_TYPE_DEF = 352,
    TK_TYPE_DECL = 353,
    TK_FIELD_DL = 354,
    TK_FIELD_DECL = 355,
    TK_NL = 356,
    TK_STD_SYS_TYPE = 357,
    TK_STD_ID = 358,
    TK_STD_NL = 359,
    TK_STD_DD = 360,
    TK_DL = 361,
    TK_VAR_DECL = 362,
    TK_FUNC_DECL = 363,
    TK_FUNC_HEAD = 364,
    TK_PROC_DECL = 365,
    TK_PROC_HEAD = 366,
    TK_PARA = 367,
    TK_PARA_DL = 368,
    TK_PARA_TL = 369,
    TK_PROC = 370,
    TK_CASE_EL = 371,
    TK_CASE_EXPR = 372,
    TK_EXPR = 373,
    TK_ASSIGN_ID = 374,
    TK_ASSIGN_ID_EXPR = 375,
    TK_ASSIGN_DD = 376,
    TK_PROC_ID = 377,
    TK_PROC_ID_ARGS = 378,
    TK_PROC_SYS = 379,
    TK_PROC_SYS_ARGS = 380,
    TK_PROC_READ = 381
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

#endif /* !YY_YY_YY_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "yy.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    48,    60,    71,    84,    93,   103,   114,
     126,   132,   138,   144,   150,   158,   167,   178,   187,   197,
     208,   216,   224,   234,   246,   257,   266,   276,   288,   298,
     308,   317,   325,   333,   342,   352,   363,   374,   383,   393,
     402,   412,   424,   433,   442,   450,   458,   468,   480,   493,
     505,   517,   526,   537,   547,   558,   568,   580,   591,   601,
     611,   620,   630,   640,   651,   659,   667,   675,   683,   691,
     699,   707,   715,   725,   735,   746,   760,   768,   778,   786,
     796,   808,   818,   831,   839,   849,   861,   873,   888,   895,
     904,   916,   926,   937,   947,   959,   969,   979,   989,   999,
    1008,  1017,  1026,  1035,  1044,  1054,  1064,  1074,  1084,  1095,
    1104,  1113,  1121,  1130,  1140,  1149,  1159,  1169,  1177,  1186,
    1194,  1202,  1212,  1224,  1234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_AND", "TK_ARRAY", "TK_ASSIGN",
  "TK_CASE", "TK_TYPE", "TK_SYS_TYPE", "TK_COLON", "TK_COMMA", "TK_CONST",
  "TK_DIGITS", "TK_DIV", "TK_DO", "TK_DOT", "TK_DOTDOT", "TK_DOWNTO",
  "TK_ELSE", "TK_END", "TK_EQUAL", "TK_FOR", "TK_FUNCTION", "TK_GE",
  "TK_GOTO", "TK_GT", "TK_ID", "TK_IF", "TK_IN", "TK_LB", "TK_LE", "TK_LP",
  "TK_LT", "TK_MINUS", "TK_MOD", "TK_UNEQUAL", "TK_OF", "TK_OR",
  "TK_OTHERWISE", "TK_BEGIN", "TK_PLUS", "TK_PROCEDURE", "TK_PROGRAM",
  "TK_RB", "TK_REAL", "TK_RECORD", "TK_REPEAT", "TK_RP", "TK_SYS_PROC",
  "TK_READ", "TK_SEMI", "TK_MUL", "TK_THEN", "TK_NOT", "TK_TO", "TK_UNTIL",
  "TK_UPARROW", "TK_VAR", "TK_WHILE", "TK_SET", "TK_STARSTAR", "TK_CHAR",
  "TK_STRING", "TK_INTEGER", "TK_SYS_CON", "TK_SYS_FUNCT", "TK_WITH",
  "TK_NIL", "ERROR", "TK_PROGRAM_HEAD", "TK_ROUTINE", "TK_ROUTINE_HEAD",
  "TK_ROUTINE_BODY", "TK_CONST_PART", "TK_TYPE_PART", "TK_VAR_PART",
  "TK_ROUTINE_PART", "TK_STMT_LIST", "TK_STMT", "TK_CP_STMT",
  "TK_VAL_PARA_LIST", "TK_NON_LABEL_STMT", "TK_EXP_LIST", "TK_EXP",
  "TK_TERM", "TK_FACTOR_ID", "TK_FACTOR_ID_ARGS", "TK_FACTOR_SYS_FUNCT",
  "TK_FACTOR_CONST", "TK_FACTOR_EXP", "TK_FACTOR_NOT", "TK_FACTOR_MINUS",
  "TK_FACTOR_ID_EXP", "TK_FACTOR_DD", "TK_ARGS_LIST", "TK_CONST_EL",
  "TK_TYPE_DL", "TK_TYPE_DEF", "TK_TYPE_DECL", "TK_FIELD_DL",
  "TK_FIELD_DECL", "TK_NL", "TK_STD_SYS_TYPE", "TK_STD_ID", "TK_STD_NL",
  "TK_STD_DD", "TK_DL", "TK_VAR_DECL", "TK_FUNC_DECL", "TK_FUNC_HEAD",
  "TK_PROC_DECL", "TK_PROC_HEAD", "TK_PARA", "TK_PARA_DL", "TK_PARA_TL",
  "TK_PROC", "TK_CASE_EL", "TK_CASE_EXPR", "TK_EXPR", "TK_ASSIGN_ID",
  "TK_ASSIGN_ID_EXPR", "TK_ASSIGN_DD", "TK_PROC_ID", "TK_PROC_ID_ARGS",
  "TK_PROC_SYS", "TK_PROC_SYS_ARGS", "TK_PROC_READ", "$accept", "program",
  "program_head", "routine", "routine_head", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "simple_type_decl",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "compound_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,    34,    49,    56,    35,  -144,    69,    95,    76,   109,
    -144,   106,   102,  -144,  -144,  -144,  -144,   103,    81,   -20,
     119,   121,   130,   103,  -144,   115,    14,  -144,  -144,  -144,
    -144,  -144,   104,   -20,   212,  -144,   127,    92,    47,   212,
    -144,   126,   132,   212,   152,   116,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,    57,  -144,  -144,    24,
     115,  -144,   139,   142,    14,  -144,   122,  -144,   128,  -144,
     131,    83,   212,   212,   212,   145,  -144,   304,    66,     5,
    -144,   170,  -144,   212,   151,   212,   212,   227,   125,   212,
     212,   290,   191,  -144,   157,  -144,   171,   115,   -20,   115,
     174,   150,  -144,  -144,  -144,    57,   166,  -144,   182,   182,
    -144,  -144,    56,    56,  -144,   177,   212,   212,   176,  -144,
    -144,   212,   212,   212,   212,   212,   212,   212,   -16,   212,
     212,   212,   212,   212,   212,   212,   212,   312,   197,   265,
     312,    11,   183,   212,    16,   312,   158,   183,  -144,    61,
     193,    17,   208,    -4,  -144,    98,   -20,  -144,   175,  -144,
      -7,   217,  -144,   192,   194,  -144,   266,    21,  -144,    28,
      66,    66,    66,    66,    66,    66,   218,   239,   172,  -144,
       5,     5,     5,  -144,  -144,  -144,  -144,     0,   212,   246,
     212,  -144,   236,   312,   212,  -144,  -144,  -144,   215,  -144,
    -144,   220,  -144,  -144,    57,  -144,  -144,   115,   245,    30,
    -144,   251,   252,    61,  -144,  -144,  -144,  -144,  -144,   183,
     183,  -144,  -144,  -144,  -144,   212,   312,   212,   312,   183,
    -144,   312,   242,   -20,  -144,   213,   245,  -144,    -7,    61,
      61,  -144,   222,   230,   291,   312,  -144,    57,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,   183,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    16,
       3,     0,     6,     2,    61,     4,    59,     0,    38,     0,
       0,     0,     0,    15,    18,     0,    46,    11,    12,    13,
      10,    14,     0,     0,     0,    81,     0,     0,    76,     0,
      61,    78,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    17,    29,     0,
      37,    40,     0,     0,     5,    44,     0,    45,     0,     9,
       0,   114,     0,     0,     0,     0,   117,     0,   104,   108,
     113,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,    30,    31,     0,     0,     0,
       0,     0,    21,    22,    20,     0,     0,    39,    52,    52,
      42,    43,     7,     7,     8,     0,     0,     0,     0,   120,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
     124,     0,     0,     0,     0,    97,     0,     0,    62,     0,
       0,     0,     0,     0,    26,     0,     0,    19,     0,    28,
       0,     0,    50,     0,     0,   122,     0,     0,   118,     0,
     102,    98,    99,   100,   101,   103,     0,     0,     0,    92,
     106,   107,   105,   112,   110,   111,   109,     0,     0,     0,
       0,    77,    84,    85,     0,    79,    80,    86,     0,    36,
      32,     0,    24,    25,     0,    33,    41,     0,    58,     0,
      54,     0,     0,     0,    47,    49,   121,   115,   116,     0,
       0,    90,    91,    89,    88,     0,    75,     0,   123,     0,
      82,    96,     0,     0,    34,     0,    57,    51,     0,     0,
       0,    48,     0,     0,     0,    74,    83,     0,    35,    27,
      53,    55,    56,    94,    93,     0,    23,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,    23,  -144,  -144,  -144,   -19,  -144,  -144,
     264,  -104,  -144,  -144,  -144,   140,   -94,  -143,  -144,  -144,
     232,  -144,   235,  -144,   238,  -144,   185,  -144,    65,  -144,
    -144,  -144,   267,  -138,   214,  -144,  -144,   309,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   134,  -144,  -144,   -32,
     144,     3,   -61,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    12,    76,    18,    23,
      24,   101,   102,   103,   153,   154,    59,   104,    26,    60,
      61,    64,    65,    66,    67,    68,   161,   209,   210,   211,
     212,    15,    21,    45,    46,    47,    48,    49,    50,   230,
      51,    52,    53,   225,    54,   178,   179,    55,   144,   140,
      78,    79,    80,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      32,   158,    77,   151,   192,   155,   198,    87,   132,   197,
     176,    91,   119,   120,    70,   202,     1,   223,   133,    58,
     122,   190,    58,   123,    27,   124,   194,   106,    27,   146,
     125,   190,   126,   105,   106,   127,    62,   100,   190,   134,
     118,    28,    29,    30,    31,    28,    29,    30,    31,     5,
     207,   137,    83,   139,   224,    63,   135,   145,   191,   155,
       4,    94,    84,   195,   200,    95,   208,     6,   217,    95,
     241,   183,   184,   185,   186,   218,    85,   237,    86,   152,
     238,   242,   243,    96,   166,    10,   100,    96,    97,   167,
      98,   246,    97,   169,    98,    11,   251,   252,   115,   129,
     235,    27,    99,   130,   187,    27,   131,   204,   106,   177,
      13,   193,   116,   236,   117,    14,    17,   257,    28,    29,
      30,    31,    28,    29,    30,    31,    19,    34,    20,    22,
     100,    34,   180,   181,   182,   163,   164,   205,    25,    33,
      35,    58,    36,   256,   208,    37,    36,    38,    39,    37,
      56,    38,    39,    81,    69,    82,   226,    89,   228,   177,
      14,    92,   231,    90,    14,   108,    93,    40,   109,    41,
      42,    40,   112,    41,    42,   136,   121,   138,   113,    43,
     143,   114,   234,    43,    44,   100,   149,   150,    44,    34,
     156,   221,   159,   244,   100,   245,   122,    34,   176,   123,
     157,   124,   188,   165,    36,   196,   125,    37,   126,    38,
      39,   127,    36,   160,   248,    37,    27,    38,    39,   199,
     100,   100,    14,   168,   201,   206,   213,   219,   100,    40,
      14,    41,    42,    28,    29,    30,    31,    40,    71,    41,
      42,    43,   214,    72,   215,    73,    44,   122,   220,    43,
     123,   227,   124,   233,   229,   106,    27,   125,   232,   126,
     239,   240,   127,   249,    27,    74,   170,   171,   172,   173,
     174,   175,   253,    28,    29,    30,    31,    75,   247,   142,
     254,    28,    29,    30,    31,   122,   122,    57,   123,   123,
     124,   124,   107,   203,   162,   125,   125,   126,   126,   110,
     127,   127,   111,   250,   147,   255,   148,    88,   189,   216,
     122,   122,   222,   123,   123,   124,   124,    16,     0,     0,
     125,   125,   126,   126,   122,   127,   127,   123,     0,   124,
       0,     0,   122,     0,   125,   123,   126,   124,     0,   127,
     128,     0,   125,     0,   126,     0,     0,   127
};

static const yytype_int16 yycheck[] =
{
      19,   105,    34,    97,   142,    99,   149,    39,     3,   147,
      26,    43,    73,    74,    33,    19,    42,    17,    13,    26,
      20,    10,    26,    23,    44,    25,    10,    10,    44,    90,
      30,    10,    32,     9,    10,    35,    22,    56,    10,    34,
      72,    61,    62,    63,    64,    61,    62,    63,    64,     0,
      57,    83,     5,    85,    54,    41,    51,    89,    47,   153,
      26,     4,    15,    47,    47,     8,   160,    11,    47,     8,
     213,   132,   133,   134,   135,    47,    29,    47,    31,    98,
      50,   219,   220,    26,   116,    50,   105,    26,    31,   117,
      33,   229,    31,   121,    33,    26,   239,   240,    15,    33,
     204,    44,    45,    37,   136,    44,    40,     9,    10,   128,
      15,   143,    29,   207,    31,    39,     7,   255,    61,    62,
      63,    64,    61,    62,    63,    64,    20,     6,    26,    26,
     149,     6,   129,   130,   131,   112,   113,   156,    57,    20,
      19,    26,    21,   247,   238,    24,    21,    26,    27,    24,
      20,    26,    27,    26,    50,    63,   188,    31,   190,   178,
      39,     9,   194,    31,    39,    26,    50,    46,    26,    48,
      49,    46,    50,    48,    49,     5,    31,    26,    50,    58,
      55,    50,   201,    58,    63,   204,    29,    16,    63,     6,
      16,    19,    26,   225,   213,   227,    20,     6,    26,    23,
      50,    25,     5,    26,    21,    47,    30,    24,    32,    26,
      27,    35,    21,    31,   233,    24,    44,    26,    27,    26,
     239,   240,    39,    47,    16,    50,     9,     9,   247,    46,
      39,    48,    49,    61,    62,    63,    64,    46,    26,    48,
      49,    58,    50,    31,    50,    33,    63,    20,     9,    58,
      23,     5,    25,    33,    18,    10,    44,    30,    43,    32,
       9,     9,    35,    50,    44,    53,   122,   123,   124,   125,
     126,   127,    50,    61,    62,    63,    64,    65,    36,    52,
      50,    61,    62,    63,    64,    20,    20,    23,    23,    23,
      25,    25,    60,   153,   109,    30,    30,    32,    32,    64,
      35,    35,    64,   238,    14,    14,    92,    40,    43,    43,
      20,    20,   178,    23,    23,    25,    25,     8,    -1,    -1,
      30,    30,    32,    32,    20,    35,    35,    23,    -1,    25,
      -1,    -1,    20,    -1,    30,    23,    32,    25,    -1,    35,
      36,    -1,    30,    -1,    32,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,   128,   129,    26,     0,    11,   130,   131,   132,
      50,    26,   133,    15,    39,   158,   164,     7,   135,    20,
      26,   159,    26,   136,   137,    57,   145,    44,    61,    62,
      63,    64,   134,    20,     6,    19,    21,    24,    26,    27,
      46,    48,    49,    58,    63,   160,   161,   162,   163,   164,
     165,   167,   168,   169,   171,   174,    20,   137,    26,   143,
     146,   147,    22,    41,   148,   149,   150,   151,   152,    50,
     134,    26,    31,    33,    53,    65,   134,   176,   177,   178,
     179,    26,    63,     5,    15,    29,    31,   176,   159,    31,
      31,   176,     9,    50,     4,     8,    26,    31,    33,    45,
     134,   138,   139,   140,   144,     9,    10,   147,    26,    26,
     149,   151,    50,    50,    50,    15,    29,    31,   176,   179,
     179,    31,    20,    23,    25,    30,    32,    35,    36,    33,
      37,    40,     3,    13,    34,    51,     5,   176,    26,   176,
     176,   180,    52,    55,   175,   176,   179,    14,   161,    29,
      16,   143,   134,   141,   142,   143,    16,    50,   138,    26,
      31,   153,   153,   130,   130,    26,   176,   180,    47,   180,
     177,   177,   177,   177,   177,   177,    26,   134,   172,   173,
     178,   178,   178,   179,   179,   179,   179,   176,     5,    43,
      10,    47,   160,   176,    10,    47,    47,   160,   144,    26,
      47,    16,    19,   142,     9,   134,    50,    57,   143,   154,
     155,   156,   157,     9,    50,    50,    43,    47,    47,     9,
       9,    19,   173,    17,    54,   170,   176,     5,   176,    18,
     166,   176,    43,    33,   134,   138,   143,    47,    50,     9,
       9,   144,   160,   160,   176,   176,   160,    36,   134,    50,
     155,   144,   144,    50,    50,    14,   138,   160
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   127,   128,   129,   130,   131,   132,   132,   133,   133,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   137,
     138,   138,   138,   139,   140,   141,   141,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   145,   145,   146,
     146,   147,   148,   148,   148,   148,   148,   149,   150,   151,
     152,   153,   153,   154,   154,   155,   155,   156,   157,   158,
     159,   159,   160,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   162,   162,   162,   163,   163,   163,   163,
     163,   164,   165,   166,   166,   167,   168,   169,   170,   170,
     171,   172,   172,   173,   173,   174,   175,   175,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   178,
     178,   178,   178,   178,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   180,   180
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     4,     2,     0,     5,     4,
       1,     1,     1,     1,     1,     2,     0,     2,     1,     4,
       1,     1,     1,     6,     3,     2,     1,     4,     3,     1,
       1,     1,     3,     3,     4,     5,     3,     2,     0,     2,
       1,     4,     2,     2,     1,     1,     0,     4,     5,     4,
       3,     3,     0,     3,     1,     3,     3,     2,     1,     1,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     5,     1,     4,     1,     4,
       4,     3,     5,     2,     0,     4,     4,     8,     1,     1,
       5,     2,     1,     4,     4,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     4,     4,     1,     3,     2,
       2,     4,     3,     3,     1
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
#line 35 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING PROGRAM\n");
            }
            (yyval) = NEWNODE(TK_PROGRAM);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-2]);
            (yyval)->child[1] = (yyvsp[-1]);

            ROOT = (yyval);
        }
#line 1577 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 48 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: PROGRAM HEAD ACTUALLY IS TK_ID
            if(DEBUG){
                printf("PROGRAM HEAD:%s\n", (yyvsp[-1])->name);
            }
            (yyval) = (yyvsp[-1]);
            (yyval)->type = TK_PROGRAM_HEAD;
            (yyval)->child_number = 0;
            (yyval)->child = NULL;
        }
#line 1592 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 60 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING ROUTINE\n");
            }
            (yyval) = NEWNODE(TK_ROUTINE);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-1]);
            (yyval)->child[1] = (yyvsp[0]);
        }
#line 1606 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 71 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING ROUTINE HEAD\n");
            }
            (yyval) = NEWNODE(TK_ROUTINE_HEAD);
            (yyval)->child = MALLOC((yyval),4);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-2]);
            (yyval)->child[2] = (yyvsp[-1]);
            (yyval)->child[3] = (yyvsp[0]);
        }
#line 1622 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 84 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: IGNORE TK_CONST
            if(DEBUG){
                printf("PARSING CONST PART\n");
            }
            (yyval) = NEWNODE(TK_CONST_PART);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[-1]);
        }
#line 1636 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 93 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING CONST PART NULL\n");
            }
            (yyval) = NEWNODE(TK_CONST_PART);
            (yyval)->child_number = 0;
            (yyval)->child = NULL;
        }
#line 1649 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 103 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST\n");
                    }
                    (yyval) = NEWNODE(TK_CONST_EL);
                    (yyval)->child = MALLOC((yyval),3);
                    (yyval)->child[0] = (yyvsp[-4]);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[-1]);    
                }
#line 1665 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 114 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST : FIRST ONE\n");
                    }
                    (yyval) = NEWNODE(TK_CONST_EL);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-3]);
                    (yyval)->child[1] = (yyvsp[-1]);
                }
#line 1680 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 126 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE INTEGER\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1691 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 132 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE REAL\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1702 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 138 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE CHAR\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1713 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 144 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE STRING\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1724 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 150 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE SYS CON\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1735 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 158 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TYPE
            if(DEBUG){
                printf("PARSING TYPE PART NULL\n");
            }
            (yyval) = NEWNODE(TK_TYPE_PART);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);
        }
#line 1749 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 167 "syntax.y" /* yacc.c:1661  */
    {
              //NOTE: IGNORE TYPE
                  if(DEBUG){
                      printf("PARSING TYPE PART NULL\n");
                  }
                  (yyval) = NEWNODE(TK_TYPE_PART);
                (yyval)->child_number = 0;
                (yyval)->child = NULL;
        }
#line 1763 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 178 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST DEF\n");
                    }
                    (yyval) = NEWNODE(TK_TYPE_DL);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-1]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 1777 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 187 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST\n");
                    }
                    (yyval) = NEWNODE(TK_TYPE_DL);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
               }
#line 1790 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 197 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DEF\n");
                    }
                    (yyval) = NEWNODE(TK_TYPE_DEF);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-3]);
                    (yyval)->child[1] = (yyvsp[-1]);
                }
#line 1804 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 208 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
          }
#line 1817 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 216 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
          }
#line 1830 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 224 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
          }
#line 1843 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 234 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_LB TK_RB TK_OF
                if(DEBUG){
                    printf("PARSING ARRAY\n");
                }
                (yyval) = NEWNODE(TK_ARRAY);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 1858 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 246 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_END
                if(DEBUG){
                    printf("PARSING RECORD TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_RECORD);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[-1]);
            }
#line 1872 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 257 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST\n");
                }
                (yyval) = NEWNODE(TK_FIELD_DL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 1886 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 266 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_FIELD_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 1899 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 276 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
                if(DEBUG){
                    printf("PARSING FIELD DECL\n");
                }
                (yyval) = NEWNODE(TK_FIELD_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);
            }
#line 1914 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 288 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
                if(DEBUG){
                    printf("PARSING NAME LIST\n");
                }
                (yyval) = NEWNODE(TK_NL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 1929 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 298 "syntax.y" /* yacc.c:1661  */
    {
                  if(DEBUG){
                      printf("PARSING NAME LIST : FIRST ONE\n");
                  }
                  (yyval) = NEWNODE(TK_NL);
                  (yyval)->child = MALLOC((yyval),1);
                  (yyval)->child[0] = (yyvsp[0]);
              }
#line 1942 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 308 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
                    }
                    (yyval) = NEWNODE(TK_STD_SYS_TYPE);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 1956 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 317 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_ID);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 1969 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 325 "syntax.y" /* yacc.c:1661  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_NL);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[-1]);
                }
#line 1982 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 333 "syntax.y" /* yacc.c:1661  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 1996 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 342 "syntax.y" /* yacc.c:1661  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD);
                    (yyval)->child = MALLOC((yyval),3);
                    (yyval)->child[0] = (yyvsp[-3]);
                    (yyval)->child[1] = (yyvsp[-2]);
                    (yyval)->child[2] = (yyvsp[0]);
                }
#line 2011 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 352 "syntax.y" /* yacc.c:1661  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD);
                    (yyval)->child = MALLOC((yyval),4);
                    (yyval)->child[0] = (yyvsp[-4]);
                    (yyval)->child[1] = (yyvsp[-3]);
                    (yyval)->child[2] = (yyvsp[-1]);
                    (yyval)->child[3] = (yyvsp[0]);
                }
#line 2027 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 363 "syntax.y" /* yacc.c:1661  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 2041 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 374 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: IGNORE TK_VAR
            if(DEBUG){
                  printf("PARSING VAR PART NULL\n");
              }
              (yyval) = NEWNODE(TK_VAR_PART);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);
        }
#line 2055 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 383 "syntax.y" /* yacc.c:1661  */
    {
              if(DEBUG){
                  printf("PARSING VAR PART NULL\n");
              }
              (yyval) = NEWNODE(TK_VAR_PART);
            (yyval)->child_number = 0;
            (yyval)->child = NULL;
        }
#line 2068 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 393 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING VAR DECL LIST\n");
                }
                (yyval) = NEWNODE(TK_DL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2082 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 402 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING VAR DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2095 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 412 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING VAR DECL\n");
            }
            (yyval) = NEWNODE(TK_VAR_DECL);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 2110 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 424 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2124 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 433 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2138 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 442 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2151 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 450 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2164 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 458 "syntax.y" /* yacc.c:1661  */
    {
                 if(DEBUG){
                     printf("PARSING ROUTINE_PART NULL\n");
                 }
                 (yyval) = NEWNODE(TK_ROUTINE_PART);
                 (yyval)->child_number = 0;
                 (yyval)->child = NULL;
             }
#line 2177 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 468 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_SEMI
                if(DEBUG){
                    printf("PARSING FUNC DECL\n");
                }
                (yyval) = NEWNODE(TK_FUNC_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);
            }
#line 2192 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 480 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_FUNCTION TK_COLON
                if(DEBUG){
                    printf("PARSING TK_FUNCTINO HEAD\n");
                }
                (yyval) = NEWNODE(TK_FUNC_HEAD);
                (yyval)->child = MALLOC((yyval),3);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2208 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 493 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
                if(DEBUG){
                    printf("PARSING PROC DECL\n");
                }
                (yyval) = NEWNODE(TK_PROC_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);
            }
#line 2223 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 505 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_PROCEDURE  PROCEDURE_HEAD IS 'TK_PROC_HEAD'
                if(DEBUG){
                    printf("PARSING PROC HEAD\n");
                }
                (yyval) = NEWNODE(TK_PROC_HEAD);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2238 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 517 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
                if(DEBUG){
                    printf("PARSING PARA\n");
                }
                (yyval) = NEWNODE(TK_PARA);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[-1]);
            }
#line 2252 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 526 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: PARAMETERS IS 'TK_PARA'
                if(DEBUG){
                    printf("PARSING PARA NULL\n");
                }
                (yyval) = NEWNODE(TK_PARA);
                (yyval)->child_number = 0;
                (yyval)->child = NULL;
            }
#line 2266 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 537 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST\n");
                }
                (yyval) = NEWNODE(TK_PARA_DL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2281 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 547 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_PARA_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2295 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 558 "syntax.y" /* yacc.c:1661  */
    {
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    (yyval) = NEWNODE(TK_PARA_TL);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 2310 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 568 "syntax.y" /* yacc.c:1661  */
    {
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    (yyval) = NEWNODE(TK_PARA_TL);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 2325 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 580 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
                if(DEBUG){
                    printf("PARSING VAR LIST\n");
                }
                (yyval) = NEWNODE(TK_VAR);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2339 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 591 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING VAL PARA LIST\n");
                }
                (yyval) = NEWNODE(TK_VAL_PARA_LIST);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2352 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 601 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE BODY\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2365 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 611 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING STMT LIST\n");
            }
            (yyval) = NEWNODE(TK_STMT_LIST);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-2]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 2379 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 620 "syntax.y" /* yacc.c:1661  */
    {
              if(DEBUG){
                  printf("PARSING STMT LIST NULL\n");
              }
              (yyval) = NEWNODE(TK_STMT_LIST);
              (yyval)->child_number = 0;
              (yyval)->child = NULL;
        }
#line 2392 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 630 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: IGNORE TK_COLON
        if(DEBUG){
            printf("PARSING STMT\n");
        }
        (yyval) = NEWNODE(TK_STMT);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
    }
#line 2407 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 640 "syntax.y" /* yacc.c:1661  */
    {
         //NOTE: IGNORE TK_COLON
         if(DEBUG){
             printf("PARSING NON LABEL STMT\n");
         }
         (yyval) = NEWNODE(TK_STMT);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);
     }
#line 2421 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 651 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING ASSIGN STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2434 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 659 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING PROC STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2447 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 667 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING CP STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2460 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 675 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING IF STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2473 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 683 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING REPEAT STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2486 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 691 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING WHILE STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2499 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 699 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING FOR STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2512 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 707 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING CASE STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2525 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 715 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING GOTO STMT\n");
                    }
                    (yyval) = NEWNODE(TK_NON_LABEL_STMT);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2538 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 725 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_ASSIGN
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                (yyval) = NEWNODE(TK_ASSIGN_ID);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2553 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 735 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                (yyval) = NEWNODE(TK_ASSIGN_ID_EXPR);
                (yyval)->child = MALLOC((yyval),3);
                (yyval)->child[0] = (yyvsp[-5]);
                (yyval)->child[1] = (yyvsp[-3]);
                (yyval)->child[2] = (yyvsp[0]);
            }
#line 2569 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 746 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                (yyval) = NEWNODE(TK_ASSIGN_DD);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-4]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyvsp[-4])->attr = (yyvsp[-2]);
            }
#line 2586 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 760 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_ID);
           (yyval)->child = MALLOC((yyval),1);
           (yyval)->child[0] = (yyvsp[0]);
        }
#line 2599 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 768 "syntax.y" /* yacc.c:1661  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_ID_ARGS);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2614 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 778 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_SYS);
           (yyval)->child = MALLOC((yyval),1);
           (yyval)->child[0] = (yyvsp[0]);
        }
#line 2627 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 786 "syntax.y" /* yacc.c:1661  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_SYS_ARGS);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2642 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 796 "syntax.y" /* yacc.c:1661  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_READ);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);
          }
#line 2657 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 808 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING CP STMT\n");
            }
            (yyval) = NEWNODE(TK_CP_STMT);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[-1]);
        }
#line 2670 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 818 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_IF TK_THEN
            if(DEBUG){
                printf("PARSING IF STMT\n");
            }
            (yyval) = NEWNODE(TK_IF);
            (yyval)->child = MALLOC((yyval),3);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);
            (yyval)->child[2] = (yyvsp[0]);
        }
#line 2686 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 831 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE\n");
                }
                (yyval) = NEWNODE(TK_ELSE);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
            }
#line 2699 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 839 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE NULL\n");
                }
                (yyval) = NEWNODE(TK_ELSE);
                (yyval)->child_number = 0;
                (yyval)->child = NULL;
            }
#line 2712 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 849 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_REPEAR TK_UNTIL
                if(DEBUG){
                    printf("PARSING REPEAT STMT\n");
                }
                (yyval) = NEWNODE(TK_REPEAT);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2727 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 861 "syntax.y" /* yacc.c:1661  */
    {
                //NOTE: IGNORE TK_WHILE TK_DO
                if(DEBUG){
                    printf("PARSING WHILE STMT\n");
                }
                (yyval) = NEWNODE(TK_WHILE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
            }
#line 2742 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 873 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
            if(DEBUG){
                printf("PARSING FOR STMT\n");
            }
            (yyval) = NEWNODE(TK_FOR);
            (yyval)->child = MALLOC((yyval),5);
            (yyval)->child[0] = (yyvsp[-6]);
            (yyval)->child[1] = (yyvsp[-4]);
            (yyval)->child[2] = (yyvsp[-3]);
            (yyval)->child[3] = (yyvsp[-2]);
            (yyval)->child[4] = (yyvsp[0]);
        }
#line 2760 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 888 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR TO\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 2772 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 895 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR DOWNTO\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 2784 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 904 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_CASE TK_OF TK_END
            if(DEBUG){
                printf("PARSING CASE STMT\n");
            }
            (yyval) = NEWNODE(TK_CASE);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 2799 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 916 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST\n");
            }
            (yyval) = NEWNODE(TK_CASE_EL);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-1]);
            (yyval)->child[1] = (yyvsp[0]);
        }
#line 2814 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 926 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST : FIRST ONE\n");
            }
            (yyval) = NEWNODE(TK_CASE_EL);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);
        }
#line 2828 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 937 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            (yyval) = NEWNODE(TK_CASE_EXPR);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 2843 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 947 "syntax.y" /* yacc.c:1661  */
    {
         //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            (yyval) = NEWNODE(TK_CASE_EXPR);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 2858 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 959 "syntax.y" /* yacc.c:1661  */
    {
        //NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
            if(DEBUG){
                printf("PARSING GOTO STMT\n");
            }
            (yyval) = (yyvsp[0]);
            (yyval)->type = TK_GOTO;
        }
#line 2871 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 969 "syntax.y" /* yacc.c:1661  */
    {
                    //NOTE: IGNORE TK_COMMA
                    if(DEBUG){
                        printf("PARSING EXP LIST\n");
                    }
                    (yyval) = NEWNODE(TK_EXP_LIST);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);
                }
#line 2886 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 979 "syntax.y" /* yacc.c:1661  */
    {
                    if(DEBUG){
                        printf("PARSING EXP LIST : FIRST ONE\n");
                    }
                    (yyval) = NEWNODE(TK_EXP_LIST);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                }
#line 2899 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 989 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_GE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2914 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 999 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_GT);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2928 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 1008 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_LE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2942 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 1017 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_LT);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2956 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 1026 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_EQUAL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2970 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 1035 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_UNEQUAL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);
           }
#line 2984 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 1044 "syntax.y" /* yacc.c:1661  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_EXP);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
           }
#line 2997 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 1054 "syntax.y" /* yacc.c:1661  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_PLUS);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3012 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 1064 "syntax.y" /* yacc.c:1661  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_MINUS);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3027 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 1074 "syntax.y" /* yacc.c:1661  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_OR);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3042 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 1084 "syntax.y" /* yacc.c:1661  */
    {
     //NOTE: expr IS EXPR, expression IS EXP
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_EXPR);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);
     }
#line 3056 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 1095 "syntax.y" /* yacc.c:1661  */
    {
         if(DEBUG){
             printf("PARSING TK_MUL\n");
         }
         (yyval) = NEWNODE(TK_MUL);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3070 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 1104 "syntax.y" /* yacc.c:1661  */
    {
         if(DEBUG){
             printf("PARSING TK_DIV\n");
         }
         (yyval) = NEWNODE(TK_DIV);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3084 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 1113 "syntax.y" /* yacc.c:1661  */
    {
         if(DEBUG){
             printf("PARSING TK_MOD\n");
         }
         (yyval) = NEWNODE(TK_MOD);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3097 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 1121 "syntax.y" /* yacc.c:1661  */
    {
         if(DEBUG){
             printf("PARSING TK_AND\n");
         }
         (yyval) = NEWNODE(TK_AND);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);
     }
#line 3111 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 1130 "syntax.y" /* yacc.c:1661  */
    {
         if(DEBUG){
             printf("PARSING TERM : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_TERM);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);
     }
#line 3124 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 1140 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
        if(DEBUG){
            printf("PARSING FACTOR\n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
    }
#line 3138 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 1149 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID_ARGS);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
    }
#line 3153 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 1159 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_SYS_FUNCT);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
    }
#line 3168 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 1169 "syntax.y" /* yacc.c:1661  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_CONST);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
    }
#line 3181 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 1177 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_EXP);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[-1]);
    }
#line 3195 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 1186 "syntax.y" /* yacc.c:1661  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_NOT);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
    }
#line 3208 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 1194 "syntax.y" /* yacc.c:1661  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_MINUS);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
    }
#line 3221 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 1202 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: IGNORE TK_LB TK_RB
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID_EXP);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
    }
#line 3236 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 1212 "syntax.y" /* yacc.c:1661  */
    {
    //NOTE: ID->ID IS IN ONE NODE
        if(DEBUG){
            printf("PARSING FACTOR FOR ID->ID\n");
        }
        (yyval) = NEWNODE(TK_FACTOR_DD);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[-2]);
        (yyvsp[-2])->attr = (yyvsp[-1]);
    }
#line 3251 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 1224 "syntax.y" /* yacc.c:1661  */
    {
            //NOTE: IGNORE TK_COMMA
            if(DEBUG){
                printf("PARSING ARGS LIST\n");
            }
            (yyval) = NEWNODE(TK_ARGS_LIST);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-2]);
            (yyval)->child[1] = (yyvsp[-1]);
        }
#line 3266 "yy.tab.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 1234 "syntax.y" /* yacc.c:1661  */
    {
            if(DEBUG){
                printf("PARSING ARGS LIST : FIRST ONE\n");
            }
            (yyval) = NEWNODE(TK_ARGS_LIST);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);
        }
#line 3279 "yy.tab.cpp" /* yacc.c:1661  */
    break;


#line 3283 "yy.tab.cpp" /* yacc.c:1661  */
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
#line 1244 "syntax.y" /* yacc.c:1906  */


int yyerror(char* s){
    extern char* yytext;
    printf("\n");
    printf( "%s\n", s);
    //fprintf(stderr, "line %d: ", yylineno);
    fprintf(stderr, "\"%s\"\n", yytext);
    return 1;
}

