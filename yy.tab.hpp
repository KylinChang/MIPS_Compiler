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
    TK_TYPE_PART = 332,
    TK_VAR_PART = 333,
    TK_ROUTINE_PART_RF = 334,
    TK_ROUTINE_PART_RP = 335,
    TK_ROUTINE_PART_FUNC = 336,
    TK_ROUTINE_PART_PROC = 337,
    TK_ROUTINE_PART_NULL = 338,
    TK_STMT_LIST = 339,
    TK_STMT_LIST_NULL = 340,
    TK_STMT_LABEL = 341,
    TK_STMT = 342,
    TK_CP_STMT = 343,
    TK_VAL_PARA_LIST = 344,
    TK_NON_LABEL_STMT_ASSIGN = 345,
    TK_NON_LABEL_STMT_PROC = 346,
    TK_NON_LABEL_STMT_CP = 347,
    TK_NON_LABEL_STMT_IF = 348,
    TK_NON_LABEL_STMT_REP = 349,
    TK_NON_LABEL_STMT_WHILE = 350,
    TK_NON_LABEL_STMT_FOR = 351,
    TK_NON_LABEL_STMT_CASE = 352,
    TK_NON_LABEL_STMT_GOTO = 353,
    TK_EXP_LIST = 354,
    TK_EXP_LIST_END = 355,
    TK_EXP = 356,
    TK_TERM = 357,
    TK_FACTOR_ID = 358,
    TK_FACTOR_ID_ARGS = 359,
    TK_FACTOR_SYS_FUNCT = 360,
    TK_FACTOR_CONST = 361,
    TK_FACTOR_EXP = 362,
    TK_FACTOR_NOT = 363,
    TK_FACTOR_MINUS = 364,
    TK_FACTOR_ID_EXP = 365,
    TK_FACTOR_DD = 366,
    TK_ARGS_LIST = 367,
    TK_ARGS_LIST_END = 368,
    TK_CONST_EL = 369,
    TK_CONST_EL_END = 370,
    TK_TYPE_DL = 371,
    TK_TYPE_DL_END = 372,
    TK_TYPE_DEF = 373,
    TK_TYPE_DECL = 374,
    TK_TYPE_DECL_SIM = 375,
    TK_TYPE_DECL_ARR = 376,
    TK_TYPE_DECL_REC = 377,
    TK_FIELD_DL = 378,
    TK_FIELD_DL_END = 379,
    TK_FIELD_DECL = 380,
    TK_NL = 381,
    TK_NL_END = 382,
    TK_STD_SYS_TYPE = 383,
    TK_STD_ID = 384,
    TK_STD_NL = 385,
    TK_STD_DD = 386,
    TK_STD_DD_M = 387,
    TK_STD_DD_MM = 388,
    TK_STD_DD_ID = 389,
    TK_DL = 390,
    TK_DL_END = 391,
    TK_VAR_DECL = 392,
    TK_FUNC_DECL = 393,
    TK_FUNC_HEAD = 394,
    TK_PROC_DECL = 395,
    TK_PROC_HEAD = 396,
    TK_PARA = 397,
    TK_PARA_TL = 398,
    TK_PARA_NULL = 399,
    TK_PARA_DL = 400,
    TK_PARA_DL_END = 401,
    TK_PARA_TL_VAR = 402,
    TK_PARA_TL_VAL = 403,
    TK_PARA_TL_END = 404,
    TK_PROC = 405,
    TK_CASE_EL = 406,
    TK_CASE_EL_END = 407,
    TK_CASE_EXPR = 408,
    TK_CASE_EXPR_END = 409,
    TK_EXPR = 410,
    TK_ASSIGN_ID = 411,
    TK_ASSIGN_ID_EXPR = 412,
    TK_ASSIGN_DD = 413,
    TK_PROC_ID = 414,
    TK_PROC_ID_ARGS = 415,
    TK_PROC_SYS = 416,
    TK_PROC_SYS_ARGS = 417,
    TK_PROC_READ = 418,
    TK_STMT_ASSIGN = 419,
    TK_STMT_PROC = 420,
    TK_STMT_CP = 421
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
