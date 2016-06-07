/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
extern int yylineno;


#line 76 "yy.tab.cpp" /* yacc.c:339  */

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
    TK_ELSE_NULL = 274,
    TK_END = 275,
    TK_EQUAL = 276,
    TK_FOR = 277,
    TK_FUNCTION = 278,
    TK_GE = 279,
    TK_GOTO = 280,
    TK_GT = 281,
    TK_ID = 282,
    TK_REF = 283,
    TK_IF = 284,
    TK_IN = 285,
    TK_LB = 286,
    TK_LE = 287,
    TK_LP = 288,
    TK_LT = 289,
    TK_MINUS = 290,
    TK_MOD = 291,
    TK_UNEQUAL = 292,
    TK_OF = 293,
    TK_OR = 294,
    TK_OTHERWISE = 295,
    TK_BEGIN = 296,
    TK_PLUS = 297,
    TK_PROCEDURE = 298,
    TK_PROGRAM = 299,
    TK_RB = 300,
    TK_REAL = 301,
    TK_RECORD = 302,
    TK_REPEAT = 303,
    TK_RP = 304,
    TK_SYS_PROC = 305,
    TK_READ = 306,
    TK_SEMI = 307,
    TK_MUL = 308,
    TK_THEN = 309,
    TK_NOT = 310,
    TK_TO = 311,
    TK_UNTIL = 312,
    TK_UPARROW = 313,
    TK_VAR = 314,
    TK_WHILE = 315,
    TK_SET = 316,
    TK_STARSTAR = 317,
    TK_CHAR = 318,
    TK_STRING = 319,
    TK_INTEGER = 320,
    TK_SYS_CON = 321,
    TK_SYS_FUNCT = 322,
    TK_WITH = 323,
    TK_NIL = 324,
    ERROR = 325,
    TK_PROGRAM_HEAD = 326,
    TK_ROUTINE = 327,
    TK_ROUTINE_PART = 328,
    TK_ROUTINE_HEAD = 329,
    TK_ROUTINE_BODY = 330,
    TK_CONST_PART = 331,
    TK_CONST_PART_END = 332,
    TK_TYPE_PART = 333,
    TK_TYPE_PART_END = 334,
    TK_VAR_PART = 335,
    TK_VAR_PART_END = 336,
    TK_ROUTINE_PART_RF = 337,
    TK_ROUTINE_PART_RP = 338,
    TK_ROUTINE_PART_FUNC = 339,
    TK_ROUTINE_PART_PROC = 340,
    TK_ROUTINE_PART_NULL = 341,
    TK_STMT_LIST = 342,
    TK_STMT_LIST_NULL = 343,
    TK_STMT_LABEL = 344,
    TK_STMT = 345,
    TK_CP_STMT = 346,
    TK_VAL_PARA_LIST = 347,
    TK_NON_LABEL_STMT_ASSIGN = 348,
    TK_NON_LABEL_STMT_PROC = 349,
    TK_NON_LABEL_STMT_CP = 350,
    TK_NON_LABEL_STMT_IF = 351,
    TK_NON_LABEL_STMT_REP = 352,
    TK_NON_LABEL_STMT_WHILE = 353,
    TK_NON_LABEL_STMT_FOR = 354,
    TK_NON_LABEL_STMT_CASE = 355,
    TK_NON_LABEL_STMT_GOTO = 356,
    TK_EXP_LIST = 357,
    TK_EXP_LIST_END = 358,
    TK_EXP = 359,
    TK_TERM = 360,
    TK_FACTOR_ID = 361,
    TK_FACTOR_ID_ARGS = 362,
    TK_FACTOR_SYS_FUNCT = 363,
    TK_FACTOR_CONST = 364,
    TK_FACTOR_EXP = 365,
    TK_FACTOR_NOT = 366,
    TK_FACTOR_MINUS = 367,
    TK_FACTOR_ID_EXP = 368,
    TK_FACTOR_DD = 369,
    TK_ARGS_LIST = 370,
    TK_ARGS_LIST_END = 371,
    TK_CONST_DL = 372,
    TK_CONST_DL_END = 373,
    TK_TYPE_DL = 374,
    TK_TYPE_DL_END = 375,
    TK_TYPE_DEF = 376,
    TK_TYPE_DECL = 377,
    TK_TYPE_DECL_SIM = 378,
    TK_TYPE_DECL_ARR = 379,
    TK_TYPE_DECL_REC = 380,
    TK_FIELD_DL = 381,
    TK_FIELD_DL_END = 382,
    TK_FIELD_DECL = 383,
    TK_NL = 384,
    TK_NL_END = 385,
    TK_STD_SYS_TYPE = 386,
    TK_STD_ID = 387,
    TK_STD_NL = 388,
    TK_STD_DD = 389,
    TK_STD_DD_M = 390,
    TK_STD_DD_MM = 391,
    TK_STD_DD_ID = 392,
    TK_DL = 393,
    TK_DL_END = 394,
    TK_VAR_DECL = 395,
    TK_FUNC_DECL = 396,
    TK_FUNC_HEAD = 397,
    TK_PROC_DECL = 398,
    TK_PROC_HEAD = 399,
    TK_PARA = 400,
    TK_PARA_TL = 401,
    TK_PARA_NULL = 402,
    TK_PARA_DL = 403,
    TK_PARA_DL_END = 404,
    TK_PARA_TL_VAR = 405,
    TK_PARA_TL_VAL = 406,
    TK_PARA_TL_END = 407,
    TK_PROC = 408,
    TK_CASE_EL = 409,
    TK_CASE_EL_END = 410,
    TK_CASE_EXPR = 411,
    TK_CASE_EXPR_END = 412,
    TK_EXPR = 413,
    TK_ASSIGN_ID = 414,
    TK_ASSIGN_ID_EXPR = 415,
    TK_ASSIGN_DD = 416,
    TK_PROC_ID = 417,
    TK_PROC_ID_ARGS = 418,
    TK_PROC_SYS = 419,
    TK_PROC_SYS_ARGS = 420,
    TK_PROC_READ = 421,
    TK_STMT_ASSIGN = 422,
    TK_STMT_PROC = 423,
    TK_STMT_CP = 424
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
#define TK_ELSE_NULL 274
#define TK_END 275
#define TK_EQUAL 276
#define TK_FOR 277
#define TK_FUNCTION 278
#define TK_GE 279
#define TK_GOTO 280
#define TK_GT 281
#define TK_ID 282
#define TK_REF 283
#define TK_IF 284
#define TK_IN 285
#define TK_LB 286
#define TK_LE 287
#define TK_LP 288
#define TK_LT 289
#define TK_MINUS 290
#define TK_MOD 291
#define TK_UNEQUAL 292
#define TK_OF 293
#define TK_OR 294
#define TK_OTHERWISE 295
#define TK_BEGIN 296
#define TK_PLUS 297
#define TK_PROCEDURE 298
#define TK_PROGRAM 299
#define TK_RB 300
#define TK_REAL 301
#define TK_RECORD 302
#define TK_REPEAT 303
#define TK_RP 304
#define TK_SYS_PROC 305
#define TK_READ 306
#define TK_SEMI 307
#define TK_MUL 308
#define TK_THEN 309
#define TK_NOT 310
#define TK_TO 311
#define TK_UNTIL 312
#define TK_UPARROW 313
#define TK_VAR 314
#define TK_WHILE 315
#define TK_SET 316
#define TK_STARSTAR 317
#define TK_CHAR 318
#define TK_STRING 319
#define TK_INTEGER 320
#define TK_SYS_CON 321
#define TK_SYS_FUNCT 322
#define TK_WITH 323
#define TK_NIL 324
#define ERROR 325
#define TK_PROGRAM_HEAD 326
#define TK_ROUTINE 327
#define TK_ROUTINE_PART 328
#define TK_ROUTINE_HEAD 329
#define TK_ROUTINE_BODY 330
#define TK_CONST_PART 331
#define TK_CONST_PART_END 332
#define TK_TYPE_PART 333
#define TK_TYPE_PART_END 334
#define TK_VAR_PART 335
#define TK_VAR_PART_END 336
#define TK_ROUTINE_PART_RF 337
#define TK_ROUTINE_PART_RP 338
#define TK_ROUTINE_PART_FUNC 339
#define TK_ROUTINE_PART_PROC 340
#define TK_ROUTINE_PART_NULL 341
#define TK_STMT_LIST 342
#define TK_STMT_LIST_NULL 343
#define TK_STMT_LABEL 344
#define TK_STMT 345
#define TK_CP_STMT 346
#define TK_VAL_PARA_LIST 347
#define TK_NON_LABEL_STMT_ASSIGN 348
#define TK_NON_LABEL_STMT_PROC 349
#define TK_NON_LABEL_STMT_CP 350
#define TK_NON_LABEL_STMT_IF 351
#define TK_NON_LABEL_STMT_REP 352
#define TK_NON_LABEL_STMT_WHILE 353
#define TK_NON_LABEL_STMT_FOR 354
#define TK_NON_LABEL_STMT_CASE 355
#define TK_NON_LABEL_STMT_GOTO 356
#define TK_EXP_LIST 357
#define TK_EXP_LIST_END 358
#define TK_EXP 359
#define TK_TERM 360
#define TK_FACTOR_ID 361
#define TK_FACTOR_ID_ARGS 362
#define TK_FACTOR_SYS_FUNCT 363
#define TK_FACTOR_CONST 364
#define TK_FACTOR_EXP 365
#define TK_FACTOR_NOT 366
#define TK_FACTOR_MINUS 367
#define TK_FACTOR_ID_EXP 368
#define TK_FACTOR_DD 369
#define TK_ARGS_LIST 370
#define TK_ARGS_LIST_END 371
#define TK_CONST_DL 372
#define TK_CONST_DL_END 373
#define TK_TYPE_DL 374
#define TK_TYPE_DL_END 375
#define TK_TYPE_DEF 376
#define TK_TYPE_DECL 377
#define TK_TYPE_DECL_SIM 378
#define TK_TYPE_DECL_ARR 379
#define TK_TYPE_DECL_REC 380
#define TK_FIELD_DL 381
#define TK_FIELD_DL_END 382
#define TK_FIELD_DECL 383
#define TK_NL 384
#define TK_NL_END 385
#define TK_STD_SYS_TYPE 386
#define TK_STD_ID 387
#define TK_STD_NL 388
#define TK_STD_DD 389
#define TK_STD_DD_M 390
#define TK_STD_DD_MM 391
#define TK_STD_DD_ID 392
#define TK_DL 393
#define TK_DL_END 394
#define TK_VAR_DECL 395
#define TK_FUNC_DECL 396
#define TK_FUNC_HEAD 397
#define TK_PROC_DECL 398
#define TK_PROC_HEAD 399
#define TK_PARA 400
#define TK_PARA_TL 401
#define TK_PARA_NULL 402
#define TK_PARA_DL 403
#define TK_PARA_DL_END 404
#define TK_PARA_TL_VAR 405
#define TK_PARA_TL_VAL 406
#define TK_PARA_TL_END 407
#define TK_PROC 408
#define TK_CASE_EL 409
#define TK_CASE_EL_END 410
#define TK_CASE_EXPR 411
#define TK_CASE_EXPR_END 412
#define TK_EXPR 413
#define TK_ASSIGN_ID 414
#define TK_ASSIGN_ID_EXPR 415
#define TK_ASSIGN_DD 416
#define TK_PROC_ID 417
#define TK_PROC_ID_ARGS 418
#define TK_PROC_SYS 419
#define TK_PROC_SYS_ARGS 420
#define TK_PROC_READ 421
#define TK_STMT_ASSIGN 422
#define TK_STMT_PROC 423
#define TK_STMT_CP 424

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

