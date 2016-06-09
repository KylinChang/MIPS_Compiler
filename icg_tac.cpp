#include <string>
#include <queue>
#include <sstream>
#include "common.h"
#include "symbolTable.h"
#include "yy.tab.hpp"
#include "icg_tac.h"
using namespace std;

/*
	下面符号，意义和C++中的一样。
		运算符： + - * | & %
		地址操作符(可在赋值号左边或右边)： & *
		< <= > >=
	
	不太一样的操作符：
		DIV					整数除
		/					浮点除
	

	三地址码定义：
		read x					读入变量x
		elem_size(...)			返回变量的本身占用的字节长度
		field_offset(x,a)		返回a变量在x结构中的offset
		malloc a 16				给a数组分配一个16字节的内存
		string s0 "..."			字符串定义

		变量定义(大括号中的项目是必填的)：
			{Type} a {value} local f
			{Type} a {value} global
		目前有的变量定义：
			int, double
	
		得到局部变量i在站上的位置：
			t0 = rsp + ...; 得到i在栈上的位置
			load double t1 t0; t0为地址，t1为该地址取出的double型变量
		load目前有以下几种：
			load int
			load float
			load double
		
		输入输出：
			write
			writeln
		
		
	pascal参数传递顺序：
		1.参数按出现顺序，从左至右地进栈。
    	2.被调用函数在返回调用前负责栈的平衡。
	
	关于常量：
		true和false直接翻译成1、0。
*/

