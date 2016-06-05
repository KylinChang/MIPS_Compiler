#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

typedef struct NODE{
    char* name;
    char* str;
    char ch;
    int type;
	int is_ref;
    int ival;
    double dval;
    int child_number;
    struct NODE** child;
    struct NODE* record;

	int lineno; //output the error line number
}NODE;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)
#define MALLOC(pointer,num) (NODE**)malloc(NODE_POINTER_SIZE*(pointer->child_number=num))

NODE* NEWNODE(int type);
void cpString(char** str1, char** str2);
void setName(NODE* node, int type);
void init();

extern "C" {
	extern int yylex();
}

int yyerror(string s);

#define YYSTYPE NODE*

extern char* yytext;
//extern int yylineno;
extern FILE* yyin;

#endif
