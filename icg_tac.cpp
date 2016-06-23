#include <string>
#include <queue>
#include <sstream>
#include "common.h"
#include "symbolTable.h"
#include "yy.tab.hpp"
#include "icg_tac.h"
using namespace std;

static const bool ICG_DEBUG = 0;
void outDebug(string str="") { cout<<("***********************" + str + "****************************")<<endl; }
#define dbg(x) cout<<#x<<" = "<<x<<endl

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
		field_offset(x,a)		返回a变量在x结构中的offset
		malloc a 16				给a数组分配一个16字节的内存
		string s0 "..."			字符串定义

		变量定义(大括号中的项目是必填的)：
			{Type} a {value} local f
			{Type} a {value} global
		目前有的变量定义：
			int, double
			
		关于栈：
			bp					Control Link
			sp					栈指针
	
		得到局部变量i在站上的位置：
			t0 = bp - ...; 得到i在栈上的位置

		
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
string toString(int a) {
	stringstream ss;
	string s;
	ss<<a; ss>>s;
	return s;
}
string toString(double a) {
	stringstream ss;
	string s;
	ss<<a; ss>>s;
	return s;
}
inline string operator+(const int &a, const string &b) {
	return toString(a) + b;
}
inline string operator+(const string &a, const int &b) {
	return a + toString(b);
}
inline string operator+(const double &a, const string &b) {
	stringstream ss;
	string c;
	ss<<a; ss>>c;
	return c+b;
}
inline string operator+(const string &a, const double &b) {
	stringstream ss;
	string c;
	ss<<b; ss>>c;
	return a+c;
}


_Value::_Value():type(-1) {}
_Value::_Value(int a):type(INTEGER) { val.i = a; }
_Value::_Value(double a):type(FLOAT) { val.d = a; }
_Value::_Value(char a):type(CHAR) { val.c = a; }
_Value::_Value(string a):type(Variable) { val.varName = a; }
_Value::_Value(int a, string pt):type(POINT), pt(pt) { val.i = a; }

_Value::_Value(int a, int d):type(MYINT),i(a) {}
_Value::_Value(char *s, int d):type(MYSTRING), s(s) { i = d; }
_Value::_Value(string s, int d):type(MYSTRING), s(s) { i = d; }

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
		case POINT: ss<<val.i; break;
		default: break;
	}
	string s; ss>>s;
	return s;
}
int _Value::toInt() {
	if (type == INTEGER) return val.i;
	if (type == POINT) return val.i;
	if (type == CHAR) return val.c;
	if (type == MYINT) return i;
	throw Error("_Value cast value: Current value is not an integer");
}
double _Value::toFloat() {
	if (type == INTEGER) return val.i;
	if (type == POINT) return val.i;
	if (type == CHAR) return val.c;
	if (type == FLOAT) return val.d;
	if (type == MYINT) return i;
	throw Error("_Value cast value: Current value is not a float point number");
}
string _Value::getType() {
	if (type == INTEGER) return "int";
	if (type == FLOAT) return "float";
	if (type == CHAR) return "char";
	// if (type == STRING) return "string";
	if (type == POINT) return pt;
	//if (type == Variable) return ??;
	assert(0);
}
_Value operator+(_Value a, _Value b) {  //注意：这里的Variable其实就是String常量, vanName指代里面保存的字符串常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() + b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() + b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(a.toInt() + b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(a.toFloat() + b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(b.toInt() + a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(b.toFloat() + a.val.varName);
	}
	else {
		return a.val.varName + b.val.varName;
	}
}
_Value operator-(_Value a, _Value b) {  //注意：这里的Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() - b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() - b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
		// return a.val.varName + b.val.varName;
	}
}
_Value operator|(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() | b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator*(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() * b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() * b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value _Value::div(_Value b) {
	_Value a = *this;
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() / b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator/(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() *1.0/ b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() / b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator%(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() % b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator&(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() & b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (a.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		throw Error("Wrong Operation.");
	}
	else if (b.type == _Value::FLOAT) {
		throw Error("Wrong Operation.");
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator>=(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() >= b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() >= b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) >= b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) >= b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) >= a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) >= a.val.varName);
	}
	else {
		return a.val.varName >= b.val.varName;
	}
}
_Value operator>(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() > b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() > b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) > b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) > b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) > a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) > a.val.varName);
	}
	else {
		return a.val.varName > b.val.varName;
	}
}
_Value operator<=(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() <= b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() <= b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) <= b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) <= b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) <= a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) <= a.val.varName);
	}
	else {
		return a.val.varName <= b.val.varName;
	}
}
_Value operator<(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() < b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() < b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) < b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) < b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) < a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) < a.val.varName);
	}
	else {
		return a.val.varName < b.val.varName;
	}
}
_Value operator==(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() == b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() == b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) == b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) == b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) == a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) == a.val.varName);
	}
	else {
		return a.val.varName == b.val.varName;
	}
}
_Value operator!=(_Value a, _Value b) {  //注意：这里的_Value::Variable其实就是String常量
	if ((a.type == _Value::INTEGER || a.type == _Value::CHAR) && (b.type == _Value::INTEGER || b.type == _Value::CHAR)) {
		return _Value(a.toInt() != b.toInt());
	}
	else if ((a.type == _Value::FLOAT && b.type != _Value::Variable) || (b.type == _Value::FLOAT && a.type != _Value::Variable)) {
		return _Value(a.toFloat() != b.toFloat());
	}
	else if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(toString(a.toInt()) != b.val.varName);
	}
	else if (a.type == _Value::FLOAT) {
		return _Value(toString(a.toFloat()) != b.val.varName);
	}
	else if (b.type == _Value::INTEGER || b.type == _Value::CHAR) {
		return _Value(toString(b.toInt()) != a.val.varName);
	}
	else if (b.type == _Value::FLOAT) {
		return _Value(toString(b.toFloat()) != a.val.varName);
	}
	else {
		return a.val.varName != b.val.varName;
	}
}
_Value operator~(_Value a) {  //注意：这里的_Value::Variable其实就是String常量
	if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(~a.toInt());
	}
	else {
		throw Error("Wrong Operation.");
	}
}
_Value operator-(_Value a) {  //注意：这里的_Value::Variable其实就是String常量
	if (a.type == _Value::INTEGER || a.type == _Value::CHAR) {
		return _Value(~a.toInt());
	}
	else {
		throw Error("Wrong Operation.");
	}
}