#line 465 "yy.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   424

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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    56,    68,    81,    98,   105,   113,   135,
     155,   161,   167,   173,   179,   187,   194,   203,   218,   229,
     242,   251,   260,   271,   288,   297,   313,   325,   339,   356,
     368,   379,   389,   399,   410,   423,   430,   438,   454,   466,
     480,   496,   512,   522,   532,   540,   554,   574,   588,   602,
     609,   618,   635,   648,   663,   680,   689,   697,   705,   730,
     738,   750,   763,   773,   783,   793,   799,   805,   811,   817,
     823,   831,   843,   857,   873,   883,   895,   905,   917,   931,
     939,   955,   961,   969,   983,   997,  1017,  1024,  1033,  1048,
    1065,  1078,  1091,  1105,  1116,  1133,  1145,  1157,  1168,  1179,
    1190,  1200,  1210,  1221,  1232,  1243,  1254,  1267,  1277,  1287,
    1297,  1307,  1319,  1330,  1341,  1352,  1361,  1371,  1380,  1389,
    1400,  1413,  1430
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
  "TK_ELSE", "TK_ELSE_NULL", "TK_END", "TK_EQUAL", "TK_FOR", "TK_FUNCTION",
  "TK_GE", "TK_GOTO", "TK_GT", "TK_ID", "TK_REF", "TK_IF", "TK_IN",
  "TK_LB", "TK_LE", "TK_LP", "TK_LT", "TK_MINUS", "TK_MOD", "TK_UNEQUAL",
  "TK_OF", "TK_OR", "TK_OTHERWISE", "TK_BEGIN", "TK_PLUS", "TK_PROCEDURE",
  "TK_PROGRAM", "TK_RB", "TK_REAL", "TK_RECORD", "TK_REPEAT", "TK_RP",
  "TK_SYS_PROC", "TK_READ", "TK_SEMI", "TK_MUL", "TK_THEN", "TK_NOT",
  "TK_TO", "TK_UNTIL", "TK_UPARROW", "TK_VAR", "TK_WHILE", "TK_SET",
  "TK_STARSTAR", "TK_CHAR", "TK_STRING", "TK_INTEGER", "TK_SYS_CON",
  "TK_SYS_FUNCT", "TK_WITH", "TK_NIL", "ERROR", "TK_PROGRAM_HEAD",
  "TK_ROUTINE", "TK_ROUTINE_PART", "TK_ROUTINE_HEAD", "TK_ROUTINE_BODY",
  "TK_CONST_PART", "TK_CONST_PART_END", "TK_TYPE_PART", "TK_TYPE_PART_END",
  "TK_VAR_PART", "TK_VAR_PART_END", "TK_ROUTINE_PART_RF",
  "TK_ROUTINE_PART_RP", "TK_ROUTINE_PART_FUNC", "TK_ROUTINE_PART_PROC",
  "TK_ROUTINE_PART_NULL", "TK_STMT_LIST", "TK_STMT_LIST_NULL",
  "TK_STMT_LABEL", "TK_STMT", "TK_CP_STMT", "TK_VAL_PARA_LIST",
  "TK_NON_LABEL_STMT_ASSIGN", "TK_NON_LABEL_STMT_PROC",
  "TK_NON_LABEL_STMT_CP", "TK_NON_LABEL_STMT_IF", "TK_NON_LABEL_STMT_REP",
  "TK_NON_LABEL_STMT_WHILE", "TK_NON_LABEL_STMT_FOR",
  "TK_NON_LABEL_STMT_CASE", "TK_NON_LABEL_STMT_GOTO", "TK_EXP_LIST",
  "TK_EXP_LIST_END", "TK_EXP", "TK_TERM", "TK_FACTOR_ID",
  "TK_FACTOR_ID_ARGS", "TK_FACTOR_SYS_FUNCT", "TK_FACTOR_CONST",
  "TK_FACTOR_EXP", "TK_FACTOR_NOT", "TK_FACTOR_MINUS", "TK_FACTOR_ID_EXP",
  "TK_FACTOR_DD", "TK_ARGS_LIST", "TK_ARGS_LIST_END", "TK_CONST_DL",
  "TK_CONST_DL_END", "TK_TYPE_DL", "TK_TYPE_DL_END", "TK_TYPE_DEF",
  "TK_TYPE_DECL", "TK_TYPE_DECL_SIM", "TK_TYPE_DECL_ARR",
  "TK_TYPE_DECL_REC", "TK_FIELD_DL", "TK_FIELD_DL_END", "TK_FIELD_DECL",
  "TK_NL", "TK_NL_END", "TK_STD_SYS_TYPE", "TK_STD_ID", "TK_STD_NL",
  "TK_STD_DD", "TK_STD_DD_M", "TK_STD_DD_MM", "TK_STD_DD_ID", "TK_DL",
  "TK_DL_END", "TK_VAR_DECL", "TK_FUNC_DECL", "TK_FUNC_HEAD",
  "TK_PROC_DECL", "TK_PROC_HEAD", "TK_PARA", "TK_PARA_TL", "TK_PARA_NULL",
  "TK_PARA_DL", "TK_PARA_DL_END", "TK_PARA_TL_VAR", "TK_PARA_TL_VAL",
  "TK_PARA_TL_END", "TK_PROC", "TK_CASE_EL", "TK_CASE_EL_END",
  "TK_CASE_EXPR", "TK_CASE_EXPR_END", "TK_EXPR", "TK_ASSIGN_ID",
  "TK_ASSIGN_ID_EXPR", "TK_ASSIGN_DD", "TK_PROC_ID", "TK_PROC_ID_ARGS",
  "TK_PROC_SYS", "TK_PROC_SYS_ARGS", "TK_PROC_READ", "TK_STMT_ASSIGN",
  "TK_STMT_PROC", "TK_STMT_CP", "$accept", "program", "program_head",
  "routine", "routine_head", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "array_type_decl", "record_type_decl", "field_decl_list",
  "field_decl", "name_list", "simple_type_decl", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,   -14,    34,    33,    -3,  -143,    45,    71,    49,    87,
    -143,    75,    86,  -143,  -143,  -143,  -143,    88,    58,   231,
      97,     4,   100,    88,  -143,    98,    48,  -143,  -143,  -143,
    -143,  -143,    89,   231,   132,  -143,   117,    82,    15,   132,
    -143,   120,   122,   132,   154,   116,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,    14,  -143,  -143,    29,
      98,  -143,   148,   149,    48,  -143,   125,  -143,   127,  -143,
     128,    91,   132,   132,   132,   151,  -143,   267,    77,     6,
    -143,   180,  -143,   132,   161,   132,   132,   185,   101,   132,
     132,   252,   183,  -143,   162,  -143,   178,    98,    98,   188,
     155,  -143,  -143,  -143,    14,   186,  -143,   181,   181,  -143,
    -143,    33,    33,  -143,   191,   132,   132,   216,  -143,  -143,
     132,   132,   132,   132,   132,   132,   132,    68,   132,   132,
     132,   132,   132,   132,   132,   132,   285,   215,   225,   285,
      13,   121,   132,    17,   285,   177,   121,  -143,   137,   200,
      18,    16,  -143,    95,   231,  -143,   192,  -143,   -24,   220,
    -143,   193,   195,  -143,   237,    40,  -143,    60,    77,    77,
      77,    77,    77,    77,   223,   226,    36,  -143,     6,     6,
       6,  -143,  -143,  -143,  -143,   204,   132,   247,   132,  -143,
     236,   285,   132,  -143,  -143,  -143,   210,  -143,  -143,  -143,
    -143,    14,  -143,  -143,    98,   246,    32,  -143,   255,   258,
     137,  -143,  -143,  -143,  -143,  -143,   121,   121,  -143,  -143,
    -143,  -143,   132,   285,   132,   285,   121,  -143,   285,   230,
     227,   246,  -143,   -24,   137,   137,  -143,   229,   233,   266,
     285,  -143,    14,  -143,  -143,  -143,  -143,  -143,  -143,   121,
    -143,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    16,
       3,     0,     6,     2,    59,     4,    57,     0,    36,     0,
       0,     0,     0,    15,    18,     0,    44,    11,    12,    13,
      10,    14,     0,     0,     0,    79,     0,     0,    74,     0,
      59,    76,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    17,    29,     0,
      35,    38,     0,     0,     5,    42,     0,    43,     0,     9,
       0,   112,     0,     0,     0,     0,   115,     0,   102,   106,
     111,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    30,    31,     0,     0,     0,
       0,    21,    22,    20,     0,     0,    37,    50,    50,    40,
      41,     7,     7,     8,     0,     0,     0,     0,   118,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     0,     0,   122,
       0,     0,     0,     0,    95,     0,     0,    60,     0,     0,
       0,     0,    26,     0,     0,    19,     0,    28,     0,     0,
      48,     0,     0,   120,     0,     0,   116,     0,   100,    96,
      97,    98,    99,   101,     0,     0,     0,    90,   104,   105,
     103,   110,   108,   109,   107,     0,     0,     0,     0,    75,
      82,    83,     0,    77,    78,    84,     0,    34,    32,    24,
      25,     0,    33,    39,     0,    56,     0,    52,     0,     0,
       0,    45,    47,   119,   113,   114,     0,     0,    88,    89,
      87,    86,     0,    73,     0,   121,     0,    80,    94,     0,
       0,    55,    49,     0,     0,     0,    46,     0,     0,     0,
      72,    81,     0,    27,    51,    53,    54,    92,    91,     0,
      23,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,    62,  -143,  -143,  -143,   -19,  -143,  -143,
     249,  -103,  -143,  -143,  -143,   124,   -93,  -142,  -143,  -143,
     242,  -143,   219,  -143,   243,  -143,   205,  -143,    79,  -143,
    -143,  -143,   268,  -129,   218,  -143,  -143,   306,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   139,  -143,  -143,   -32,
     202,     8,   -58,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    12,    76,    18,    23,
      24,   100,   101,   102,   151,   152,    59,   103,    26,    60,
      61,    64,    65,    66,    67,    68,   159,   206,   207,   208,
     209,    15,    21,    45,    46,    47,    48,    49,    50,   227,
      51,    52,    53,   222,    54,   176,   177,    55,   143,   139,
      78,    79,    80,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,   156,    77,    58,   150,   153,   196,    87,     1,   131,
      34,    91,   190,     4,    70,   118,   119,   195,    94,   132,
      83,   165,    95,   188,    35,   167,    36,   192,   105,    37,
      84,    38,   145,    39,     5,   204,   199,    99,   104,   105,
     117,    96,   133,    58,     6,    14,    85,    97,    86,    10,
     188,   136,    40,   138,    41,    42,   218,   144,   153,   134,
      27,    98,   189,   174,    43,   205,   193,   198,   236,    44,
     188,    62,    11,   181,   182,   183,   184,    28,    29,    30,
      31,   232,    27,   164,   233,    99,    13,   237,   238,   214,
      14,    63,   245,   246,    17,   174,    19,   241,   230,    28,
      29,    30,    31,   185,   201,   105,   114,    34,   175,   215,
     191,   231,   128,    20,    27,    22,   129,    25,    33,   130,
     251,    56,   115,    36,   116,    58,    37,    34,    38,    99,
      39,    28,    29,    30,    31,   202,   178,   179,   180,   250,
     205,    69,    14,    36,    81,    95,    37,    82,    38,    40,
      39,    41,    42,    89,   223,    90,   225,   175,   142,    71,
     228,    43,    14,    92,    96,    72,    44,    73,    93,    40,
      97,    41,    42,   161,   162,   107,   108,   111,    27,   112,
     113,    43,    99,    27,   120,   135,    44,    74,   137,    34,
     239,    99,   240,   148,   149,    28,    29,    30,    31,    75,
      28,    29,    30,    31,   154,    36,   121,   155,    37,   122,
      38,   123,    39,   157,   158,    99,    99,   124,   163,   125,
     186,   220,   126,    99,    14,   121,   194,   197,   122,   210,
     123,    40,   216,    41,    42,   217,   124,   121,   125,   141,
     122,   126,   123,    43,   203,   211,   121,   212,   124,   122,
     125,   123,   224,   126,   226,   229,   105,   124,   121,   125,
     221,   122,   126,   123,   234,   166,   146,   235,   242,   124,
     187,   125,    57,   121,   126,   200,   122,    27,   123,   243,
     249,   247,   213,   109,   124,   248,   125,   121,   121,   126,
     122,   122,   123,   123,    28,    29,    30,    31,   124,   124,
     125,   125,   106,   126,   126,   127,   121,   110,    88,   122,
     147,   123,   244,   160,    16,   219,     0,   124,     0,   125,
       0,     0,   126,   168,   169,   170,   171,   172,   173
};

