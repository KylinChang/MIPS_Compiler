%option caseless
%{
/*
	* <del>TK_MUL有修改成TK_STAR</del>
	* <del>不知道文档里的DIV表示"/"还是"DIV"，我就当实数除"/"处理了</del>
	  <del>文档里的DIV表示"/"</del>
	  <del>用SLAH表示"/"，而DIV表示"DIV"</del>
	  DIV表示"DIV"和"/"
	  
	* 在真正的pascal中，program_head中的标识符ID是不能以下划线开头的，而变量里的标识符是可以的。然而老师文档里这两者并没有进行区分，所以我就直接取了两者的交集(即不能以下划线开头)。
	* boolean类型只有两种值：true, false，且老师文档里没有提及，所以我就把它写在SYS_CON里了。
	* 文档里没写注释的匹配规则，所以我就没写。
	* 暂时先将长度为1的字符(串)常量定为CHAR类型，长度大于2的字符串常量定为STRING类型。
	* 文档里的GOTO语句貌似是错的。
*/
/*
	代码内容修改：
	2016.5.29
		* 按照张的文档对代码进行了相应的修改
	2016.5.24
		* 修改了CHAR和STRING的判断条件，STRING可判断多单引号情况，且将空字符归为STRING(ubuntu上的free pascal是这样)
*/

 
#include "common.h"
#include "yy.tab.hpp"
#define min(a,b) ( ((a)>(b)) ? (b):(a) )
extern int DEBUG;
extern FILE* yyout;
void endlessComment();  /*  用于处理注释只有前面一半的情况  */
%}

DOT "."
PROGRAM "PROGRAM"
SEMI ";"
CONST "CONST"
EQUAL "="

DIGITS ([0-9])+
INTEGER_10 ("+"|"-")?{DIGITS}
INTEGER ("+"|"-")?$?{DIGITS}
REAL {INTEGER_10}"."{DIGITS}(E{INTEGER_10})?
CHAR '([^'\n]|'')'
STRING '([^\'\n]|'')*'

TYPE "TYPE"
ARRAY "ARRAY"
LB "["
RB "]"
OF "OF"
RECORD "RECORD"
END "END"
COLON ":"
COMMA ","
LP "("
RP ")"
DOTDOT ".."
MINUS "-"
VAR "VAR"
FUNCTION "FUNCTION"
PROCEDURE "PROCEDURE"
ASSIGN ":="
SYS_PROC "write"|"writeln"
READ "READ"
BEGIN "BEGIN"
IF "IF"
THEN "THEN"
ELSE "ELSE"
REPEAT "REPEAT"
UNTIL "UNTIL"
WHILE "WHILE"
DO "DO"
FOR "FOR"
TO "TO"
DOWNTO "DOWNTO"
CASE "CASE"
GOTO "GOTO"
GE ">="
GT ">"
LE "<="
LT "<"
UNEQUAL "<>"
PLUS "+"
OR "OR"
MUL "*"
DIV "DIV"|"/"
MOD "MOD"
AND "AND"
SYS_FUNCT "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
NOT "NOT"

SYS_CON "maxint"|"maxlongint"|"true"|"false"
SYS_TYPE "shortint"|"smallint"|"longint"|"int64"|"integer"|"single"|"double"|"extended"|"comp"|"currency"|"real"|"ansichar"|"widechar"|"char"|"string"|"bytebool"|"wordbool"|"longbool"|"boolean"|"byte"|"word"|"dword"|"longword"|"cardinal"|"text"|"TDateTime"

ID [A-Z]([_A-Z0-9])*

%%
{DOT} { return TK_DOT; }
{PROGRAM} { return TK_PROGRAM; }
{SEMI} { return TK_SEMI; }
{CONST} { return TK_CONST; }
{EQUAL} { return TK_EQUAL; }

{REAL} {
	yylval = NEWNODE(TK_REAL);
	yylval->lineno = yylineno;
	double tmp;
	sscanf(yytext, "%lf", &tmp);
	yylval->value = new Value(tmp);
	return TK_REAL;
}  /*  实数类型应写在整数类型之上  */
{INTEGER} {
	yylval = NEWNODE(TK_INTEGER);
	yylval->lineno = yylineno;
	char *ts = yytext;
	int sign = 1;
	if (*ts == '+' || *ts == '-') {
		sign = (*ts=='+') ? 1 : -1;
		ts++;
	}

	int tmp;
	if (*ts == '$') sscanf(++ts, "%x", &tmp);
	else            sscanf(ts, "%d", &tmp);
	yylval->value = new Value(tmp*sign);
	return TK_INTEGER;
}
{CHAR} {
	yylval = NEWNODE(TK_CHAR);
	yylval->lineno = yylineno;

	char tmp;
	sscanf(yytext+1, "%c", &tmp);  /*  单引号的情况也可处理  */
	yylval->value = new Value(tmp);
	return TK_CHAR;
}  /*  注意单引号的表示方法：''''，以及多个单引号的表示方法。  */
{STRING} {
	yylval = NEWNODE(TK_STRING);
	yylval->lineno = yylineno;
	yytext[min(256, yyleng-1)]=0;
	yylval->value = new Value(genString(yytext+1, min(255, yyleng-2)));
	return TK_STRING;
}  /*  注意STRING可能是空串，且按照pascal标准，只会保存前255个字符。  */

