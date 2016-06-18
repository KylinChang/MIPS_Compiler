%{
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
int DEBUG = 0;
int IS_SYNTAX_ERROR=0;
int syntax_const_error = 0;
NODE* ROOT;
extern int yylineno;

#define STR_DOT     "\".\""
#define STR_SEMI    "\";\""
#define STR_EQU     "\"=\""
#define STR_COMMA   "\",\""
#define STR_COLON   "\":\""
#define STR_ASSIGN  "\":=\""
#define STR_RP      "\")\""
#define STR_RB      "\"]\""

#define STR_END     "\"end\""
#define STR_UNTIL   "\"until\""
#define STR_DO      "\"do\""
#define STR_TO_OR_DOWNTO      "\"do\" or \"downto\""
#define STR_OF      "\"of\""
#define STR_LABEL   "\"label\""

void LOG_ERROR(string expected, int line);

%}

%token     TK_AND TK_ARRAY TK_ASSIGN TK_CASE TK_TYPE TK_SYS_TYPE 
%token     TK_COLON TK_COMMA TK_CONST TK_DIGITS TK_DIV  TK_REM TK_DO TK_DOT TK_DOTDOT
%token     TK_DOWNTO TK_ELSE  TK_ELSE_NULL TK_END TK_EQUAL TK_FOR
%token     TK_FUNCTION TK_GE TK_GOTO TK_GT TK_ID TK_REF TK_IF TK_IN TK_LB
%token     TK_LE TK_LP TK_LT TK_MINUS TK_MOD TK_UNEQUAL TK_OF TK_OR
%token     TK_OTHERWISE TK_BEGIN TK_PLUS TK_PROCEDURE
%token     TK_PROGRAM TK_RB TK_REAL TK_RECORD TK_REPEAT TK_RP TK_SYS_PROC TK_READ TK_READLN
%token     TK_SEMI TK_MUL TK_THEN TK_NOT
%token     TK_TO TK_UNTIL TK_UPARROW TK_VAR TK_WHILE TK_SET TK_STARSTAR
%token     TK_CHAR TK_STRING TK_INTEGER TK_SYS_CON TK_SYS_FUNCT TK_WITH TK_NIL
%token     ERROR 

%token     TK_PROGRAM_HEAD TK_ROUTINE TK_ROUTINE_PART TK_ROUTINE_HEAD TK_ROUTINE_BODY TK_CONST_PART TK_CONST_PART_END
        TK_TYPE_PART TK_TYPE_PART_END TK_VAR_PART TK_VAR_PART_END TK_ROUTINE_PART_RF TK_ROUTINE_PART_RP TK_ROUTINE_PART_FUNC TK_ROUTINE_PART_PROC TK_ROUTINE_PART_NULL TK_STMT_LIST TK_STMT_LIST_NULL TK_STMT_LABEL TK_STMT TK_CP_STMT

%token     TK_VAL_PARA_LIST TK_NON_LABEL_STMT_ASSIGN TK_NON_LABEL_STMT_PROC TK_NON_LABEL_STMT_CP 	
		TK_NON_LABEL_STMT_IF TK_NON_LABEL_STMT_REP TK_NON_LABEL_STMT_WHILE TK_NON_LABEL_STMT_FOR
		TK_NON_LABEL_STMT_CASE TK_NON_LABEL_STMT_GOTO
		TK_EXP_LIST TK_EXP_LIST_END TK_EXP TK_TERM  TK_CONST_MINUS TK_ID_MINUS
        TK_FACTOR_ID TK_FACTOR_ID_ARGS TK_FACTOR_SYS_FUNCT TK_FACTOR_CONST TK_FACTOR_EXP TK_FACTOR_NOT
        TK_FACTOR_MINUS TK_FACTOR_ID_EXP TK_FACTOR_DD TK_ARGS_LIST TK_ARGS_LIST_END
        TK_CONST_DL TK_CONST_DL_END TK_TYPE_DL TK_TYPE_DL_END TK_TYPE_DEF TK_TYPE_DECL TK_TYPE_DECL_SIM TK_TYPE_DECL_ARR TK_TYPE_DECL_REC
        TK_FIELD_DL TK_FIELD_DL_END TK_FIELD_DECL TK_NL TK_NL_END
        TK_STD_SYS_TYPE TK_STD_ID TK_STD_NL TK_STD_DD TK_STD_DD_M TK_STD_DD_MM TK_STD_DD_ID TK_DL TK_DL_END TK_VAR_DECL TK_FUNC_DECL TK_FUNC_HEAD 
        TK_PROC_DECL TK_PROC_HEAD TK_PARA  TK_PARA_TL TK_PARA_NULL TK_PARA_DL TK_PARA_DL_END TK_PARA_TL_VAR TK_PARA_TL_VAL TK_PARA_TL_END TK_PROC
        TK_CASE_EL TK_CASE_EL_END TK_CASE_EXPR TK_CASE_EXPR_END TK_EXPR TK_ASSIGN_ID TK_ASSIGN_ID_EXPR TK_ASSIGN_DD
        TK_PROC_ID TK_PROC_ID_ARGS TK_PROC_SYS TK_PROC_SYS_ARGS TK_PROC_READ TK_PROC_READLN
        TK_STMT_ASSIGN TK_STMT_PROC TK_STMT_CP

%%
program : program_head routine TK_DOT{
            if(DEBUG){
                printf("PARSING PROGRAM\n");
            }
            $$ = NEWNODE(TK_PROGRAM);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $2;

            $$->lineno = MIN($1,$2);

            if(syntax_const_error)
                ROOT = NULL;
            else
                ROOT = $$;
        }
        |program_head routine error{
            if(DEBUG){
                printf("PARSING PROGRAM\n");
            }
            $$ = NEWNODE(TK_PROGRAM);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $2;

            $$->lineno = MIN($1,$2);

            if(syntax_const_error)
                ROOT = NULL;
            else
                ROOT = $$;

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_DOT,yylineno);
        }
        ;

program_head : TK_PROGRAM TK_ID TK_SEMI{
        //NOTE: PROGRAM HEAD ACTUALLY IS TK_ID
            if(DEBUG){
                printf("PROGRAM HEAD:%s\n", $2->name.c_str());
            }
            $$ = $2;
            $$->type = TK_PROGRAM_HEAD;
            $$->child_number = 0;
            $$->child = NULL;
        }
        |TK_PROGRAM TK_ID error{
        //NOTE: PROGRAM HEAD ACTUALLY IS TK_ID
            if(DEBUG){
                printf("PROGRAM HEAD:%s\n", $2->name.c_str());
            }
            $$ = $2;
            $$->type = TK_PROGRAM_HEAD;
            $$->child_number = 0;
            $$->child = NULL;

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_SEMI, $$->lineno);
        }
        ;

routine : routine_head routine_body{
            if(DEBUG){
                printf("PARSING ROUTINE\n");
            }
            $$ = NEWNODE(TK_ROUTINE);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $2;

            $$->lineno = MIN($1,$2);
        }
        ;