bool isTempVar(piv a) {
	return a.first == 0 || a.first == 6;
}
void output(string s);
struct TempVars {
	static int ind;
	static priority_queue<int, vector<int>, greater<int> > idleTemp;  // 注意别用size()来判断是否empty，用empty()
	static int getAnother(string type) {
		int ret;
		if (idleTemp.empty()) {
			ret = ind++;
		}
		else {
			ret = idleTemp.top();
			idleTemp.pop();
		}
		if (type.find("point") == string::npos)
			output("var " + type + " t" + string(_Value(ret)));
		else
			output(type + " t" + string(_Value(ret)));
		return ret;
	}
	static void release(int TempVar) {
		idleTemp.push(TempVar);
	}
	static void release(pair<int, _Value> a) {
		if (isTempVar(a)) release(a.second.toInt());
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
	//此类型肯定在输出前会转为类型6
	}
	else if (a.first == 6) {  // 指向某个内存的指针，但是要当引用来用
		return "*t" + string(a.second);
	}
}

static string indent;
void moreIndent() {
	//indent+="\t";
}
void lessIndent() {
	//indent = indent.substr(0, indent.size()-1);
}

void output(string s) {
	printf("%s%s\n", indent.c_str(), s.c_str());
}
void output(string c, string op, string a) {
	printf("%s%s %s %s\n", indent.c_str(), c.c_str(), op.c_str(), a.c_str());
}
void output(piv c, string op, piv a) {
	output(getName(c), op, getName(a));
}
void output(string c, string a, string op, string b) {
	printf("%s%s = %s %s %s\n", indent.c_str(), c.c_str(), a.c_str(), op.c_str(), b.c_str());
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
	for (int i=0; i<ss.size(); i++) output(ss[i]);
}
piv output(NODE *t, piv a) {  //临时变量装载(TO-DO 函数参数的offset计算）
	if (a.first != 5) return a;
	string varName = string(a.second);
	auto st = t->symbolTable;
	// outDebug();
	// cout<<(st->funcSymbolTable.find(varName) == st->funcSymbolTable.end())<<" "<<varName<<endl;
	if (st->funcSymbolTable.find(varName) == st->funcSymbolTable.end()) {
		bool flag = 0;
		int offset = 0;
		for (int i=0; i<st->varSequence.size(); i++) {
			if (varName == st->varSequence[i]) {
				flag = 1;
				break;
			}
		}
		// dbg(flag);
		if (flag) {  //函数内部局部变量
			// dbg(semanticAnalysisError);
			for (int i=0; i<st->varSequence.size(); i++) {
				offset += st->varSymbolTable[st->varSequence[i]].size();
				if (varName == st->varSequence[i])
					break;
			}
			if (!st->varSymbolTable[varName].isSimpleType) {
				piv t0 = mp(6, _Value(TempVars::getAnother("point record")));
				output(getName(mp(0, t0.second)) + " = bp - " + string(_Value(offset)));
				return t0;
			}
			piv t0 = mp(6, _Value(TempVars::getAnother("point " + string(st->varSymbolTable[varName])), string(st->varSymbolTable[varName])));  //--  //, t1 = mp(0, TempVars::getAnother());
			output(getName(mp(0, t0.second)) + " = bp - " + string(_Value(offset)));  //计算时要注意数组和record的情况，还得判断是不是函数本身
			//output(string("") + "load " + string(st->varSymbolTable[varName]) + " " + getName(t1) + " " + getName(t0));
			TempVars::release(a); return t0;
		}
		else {  //函数参数
			// outDebug("wahaha");
			for (int i=st->paraSequence.size()-1; i>=0; i--) {
				if (varName == st->paraSequence[i])
					break;
				offset += st->varSymbolTable[st->paraSequence[i]].size();
			}
			piv t0 = mp(6, _Value(TempVars::getAnother("point " + string(st->varSymbolTable[varName])), string(st->varSymbolTable[varName])));
			output(getName(mp(0, t0.second)) + " = bp + " + string(_Value(offset + 8)));  //需要保存bp和ra，所以要+8  //计算时要注意数组和record的情况，还得判断是不是函数本身
			//output(string("") + "load " + string(st->varSymbolTable[varName]) + " " + getName(t1) + " " + getName(a));
			TempVars::release(a); return t0;
		}
	}
	else {  //函数名
		// dbg(string(a.second));
		// dbg(st->findVar(varName).null);
		// dbg(st->findFunc(varName).complexType);
		piv t0 = mp(2, _Value(string(a.second), st->findFunc(varName).complexType->complexType == type_func));  //TO-DO 还需要知道这个函数的返回值大小
		TempVars::release(a);
		return t0;
	}
	return a;
}
string _output(string s) {  //没有自带回车
	return indent+ s;
}
string _output(string c, string op, string a) {
	return indent+ c + " " + op + " " + a;
}
string _output(piv c, string op, piv a) {
	return _output(getName(c), op, getName(a));
}
string _output(string c, string a, string op, string b) {
	return indent+ c + " = " + a + " " + op + " " + b;
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
	static vector<vector<CaseExpr> > scases;
	static int endLabel;
	
	static void setEndLabel(int a) { endLabel = a; }
	static int getEndLabel() { return endLabel; }
	
	static void addNew() { scases.push_back(vector<CaseExpr>()); }
	static vector<string> pop(piv E) {
		if (scases.size() == 0) throw Error("Unexpected end of 'switch..case'");
		vector<string> ret;
		vector<CaseExpr> &cases = *scases.rbegin();
		for (int i=0; i<cases.size(); i++)
			ret.push_back("if " + getName(E) + " == " + getName(cases[i].a) + " then goto L" + toString(cases[i].label));
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

/*  返回当前的计算值放在哪个临时变量中  **
**  返回-1表示当前表达式不产生返回值   */
#define SON(d) ((t)->child[(d)])
static piv getTempVar(piv a) {
	if (isTempVar(a)) return a;
	piv c = mp(0, _Value(TempVars::getAnother(a.second.getType())));
	output(c, "=", a);
	return c;
}
static piv getReturnNum(Type type, int size) {
	piv a, b;
	output(getName(a=mp(0, TempVars::getAnother(string("point ") + string(type)))) + " = sp - " + string(_Value(size)));
	output(getName(b=mp(0, TempVars::getAnother(type))) + " = *t" + string(a.second));
	TempVars::release(a); return b;
}
extern map<int, string> NODE_NAMES;
int calSize(vector<Type> a) {
	int ret = 0;
	for (auto t:a) ret+=t.size();
	return ret;
}
int calSize(vector<Type> a, vector<bool> b) {
	int ret = 0;
	for (int i=0; i<(int)a.size(); i++)
		ret += b[i]==1 ? 4 : a[i].size();
	return ret;
}
int calSize(FPType a) {
	return calSize(a.argTypeList, a.argVarList) + a.retType.size();
}
int calSize(unordered_map<string, Type> a) {
	int ret = 0;
	for (auto t:a) ret+=t.second.size();
	return ret;
}
int calSize(vector<string> vars, unordered_map<string, Type> a) {
	int ret = 0;
	for (auto t:vars) ret+=a[t].size();
	return ret;
}

static string sysproc;
// bool constVar(int type) {
// 	return type == REAL
// 		|| type == TK_INTEGER
// 		|| type == TK_CHAR
// 		|| type == TK_STRING
// 		|| type == TK_SYS_CON;
// }
pair<bool, _Value> testOptimize(NODE *t) {
	// cout<<NODE_NAMES[t->type]<<endl;
	if (t) {
		pair<bool, _Value> a, b;
		switch (t->type) {
		case TK_REAL:
			return mp(true, _Value(t->value.dval));
			break;
		case TK_INTEGER:
			return mp(true, _Value(t->value.ival));
			break;
		case TK_CHAR:
			return mp(true, _Value(t->value.cval));
			break;
		case TK_STRING:
			return mp(true, _Value(t->value.sval));  //?? TO-DO
			break;
		case TK_SYS_CON:
			if (t->value.type == type_integer) a = mp(true, _Value(t->value.ival));
			else if (t->value.type == type_real) a = mp(true, _Value(t->value.dval));
			else if (t->value.type == type_boolean) a = mp(true, _Value(t->value.bval));
			else if (t->value.type == type_char) a = mp(true, _Value(t->value.cval));
			return mp(false, _Value());
			break;
		
		case TK_EXPR:
			return testOptimize(SON(0));
			break;
		case TK_TERM:
			return testOptimize(SON(0));
			break;
		case TK_EXP:
			return testOptimize(SON(0));
			break;
		case TK_FACTOR_EXP:
			return testOptimize(SON(0));
			break;
		case TK_FACTOR_CONST:
			return testOptimize(SON(0));
			break;

		
		case TK_PLUS:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second + b.second);
			return mp(false, _Value());
			break;
		case TK_MINUS:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second - b.second);
			return mp(false, _Value());
			break;
		case TK_OR:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second | b.second);
			return mp(false, _Value());
			break;
		case TK_MUL:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second * b.second);
			return mp(false, _Value());
			break;
		case TK_DIV:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second.div(b.second));
			return mp(false, _Value());
			break;
		case TK_REM:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second / b.second);
			return mp(false, _Value());
			break;
		case TK_MOD:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second % b.second);
			return mp(false, _Value());
			break;
		case TK_AND:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second & b.second);
			return mp(false, _Value());
			break;
		
		case TK_GE:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second >= b.second);
			return mp(false, _Value());
			break;
		case TK_GT:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second > b.second);
			return mp(false, _Value());
			break;
		case TK_LE:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second <= b.second);
			return mp(false, _Value());
			break;
		case TK_LT:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second < b.second);
			return mp(false, _Value());
			break;
		case TK_EQUAL:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second == b.second);
			return mp(false, _Value());
			break;
		case TK_UNEQUAL:
			a = testOptimize(SON(0)), b = testOptimize(SON(1));
			if (a.first & b.first) return mp(true, a.second != b.second);
			return mp(false, _Value());
			break;

		case TK_FACTOR_NOT:
			a = testOptimize(SON(0));
			if (a.first) return mp(true, ~a.second);
			return mp(false, _Value());
			break;
		case TK_FACTOR_MINUS:
			a = testOptimize(SON(0));
			if (a.first) return mp(true, -a.second);
			return mp(false, _Value());
			break;
		default:
			return mp(false, _Value());
			break;
		}
	}
	else {
		throw Error("Unexpected null pointer of the syntax tree, parsing has to stop.");
		exit(0);
	}
}
piv genCode(NODE *t, int extraMsg) {
	// cout<<t->type<<" "<<NODE_NAMES[t->type]<<endl;
	if (t) {
	if (ICG_DEBUG) cout<<t->type<<" "<<NODE_NAMES[t->type]<<endl;
		piv a, b, c;
		piv x, d, tmp;
		int w1, w2, ww;
		string stemp;
		pair<bool, _Value> ta, tb; _Value tv;
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
			output("string " + getName(a) + " " + "\"" + t->value.sval + "\"");
			return a;
			break;
		case TK_SYS_CON:
			if (t->value.type == type_integer) a = mp(1, _Value(t->value.ival));
			else if (t->value.type == type_real) a = mp(1, _Value(t->value.dval));
			else if (t->value.type == type_boolean) a = mp(1, _Value(t->value.bval));
			else if (t->value.type == type_char) a = mp(1, _Value(t->value.cval));
			return a;
			break;
		case TK_SYS_FUNCT:
			return mp(4, _Value(t->name, TK_SYS_FUNCT));
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
			// if (t->symbolTable == nullptr) output("报警，变量名：" + t->name);
			if (t->symbolTable != nullptr)
				return output(t, mp(5, _Value(t->name)));
			else  //全局变量
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
		// 		output(string(t->dataType) + "" + getName(genCode(SON(i))));
		// 	break;

		/*  操作符  */
		case TK_PLUS:
			if (ICG_DEBUG) cout<<TempVars::ind<<endl;
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			// cout<<"wahahahahahahah"<<" "<<ta.first<<" "<<tb.first<<" "<<NODE_NAMES[t->type]<<endl;
			if (ta.first && tb.first) {
				tv = ta.second + tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '+');  chkOpnd(b, "Right", '+');
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "+", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_MINUS:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second - tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '-');  chkOpnd(b, "Right", '-');
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "-", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_OR:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second | tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '|');  chkOpnd(b, "Right", '|');
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "|", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		
		case TK_MUL:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second * tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", '*');  chkOpnd(b, "Right", '*');
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "*", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_DIV:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second.div(tb.second);
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'DIV'");  chkOpnd(b, "Right", "'DIV'");
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "DIV", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_REM:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second / tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'/'");  chkOpnd(b, "Right", "'/'");
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "/", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_MOD:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second % tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'MOD'");  chkOpnd(b, "%", "'MOD'");
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "%", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_AND:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second & tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(t->child[0]), b = genCode(t->child[1]);
			chkOpnd(a, "Left", "'AND'");  chkOpnd(b, "Right", "'AND'");
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "&", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
			
		/*  函数  */
		case TK_FUNC_DECL:
			genCode(t->child[0]);
			//TO-DO　计算函数sp位置
			genCode(t->child[1]);
			// output("ret"); lessIndent();
			break;
		case TK_PROC_DECL:
			genCode(t->child[0]);
			genCode(t->child[1]);
			// output("ret"); lessIndent();
			break;
		case TK_FUNC_HEAD:
			a = genCode(t->child[0]);
			a.first!=2 ? throw Error(getName(a) + " cannot be the name of a function."): 0;
			output("entry " + getName(a)); moreIndent();
			//parameters, simple_type_decl ignored
			break;
		case TK_PROC_HEAD:
			a = genCode(t->child[0]);
			output("entry " + getName(a)); moreIndent();
			break;
			
		case TK_PARA:
			throw Error("Wrong syntax tree as it somehow generates illegal 'TK_PARA'");
			break;
		case TK_ROUTINE:
			// output("int bp sp");
			output("sp = sp - " + string(_Value(calSize(t->symbolTable->varSequence, t->symbolTable->varSymbolTable))));  //将sp减去局部变量(包括返回值)的大小
			if (SON(1)) TempVars::release(genCode(SON(1), TK_ROUTINE));
			output("sp = sp + " + string(_Value(calSize(t->symbolTable->varSequence, t->symbolTable->varSymbolTable))));
			output("ret"); lessIndent();

			// ww = t->name=="FUNC" ? t->symbolTable->varSymbolTable[t->symbolTable->varSequence[0]].size() : 0;  //是function ?? TO-DO
			// outDebug();
			// cout<<calSize(t->symbolTable->varSymbolTable)<<" "<<calSize(t->symbolTable->paraSequence, t->symbolTable->varSymbolTable)<<" "<<ww<<" "<<t->symbolTable->varSequence.size()<<endl;
			// outDebug();
			// output("sp = sp + " + string(_Value(calSize(t->symbolTable->varSymbolTable) - ww + 4)));
			// TO-DO output("return" ...); (要用到符号表里的变量吧)(检查某变量是否有被用到过，以确定是否有返回值)
			
			genCode(SON(0));
			break;
		case TK_ROUTINE_HEAD:
			//TO-DO 其他部分
			if (SON(3)) genCode(SON(3));  //注意NULL判断
			break;
		case TK_ROUTINE_PART:  //routine_body和routine_part都是这个??
			for (int i=0; i<t->child_number; i++)
				genCode(SON(i));
			// if (extraMsg == TK_ROUTINE) {  //to generate code of compound_stmt
			// 	if (!t->child[0] || t->child[0]->type!=TK_CP_STMT)
			// 		throw Error("Wrong syntax tree as it somehow generates illegal 't->child[0]->type' under 'TK_ROUTINE->TK_ROUTINE_PART'");
			// 	else
			// 		genCode(t->child[0]);
			// }
			// else {
			// 	// TO-DO
			// }
			break;
		case TK_STMT_LIST:
			for (int i=0; i<t->child_number; i++)
				TempVars::release(genCode(SON(i)));
			break;
		case TK_STMT_LABEL:  /*  stmt其实不需要一个返回值  */
			a = genCode(t->child[0]);
			a.first!=1||a.second.type!=_Value::INTEGER ? throw Error("Wrong syntax tree under TK_STMT, above TK_INTEGER"): 0;
			output("Label LUSER" + getName(a));
			return genCode(t->child[1]);
			break;
		case TK_STMT:
			return genCode(t->child[0]);
			break;
		//assign_stmt
		case TK_STMT_ASSIGN:
			return genCode(SON(0));
			break;
		case TK_ASSIGN_ID:
			c = genCode(SON(0)); a = genCode(SON(1));
			c.first!=2&&c.first!=6 ? throw Error("L-value must be a changeable variable"): 0;
			a.first==-1 ? throw Error("R-value must not be empty"): 0;
			output(c, "=", a);
			TempVars::release(a); return c;
			break;
		case TK_ASSIGN_ID_EXPR:  //  P321 数组计算的时候还要考虑lower_bound
			// a = genCode(SON(0));  b = genCode(SON(1));  x = genCode(SON(1));
			// output(tmp=mp(0, TempVars::getAnother()), b, "-", string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.start)));
			// //output(getName(d=mp(0, TempVars::getAnother())) + " = " + getName(tmp) + " * " + "elem_size(" + getName(a) + ")");
			// output(getName(tmp)
			// 				+ " = " + getName(tmp)
			// 					+ " * " + string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.elementSize)));  //t3 = t1 * {elem_size(a)};可以优化掉t3  TO-DO
			// output(getName(tmp) + " = &" + getName(a) + " + " + getName(tmp));
			// output("*" + getName(tmp) + " = " + getName(x));
			// output(getName(c=mp(0, TempVars::getAnother())) + " = *" + getName(tmp));
			// TempVars::release(b); TempVars::release(x); TempVars::release(tmp); return c;
			break;
		// case TK_ASSIGN_DD:  //TO-DO
		// 	break;
		
		//proc_stmt (procedure没有返回值)
		case TK_STMT_PROC:
			return genCode(SON(0));
			break;
		case TK_PROC_ID:  //a因为是变量所以不用release
			a = genCode(SON(0));
			// output("begin_args");
			output("call " + getName(a));
			if (a.second.i == 1) return getReturnNum(SON(0)->symbolTable->findFunc(SON(0)->name).complexType->fpType.retType,
													SON(0)->symbolTable->findFunc(SON(0)->name).complexType->fpType.retType.size() + 8);
			//if (a.second.i == 1) return getReturnNum(SON(0)->symbolTable->findFunc(SON(0)->name).complexType->fpType.retType);
			break;
		case TK_PROC_ID_ARGS:
			a = genCode(SON(0));
			// output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + getName(a));
			if (a.second.i == 1) return getReturnNum(SON(0)->symbolTable->findFunc(SON(0)->name, expressionListAnalysis(SON(1))).complexType->fpType.retType,
													SON(0)->symbolTable->findFunc(SON(0)->name, expressionListAnalysis(SON(1))).complexType->fpType.retType.size() + 8);
			break;
		
		//SYS_PROC
		case TK_PROC_SYS:  //这是procedure
			a = genCode(SON(0));
			// output("begin_args");
			output("call " + getName(a));
			// if (a.second.i == 1) return getReturnNum();
			break;
		case TK_PROC_SYS_ARGS:  //这是procedure(只有write和writeln)
			a = genCode(SON(0));
			sysproc = string(a.second)=="writeln" ? "println" : "print";
			// puts("*********************");
			TempVars::release(genCode(SON(1)));
			// output("begin_args");
			// b = genCode(SON(1)->child[0]);
			// if (b.first == 6) {
			// 	output(getName(tmp=mp(0, TempVars::getAnother(b.second.getType()))) + " = " + getName(b));
			// 	TempVars::release(b); b=tmp;
			// }
			// output((string(a.second)=="writeln"?"println ":"print ") + getName(b));  //TO-DO 暂时只处理了单个变量的输出
			// TempVars::release(genCode(SON(1)));
			break;
		
		//TK_READ
		case TK_PROC_READ:  //TO-DO 应该只有ID而不是factor可以read??先当成单个ID来做
			for (int i=0; i<SON(1)->child_number; i++) {
				a = genCode(SON(1)->child[i]);
				output("read t" + string(a.second));
				if (isTempVar(a)) TempVars::release(a);
			}
			// a = genCode(SON(0));
			// b = genCode(SON(1));
			// stemp = string(SON(1)->child[0]->symbolTable->varSymbolTable[SON(1)->child[0]->name]);
			// // output("begin_args");
			// output("read t" + string(b.second));
			break;
		case TK_PROC_READLN:
			for (int i=0; i<SON(1)->child_number; i++) {
				a = genCode(SON(1)->child[i]);
				output(string("read") + (i==SON(1)->child_number-1?"ln":"") + " t" + string(a.second));
				if (isTempVar(a)) TempVars::release(a);
			}
			break;
		
		//compound_stmt
		case TK_STMT_CP:
			if (SON(0)) return genCode(SON(0));
			break;
		
		//if_stmt
		case TK_IF:
			a = genCode(SON(0));
			output("if_false " + getName(a) + " goto L" + toString(w1=Label::newLabel()));
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
			TempVars::release(genCode(SON(0)));
			a = genCode(SON(1));
			output("if_false " + getName(a) + " goto L" + toString(w1));
			TempVars::release(a);
			break;
		//while_stmt
		case TK_WHILE:
			output("label L" + toString(w1=Label::newLabel()));
			a = genCode(SON(0));
			output("if_false " + getName(a) + " goto L" + toString(w2=Label::newLabel()));
			TempVars::release(genCode(SON(1)));
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
					output(d=mp(0, TempVars::getAnother("int")), "=", mp(1, 1));
				else
					output(d=mp(0, TempVars::getAnother("int")), "=", mp(1, -1));
				TempVars::release(tmp);
			
			//while (x!=b) { stmt; x=x+d; }
				output("label L" + toString(w1=Label::newLabel()));
				output(tmp=mp(0, TempVars::getAnother("int")), x, "!=", b);
				output("if_false " + getName(tmp) + " goto L" + toString(w2=Label::newLabel()));
				genCode(SON(4)); output(x, x, "+", d);
				output("goto L" + toString(w1));
				output("label L" + toString(w2));
				TempVars::release(tmp);
				
			//while (x==b) { stmt; x=x+d; }
				output("label L" + toString(w1=Label::newLabel()));
				output(tmp=mp(0, TempVars::getAnother("int")), x, "==", b);
				output("if_false " + getName(tmp) + " goto L" + toString(w2=Label::newLabel()));
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
			output(string("goto L") + CaseParse::getEndLabel());
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
		// 	output("arg " + getName(a));
		// 	if (isTempVar(a)) TempVars::release(a);
		// 	break;
		case TK_ARGS_LIST:
			if (ICG_DEBUG) cout<<TempVars::ind<<" TK_ARGS_LIST0"<<endl;
			for (int i=0; i<t->child_number; i++) {
				a = genCode(SON(i));
				output("arg " + getName(a));
				if (isTempVar(a)) TempVars::release(a);
			}
			if (ICG_DEBUG) cout<<TempVars::ind<<" TK_ARGS_LIST1"<<endl;
			break;
			
		//expression_list
		// case TK_EXP_LIST_COMMA:
		// 	genCode(SON(0));
		// 	a = genCode(SON(1));
		// 	output("arg " + getName(a));
		// 	if (isTempVar(a)) TempVars::release(a);
		// 	break;
		case TK_EXP_LIST:
			for (int i=0; i<t->child_number; i++) {
				a = genCode(SON(i));
				if (a.first == 6) {
					output(getName(tmp=mp(0, TempVars::getAnother(a.second.getType()))) + " = " + getName(a));
					TempVars::release(a); a=tmp;
				}
				output(sysproc + " " + getName(a));
				if (isTempVar(a)) TempVars::release(a);
			}
			break;
		
		//expression  //TO-DO
		case TK_GE:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second >= tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, ">=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_GT:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second > tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, ">", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_LE:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second <= tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "<=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_LT:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second < tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "<", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_EQUAL:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second == tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "==", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_UNEQUAL:
			ta = testOptimize(SON(0)); tb = testOptimize(SON(1));
			if (ta.first && tb.first) {
				tv = ta.second != tb.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));  b = genCode(SON(1));
			output(c=mp(0, TempVars::getAnother(t->dataType)), a, "!=", b);  // TO-DO a=a+b??
			TempVars::release(a); TempVars::release(b); return c;
			break;
		case TK_EXP:
			if (ICG_DEBUG) cout<<TempVars::ind<<endl;
			return genCode(SON(0));
			break;
		
		//expr
		case TK_EXPR:
			if (ICG_DEBUG) cout<<TempVars::ind<<endl;
			return genCode(SON(0));
			break;
		
		//term  //TO-DO
		case TK_TERM:
			if (ICG_DEBUG) cout<<TempVars::ind<<endl;
			return genCode(SON(0));
			break;
		
		//factor
		case TK_FACTOR_ID:
			return genCode(SON(0));
			break;
		case TK_FACTOR_ID_ARGS:
			if (ICG_DEBUG) cout<<TempVars::ind<<" TK_FACTOR_ID_ARGS0"<<endl;
			a = genCode(SON(0));
			// output("begin_args");
			if (ICG_DEBUG) cout<<TempVars::ind<<" TK_FACTOR_ID_ARGS1"<<endl;
			TempVars::release(genCode(SON(1)));
			output("call " + getName(a));
			return getReturnNum(t->dataType.complexType->fpType.retType, t->dataType.complexType->fpType.retType.size() + 8);
