#include <string>
#include <queue>
#include <sstream>
#include "y.tab.h"
using namespace std;

/*
	下面符号，意义和C++中的一样。
		+ - * /
		地址操作符(可在赋值号左边或右边)： & *

	read x				读入整数x
	elem_size(...)		返回变量的本身占用的字节长度
	field_offset(x,a)	返回a变量在x结构中的offset
	
	赋值语句
	
	
	pascal参数传递顺序：
		1.参数按出现顺序，从左至右地进栈。
    	2.被调用函数在返回调用前负责栈的平衡。
*/

/*
	if (E) S1 else S2
	->
		<code to evaluate E to t1>
		if_false t1 goto L1
		<code for S1>
		goto L2
		label L1
		<code for S2>
		label L2

	while ( E ) S
	->
		label L1
		<code to evaluate E to t1>
		if_false t1 goto L2
		<code forS>
		goto L1
		label L2
*/

/*
	Temp Note:
		procedure是没有返回值的函数，function是有返回值的函数。而且procedure可以在没有参数的时候不使用括号调用。
		function_head + routine 约等于 function
*/

#define mp make_pair

struct Error {
	string msg;
	Error(string msg):msg(msg) {}
};

struct TempVars {
	static int ind;
	static priority_queue<int, vector<int>, greater<int> > idleTemp;  // 注意别用size()来判断是否empty，用empty()
	static int getAnother() {
		if (idleTemp.empty()) {
			return ++ind;
		}
		else {
			int ret = idleTemp.top();
			idleTemp.pop();
			return ret;
		}
	}
	static void release(int TempVar) {
		idleTemp.push(TempVar);
	}
	template <class T>
	static void release(pair<int,T> a) {
		release(a.first);
	}
};
int TempVars::ind = 0;

struct Label {
	static int ind;
	static int newLabel() { return ++ind; }
};
int Label::ind = 0;

// struct Value {
// 	enum Type { INTEGER, FLOAT, CHAR, STRING };
// 	int type;
// 	struct Val {
// 		int i;
// 		double d;
// 		char c;
// 		string s;
// 	} val;
// 	Value():type(-1) {}
// 	Value(int a):type(INTEGER) { val.i = a; }
// 	Value(double a):type(FLOAT) { val.d = a; }
// 	Value(char a):type(CHAR) { val.c = a; }
// 	Value(string a):type(STRING) { val.s = a; }
// 	Value(char *a,int d=0):type(STRING) {
// 		val.s = string(a);
// 		if (d) delete a;
// 	}
// };
// inline string operator+(const int &a, const string &b) {
// 	stringstream ss;
// 	string c;
// 	ss<<a; ss>>c;
// 	return c+b;
// }
// inline string operator+(const string &a, const int &b) {
// 	return b+a;
// }
// inline string operator+(const double &a, const string &b) {
// 	stringstream ss;
// 	string c;
// 	ss<<a; ss>>c;
// 	return c+b;
// }
// inline string operator+(const string &a, const double &b) {
// 	return b+a;
// }
// inline Value operator+(const Value &a, const Value &b) {
// 	if (a.type == Value::INTEGER) {
// 		if (b.type == Value::INTEGER)
// 			return Value(a.val.i + b.val.i);
// 		else if (b.type == Value::FLOAT)
// 			return Value(a.val.i + b.val.d);
// 		else if (b.type == Value::CHAR)
// 			return Value(a.val.i + b.val.c);
// 		else //if (b.type == Value::STRING)
// 			return Value(a.val.i + b.val.s);
// 	}
// 	else if (a.type == Value::FLOAT) {
// 		if (b.type == Value::INTEGER)
// 			return Value(a.val.d + b.val.i);
// 		else if (b.type == Value::FLOAT)
// 			return Value(a.val.d + b.val.d);
// 		else if (b.type == Value::CHAR)
// 			return Value(a.val.d + b.val.c);
// 		else //if (b.type == Value::STRING)
// 			return Value(a.val.d + b.val.s);
// 	}
// 	else if (a.type == Value::CHAR) {
// 		if (b.type == Value::INTEGER)
// 			return Value(a.val.c + b.val.i);
// 		else if (b.type == Value::FLOAT)
// 			return Value(a.val.c + b.val.d);
// 		else if (b.type == Value::CHAR)
// 			return Value(a.val.c + b.val.c);
// 		else //if (b.type == Value::STRING)
// 			return Value(a.val.c + b.val.s);
// 	}
// 	else if (a.type == Value::STRING) {
// 		if (b.type == Value::INTEGER)
// 			return Value(a.val.s + b.val.i);
// 		else if (b.type == Value::FLOAT)
// 			return Value(a.val.s + b.val.d);
// 		else if (b.type == Value::CHAR)
// 			return Value(a.val.s + b.val.c);
// 		else //if (b.type == Value::STRING)
// 			return Value(a.val.s + b.val.s);
// 	}
// }