static const yytype_int16 yycheck[] =
{
      19,   104,    34,    27,    97,    98,   148,    39,    44,     3,
       6,    43,   141,    27,    33,    73,    74,   146,     4,    13,
       5,   116,     8,    10,    20,   120,    22,    10,    10,    25,
      15,    27,    90,    29,     0,    59,    20,    56,     9,    10,
      72,    27,    36,    27,    11,    41,    31,    33,    33,    52,
      10,    83,    48,    85,    50,    51,    20,    89,   151,    53,
      46,    47,    49,    27,    60,   158,    49,    49,   210,    65,
      10,    23,    27,   131,   132,   133,   134,    63,    64,    65,
      66,    49,    46,   115,    52,   104,    15,   216,   217,    49,
      41,    43,   234,   235,     7,    27,    21,   226,   201,    63,
      64,    65,    66,   135,     9,    10,    15,     6,   127,    49,
     142,   204,    35,    27,    46,    27,    39,    59,    21,    42,
     249,    21,    31,    22,    33,    27,    25,     6,    27,   148,
      29,    63,    64,    65,    66,   154,   128,   129,   130,   242,
     233,    52,    41,    22,    27,     8,    25,    65,    27,    48,
      29,    50,    51,    33,   186,    33,   188,   176,    57,    27,
     192,    60,    41,     9,    27,    33,    65,    35,    52,    48,
      33,    50,    51,   111,   112,    27,    27,    52,    46,    52,
      52,    60,   201,    46,    33,     5,    65,    55,    27,     6,
     222,   210,   224,    31,    16,    63,    64,    65,    66,    67,
      63,    64,    65,    66,    16,    22,    21,    52,    25,    24,
      27,    26,    29,    27,    33,   234,   235,    32,    27,    34,
       5,    17,    37,   242,    41,    21,    49,    27,    24,     9,
      26,    48,     9,    50,    51,     9,    32,    21,    34,    54,
      24,    37,    26,    60,    52,    52,    21,    52,    32,    24,
      34,    26,     5,    37,    18,    45,    10,    32,    21,    34,
      56,    24,    37,    26,     9,    49,    14,     9,    38,    32,
      45,    34,    23,    21,    37,   151,    24,    46,    26,    52,
      14,    52,    45,    64,    32,    52,    34,    21,    21,    37,
      24,    24,    26,    26,    63,    64,    65,    66,    32,    32,
      34,    34,    60,    37,    37,    38,    21,    64,    40,    24,
      92,    26,   233,   108,     8,   176,    -1,    32,    -1,    34,
      -1,    -1,    37,   121,   122,   123,   124,   125,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,   171,   172,    27,     0,    11,   173,   174,   175,
      52,    27,   176,    15,    41,   201,   207,     7,   178,    21,
      27,   202,    27,   179,   180,    59,   188,    46,    63,    64,
      65,    66,   177,    21,     6,    20,    22,    25,    27,    29,
      48,    50,    51,    60,    65,   203,   204,   205,   206,   207,
     208,   210,   211,   212,   214,   217,    21,   180,    27,   186,
     189,   190,    23,    43,   191,   192,   193,   194,   195,    52,
     177,    27,    33,    35,    55,    67,   177,   219,   220,   221,
     222,    27,    65,     5,    15,    31,    33,   219,   202,    33,
      33,   219,     9,    52,     4,     8,    27,    33,    47,   177,
     181,   182,   183,   187,     9,    10,   190,    27,    27,   192,
     194,    52,    52,    52,    15,    31,    33,   219,   222,   222,
      33,    21,    24,    26,    32,    34,    37,    38,    35,    39,
      42,     3,    13,    36,    53,     5,   219,    27,   219,   219,
     223,    54,    57,   218,   219,   222,    14,   204,    31,    16,
     186,   184,   185,   186,    16,    52,   181,    27,    33,   196,
     196,   173,   173,    27,   219,   223,    49,   223,   220,   220,
     220,   220,   220,   220,    27,   177,   215,   216,   221,   221,
     221,   222,   222,   222,   222,   219,     5,    45,    10,    49,
     203,   219,    10,    49,    49,   203,   187,    27,    49,    20,
     185,     9,   177,    52,    59,   186,   197,   198,   199,   200,
       9,    52,    52,    45,    49,    49,     9,     9,    20,   216,
      17,    56,   213,   219,     5,   219,    18,   209,   219,    45,
     181,   186,    49,    52,     9,     9,   187,   203,   203,   219,
     219,   203,    38,    52,   198,   187,   187,    52,    52,    14,
     181,   203
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   170,   171,   172,   173,   174,   175,   175,   176,   176,
     177,   177,   177,   177,   177,   178,   178,   179,   179,   180,
     181,   181,   181,   182,   183,   184,   184,   185,   186,   186,
     187,   187,   187,   187,   187,   188,   188,   189,   189,   190,
     191,   191,   191,   191,   191,   192,   193,   194,   195,   196,
     196,   197,   197,   198,   198,   199,   200,   201,   202,   202,
     203,   203,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   206,   206,   206,   206,   206,   207,
     208,   209,   209,   210,   211,   212,   213,   213,   214,   215,
     215,   216,   216,   217,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   220,   220,   220,   220,   221,   221,   221,
     221,   221,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   223,   223
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     4,     2,     0,     5,     4,
       1,     1,     1,     1,     1,     2,     0,     2,     1,     4,
       1,     1,     1,     6,     3,     2,     1,     4,     3,     1,
       1,     1,     3,     3,     3,     2,     0,     2,     1,     4,
       2,     2,     1,     1,     0,     4,     5,     4,     3,     3,
       0,     3,     1,     3,     3,     2,     1,     1,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     6,     5,     1,     4,     1,     4,     4,     3,
       5,     2,     0,     4,     4,     8,     1,     1,     5,     2,
       1,     4,     4,     2,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     4,     4,     1,     3,     2,     2,     4,
       3,     3,     1
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
#line 41 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING PROGRAM\n");
            }
            (yyval) = NEWNODE(TK_PROGRAM);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-2]);
            (yyval)->child[1] = (yyvsp[-1]);

            (yyval)->lineno = MIN((yyvsp[-2]),(yyvsp[-1]));

            ROOT = (yyval);
        }
