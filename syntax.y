%code requires{
typedef struct NODE{
    char name[256];
    char ch;
    char* str;
    int type;
    int ival;
    double dval;
    int child_number;
    struct NODE** child;

    struct NODE** attr;
}NODE;

#define YYSTYPE struct NODE
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preorder(NODE* root);

extern char* yytext;
extern int yylineno;
extern FILE* yyin;
struct NODE* ROOT;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)
#define MALLOC(num) (NODE**)malloc(NODE_POINTER_SIZE*num)

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


%%
program : program_head routine TK_DOT{
			if(DEBUG){
				printf("PARSING PROGRAM\n");
			}
			$$.type = TK_PROGRAM;
			$$.child_number = 2;
			$$.child = MALLOC(2);
			$$.child[0] = &$1;
			$$.child[1] = &$2;

			ROOT = &$$;
		}
		;

program_head : TK_PROGRAM TK_ID TK_SEMI{
			if(DEBUG){
				printf("PROGRAM HEAD:%s\n", $2.name);
			}
			$$ = $2;
			$$.type = TK_PROGRAM_HEAD;
			//strcpy($$.name, $2.name);
			$$.child_number = 0;
			$$.child = NULL;
		}
		;

routine : routine_head routine_body{
			if(DEBUG){
				printf("PARSING ROUTINE\n");
			}
			$$.type = TK_ROUTINE;
			$$.child_number = 2;
			$$.child = MALLOC(2);
			$$.child[0] = &$1;
			$$.child[1] = &$2;
		}
		;

routine_head : const_part type_part var_part routine_part{
			if(DEBUG){
				printf("PARSING ROUTINE HEAD\n");
			}
			$$.type = TK_ROUTINE_HEAD;
			$$.child_number = 4;
			$$.child = MALLOC(4);
			$$.child[0] = &$1;
			$$.child[1] = &$2;
			$$.child[2] = &$3;
			$$.child[3] = &$4;
		}
		;

const_part : TK_CONST const_expr_list{
		//NOTE: IGNORE TK_CONST
			if(DEBUG){
				printf("PARSING CONST PART\n");
			}
			$$.type = TK_CONST_PART;
			$$.child_number = 0;
			$$.child = MALLOC(1);
			$$.child[0] = &$1;
		}
		|{
			if(DEBUG){
				printf("PARSING CONST PART NULL\n");
			}
			$$.type = TK_CONST_PART;
			$$.child_number = 0;
			$$.child = NULL;
		}
		;

const_expr_list : const_expr_list TK_ID TK_EQUAL const_value TK_SEMI{
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST\n");
					}
					$$.type = TK_CONST_EXPR_LIST;
					$$.child_number = 3;
					$$.child = MALLOC(3);
					$$.child[0] = &$1;
					$$.child[1] = &$2;
					$$.child[2] = &$4;	
				}
				| TK_ID TK_EQUAL const_value TK_SEMI{
				//NOTE: IGNORE TK_EQUAL TK_SEMI
					if(DEBUG){
						printf("PARSING CONST EXPR LIST : FIRST ONE\n");
					}
					$$.type = TK_CONST_EXPR_LIST;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				;

const_value : TK_INTEGER{
				if(DEBUG){
					printf("PARSING COSNT VALUE INTEGER\n");
				}
				$$ = $1;
				$$.type = TK_INTEGER;
				$$.child_number = 0;
				$$.child = NULL;
			}
			| TK_REAL{
				if(DEBUG){
					printf("PARSING COSNT VALUE REAL\n");
				}
				$$ = $1;
				$$.type = TK_REAL;
				$$.child_number = 0;
				$$.child = NULL;
			}
			| TK_CHAR{
				if(DEBUG){
					printf("PARSING COSNT VALUE CHAR\n");
				}
				$$ = $1;
				$$.type = TK_CHAR;
				$$.child_number = 0;
				$$.child = NULL;
			}
			| TK_STRING{
				if(DEBUG){
					printf("PARSING COSNT VALUE STRING\n");
				}
				$$ = $1;
				$$.type = TK_STRING;
				$$.child_number = 0;
				$$.child = NULL;
			}
			| TK_SYS_CON{
				if(DEBUG){
					printf("PARSING COSNT VALUE SYS CON\n");
				}
				$$ = $1;
				$$.type = TK_SYS_CON;
				$$.child_number = 0;
				$$.child = NULL;
			}
			;

type_part : TK_TYPE type_decl_list{
			//NOTE: IGNORE TYPE
			if(DEBUG){
				printf("PARSING TYPE PART NULL\n");
			}
			$$.type = TK_TYPE_PART;
			$$.child_number = 1;
			$$.child = MALLOC(1);
			$$.child[0] = &$2;
		}
		|{
		  	//NOTE: IGNORE TYPE
		  		if(DEBUG){
		  			printf("PARSING TYPE PART NULL\n");
		  		}
		  		$$.type = TK_TYPE_PART;
				$$.child_number = 0;
				$$.child = NULL;
		}
		;

type_decl_list : type_decl_list type_definition{
					if(DEBUG){
						printf("PARSING TYPE DECL LIST DEF\n");
					}
					$$.type = TK_TYPE_DECL_LIST;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$2;
				}
			   | type_definition{
			   		if(DEBUG){
						printf("PARSING TYPE DECL LIST\n");
					}
					$$.type = TK_TYPE_DECL_LIST;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
			   }
			   ;

type_definition : TK_ID TK_EQUAL type_decl TK_SEMI{
					if(DEBUG){
						printf("PARSING TYPE DEF\n");
					}
					$$.type = TK_TYPE_DEF;
					$$.child_number = 1;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				;

type_decl : simple_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$.type = TK_TYPE_DECL;
				$$.child_number =  1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
		  }
		  | array_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$.type = TK_TYPE_DECL;
				$$.child_number =  1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
		  }
		  | record_type_decl{
				if(DEBUG){
					printf("PARSING TYPE DECL\n");
				}
				$$.type = TK_TYPE_DECL;
				$$.child_number =  1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
		  }
		  ;