routine_head : const_part type_part var_part routine_part{
            if(DEBUG){
                printf("PARSING ROUTINE HEAD\n");
            }
            $$ = NEWNODE(TK_ROUTINE_HEAD);
            $$->child = MALLOC($$,4);
            $$->child[0] = $1;
            $$->child[1] = $2;
            $$->child[2] = $3;
            $$->child[3] = $4;

            $$->lineno = MIN($1,$2);
            $$->lineno = MIN($$,$3);
            $$->lineno = MIN($$,$4);
        }
        ;

const_part : TK_CONST const_expr_list{
        //NOTE: IGNORE TK_CONST
            if(DEBUG){
                printf("PARSING CONST PART\n");
            }
            $$ = $2;
        }
        |{
            if(DEBUG){
                printf("PARSING CONST PART NULL\n");
            }
            $$ = NULL;
        }
        ;

const_expr_list : const_expr_list TK_ID TK_EQUAL const_value TK_SEMI{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST\n");
                    }
                    $$ = $1;
                    NODE* node = NEWNODE(TK_CONST_DL_END);
                    node->child = MALLOC(node,2);
                    node->child[0] = $2;
                    node->child[1] = $4;

                    NODE** tmp = $$->child;
                    int old_child_number = $$->child_number;
                    $$->child = MALLOC($$, (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                    	$$->child[i] = tmp[i];
                    }
                    $$->child[i] = node;

                    free(tmp);
                }
                |const_expr_list TK_ID error {  IS_SYNTAX_ERROR = 1;LOG_ERROR(STR_EQU,$2->lineno);} const_value TK_SEMI{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST\n");
                    }
                    $$ = $1;
                    NODE* node = NEWNODE(TK_CONST_DL_END);
                    node->child = MALLOC(node,2);
                    node->child[0] = $2;
                    node->child[1] = $4;

                    NODE** tmp = $$->child;
                    int old_child_number = $$->child_number;
                    $$->child = MALLOC($$, (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                        $$->child[i] = tmp[i];
                    }
                    $$->child[i] = node;

                    free(tmp);
                }
                |const_expr_list TK_ID TK_EQUAL const_value error{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST\n");
                    }
                    $$ = $1;
                    NODE* node = NEWNODE(TK_CONST_DL_END);
                    node->child = MALLOC(node,2);
                    node->child[0] = $2;
                    node->child[1] = $4;

                    NODE** tmp = $$->child;
                    int old_child_number = $$->child_number;
                    $$->child = MALLOC($$, (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                        $$->child[i] = tmp[i];
                    }
                    $$->child[i] = node;

                    free(tmp);

                    IS_SYNTAX_ERROR = 1;
                    LOG_ERROR(STR_SEMI, $4->lineno);
                }
                | TK_ID TK_EQUAL const_value TK_SEMI{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST : FIRST ONE\n");
                    }
                    $$ = NEWNODE(TK_CONST_DL);
                    NODE* node = NEWNODE(TK_CONST_DL_END);

                    node->child = MALLOC(node,2);
                    node->child[0] = $1;
                    node->child[1] = $3;
                    $$->lineno = node->lineno = MIN($1, $3);

                    $$->child = MALLOC($$,1);
                    $$->child[0] = node;
                }
                | TK_ID error { IS_SYNTAX_ERROR = 1;LOG_ERROR(STR_EQU,$1->lineno); } const_value TK_SEMI{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST : FIRST ONE\n");
                    }
                    $$ = NEWNODE(TK_CONST_DL);
                    NODE* node = NEWNODE(TK_CONST_DL_END);

                    node->child = MALLOC(node,2);
                    node->child[0] = $1;
                    node->child[1] = $3;
                    $$->lineno = node->lineno = MIN($1, $3);

                    $$->child = MALLOC($$,1);
                    $$->child[0] = node;
                }
                |TK_ID TK_EQUAL const_value error{
                //NOTE: IGNORE TK_EQUAL TK_SEMI
                    if(DEBUG){
                        printf("PARSING CONST EXPR LIST : FIRST ONE\n");
                    }
                    $$ = NEWNODE(TK_CONST_DL);
                    NODE* node = NEWNODE(TK_CONST_DL_END);

                    node->child = MALLOC(node,2);
                    node->child[0] = $1;
                    node->child[1] = $3;
                    $$->lineno = node->lineno = MIN($1, $3);

                    $$->child = MALLOC($$,1);
                    $$->child[0] = node;

                    IS_SYNTAX_ERROR = 1;
                    LOG_ERROR(STR_SEMI, $3->lineno);
                }
                ;

const_value : TK_INTEGER{
                if(DEBUG){
                    printf("PARSING COSNT VALUE INTEGER\n");
                }
                $$ = $1;
            }
            | TK_REAL{
                if(DEBUG){
                    printf("PARSING COSNT VALUE REAL\n");
                }
                $$ = $1;
            }
            | TK_CHAR{
                if(DEBUG){
                    printf("PARSING COSNT VALUE CHAR\n");
                }
                $$ = $1;
            }
            | TK_STRING{
                if(DEBUG){
                    printf("PARSING COSNT VALUE STRING\n");
                }
                $$ = $1;
            }
            | TK_SYS_CON{
                if(DEBUG){
                    printf("PARSING COSNT VALUE SYS CON\n");
                }
                $$ = $1;
            }
            ;

type_part : TK_TYPE type_decl_list{
            //NOTE: IGNORE TYPE
            if(DEBUG){
                printf("PARSING TYPE PART NULL\n");
            }
            $$ = $2;
        }
        |{
              //NOTE: IGNORE TYPE
                  if(DEBUG){
                      printf("PARSING TYPE PART NULL\n");
                  }
                $$=NULL;
                }
        ;

type_decl_list : type_decl_list type_definition{
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST DEF\n");
                    }
                    $$ = $1;

                    int old_child_number = $$->child_number;
                    NODE** tmp = $$->child;
                    $$->child = MALLOC($$, (1+old_child_number));
                    int i;
                    for(i=0;i<old_child_number;i++){
                    	$$->child[i] = tmp[i];
                    }
                    $$->child[i] = $2;
                }
               | type_definition{
                    if(DEBUG){
                        printf("PARSING TYPE DECL LIST\n");
                    }
                    $$ = NEWNODE(TK_TYPE_DL);
                    $$->child = MALLOC($$,1);
                    $$->child[0] = $1;
                    $$->lineno = $1->lineno;
               }
               ;

type_definition : TK_ID TK_EQUAL type_decl TK_SEMI{
                    if(DEBUG){
                        printf("PARSING TYPE DEF\n");
                    }
                    $$ = NEWNODE(TK_TYPE_DEF);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = $3;

                    $$->lineno = MIN($1,$3);
                }
                |TK_ID error { IS_SYNTAX_ERROR = 1;LOG_ERROR(STR_EQU,$1->lineno); } type_decl TK_SEMI{
                    if(DEBUG){
                        printf("PARSING TYPE DEF\n");
                    }
                    $$ = NEWNODE(TK_TYPE_DEF);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = $3;

                    $$->lineno = MIN($1,$3);
                }
                | TK_ID TK_EQUAL type_decl error{
                    if(DEBUG){
                        printf("PARSING TYPE DEF\n");
                    }
                    $$ = NEWNODE(TK_TYPE_DEF);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = $3;

                    $$->lineno = MIN($1,$3);

                    IS_SYNTAX_ERROR = 1;
                    LOG_ERROR(STR_SEMI, yylineno);
                }
                ;