#line 1809 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: PROGRAM HEAD ACTUALLY IS TK_ID
            if(DEBUG){
                printf("PROGRAM HEAD:%s\n", (yyvsp[-1])->name.c_str());
            }
            (yyval) = (yyvsp[-1]);
            (yyval)->type = TK_PROGRAM_HEAD;
            (yyval)->child_number = 0;
            (yyval)->child = NULL;
        }
#line 1824 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING ROUTINE\n");
            }
            (yyval) = NEWNODE(TK_ROUTINE);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-1]);
            (yyval)->child[1] = (yyvsp[0]);

            (yyval)->lineno = MIN((yyvsp[-1]),(yyvsp[0]));
        }
#line 1840 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "syntax.y" /* yacc.c:1646  */
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

            (yyval)->lineno = MIN((yyvsp[-3]),(yyvsp[-2]));
            (yyval)->lineno = MIN((yyval),(yyvsp[-1]));
            (yyval)->lineno = MIN((yyval),(yyvsp[0]));
        }
#line 1860 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: IGNORE TK_CONST
            if(DEBUG){
                printf("PARSING CONST PART\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 1872 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING CONST PART NULL\n");
            }
            (yyval) = NULL;
        }
#line 1883 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST\n");
                    }
                    (yyval) = (yyvsp[-4]);
                    NODE* node = NEWNODE(TK_CONST_DL_END);
                    node->child = MALLOC(node,2);
                    node->child[0] = (yyvsp[-3]);
                    node->child[1] = (yyvsp[-1]);

                    NODE** tmp = (yyval)->child;
                    int old_child_number = (yyval)->child_number;
                    (yyval)->child = MALLOC((yyval), (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                    	(yyval)->child[i] = tmp[i];
                    }
                    (yyval)->child[i] = node;

                    free(tmp);
                }
