#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <climits>
#include <cstdarg>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

enum IntType {
    t_byte,
	t_shortint,
    t_word,
	t_smallint,
    t_dword, //t_longword, t_cardinal
	t_longint, // t_integer
    t_qword,
	t_int64, // t_comp
};

enum RealType {
	t_single,
	t_double, // t_real
	t_extended,
//	t_currency
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
	bool operator < (const Value &b) const;
	bool invalid;
	SimpleTypeEnum type;
	int ival;
	double dval;
	bool bval;
	char cval;
	string sval;

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
};

class SimpleType;
class ComplexType;
class SymbolTable;

class Type {
public:
    bool operator <(const Type &o) const;
    bool operator ==(const Type &o) const;
	int size();

	bool null;
	bool isSimpleType;
	SimpleType *simpleType;
	ComplexType *complexType;

    Type(){
        null = true;
        simpleType = nullptr;
        complexType = nullptr;
    }
    Type(const Type &o);
    Type(const string &x);
    Type(const vector<string> &x);
    Type(int start, int end, const Type &elementType);
    Type(const unordered_map<string, Type> &x);
    Type(const SimpleTypeEnum &x, const Value &a, const Value &b);
    Type(const vector<Type> &argTypeList, const vector<bool> &argVarList, const Type &retType, int isFunc = 0);

	//for ICG
	operator string();  //暂时只有simple type
};

Type parseValueType(const Value &x);


/* NOTE: simple type transform:
 * shortint <-> byte
 * smallint <-> word
 * longint <-> dword
 * int64 <-> qword
 * and the type occupies less memory -> the type occupies more memory
 * will be done automatically
 * IR generator should be carefull
 * */


class SimpleType {

public:
	SimpleTypeEnum simpleType;
	IntType intType;
	RealType realType;
	int size();

    SimpleType(){}
    SimpleType(const string &x);
};

class EnumType {
	// NOTE: one enum item cannot be in different enumType
public:
	EnumType(){}
	EnumType(const vector<string> &x): enumList(x.begin(), x.end()){}
	set<string> enumList;
};

class RecordType {
public:
	// NOTE: here we assume string in different unordered_map should have the same order
	unordered_map<string, Type> attrType;
	unordered_map<string, int> offset;

	// NOTE: here caller should guarantee attr x in this record
	Type getType(const string &x) {
		return attrType[x];
	}
	int getOffset(const string &x) {
		return offset[x];
	}
    bool operator ==(const RecordType &o) const;
    RecordType(){}
    RecordType(const unordered_map<string, Type> &x);
};

class ArrayType {
public:
	ArrayType(){}
	ArrayType(int _start, int _end, const Type &_elementType);
	int start, end, elementSize;
	Type elementType;
};

class RangeType {
	// NOTE: we assume we can determine the value in semantic analysis phase
public:
	SimpleTypeEnum rangeType;
	Value start, end;

    RangeType(){}
    RangeType(const SimpleTypeEnum &_rangeType, const Value &_start, const Value &_end): rangeType(_rangeType), start(_start), end(_end) {}
};

class FPType {
public:
	vector<Type> argTypeList;
    vector<bool> argVarList;
	Type retType;

    bool operator ==(const FPType &o) const;
    FPType(){}
    FPType(const vector<Type> &_argTypeList, const vector<bool> &_argVarList , Type _retType): argTypeList(_argTypeList), argVarList(_argVarList), retType(_retType){}
};



class ComplexType {
public:
	ComplexTypeEnum complexType;
	EnumType enumType;
	RecordType recordType;
	ArrayType arrayType;
	RangeType rangeType;
	// NOTE: here we use fptype to represent func and proc
	FPType fpType;
    int size();

    ComplexType(const vector<string> &x): enumType(x) {
        complexType = type_enum;
    }
    ComplexType(int start, int end, Type elementType): arrayType(start, end, elementType) {
        complexType = type_array;
    }
    ComplexType(const unordered_map<string, Type> &x): recordType(x) {
        complexType = type_record;
    }
    ComplexType(const SimpleTypeEnum &x, const Value &a, const Value &b): rangeType(x, a, b) {
        complexType = type_range;
    }
    ComplexType(const vector<Type> &argTypeList, const vector<bool> &argVarList, Type retType, int isFunc = 0): fpType(argTypeList, argVarList, retType) {
        complexType = isFunc ? type_func : type_proc;
    }
};

typedef struct NODE{
    string name;
	Value value;
	int type;
    int child_number;
    struct NODE** child;
    struct NODE* record;
	Type dataType;
    SymbolTable* symbolTable;
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
extern int IS_SYNTAX_ERROR;

#endif
