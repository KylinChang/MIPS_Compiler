#include <string>
#include <stringstream>
#include "y.tab.h"
using namespace std;

/*
	很多书上找不到定义的P-code指令，我就自己定义了。

	adi			integer addition
	sbi			integer subtraction
	mpi			integer multiplication
	ori			整数or
	
	grt			greater than(针对整数). 把在栈最顶端的两个元素pop出来，设栈顶最顶端的是b，次顶端的是a，那么push a>b的结果。
	equ			equal(针对整数). 操作类似grt
	
	sto			pop栈，并把pop出来的值赋给新栈顶(作为指针)指向的内存中，然后再pop。
	stn			pop栈，并把pop出来的值赋给新栈顶(作为指针)指向的内存中，然后把新栈顶的值该为pop出来的值。
	ldc 1		把常值1 push到栈顶(大概是针对整数而言?)。
	lda x		把x的地址push到栈顶。
	lod x		把x的值push到栈顶。
	
	fjp L1		pop栈顶的boolean值，如果值为false那么跳到L1。
	ujp L1		无条件转移
	lab L1		定义L1这个label。这里大概需要调用符号表的接口。
	
	rdi			read一个整数，把这个整数赋给栈顶(作为指针)指向的内存中，然后pop栈。
	wri			write栈顶的数值，并pop栈。
	
	ent f  \\
	ret			函数入口指令是ent，返回指令是ret
	
	stp			stop，表示程序的结束。
*/

enum {
}

void genCode(NODE *t) {  //, int d) {  /*  d==1表示反方向遍历t与它的兄弟  */
	string codestr;
	
	// vector<NODE> nodeList;
	// for (; t; t=t->sib) nodeList.pb(t);
	// int start=0, end=nodeList.size(), step=1;
	// if (d) start=nodeList.size()-1, end=-1, step=-1;
	
	// for (int i=start; i!=end; i+=step) {
	// 	t = nodeList[i];
	for (; t; t = t->sib) {
		switch (t->type) {
		case TK_PLUS:
			//sign和普通加法??
			break;
		case TK_MINUS:
			break;
		case TK_OR:
			if ()
			genCode(t->child);
			emitCode("ori");
			break;
			
		case TK_EQUAL:
			genCode(t->child);
			emitCode("equ");
			break;

		case TK_ASSIGN:  /*  假设Assign的语法树只有一个左儿子  */
			emitCode(string("lda ") + t->child->name);
			genCode(t->child->sib);
			emitCode("stn");
			break;
		case TK_ID:
			
			break;
		default:
			emitCode("Unkonw NODE type Error");
			break;
		}
	}
}