array_type_decl : TK_ARRAY TK_LB simple_type_decl TK_RB TK_OF type_decl{
				//NOTE: IGNORE TK_LB TK_RB TK_OF
				if(DEBUG){
					printf("PARSING ARRAY\n");
				}
				$$.type = TK_ARRAY;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$3;
				$$.child[1] = &$6;
			}
			;

record_type_decl : TK_RECORD field_decl_list TK_END{
				//NOTE: IGNORE TK_END
				$$.type = TK_RECORD;
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$2;
			}
			;

field_decl_list : field_decl_list field_decl{
				if(DEBUG){
					printf("PARSING FIELD DECL LIST\n");
				}
				$$.type = TK_FIELD_DECL_LIST;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$2;
			}
			| field_decl{
				if(DEBUG){
					printf("PARSING FIELD DECL LIST : FIRST ONE\n");
				}
				$$.type = TK_FIELD_DECL_LIST;
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
			}
			;

field_decl : name_list TK_COLON type_decl TK_SEMI{
			//NOTE: IGNORE TK_COLON TK_SEMI
				if(DEBUG){
					printf("PARSING FIELD DECL\n");
				}
				$$.type = TK_FIELD_DECL;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$3;
			}
		   	;

name_list : name_list TK_COMMA TK_ID{
			//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_NL', IGNORE TK_COMMA
				if(DEBUG){
					printf("PARSING NAME LIST\n");
				}
				$$.type = TK_NL;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$3;
			}
		  	| TK_ID{
		  		if(DEBUG){
		  			printf("PARSING NAME LIST : FIRST ONE\n");
		  		}
		  		$$.type = TK_NL;
		  		$$.child_number = 1;
		  		$$.child = MALLOC(1);
		  		$$.child[0] = &$1;
		  	}
		  	;