type_decl : simple_type_decl{
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                $$ = NEWNODE(TK_TYPE_DECL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;
                $$->lineno = $1->lineno;
          }
          | array_type_decl{
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                $$ = NEWNODE(TK_TYPE_DECL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;
                $$->lineno = $1->lineno;
          }
          | record_type_decl{
                if(DEBUG){
                    printf("PARSING TYPE DECL\n");
                }
                $$ = NEWNODE(TK_TYPE_DECL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;
                $$->lineno = $1->lineno;
          }
          ;

array_type_decl : TK_ARRAY TK_LB simple_type_decl TK_RB TK_OF type_decl{
                //NOTE: IGNORE TK_LB TK_RB TK_OF
                if(DEBUG){
                    printf("PARSING ARRAY\n");
                }
                $$ = NEWNODE(TK_ARRAY);
                $$->child = MALLOC($$,2);
                $$->child[0] = NEWNODE(TK_TYPE_DECL);
                $$->child[0]->lineno = $3->lineno;
                $$->child[0]->child = MALLOC($$, 1);
                $$->child[0]->child[0] = $3;
                $$->child[1] = $6;

                $$->lineno = MIN($3, $6);
            }
            |TK_ARRAY TK_LB simple_type_decl error { IS_SYNTAX_ERROR = 1; LOG_ERROR(STR_RB, yylineno); } TK_OF type_decl{
                //NOTE: IGNORE TK_LB TK_RB TK_OF
                if(DEBUG){
                    printf("PARSING ARRAY\n");
                }
                $$ = NEWNODE(TK_ARRAY);
                $$->child = MALLOC($$,2);
                $$->child[0] = NEWNODE(TK_TYPE_DECL);
                $$->child[0]->lineno = $3->lineno;
                $$->child[0]->child = MALLOC($$, 1);
                $$->child[0]->child[0] = $3;
                $$->child[1] = $6;

                $$->lineno = MIN($3, $6);
            }
            ;

record_type_decl : TK_RECORD field_decl_list TK_END{
                //NOTE: IGNORE TK_END
                if(DEBUG){
                    printf("PARSING RECORD TYPE DECL\n");
                }
                $$ = $2;
            }
            | TK_RECORD field_decl_list error{
                //NOTE: IGNORE TK_END
                if(DEBUG){
                    printf("PARSING RECORD TYPE DECL\n");
                }
                $$ = $2;

                IS_SYNTAX_ERROR = 1;
                LOG_ERROR(STR_END,$2->lineno);
            }
            ;

field_decl_list : field_decl_list field_decl{
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
            }
            | field_decl{
                if(DEBUG){
                    printf("PARSING FIELD DECL LIST : FIRST ONE\n");
                }
                $$ = NEWNODE(TK_FIELD_DL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;

                $$->lineno = $1->lineno;
            }
            ;

field_decl : name_list TK_COLON type_decl TK_SEMI{
            //NOTE: IGNORE TK_COLON TK_SEMI
                if(DEBUG){
                    printf("PARSING FIELD DECL\n");
                }
                $$ = NEWNODE(TK_FIELD_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1,$3);
            } 
            | name_list error {IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, yylineno);} type_decl TK_SEMI{
            //NOTE: IGNORE TK_COLON TK_SEMI
                if(DEBUG){
                    printf("PARSING FIELD DECL\n");
                }
                $$ = NEWNODE(TK_FIELD_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1,$3);
            } 
            | name_list TK_COLON type_decl error{
            //NOTE: IGNORE TK_COLON TK_SEMI
                if(DEBUG){
                    printf("PARSING FIELD DECL\n");
                }
                $$ = NEWNODE(TK_FIELD_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1,$3);

                IS_SYNTAX_ERROR = 1;
                LOG_ERROR(STR_SEMI, yylineno);
            } 
            ;

name_list : name_list TK_COMMA TK_ID{
            //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
                if(DEBUG){
                    printf("PARSING NAME LIST\n");
                }
              	$$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $3;

                free(tmp);
            }
              | TK_ID{
                  if(DEBUG){
                      printf("PARSING NAME LIST : FIRST ONE\n");
                  }
                  $$ = NEWNODE(TK_NL);
                  $$->child = MALLOC($$,1);
                  $$->child[0] = $1;

                  $$->lineno = $1->lineno;
              }
              ;

simple_type_decl : TK_SYS_TYPE{
                //NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
                    }
                    $$ = NEWNODE(TK_STD_SYS_TYPE);
                    $$->child = MALLOC($$,1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
                 | TK_ID{
                    if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    $$ = NEWNODE(TK_STD_ID);
                    $$->child = MALLOC($$,1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
                 | TK_LP name_list TK_RP{
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    $$ = NEWNODE(TK_STD_NL);
                    $$->child = MALLOC($$,1);
                    $$->child[0] = $2;

                    $$->lineno = $1->lineno;
                }
                 | const_value TK_DOTDOT const_value{
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    $$ = NEWNODE(TK_STD_DD);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = $3;

                    $$->lineno = $1->lineno;
                }
                 | TK_MINUS const_value TK_DOTDOT const_value{
                                      if(DEBUG){
                                         printf("PARSING SIMPLE TYPE DECL ID\n");
                                     }
                                     $$ = NEWNODE(TK_STD_DD);
                                     $$->child = MALLOC($$,2);
                                     if($2->type!=TK_INTEGER){
                                        syntax_const_error  = 1;
                                     }else{
                                        $2->value.ival *= -1;
                                     }

                                     $$->child[0] = $2;
                                     $$->child[1] = $4;

                                     $$->lineno = $1->lineno;
                   }
                 | TK_MINUS const_value TK_DOTDOT TK_MINUS const_value{
                                      if(DEBUG){
                                         printf("PARSING SIMPLE TYPE DECL ID\n");
                                      }
                                      if($2->type!=TK_INTEGER){
                                         syntax_const_error  = 1;
                                      }else{
                                           $2->value.ival *= -1;
                                      }
                                      if($5->type!=TK_INTEGER){
                                         syntax_const_error  = 1;
                                      }else{
                                         $5->value.ival *= -1;
                                      }

                                     $$ = NEWNODE(TK_STD_DD);
                                     $$->child = MALLOC($$,2);
                                     $$->child[0] = $2;
                                     $$->child[1] = $5;

                                     $$->lineno = $1->lineno;
                 }
                 | TK_ID TK_DOTDOT TK_ID{
                     if(DEBUG){
                        printf("PARSING SIMPLE TYPE DECL ID\n");
                    }
                    $$ = NEWNODE(TK_STD_DD_ID);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = $3;

                    $$->lineno = $1->lineno;
                }
                | TK_MINUS TK_ID TK_DOTDOT TK_ID{
                                     if(DEBUG){
                                        printf("PARSING SIMPLE TYPE DECL ID\n");
                                    }
                                    $$ = NEWNODE(TK_STD_DD_ID);
                                    $$->child = MALLOC($$,2);

                                    $2->type = TK_ID_MINUS;
                                    $$->child[0] = $2;

                                    $$->child[1] = $4;

                                    $$->lineno = $2->lineno;
                                }
                | TK_ID TK_DOTDOT TK_MINUS TK_ID{
                                     if(DEBUG){
                                        printf("PARSING SIMPLE TYPE DECL ID\n");
                                    }
                                    $$ = NEWNODE(TK_STD_DD_ID);
                                    $$->child = MALLOC($$,2);

                                    $$->child[0] = $1;
                                    $4->type = TK_ID_MINUS;
                                    $$->child[1] = $4;

                                    $$->lineno = $1->lineno;
                                }
                | TK_MINUS TK_ID TK_DOTDOT TK_MINUS TK_ID{
                                     if(DEBUG){
                                         printf("PARSING SIMPLE TYPE DECL ID\n");
                                     }
                                     $$ = NEWNODE(TK_STD_DD_ID);
                                     $$->child = MALLOC($$,2);

                                     $2->type = TK_ID_MINUS;
                                     $$->child[0] = $2;
                                     $5->type = TK_ID_MINUS;
                                     $$->child[1] = $5;

                                     $$->lineno = $2->lineno;
                                 }
                 ;

var_part : TK_VAR var_decl_list{
        //NOTE: IGNORE TK_VAR
            if(DEBUG){
                  printf("PARSING VAR PART NOT NULL\n");
              }
              $$ = $2;
        }
        |{
              if(DEBUG){
                  printf("PARSING VAR PART NULL\n");
              }
             $$ = NULL;
        }
        ;

var_decl_list : var_decl_list var_decl{
                if(DEBUG){
                    printf("PARSING VAR DECL LIST\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
            }
            | var_decl{
                if(DEBUG){
                    printf("PARSING VAR DECL LIST : FIRST ONE\n");
                }
                $$ = NEWNODE(TK_DL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;

                $$->lineno = $1->lineno;
            }
            ;

var_decl : name_list TK_COLON type_decl TK_SEMI{
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING VAR DECL\n");
            }
            $$ = NEWNODE(TK_VAR_DECL);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);
        }
        |name_list error {IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, yylineno);} type_decl TK_SEMI{
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING VAR DECL\n");
            }
            $$ = NEWNODE(TK_VAR_DECL);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);
        }
        | name_list TK_COLON type_decl error{
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING VAR DECL\n");
            }
            $$ = NEWNODE(TK_VAR_DECL);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_SEMI, yylineno);
        }
        ;

routine_part : routine_part function_decl{
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
            }
             | routine_part procedure_decl{
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
            }
             | function_decl{
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                $$ = NEWNODE(TK_ROUTINE_PART);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;

                $$->lineno = $1->lineno;
            }
             | procedure_decl{
                if(DEBUG){
                    printf("PARSING ROUTINE_PART\n");
                }
                $$ = NEWNODE(TK_ROUTINE_PART);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;

                $$->lineno = $1->lineno;
            }
             |{
                 if(DEBUG){
                     printf("PARSING ROUTINE_PART NULL\n");
                 }
                 $$ = NULL;
             }
             ;

function_decl : function_head TK_SEMI routine TK_SEMI{
                //NOTE: IGNORE TK_SEMI
                if(DEBUG){
                    printf("PARSING FUNC DECL\n");
                }
                $$ = NEWNODE(TK_FUNC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
            }
            |function_head TK_SEMI routine error{
                //NOTE: IGNORE TK_SEMI
                if(DEBUG){
                    printf("PARSING FUNC DECL\n");
                }
                $$ = NEWNODE(TK_FUNC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);

                IS_SYNTAX_ERROR = 1;
                LOG_ERROR(STR_SEMI, yylineno);
            }
            | function_head error { IS_SYNTAX_ERROR = 1;LOG_ERROR(STR_SEMI, $1->lineno); } routine TK_SEMI{
                //NOTE: IGNORE TK_SEMI
                if(DEBUG){
                    printf("PARSING FUNC DECL\n");
                }
                $$ = NEWNODE(TK_FUNC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
            }
            ;

function_head : TK_FUNCTION TK_ID parameters TK_COLON simple_type_decl{
                //NOTE: IGNORE TK_FUNCTION TK_COLON
                if(DEBUG){
                    printf("PARSING TK_FUNCTINO HEAD\n");
                }
                $$ = NEWNODE(TK_FUNC_HEAD);
                $$->child = MALLOC($$,3);
                $$->child[0] = $2;
                $$->child[1] = $3;
                $$->child[2] = NEWNODE(TK_TYPE_DECL);
                $$->child[2]->lineno = $5->lineno;
                $$->child[2]->child = MALLOC($$, 1);
                $$->child[2]->child[0] = $5;

                $$->lineno = MIN($2,$3);
                $$->lineno = MIN($$,$5);

            }
            | TK_FUNCTION TK_ID parameters error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, yylineno); } simple_type_decl{
                //NOTE: IGNORE TK_FUNCTION TK_COLON
                if(DEBUG){
                    printf("PARSING TK_FUNCTINO HEAD\n");
                }
                $$ = NEWNODE(TK_FUNC_HEAD);
                $$->child = MALLOC($$,3);
                $$->child[0] = $2;
                $$->child[1] = $3;
                $$->child[2] = NEWNODE(TK_TYPE_DECL);
                $$->child[2]->lineno = $5->lineno;
                $$->child[2]->child = MALLOC($$, 1);
                $$->child[2]->child[0] = $5;

                $$->lineno = MIN($2,$3);
                $$->lineno = MIN($$,$5);

            }
            ;

procedure_decl : procedure_head TK_SEMI routine TK_SEMI{
                //NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
                if(DEBUG){
                    printf("PARSING PROC DECL\n");
                }
                $$ = NEWNODE(TK_PROC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
            }
            | procedure_head TK_SEMI routine error{
                //NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
                if(DEBUG){
                    printf("PARSING PROC DECL\n");
                }
                $$ = NEWNODE(TK_PROC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);

                IS_SYNTAX_ERROR = 1;
                LOG_ERROR(STR_SEMI, yylineno);
            }
            | procedure_head error { IS_SYNTAX_ERROR = 1;LOG_ERROR(STR_SEMI, $1->lineno); } routine TK_SEMI{
                //NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
                if(DEBUG){
                    printf("PARSING PROC DECL\n");
                }
                $$ = NEWNODE(TK_PROC_DECL);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
            }
            ;

procedure_head : TK_PROCEDURE TK_ID parameters{
                //NOTE: IGNORE TK_PROCEDURE  PROCEDURE_HEAD IS 'TK_PROC_HEAD'
                if(DEBUG){
                    printf("PARSING PROC HEAD\n");
                }
                $$ = NEWNODE(TK_PROC_HEAD);
                $$->child = MALLOC($$,2);
                $$->child[0] = $2;
                $$->child[1] = $3;

                $$->lineno = MIN($2, $3);
            }
            ;

parameters : TK_LP para_decl_list TK_RP{
            //NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
                if(DEBUG){
                    printf("PARSING PARA\n");
                }
                $$ = $2;
            }
            | TK_LP para_decl_list error{
            //NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
                if(DEBUG){
                    printf("PARSING PARA\n");
                }
                $$ = $2;

                IS_SYNTAX_ERROR=1; 
                LOG_ERROR(STR_RP, yylineno); 
            }
            |{
            //NOTE: PARAMETERS IS 'TK_PARA'
                if(DEBUG){
                    printf("PARSING PARA NULL\n");
                }
                $$ = NULL;
            }
            ;

para_decl_list : para_decl_list TK_SEMI para_type_list{
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $3;

                free(tmp);
            }
            |para_decl_list error {  IS_SYNTAX_ERROR = 1; LOG_ERROR(STR_SEMI, yylineno); }  para_type_list{
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST\n");
                }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                    $$->child[i] = tmp[i];
                }
                $$->child[i] = $3;

                free(tmp);
            }
            | para_type_list{
                //NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
                if(DEBUG){
                    printf("PARSING PARA DECL LIST : FIRST ONE\n");
                }
                $$ = NEWNODE(TK_PARA_DL);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;

                $$->lineno = $1->lineno;
            }
            ;

para_type_list : var_para_list TK_COLON simple_type_decl{
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    $$ = NEWNODE(TK_PARA_TL_VAR);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = NEWNODE(TK_TYPE_DECL);
                    $$->child[1]->lineno = $3->lineno;
                    $$->child[1]->child = MALLOC($$, 1);
                    $$->child[1]->child[0] = $3;

                    $$->lineno = MIN($1, $3);
                }
                | var_para_list error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, yylineno); } simple_type_decl{
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    $$ = NEWNODE(TK_PARA_TL_VAR);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = NEWNODE(TK_TYPE_DECL);
                    $$->child[1]->lineno = $3->lineno;
                    $$->child[1]->child = MALLOC($$, 1);
                    $$->child[1]->child[0] = $3;

                    $$->lineno = MIN($1, $3);
                }
                | val_para_list TK_COLON simple_type_decl{
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    $$ = NEWNODE(TK_PARA_TL_VAL);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = NEWNODE(TK_TYPE_DECL);
                    $$->child[1]->lineno = $3->lineno;
                    $$->child[1]->child = MALLOC($$, 1);
                    $$->child[1]->child[0] = $3;

                    $$->lineno = MIN($1, $3);
                }
                | val_para_list error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, yylineno); } simple_type_decl{
                    //NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
                    if(DEBUG){
                        printf("PARSING TK_COLON\n");
                    }
                    $$ = NEWNODE(TK_PARA_TL_VAL);
                    $$->child = MALLOC($$,2);
                    $$->child[0] = $1;
                    $$->child[1] = NEWNODE(TK_TYPE_DECL);
                    $$->child[1]->lineno = $3->lineno;
                    $$->child[1]->child = MALLOC($$, 1);
                    $$->child[1]->child[0] = $3;

                    $$->lineno = MIN($1, $3);
                }
               ;