struct Value {
	enum Type { INTEGER, FLOAT, CHAR, STRING, Variable };
	int type;
	struct Val {
		int i;
		double d;
		char c;
		int strid;
		int varid;
	} val;
	Value():type(-1) {}
	Value(int a):type(INTEGER) { val.i = a; }
	operator string() {
		stringstream ss;
		switch (type) {
			case INTEGER: ss<<val.i; break;
			case FLOAT: ss<<val.d; break;
			case CHAR: ss<<val.c; break;
			//case STRING: ... break;  // TO-DO
			//case Variable: ... break;  // TO-DO
			default: break;
		}
		string s; ss>>s;
		return s;
	}
};

typedef pair<int, Value> piv;
string getName(piv a) {
	if (a.first == 0) {  // t开头的临时变量(type==INTEGER，val.i保存值)
		return 't' + string(a.second);
	}
	else if (a.first == 1) {  // 常量(type==INTEGER, FLOAT, CHAR)
		return a.second;
	}
	else if (a.first == 2) {  // 代码里(符号表里)的变量 (可能带的是变量名、函数名、Program名)
		// TO-DO
	}
	else if (a.first == 3) {  // 符号表里的字符串常量
		// TO-DO
	}
}
void output(string s) {
	printf("%s\n", s.c_str());
}
void output(string c, string a, string op, string b) {
	printf("%s = %s %s %s\n", c.c_str(), a.c_str(), op.c_str(), b.c_str());
}
void output(piv c, piv a, string op, piv b) {
	output(getName(c), getName(a), op, getName(b));
}


void chkOpnd(piv a, string side, string op) {
	a.first==-1 ? throw Error(side + " operand of " + op + " cannot be void"): 0; 
}
void chkOpnd(piv a, string side, char op) {
	chkOpnd(a, side, string("") + '\'' + op + '\'');
}
void genSymbolTable() {  // TO-DO
}