simple_type_decl : TK_SYS_TYPE{
				//NOTE: HERE TAG IS SIMPLIFIED AS 'TK_STD' AND FOLLOWED BY A TYPE
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL SYS TYPE\n");
					}
					$$.type = TK_STD_SYS_TYPE;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
				 | TK_ID{
					if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_ID;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
				 | TK_LP name_list TK_RP{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_NL;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$2;
				}
				 | const_value TK_DOTDOT const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_DD;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				 | TK_MINUS const_value TK_DOTDOT const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_DD;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				 | TK_MINUS const_value TK_DOTDOT TK_MINUS const_value{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_DD;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				 | TK_ID TK_DOTDOT TK_ID{
				 	if(DEBUG){
						printf("PARSING SIMPLE TYPE DECL ID\n");
					}
					$$.type = TK_STD_DD;
					$$.child_number = 2;
					$$.child = MALLOC(2);
					$$.child[0] = &$1;
					$$.child[1] = &$3;
				}
				 ;

var_part : TK_VAR var_decl_list{
		//NOTE: IGNORE TK_VAR
			if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	$$.type = TK_VAR_PART;
			$$.child_number = 1;
			$$.child = MALLOC(1);
			$$.child[0] = &$2;
		}
		|{
		  	if(DEBUG){
		  		printf("PARSING VAR PART NULL\n");
		  	}
		  	$$.type = TK_VAR_PART;
			$$.child_number = 0;
			$$.child = NULL;
		}
		;

var_decl_list : var_decl_list var_decl{
				if(DEBUG){
					printf("PARSING VAR DECL LIST\n");
				}
				$$.type = TK_DECL_LIST;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$2;
			}
			| var_decl{
				if(DEBUG){
					printf("PARSING VAR DECL LIST : FIRST ONE\n");
				}
				$$.type = TK_DECL_LIST;
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
			}
			;

var_decl : name_list TK_COLON type_decl TK_SEMI{
			//NOTE: IGNORE TK_COLON TK_SEMI
			if(DEBUG){
				printf("PARSING VAR DECL\n");
			}
			$$.type = TK_VAR_DECL;
			$$.child_number = 2;
			$$.child = MALLOC(2);
			$$.child[0] = &$1;
			$$.child[1] = &$3;
		}
		;

routine_part : routine_part function_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$.type = TK_ROUTINE_PART;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$2;
			}
			 | routine_part procedure_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$.type = TK_ROUTINE_PART;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$2;
			}
			 | function_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$.type = TK_ROUTINE_PART;
				$$.child_number = 1;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
			}
			 | procedure_decl{
				if(DEBUG){
					printf("PARSING ROUTINE_PART\n");
				}
				$$.type = TK_ROUTINE_PART;
				$$.child_number = 1;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
			}
			 |{
			 	if(DEBUG){
			 		printf("PARSING ROUTINE_PART NULL\n");
			 	}
			 	$$.type = TK_ROUTINE_PART;
			 	$$.child_number = 0;
			 	$$.child = NULL;
			 }
			 ;

function_decl : function_head TK_SEMI routine TK_SEMI{
				//NOTE: IGNORE TK_SEMI
				if(DEBUG){
					printf("PARSING FUNC DECL\n");
				}
				$$.type = TK_FUNC_DECL;
				$$.child_number = 2;
				$$.child = MALLOC(2);
				$$.child[0] = &$1;
				$$.child[1] = &$3;
			}
			;

function_head : TK_FUNCTION TK_ID parameters TK_COLON simple_type_decl
			  ;

procedure_decl : procedure_head TK_SEMI routine TK_SEMI
			   ;

procedure_head : TK_PROCEDURE TK_ID parameters
			   ;

parameters : TK_LP para_decl_list TK_RP
		   |{
		   		if(DEBUG){
		   			printf("PARSING PARA NULL\n");
		   		}
		   }
		   ;

para_decl_list : para_decl_list TK_SEMI para_type_list
			| para_type_list
			;

para_type_list : var_para_list TK_COLON simple_type_decl
			   | val_para_list TK_COLON simple_type_decl
			   ;

var_para_list : TK_VAR name_list{
				//NOTE: IGNORE TK_VAR VAR_PARA_LIST IS "TK_VAR"
				if(DEBUG){
					printf("PARSING VAR LIST\n");
				}
				$$.type = TK_VAR；
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$2;
			}
			;

val_para_list : name_list{
				if(DEBUG){
					printf("PARSING VAL PARA LIST\n");
				}
				$$.type = TK_VAL_PARA_LIST;
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
			}
			;

routine_body : compound_stmt{
				if(DEBUG){
					printf("PARSING ROUTINE BODY\n");
				}
				$$.type = TK_ROUTINE_PART;
				$$.child_number = 1;
				$$.child = MALLOC(1);
				$$.child[0] = &$1;
			}
			;

stmt_list : stmt_list stmt TK_SEMI{
			if(DEBUG){
				printf("PARSING STMT LIST\n");
			}
			$$.type = TK_STMT_LIST;
			$$.child_number = 2;
			$$.child = MALLOC(2);
			$$.child[0] = &$1;
			$$.child[1] = &$2;
		}
		|{
		  	if(DEBUG){
		  		printf("PARSING STMT LIST NULL\n");
		  	}
		  	$$.type = TK_STMT_LIST;
		  	$$.child_number = 0;
		  	$$.child = NULL;
		}
		;

stmt : TK_INTEGER TK_COLON non_label_stmt{
		//NOTE: IGNORE TK_COLON
		if(DEBUG){
			printf("PARSING STMT\n");
		}
		$$.type = TK_STMT;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	}	
	 | non_label_stmt{
	 	//NOTE: IGNORE TK_COLON
	 	if(DEBUG){
	 		printf("PARSING NON LABEL STMT\n");
	 	}
	 	$$.type = TK_STMT;
	 	$$.child_number = 1;
	 	$$.child = MALLOC(1);
	 	$$.child[0] = &$1;
	 }
	 ;

