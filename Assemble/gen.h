//
//  basic.h
//  Generator
//
//  Created by Peter Tam on 16/6/17.
//  Copyright (c) 2016年 Peter Tam. All rights reserved.
//

#ifndef Generator_basic_h
#define Generator_basic_h

#include <stdio.h>

//定义布尔类型
typedef enum {FALSE, TRUE} bool;

//定义变量类型
typedef enum {INTEGER, FLOAT, DOUBLE, STRING, ARRAY, UNDEFINED, IMM} type;

//变量
typedef struct {
    char name[200];
    union {
        char initval[200]; //初始值
        char floatval[200];
        char doubleval[200];
    };
    type type; //指向的类型
    bool isVar;
} Variable;

//变量表
typedef struct {
    int num; //变量数
    Variable var[200];
} VariableMap;

//定义三地址码的操作类型
typedef enum {
    gt, sm, eq, ne, if_f, lab, add, sub, dvd, mul, rd, pri, priln, asn, jump, dec, call, var, sp, func, ret, arg
    //add sub mul dvd是加减乘除
    //gt sm eq是比较
    //pri priln rd是输入输出
    //if_f jump是跳转
    //dec改变指针类型
    //func是函数
} OpKind;

//定义三地址码的地址类型 分别是空的、整形、字符串类型（名字）、地址（含&）、值（含*）
typedef enum {
    IntConst, FloatConst, String, Addr, Val, Empty
} AddrKind;

//定义三地址码的地址结构
typedef struct {
    AddrKind kind;
    union {
        int intVal;
        float floatVal;
        double doubleVal;
        char name[20];
    } contents;
} Address;

//定义三地址码的语句格式 即四元组
typedef struct {
    Address addr1, addr2, addr3;
    OpKind op;
} Quad;

//四元组表
typedef struct {
    int num;
    Quad quad[1000];
} QuadTable;

//标签表
typedef struct {
    int num;
    char labels[100][100];
} LabelTable;

#endif