#line 1910 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST : FIRST ONE\n");
                    }
                    (yyval) = NEWNODE(TK_CONST_DL);
                    NODE* node = NEWNODE(TK_CONST_DL_END);

                    node->child = MALLOC(node,2);
                    node->child[0] = (yyvsp[-3]);
                    node->child[1] = (yyvsp[-1]);
                    (yyval)->lineno = node->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));

                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = node;


                }
#line 1933 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE INTEGER\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1944 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE REAL\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1955 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE CHAR\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1966 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 173 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE STRING\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1977 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING COSNT VALUE SYS CON\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 1988 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 187 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TYPE
            if(DEBUG){
                printf("PARSING TYPE PART NULL\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 2000 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 194 "syntax.y" /* yacc.c:1646  */
    {
              //NOTE: IGNORE TYPE
                  if(DEBUG){
                      printf("PARSING TYPE PART NULL\n");
                  }
                (yyval)=NULL;
                }
#line 2012 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 203 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST DEF\n");
                    }
                    (yyval) = (yyvsp[-1]);

                    int old_child_number = (yyval)->child_number;
                    NODE** tmp = (yyval)->child;
                    (yyval)->child = MALLOC((yyval), (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                    	(yyval)->child[i] = tmp[i];
                    }
                    (yyval)->child[i] = (yyvsp[0]);
                }
#line 2032 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 218 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST\n");
                    }
                    (yyval) = NEWNODE(TK_TYPE_DL);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);
                    (yyval)->lineno = (yyvsp[0])->lineno;
               }
#line 2046 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 229 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING TYPE DEF\n");
                    }
                    (yyval) = NEWNODE(TK_TYPE_DEF);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-3]);
                    (yyval)->child[1] = (yyvsp[-1]);

                    (yyval)->lineno = MIN((yyvsp[-3]),(yyvsp[-1]));
                }
#line 2062 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
                (yyval)->lineno = (yyvsp[0])->lineno;
          }
#line 2076 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
                (yyval)->lineno = (yyvsp[0])->lineno;
          }
#line 2090 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                (yyval) = NEWNODE(TK_TYPE_DECL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
                (yyval)->lineno = (yyvsp[0])->lineno;
          }
#line 2104 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 271 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_LB TK_RB TK_OF
                if(DEBUG){
                    printf("PARSING ARRAY\n");
                }
                (yyval) = NEWNODE(TK_ARRAY);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = NEWNODE(TK_TYPE_DECL);
                (yyval)->child[0]->lineno = (yyvsp[-3])->lineno;
                (yyval)->child[0]->child = MALLOC((yyval), 1);
                (yyval)->child[0]->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[0]));
            }
#line 2124 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 288 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_END
                if(DEBUG){
                    printf("PARSING RECORD TYPE DECL\n");
                }
                (yyval) = (yyvsp[-1]);
            }
#line 2136 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST\n");
                }
                (yyval) = (yyvsp[-1]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2157 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 313 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_FIELD_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);

                (yyval)->lineno = (yyvsp[0])->lineno;
            }
#line 2172 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 325 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
                if(DEBUG){
                    printf("PARSING FIELD DECL\n");
                }
                (yyval) = NEWNODE(TK_FIELD_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);

                (yyval)->lineno = MIN((yyvsp[-3]),(yyvsp[-1]));
            }
