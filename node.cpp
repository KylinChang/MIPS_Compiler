#include "common.h"
#include "yy.tab.hpp"
#include <algorithm>
map<int, string> NODE_NAMES;

NODE* NEWNODE(int type){
	NODE* node = new NODE();
	node->type = type;
	node->child_number = 0;
	node->child = NULL;
	if(NODE_NAMES.find(type)!=NODE_NAMES.end()){
//		char* tmp = (char*)malloc(sizeof(char)*(NODE_NAMES[type].length()+1));
//		strcpy(tmp, NODE_NAMES[type].c_str());
        node->name = NODE_NAMES[type];
	}
	return node;
} 


string genString(char *s, int len) {
	s[len] = 0; string ss(s);
	transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
    return string(ss);
}

void setName(NODE* node, int type){
	if(NODE_NAMES.find(type)!=NODE_NAMES.end()){
//        char* tmp = (char*)malloc(sizeof(char)*(NODE_NAMES[type].length()+1));
//        strcpy(tmp, NODE_NAMES[type].c_str());
//        node->name = string(tmp);
        node->name = NODE_NAMES[type];
	}
}

void node_init(){

	NODE_NAMES[TK_PROGRAM] = "TK_PROGRAM";
	NODE_NAMES[TK_PROGRAM_HEAD] = "TK_PROGRAM_HEAD";
	NODE_NAMES[TK_ROUTINE] = "TK_ROUTINE";
	NODE_NAMES[TK_ROUTINE_HEAD] = "TK_ROUTINE_HEAD";
	NODE_NAMES[TK_CONST_PART] = "TK_CONST_PART";
	NODE_NAMES[TK_CONST_DL] = "TK_CONST_DL";
	NODE_NAMES[TK_CONST_DL_END] = "TK_CONST_DL_END";
	NODE_NAMES[TK_CONST_MINUS] = "TK_CONST_MINUS";
	NODE_NAMES[TK_TYPE_PART] = "TK_TYPE_PART";
	NODE_NAMES[TK_TYPE_DL] = "TK_TYPE_DL";
	NODE_NAMES[TK_TYPE_DL_END] = "TK_TYPE_DL_END";
	NODE_NAMES[TK_TYPE_DEF] = "TK_TYPE_DEF";
	NODE_NAMES[TK_TYPE_DECL_SIM] = "TK_TYPE_DECL_SIM";
	NODE_NAMES[TK_TYPE_DECL_ARR] = "TK_TYPE_DECL_ARR";
	NODE_NAMES[TK_TYPE_DECL_REC] = "TK_TYPE_DECL_REC";
	NODE_NAMES[TK_ARRAY] = "TK_ARRAY";
	NODE_NAMES[TK_RECORD] = "TK_RECORD";
	NODE_NAMES[TK_FIELD_DL] = "TK_FIELD_DL";
	NODE_NAMES[TK_FIELD_DL_END] = "TK_FIELD_DL_END";
	NODE_NAMES[TK_FIELD_DECL] = "TK_FIELD_DECL";
	NODE_NAMES[TK_NL] = "TK_NL";
	NODE_NAMES[TK_NL_END] = "TK_NL_END";
	NODE_NAMES[TK_STD_SYS_TYPE] = "TK_STD_SYS_TYPE";
	NODE_NAMES[TK_STD_ID] = "TK_STD_ID";
	NODE_NAMES[TK_STD_NL] = "TK_STD_NL";
	NODE_NAMES[TK_STD_DD] = "TK_STD_DD";
	NODE_NAMES[TK_STD_DD_M] = "TK_STD_DD_M";
	NODE_NAMES[TK_STD_DD_MM] = "TK_STD_DD_MM";
	NODE_NAMES[TK_STD_DD_ID] = "TK_STD_DD_ID";
	NODE_NAMES[TK_ID_MINUS] = "TK_ID_MINUS";

	NODE_NAMES[TK_VAR_PART] = "TK_VAR_PART";
	NODE_NAMES[TK_DL] = "TK_DL";
	NODE_NAMES[TK_DL_END] = "TK_DL_END";
	NODE_NAMES[TK_VAR_DECL] = "TK_VAR_DECL";

	NODE_NAMES[TK_ROUTINE_PART_RF] = "TK_ROUTINE_PART_RF";
	NODE_NAMES[TK_ROUTINE_PART_RP] = "TK_ROUTINE_PART_RP";
	NODE_NAMES[TK_ROUTINE_PART_FUNC] = "TK_ROUTINE_PART_FUNC";
	NODE_NAMES[TK_ROUTINE_PART_PROC] = "TK_ROUTINE_PART_PROC";
	NODE_NAMES[TK_ROUTINE_PART_NULL] = "TK_ROUTINE_PART_NULL";

	NODE_NAMES[TK_FUNC_DECL] = "TK_FUNC_DECL";
	NODE_NAMES[TK_FUNC_HEAD] = "TK_FUNC_HEAD";
	NODE_NAMES[TK_PROC_DECL] = "TK_PROC_DECL";
	NODE_NAMES[TK_PROC_HEAD] = "TK_PROC_HEAD";
	NODE_NAMES[TK_PARA_TL_VAL] = "TK_PARA_TL_VAL";
	NODE_NAMES[TK_PARA_TL_VAR] = "TK_PARA_TL_VAR";
	NODE_NAMES[TK_PARA] = "TK_PARA";
	NODE_NAMES[TK_PARA_NULL] = "TK_PARA_NULL";
	NODE_NAMES[TK_PARA_DL] = "TK_PARA_DL";
	NODE_NAMES[TK_PARA_DL_END] = "TK_PARA_DL_END";
	NODE_NAMES[TK_PARA_TL] = "TK_PARA_TL";
	NODE_NAMES[TK_PARA_TL_END] = "TK_PARA_TL_END";
	NODE_NAMES[TK_VAR] = "TK_VAR";
	NODE_NAMES[TK_VAL_PARA_LIST] = "TK_VAL_PARA_LIST";
	NODE_NAMES[TK_ROUTINE_BODY] = "TK_ROUTINE_BODY";
	NODE_NAMES[TK_STMT_LIST] = "TK_STMT_LIST";
	NODE_NAMES[TK_STMT_LIST_NULL] = "TK_STMT_LIST_NULL";
	NODE_NAMES[TK_STMT] = "TK_STMT";

	NODE_NAMES[TK_NON_LABEL_STMT_ASSIGN] = "TK_NON_LABEL_STMT_ASSIGN";
	NODE_NAMES[TK_NON_LABEL_STMT_PROC] = "TK_NON_LABEL_STMT_PROC";
	NODE_NAMES[TK_NON_LABEL_STMT_CP] = "TK_NON_LABEL_STMT_CP";
	NODE_NAMES[TK_NON_LABEL_STMT_IF] = "TK_NON_LABEL_STMT_IF";
	NODE_NAMES[TK_NON_LABEL_STMT_REP] = "TK_NON_LABEL_STMT_REP";
	NODE_NAMES[TK_NON_LABEL_STMT_WHILE] = "TK_NON_LABEL_STMT_WHILE";
	NODE_NAMES[TK_NON_LABEL_STMT_FOR] = "TK_NON_LABEL_STMT_FOR";
	NODE_NAMES[TK_NON_LABEL_STMT_CASE] = "TK_NON_LABEL_STMT_CASE";
	NODE_NAMES[TK_NON_LABEL_STMT_GOTO] = "TK_NON_LABEL_STMT_GOTO";

	NODE_NAMES[TK_ASSIGN_ID] = "TK_ASSIGN_ID";
	NODE_NAMES[TK_ASSIGN_ID_EXPR] = "TK_ASSIGN_ID_EXPR";
	NODE_NAMES[TK_ASSIGN_DD] = "TK_ASSIGN_DD";

	NODE_NAMES[TK_PROC_ID] = "TK_PROC_ID";
	NODE_NAMES[TK_PROC_ID_ARGS] = "TK_PROC_ID_ARGS";
	NODE_NAMES[TK_PROC_SYS] = "TK_PROC_SYS";
	NODE_NAMES[TK_PROC_SYS_ARGS] = "TK_PROC_SYS_ARGS";
	NODE_NAMES[TK_PROC_READ] = "TK_PROC_READ";
	NODE_NAMES[TK_PROC_READLN] = "TK_PROC_READLN";

	NODE_NAMES[TK_CP_STMT] = "TK_CP_STMT";
	NODE_NAMES[TK_IF] = "TK_IF";
	NODE_NAMES[TK_ELSE] = "TK_ELSE";
	NODE_NAMES[TK_ELSE_NULL] = "TK_ELSE_NULL";

	NODE_NAMES[TK_REPEAT] = "TK_REPEAT";
	NODE_NAMES[TK_WHILE] = "TK_WHILE";
	NODE_NAMES[TK_FOR] = "TK_FOR";
	NODE_NAMES[TK_TO] = "TK_TO";
	NODE_NAMES[TK_DOWNTO] = "TK_DOWNTO";
	NODE_NAMES[TK_CASE] = "TK_CASE";
	NODE_NAMES[TK_CASE_EL] = "TK_CASE_EL";
	NODE_NAMES[TK_CASE_EL_END] = "TK_CASE_EL_END";
	NODE_NAMES[TK_CASE_EXPR] = "TK_CASE_EXPR";
	NODE_NAMES[TK_CASE_EXPR_END] = "TK_CASE_EXPR_END";

	NODE_NAMES[TK_GOTO] = "TK_GOTO";
	NODE_NAMES[TK_EXP_LIST] = "TK_EXP_LIST";
	NODE_NAMES[TK_EXP_LIST_END] = "TK_EXP_LIST_END";

	NODE_NAMES[TK_GE] = "TK_GE";
	NODE_NAMES[TK_GT] = "TK_GT";
	NODE_NAMES[TK_LE] = "TK_LE";
	NODE_NAMES[TK_LT] = "TK_LT";
	NODE_NAMES[TK_EQUAL] = "TK_EQUAL";
	NODE_NAMES[TK_UNEQUAL] = "TK_UNEQUAL";
	NODE_NAMES[TK_EXP]  = "TK_EXP";

	NODE_NAMES[TK_PLUS] = "TK_PLUS";
	NODE_NAMES[TK_MINUS] = "TK_MINUS";
	NODE_NAMES[TK_OR] = "TK_OR";
	NODE_NAMES[TK_EXPR] = "TK_EXPR";

	NODE_NAMES[TK_MUL] = "TK_MUL";
	NODE_NAMES[TK_DIV] = "TK_DIV";
	NODE_NAMES[TK_MOD] = "TK_MOD";
	NODE_NAMES[TK_AND] = "TK_AND";
	NODE_NAMES[TK_TERM] = "TK_TERM";

	NODE_NAMES[TK_FACTOR_ID] = "TK_FACTOR_ID";
	NODE_NAMES[TK_FACTOR_ID_ARGS] = "TK_FACTOR_ID_ARGS";
	NODE_NAMES[TK_FACTOR_SYS_FUNCT] = "TK_FACTOR_SYS_FUNCT";
	NODE_NAMES[TK_FACTOR_CONST] = "TK_FACTOR_CONST";
	NODE_NAMES[TK_FACTOR_EXP] = "TK_FACTOR_EXP";
	NODE_NAMES[TK_FACTOR_NOT] = "TK_FACTOR_NOT";
	NODE_NAMES[TK_FACTOR_MINUS] = "TK_FACTOR_MINUS";
	NODE_NAMES[TK_FACTOR_ID_EXP] = "TK_FACTOR_ID_EXP";
	NODE_NAMES[TK_FACTOR_DD] = "TK_FACTOR_DD";

	NODE_NAMES[TK_ARGS_LIST] = "TK_ARGS_LIST";
	NODE_NAMES[TK_ARGS_LIST_END] = "TK_ARGS_LIST_END";

	NODE_NAMES[TK_TYPE_DECL] = "TK_TYPE_DECL";
	NODE_NAMES[TK_ROUTINE_PART] = "TK_ROUTINE_PART";


	NODE_NAMES[TK_STMT_ASSIGN] = "TK_STMT_ASSIGN";
	NODE_NAMES[TK_STMT_PROC] = "TK_STMT_PROC";
	NODE_NAMES[TK_STMT_CP] = "TK_STMT_CP";
	NODE_NAMES[TK_STMT_LABEL] = "TK_STMT_LABEL";

	NODE_NAMES[TK_INTEGER] = "TK_INTEGER";
	NODE_NAMES[TK_REAL] = "TK_REAL";
	NODE_NAMES[TK_CHAR] = "TK_CHAR";
	
	NODE_NAMES[TK_ID] = "TK_ID";

}
