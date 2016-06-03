/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "syntax.y" /* yacc.c:1909  */

#include "node.h"

#define YYSTYPE NODE*

NODE* ROOT;

#line 52 "y.tab.h" /* yacc.c:1909  */

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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