#line 2189 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 339 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
                if(DEBUG){
                    printf("PARSING NAME LIST\n");
                }
              	(yyval) = (yyvsp[-2]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2211 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 356 "syntax.y" /* yacc.c:1646  */
    {
                  if(DEBUG){
                      printf("PARSING NAME LIST : FIRST ONE\n");
                  }
                  (yyval) = NEWNODE(TK_NL);
                  (yyval)->child = MALLOC((yyval),1);
                  (yyval)->child[0] = (yyvsp[0]);

                  (yyval)->lineno = (yyvsp[0])->lineno;
              }
#line 2226 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 368 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
                    }
                    (yyval) = NEWNODE(TK_STD_SYS_TYPE);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 2242 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 379 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_ID);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 2257 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 389 "syntax.y" /* yacc.c:1646  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_NL);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[-1]);

                    (yyval)->lineno = (yyvsp[-2])->lineno;
                }
#line 2272 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 399 "syntax.y" /* yacc.c:1646  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[-2])->lineno;
                }
#line 2288 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "syntax.y" /* yacc.c:1646  */
    {
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    (yyval) = NEWNODE(TK_STD_DD_ID);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[-2])->lineno;
                }
#line 2304 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 423 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: IGNORE TK_VAR
            if(DEBUG){
                  printf("PARSING VAR PART NOT NULL\n");
              }
              (yyval) = (yyvsp[0]);
        }
#line 2316 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 430 "syntax.y" /* yacc.c:1646  */
    {
              if(DEBUG){
                  printf("PARSING VAR PART NULL\n");
              }
             (yyval) = NULL;
        }
#line 2327 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 438 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING VAR DECL LIST\n");
                }
                (yyval) = (yyvsp[-1]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2348 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 454 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING VAR DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);

                (yyval)->lineno = (yyvsp[0])->lineno;
            }
#line 2363 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 466 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING VAR DECL\n");
            }
            (yyval) = NEWNODE(TK_VAR_DECL);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);

            (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
        }
#line 2380 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 480 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = (yyvsp[-1]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2401 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 496 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = (yyvsp[-1]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2422 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 512 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);

                (yyval)->lineno = (yyvsp[0])->lineno;
            }
#line 2437 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 522 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                (yyval) = NEWNODE(TK_ROUTINE_PART);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);

                (yyval)->lineno = (yyvsp[0])->lineno;
            }
#line 2452 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 532 "syntax.y" /* yacc.c:1646  */
    {
                 if(DEBUG){
                     printf("PARSING ROUTINE_PART NULL\n");
                 }
                 (yyval) = NULL;
             }
#line 2463 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 540 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_SEMI
                if(DEBUG){
                    printf("PARSING FUNC DECL\n");
                }
                (yyval) = NEWNODE(TK_FUNC_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);

                (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
            }
#line 2480 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 554 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_FUNCTION TK_COLON
                if(DEBUG){
                    printf("PARSING TK_FUNCTINO HEAD\n");
                }
                (yyval) = NEWNODE(TK_FUNC_HEAD);
                (yyval)->child = MALLOC((yyval),3);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-2]);
                (yyval)->child[2] = NEWNODE(TK_TYPE_DECL);
                (yyval)->child[2]->lineno = (yyvsp[0])->lineno;
                (yyval)->child[2]->child = MALLOC((yyval), 1);
                (yyval)->child[2]->child[0] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-3]),(yyvsp[-2]));
                (yyval)->lineno = MIN((yyval),(yyvsp[0]));

            }
#line 2503 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 574 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
                if(DEBUG){
                    printf("PARSING PROC DECL\n");
                }
                (yyval) = NEWNODE(TK_PROC_DECL);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-3]);
                (yyval)->child[1] = (yyvsp[-1]);

                (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
            }
#line 2520 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 588 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_PROCEDURE  PROCEDURE_HEAD IS 'TK_PROC_HEAD'
                if(DEBUG){
                    printf("PARSING PROC HEAD\n");
                }
                (yyval) = NEWNODE(TK_PROC_HEAD);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-1]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-1]), (yyvsp[0]));
            }
#line 2537 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 602 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
                if(DEBUG){
                    printf("PARSING PARA\n");
                }
                (yyval) = (yyvsp[-1]);
            }
#line 2549 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 609 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: PARAMETERS IS 'TK_PARA'
                if(DEBUG){
                    printf("PARSING PARA NULL\n");
                }
                (yyval) = NULL;
            }
#line 2561 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 618 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST\n");
                }
                (yyval) = (yyvsp[-2]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
            }
#line 2583 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 635 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_PARA_DL);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);

                (yyval)->lineno = (yyvsp[0])->lineno;
            }
#line 2599 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 648 "syntax.y" /* yacc.c:1646  */
    {
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    (yyval) = NEWNODE(TK_PARA_TL_VAR);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = NEWNODE(TK_TYPE_DECL);
                    (yyval)->child[1]->lineno = (yyvsp[0])->lineno;
                    (yyval)->child[1]->child = MALLOC((yyval), 1);
                    (yyval)->child[1]->child[0] = (yyvsp[0]);

                    (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
                }
#line 2619 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 663 "syntax.y" /* yacc.c:1646  */
    {
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    (yyval) = NEWNODE(TK_PARA_TL_VAL);
                    (yyval)->child = MALLOC((yyval),2);
                    (yyval)->child[0] = (yyvsp[-2]);
                    (yyval)->child[1] = NEWNODE(TK_TYPE_DECL);
                    (yyval)->child[1]->lineno = (yyvsp[0])->lineno;
                    (yyval)->child[1]->child = MALLOC((yyval), 1);
                    (yyval)->child[1]->child[0] = (yyvsp[0]);

                    (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
                }
#line 2639 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 680 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
                if(DEBUG){
                    printf("PARSING VAR LIST\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 2651 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 689 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING VAL PARA LIST\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 2662 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 697 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ROUTINE BODY\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 2673 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 705 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING STMT LIST\n");
            }
            if((yyvsp[-2])==NULL){
          		(yyval) = NEWNODE(TK_STMT_LIST);
          		(yyval)->child = MALLOC((yyval), 1);
          		(yyval)->child[0] = (yyvsp[-1]);

          		(yyval)->lineno = (yyvsp[-1])->lineno;
            }
          	else{
          		(yyval) = (yyvsp[-2]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[-1]);

                free(tmp);
          	}
        }
#line 2703 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 730 "syntax.y" /* yacc.c:1646  */
    {
              if(DEBUG){
                  printf("PARSING STMT LIST NULL\n");
              }
              (yyval)=NULL;
        }
#line 2714 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 738 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: IGNORE TK_COLON
        if(DEBUG){
            printf("PARSING STMT\n");
        }
        (yyval) = NEWNODE(TK_STMT_LABEL);
         (yyval)->child = MALLOC((yyval),2);
         (yyval)->child[0] = (yyvsp[-2]);
         (yyval)->child[1] = (yyvsp[0]);

         (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
    }
#line 2731 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 750 "syntax.y" /* yacc.c:1646  */
    {
         //NOTE: IGNORE TK_COLON
         if(DEBUG){
             printf("PARSING NON LABEL STMT\n");
         }
         (yyval) = NEWNODE(TK_STMT);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);

         (yyval)->lineno = (yyvsp[0])->lineno;
     }