// /*  返回当前的计算值放在哪个临时变量中  **
// **  返回-1表示当前表达式不产生返回值   */
piv genCode(NODE *t, int faToken=-1) {
	if (t) {
		piv a, b, c;
		switch (t->type) {
		/*  常数  */
		case TK_REAL:
			return mp(1, Value(t->dval));
			break;
		case TK_INTEGER:
			return mp(1, Value(t->ival));
			break;
		case TK_CHAR:
			return mp(1, Value(t->ch));
			break;
		// case TK_STRING:
		// 	return mp(3, Value());  // TO-DO
		// 	break;
		// case TK_SYS_CON:
		// 	return mp(3, );
		// 	break;
		
		/*  变量  */
		case TK_ID:
			return mp(2, Value(t->name));
			break;

		/*  操作符  */
		case TK_PLUS:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '+');  chkOpnd(b, "Right", '+');
			output(c=mp(0, TempVars::getAnother()), a, "+", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_MINUS:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '-');  chkOpnd(b, "Right", '-');
			output(c=mp(0, TempVars::getAnother()), a, "-", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_FACTOR_MINUS:
			a = genCode(t->child[0]);
			chkOpnd(a, "Left", "factor minus operator '-'");
			output(c=mp(0, TempVars::getAnother()), a, "-", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_OR:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '|');  chkOpnd(b, "Right", '|');
			output(c=mp(0, TempVars::getAnother()), a, "|", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		
		case TK_MUL:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '*');  chkOpnd(b, "Right", '*');
			output(c=mp(0, TempVars::getAnother()), a, "*", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_DIV:
			// TO-DO 浮点除
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'DIV'");  chkOpnd(b, "Right", "'DIV'");
			output(c=mp(0, TempVars::getAnother()), a, "DIV", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_MOD:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'MOD'");  chkOpnd(b, "Right", "'MOD'");
			output(c=mp(0, TempVars::getAnother()), a, "MOD", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_AND:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'AND'");  chkOpnd(b, "Right", "'AND'");
			output(c=mp(0, TempVars::getAnother()), a, "AND", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
			
		/*  函数  */
		case TK_FUNC_DECL:
			genCode(t->child[0]);
			genCode(t->child[1]);
			break;
		case TK_FUNC_HEAD:
			a = genCode(t->child[0]);
			a.first!=2 ? throw Error(string(a.second) + "cannot be the name of a function."): 0;
			output("entry" + string(a.second));
			//parameters ignored
			break;
		case TK_PARA:
			throw Error("Wrong syntax tree as it somehow generates illegal 'TK_PARA'");
			break;
		case TK_ROUTINE:
			//routine_head ignored
			genCode(t->child[1], TK_ROUTINE);
			break;
		case TK_ROUTINE_PART:  //routine_body和routine_part都是这个??
			if (faToken == TK_ROUTINE) {  //to generate code of compound_stmt
				if (!t->child[0] || t->child[0]->type!=TK_CP_STMT)
					throw Error("Wrong syntax tree as it somehow generates illegal 't->child[0]->type' under 'TK_ROUTINE->TK_ROUTINE_PART'");
				else
					genCode(t->child[0]);
			}
			else {
				// TO-DO
			}
			break;
		case TK_STMT_LIST:
			if (t->child[0]) {
				genCode(t->child[0]);
				genCode(t->child[1]);
			}
			break;
		case TK_STMT:
			if (t->child[0]->type == TK_INTEGER) {
				a = genCode(t->child[0]);
				a.first!=1||a.second.type!=Value::INTEGER ? throw Error("Wrong syntax tree under TK_STMT, above TK_INTEGER."): 0;
				output("Label L"+string(a.second));
				genCode(t->child[1]);
			}
			else {
				genCode(t->child[0]);
			}
			break;
		case TK_NON_LABEL_STMT:
			genCode(t->child[0]);
			break;
		// case TK_ASSIGN:  //TO-DO
		// 	return ;
		// 	break;
		// case TK_PROC:  //TO-DO  //第一个和第二个，3和4
		// 	switch (t->child[0]->type) {
		// 	case TK_ID:
		// 		if (t->child[1]) {  //zhe yang xie keneng youwenti
		// 		}
		// 		else {
		// 		}
		// 		break;
		// 	default:
		// 		break;
		// 	}
			
		// 	break;
		case TK_CP_STMT:
			return genCode(t->child[0]);
			break;
			
		//procedure??
		
		case TK_SYS_FUNCT:
			break;
		case TK_SYS_TYPE:
			break;
			
		case TK_PROGRAM_HEAD:
			//??
			break;
		case TK_PROGRAM:
			//??
			break;
		case TK_ROUTINE:
			//??
			break;
		case TK_ROUTINE_HEAD:
			//??
			break;
		case TK_CONST_PART:
			//??
			break;
		case TK_CONST_EL:
			//??
			break;
		case TK_GOTO:
			break;
		default:
			break;
		}
	}
	else {
		throw Error("This syntax tree has errors, parsing has to stop.");
		exit(0);
	}
	return mp(-1, 0);
}
