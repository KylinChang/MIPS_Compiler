#ifndef __NODE__
#define __NODE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE{
    int type;
    
    char* name;
    char* str;
    char ch;
    int ival;
    double dval;
    int child_number;
    struct NODE** child;

    struct NODE* attr;
}NODE;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)
#define MALLOC(pointer,num) (NODE**)malloc(NODE_POINTER_SIZE*(pointer->child_number=num))

NODE* NEWNODE(int type);
void cpString(char** str1, char** str2);

#endif