{TYPE} { return TK_TYPE; }
{ARRAY} { return TK_ARRAY; }
{LB} { return TK_LB; }
{RB} { return TK_RB; }
{OF} { return TK_OF; }
{RECORD} { return TK_RECORD; }
{END} {
	return TK_END; 
}
{COLON} { return TK_COLON; }
{COMMA} { return TK_COMMA; }
{LP} { return TK_LP; }
{RP} { return TK_RP; }
{DOTDOT} { return TK_DOTDOT; }
{MINUS} { return TK_MINUS; }
{VAR} {
	return TK_VAR;
}
{FUNCTION} { return TK_FUNCTION; }
{PROCEDURE} { return TK_PROCEDURE; }
{ASSIGN} { return TK_ASSIGN; }
{SYS_PROC} {
	yylval = NEWNODE(TK_SYS_PROC);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_SYS_PROC;
}
{READ} {
	yylval = NEWNODE(TK_READ);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_READ;
}
{BEGIN} {
	return TK_BEGIN;
}
{IF} { return TK_IF; }
{THEN} { return TK_THEN; }
{ELSE} { return TK_ELSE; }
{REPEAT} { return TK_REPEAT; }
{UNTIL} { return TK_UNTIL; }
{WHILE} { return TK_WHILE; }
{DO} { return TK_DO; }
{FOR} { return TK_FOR; }
{TO} {
	yylval = NEWNODE(TK_TO);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_TO;
}
{DOWNTO} {
	yylval = NEWNODE(TK_DOWNTO);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_DOWNTO;
}
{CASE} { return TK_CASE; }
{GOTO} { return TK_GOTO; }
{GE} { return TK_GE; }
{GT} { return TK_GT; }
{LE} { return TK_LE; }
{LT} { return TK_LT; }
{UNEQUAL} { return TK_UNEQUAL; }
{PLUS} { return TK_PLUS; }
{OR} { return TK_OR; }
{MUL} { return TK_MUL; }
{DIV} {
	yylval = NEWNODE(TK_DIV);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_DIV;
}
{MOD} { return TK_MOD; }
{AND} { return TK_AND; }
{SYS_FUNCT} {
	yylval = NEWNODE(TK_SYS_FUNCT);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_SYS_FUNCT;
}
{NOT} { return TK_NOT; }

{SYS_CON} {
	yylval = NEWNODE(TK_SYS_CON);
	yylval->lineno = yylineno;
	string tmp = genString(yytext, yyleng);
	yylval->name = tmp;
	if(tmp=="maxint" || tmp=="maxlongint"){
	    yylval->value = new Value(INT32_MAX);
	}else if(tmp=="true"){
	    yylval->value = new Value(true);
	}else if(tmp=="false"){
	    yylval->value = new Value(false);
	}
	return TK_SYS_CON;
}
{SYS_TYPE} {
	yylval = NEWNODE(TK_SYS_TYPE);
	yylval->lineno = yylineno;
	yylval->name = genString(yytext, yyleng);
	return TK_SYS_TYPE;
}

{ID} {
	yylval = NEWNODE(TK_ID);
	yylval->lineno = yylineno;
	//cpString(yylval->name, &yytext);
	yylval->name = yytext;
	return TK_ID; 
}  /*  因为保留字不能做操作符，所以将其移到最后一个以降低分析优先级  */

"{" {
	char c;
	while ((c=yyinput())!='}') {
		if (!(~c)) endlessComment();
		if (c=='\n') yylineno++;
	}
}
"(*" {
	char c;
	do {
		while ((c=yyinput())!='*') {
			if (!(~c)) endlessComment();		
			if (c=='\n') yylineno++;
		}
		while ((c=yyinput())=='*');
		if (!(~c)) endlessComment();
		if (c=='\n') yylineno++;
		if (c==')') break;
	} while (1);
}

\n {
	++yylineno;
}
\r {
}
^[ \t]+ { /*  缩进  */ }
[ \t\f]+ { /*  skip whitespace  */ }
. { return ERROR; }

%%
void endlessComment() {
	fprintf(yyout, "Unexpected EOF inside comment\n");
	exit(1);
}
int yywrap() {
	return 1;
}
/*int main() {
	yylex();
}*/