#line 2747 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 763 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING ASSIGN STMT\n");
                    }
                    (yyval) = NEWNODE(TK_STMT_ASSIGN);
                    (yyval)->child = MALLOC((yyval), 1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 2762 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 773 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING PROC STMT\n");
                    }
                    (yyval) = NEWNODE(TK_STMT_PROC);
                    (yyval)->child = MALLOC((yyval), 1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 2777 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 783 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING CP STMT\n");
                    }
                    (yyval) = NEWNODE(TK_STMT_CP);
                    (yyval)->child = MALLOC((yyval), 1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 2792 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 793 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING IF STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2803 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 799 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING REPEAT STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2814 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 805 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING WHILE STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2825 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 811 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING FOR STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2836 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 817 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING CASE STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2847 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 823 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING GOTO STMT\n");
                    }
                    (yyval) = (yyvsp[0]);
                }
#line 2858 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 831 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_ASSIGN
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                (yyval) = NEWNODE(TK_ASSIGN_ID);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
            }
#line 2875 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 843 "syntax.y" /* yacc.c:1646  */
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

                (yyval)->lineno = MIN((yyvsp[-5]), (yyvsp[-3]));
                (yyval)->lineno = MIN((yyval), (yyvsp[0]));
            }
#line 2894 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 857 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                (yyval) = NEWNODE(TK_ASSIGN_DD);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-4]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-4]), (yyvsp[0]));

                (yyvsp[-4])->record = (yyvsp[-2]);
            }
#line 2913 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 873 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_ID);
           (yyval)->child = MALLOC((yyval),1);
           (yyval)->child[0] = (yyvsp[0]);

           (yyval)->lineno = (yyvsp[0])->lineno;
        }
#line 2928 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 883 "syntax.y" /* yacc.c:1646  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_ID_ARGS);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);

           (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
          }
#line 2945 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 895 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_SYS);
           (yyval)->child = MALLOC((yyval),1);
           (yyval)->child[0] = (yyvsp[0]);

           (yyval)->lineno = (yyvsp[0])->lineno;
        }
#line 2960 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 905 "syntax.y" /* yacc.c:1646  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_SYS_ARGS);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);

           (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
          }
#line 2977 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 917 "syntax.y" /* yacc.c:1646  */
    {
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           (yyval) = NEWNODE(TK_PROC_READ);
           (yyval)->child = MALLOC((yyval),2);
           (yyval)->child[0] = (yyvsp[-3]);
           (yyval)->child[1] = (yyvsp[-1]);

           (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
          }
#line 2994 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 931 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING CP STMT\n");
            }
            (yyval) = (yyvsp[-1]);
        }
#line 3005 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 939 "syntax.y" /* yacc.c:1646  */
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

            (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
            (yyval)->lineno = MIN((yyval), (yyvsp[0]));
        }
#line 3024 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 955 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE\n");
                }
                (yyval) = (yyvsp[0]);
            }
#line 3035 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 961 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE NULL\n");
                }
                (yyval) = NULL;
            }
#line 3046 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 969 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_REPEAR TK_UNTIL
                if(DEBUG){
                    printf("PARSING REPEAT STMT\n");
                }
                (yyval) = NEWNODE(TK_REPEAT);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
            }
#line 3063 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 983 "syntax.y" /* yacc.c:1646  */
    {
                //NOTE: IGNORE TK_WHILE TK_DO
                if(DEBUG){
                    printf("PARSING WHILE STMT\n");
                }
                (yyval) = NEWNODE(TK_WHILE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
            }
#line 3080 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 997 "syntax.y" /* yacc.c:1646  */
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

            (yyval)->lineno = MIN((yyvsp[-6]), (yyvsp[-4]));
            (yyval)->lineno = MIN((yyval), (yyvsp[-3]));
            (yyval)->lineno = MIN((yyval), (yyvsp[-2]));
            (yyval)->lineno = MIN((yyval), (yyvsp[0]));
        }
#line 3103 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1017 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR TO\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 3115 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1024 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR DOWNTO\n");
            }
            (yyval) = (yyvsp[0]);
        }
#line 3127 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1033 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_CASE TK_OF TK_END
            if(DEBUG){
                printf("PARSING CASE STMT\n");
            }
            (yyval) = NEWNODE(TK_CASE);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);

            (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));

        }
#line 3145 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1048 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST\n");
            }
            	(yyval) = (yyvsp[-1]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
        }
#line 3167 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1065 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST : FIRST ONE\n");
            }
            (yyval) = NEWNODE(TK_CASE_EL);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);

            (yyval)->lineno = (yyvsp[0])->lineno;
        }
#line 3183 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1078 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            (yyval) = NEWNODE(TK_CASE_EXPR);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);

            (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));

        }
