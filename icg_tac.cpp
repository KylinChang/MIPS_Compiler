#include <string>
#include <queue>
#include <sstream>
#include "common.h"
#include "yy.tab.hpp"
using namespace std;

/*
	下面符号，意义和C++中的一样。
		+ - * /
		地址操作符(可在赋值号左边或右边)： & *
		< <= > >=

	read x				读入整数x
	elem_size(...)		返回变量的本身占用的字节长度
	field_offset(x,a)	返回a变量在x结构中的offset
		
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
		<code for S>
		goto L1
		label L2
	
	
	repeat S until E
	->
		label L1
		<code for S>
		a = result<code for expression>
		if_false a goto L1


	for x:=A direction B do
		stmt
	->
		a = <code for calculate A>
		b = <code for calculate B>
		x = a;
		
		/ to -> d=1
		\ downto -> d=-1
		
		while (x!=b) {
			stmt;
			x=x+d;
		}
		while (X==b) {
			stmt;
			x=x+d;
		}
	
	
	case E of
		a1: S1;
		a2: S2;
		...
	end;
	->
		x = <code for calculate E>
		goto L..1(CaseTable)
		
		L1: S1
		goto L..2(CaseEnd)
		->
			Label L1
			<code for S1>
			goto L..2(CaseEnd)
		
		L2: S2
		goto L..2(CaseEnd)
		...
		
		
		L..1(CaseTable)
		if E==a1 then goto L1
		->
		
		if E==a2 then goto L2
		...
		
		L..2(CaseEnd)
*/

/*
	Temp Note:
		procedure是没有返回值的函数，function是有返回值的函数。而且procedure可以在没有参数的时候不使用括号调用。
		function_head + routine 约等于 function
	
		注意！所有涉及到计算的地方都应该check一遍是否有release临时变量。
*/

#define mp make_pair

struct Error {
	string msg;
	Error(string msg):msg(msg) {}
};

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
inline string operator+(const int &a, const string &b) {
	stringstream ss;
	string c;
	ss<<a; ss>>c;
	return c+b;
}
inline string operator+(const string &a, const int &b) {
	return b+a;
}
inline string operator+(const double &a, const string &b) {
	stringstream ss;
	string c;
	ss<<a; ss>>c;
	return c+b;
}
inline string operator+(const string &a, const double &b) {
	return b+a;
}
string toString(int a) {
	stringstream ss;
	string s;
	ss<<a; ss>>s;
	return s;
}

struct Value {
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
		string var;
	} val;
	int i;
	string s;
	Value():type(-1) {}
	Value(int a):type(INTEGER) { val.i = a; }
	Value(double a):type(FLOAT) { val.d = a; }
	Value(char a):type(CHAR) { val.c = a; }
	Value(string a):type(Variable) { val.var = a; }
	
	Value(int a, int d):type(MYINT),i(a) {}
	Value(char *s, int d):type(MYSTRING),s(s) {}
	Value(string s, int d) { Value(s.c_str()); }
	
	operator string() {
		stringstream ss;
		switch (type) {
			case INTEGER: ss<<val.i; break;
			case FLOAT: ss<<val.d; break;
			case CHAR: ss<<val.c; break;
			//case STRING: ... break;  // TO-DO
			case Variable: ss<<val.var; break;
			case MYINT: ss<<i; break;
			case MYSTRING: ss<<s; break;
			default: break;
		}
		string s; ss>>s;
		return s;
	}
	int toInt() {
		//if (type == INTEGER) return val.i;
		if (type == MYINT) return i;
		throw Error("Value cast value: Current value is not an integer");
	}
};
typedef pair<int, Value> piv;


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
	static void release(pair<int, Value> a) {
		if (a.first == 0) release(a.second.toInt());
	}
};
int TempVars::ind = 0;

