#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <climits>
#include <cstdarg>

using namespace std;

enum IntType {
	t_shortint,
	t_smallint,
	t_longint, // t_integer
	t_int64, // t_comp
	t_byte,
	t_word,
	t_dword, //t_longword, t_cardinal
	t_qword
};

enum RealType {
	t_single,
	t_double, // t_real
	t_extended,
	t_currency
};

enum SimpleTypeEnum {
	type_integer,
	type_real,
	type_boolean,
	type_char,
	type_string
};

enum ComplexTypeEnum {
	type_array,
	type_enum,
	type_record,
	type_range,
	type_func,
	type_proc
};

class Value {
public:
	Value(){invalid = true;}
	Value(int x) {
		invalid = false;
		ival = x;
		type = type_integer;
	}
	Value (double x) {
		invalid = false;
		dval = x;
		type = type_real;
	}
	Value (bool x) {
		invalid = false;
		bval = x;
		type = type_boolean;
	}
	Value (char x) {
		invalid = false;
		cval = x;
		type = type_char;
	}
	Value (string x) {
		invalid = false;
		sval = x;
		type = type_string;
	}
	bool invalid;
	SimpleTypeEnum type;
	int ival;
	double dval;
	bool bval;
	char cval;
	string sval;
};

typedef struct NODE{
    string name;
	Value value;
	int type;
    int child_number;
    struct NODE** child;
    struct NODE* record;

	int lineno; //output the error line number
} NODE;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)

//#define MALLOC(pointer,num) (NODE**)malloc(NODE_POINTER_SIZE*(pointer->child_number=num))
#define MALLOC(pointer,num) new NODE*[pointer->child_number=num]
#define TO_LOWER_CASE(ch) (ch<='A' && ch>='a')?(ch-'A'+'a') : ch;

#define MIN(a, b) min(a == NULL ? INT_MAX : a->lineno, b == NULL ? INT_MAX : b->lineno)
//#define MIN(a,b) ((a)->lineno) < ((b)->lineno) ? ((a)->lineno) : ((b)->lineno);

//LOGERR FOR error output
void LOGERR(int cnt, ...);

NODE* NEWNODE(int type);
void setName(NODE* node, int type);
void node_init();
string genString(char *s, int len);

extern "C" {
	extern int yylex();
}

int yyerror(string s);

#define YYSTYPE NODE*

extern char* yytext;
//extern int yylineno;
extern FILE* yyin;

extern int yyparse();
extern int DEBUG;
extern NODE* ROOT;


#endif