var_para_list : TK_VAR name_list{
                //NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
                if(DEBUG){
                    printf("PARSING VAR LIST\n");
                }
                $$ = $2;
            }
            ;

val_para_list : name_list{
                if(DEBUG){
                    printf("PARSING VAL PARA LIST\n");
                }
                $$ = $1;
            }
            ;

routine_body : compound_stmt{
                if(DEBUG){
                    printf("PARSING ROUTINE BODY\n");
                }
                $$ = $1;
            }
            ;

stmt_list : stmt_list stmt TK_SEMI{
            if(DEBUG){
                printf("PARSING STMT LIST\n");
            }
            if($1==NULL){
          		$$ = NEWNODE(TK_STMT_LIST);
          		$$->child = MALLOC($$, 1);
          		$$->child[0] = $2;

          		$$->lineno = $2->lineno;
            }
          	else{
          		$$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
          	}
        }
        | stmt_list stmt error{
            if(DEBUG){
                printf("PARSING STMT LIST\n");
            }
            if($1==NULL){
                $$ = NEWNODE(TK_STMT_LIST);
                $$->child = MALLOC($$, 1);
                $$->child[0] = $2;

                $$->lineno = $2->lineno;
            }
            else{
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                    $$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
            }

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_SEMI, $2->lineno);
        }
        |{
              if(DEBUG){
                  printf("PARSING STMT LIST NULL\n");
              }
              $$=NULL;
        }
        ;