non_label_stmt : assign_stmt{
					if(DEBUG){
						printf("PARSING ASSIGN STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | proc_stmt{
					if(DEBUG){
						printf("PARSING PROC STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | compound_stmt{
					if(DEBUG){
						printf("PARSING CP STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | if_stmt{
					if(DEBUG){
						printf("PARSING IF STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | repeat_stmt{
					if(DEBUG){
						printf("PARSING REPEAT STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | while_stmt{
					if(DEBUG){
						printf("PARSING WHILE STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | for_stmt{
					if(DEBUG){
						printf("PARSING FOR STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | case_stmt{
					if(DEBUG){
						printf("PARSING CASE STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   | goto_stmt{
					if(DEBUG){
						printf("PARSING GOTO STMT\n");
					}
					$$.type = TK_NON_LABEL_STMT;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
			   ;

assign_stmt : TK_ID TK_ASSIGN expression
			| TK_ID TK_LB expression TK_RB TK_ASSIGN expression
			| TK_ID TK_DOT TK_ID TK_ASSIGN expression
			;

proc_stmt : TK_ID{
				
			}
          | TK_ID TK_LP args_list TK_RP
          | TK_SYS_PROC
          | TK_SYS_PROC TK_LP expression_list TK_RP
          | TK_READ TK_LP factor TK_RP
		  ;

compound_stmt : TK_BEGIN stmt_list TK_END{
			if(DEBUG){
				printf("PARSING CP STMT\n");
			}
			$$.type = TK_CP_STMT;
			$$.child_number = 1;
			$$.child = MALLOC(1);
			$$.child[0] = &$2;
		}
		;

if_stmt : TK_IF expression TK_THEN stmt else_clause{
			//NOTE: IGNORE TK_IF TK_THEN
			
		}
		;

else_clause : TK_ELSE stmt
			|{
				if(DEBUG){
					printf("PARSING ELSE CLAUSE NULL\n");
				}
				$$.type = TK_ELSE;
				$$.child_number = 0;
				$$.child = NULL;
			}
			;

repeat_stmt : TK_REPEAT stmt_list TK_UNTIL expression

while_stmt : TK_WHILE expression TK_DO stmt
		   ;

for_stmt : TK_FOR TK_ID TK_ASSIGN expression direction expression TK_DO stmt
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

case_stmt : TK_CASE expression TK_OF case_expr_list TK_END
		  ;

case_expr_list : case_expr_list case_expr
			   | case_expr
			   ;

case_expr : const_value TK_COLON stmt TK_SEMI
          | TK_ID TK_COLON stmt TK_SEMI
		  ;

goto_stmt : TK_GOTO TK_INTEGER{
		//NOTE: GOTO STMT IS ACTUALLY TK_INTEGER
			if(DEBUG){
				printf("PARSING GOTO STMT\n");
			}
			$$ = $2;
			$$.type = TK_GOTO;
		}
		;

expression_list : expression_list TK_COMMA expression{
					//NOTE: IGNORE TK_COMMA

				}
				| expression{
					if(DEBUG){
						printf("PARSING EXP LIST\n");
					}
					$$.type = TK_EXP_LIST;
					$$.child_number = 1;
					$$.child = MALLOC(1);
					$$.child[0] = &$1;
				}
				;

expression : expression TK_GE expr{
			//NOTE: IGNORE TK_GE TK_GT TK_LE TK_LT TK_EQUAL TK_UNEQUAL
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_GE;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expression TK_GT expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_GT;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expression TK_LE expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_LE;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expression TK_LT expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_LT;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expression TK_EQUAL expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_EQUAL;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expression TK_UNEQUAL expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION\n");
		   		}
		   		$$.type = TK_UNEQUAL;
		   		$$.child_number = 2;
		   		$$.child = MALLOC(2);
		   		$$.child[0] = &$1;
		   		$$.child[1] = &$3;
		   }
		   | expr{
		   		if(DEBUG){
		   			printf("PARSING EXPRESSION : FIRST ONE\n");
		   		}
		   		$$.type = TK_EXP;
		   		$$.child_number = 1;
		   		$$.child = MALLOC(1);
		   		$$.child[0] = &$1;
		   }
		   ;

expr : expr TK_PLUS term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_PLUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$.type = TK_PLUS;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | expr TK_MINUS term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_MINUS
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$.type = TK_MINUS;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | expr TK_OR term{
	 //NOTE: expr IS EXPR, expression IS EXP, IGNORE TK_OR
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$.type = TK_OR;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | term{
	 //NOTE: expr IS EXPR, expression IS EXP
	 	if(DEBUG){
	 		printf("PARSING EXPR : FIRST ONE\n");
	 	}
	 	$$.type = TK_EXPR;
	 	$$.child_number = 1;
	 	$$.child = MALLOC(1);
	 	$$.child[0] = &$1;
	 }
	 ;

term : term TK_MUL factor{
	 	if(DEBUG){
	 		printf("PARSING TK_MUL\n");
	 	}
	 	$$.type = TK_MUL;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | term TK_DIV factor{
	 	if(DEBUG){
	 		printf("PARSING TK_DIV\n");
	 	}
	 	$$.type = TK_DIV;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | term TK_MOD factor{
	 	if(DEBUG){
	 		printf("PARSING TK_MOD\n");
	 	}
	 	$$.type = TK_MOD;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | term TK_AND factor{
	 	if(DEBUG){
	 		printf("PARSING TK_AND\n");
	 	}
	 	$$.type = TK_AND;
	 	$$.child_number = 2;
	 	$$.child = MALLOC(2);
	 	$$.child[0] = &$1;
	 	$$.child[1] = &$3;
	 }
	 | factor{
	 	if(DEBUG){
	 		printf("PARSING TERM : FIRST ONE\n");
	 	}
	 	$$.type = TK_TERM;
	 	$$.child_number = 1;
	 	$$.child = MALLOC(1);
	 	$$.child[0] = &$1;
	 }
	 ;

factor : TK_ID{
	//NOTE: THERE IS NO TK_FACTOR BUT 'TK_FACTOR' FOLLOWED BY A TYPE
		if(DEBUG){
			printf("PARSING FACTOR\n");
		}
		$$.type = TK_FACTOR_ID;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$1;
	}
	| TK_ID TK_LP args_list TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_ID_ARGS;
		$$.child_number = 2;
		$$.child = MALLOC(2);
		$$.child[0] = &$1;
		$$.child[1] = &$3;
	}
	| TK_SYS_FUNCT TK_LP args_list TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_SYS_FUNCT;
		$$.child_number = 2;
		$$.child = MALLOC(2);
		$$.child[0] = &$1;
		$$.child[1] = &$3;
	}
	| const_value{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_CONST;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$1;
	}
	| TK_LP expression TK_RP{
	//NOTE: IGNORE TK_LP TK_RP
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_EXP;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$2;
	}
	| TK_NOT factor{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_NOT;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$2;
	}
	| TK_MINUS factor{
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_MINUS;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$2;
	}
	| TK_ID TK_LB expression TK_RB{
	//NOTE: IGNORE TK_LB TK_RB
		if(DEBUG){
			printf("PARSING FACTOR \n");
		}
		$$.type = TK_FACTOR_ID_EXP;
		$$.child_number = 2;
		$$.child = MALLOC(2);
		$$.child[0] = &$1;
		$$.child[1] = &$3;
	}
	| TK_ID TK_DOT TK_ID{
	//NOTE: ID.ID IS IN ONE NODE
		if(DEBUG){
			printf("PARSING FACTOR FOR ID.ID\n");
		}
		$$.type = TK_FACTOR_DD;
		$$.child_number = 1;
		$$.child = MALLOC(1);
		$$.child[0] = &$1;
		$1.attr = MALLOC(1);
		$1.attr[0] = &$2;
	}
	;

args_list : args_list TK_COMMA expression{
			//NOTE: IGNORE TK_COMMA
			if(DEBUG){
				printf("PARSING ARGS LIST\n");
			}
			$$.type = TK_ARGS_LIST;
			$$.child_number = 2;
			$$.child = MALLOC(2);
			$$.child[0] = &$1;
			$$.child[1] = &$2;
		}
		| expression{
			if(DEBUG){
				printf("PARSING ARGS LIST : FIRST ONE\n");
			}
			$$.type = TK_ARGS_LIST;
			$$.child_number = 1;
			$$.child = MALLOC(1);
			$$.child[0] = &$1;
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

void preorder(NODE* root){
	int i;
	printf("TYPE:%d; CHILDREN:%d\n", root->type, root->child_number);
	for(i=0;i<root->child_number;i++){
		preorder(root->child[i]);
	}
}
