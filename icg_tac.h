#ifndef __ICG_TAC_H__
#define __ICG_TAC_H__

struct Error {
	string msg;
	Error(string msg);
};
struct _Value {
	enum Type {
		INTEGER, FLOAT, CHAR, STRING, Variable,
		MYINT, MYSTRING
	};
	int type;
	struct Val {
		int i;
		double d;
		char c;
		int strid;
		string varName;
	} val;
	int i;
	string s;
	_Value();
	_Value(int a);
	_Value(double a);
	_Value(char a);
	_Value(string a);
	
	_Value(int a, int d);
	_Value(char *s, int d);
	_Value(string s, int d);
	
	operator string();
	int toInt();
};
typedef pair<int, _Value> piv;
piv genCode(NODE *t, int extraMsg=-1);

#endif