stmt : TK_INTEGER TK_COLON non_label_stmt{
        //NOTE: IGNORE TK_COLON
        if(DEBUG){
            printf("PARSING STMT\n");
        }
        $$ = NEWNODE(TK_STMT_LABEL);
         $$->child = MALLOC($$,2);
         $$->child[0] = $1;
         $$->child[1] = $3;

         $$->lineno = MIN($1, $3);
    }    
    |TK_INTEGER error{ IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COLON, $1->lineno); } non_label_stmt{
        //NOTE: IGNORE TK_COLON
        if(DEBUG){
            printf("PARSING STMT\n");
        }
        $$ = NEWNODE(TK_STMT_LABEL);
         $$->child = MALLOC($$,2);
         $$->child[0] = $1;
         $$->child[1] = $3;

         $$->lineno = MIN($1, $3);
    }    
     | non_label_stmt{
         //NOTE: IGNORE TK_COLON
         if(DEBUG){
             printf("PARSING NON LABEL STMT\n");
         }
         $$ = NEWNODE(TK_STMT);
         $$->child = MALLOC($$,1);
         $$->child[0] = $1;

         $$->lineno = $1->lineno;
     }
     ;

non_label_stmt : assign_stmt{
                    if(DEBUG){
                        printf("PARSING ASSIGN STMT\n");
                    }
                    $$ = NEWNODE(TK_STMT_ASSIGN);
                    $$->child = MALLOC($$, 1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
               | proc_stmt{
                    if(DEBUG){
                        printf("PARSING PROC STMT\n");
                    }
                    $$ = NEWNODE(TK_STMT_PROC);
                    $$->child = MALLOC($$, 1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
               | compound_stmt{
                    if(DEBUG){
                        printf("PARSING CP STMT\n");
                    }
                    $$ = NEWNODE(TK_STMT_CP);
                    $$->child = MALLOC($$, 1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
               | if_stmt{
                    if(DEBUG){
                        printf("PARSING IF STMT\n");
                    }
                    $$ = $1;
                }
               | repeat_stmt{
                    if(DEBUG){
                        printf("PARSING REPEAT STMT\n");
                    }
                    $$ = $1;
                }
               | while_stmt{
                    if(DEBUG){
                        printf("PARSING WHILE STMT\n");
                    }
                    $$ = $1;
                }
               | for_stmt{
                    if(DEBUG){
                        printf("PARSING FOR STMT\n");
                    }
                    $$ = $1;
                }
               | case_stmt{
                    if(DEBUG){
                        printf("PARSING CASE STMT\n");
                    }
                    $$ = $1;
                }
               | goto_stmt{
                    if(DEBUG){
                        printf("PARSING GOTO STMT\n");
                    }
                    $$ = $1;
                }
               ;

assign_stmt : TK_ID TK_ASSIGN expression{
                //NOTE: IGNORE TK_ASSIGN
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                $$ = NEWNODE(TK_ASSIGN_ID);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
            }
            | TK_ID TK_LB expr TK_RB TK_ASSIGN expression{
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                $$ = NEWNODE(TK_ASSIGN_ID_EXPR);
                $$->child = MALLOC($$,3);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->child[2] = $6;

                $$->lineno = MIN($1, $3);
                $$->lineno = MIN($$, $6);
            }
            | TK_ID TK_LB expr error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_RB, yylineno);} TK_ASSIGN expression{
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                $$ = NEWNODE(TK_ASSIGN_ID_EXPR);
                $$->child = MALLOC($$,3);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->child[2] = $6;

                $$->lineno = MIN($1, $3);
                $$->lineno = MIN($$, $6);
            }
            | TK_ID TK_DOT TK_ID TK_ASSIGN  expression{
                //NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
                if(DEBUG){
                    printf("PARSING ASSIGN\n");
                }
                $$ = NEWNODE(TK_ASSIGN_DD);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $5;

                $$->lineno = MIN($1, $5);

                $1->record = $3;
            }
            ;

proc_stmt : TK_ID{
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_ID);
           $$->child = MALLOC($$,1);
           $$->child[0] = $1;

           $$->lineno = $1->lineno;
        }
          | TK_ID TK_LP args_list TK_RP{
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_ID_ARGS);
           $$->child = MALLOC($$,2);
           $$->child[0] = $1;
           $$->child[1] = $3;

           $$->lineno = MIN($1, $3);
          }
          | TK_ID TK_LP args_list error{
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_ID_ARGS);
           $$->child = MALLOC($$,2);
           $$->child[0] = $1;
           $$->child[1] = $3;

           $$->lineno = MIN($1, $3);

           IS_SYNTAX_ERROR=1;
           LOG_ERROR(STR_RP, yylineno);
          }
          | TK_SYS_PROC{
            if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_SYS);
           $$->child = MALLOC($$,1);
           $$->child[0] = $1;

           $$->lineno = $1->lineno;
        }
          | TK_SYS_PROC TK_LP expression_list TK_RP{
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_SYS_ARGS);
           $$->child = MALLOC($$,2);
           $$->child[0] = $1;
           $$->child[1] = $3;

           $$->lineno = MIN($1, $3);
          }
          | TK_SYS_PROC TK_LP expression_list error{
           //NOTE: IGNROE TK_LP TK_RP
           if(DEBUG){
               printf("PARSING PROC STMT\n");
           }
           $$ = NEWNODE(TK_PROC_SYS_ARGS);
           $$->child = MALLOC($$,2);
           $$->child[0] = $1;
           $$->child[1] = $3;

           $$->lineno = MIN($1, $3);

           IS_SYNTAX_ERROR=1;
           LOG_ERROR(STR_RP, yylineno);
          }
          ;

