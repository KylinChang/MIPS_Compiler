%code requires{
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
}

%{
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
%}

%token 	TK_AND TK_ARRAY TK_ASSIGN TK_CASE TK_TYPE TK_SYS_TYPE 
%token 	TK_COLON TK_COMMA TK_CONST TK_DIGITS TK_DIV TK_DO TK_DOT TK_DOTDOT
%token 	TK_DOWNTO TK_ELSE TK_END TK_EQUAL TK_FOR
%token 	TK_FUNCTION TK_GE TK_GOTO TK_GT TK_ID TK_IF TK_IN TK_LB
%token 	TK_LE TK_LP TK_LT TK_MINUS TK_MOD TK_UNEQUAL TK_OF TK_OR
%token 	TK_OTHERWISE TK_BEGIN TK_PLUS TK_PROCEDURE
%token 	TK_PROGRAM TK_RB TK_REAL TK_RECORD TK_REPEAT TK_RP TK_SYS_PROC TK_READ
%token 	TK_SEMI TK_MUL TK_THEN TK_NOT
%token 	TK_TO TK_UNTIL TK_UPARROW TK_VAR TK_WHILE TK_SET TK_STARSTAR
%token 	TK_CHAR TK_STRING TK_INTEGER TK_SYS_CON TK_SYS_FUNCT TK_WITH TK_NIL
%token 	ERROR 

%token 	TK_PROGRAM_HEAD TK_ROUTINE TK_ROUTINE_HEAD TK_ROUTINE_BODY TK_CONST_PART
		TK_TYPE_PART TK_VAR_PART TK_ROUTINE_PART TK_STMT_LIST TK_STMT TK_CP_STMT

%token 	TK_VAL_PARA_LIST TK_NON_LABEL_STMT TK_EXP_LIST TK_EXP TK_TERM 
		TK_FACTOR_ID TK_FACTOR_ID_ARGS TK_FACTOR_SYS_FUNCT TK_FACTOR_CONST TK_FACTOR_EXP TK_FACTOR_NOT
		TK_FACTOR_MINUS TK_FACTOR_ID_EXP TK_FACTOR_DD TK_ARGS_LIST
		TK_CONST_EL TK_TYPE_DL TK_TYPE_DEF TK_TYPE_DECL TK_FIELD_DL TK_FIELD_DECL TK_NL
		TK_STD_SYS_TYPE TK_STD_ID TK_STD_NL TK_STD_DD TK_DL TK_VAR_DECL TK_FUNC_DECL TK_FUNC_HEAD 
		TK_PROC_DECL TK_PROC_HEAD TK_PARA TK_PARA_DL TK_PARA_TL TK_PROC
		TK_CASE_EL TK_CASE_EXPR TK_EXPR

%%
program : program_head routine TK_DOT{
			if(DEBUG){
				printf("PARSING PROGRAM\n");
			}
			$$ = NEWNODE;
			$$->type = TK_PROGRAM;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $2;

			ROOT = $$;
		}
		;

program_head : TK_PROGRAM TK_ID TK_SEMI{
		//NOTE: PROGRAM HEAD ACTUALLY IS TK_ID
			if(DEBUG){
				printf("PROGRAM HEAD:%s\n", $2->name);
			}
			$$ = NEWNODE;
			$$ = $2;
			$$->type = TK_PROGRAM_HEAD;
			cpString(&($$->name), &($2->name));
			$$->child_number = 0;
			$$->child = NULL;
		}
		;

routine : routine_head routine_body{
			if(DEBUG){
				printf("PARSING ROUTINE\n");
			}
			$$ = NEWNODE;
			$$->type = TK_ROUTINE;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $2;
		}
		;

routine_head : const_part type_part var_part routine_part{
			if(DEBUG){
				printf("PARSING ROUTINE HEAD\n");
			}
			$$ = NEWNODE;
			$$->type = TK_ROUTINE_HEAD;
			$$->child_number = 4;
			$$->child = MALLOC(4);
			$$->child[0] = $1;
			$$->child[1] = $2;
			$$->child[2] = $3;
			$$->child[3] = $4;
		}
		;