#line 3201 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1091 "syntax.y" /* yacc.c:1646  */
    {
         //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            (yyval) = NEWNODE(TK_CASE_EXPR_END);
            (yyval)->child = MALLOC((yyval),2);
            (yyval)->child[0] = (yyvsp[-3]);
            (yyval)->child[1] = (yyvsp[-1]);

            (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
        }
#line 3218 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1105 "syntax.y" /* yacc.c:1646  */
    {
        //NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
            if(DEBUG){
                printf("PARSING GOTO STMT\n");
            }
            (yyval) = (yyvsp[0]);
            (yyval)->type = TK_GOTO;
           	setName((yyval), TK_GOTO);
        }
#line 3232 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1116 "syntax.y" /* yacc.c:1646  */
    {
                    //NOTE: IGNORE TK_COMMA
                    if(DEBUG){
                        printf("PARSING EXP LIST\n");
                    }
                    (yyval) = (yyvsp[-2]);
                	int old_child_number = (yyval)->child_number;
                	NODE** tmp = (yyval)->child;
                	(yyval)->child = MALLOC((yyval), (1+old_child_number));
                	int i;
                	for(i=0;i<old_child_number;i++){
                		(yyval)->child[i] = tmp[i];
                	}
                	(yyval)->child[i] = (yyvsp[0]);

                	free(tmp);
                }
#line 3254 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1133 "syntax.y" /* yacc.c:1646  */
    {
                    if(DEBUG){
                        printf("PARSING EXP LIST : FIRST ONE\n");
                    }
                    (yyval) = NEWNODE(TK_EXP_LIST);
                    (yyval)->child = MALLOC((yyval),1);
                    (yyval)->child[0] = (yyvsp[0]);

                    (yyval)->lineno = (yyvsp[0])->lineno;
                }
#line 3269 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1145 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_GE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3286 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1157 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_GT);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3302 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1168 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_LE);
                (yyval)->child = MALLOC((yyval),2);
                (yyval)->child[0] = (yyvsp[-2]);
                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3318 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1179 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_LT);
                (yyval)->child = MALLOC((yyval),2);
                                (yyval)->child[0] = (yyvsp[-2]);
                                (yyval)->child[1] = (yyvsp[0]);

                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3334 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1190 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_EQUAL);
                (yyval)->child = MALLOC((yyval),2);
                                (yyval)->child[0] = (yyvsp[-2]);
                                (yyval)->child[1] = (yyvsp[0]);
                 (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3349 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1200 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                (yyval) = NEWNODE(TK_UNEQUAL);
                (yyval)->child = MALLOC((yyval),2);
                                (yyval)->child[0] = (yyvsp[-2]);
                                (yyval)->child[1] = (yyvsp[0]);
                                (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
           }
#line 3364 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1210 "syntax.y" /* yacc.c:1646  */
    {
                if(DEBUG){
                    printf("PARSING EXPRESSION : FIRST ONE\n");
                }
                (yyval) = NEWNODE(TK_EXP);
                (yyval)->child = MALLOC((yyval),1);
                (yyval)->child[0] = (yyvsp[0]);
                (yyval)->lineno = (yyvsp[0])->lineno;
           }
#line 3378 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1221 "syntax.y" /* yacc.c:1646  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_PLUS);
         (yyval)->child = MALLOC((yyval),2);
                         (yyval)->child[0] = (yyvsp[-2]);
                         (yyval)->child[1] = (yyvsp[0]);
                         (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3394 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1232 "syntax.y" /* yacc.c:1646  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_MINUS);
         (yyval)->child = MALLOC((yyval),2);
                         (yyval)->child[0] = (yyvsp[-2]);
                         (yyval)->child[1] = (yyvsp[0]);
                         (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3410 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1243 "syntax.y" /* yacc.c:1646  */
    {
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_OR);
         (yyval)->child = MALLOC((yyval),2);
                         (yyval)->child[0] = (yyvsp[-2]);
                         (yyval)->child[1] = (yyvsp[0]);
                         (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3426 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1254 "syntax.y" /* yacc.c:1646  */
    {
     //NOTE: expr IS EXPR, expression IS EXP
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_EXPR);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);

         (yyval)->lineno = (yyvsp[0])->lineno;
     }
#line 3442 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1267 "syntax.y" /* yacc.c:1646  */
    {
         if(DEBUG){
             printf("PARSING TK_MUL\n");
         }
         (yyval) = NEWNODE(TK_MUL);
         (yyval)->child = MALLOC((yyval),2);
                                  (yyval)->child[0] = (yyvsp[-2]);
                                  (yyval)->child[1] = (yyvsp[0]);
                                  (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3457 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1277 "syntax.y" /* yacc.c:1646  */
    {
         if(DEBUG){
             printf("PARSING TK_DIV\n");
         }
         (yyval) = NEWNODE(TK_DIV);
        (yyval)->child = MALLOC((yyval),2);
                                 (yyval)->child[0] = (yyvsp[-2]);
                                 (yyval)->child[1] = (yyvsp[0]);
                                 (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3472 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1287 "syntax.y" /* yacc.c:1646  */
    {
         if(DEBUG){
             printf("PARSING TK_MOD\n");
         }
         (yyval) = NEWNODE(TK_MOD);
        (yyval)->child = MALLOC((yyval),2);
                                 (yyval)->child[0] = (yyvsp[-2]);
                                 (yyval)->child[1] = (yyvsp[0]);
                                 (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3487 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1297 "syntax.y" /* yacc.c:1646  */
    {
         if(DEBUG){
             printf("PARSING TK_AND\n");
         }
         (yyval) = NEWNODE(TK_AND);
         (yyval)->child = MALLOC((yyval),2);
                                  (yyval)->child[0] = (yyvsp[-2]);
                                  (yyval)->child[1] = (yyvsp[0]);
                                  (yyval)->lineno = MIN((yyvsp[-2]), (yyvsp[0]));
     }
#line 3502 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1307 "syntax.y" /* yacc.c:1646  */
    {
         if(DEBUG){
             printf("PARSING TERM : FIRST ONE\n");
         }
         (yyval) = NEWNODE(TK_TERM);
         (yyval)->child = MALLOC((yyval),1);
         (yyval)->child[0] = (yyvsp[0]);

         (yyval)->lineno = (yyvsp[0])->lineno;
     }
#line 3517 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1319 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
        if(DEBUG){
            printf("PARSING FACTOR\n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);

        (yyval)->lineno = (yyvsp[0])->lineno;
    }
#line 3533 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1330 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID_ARGS);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
        (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
    }
#line 3549 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1341 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_SYS_FUNCT);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
        (yyval)->lineno = MIN((yyvsp[-3]), (yyvsp[-1]));
    }
#line 3565 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1352 "syntax.y" /* yacc.c:1646  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_CONST);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
        (yyval)->lineno = (yyvsp[0])->lineno;
    }
#line 3579 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1361 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_EXP);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[-1]);
        (yyval)->lineno = (yyvsp[-1])->lineno;
    }
#line 3594 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1371 "syntax.y" /* yacc.c:1646  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_NOT);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
        (yyval)->lineno = (yyvsp[0])->lineno;
    }
#line 3608 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1380 "syntax.y" /* yacc.c:1646  */
    {
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_MINUS);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[0]);
        (yyval)->lineno = (yyvsp[0])->lineno;
    }
#line 3622 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1389 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: IGNORE TK_LB TK_RB
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        (yyval) = NEWNODE(TK_FACTOR_ID_EXP);
        (yyval)->child = MALLOC((yyval),2);
        (yyval)->child[0] = (yyvsp[-3]);
        (yyval)->child[1] = (yyvsp[-1]);
        (yyval)->lineno = MIN((yyvsp[-3]),(yyvsp[-1]));
    }
#line 3638 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1400 "syntax.y" /* yacc.c:1646  */
    {
    //NOTE: ID->ID IS IN ONE NODE
        if(DEBUG){
            printf("PARSING FACTOR FOR ID->ID\n");
        }
        (yyval) = NEWNODE(TK_FACTOR_DD);
        (yyval)->child = MALLOC((yyval),1);
        (yyval)->child[0] = (yyvsp[-2]);
        (yyval)->lineno = (yyvsp[-2])->lineno;
        (yyvsp[-2])->record = (yyvsp[-1]);
    }
#line 3654 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1413 "syntax.y" /* yacc.c:1646  */
    {
            //NOTE: IGNORE TK_COMMA
            if(DEBUG){
                printf("PARSING ARGS LIST\n");
            }
            	(yyval) = (yyvsp[-2]);
                int old_child_number = (yyval)->child_number;
                NODE** tmp = (yyval)->child;
                (yyval)->child = MALLOC((yyval), (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	(yyval)->child[i] = tmp[i];
                }
                (yyval)->child[i] = (yyvsp[0]);

                free(tmp);
        }
#line 3676 "yy.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1430 "syntax.y" /* yacc.c:1646  */
    {
            if(DEBUG){
                printf("PARSING ARGS LIST : FIRST ONE\n");
            }
            (yyval) = NEWNODE(TK_ARGS_LIST);
            (yyval)->child = MALLOC((yyval),1);
            (yyval)->child[0] = (yyvsp[0]);
            (yyval)->lineno = (yyvsp[0])->lineno;
        }
#line 3690 "yy.tab.cpp" /* yacc.c:1646  */
    break;


#line 3694 "yy.tab.cpp" /* yacc.c:1646  */
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
#line 1441 "syntax.y" /* yacc.c:1906  */


int yyerror(string s){
    //extern char* yytext;
   // printf("\n");
    //printf( "%s\n", s);
    //fprintf(stderr, "line %d: ", yylineno);
    //fprintf(stderr, "\"%s\"\n", yytext);
    return 1;
}