compound_stmt : TK_BEGIN stmt_list TK_END{
            if(DEBUG){
                printf("PARSING CP STMT\n");
            }
            $$ = $2;
        }
        ;

if_stmt : TK_IF expression TK_THEN stmt else_clause{
            //NOTE: IGNORE TK_IF TK_THEN
            if(DEBUG){
                printf("PARSING IF STMT\n");
            }
            $$ = NEWNODE(TK_IF);
            $$->child = MALLOC($$,3);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;

            $$->lineno = MIN($2, $4);
            $$->lineno = MIN($$, $5);
        }

        ;

else_clause : TK_ELSE stmt{
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE\n");
                }
                $$ = $2;
            }
            |{
                if(DEBUG){
                    printf("PARSING ELSE CLAUSE NULL\n");
                }
                $$ = NULL;
            }
            ;

repeat_stmt : TK_REPEAT stmt_list TK_UNTIL expression{
                //NOTE: IGNORE TK_REPEAR TK_UNTIL
                if(DEBUG){
                    printf("PARSING REPEAT STMT\n");
                }
                $$ = NEWNODE(TK_REPEAT);
                $$->child = MALLOC($$,2);
                $$->child[0] = $2;
                $$->child[1] = $4;

                $$->lineno = MIN($2, $4);
            }
            |TK_REPEAT stmt_list error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_UNTIL, yylineno);} expression{
                //NOTE: IGNORE TK_REPEAR TK_UNTIL
                if(DEBUG){
                    printf("PARSING REPEAT STMT\n");
                }
                $$ = NEWNODE(TK_REPEAT);
                $$->child = MALLOC($$,2);
                $$->child[0] = $2;
                $$->child[1] = $4;

                $$->lineno = MIN($2, $4);
            }
            ;

while_stmt : TK_WHILE expression TK_DO stmt{
                //NOTE: IGNORE TK_WHILE TK_DO
                if(DEBUG){
                    printf("PARSING WHILE STMT\n");
                }
                $$ = NEWNODE(TK_WHILE);
                $$->child = MALLOC($$,2);
                $$->child[0] = $2;
                $$->child[1] = $4;

                $$->lineno = MIN($2, $4);
            }
            | TK_WHILE expression error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_DO, yylineno); } stmt{
                //NOTE: IGNORE TK_WHILE TK_DO
                if(DEBUG){
                    printf("PARSING WHILE STMT\n");
                }
                $$ = NEWNODE(TK_WHILE);
                $$->child = MALLOC($$,2);
                $$->child[0] = $2;
                $$->child[1] = $4;

                $$->lineno = MIN($2, $4);
            }
            ;