struct Label {
	static int ind;
	static int newLabel() { return ind++; }
};
int Label::ind = 0;

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
	else if (a.first == 4) {  // 其他情况(不依靠符号表，强行生成代码)
	}
}
void output(string s) {
	printf("%s\n", s.c_str());
}
void output(string c, string op, string a) {
	printf("%s %s %s\n", c.c_str(), op.c_str(), a.c_str());
}
void output(piv c, string op, piv a) {
	output(getName(c), op, getName(a));
}
void output(string c, string a, string op, string b) {
	printf("%s = %s %s %s\n", c.c_str(), a.c_str(), op.c_str(), b.c_str());
}
void output(piv c, piv a, string op, piv b) {
	output(getName(c), getName(a), op, getName(b));
}
void output(vector<string> ss) {
	for (int i=0; i<ss.size(); i++)
		printf("%s\n", ss[i].c_str());
}
string _output(string s) {  //没有自带回车
	return s;
}
string _output(string c, string op, string a) {
	return c + " " + op + " " + a;
}
string _output(piv c, string op, piv a) {
	return _output(getName(c), op, getName(a));
}
string _output(string c, string a, string op, string b) {
	return c + " = " + a + " " + op + " " + b;
}
string _output(piv c, piv a, string op, piv b) {
	return _output(getName(c), getName(a), op, getName(b));
}


struct CaseExpr {
	piv a;
	int label;
	CaseExpr() {}
	CaseExpr(piv a, int label):a(a), label(label) {}
};
struct CaseParse {
	// static piv E;
	static vector<vector<CaseExpr> > scases;
	static int endLabel;
	
	// static void setE(piv e) { E = e; }
	// static piv getE() { return E; }
	static void setEndLabel(int a) { endLabel = a; }
	static int getEndLabel() { return endLabel; }
	
	static void addNew() { scases.push_back(vector<CaseExpr>()); }
	static vector<string> pop(piv E) {
		if (scases.size() == 0) throw Error("Unexpected end of 'switch..case'");
		vector<string> ret;
		vector<CaseExpr> &cases = *scases.rbegin();
		for (int i=0; i<cases.size(); i++)
			ret.push_back("if " + string(E.second) + "==" + string(cases[i].a.second) + " then goto L" + toString(cases[i].label));
		scases.pop_back();
		return ret;
	}
	