//			return getReturnNum(SON(0)->symbolTable->findFunc(SON(0)->name, expressionListAnalysisForICG(SON(1))).complexType->fpType.retType); //output(getName(c=mp(0, TempVars::getAnother())) + " = *sp");
			if (ICG_DEBUG) cout<<TempVars::ind<<" TK_FACTOR_ID_ARGS2"<<endl;
			// output(getName(mp(0, (c=mp(6, TempVars::getAnother())).second)) + " = sp");
			return c;
			//返回值?? TO-DO
			break;
		case TK_FACTOR_SYS_FUNCT:
			a = genCode(SON(0));
			// output("begin_args");
			TempVars::release(genCode(SON(1)));
			output("call " + getName(a));
			return getReturnNum(t->dataType.complexType->fpType.retType, t->dataType.complexType->fpType.retType.size() + 8); //output(getName(c=mp(0, TempVars::getAnother())) + " = *sp");
			// output(getName(mp(0, (c=mp(6, TempVars::getAnother())).second)) + " = sp");
			return c;
			//返回值?? TO-DO
			break;
		case TK_FACTOR_CONST:
			if (ICG_DEBUG) cout<<TempVars::ind<<endl;
			return genCode(SON(0));
			break;
		case TK_FACTOR_EXP:
			return genCode(SON(0));
			break;
		case TK_FACTOR_NOT:
			ta = testOptimize(SON(0));
			if (ta.first) {
				tv = ~ta.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));
			output(tmp=mp(0, TempVars::getAnother(a.second.getType())), "= NOT", a);
			TempVars::release(a);  return tmp;
			break;
		case TK_FACTOR_MINUS:
			ta = testOptimize(SON(0));
			if (ta.first) {
				tv = -ta.second;
				if (tv.type == _Value::Variable) {
					a = mp(3, _Value(stringVars++));
					output("string " + getName(a) + " " + "\"" + string(tv) + "\"");
					return a;
				}
				else return mp(1, tv);
			}
			a = genCode(SON(0));
			output(tmp=mp(0, TempVars::getAnother(a.second.getType())), "= -", a);
			TempVars::release(a);  return tmp;
			break;
		case TK_FACTOR_ID_EXP:  //TO-DO
			// a = genCode(SON(0));  b = genCode(SON(1));
			// output(tmp=mp(0, TempVars::getAnother()), b, "-", string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.start)));
			// //output(getName(d=mp(0, TempVars::getAnother())) + " = " + getName(tmp) + " * " + "elem_size(" + getName(a) + ")");
			// output(getName(tmp)
			// 				+ " = " + getName(tmp)
			// 					+ " * " + string(_Value(t->symbolTable->findVar(string(a.second)).complexType->arrayType.elementSize)));  //t3 = t1 * {elem_size(a)};可以优化掉t3  TO-DO
			// output(getName(tmp) + " = &" + getName(a) + " + " + getName(tmp));
			// output(getName(c=mp(0, TempVars::getAnother())) + " = *" + getName(tmp));
			// TempVars::release(b); TempVars::release(tmp); return c;
			break;
		case TK_FACTOR_DD:
			a = genCode(SON(0));
			// output(getName(tmp=mp(0, TempVars::getAnother("point int"))) + " = t" + string(a.second) + " + field_offset(" + SON(0)->name + "," + SON(1)->name + ")");
			output("t" + string((tmp=mp(6, TempVars::getAnother(string("point ") + string(SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getType(SON(1)->name))))).second) 
					+ " = t" + string(a.second) + " + " + string(_Value(SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getOffset(SON(1)->name))));
			TempVars::release(a); return tmp;
			// TO-DO
			break;
		case TK_ASSIGN_DD:
			a = genCode(SON(0));
			// outDebug();
			// if you want get SON(0)'s field, you should access SON(0)->record
			// and it should be (SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getType(SON(0)->record->name)
			// cout<< (SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getType(SON(0)->record->name).isSimpleType) <<endl;
			output("t" + string((tmp=mp(6, TempVars::getAnother(string("point ") + string(SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getType(SON(0)->record->name))))).second)
					+ " = t" + string(a.second) + " + " + string(_Value(SON(0)->symbolTable->varSymbolTable[SON(0)->name].complexType->recordType.getOffset(SON(0)->record->name))));
			b = genCode(SON(1));
			output(getName(tmp) + " = " + getName(b));
			// outDebug();
			TempVars::release(a); TempVars::release(b); return tmp;
			break;
			
		//procedure??
		
		case TK_SYS_TYPE:
			break;
			
		case TK_PROGRAM:
			genCode(SON(1)->child[0]);
			puts("entry main");
			output("sp = sp - " + string(_Value(calSize(SON(1)->symbolTable->varSequence, SON(1)->symbolTable->varSymbolTable))));  //将sp减去参数和局部变量的大小
			if (SON(1)->child[1]) TempVars::release(genCode(SON(1)->child[1], TK_ROUTINE));
			ww = SON(1)->name=="FUNC" ? SON(1)->symbolTable->varSymbolTable[SON(1)->symbolTable->varSequence[0]].size() : 0;
			// output("sp = sp + " + string(_Value(calSize(SON(1)->symbolTable->varSymbolTable) - ww + 4)));
			output("sp = sp + " + string(_Value(calSize(SON(1)->symbolTable->varSequence, SON(1)->symbolTable->varSymbolTable))));
			// TO-DO output("return" ...); (要用到符号表里的变量吧)(检查某变量是否有被用到过，以确定是否有返回值)
			//暂时不做处理
			
			if (ICG_DEBUG) {
				cout<<TempVars::idleTemp.size()<<" "<<TempVars::ind<<endl;
				// while (TempVars::idleTemp.size()) cout<<TempVars::idleTemp.top()<<endl, TempVars::idleTemp.pop();
			}
			break;
		case TK_PROGRAM_HEAD:
			//暂时不做处理
			break;
		case TK_CONST_PART:
			//??
			break;
		default:
			break;
		}
		if (ICG_DEBUG) cout<<NODE_NAMES[t->type]<<" back"<<endl;
	}
	else {
		throw Error("Unexpected null pointer of the syntax tree, parsing has to stop.");
		exit(0);
	}

	return mp(-1, 0);
}