for_stmt : TK_FOR TK_ID TK_ASSIGN expression direction expression TK_DO stmt{
            //NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
            if(DEBUG){
                printf("PARSING FOR STMT\n");
            }
            $$ = NEWNODE(TK_FOR);
            $$->child = MALLOC($$,5);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            $$->child[3] = $6;
            $$->child[4] = $8;

            $$->lineno = MIN($2, $4);
            $$->lineno = MIN($$, $5);
            $$->lineno = MIN($$, $6);
            $$->lineno = MIN($$, $8);
        }
        |TK_FOR TK_ID error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_ASSIGN, $1->lineno); } expression direction expression TK_DO stmt{
            //NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
            if(DEBUG){
                printf("PARSING FOR STMT\n");
            }
            $$ = NEWNODE(TK_FOR);
            $$->child = MALLOC($$,5);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            $$->child[3] = $6;
            $$->child[4] = $8;

            $$->lineno = MIN($2, $4);
            $$->lineno = MIN($$, $5);
            $$->lineno = MIN($$, $6);
            $$->lineno = MIN($$, $8);
        }
        | TK_FOR TK_ID TK_ASSIGN expression error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_TO_OR_DOWNTO, yylineno); } expression TK_DO stmt{
            //NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
            if(DEBUG){
                printf("PARSING FOR STMT\n");
            }
            $$ = NEWNODE(TK_FOR);
            $$->child = MALLOC($$,5);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            $$->child[3] = $6;
            $$->child[4] = $8;

            $$->lineno = MIN($2, $4);
            $$->lineno = MIN($$, $5);
            $$->lineno = MIN($$, $6);
            $$->lineno = MIN($$, $8);
        }
        | TK_FOR TK_ID TK_ASSIGN expression direction expression error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_DO, yylineno); } stmt{
            //NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
            if(DEBUG){
                printf("PARSING FOR STMT\n");
            }
            $$ = NEWNODE(TK_FOR);
            $$->child = MALLOC($$,5);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            $$->child[3] = $6;
            $$->child[4] = $8;

            $$->lineno = MIN($2, $4);
            $$->lineno = MIN($$, $5);
            $$->lineno = MIN($$, $6);
            $$->lineno = MIN($$, $8);
        }
        ;

direction : TK_TO{
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR TO\n");
            }
            $$ = $1;
        }
        | TK_DOWNTO{
        //NOTE: THERE IS NO DIR
            if(DEBUG){
                printf("PARSING DIR DOWNTO\n");
            }
            $$ = $1;
        }
        ;

case_stmt : TK_CASE expression TK_OF case_expr_list TK_END{
            //NOTE: IGNORE TK_CASE TK_OF TK_END
            if(DEBUG){
                printf("PARSING CASE STMT\n");
            }
            $$ = NEWNODE(TK_CASE);
            $$->child = MALLOC($$,2);
            $$->child[0] = $2;
            $$->child[1] = $4;

            $$->lineno = MIN($2, $4);

        }
        | TK_CASE expression error { IS_SYNTAX_ERROR=1; LOG_ERROR(STR_OF, yylineno);} case_expr_list TK_END{
            //NOTE: IGNORE TK_CASE TK_OF TK_END
            if(DEBUG){
                printf("PARSING CASE STMT\n");
            }
            $$ = NEWNODE(TK_CASE);
            $$->child = MALLOC($$,2);
            $$->child[0] = $2;
            $$->child[1] = $4;

            $$->lineno = MIN($2, $4);

        }
        ;

case_expr_list : case_expr_list case_expr{
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST\n");
            }
            	$$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $2;

                free(tmp);
        }
        | case_expr{
            //NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
            if(DEBUG){
                printf("PARSING CASE EXPR LIST : FIRST ONE\n");
            }
            $$ = NEWNODE(TK_CASE_EL);
            $$->child = MALLOC($$,1);
            $$->child[0] = $1;

            $$->lineno = $1->lineno;
        }
        ;

case_expr : const_value TK_COLON stmt TK_SEMI{
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            $$ = NEWNODE(TK_CASE_EXPR);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);

        }
        |const_value TK_COLON stmt error{
            //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            $$ = NEWNODE(TK_CASE_EXPR);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_SEMI, $3->lineno);

        }
        | TK_ID TK_COLON stmt TK_SEMI{
         //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            $$ = NEWNODE(TK_CASE_EXPR_END);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);
        }
        |TK_ID TK_COLON stmt error{
         //NOTE: IGNORE TK_COLON TK_SEMI
            if(DEBUG){
                printf("PARSING CASE EXPR\n");
            }
            $$ = NEWNODE(TK_CASE_EXPR_END);
            $$->child = MALLOC($$,2);
            $$->child[0] = $1;
            $$->child[1] = $3;

            $$->lineno = MIN($1, $3);

            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_SEMI, $3->lineno);
        }
        ;

goto_stmt : TK_GOTO TK_INTEGER{
        //NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
            if(DEBUG){
                printf("PARSING GOTO STMT\n");
            }
            $$ = $2;
            $$->type = TK_GOTO;
           	setName($$, TK_GOTO);
        } 
        | TK_GOTO error{
        //NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
            if(DEBUG){
                printf("PARSING GOTO STMT\n");
            }
            $$ = NULL;

            syntax_const_error=1;
            IS_SYNTAX_ERROR = 1;
            LOG_ERROR(STR_LABEL, yylineno);
        }

        ;

expression_list : expression_list TK_COMMA expression{
                    //NOTE: IGNORE TK_COMMA
                    if(DEBUG){
                        printf("PARSING EXP LIST\n");
                    }
                    $$ = $1;
                	int old_child_number = $$->child_number;
                	NODE** tmp = $$->child;
                	$$->child = MALLOC($$, (1+old_child_number));
                	int i;
                	for(i=0;i<old_child_number;i++){
                		$$->child[i] = tmp[i];
                	}
                	$$->child[i] = $3;

                	free(tmp);
                }
                | expression{
                    if(DEBUG){
                        printf("PARSING EXP LIST : FIRST ONE\n");
                    }
                    $$ = NEWNODE(TK_EXP_LIST);
                    $$->child = MALLOC($$,1);
                    $$->child[0] = $1;

                    $$->lineno = $1->lineno;
                }
                ;

expression : expression TK_GE expr{
            //NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_GE);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
           }
           | expression TK_GT expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_GT);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
           }
           | expression TK_LE expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_LE);
                $$->child = MALLOC($$,2);
                $$->child[0] = $1;
                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
           }
           | expression TK_LT expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_LT);
                $$->child = MALLOC($$,2);
                                $$->child[0] = $1;
                                $$->child[1] = $3;

                $$->lineno = MIN($1, $3);
           }
           | expression TK_EQUAL expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_EQUAL);
                $$->child = MALLOC($$,2);
                                $$->child[0] = $1;
                                $$->child[1] = $3;
                 $$->lineno = MIN($1, $3);
           }
           | expression TK_UNEQUAL expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION\n");
                }
                $$ = NEWNODE(TK_UNEQUAL);
                $$->child = MALLOC($$,2);
                                $$->child[0] = $1;
                                $$->child[1] = $3;
                                $$->lineno = MIN($1, $3);
           }
           | expr{
                if(DEBUG){
                    printf("PARSING EXPRESSION : FIRST ONE\n");
                }
                $$ = NEWNODE(TK_EXP);
                $$->child = MALLOC($$,1);
                $$->child[0] = $1;
                $$->lineno = $1->lineno;
           }
           ;

