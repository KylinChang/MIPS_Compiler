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
    TK_CONST_EL = 372,
    TK_CONST_EL_END = 373,
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
#define TK_CONST_EL 372
#define TK_CONST_EL_END 373
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
