
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 20 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* yytext;
extern int yylineno;
extern FILE* yyin;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)
#define NEWNODE (NODE*)malloc(NODE_SIZE)
#define MALLOC(num) (NODE**)malloc(NODE_POINTER_SIZE*num)

void cpString(char** str1, char** str2);

int DEBUG=1;


/* Line 189 of yacc.c  */
#line 93 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 "syntax.y"

typedef struct NODE{
    char* name;
    char* str;
    char ch;
    int type;
    int ival;
    double dval;
    int child_number;
    struct NODE** child;

    struct NODE* attr;
}NODE;

#define YYSTYPE NODE*

NODE* ROOT;



/* Line 209 of yacc.c  */
#line 138 "y.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     TK_EXPR = 373
   };
#endif
/* Tokens.  */
#define TK_AND 258
#define TK_ARRAY 259
#define TK_ASSIGN 260
#define TK_CASE 261
#define TK_TYPE 262
#define TK_SYS_TYPE 263
#define TK_COLON 264
#define TK_COMMA 265
#define TK_CONST 266
#define TK_DIGITS 267
#define TK_DIV 268
#define TK_DO 269
#define TK_DOT 270
#define TK_DOTDOT 271
#define TK_DOWNTO 272
#define TK_ELSE 273
#define TK_END 274
#define TK_EQUAL 275
#define TK_FOR 276
#define TK_FUNCTION 277
#define TK_GE 278
#define TK_GOTO 279
#define TK_GT 280
#define TK_ID 281
#define TK_IF 282
#define TK_IN 283
#define TK_LB 284
#define TK_LE 285
#define TK_LP 286
#define TK_LT 287
#define TK_MINUS 288
#define TK_MOD 289
#define TK_UNEQUAL 290
#define TK_OF 291
#define TK_OR 292
#define TK_OTHERWISE 293
#define TK_BEGIN 294
#define TK_PLUS 295
#define TK_PROCEDURE 296
#define TK_PROGRAM 297
#define TK_RB 298
#define TK_REAL 299
#define TK_RECORD 300
#define TK_REPEAT 301
#define TK_RP 302
#define TK_SYS_PROC 303
#define TK_READ 304
#define TK_SEMI 305
#define TK_MUL 306
#define TK_THEN 307
#define TK_NOT 308
#define TK_TO 309
#define TK_UNTIL 310
#define TK_UPARROW 311
#define TK_VAR 312
#define TK_WHILE 313
#define TK_SET 314
#define TK_STARSTAR 315
#define TK_CHAR 316
#define TK_STRING 317
#define TK_INTEGER 318
#define TK_SYS_CON 319
#define TK_SYS_FUNCT 320
#define TK_WITH 321
#define TK_NIL 322
#define ERROR 323
#define TK_PROGRAM_HEAD 324
#define TK_ROUTINE 325
#define TK_ROUTINE_HEAD 326
#define TK_ROUTINE_BODY 327
#define TK_CONST_PART 328
#define TK_TYPE_PART 329
#define TK_VAR_PART 330
#define TK_ROUTINE_PART 331
#define TK_STMT_LIST 332
#define TK_STMT 333
#define TK_CP_STMT 334
#define TK_VAL_PARA_LIST 335
#define TK_NON_LABEL_STMT 336
#define TK_EXP_LIST 337
#define TK_EXP 338
#define TK_TERM 339
#define TK_FACTOR_ID 340
#define TK_FACTOR_ID_ARGS 341
#define TK_FACTOR_SYS_FUNCT 342
#define TK_FACTOR_CONST 343
#define TK_FACTOR_EXP 344
#define TK_FACTOR_NOT 345
#define TK_FACTOR_MINUS 346
#define TK_FACTOR_ID_EXP 347
#define TK_FACTOR_DD 348
#define TK_ARGS_LIST 349
#define TK_CONST_EL 350
#define TK_TYPE_DL 351
#define TK_TYPE_DEF 352
#define TK_TYPE_DECL 353
#define TK_FIELD_DL 354
#define TK_FIELD_DECL 355
#define TK_NL 356
#define TK_STD_SYS_TYPE 357
#define TK_STD_ID 358
#define TK_STD_NL 359
#define TK_STD_DD 360
#define TK_DL 361
#define TK_VAR_DECL 362
#define TK_FUNC_DECL 363
#define TK_FUNC_HEAD 364
#define TK_PROC_DECL 365
#define TK_PROC_HEAD 366
#define TK_PARA 367
#define TK_PARA_DL 368
#define TK_PARA_TL 369
#define TK_PROC 370
#define TK_CASE_EL 371
#define TK_CASE_EXPR 372
#define TK_EXPR 373




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 397 "y.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   373

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    19,    22,    23,    29,
      34,    36,    38,    40,    42,    44,    47,    48,    51,    53,
      58,    60,    62,    64,    71,    75,    78,    80,    85,    89,
      91,    93,    95,    99,   103,   108,   114,   118,   121,   122,
     125,   127,   132,   135,   138,   140,   142,   143,   148,   154,
     159,   163,   167,   168,   172,   174,   178,   182,   185,   187,
     189,   193,   194,   198,   200,   202,   204,   206,   208,   210,
     212,   214,   216,   218,   222,   229,   235,   237,   242,   244,
     249,   254,   258,   264,   267,   268,   273,   278,   287,   289,
     291,   297,   300,   302,   307,   312,   315,   319,   321,   325,
     329,   333,   337,   341,   345,   347,   351,   355,   359,   361,
     365,   369,   373,   377,   379,   381,   386,   391,   393,   397,
     400,   403,   408,   412,   416
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     120,     0,    -1,   121,   122,    15,    -1,    42,    26,    50,
      -1,   123,   150,    -1,   124,   127,   137,   140,    -1,    11,
     125,    -1,    -1,   125,    26,    20,   126,    50,    -1,    26,
      20,   126,    50,    -1,    63,    -1,    44,    -1,    61,    -1,
      62,    -1,    64,    -1,     7,   128,    -1,    -1,   128,   129,
      -1,   129,    -1,    26,    20,   130,    50,    -1,   136,    -1,
     131,    -1,   132,    -1,     4,    29,   136,    43,    36,   130,
      -1,    45,   133,    19,    -1,   133,   134,    -1,   134,    -1,
     135,     9,   130,    50,    -1,   135,    10,    26,    -1,    26,
      -1,     8,    -1,    26,    -1,    31,   135,    47,    -1,   126,
      16,   126,    -1,    33,   126,    16,   126,    -1,    33,   126,
      16,    33,   126,    -1,    26,    16,    26,    -1,    57,   138,
      -1,    -1,   138,   139,    -1,   139,    -1,   135,     9,   130,
      50,    -1,   140,   141,    -1,   140,   143,    -1,   141,    -1,
     143,    -1,    -1,   142,    50,   122,    50,    -1,    22,    26,
     145,     9,   136,    -1,   144,    50,   122,    50,    -1,    41,
      26,   145,    -1,    31,   146,    47,    -1,    -1,   146,    50,
     147,    -1,   147,    -1,   148,     9,   136,    -1,   149,     9,
     136,    -1,    57,   135,    -1,   135,    -1,   156,    -1,   151,
     152,    50,    -1,    -1,    63,     9,   153,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   159,    -1,
     160,    -1,   161,    -1,   163,    -1,   166,    -1,    26,     5,
     168,    -1,    26,    29,   168,    43,     5,   168,    -1,    26,
      15,    26,     5,   168,    -1,    26,    -1,    26,    31,   172,
      47,    -1,    48,    -1,    48,    31,   167,    47,    -1,    49,
      31,   171,    47,    -1,    39,   151,    19,    -1,    27,   168,
      52,   152,   158,    -1,    18,   152,    -1,    -1,    46,   151,
      55,   168,    -1,    58,   168,    14,   152,    -1,    21,    26,
       5,   168,   162,   168,    14,   152,    -1,    54,    -1,    17,
      -1,     6,   168,    36,   164,    19,    -1,   164,   165,    -1,
     165,    -1,   126,     9,   152,    50,    -1,    26,     9,   152,
      50,    -1,    24,    63,    -1,   167,    10,   168,    -1,   168,
      -1,   168,    23,   169,    -1,   168,    25,   169,    -1,   168,
      30,   169,    -1,   168,    32,   169,    -1,   168,    20,   169,
      -1,   168,    35,   169,    -1,   169,    -1,   169,    40,   170,
      -1,   169,    33,   170,    -1,   169,    37,   170,    -1,   170,
      -1,   170,    51,   171,    -1,   170,    13,   171,    -1,   170,
      34,   171,    -1,   170,     3,   171,    -1,   171,    -1,    26,
      -1,    26,    31,   172,    47,    -1,    65,    31,   172,    47,
      -1,   126,    -1,    31,   168,    47,    -1,    53,   171,    -1,
      33,   171,    -1,    26,    29,   168,    43,    -1,    26,    15,
      26,    -1,   172,    10,   168,    -1,   168,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    78,    91,   104,   119,   130,   141,   154,
     168,   178,   188,   198,   208,   220,   231,   243,   254,   266,
     279,   289,   299,   311,   325,   338,   349,   361,   375,   387,
     399,   410,   420,   430,   441,   452,   463,   476,   487,   498,
     509,   521,   535,   546,   557,   567,   577,   588,   602,   617,
     631,   645,   656,   668,   680,   693,   705,   719,   732,   744,
     756,   767,   778,   790,   803,   813,   823,   833,   843,   853,
     863,   873,   883,   895,   907,   920,   936,   946,   958,   968,
     980,   994,  1006,  1021,  1031,  1042,  1056,  1070,  1087,  1095,
    1105,  1119,  1131,  1144,  1156,  1170,  1181,  1193,  1205,  1217,
    1228,  1239,  1250,  1261,  1272,  1284,  1296,  1308,  1320,  1333,
    1344,  1355,  1366,  1377,  1389,  1400,  1412,  1424,  1434,  1445,
    1455,  1465,  1477,  1491,  1503
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "TK_PROC", "TK_CASE_EL", "TK_CASE_EXPR", "TK_EXPR", "$accept", "program",
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
  "term", "factor", "args_list", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   121,   122,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   129,
     130,   130,   130,   131,   132,   133,   133,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   138,
     138,   139,   140,   140,   140,   140,   140,   141,   142,   143,
     144,   145,   145,   146,   146,   147,   147,   148,   149,   150,
     151,   151,   152,   152,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   154,   154,   154,   155,   155,   155,   155,
     155,   156,   157,   158,   158,   159,   160,   161,   162,   162,
     163,   164,   164,   165,   165,   166,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   169,   169,   170,
     170,   170,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   172,   172
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
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

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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
       0,    42,   120,   121,    26,     0,    11,   122,   123,   124,
      50,    26,   125,    15,    39,   150,   156,     7,   127,    20,
      26,   151,    26,   128,   129,    57,   137,    44,    61,    62,
      63,    64,   126,    20,     6,    19,    21,    24,    26,    27,
      46,    48,    49,    58,    63,   152,   153,   154,   155,   156,
     157,   159,   160,   161,   163,   166,    20,   129,    26,   135,
     138,   139,    22,    41,   140,   141,   142,   143,   144,    50,
     126,    26,    31,    33,    53,    65,   126,   168,   169,   170,
     171,    26,    63,     5,    15,    29,    31,   168,   151,    31,
      31,   168,     9,    50,     4,     8,    26,    31,    33,    45,
     126,   130,   131,   132,   136,     9,    10,   139,    26,    26,
     141,   143,    50,    50,    50,    15,    29,    31,   168,   171,
     171,    31,    20,    23,    25,    30,    32,    35,    36,    33,
      37,    40,     3,    13,    34,    51,     5,   168,    26,   168,
     168,   172,    52,    55,   167,   168,   171,    14,   153,    29,
      16,   135,   126,   133,   134,   135,    16,    50,   130,    26,
      31,   145,   145,   122,   122,    26,   168,   172,    47,   172,
     169,   169,   169,   169,   169,   169,    26,   126,   164,   165,
     170,   170,   170,   171,   171,   171,   171,   168,     5,    43,
      10,    47,   152,   168,    10,    47,    47,   152,   136,    26,
      47,    16,    19,   134,     9,   126,    50,    57,   135,   146,
     147,   148,   149,     9,    50,    50,    43,    47,    47,     9,
       9,    19,   165,    17,    54,   162,   168,     5,   168,    18,
     158,   168,    43,    33,   126,   130,   135,    47,    50,     9,
       9,   136,   152,   152,   168,   168,   152,    36,   126,    50,
     147,   136,   136,    50,    50,    14,   130,   152
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 63 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING PROGRAM\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_PROGRAM;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (3)]);
			(yyval)->child[1] = (yyvsp[(2) - (3)]);

			ROOT = (yyval);
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 78 "syntax.y"
    {
			if(DEBUG){
				printf("PROGRAM HEAD:%s\n", (yyvsp[(2) - (3)])->name);
			}
			(yyval) = NEWNODE;
			(yyval) = (yyvsp[(2) - (3)]);
			(yyval)->type = TK_PROGRAM_HEAD;
			cpString(&((yyval)->name), &((yyvsp[(2) - (3)])->name));
			(yyval)->child_number = 0;
			(yyval)->child = NULL;
		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 91 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING ROUTINE\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_ROUTINE;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (2)]);
			(yyval)->child[1] = (yyvsp[(2) - (2)]);
		}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 104 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING ROUTINE HEAD\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_ROUTINE_HEAD;
			(yyval)->child_number = 4;
			(yyval)->child = MALLOC(4);
			(yyval)->child[0] = (yyvsp[(1) - (4)]);
			(yyval)->child[1] = (yyvsp[(2) - (4)]);
			(yyval)->child[2] = (yyvsp[(3) - (4)]);
			(yyval)->child[3] = (yyvsp[(4) - (4)]);
		}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 119 "syntax.y"
    {
		//NOTE: IGNORE TK_CONST
			if(DEBUG){
				printf("PARSING CONST PART\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CONST_PART;
			(yyval)->child_number = 0;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(1) - (2)]);
		}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 130 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING CONST PART NULL\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CONST_PART;
			(yyval)->child_number = 0;
			(yyval)->child = NULL;
		}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 141 "syntax.y"
    {
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_CONST_EL;
					(yyval)->child_number = 3;
					(yyval)->child = MALLOC(3);
					(yyval)->child[0] = (yyvsp[(1) - (5)]);
					(yyval)->child[1] = (yyvsp[(2) - (5)]);
					(yyval)->child[2] = (yyvsp[(4) - (5)]);	
				}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 154 "syntax.y"
    {
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST : FIRST ONE\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_CONST_EL;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (4)]);
					(yyval)->child[1] = (yyvsp[(3) - (4)]);
				}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 168 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING COSNT VALUE INTEGER\n");
				}
				(yyval) = NEWNODE;
				(yyval) = (yyvsp[(1) - (1)]);
				(yyval)->type = TK_INTEGER;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 178 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING COSNT VALUE REAL\n");
				}
				(yyval) = NEWNODE;
				(yyval) = (yyvsp[(1) - (1)]);
				(yyval)->type = TK_REAL;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 188 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING COSNT VALUE CHAR\n");
				}
				(yyval) = NEWNODE;
				(yyval) = (yyvsp[(1) - (1)]);
				(yyval)->type = TK_CHAR;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 198 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING COSNT VALUE STRING\n");
				}
				(yyval) = NEWNODE;
				(yyval) = (yyvsp[(1) - (1)]);
				(yyval)->type = TK_STRING;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 208 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING COSNT VALUE SYS CON\n");
				}
				(yyval) = NEWNODE;
				(yyval) = (yyvsp[(1) - (1)]);
				(yyval)->type = TK_SYS_CON;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 220 "syntax.y"
    {
			//NOTE: IGNORE TYPE
			if(DEBUG){
				printf("PARSING TYPE PART NULL\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_TYPE_PART;
			(yyval)->child_number = 1;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(2) - (2)]);
		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    {
		  	//NOTE: IGNORE TYPE
		  		if(DEBUG){
		  			printf("PARSING TYPE PART NULL\n");
		  		}
		  		(yyval) = NEWNODE;
		  		(yyval)->type = TK_TYPE_PART;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
		}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 243 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING TYPE DECL LIST DEF\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_TYPE_DL;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (2)]);
					(yyval)->child[1] = (yyvsp[(2) - (2)]);
				}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 254 "syntax.y"
    {
			   		if(DEBUG){
						printf("PARSING TYPE DECL LIST\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_TYPE_DL;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
			   }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 266 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING TYPE DEF\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_TYPE_DEF;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (4)]);
					(yyval)->child[1] = (yyvsp[(3) - (4)]);
				}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 279 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_TYPE_DECL;
				(yyval)->child_number =  1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
		  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 289 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_TYPE_DECL;
				(yyval)->child_number =  1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
		  }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 299 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_TYPE_DECL;
				(yyval)->child_number =  1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
		  }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 311 "syntax.y"
    {
				//NOTE: IGNORE TK_LB TK_RB TK_OF
				if(DEBUG){
					printf("PARSING ARRAY\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ARRAY;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(3) - (6)]);
				(yyval)->child[1] = (yyvsp[(6) - (6)]);
			}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 325 "syntax.y"
    {
				//NOTE: IGNORE TK_END
				if(DEBUG){
					printf("PARSING RECORD TYPE DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_RECORD;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(2) - (3)]);
			}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 338 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING FIELD DECL LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_FIELD_DL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (2)]);
				(yyval)->child[1] = (yyvsp[(2) - (2)]);
			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 349 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING FIELD DECL LIST : FIRST ONE\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_FIELD_DL;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 361 "syntax.y"
    {
			//NOTE: IGNORE TK_COLON TK_SEMI
				if(DEBUG){
					printf("PARSING FIELD DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_FIELD_DECL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (4)]);
				(yyval)->child[1] = (yyvsp[(3) - (4)]);
			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 375 "syntax.y"
    {
			//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
				if(DEBUG){
					printf("PARSING NAME LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_NL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (3)]);
				(yyval)->child[1] = (yyvsp[(3) - (3)]);
			}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 387 "syntax.y"
    {
		  		if(DEBUG){
		  			printf("PARSING NAME LIST : FIRST ONE\n");
		  		}
		  		(yyval) = NEWNODE;
		  		(yyval)->type = TK_NL;
		  		(yyval)->child_number = 1;
		  		(yyval)->child = MALLOC(1);
		  		(yyval)->child[0] = (yyvsp[(1) - (1)]);
		  	}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 399 "syntax.y"
    {
				//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_SYS_TYPE;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 410 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_ID;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 420 "syntax.y"
    {
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_NL;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(2) - (3)]);
				}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 430 "syntax.y"
    {
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_DD;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (3)]);
					(yyval)->child[1] = (yyvsp[(3) - (3)]);
				}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 441 "syntax.y"
    {
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_DD;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (4)]);
					(yyval)->child[1] = (yyvsp[(3) - (4)]);
				}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 452 "syntax.y"
    {
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_DD;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (5)]);
					(yyval)->child[1] = (yyvsp[(3) - (5)]);
				}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 463 "syntax.y"
    {
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_STD_DD;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (3)]);
					(yyval)->child[1] = (yyvsp[(3) - (3)]);
				}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 476 "syntax.y"
    {
		//NOTE: IGNORE TK_VAR
			if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	(yyval) = NEWNODE;
		  	(yyval)->type = TK_VAR_PART;
			(yyval)->child_number = 1;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(2) - (2)]);
		}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 487 "syntax.y"
    {
		  	if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	(yyval) = NEWNODE;
		  	(yyval)->type = TK_VAR_PART;
			(yyval)->child_number = 0;
			(yyval)->child = NULL;
		}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 498 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING VAR DECL LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_DL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (2)]);
				(yyval)->child[1] = (yyvsp[(2) - (2)]);
			}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 509 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING VAR DECL LIST : FIRST ONE\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_DL;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 521 "syntax.y"
    {
			//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING VAR DECL\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_VAR_DECL;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (4)]);
			(yyval)->child[1] = (yyvsp[(3) - (4)]);
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 535 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ROUTINE_PART;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (2)]);
				(yyval)->child[1] = (yyvsp[(2) - (2)]);
			}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 546 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ROUTINE_PART;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (2)]);
				(yyval)->child[1] = (yyvsp[(2) - (2)]);
			}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 557 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ROUTINE_PART;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 567 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ROUTINE_PART;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 577 "syntax.y"
    {
			 	if(DEBUG){
			 		printf("PARSING ROUTINE_PART NULL\n");
			 	}
			 	(yyval) = NEWNODE;
			 	(yyval)->type = TK_ROUTINE_PART;
			 	(yyval)->child_number = 0;
			 	(yyval)->child = NULL;
			 }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 588 "syntax.y"
    {
				//NOTE: IGNORE TK_SEMI
				if(DEBUG){
					printf("PARSING FUNC DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_FUNC_DECL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (4)]);
				(yyval)->child[1] = (yyvsp[(3) - (4)]);
			}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 602 "syntax.y"
    {
				//NOTE: IGNORE TK_FUNCTION TK_COLON
				if(DEBUG){
					printf("PARSING TK_FUNCTINO HEAD\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_FUNC_HEAD;
				(yyval)->child_number = 3;
				(yyval)->child = MALLOC(3);
				(yyval)->child[0] = (yyvsp[(2) - (5)]);
				(yyval)->child[1] = (yyvsp[(3) - (5)]);
				(yyval)->child[2] = (yyvsp[(5) - (5)]);
			}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 617 "syntax.y"
    {
				//NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
				if(DEBUG){
					printf("PARSING PROC DECL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_PROC_DECL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (4)]);
				(yyval)->child[1] = (yyvsp[(3) - (4)]);
			}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 631 "syntax.y"
    {
				//NOTE: IGNORE TK_PROCEDURE  PROCEDURE_HEAD IS 'TK_PROC_HEAD'
				if(DEBUG){
					printf("PARSING PROC HEAD\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_PROC_HEAD;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(2) - (3)]);
				(yyval)->child[1] = (yyvsp[(3) - (3)]);
			}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 645 "syntax.y"
    {
			//NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
				if(DEBUG){
					printf("PARSING PARA\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_PARA;
		   		(yyval)->child_number = 1;
		   		(yyval)->child = MALLOC(1);
		   		(yyval)->child[0] = (yyvsp[(2) - (3)]);
			}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 656 "syntax.y"
    {
		   	//NOTE: PARAMETERS IS 'TK_PARA'
		   		if(DEBUG){
		   			printf("PARSING PARA NULL\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_PARA;
		   		(yyval)->child_number = 0;
		   		(yyval)->child = NULL;
		   	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 668 "syntax.y"
    {
				//NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
				if(DEBUG){
					printf("PARSING PARA DECL LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_PARA_DL;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (3)]);
				(yyval)->child[1] = (yyvsp[(3) - (3)]);
			}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 680 "syntax.y"
    {
				//NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
				if(DEBUG){
					printf("PARSING PARA DECL LIST : FIRST ONE\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_PARA_DL;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 693 "syntax.y"
    {
					//NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
					if(DEBUG){
						printf("PARSING TK_COLON\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_PARA_TL;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (3)]);
					(yyval)->child[1] = (yyvsp[(3) - (3)]);
				}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 705 "syntax.y"
    {
					//NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
					if(DEBUG){
						printf("PARSING TK_COLON\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_PARA_TL;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (3)]);
					(yyval)->child[1] = (yyvsp[(3) - (3)]);
				}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 719 "syntax.y"
    {
				//NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
				if(DEBUG){
					printf("PARSING VAR LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_VAR;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(2) - (2)]);
			}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 732 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING VAL PARA LIST\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_VAL_PARA_LIST;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 744 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ROUTINE BODY\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ROUTINE_PART;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(1) - (1)]);
			}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 756 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING STMT LIST\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_STMT_LIST;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (3)]);
			(yyval)->child[1] = (yyvsp[(2) - (3)]);
		}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 767 "syntax.y"
    {
		  	if(DEBUG){
		  		printf("PARSING STMT LIST NULL\n");
		  	}
		  	(yyval) = NEWNODE;
		  	(yyval)->type = TK_STMT_LIST;
		  	(yyval)->child_number = 0;
		  	(yyval)->child = NULL;
		}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 778 "syntax.y"
    {
		//NOTE: IGNORE TK_COLON
		if(DEBUG){
			printf("PARSING STMT\n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_STMT;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 790 "syntax.y"
    {
	 	//NOTE: IGNORE TK_COLON
	 	if(DEBUG){
	 		printf("PARSING NON LABEL STMT\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_STMT;
	 	(yyval)->child_number = 1;
	 	(yyval)->child = MALLOC(1);
	 	(yyval)->child[0] = (yyvsp[(1) - (1)]);
	 }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 803 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING ASSIGN STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 813 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING PROC STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 823 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING CP STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 833 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING IF STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 843 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING REPEAT STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 853 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING WHILE STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 863 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING FOR STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 873 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING CASE STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 883 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING GOTO STMT\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_NON_LABEL_STMT;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 895 "syntax.y"
    {
				//NOTE: IGNORE TK_ASSIGN
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ASSIGN;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(2) - (3)]);
				(yyval)->child[1] = (yyvsp[(3) - (3)]);
			}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 907 "syntax.y"
    {
				//NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ASSIGN;
				(yyval)->child_number = 3;
				(yyval)->child = MALLOC(3);
				(yyval)->child[0] = (yyvsp[(1) - (6)]);
				(yyval)->child[1] = (yyvsp[(3) - (6)]);
				(yyval)->child[2] = (yyvsp[(6) - (6)]);
			}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 920 "syntax.y"
    {
				//NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ASSIGN;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(1) - (5)]);
				(yyval)->child[1] = (yyvsp[(5) - (5)]);

				(yyvsp[(1) - (5)])->attr = (yyvsp[(3) - (5)]);
			}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 936 "syntax.y"
    {
			if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	(yyval) = NEWNODE;
          	(yyval)->type = TK_PROC;
          	(yyval)->child_number = 1;
          	(yyval)->child = MALLOC(1);
          	(yyval)->child[0] = (yyvsp[(1) - (1)]);
		}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 946 "syntax.y"
    {
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	(yyval) = NEWNODE;
          	(yyval)->type = TK_PROC;
          	(yyval)->child_number = 2;
          	(yyval)->child = MALLOC(2);
          	(yyval)->child[0] = (yyvsp[(1) - (4)]);
          	(yyval)->child[1] = (yyvsp[(3) - (4)]);
          }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 958 "syntax.y"
    {
			if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	(yyval) = NEWNODE;
          	(yyval)->type = TK_PROC;
          	(yyval)->child_number = 1;
          	(yyval)->child = MALLOC(1);
          	(yyval)->child[0] = (yyvsp[(1) - (1)]);
		}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 968 "syntax.y"
    {
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	(yyval) = NEWNODE;
          	(yyval)->type = TK_PROC;
          	(yyval)->child_number = 2;
          	(yyval)->child = MALLOC(2);
          	(yyval)->child[0] = (yyvsp[(1) - (4)]);
          	(yyval)->child[1] = (yyvsp[(3) - (4)]);
          }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 980 "syntax.y"
    {
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	(yyval) = NEWNODE;
          	(yyval)->type = TK_PROC;
          	(yyval)->child_number = 2;
          	(yyval)->child = MALLOC(2);
          	(yyval)->child[0] = (yyvsp[(1) - (4)]);
          	(yyval)->child[1] = (yyvsp[(3) - (4)]);
          }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 994 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING CP STMT\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CP_STMT;
			(yyval)->child_number = 1;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(2) - (3)]);
		}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1006 "syntax.y"
    {
			//NOTE: IGNORE TK_IF TK_THEN
			if(DEBUG){
				printf("PARSING IF STMT\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_IF;
			(yyval)->child_number = 3;
			(yyval)->child = MALLOC(3);
			(yyval)->child[0] = (yyvsp[(2) - (5)]);
			(yyval)->child[1] = (yyvsp[(4) - (5)]);
			(yyval)->child[2] = (yyvsp[(5) - (5)]);
		}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1021 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ELSE CLAUSE\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ELSE;
				(yyval)->child_number = 1;
				(yyval)->child = MALLOC(1);
				(yyval)->child[0] = (yyvsp[(2) - (2)]);
			}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1031 "syntax.y"
    {
				if(DEBUG){
					printf("PARSING ELSE CLAUSE NULL\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_ELSE;
				(yyval)->child_number = 0;
				(yyval)->child = NULL;
			}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1042 "syntax.y"
    {
				//NOTE: IGNORE TK_REPEAR TK_UNTIL
				if(DEBUG){
					printf("PARSING REPEAT STMT\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_REPEAT;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(2) - (4)]);
				(yyval)->child[1] = (yyvsp[(4) - (4)]);
			}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1056 "syntax.y"
    {
				//NOTE: IGNORE TK_WHILE TK_DO
				if(DEBUG){
					printf("PARSING WHILE STMT\n");
				}
				(yyval) = NEWNODE;
				(yyval)->type = TK_WHILE;
				(yyval)->child_number = 2;
				(yyval)->child = MALLOC(2);
				(yyval)->child[0] = (yyvsp[(2) - (4)]);
				(yyval)->child[1] = (yyvsp[(4) - (4)]);
			}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1070 "syntax.y"
    {
			//NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
			if(DEBUG){
				printf("PARSING FOR STMT\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_FOR;
			(yyval)->child_number = 5;
			(yyval)->child = MALLOC(5);
			(yyval)->child[0] = (yyvsp[(2) - (8)]);
			(yyval)->child[1] = (yyvsp[(4) - (8)]);
			(yyval)->child[2] = (yyvsp[(5) - (8)]);
			(yyval)->child[3] = (yyvsp[(6) - (8)]);
			(yyval)->child[4] = (yyvsp[(8) - (8)]);
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1087 "syntax.y"
    {
		//NOTE: THERE IS NO DIR
			if(DEBUG){
				printf("PARSING DIR TO\n");
			}
			(yyval) = NEWNODE;
			*(yyval) = *(yyvsp[(1) - (1)]);
		}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1095 "syntax.y"
    {
		//NOTE: THERE IS NO DIR
			if(DEBUG){
				printf("PARSING DIR DOWNTO\n");
			}
			(yyval) = NEWNODE;
			*(yyval) = *(yyvsp[(1) - (1)]);
		}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1105 "syntax.y"
    {
			//NOTE: IGNORE TK_CASE TK_OF TK_END
			if(DEBUG){
				printf("PARSING CASE STMT\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CASE;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(2) - (5)]);
			(yyval)->child[1] = (yyvsp[(4) - (5)]);
		}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1119 "syntax.y"
    {
			//NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
			if(DEBUG){
				printf("PARSING CASE EXPR LIST\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CASE_EL;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (2)]);
			(yyval)->child[1] = (yyvsp[(2) - (2)]);
		}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1131 "syntax.y"
    {
			//NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
			if(DEBUG){
				printf("PARSING CASE EXPR LIST : FIRST ONE\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CASE_EL;
			(yyval)->child_number = 1;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(1) - (1)]);
		}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1144 "syntax.y"
    {
			//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING CASE EXPR\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CASE_EXPR;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (4)]);
			(yyval)->child[1] = (yyvsp[(3) - (4)]);
		}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1156 "syntax.y"
    {
        	//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING CASE EXPR\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_CASE_EXPR;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (4)]);
			(yyval)->child[1] = (yyvsp[(3) - (4)]);
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1170 "syntax.y"
    {
		//NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
			if(DEBUG){
				printf("PARSING GOTO STMT\n");
			}
			(yyval) = NEWNODE;
			(yyval) = (yyvsp[(2) - (2)]);
			(yyval)->type = TK_GOTO;
		}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1181 "syntax.y"
    {
					//NOTE: IGNORE TK_COMMA
					if(DEBUG){
						printf("PARSING EXP LIST\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_EXP_LIST;
					(yyval)->child_number = 2;
					(yyval)->child = MALLOC(2);
					(yyval)->child[0] = (yyvsp[(1) - (3)]);
					(yyval)->child[1] = (yyvsp[(3) - (3)]);
				}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1193 "syntax.y"
    {
					if(DEBUG){
						printf("PARSING EXP LIST : FIRST ONE\n");
					}
					(yyval) = NEWNODE;
					(yyval)->type = TK_EXP_LIST;
					(yyval)->child_number = 1;
					(yyval)->child = MALLOC(1);
					(yyval)->child[0] = (yyvsp[(1) - (1)]);
				}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1205 "syntax.y"
    {
			//NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_GE;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1217 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_GT;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1228 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_LE;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1239 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_LT;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1250 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_EQUAL;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1261 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_UNEQUAL;
		   		(yyval)->child_number = 2;
		   		(yyval)->child = MALLOC(2);
		   		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		   		(yyval)->child[1] = (yyvsp[(3) - (3)]);
		   }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1272 "syntax.y"
    {
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION : FIRST ONE\n");
		   		}
		   		(yyval) = NEWNODE;
		   		(yyval)->type = TK_EXP;
		   		(yyval)->child_number = 1;
		   		(yyval)->child = MALLOC(1);
		   		(yyval)->child[0] = (yyvsp[(1) - (1)]);
		   }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1284 "syntax.y"
    {
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_PLUS;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1296 "syntax.y"
    {
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_MINUS;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1308 "syntax.y"
    {
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_OR;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1320 "syntax.y"
    {
	 //NOTE: expr IS EXPR, expression IS EXP
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_EXPR;
	 	(yyval)->child_number = 1;
	 	(yyval)->child = MALLOC(1);
	 	(yyval)->child[0] = (yyvsp[(1) - (1)]);
	 }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1333 "syntax.y"
    {
	 	if(DEBUG){
	 		printf("PARSING TK_MUL\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_MUL;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1344 "syntax.y"
    {
	 	if(DEBUG){
	 		printf("PARSING TK_DIV\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_DIV;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1355 "syntax.y"
    {
	 	if(DEBUG){
	 		printf("PARSING TK_MOD\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_MOD;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1366 "syntax.y"
    {
	 	if(DEBUG){
	 		printf("PARSING TK_AND\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_AND;
	 	(yyval)->child_number = 2;
	 	(yyval)->child = MALLOC(2);
	 	(yyval)->child[0] = (yyvsp[(1) - (3)]);
	 	(yyval)->child[1] = (yyvsp[(3) - (3)]);
	 }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1377 "syntax.y"
    {
	 	if(DEBUG){
	 		printf("PARSING TERM : FIRST ONE\n");
	 	}
	 	(yyval) = NEWNODE;
	 	(yyval)->type = TK_TERM;
	 	(yyval)->child_number = 1;
	 	(yyval)->child = MALLOC(1);
	 	(yyval)->child[0] = (yyvsp[(1) - (1)]);
	 }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1389 "syntax.y"
    {
	//NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
		if(DEBUG){
			printf("PARSING FACTOR\n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_ID;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(1) - (1)]);
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1400 "syntax.y"
    {
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_ID_ARGS;
		(yyval)->child_number = 2;
		(yyval)->child = MALLOC(2);
		(yyval)->child[0] = (yyvsp[(1) - (4)]);
		(yyval)->child[1] = (yyvsp[(3) - (4)]);
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1412 "syntax.y"
    {
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_SYS_FUNCT;
		(yyval)->child_number = 2;
		(yyval)->child = MALLOC(2);
		(yyval)->child[0] = (yyvsp[(1) - (4)]);
		(yyval)->child[1] = (yyvsp[(3) - (4)]);
	}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1424 "syntax.y"
    {
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_CONST;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(1) - (1)]);
	}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1434 "syntax.y"
    {
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_EXP;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(2) - (3)]);
	}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1445 "syntax.y"
    {
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_NOT;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(2) - (2)]);
	}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1455 "syntax.y"
    {
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_MINUS;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(2) - (2)]);
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1465 "syntax.y"
    {
	//NOTE: IGNORE TK_LB TK_RB
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_ID_EXP;
		(yyval)->child_number = 2;
		(yyval)->child = MALLOC(2);
		(yyval)->child[0] = (yyvsp[(1) - (4)]);
		(yyval)->child[1] = (yyvsp[(3) - (4)]);
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1477 "syntax.y"
    {
	//NOTE: ID->ID IS IN ONE NODE
		if(DEBUG){
			printf("PARSING FACTOR FOR ID->ID\n");
		}
		(yyval) = NEWNODE;
		(yyval)->type = TK_FACTOR_DD;
		(yyval)->child_number = 1;
		(yyval)->child = MALLOC(1);
		(yyval)->child[0] = (yyvsp[(1) - (3)]);
		(yyvsp[(1) - (3)])->attr = (yyvsp[(2) - (3)]);
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1491 "syntax.y"
    {
			//NOTE: IGNORE TK_COMMA
			if(DEBUG){
				printf("PARSING ARGS LIST\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_ARGS_LIST;
			(yyval)->child_number = 2;
			(yyval)->child = MALLOC(2);
			(yyval)->child[0] = (yyvsp[(1) - (3)]);
			(yyval)->child[1] = (yyvsp[(2) - (3)]);
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1503 "syntax.y"
    {
			if(DEBUG){
				printf("PARSING ARGS LIST : FIRST ONE\n");
			}
			(yyval) = NEWNODE;
			(yyval)->type = TK_ARGS_LIST;
			(yyval)->child_number = 1;
			(yyval)->child = MALLOC(1);
			(yyval)->child[0] = (yyvsp[(1) - (1)]);
		}
    break;



/* Line 1455 of yacc.c  */
#line 3956 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 1515 "syntax.y"


int yyerror(char* s){
            printf("\n");
            printf( "%s\n", s);
            fprintf(stderr, "line %d: ", yylineno);
            fprintf(stderr, "\"%s\"\n", yytext);
            return 1;
}

void preorder(NODE* root){
	int i;
	printf("TYPE:%d; CHILDREN:%d\n", root->type, root->child_number);
	for(i=0;i<root->child_number;i++){
		preorder(root->child[i]);
	}
}

void cpString(char** str1, char** str2){
	*str1 = (char*)malloc(sizeof(char) * (strlen(*str2) + 1));
	strcpy(*str1, *str2);
}

int main(){
    char FILENAME[100];
    printf("Please input the test file: ");
    scanf("%s", FILENAME);
    FILE* file = fopen(FILENAME, "r");
    yyin = file;

    yyparse();

    if(DEBUG){
    	preorder(ROOT);
    }

    return 0;
}