expr : expr TK_PLUS term{
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         $$ = NEWNODE(TK_PLUS);
         $$->child = MALLOC($$,2);
                         $$->child[0] = $1;
                         $$->child[1] = $3;
                         $$->lineno = MIN($1, $3);
     }
     | expr TK_MINUS term{
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         $$ = NEWNODE(TK_MINUS);
         $$->child = MALLOC($$,2);
                         $$->child[0] = $1;
                         $$->child[1] = $3;
                         $$->lineno = MIN($1, $3);
     }
     | expr TK_OR term{
     //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         $$ = NEWNODE(TK_OR);
         $$->child = MALLOC($$,2);
                         $$->child[0] = $1;
                         $$->child[1] = $3;
                         $$->lineno = MIN($1, $3);
     }
     | term{
     //NOTE: expr IS EXPR, expression IS EXP
         if(DEBUG){
             printf("PARSING EXPR : FIRST ONE\n");
         }
         $$ = NEWNODE(TK_EXPR);
         $$->child = MALLOC($$,1);
         $$->child[0] = $1;

         $$->lineno = $1->lineno;
     }
     ;

term : term TK_MUL factor{
         if(DEBUG){
             printf("PARSING TK_MUL\n");
         }
         $$ = NEWNODE(TK_MUL);
         $$->child = MALLOC($$,2);
                                  $$->child[0] = $1;
                                  $$->child[1] = $3;
                                  $$->lineno = MIN($1, $3);
     }
     | term TK_DIV factor{
         if(DEBUG){
             printf("PARSING TK_DIV\n");
         }
         $$ = NEWNODE(TK_DIV);
        $$->child = MALLOC($$,2);
                                 $$->child[0] = $1;
                                 $$->child[1] = $3;
                                 $$->lineno = MIN($1, $3);
     }
     |term TK_REM factor{
               if(DEBUG){
                   printf("PARSING TK_REM\n");
               }
               $$ = NEWNODE(TK_REM);
              $$->child = MALLOC($$,2);
                                       $$->child[0] = $1;
                                       $$->child[1] = $3;
                                       $$->lineno = MIN($1, $3);
           }
     | term TK_MOD factor{
         if(DEBUG){
             printf("PARSING TK_MOD\n");
         }
         $$ = NEWNODE(TK_MOD);
        $$->child = MALLOC($$,2);
                                 $$->child[0] = $1;
                                 $$->child[1] = $3;
                                 $$->lineno = MIN($1, $3);
     }
     | term TK_AND factor{
         if(DEBUG){
             printf("PARSING TK_AND\n");
         }
         $$ = NEWNODE(TK_AND);
         $$->child = MALLOC($$,2);
                                  $$->child[0] = $1;
                                  $$->child[1] = $3;
                                  $$->lineno = MIN($1, $3);
     }
     | factor{
         if(DEBUG){
             printf("PARSING TERM : FIRST ONE\n");
         }
         $$ = NEWNODE(TK_TERM);
         $$->child = MALLOC($$,1);
         $$->child[0] = $1;

         $$->lineno = $1->lineno;
     }

     ;

factor : TK_ID{
    //NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
        if(DEBUG){
            printf("PARSING FACTOR\n");
        }
        $$ = NEWNODE(TK_FACTOR_ID);
        $$->child = MALLOC($$,1);
        $$->child[0] = $1;

        $$->lineno = $1->lineno;
    }
    | TK_ID TK_LP args_list TK_RP{
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_ID_ARGS);
        $$->child = MALLOC($$,2);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = MIN($1, $3);
    }
    | TK_SYS_FUNCT TK_LP args_list TK_RP{
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_SYS_FUNCT);
        $$->child = MALLOC($$,2);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = MIN($1, $3);
    }
    | const_value{
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_CONST);
        $$->child = MALLOC($$,1);
        $$->child[0] = $1;
        $$->lineno = $1->lineno;
    }
    | TK_LP expression TK_RP{
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_EXP);
        $$->child = MALLOC($$,1);
        $$->child[0] = $2;
        $$->lineno = $2->lineno;
    }
    | TK_LP expression error{
    //NOTE: IGNORE TK_LP TK_RP
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_EXP);
        $$->child = MALLOC($$,1);
        $$->child[0] = $2;
        $$->lineno = $2->lineno;

        IS_SYNTAX_ERROR = 1;
        LOG_ERROR(STR_RP, yylineno);
    }
    | TK_NOT factor{
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_NOT);
        $$->child = MALLOC($$,1);
        $$->child[0] = $2;
        $$->lineno = $2->lineno;
    }
    | TK_MINUS factor{
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_MINUS);
        $$->child = MALLOC($$,1);
        $$->child[0] = $2;
        $$->lineno = $2->lineno;
    }
    | TK_ID TK_LB expr TK_RB{
    //NOTE: IGNORE TK_LB TK_RB
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_ID_EXP);
        $$->child = MALLOC($$,2);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = MIN($1,$3);
    }
    | TK_ID TK_LB expr error{
    //NOTE: IGNORE TK_LB TK_RB
        if(DEBUG){
            printf("PARSING FACTOR \n");
        }
        $$ = NEWNODE(TK_FACTOR_ID_EXP);
        $$->child = MALLOC($$,2);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = MIN($1,$3);

        IS_SYNTAX_ERROR = 1;
        LOG_ERROR(STR_RB ,yylineno);
    }
    | TK_ID TK_DOT TK_ID{
    //NOTE: ID->ID IS IN ONE NODE
        if(DEBUG){
            printf("PARSING FACTOR FOR ID->ID\n");
        }
        $$ = NEWNODE(TK_FACTOR_DD);
        $$->child = MALLOC($$,2);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = $1->lineno;
        $1->record = $3;
    }
    ;

args_list : args_list TK_COMMA expression{
            //NOTE: IGNORE TK_COMMA
            if(DEBUG){
                printf("PARSING ARGS LIST\n");
            }
            	$$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                	$$->child[i] = tmp[i];
                }
                $$->child[i] = $3;

                free(tmp);
        }
        | args_list error {IS_SYNTAX_ERROR=1; LOG_ERROR(STR_COMMA, yylineno);} expression{
            //NOTE: IGNORE TK_COMMA
            if(DEBUG){
                printf("PARSING ARGS LIST\n");
            }
                $$ = $1;
                int old_child_number = $$->child_number;
                NODE** tmp = $$->child;
                $$->child = MALLOC($$, (1+old_child_number));
                int i;
                for(i=0;i<old_child_number;i++){
                    $$->child[i] = tmp[i];
                }
                $$->child[i] = $3;

                free(tmp);
        }
        | expression{
            if(DEBUG){
                printf("PARSING ARGS LIST : FIRST ONE\n");
            }
            $$ = NEWNODE(TK_ARGS_LIST);
            $$->child = MALLOC($$,1);
            $$->child[0] = $1;
            $$->lineno = $1->lineno;
        }
        ;

%%

int yyerror(string s){
    //extern char* yytext;
   // printf("\n");
    //printf( "%s\n", s);
    //fprintf(stderr, "line %d: ", yylineno);
    //fprintf(stderr, "\"%s\"\n", yytext);
    return 1;
}

void LOG_ERROR(string expected, int line){
    printf("line %d: error: missing %s\n", line, expected.c_str());
}