const_part : TK_CONST const_expr_list{
		//NOTE: IGNORE TK_CONST
			if(DEBUG){
				printf("PARSING CONST PART\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CONST_PART;
			$$->child_number = 0;
			$$->child = MALLOC(1);
			$$->child[0] = $1;
		}
		|{
			if(DEBUG){
				printf("PARSING CONST PART NULL\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CONST_PART;
			$$->child_number = 0;
			$$->child = NULL;
		}
		;

const_expr_list : const_expr_list TK_ID TK_EQUAL const_value TK_SEMI{
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST\n");
					}
					$$ = NEWNODE;
					$$->type = TK_CONST_EL;
					$$->child_number = 3;
					$$->child = MALLOC(3);
					$$->child[0] = $1;
					$$->child[1] = $2;
					$$->child[2] = $4;	
				}
				| TK_ID TK_EQUAL const_value TK_SEMI{
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST : FIRST ONE\n");
					}
					$$ = NEWNODE;
					$$->type = TK_CONST_EL;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				;

const_value : TK_INTEGER{
				if(DEBUG){
					printf("PARSING COSNT VALUE INTEGER\n");
				}
				$$ = NEWNODE;
				$$ = $1;
				$$->type = TK_INTEGER;
				$$->child_number = 0;
				$$->child = NULL;
			}
			| TK_REAL{
				if(DEBUG){
					printf("PARSING COSNT VALUE REAL\n");
				}
				$$ = NEWNODE;
				$$ = $1;
				$$->type = TK_REAL;
				$$->child_number = 0;
				$$->child = NULL;
			}
			| TK_CHAR{
				if(DEBUG){
					printf("PARSING COSNT VALUE CHAR\n");
				}
				$$ = NEWNODE;
				$$ = $1;
				$$->type = TK_CHAR;
				$$->child_number = 0;
				$$->child = NULL;
			}
			| TK_STRING{
				if(DEBUG){
					printf("PARSING COSNT VALUE STRING\n");
				}
				$$ = NEWNODE;
				$$ = $1;
				$$->type = TK_STRING;
				$$->child_number = 0;
				$$->child = NULL;
			}
			| TK_SYS_CON{
				if(DEBUG){
					printf("PARSING COSNT VALUE SYS CON\n");
				}
				$$ = NEWNODE;
				$$ = $1;
				$$->type = TK_SYS_CON;
				$$->child_number = 0;
				$$->child = NULL;
			}
			;

type_part : TK_TYPE type_decl_list{
			//NOTE: IGNORE TYPE
			if(DEBUG){
				printf("PARSING TYPE PART NULL\n");
			}
			$$ = NEWNODE;
			$$->type = TK_TYPE_PART;
			$$->child_number = 1;
			$$->child = MALLOC(1);
			$$->child[0] = $2;
		}
		|{
		  	//NOTE: IGNORE TYPE
		  		if(DEBUG){
		  			printf("PARSING TYPE PART NULL\n");
		  		}
		  		$$ = NEWNODE;
		  		$$->type = TK_TYPE_PART;
				$$->child_number = 0;
				$$->child = NULL;
		}
		;

type_decl_list : type_decl_list type_definition{
					if(DEBUG){
						printf("PARSING TYPE DECL LIST DEF\n");
					}
					$$ = NEWNODE;
					$$->type = TK_TYPE_DL;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $2;
				}
			   | type_definition{
			   		if(DEBUG){
						printf("PARSING TYPE DECL LIST\n");
					}
					$$ = NEWNODE;
					$$->type = TK_TYPE_DL;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
			   }
			   ;

type_definition : TK_ID TK_EQUAL type_decl TK_SEMI{
					if(DEBUG){
						printf("PARSING TYPE DEF\n");
					}
					$$ = NEWNODE;
					$$->type = TK_TYPE_DEF;
					$$->child_number = 1;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				;

type_decl : simple_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_TYPE_DECL;
				$$->child_number =  1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
		  }
		  | array_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_TYPE_DECL;
				$$->child_number =  1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
		  }
		  | record_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_TYPE_DECL;
				$$->child_number =  1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
		  }
		  ;

array_type_decl : TK_ARRAY TK_LB simple_type_decl TK_RB TK_OF type_decl{
				//NOTE: IGNORE TK_LB TK_RB TK_OF
				if(DEBUG){
					printf("PARSING ARRAY\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ARRAY;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $3;
				$$->child[1] = $6;
			}
			;

record_type_decl : TK_RECORD field_decl_list TK_END{
				//NOTE: IGNORE TK_END
				if(DEBUG){
					printf("PARSING RECORD TYPE DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_RECORD;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $2;
			}
			;

field_decl_list : field_decl_list field_decl{
				if(DEBUG){
					printf("PARSING FIELD DECL LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_FIELD_DL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $2;
			}
			| field_decl{
				if(DEBUG){
					printf("PARSING FIELD DECL LIST : FIRST ONE\n");
				}
				$$ = NEWNODE;
				$$->type = TK_FIELD_DL;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
			}
			;

field_decl : name_list TK_COLON type_decl TK_SEMI{
			//NOTE: IGNORE TK_COLON TK_SEMI
				if(DEBUG){
					printf("PARSING FIELD DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_FIELD_DECL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
		   	;

name_list : name_list TK_COMMA TK_ID{
			//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
				if(DEBUG){
					printf("PARSING NAME LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_NL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
		  	| TK_ID{
		  		if(DEBUG){
		  			printf("PARSING NAME LIST : FIRST ONE\n");
		  		}
		  		$$ = NEWNODE;
		  		$$->type = TK_NL;
		  		$$->child_number = 1;
		  		$$->child = MALLOC(1);
		  		$$->child[0] = $1;
		  	}
		  	;

simple_type_decl : TK_SYS_TYPE{
				//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_SYS_TYPE;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
				 | TK_ID{
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_ID;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
				 | TK_LP name_list TK_RP{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_NL;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $2;
				}
				 | const_value TK_DOTDOT const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_DD;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				 | TK_MINUS const_value TK_DOTDOT const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_DD;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				 | TK_MINUS const_value TK_DOTDOT TK_MINUS const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_DD;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				 | TK_ID TK_DOTDOT TK_ID{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$ = NEWNODE;
					$$->type = TK_STD_DD;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				 ;

var_part : TK_VAR var_decl_list{
		//NOTE: IGNORE TK_VAR
			if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	$$ = NEWNODE;
		  	$$->type = TK_VAR_PART;
			$$->child_number = 1;
			$$->child = MALLOC(1);
			$$->child[0] = $2;
		}
		|{
		  	if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	$$ = NEWNODE;
		  	$$->type = TK_VAR_PART;
			$$->child_number = 0;
			$$->child = NULL;
		}
		;

var_decl_list : var_decl_list var_decl{
				if(DEBUG){
					printf("PARSING VAR DECL LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_DL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $2;
			}
			| var_decl{
				if(DEBUG){
					printf("PARSING VAR DECL LIST : FIRST ONE\n");
				}
				$$ = NEWNODE;
				$$->type = TK_DL;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
			}
			;

var_decl : name_list TK_COLON type_decl TK_SEMI{
			//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING VAR DECL\n");
			}
			$$ = NEWNODE;
			$$->type = TK_VAR_DECL;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $3;
		}
		;

routine_part : routine_part function_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ROUTINE_PART;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $2;
			}
			 | routine_part procedure_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ROUTINE_PART;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $2;
			}
			 | function_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ROUTINE_PART;
				$$->child_number = 1;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
			}
			 | procedure_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ROUTINE_PART;
				$$->child_number = 1;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
			}
			 |{
			 	if(DEBUG){
			 		printf("PARSING ROUTINE_PART NULL\n");
			 	}
			 	$$ = NEWNODE;
			 	$$->type = TK_ROUTINE_PART;
			 	$$->child_number = 0;
			 	$$->child = NULL;
			 }
			 ;

function_decl : function_head TK_SEMI routine TK_SEMI{
				//NOTE: IGNORE TK_SEMI
				if(DEBUG){
					printf("PARSING FUNC DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_FUNC_DECL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
			;

function_head : TK_FUNCTION TK_ID parameters TK_COLON simple_type_decl{
				//NOTE: IGNORE TK_FUNCTION TK_COLON
				if(DEBUG){
					printf("PARSING TK_FUNCTINO HEAD\n");
				}
				$$ = NEWNODE;
				$$->type = TK_FUNC_HEAD;
				$$->child_number = 3;
				$$->child = MALLOC(3);
				$$->child[0] = $2;
				$$->child[1] = $3;
				$$->child[2] = $5;
			}
			;

procedure_decl : procedure_head TK_SEMI routine TK_SEMI{
				//NOTE: IGNORE TK_SEMI PROCEDURE_DECL IS 'TK_PROC_DECL'
				if(DEBUG){
					printf("PARSING PROC DECL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_PROC_DECL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
			;

procedure_head : TK_PROCEDURE TK_ID parameters{
				//NOTE: IGNORE TK_PROCEDURE  PROCEDURE_HEAD IS 'TK_PROC_HEAD'
				if(DEBUG){
					printf("PARSING PROC HEAD\n");
				}
				$$ = NEWNODE;
				$$->type = TK_PROC_HEAD;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $2;
				$$->child[1] = $3;
			}
			;

parameters : TK_LP para_decl_list TK_RP{
			//NOTE: PARAMETERS IS 'TK_PARA', IGNORE TK_LP TK_RP
				if(DEBUG){
					printf("PARSING PARA\n");
				}
				$$ = NEWNODE;
				$$->type = TK_PARA;
		   		$$->child_number = 1;
		   		$$->child = MALLOC(1);
		   		$$->child[0] = $2;
			}
		   	|{
		   	//NOTE: PARAMETERS IS 'TK_PARA'
		   		if(DEBUG){
		   			printf("PARSING PARA NULL\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_PARA;
		   		$$->child_number = 0;
		   		$$->child = NULL;
		   	}
		   	;

para_decl_list : para_decl_list TK_SEMI para_type_list{
				//NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
				if(DEBUG){
					printf("PARSING PARA DECL LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_PARA_DL;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
			| para_type_list{
				//NOTE: IGNORE TK_SEMI PARA_DECL_LIST IS 'PARA_DL'
				if(DEBUG){
					printf("PARSING PARA DECL LIST : FIRST ONE\n");
				}
				$$ = NEWNODE;
				$$->type = TK_PARA_DL;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
			}
			;

para_type_list : var_para_list TK_COLON simple_type_decl{
					//NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
					if(DEBUG){
						printf("PARSING TK_COLON\n");
					}
					$$ = NEWNODE;
					$$->type = TK_PARA_TL;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
			   | val_para_list TK_COLON simple_type_decl{
					//NOTE: IGNORE TK_COLON PARA_TYPE_LIST IS 'PARA_TL'
					if(DEBUG){
						printf("PARSING TK_COLON\n");
					}
					$$ = NEWNODE;
					$$->type = TK_PARA_TL;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
			   ;

var_para_list : TK_VAR name_list{
				//NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
				if(DEBUG){
					printf("PARSING VAR LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_VAR;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $2;
			}
			;

val_para_list : name_list{
				if(DEBUG){
					printf("PARSING VAL PARA LIST\n");
				}
				$$ = NEWNODE;
				$$->type = TK_VAL_PARA_LIST;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
			}
			;

routine_body : compound_stmt{
				if(DEBUG){
					printf("PARSING ROUTINE BODY\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ROUTINE_PART;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $1;
			}
			;

stmt_list : stmt_list stmt TK_SEMI{
			if(DEBUG){
				printf("PARSING STMT LIST\n");
			}
			$$ = NEWNODE;
			$$->type = TK_STMT_LIST;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $2;
		}
		|{
		  	if(DEBUG){
		  		printf("PARSING STMT LIST NULL\n");
		  	}
		  	$$ = NEWNODE;
		  	$$->type = TK_STMT_LIST;
		  	$$->child_number = 0;
		  	$$->child = NULL;
		}
		;

stmt : TK_INTEGER TK_COLON non_label_stmt{
		//NOTE: IGNORE TK_COLON
		if(DEBUG){
			printf("PARSING STMT\n");
		}
		$$ = NEWNODE;
		$$->type = TK_STMT;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	}	
	 | non_label_stmt{
	 	//NOTE: IGNORE TK_COLON
	 	if(DEBUG){
	 		printf("PARSING NON LABEL STMT\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_STMT;
	 	$$->child_number = 1;
	 	$$->child = MALLOC(1);
	 	$$->child[0] = $1;
	 }
	 ;

non_label_stmt : assign_stmt{
					if(DEBUG){
						printf("PARSING ASSIGN STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | proc_stmt{
					if(DEBUG){
						printf("PARSING PROC STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | compound_stmt{
					if(DEBUG){
						printf("PARSING CP STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | if_stmt{
					if(DEBUG){
						printf("PARSING IF STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | repeat_stmt{
					if(DEBUG){
						printf("PARSING REPEAT STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | while_stmt{
					if(DEBUG){
						printf("PARSING WHILE STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | for_stmt{
					if(DEBUG){
						printf("PARSING FOR STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | case_stmt{
					if(DEBUG){
						printf("PARSING CASE STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   | goto_stmt{
					if(DEBUG){
						printf("PARSING GOTO STMT\n");
					}
					$$ = NEWNODE;
					$$->type = TK_NON_LABEL_STMT;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
			   ;

assign_stmt : TK_ID TK_ASSIGN expression{
				//NOTE: IGNORE TK_ASSIGN
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ASSIGN;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $2;
				$$->child[1] = $3;
			}
			| TK_ID TK_LB expression TK_RB TK_ASSIGN expression{
				//NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ASSIGN;
				$$->child_number = 3;
				$$->child = MALLOC(3);
				$$->child[0] = $1;
				$$->child[1] = $3;
				$$->child[2] = $6;
			}
			| TK_ID TK_DOT TK_ID TK_ASSIGN expression{
				//NOTE: IGNORE TK_ASSIGN TK_LB TK_RB
				if(DEBUG){
					printf("PARSING ASSIGN\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ASSIGN;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $1;
				$$->child[1] = $5;

				$1->attr = $3;
			}
			;

proc_stmt : TK_ID{
			if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	$$ = NEWNODE;
          	$$->type = TK_PROC;
          	$$->child_number = 1;
          	$$->child = MALLOC(1);
          	$$->child[0] = $1;
		}
          | TK_ID TK_LP args_list TK_RP{
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	$$ = NEWNODE;
          	$$->type = TK_PROC;
          	$$->child_number = 2;
          	$$->child = MALLOC(2);
          	$$->child[0] = $1;
          	$$->child[1] = $3;
          }
          | TK_SYS_PROC{
			if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	$$ = NEWNODE;
          	$$->type = TK_PROC;
          	$$->child_number = 1;
          	$$->child = MALLOC(1);
          	$$->child[0] = $1;
		}
          | TK_SYS_PROC TK_LP expression_list TK_RP{
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	$$ = NEWNODE;
          	$$->type = TK_PROC;
          	$$->child_number = 2;
          	$$->child = MALLOC(2);
          	$$->child[0] = $1;
          	$$->child[1] = $3;
          }
          | TK_READ TK_LP factor TK_RP{
          	//NOTE: IGNROE TK_LP TK_RP
          	if(DEBUG){
          		printf("PARSING PROC STMT\n");
          	}
          	$$ = NEWNODE;
          	$$->type = TK_PROC;
          	$$->child_number = 2;
          	$$->child = MALLOC(2);
          	$$->child[0] = $1;
          	$$->child[1] = $3;
          }
		  ;

compound_stmt : TK_BEGIN stmt_list TK_END{
			if(DEBUG){
				printf("PARSING CP STMT\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CP_STMT;
			$$->child_number = 1;
			$$->child = MALLOC(1);
			$$->child[0] = $2;
		}
		;

if_stmt : TK_IF expression TK_THEN stmt else_clause{
			//NOTE: IGNORE TK_IF TK_THEN
			if(DEBUG){
				printf("PARSING IF STMT\n");
			}
			$$ = NEWNODE;
			$$->type = TK_IF;
			$$->child_number = 3;
			$$->child = MALLOC(3);
			$$->child[0] = $2;
			$$->child[1] = $4;
			$$->child[2] = $5;
		}
		;

else_clause : TK_ELSE stmt{
				if(DEBUG){
					printf("PARSING ELSE CLAUSE\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ELSE;
				$$->child_number = 1;
				$$->child = MALLOC(1);
				$$->child[0] = $2;
			}
			|{
				if(DEBUG){
					printf("PARSING ELSE CLAUSE NULL\n");
				}
				$$ = NEWNODE;
				$$->type = TK_ELSE;
				$$->child_number = 0;
				$$->child = NULL;
			}
			;

repeat_stmt : TK_REPEAT stmt_list TK_UNTIL expression{
				//NOTE: IGNORE TK_REPEAR TK_UNTIL
				if(DEBUG){
					printf("PARSING REPEAT STMT\n");
				}
				$$ = NEWNODE;
				$$->type = TK_REPEAT;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $2;
				$$->child[1] = $4;
			}
		   	;

while_stmt : TK_WHILE expression TK_DO stmt{
				//NOTE: IGNORE TK_WHILE TK_DO
				if(DEBUG){
					printf("PARSING WHILE STMT\n");
				}
				$$ = NEWNODE;
				$$->type = TK_WHILE;
				$$->child_number = 2;
				$$->child = MALLOC(2);
				$$->child[0] = $2;
				$$->child[1] = $4;
			}
		   	;

for_stmt : TK_FOR TK_ID TK_ASSIGN expression direction expression TK_DO stmt{
			//NOTE: IGNORE TK_FOR TK_ASSIGN TK_DO
			if(DEBUG){
				printf("PARSING FOR STMT\n");
			}
			$$ = NEWNODE;
			$$->type = TK_FOR;
			$$->child_number = 5;
			$$->child = MALLOC(5);
			$$->child[0] = $2;
			$$->child[1] = $4;
			$$->child[2] = $5;
			$$->child[3] = $6;
			$$->child[4] = $8;
		}
		;

direction : TK_TO{
		//NOTE: THERE IS NO DIR
			if(DEBUG){
				printf("PARSING DIR TO\n");
			}
			$$ = NEWNODE;
			*$$ = *$1;
		}
		| TK_DOWNTO{
		//NOTE: THERE IS NO DIR
			if(DEBUG){
				printf("PARSING DIR DOWNTO\n");
			}
			$$ = NEWNODE;
			*$$ = *$1;
		}
		;

case_stmt : TK_CASE expression TK_OF case_expr_list TK_END{
			//NOTE: IGNORE TK_CASE TK_OF TK_END
			if(DEBUG){
				printf("PARSING CASE STMT\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CASE;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $2;
			$$->child[1] = $4;
		}
		;

case_expr_list : case_expr_list case_expr{
			//NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
			if(DEBUG){
				printf("PARSING CASE EXPR LIST\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CASE_EL;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $2;
		}
		| case_expr{
			//NOTE: CASE_EXPR_LIST IS 'TK_CASE_EL'
			if(DEBUG){
				printf("PARSING CASE EXPR LIST : FIRST ONE\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CASE_EL;
			$$->child_number = 1;
			$$->child = MALLOC(1);
			$$->child[0] = $1;
		}
		;

case_expr : const_value TK_COLON stmt TK_SEMI{
			//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING CASE EXPR\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CASE_EXPR;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $3;
		}
        | TK_ID TK_COLON stmt TK_SEMI{
        	//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING CASE EXPR\n");
			}
			$$ = NEWNODE;
			$$->type = TK_CASE_EXPR;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $3;
        }
		;

goto_stmt : TK_GOTO TK_INTEGER{
		//NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
			if(DEBUG){
				printf("PARSING GOTO STMT\n");
			}
			$$ = NEWNODE;
			$$ = $2;
			$$->type = TK_GOTO;
		}
		;

expression_list : expression_list TK_COMMA expression{
					//NOTE: IGNORE TK_COMMA
					if(DEBUG){
						printf("PARSING EXP LIST\n");
					}
					$$ = NEWNODE;
					$$->type = TK_EXP_LIST;
					$$->child_number = 2;
					$$->child = MALLOC(2);
					$$->child[0] = $1;
					$$->child[1] = $3;
				}
				| expression{
					if(DEBUG){
						printf("PARSING EXP LIST : FIRST ONE\n");
					}
					$$ = NEWNODE;
					$$->type = TK_EXP_LIST;
					$$->child_number = 1;
					$$->child = MALLOC(1);
					$$->child[0] = $1;
				}
				;

expression : expression TK_GE expr{
			//NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_GE;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expression TK_GT expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_GT;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expression TK_LE expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_LE;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expression TK_LT expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_LT;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expression TK_EQUAL expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_EQUAL;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expression TK_UNEQUAL expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_UNEQUAL;
		   		$$->child_number = 2;
		   		$$->child = MALLOC(2);
		   		$$->child[0] = $1;
		   		$$->child[1] = $3;
		   }
		   | expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION : FIRST ONE\n");
		   		}
		   		$$ = NEWNODE;
		   		$$->type = TK_EXP;
		   		$$->child_number = 1;
		   		$$->child = MALLOC(1);
		   		$$->child[0] = $1;
		   }
		   ;

expr : expr TK_PLUS term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_PLUS;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | expr TK_MINUS term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_MINUS;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | expr TK_OR term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_OR;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | term{
	 //NOTE: expr IS EXPR, expression IS EXP
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_EXPR;
	 	$$->child_number = 1;
	 	$$->child = MALLOC(1);
	 	$$->child[0] = $1;
	 }
	 ;

term : term TK_MUL factor{
	 	if(DEBUG){
	 		printf("PARSING TK_MUL\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_MUL;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | term TK_DIV factor{
	 	if(DEBUG){
	 		printf("PARSING TK_DIV\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_DIV;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | term TK_MOD factor{
	 	if(DEBUG){
	 		printf("PARSING TK_MOD\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_MOD;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | term TK_AND factor{
	 	if(DEBUG){
	 		printf("PARSING TK_AND\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_AND;
	 	$$->child_number = 2;
	 	$$->child = MALLOC(2);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
	 }
	 | factor{
	 	if(DEBUG){
	 		printf("PARSING TERM : FIRST ONE\n");
	 	}
	 	$$ = NEWNODE;
	 	$$->type = TK_TERM;
	 	$$->child_number = 1;
	 	$$->child = MALLOC(1);
	 	$$->child[0] = $1;
	 }
	 ;

factor : TK_ID{
	//NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
		if(DEBUG){
			printf("PARSING FACTOR\n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_ID;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $1;
	}
	| TK_ID TK_LP args_list TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_ID_ARGS;
		$$->child_number = 2;
		$$->child = MALLOC(2);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	| TK_SYS_FUNCT TK_LP args_list TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_SYS_FUNCT;
		$$->child_number = 2;
		$$->child = MALLOC(2);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	| const_value{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_CONST;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $1;
	}
	| TK_LP expression TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_EXP;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $2;
	}
	| TK_NOT factor{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_NOT;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $2;
	}
	| TK_MINUS factor{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_MINUS;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $2;
	}
	| TK_ID TK_LB expression TK_RB{
	//NOTE: IGNORE TK_LB TK_RB
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_ID_EXP;
		$$->child_number = 2;
		$$->child = MALLOC(2);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	| TK_ID TK_DOT TK_ID{
	//NOTE: ID->ID IS IN ONE NODE
		if(DEBUG){
			printf("PARSING FACTOR FOR ID->ID\n");
		}
		$$ = NEWNODE;
		$$->type = TK_FACTOR_DD;
		$$->child_number = 1;
		$$->child = MALLOC(1);
		$$->child[0] = $1;
		$1->attr = $2;
	}
	;

args_list : args_list TK_COMMA expression{
			//NOTE: IGNORE TK_COMMA
			if(DEBUG){
				printf("PARSING ARGS LIST\n");
			}
			$$ = NEWNODE;
			$$->type = TK_ARGS_LIST;
			$$->child_number = 2;
			$$->child = MALLOC(2);
			$$->child[0] = $1;
			$$->child[1] = $2;
		}
		| expression{
			if(DEBUG){
				printf("PARSING ARGS LIST : FIRST ONE\n");
			}
			$$ = NEWNODE;
			$$->type = TK_ARGS_LIST;
			$$->child_number = 1;
			$$->child = MALLOC(1);
			$$->child[0] = $1;
		}
		;

%%

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

