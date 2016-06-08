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
	bool operator < (const Value &b) const {
		// NOTE: here we assume a and b are the same type
		if (type == type_integer) {
			return ival < b.ival;
		} else if (type == type_real) {
			return dval < b.dval;
		} else if (type == type_boolean) {
			return !bval && b.bval;
		} else if (type == type_char) {
			return cval < b.cval;
		}
        assert(0);
        return false;
	}
	bool invalid;
	SimpleTypeEnum type;
	int ival;
	double dval;
	bool bval;
	char cval;
	string sval;
};

class SimpleType;
class ComplexType;
class SymbolTable;

class Type {
public:
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
	Type(const vector<Type> &argTypeList, const Type &retType, int isFunc = 0);

    bool operator <(const Type &o) const;
    bool operator ==(const Type &o) const;

	bool null;
	bool isSimpleType;
	SimpleType *simpleType;
	ComplexType *complexType;
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
	SimpleType(){}
	SimpleType(const string &x) {
		if (x == "shortint") {
			simpleType = type_integer;
			intType = t_shortint;
		} else if (x == "smallint") {
			simpleType = type_integer;
			intType = t_smallint;
		} else if (x == "longint") {
			simpleType = type_integer;
			intType = t_longint;
		} else if (x == "int64") {
			simpleType = type_integer;
			intType = t_int64;
		} else if (x == "byte") {
			simpleType = type_integer;
			intType = t_byte;
		} else if (x == "word") {
			simpleType = type_integer;
			intType = t_word;
		} else if (x == "dword") {
			simpleType = type_integer;
			intType = t_dword;
		} else if (x == "qword") {
			simpleType = type_integer;
			intType = t_qword;
		}

		if (x == "single") {
			simpleType = type_real;
			realType = t_single;
		} else if (x == "double") {
			simpleType = type_real;
			realType = t_double;
		} else if (x == "extended") {
			simpleType = type_real;
			realType = t_extended;
//		} else if (x == "currency") {
//			simpleType = type_real;
//			realType = t_currency;
		}

		if (x == "boolean") {
			simpleType = type_boolean;
		}
		if (x == "char") {
			simpleType = type_char;
		}

		if (x == "string") {
			simpleType = type_string;
		}
	}
	SimpleTypeEnum simpleType;
	IntType intType;
	RealType realType;
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
	RecordType(){}
	RecordType(const unordered_map<string, Type> &x): attrType(x){}
	unordered_map<string, Type> attrType;
    bool operator ==(const RecordType &o) const {
        if (this->attrType.size() != o.attrType.size()) {
            return false;
        }
        for (const auto &x: this->attrType) {
            auto y = o.attrType.find(x.first);
            if (y == o.attrType.end() || !(y->second == x.second)) {
                return false;
            }
        }
        return true;
    }
};

class ArrayType {
public:
	ArrayType(){}
	ArrayType(int _start, int _end, const Type &_elementType): start(_start), end(_end), elementType(_elementType){
		assert(elementType.isSimpleType);
		switch (elementType.simpleType->simpleType) {
			case type_integer:
				switch (elementType.simpleType->intType) {
					case t_shortint:
					case t_byte:
						elementSize = 1;
						break;
					case t_smallint:
					case t_word:
						elementSize = 2;
						break;
					case t_longint:
					case t_dword:
						elementSize = 4;
						break;
					case t_int64:
					case t_qword:
						elementSize = 8;
						break;
				}
				break;
			case type_real:
				switch (elementType.simpleType->realType) {
					case t_single:
						elementSize = 4;
						break;
					case t_double:
						elementSize = 8;
						break;
					case t_extended:
						elementSize = 12;
						break;
				}
				break;
			case type_boolean:
				elementSize = 1;
				break;
			case type_char:
				elementSize = 1;
				break;
			case type_string:
				assert(0);
				break;
		}
	}
	int start, end, elementSize;
	Type elementType;
};

class RangeType {
	// NOTE: we assume we can determine the value in semantic analysis phase
public:
	RangeType(){}
	RangeType(const SimpleTypeEnum &_rangeType, const Value &_start, const Value &_end): rangeType(_rangeType), start(_start), end(_end) {}
	SimpleTypeEnum rangeType;
	Value start, end;
};

class FPType {
public:
	FPType(){}
	FPType(vector<Type> _argTypeList, Type _retType): argTypeList(_argTypeList), retType(_retType){}
	vector<Type> argTypeList;
	Type retType;
    bool operator ==(const FPType &o) const {
        if (argTypeList.size() != o.argTypeList.size()) {
            return false;
        }
        for (int i = 0; i < argTypeList.size(); i++) {
            if (!(argTypeList[i] == o.argTypeList[i])) {
                return false;
            }
        }
        return true;
    }
};

class ComplexType {
public:
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
	ComplexType(const vector<Type> &argTypeList, Type retType, int isFunc = 0): fpType(argTypeList, retType) {
		complexType = isFunc ? type_func : type_proc;
	}
	ComplexTypeEnum complexType;
	EnumType enumType;
	RecordType recordType;
	ArrayType arrayType;
	RangeType rangeType;
	// NOTE: here we use fptype to represent func and proc
	FPType fpType;
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


#endif