	static void addCase(piv a, int label) {
		if (scases.size() == 0) throw Error("Unexpected case of 'switch..case'");
		scases[scases.size() - 1].push_back(CaseExpr(a, label));
	}
};



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
#define SON(d) ((t)->child[(d)])
static piv getTempVar(piv a) {
	if (a.first == 0) return a;
	piv c = mp(0, Value(TempVars::getAnother()));
	output(c, "=", a);
	return c;
}
piv genCode(NODE *t, int extraMsg=-1) {
	if (t) {
		piv a, b, c;
		piv x, d, tmp;
		int w1, w2, ww;
		switch (t->type) {
		/*  常量  */
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
		// 	return mp(1, );
		// 	break;
		case TK_SYS_PROC:
			return mp(4, Value(t->name, TK_SYS_PROC));
			break;
		case TK_READ:
			return mp(4, Value(t->name, TK_READ));
			break;
		case TK_TO:
			return mp(4, Value(t->name, TK_TO));
			break;
		case TK_DOWNTO:
			return mp(4, Value(t->name, TK_DOWNTO));
			break;
		
		/*  变量  */
		case TK_ID:
			return mp(2, Value(t->name));  //TO-DO 目前还不知道是哪种变量
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
			//TO-DO output("return" ...); (要用到符号表里的变量吧)(检查某变量是否有被用到过，以确定是否有返回值)
			break;
		case TK_ROUTINE_PART:  //routine_body和routine_part都是这个??
			if (extraMsg == TK_ROUTINE) {  //to generate code of compound_stmt
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
				return genCode(t->child[1]);
			}
			break;
		case TK_STMT_LABEL:  /*  stmt其实不需要一个返回值  */
			a = genCode(t->child[0]);
			a.first!=1||a.second.type!=Value::INTEGER ? throw Error("Wrong syntax tree under TK_STMT, above TK_INTEGER"): 0;
			output("Label LUER" + string(a.second));
			return genCode(t->child[1]);
			break;
		case TK_STMT:
			return genCode(t->child[0]);
			break;
		case TK_ASSIGN_ID:
			c = genCode(SON(0)); a = genCode(SON(1));
			c.first!=2 ? throw Error("L-value must be a changeable variable"): 0;
			a.first==-1 ? throw Error("R-value must not be empty"): 0;
			output(c, "=", a);
			TempVars::release(a); return c;
			break;
		// case TK_ASSIGN_ID_EXPR:  //TO-DO  P321 数组计算的时候还要考虑lower_bound
		// 	c = genCode(SON(0)); b = genCode (SON(1)); a = genCode (SON(2));
		// 	b = getTempVar(b);
		// 	//TempVars::release(a); TempVars::release(b); TempVars::release(c);
		// 	break;
		// case TK_ASSIGN_DD:  //TO-DO
		// 	break;
		
		//proc_stmt (procedure没有返回值)
		case TK_PROC_ID:  //a因为是变量所以不用release
			a = genCode(SON(0));
			output("begin_args");
			output("call " + string(a.second));
			break;
		case TK_PROC_ID_ARGS:
			a = genCode(SON(0));
			output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + string(a.second));
			break;
		
		//SYS_PROC
		case TK_PROC_SYS:
			a = genCode(SON(0));
			output("begin_args");
			output("call " + string(a.second));
			break;
		case TK_PROC_SYS_ARGS:
			a = genCode(SON(0));
			output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + string(a.second));
			break;
		
		//TK_READ
		// case TK_PROC_READ:  //TO-DO 应该只有ID而不是factor可以read??先当成单个ID来做
		// 	a = genCode(SON(0));
		// 	b = genCode(SON(1));
		// 	switch (getType(b.second.val.var)) {  //TO-DO 从符号表里得到variable的类型
		// 	}
		// 	output("begin_args");
		// 	break;
		
		//compound_stmt
		case TK_CP_STMT:
			return genCode(SON(0));
			break;
		
		//if_stmt
		case TK_IF:
			a = genCode(SON(0));
			output("if_false " + string(a.second) + " goto L" + toString(w1=Label::newLabel()));
			TempVars::release(a); TempVars::release(genCode(SON(1)));
			output("goto L" + toString(w2=Label::newLabel()));
			output("label L" + toString(w1));
			TempVars::release(genCode(SON(2)));  //可以优化(不一定有else)
			output("label L" + toString(w2));
			break;
		case TK_ELSE:
			if (SON(0)) TempVars::release(genCode(SON(0)));
			break;
		
		//repeat_stmt
		case TK_REPEAT:
			output("label L" + toString(w1=Label::newLabel()));
			genCode(SON(0));
			a = genCode(SON(1));
			output("if_false " + string(a.second) + " goto L" + toString(w1));
			TempVars::release(a);
			break;
		//while_stmt
		case TK_WHILE:
			output("label L" + toString(w1=Label::newLabel()));
			a = genCode(SON(0));
			output("if_false " + string(a.second) + " goto L" + toString(w2=Label::newLabel()));
			genCode(SON(1));
			output("goto L" + toString(w1));
			output("label L" + toString(w2));
			TempVars::release(a);
			break;
		//for_stmt
		case TK_FOR:  //TO-DO 结构体的单增、单减
			x = genCode(SON(0));  a = genCode(SON(1));  b = genCode(SON(3));
			output(x, "=", a);
			
			// / to -> d=1
			// \ downto -> d=-1
				tmp = genCode(SON(2));
				if (string(tmp.second) == "TO")
					output(d=mp(0, TempVars::getAnother()), "=", mp(1, 1));
				else
					output(d=mp(0, TempVars::getAnother()), "=", mp(1, -1));
				TempVars::release(tmp);
				
			//while (x!=b) { stmt; x=x+d; }
				output("label L" + toString(w1=Label::newLabel()));
				output(tmp=mp(0, TempVars::getAnother()), x, "!=", b);
				output("if_false " + string(tmp.second) + " goto L" + toString(w2=Label::newLabel()));
				genCode(SON(4)); output(x, x, "+", d);
				output("goto L" + toString(w1));
				output("label L" + toString(w2));
				TempVars::release(tmp);
				
			//while (x==b) { stmt; x=x+d; }
				output("label L" + toString(w1=Label::newLabel()));
				output(tmp=mp(0, TempVars::getAnother()), x, "==", b);
				output("if_false " + string(tmp.second) + " goto L" + toString(w2=Label::newLabel()));
				genCode(SON(4)); output(x, x, "+", d);
				output("goto L" + toString(w1));
				output("label L" + toString(w2));
				TempVars::release(tmp);
		
			TempVars::release(a); TempVars::release(b);
			break;
		//case_stmt
		case TK_CASE:
			CaseParse::addNew();
			a = genCode(SON(0));  //CaseParse::setE(a);
			output("goto L" + toString(w1=Label::newLabel()));
			CaseParse::setEndLabel(w2=Label::newLabel());
			
			genCode(SON(1));
			
			output("label L" + toString(w1));
			output(CaseParse::pop(a));
			output("label L" + toString(w2));
			break;
		//case_expr_list
		case TK_CASE_EL:
			for (int i=0; i<t->child_number; i++)
				genCode(SON(i));
			break;
		//case_expr
		case TK_CASE_EXPR: case TK_CASE_EXPR_END:
			a = genCode(SON(0));
			output("Label L" + toString(ww=Label::newLabel()));
			genCode(SON(1));
			output("goto L" + CaseParse::getEndLabel());
			CaseParse::addCase(a, ww);
			break;
		//goto_stmt
		case TK_GOTO:
			output("goto LUER" + toString(t->ival));
			break;
			
		//args_list
		// case TK_ARGS_LIST_COMMA:
		// 	genCode(SON(0));
		// 	a = genCode(SON(1));
		// 	output("arg " + string(a.second));
		// 	if (a.first == 0) TempVars::release(a);
		// 	break;
		case TK_ARGS_LIST:
			for (int i=0; i<t->child_number; i++) {
				a = genCode(SON(i));
				output("arg " + string(a.second));
				if (a.first == 0) TempVars::release(a);
			}
			break;
			
		//expression_list
		// case TK_EXP_LIST_COMMA:
		// 	genCode(SON(0));
		// 	a = genCode(SON(1));
		// 	output("arg " + string(a.second));
		// 	if (a.first == 0) TempVars::release(a);
		// 	break;
		case TK_EXP_LIST:
			for (int i=0; i<t->child_number; i++) {
				a = genCode(SON(i));
				output("arg " + string(a.second));
				if (a.first == 0) TempVars::release(a);
			}
			break;
		
		//expression  //TO-DO
		case TK_GE:
			a = genCode(SON(0));
			if (SON(1)) b = genCode(SON(1));
			break;
		case TK_GT:
			break;
		case TK_LE:
			break;
		case TK_LT:
			break;
		case TK_EQUAL:
			break;
		case TK_UNEQUAL:
			break;
		case TK_EXP:
			break;
		
		//expr  //TO-DO
		case TK_PLUS:
			break;
		case TK_MINUS:
			break;
		case TK_OR:
			break;
		case TK_EXPR:
			break;
		
		//term  //TO-DO
		case TK_MUL:
			break;
		case TK_DIV:
			break;
		case TK_MOD:
			break;
		case TK_AND:
			break;
		case TK_TERM:
			break;
		
		//factor
		case TK_FACTOR_ID:
			return genCode(SON(0));
			break;
		case TK_FACTOR_ID_ARGS:
			a = genCode(SON(0));
			output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + string(a.second));
			//返回值?? TO-DO
			break;
		case TK_FACTOR_SYS_FUNCT:
			a = genCode(SON(0));
			output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + string(a.second));
			//返回值?? TO-DO
			break;
		case TK_FACTOR_CONST:
			return genCode(SON(0));
			break;
		case TK_FACTOR_EXP:
			return genCode(SON(0));
			break;
		case TK_FACTOR_NOT:
			a = genCode(SON(0));
			output(tmp=mp(0, TempVars::getAnother()), "= NOT", a);
			TempVars::release(a);
			break;
		case TK_FACTOR_MINUS:
			a = genCode(SON(0));
			output(tmp=mp(0, TempVars::getAnother()), "= -", a);
			TempVars::release(a);
			break;
		case TK_FACTOR_ID_EXP:
			//需要得到数组的每个元素的字节长度 TO-DO
			break;
		case TK_FACTOR_DD:
			//?? TO-DO
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
		case TK_ROUTINE_HEAD:
			//??
			break;
		case TK_CONST_PART:
			//??
			break;
		case TK_CONST_EL:
			//??
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