/*
	t2 = a[t1]
	->
		t3 = t1 - {start_position_of(a)};    //这里start_position_of(a)会直接给出一个整数
		t3 = t3 * {elem_size(a)};  //这里elem_size(a)会直接给出一个整数
		t3 = &a + t3
		t2 = *t3


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

Error::Error(string msg):msg(msg) {}

// struct _Value {
// 	enum Type { INTEGER, FLOAT, CHAR, STRING };
// 	int type;
// 	struct Val {
// 		int i;
// 		double d;
// 		char c;
// 		string s;
// 	} val;
// 	_Value():type(-1) {}
// 	_Value(int a):type(INTEGER) { val.i = a; }
// 	_Value(double a):type(FLOAT) { val.d = a; }
// 	_Value(char a):type(CHAR) { val.c = a; }
// 	_Value(string a):type(STRING) { val.s = a; }
// 	_Value(char *a,int d=0):type(STRING) {
// 		val.s = string(a);
// 		if (d) delete a;
// 	}
// };
// inline _Value operator+(const _Value &a, const _Value &b) {
// 	if (a.type == _Value::INTEGER) {
// 		if (b.type == _Value::INTEGER)
// 			return _Value(a.val.i + b.val.i);
// 		else if (b.type == _Value::FLOAT)
// 			return _Value(a.val.i + b.val.d);
// 		else if (b.type == _Value::CHAR)
// 			return _Value(a.val.i + b.val.c);
// 		else //if (b.type == _Value::STRING)
// 			return _Value(a.val.i + b.val.s);
// 	}
// 	else if (a.type == _Value::FLOAT) {
// 		if (b.type == _Value::INTEGER)
// 			return _Value(a.val.d + b.val.i);
// 		else if (b.type == _Value::FLOAT)
// 			return _Value(a.val.d + b.val.d);
// 		else if (b.type == _Value::CHAR)
// 			return _Value(a.val.d + b.val.c);
// 		else //if (b.type == _Value::STRING)
// 			return _Value(a.val.d + b.val.s);
// 	}
// 	else if (a.type == _Value::CHAR) {
// 		if (b.type == _Value::INTEGER)
// 			return _Value(a.val.c + b.val.i);
// 		else if (b.type == _Value::FLOAT)
// 			return _Value(a.val.c + b.val.d);
// 		else if (b.type == _Value::CHAR)
// 			return _Value(a.val.c + b.val.c);
// 		else //if (b.type == _Value::STRING)
// 			return _Value(a.val.c + b.val.s);
// 	}
// 	else if (a.type == _Value::STRING) {
// 		if (b.type == _Value::INTEGER)
// 			return _Value(a.val.s + b.val.i);
// 		else if (b.type == _Value::FLOAT)
// 			return _Value(a.val.s + b.val.d);
// 		else if (b.type == _Value::CHAR)
// 			return _Value(a.val.s + b.val.c);
// 		else //if (b.type == _Value::STRING)
// 			return _Value(a.val.s + b.val.s);
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


_Value::_Value():type(-1) {}
_Value::_Value(int a):type(INTEGER) { val.i = a; }
_Value::_Value(double a):type(FLOAT) { val.d = a; }
_Value::_Value(char a):type(CHAR) { val.c = a; }
_Value::_Value(string a):type(Variable) { val.varName = a; }

_Value::_Value(int a, int d):type(MYINT),i(a) {}
_Value::_Value(char *s, int d):type(MYSTRING),s(s) {}
_Value::_Value(string s, int d) { _Value(s.c_str()); }

_Value::operator string() {
	stringstream ss;
	switch (type) {
		case INTEGER: ss<<val.i; break;
		case FLOAT: ss<<val.d; break;
		case CHAR: ss<<val.c; break;
		//case STRING: ... break;  // TO-DO
		case Variable: ss<<val.varName; break;
		case MYINT: ss<<i; break;
		case MYSTRING: ss<<s; break;
		default: break;
	}
	string s; ss>>s;
	return s;
}
int _Value::toInt() {
	//if (type == INTEGER) return val.i;
	if (type == MYINT) return i;
	throw Error("_Value cast value: Current value is not an integer");
}

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
	static void release(pair<int, _Value> a) {
		if (a.first == 0) release(a.second.toInt());
	}
};
int TempVars::ind = 0;
priority_queue<int, vector<int>, greater<int> > TempVars::idleTemp;

static int stringVars = 0;

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
		return '_' + string(a.second);
	}
	else if (a.first == 3) {  // 字符串常量
		return 's' + string(a.second);
	}
	else if (a.first == 4) {  // 其他情况(不依靠符号表，强行生成代码)
		return a.second;
	}
	else if (a.first == 5) {  // 存储在栈上的局部变量
	//haha
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
void output(piv c, piv a, string op, string b) {
	output(getName(c), getName(a), op, b);
}
void output(piv c, piv a, const char op[], string b) {
	output(getName(c), getName(a), op, b);
}
void output(vector<string> ss) {
	for (int i=0; i<ss.size(); i++)
		printf("%s\n", ss[i].c_str());
}
piv output(NODE *t, piv a) {  //临时变量装载
	// if (a.first != 5) return a;
	// piv t0 = mp(0, TempVars::getAnother()), t1 = mp(0, TempVars::getAnother());
	// t->symbolTable->findFunc();
	
	// output(string(t0.second) + " = bsp - " + ..);  //计算时要注意数组和record的情况，还得判断是不是函数本身
	// output(string("") + "load " + string(t->dataType） + " " + string(t1.second) + " " + string(a.second));
	// TempVars::release(a); return t1;
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
vector<vector<CaseExpr> > CaseParse::scases;
int CaseParse::endLabel;


void chkOpnd(piv a, string side, string op) {
	a.first==-1 ? throw Error(side + " operand of " + op + " cannot be void"): 0; 
}
void chkOpnd(piv a, string side, char op) {
	chkOpnd(a, side, string("") + '\'' + op + '\'');
}

// /*  返回当前的计算值放在哪个临时变量中  **
// **  返回-1表示当前表达式不产生返回值   */
#define SON(d) ((t)->child[(d)])
static piv getTempVar(piv a) {
	if (a.first == 0) return a;
	piv c = mp(0, _Value(TempVars::getAnother()));
	output(c, "=", a);
	return c;
}
extern map<int, string> NODE_NAMES;
piv genCode(NODE *t, int extraMsg) {
	if (t) {
	cout<<NODE_NAMES[t->type]<<endl;
		piv a, b, c;
		piv x, d, tmp;
		int w1, w2, ww;
		switch (t->type) {
		/*  常量  */
		case TK_REAL:
			return mp(1, _Value(t->value.dval));
			break;
		case TK_INTEGER:
			return mp(1, _Value(t->value.ival));
			break;
		case TK_CHAR:
			return mp(1, _Value(t->value.cval));
			break;
		case TK_STRING:
			a = mp(3, _Value(stringVars++));
			output("string " + string(a.second) + " " + "\"" + t->value.sval + "\"");
			return a;
			break;
		case TK_SYS_CON:
			if (t->value.type == type_integer) a = mp(1, _Value(t->value.ival));
			else if (t->value.type == type_real) a = mp(1, _Value(t->value.dval));
			else if (t->value.type == type_boolean) a = mp(1, _Value(t->value.bval));
			else if (t->value.type == type_char) a = mp(1, _Value(t->value.cval));
			return a;
			break;
		case TK_SYS_PROC:
			return mp(4, _Value(t->name, TK_SYS_PROC));
			break;
		case TK_READ:
			return mp(4, _Value(t->name, TK_READ));
			break;
		case TK_TO:
			return mp(4, _Value(t->name, TK_TO));
			break;
		case TK_DOWNTO:
			return mp(4, _Value(t->name, TK_DOWNTO));
			break;
		
		/*  变量  */
		case TK_ID:
			// if (t->symbolTable->nextSymbolTable != nullptr)
			// 	return output(t, mp(5, _Value(t->name)));
			// else
				return mp(2, _Value(t->name));
			break;
			
		/*  变量定义  */
		// case TK_DL:
		// 	for (int i=0; i<child_number; i++)
		// 		genCode(SON(i));
		// 	break;
		// case TK_VAR_DECL:
		// 	genCode(SON(0));
		// 	break;
		// //name_list
		// case TK_NL:  //默认已经知道type了
		// 	for (int i=0; i<child_number; i++)
		// 		output(string(t->dataType) + "" + string(genCode(SON(i)).second));
		// 	break;

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
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'DIV'");  chkOpnd(b, "Right", "'DIV'");
			output(c=mp(0, TempVars::getAnother()), a, "DIV", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_REM:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			output(c=mp(0, TempVars::getAnother()), a, "/", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_MOD:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'MOD'");  chkOpnd(b, "%", "'MOD'");
			output(c=mp(0, TempVars::getAnother()), a, "%", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_AND:
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'AND'");  chkOpnd(b, "Right", "'AND'");
			output(c=mp(0, TempVars::getAnother()), a, "&", b);  // TO-DO a=a+b??
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
			output("entry " + string(a.second));
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
			for (int i=0; i<t->child_number; i++)
				genCode(SON(i));
			break;
		case TK_STMT_LABEL:  /*  stmt其实不需要一个返回值  */
			a = genCode(t->child[0]);
			a.first!=1||a.second.type!=_Value::INTEGER ? throw Error("Wrong syntax tree under TK_STMT, above TK_INTEGER"): 0;
			output("Label LUER" + string(a.second));
			return genCode(t->child[1]);
			break;
		case TK_STMT:
			return genCode(t->child[0]);
			break;
		//assign_stmt
		case TK_STMT_ASSIGN:
			genCode(SON(0));
			break;
		case TK_ASSIGN_ID:
			c = genCode(SON(0)); a = genCode(SON(1));
			cout<<NODE_NAMES[t->type]<<" back"<<endl;
			c.first!=2 ? throw Error("L-value must be a changeable variable"): 0;
			a.first==-1 ? throw Error("R-value must not be empty"): 0;
			output(c, "=", a);
			TempVars::release(a); return c;
			break;
		case TK_ASSIGN_ID_EXPR:  //TO-DO  P321 数组计算的时候还要考虑lower_bound
			a = genCode(SON(0));  b = genCode(SON(1));  x = genCode(SON(1));
			output(tmp, b, "-", string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.start)));
			//output(string((d=mp(0, TempVars::getAnother())).second) + " = " + string(tmp.second) + " * " + "elem_size(" + string(a.second) + ")");
			output(string((tmp=mp(0, TempVars::getAnother())).second)
							+ " = " + string(tmp.second)
								+ " * " + string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.elementSize)));  //t3 = t1 * {elem_size(a)};可以优化掉t3  TO-DO
			output(string(tmp.second) + " = &" + string(a.second) + " + " + string(tmp.second));
			output("*" + string(tmp.second) + " = " + string(x.second));
			output(string((c=mp(0, TempVars::getAnother())).second) + " = *" + string(tmp.second));
			TempVars::release(b); TempVars::release(x); TempVars::release(tmp); return c;
			break;
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
			output("goto LUER" + toString(t->value.ival));
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
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, ">=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_GT:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, ">", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_LE:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, "<=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_LT:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, "<", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_EQUAL:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, "==", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_UNEQUAL:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother()), a, "!=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_EXP:
			return genCode(SON(0));
			break;
		
		//expr
		case TK_EXPR:
			return genCode(SON(0));
			break;
		
		//term  //TO-DO
		case TK_TERM:
			return genCode(SON(0));
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
			TempVars::release(a);  return tmp;
			break;
		case TK_FACTOR_MINUS:
			a = genCode(SON(0));
			output(tmp=mp(0, TempVars::getAnother()), "= -", a);
			TempVars::release(a);  return tmp;
			break;
		case TK_FACTOR_ID_EXP:
			a = genCode(SON(0));  b = genCode(SON(1));
			output(tmp, b, "-", string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.start)));
			//output(string((d=mp(0, TempVars::getAnother())).second) + " = " + string(tmp.second) + " * " + "elem_size(" + string(a.second) + ")");
			output(string((tmp=mp(0, TempVars::getAnother())).second)
							+ " = " + string(tmp.second)
								+ " * " + string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.elementSize)));  //t3 = t1 * {elem_size(a)};可以优化掉t3  TO-DO
			output(string(tmp.second) + " = &" + string(a.second) + " + " + string(tmp.second));
			output(string((c=mp(0, TempVars::getAnother())).second) + " = *" + string(tmp.second));
			TempVars::release(b); TempVars::release(tmp); return c;
			break;
		case TK_FACTOR_DD:
			// TO-DO
			break;
			
		//procedure??
		
		case TK_SYS_FUNCT:
			break;
		case TK_SYS_TYPE:
			break;
			
		case TK_PROGRAM:
			genCode(SON(1));
			//暂时不做处理
			break;
		case TK_PROGRAM_HEAD:
			//暂时不做处理
			break;
		case TK_ROUTINE_HEAD:
			//??
			break;
		case TK_CONST_PART:
			//??
			break;
		default:
			break;
		}
		cout<<NODE_NAMES[t->type]<<" back"<<endl;
	}
	else {
		throw Error("Unexpected null pointer of the syntax tree, parsing has to stop.");
		exit(0);
	}
	return mp(-1, 0);
}
