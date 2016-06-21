//
//  gen.h
//  Generator
//
//  Created by Peter Tam on 16/6/17.
//  Copyright (c) 2016年 Peter Tam. All rights reserved.
//
#ifndef Generator_gen_h
#define Generator_gen_h

#include "gen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* fp;
extern FILE* out;
extern int stackoffset;
extern VariableMap map;
extern QuadTable text;
extern LabelTable lb;

//从一行三地址码中提取出元素,成功则为1，失败则为0
//src是源地址码 dst是提取出的元素 head是从src的某个位置开始扫描
int getElement(char* src, int* head, char* dst) {
    int p = *head;
    int cnt = 0;
    while (src[p]!='\0') {
        if (src[p]==' ') break;
        dst[cnt++] = src[p++];
    }
    if (src[p]==' ') p++;
    *head = p;
    return cnt>0;
}

//添加一个变量到变量表中
void addVariable(VariableMap* map, char* name, type vartype, char* initval) {
    strcpy(map->var[map->num].name, name);
    strcpy(map->var[map->num].initval, initval);
    map->var[map->num].type = vartype;
    map->var[map->num].isVar = FALSE;
    map->num++;
}

//定义所有的变量 (已支持浮点数）
void declareVariable(VariableMap* map) {
    int i;
    char name[5];
    fprintf(out, ".data 0x10000000\n\n");
    fprintf(out, "\tendl:\t.asciiz\t\"\\n\"\n");
    fprintf(out, "\tbp:\t.word\t0\n");
    for (i=0; i<20; i++) {
        fprintf(out, "\tt%d:\t.word\t0\n", i);
        sprintf(name, "t%d", i);
        addVariable(map, name, INTEGER, "0");
    }
    fprintf(out, "\n");
}

//添加一个数组到变量表中
void addArray(VariableMap* map, char* name, int space) {
    strcpy(map->var[map->num].name, name);
    map->var[map->num].type = ARRAY;
    //    map->var[map->num].space = space;
    map->num++;
}

//添加一个标签
void addLabel(char* name, LabelTable* lb) {
    strcpy(lb->labels[lb->num], name);
    lb->num++;
}

//根据字符串判断元素的类型（已处理浮点数）
AddrKind getKind(char* name) {
    if (name[0]=='&') return Addr;
    if (name[0]=='*') return Val;
    if (name[0]=='_' || (name[0]>='a' && name[0]<='z') || (name[0]>='A' && name[0]<='Z')) return String;
    if (strstr(name, ".")>0) return FloatConst;
    if (name[0]>='0' && name[0]<='9') return IntConst;
    return Empty;
}

//根据变量名查到到它的类型
type getType(char* name, VariableMap* map) {
    if (name[0]=='$') return INTEGER;
    for (int i=0; i<map->num; i++)
        if (strcmp(name, map->var[i].name)==0)
            return map->var[i].type;
    return UNDEFINED;
}

//改变某个变量指针指向的类型
void changeType(Quad* quad, VariableMap* map) {
    type t = UNDEFINED;
    if (strcmp(quad->addr1.contents.name, "int")==0) t = INTEGER;
    if (strcmp(quad->addr1.contents.name, "float")==0) t = FLOAT;
    if (strcmp(quad->addr1.contents.name, "double")==0) t = DOUBLE;
    for (int i=0; i<map->num; i++)
        if (strcmp(map->var[i].name, quad->addr2.contents.name) == 0) {
            map->var[i].type = t;
            map->var[i].isVar = FALSE;
            return;
        }
}

void changeVar(Quad* quad, VariableMap* map) {
    type t = UNDEFINED;
    if (strcmp(quad->addr1.contents.name, "int")==0) t = INTEGER;
    if (strcmp(quad->addr1.contents.name, "float")==0) t = FLOAT;
    if (strcmp(quad->addr1.contents.name, "double")==0) t = DOUBLE;
    for (int i=0; i<map->num; i++)
        if (strcmp(map->var[i].name, quad->addr2.contents.name) == 0) {
            map->var[i].type = t;
            map->var[i].isVar = TRUE;
            return;
        }
}

bool getVar(char* name, VariableMap* map) {
    for (int i=0; i<map->num; i++)
        if (strcmp(name, map->var[i].name)==0)
            return map->var[i].isVar;
    return FALSE;
}

void addStar(char* name) {
    char next = ' ';
    char last = '*';
    while (next != '\0') {
        next = *name;
        *name = last;
        last = next;
        name++;
    }
    *name = '\0';
}

void removeStar(char* name) {
    char next = *(name+1);
    while (*name != '\0') {
        next = *(name+1);
        *name = next;
        name++;
    }
    *name = '\0';
}

void genFUNC(Quad* quad) {
    fprintf(out, "\n%s:\n", quad->addr1.contents.name);
    if (strcmp(quad->addr1.contents.name, "main")==0) {
        fprintf(out, "\tsw $sp, bp\n");
        return;
    }
    fprintf(out, "\t# use stack\n");
    //push bp
    fprintf(out, "\tlw $t0, bp\n");
    fprintf(out, "\taddi $sp, $sp, -4\n");
    fprintf(out, "\tsw $t0, 0($sp)\n");
    //bp_new == sp
    fprintf(out, "\tsw $sp, bp\n");
    stackoffset = 0;
}

void genCALL(Quad* quad) {
    fprintf(out, "\t# call a function\n");
    //push ra
    fprintf(out, "\taddi $sp, $sp, -4\n");
    fprintf(out, "\tsw $ra, 0($sp)\n");
    
    fprintf(out, "\tjal %s\n", quad->addr1.contents.name);
    
    //pop ra
    fprintf(out, "\tlw $ra, 0($sp)\n");
    fprintf(out, "\taddi $sp, $sp, 4\n");
    
}

void genARG(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# push an arg\n");
    type t = getType(quad->addr1.contents.name, map);
    if (t == INTEGER) {
        fprintf(out, "\taddi $sp, $sp, -4\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tlw $t0, 0($t0)\n");
        fprintf(out, "\tsw $t0, 0($sp)\n");
        stackoffset += 4;
    }
    if (t == FLOAT) {
        fprintf(out, "\taddi $sp, $sp, -4\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tl.s $f0, 0($t0)\n");
        fprintf(out, "\ts.s $f0, 0($sp)\n");
        stackoffset += 4;
    }
    if (t == DOUBLE) {
        fprintf(out, "\taddi $sp, $sp, -8\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tl.d $f0, 0($t0)\n");
        fprintf(out, "\ts.d $f0, 0($sp)\n");
        stackoffset += 8;
    }
}

void genRET(Quad*quad) {
    fprintf(out, "\t# free stack\n");
    //temp
    fprintf(out, "\taddi $sp, $sp, %d\n", stackoffset);
    //bp = bp_old / pop bp
    fprintf(out, "\tlw $t0, 0($sp)\n");
    fprintf(out, "\tsw $t0, bp\n");
    fprintf(out, "\taddi $sp, $sp, 4\n");
    fprintf(out, "\tjr $ra\n");
}

void genVAR(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# stack\n");
    if (strcmp(quad->addr1.contents.name, "int")==0) {
        stackoffset = stackoffset + 4;
        changeVar(quad, map);
        fprintf(out, "\taddi $sp, $sp, -4\n");
        fprintf(out, "\tsw $sp, %s\n", quad->addr2.contents.name);
    }
    
    if (strcmp(quad->addr1.contents.name, "float")==0) {
        stackoffset = stackoffset + 4;
        changeVar(quad, map);
        fprintf(out, "\taddi $sp, $sp, -4\n");
        fprintf(out, "\tsw $sp, %s\n", quad->addr2.contents.name);
    }
    
    if (strcmp(quad->addr1.contents.name, "double")==0) {
        stackoffset = stackoffset + 8;
        changeVar(quad, map);
        fprintf(out, "\taddi $sp, $sp, -8\n");
        fprintf(out, "\tsw $sp, %s\n", quad->addr2.contents.name);
    }
    
}


//将赋值的三地址码语句转化为mips（已支持浮点数）
void genASN(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# assign\n");
//    type t1 = UNDEFINED;
    if (quad->addr2.kind == String && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = Val;
        addStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == String && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = Val;
        addStar(quad->addr1.contents.name);
    }
    if (strcmp(quad->addr1.contents.name, "*sp")==0) {
        type t1 = getType(quad->addr2.contents.name+1, map);
        if (t1 == INTEGER) {
            fprintf(out, "\tlw $t0, 0($sp)\n");
            fprintf(out, "\tlw $t1, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\tsw, $t0, 0($t1)\n");
        }
        if (t1 == FLOAT) {
            fprintf(out, "\tl.s $f0, 0($sp)\n");
            fprintf(out, "\tl.s $t1, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\ts.s, $f0, 0($t1)\n");
        }
        if (t1 == DOUBLE) {
            fprintf(out, "\tl.d $f0, 0($sp)\n");
            fprintf(out, "\tl.d $t1, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\ts.d, $f0, 0($t1)\n");
        }
    } else
    if (quad->addr2.kind == String) {
        if (quad->addr1.kind == IntConst) fprintf(out, "\tli $t1, %d\n", quad->addr1.contents.intVal);
        if (quad->addr1.kind == String) fprintf(out, "\tlw $t1, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tsw $t1, %s\n", quad->addr2.contents.name);
    } else
    if (quad->addr2.kind == Val) {
        type t2 = getType(quad->addr2.contents.name+1, map);
        if (t2 == INTEGER) {
            if (quad->addr1.kind == IntConst) fprintf(out, "\tli $t0, %d\n", quad->addr1.contents.intVal);
            if (quad->addr1.kind == Val) {
                fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name+1);
                fprintf(out, "\tlw $t0, 0($t0)\n");
            }
            fprintf(out, "\tlw $t1, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\tsw $t0, 0($t1)\n");
        }
        if (t2 == FLOAT) {
            if (quad->addr1.kind == IntConst) {
                fprintf(out, "\tli $t0, %d\n", quad->addr1.contents.intVal);
                fprintf(out, "\tmtc1, $t0, $f0\n");
                fprintf(out, "\tcvt.s.w $f0, $f0\n");
            }
            if (quad->addr1.kind == FloatConst) fprintf(out, "\tli.s $f0, %f\n", quad->addr1.contents.floatVal);
            if (quad->addr1.kind == Val) {
                fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name+1);
                if (getType(quad->addr1.contents.name+1, map)==FLOAT) fprintf(out, "\tl.s $f0, 0($t0)\n");
                if (getType(quad->addr1.contents.name+1, map)==INTEGER) {
                    fprintf(out, "\tlw $t0, 0($t0)\n");
                    fprintf(out, "\tmtc1, $t0, $f0\n");
                    fprintf(out, "\tcvt.s.w $f0, $f0\n");
                }
            }
            fprintf(out, "\tlw $t0, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\ts.s $f0, 0($t0)\n");
        }
        if (t2 == DOUBLE) {
            if (quad->addr1.kind == IntConst) {
                fprintf(out, "\tli $t0, %d\n", quad->addr1.contents.intVal);
                fprintf(out, "\tmtc1, $t0, $f0\n");
                fprintf(out, "\tcvt.s.w $f0, $f0\n");
                fprintf(out, "\tcvt.d.s $f0, $f0\n");
            }
            if (quad->addr1.kind == FloatConst) {
                fprintf(out, "\tli.s $f0, %f\n", quad->addr1.contents.floatVal);
                fprintf(out, "\tcvt.d.s, $f0, $f0\n");
            }
            if (quad->addr1.kind == Val) {
                fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name+1);
                if (getType(quad->addr1.contents.name+1, map)==FLOAT) {
                    fprintf(out, "\tl.s $f0, 0($t0)\n");
                    fprintf(out, "\tcvt.d.s, $f0, $f0");
                }
                if (getType(quad->addr1.contents.name+1, map)==INTEGER) {
                    fprintf(out, "\tlw $t0, 0($t0)\n");
                    fprintf(out, "\tmtc1 $t0, $f0\n");
                    fprintf(out, "\tcvt.s.w $f0, $f0\n");
                    fprintf(out, "\tcvt.d.s $f0, $f0\n");
                }
                if (getType(quad->addr1.contents.name+1, map)==DOUBLE) fprintf(out, "\tl.d $f0, 0($t0)\n");
            }
            fprintf(out, "\tlw $t0, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\ts.d $f0, 0($t0)\n");
        }
    }
    if (quad->addr2.kind == Val && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = String;
        removeStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == Val && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = String;
        removeStar(quad->addr1.contents.name);
    }
}



//将加、减、乘法的三地址码语句转化为mips（已支持浮点数）
void genCAL(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# calculation\n");
    if (strcmp(quad->addr1.contents.name, "sp")==0) {
        if (quad->op == add) fprintf(out,"\taddi, $sp, $sp, %d\n", quad->addr2.contents.intVal);
        if (quad->op == sub) fprintf(out,"\taddi, $sp, $sp, -%d\n", quad->addr2.contents.intVal);
        return;
    }
    type t1 = UNDEFINED, t2 = UNDEFINED, t3 = UNDEFINED;
    if (quad->addr3.kind == String && getVar(quad->addr3.contents.name, map)) {
        addStar(quad->addr3.contents.name);
        quad->addr3.kind = Val;
    }
    if (quad->addr2.kind == String && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = Val;
        addStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == String && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = Val;
        addStar(quad->addr1.contents.name);
    }
    if (quad->addr3.kind == String) { //关于地址的计算
        if (quad->addr1.kind == IntConst) fprintf(out, "\tli $t1, %d\n", quad->addr1.contents.intVal);
        if (quad->addr1.kind == String) fprintf(out, "\tlw $t1, %s\n", quad->addr1.contents.name);
        if (quad->addr2.kind == IntConst) fprintf(out, "\tli $t2, %d\n", quad->addr2.contents.intVal);
        if (quad->addr2.kind == String) fprintf(out, "\tlw $t2, %s\n", quad->addr2.contents.name);
        if (quad->op == add) fprintf(out, "\tadd $t1, $t1, $t2\n");
        if (quad->op == sub) fprintf(out, "\tsub $t1, $t1, $t2\n");
        fprintf(out, "\tsw $t1, %s\n", quad->addr3.contents.name);
    }
    if (quad->addr3.kind == Val) { //关于值的计算
        t3 = getType(quad->addr3.contents.name+1, map);
        if (t3 == INTEGER) {
            if (quad->addr1.kind == IntConst) fprintf(out, "\tli $t1, %d\n", quad->addr1.contents.intVal);
            if (quad->addr1.kind == Val) {
                fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
                fprintf(out, "\tlw $t1, 0($t3)\n");
            }
            if (quad->addr2.kind == IntConst) fprintf(out, "\tli $t2, %d\n", quad->addr2.contents.intVal);
            if (quad->addr2.kind == Val) {
                fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
                fprintf(out, "\tlw $t2, 0($t3)\n");
            }
            if (quad->op == add) fprintf(out, "\tadd $t1, $t1, $t2\n");
            if (quad->op == sub) fprintf(out, "\tsub $t1, $t1, $t2\n");
            if (quad->op == mul) fprintf(out, "\tmul $t1, $t1, $t2\n");
            if (quad->op == dvd) fprintf(out, "\tdiv $t1, $t2\n");
            if (quad->op != dvd) {
                fprintf(out, "\tlw $t3, %s\n", quad->addr3.contents.name+1);
                fprintf(out, "\tsw $t1, 0($t3)\n");
            }
            if (quad->op == dvd) {
                fprintf(out, "\tlw $t3, %s\n", quad->addr3.contents.name+1);
                fprintf(out, "\tmflo $t2\n");
                fprintf(out, "\tsw $t2 0($t3)\n");
            }
        }
        if (t3 == FLOAT) {
            if (quad->addr1.kind == IntConst) fprintf(out, "\tli.s $f1, %d.0\n", quad->addr1.contents.intVal);
            if (quad->addr1.kind == FloatConst) fprintf(out, "\tli.s $f1, %f\n", quad->addr1.contents.floatVal);
            if (quad->addr1.kind == Val) {
                t1 = getType(quad->addr1.contents.name+1, map);
                fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
                if (t1 == FLOAT) fprintf(out, "\tl.s $f1, 0($t3)\n");
                if (t1 == INTEGER) {
                    fprintf(out, "lw $t1, 0($t3)\n");
                    fprintf(out, "\tmtc1 $t1, $f1\n");
                    fprintf(out, "\tcvt.s.w $f1, $f1\n");
                }
            }
            if (quad->addr2.kind == IntConst) fprintf(out, "\tli.s $f2, %d.0\n", quad->addr2.contents.intVal);
            if (quad->addr2.kind == FloatConst) fprintf(out, "\tli.s $f2, %f\n", quad->addr2.contents.floatVal);
            if (quad->addr2.kind == Val) { //要强制转换类型
                t2 = getType(quad->addr2.contents.name+1, map);
                fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
                if (t2 == FLOAT) fprintf(out, "\tl.s $f2, 0($t3)\n");
                if (t2 == INTEGER) {
                    fprintf(out, "\tlw $t2, 0($t3)\n");
                    fprintf(out, "\tmtc1 $t2, $f2\n");
                    fprintf(out, "\tcvt.s.w $f2, $f2\n");
                }
            }
            if (quad->op == add) fprintf(out, "\tadd.s $f3, $f1, $f2\n");
            if (quad->op == sub) fprintf(out, "\tsub.s $f3, $f1, $f2\n");
            if (quad->op == mul) fprintf(out, "\tmul.s $f3, $f1, $f2\n");
            if (quad->op == dvd) fprintf(out, "\tdiv.s $f3, $f1, $f2\n");
            fprintf(out, "\tlw $t3, %s\n", quad->addr3.contents.name+1);
            fprintf(out, "\ts.s $f3, 0($t3)\n");
        }
        if (t3 == DOUBLE) {
            if (quad->addr1.kind == IntConst) fprintf(out, "\tli.d $f0, %d.0\n", quad->addr1.contents.intVal);
            if (quad->addr1.kind == FloatConst) fprintf(out, "\tli.d $f0, %f\n", quad->addr1.contents.floatVal);
            if (quad->addr1.kind == Val) {
                t1 = getType(quad->addr1.contents.name+1, map);
                fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
                if (t1 == INTEGER) {
                    fprintf(out, "\tlw $t1, 0($t3)\n");
                    fprintf(out, "\tmtc1 $t1, $f0\n");
                    fprintf(out, "\tcvt.s.w $f0, $f0\n");
                    fprintf(out, "\tcvt.d.s $f0, $f0\n");
                }
                if (t1 == FLOAT) {
                    fprintf(out, "\tl.s $f0, 0($t3)\n");
                    fprintf(out, "\tcvt.d.s $f0, $f0\n");
                }
                if (t1 == DOUBLE) fprintf(out, "\tl.d $f0, 0($t3)\n");
            }
            if (quad->addr2.kind == IntConst) fprintf(out, "\tli.d $f2, %d.0\n", quad->addr2.contents.intVal);
            if (quad->addr2.kind == FloatConst) fprintf(out, "\tli.d $f2, %f\n", quad->addr2.contents.floatVal);
            if (quad->addr2.kind == Val) {
                t2 = getType(quad->addr2.contents.name+1, map);
                fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
                if (t2 == INTEGER) {
                    fprintf(out, "\tlw $t2, 0($t3)\n");
                    fprintf(out, "\tmtc1 $t2, $f2\n");
                    fprintf(out, "\tcvt.s.w $f2, $f2\n");
                    fprintf(out, "\tcvt.d.s $f2, $f2\n");
                }
                if (t2 == FLOAT) {
                    fprintf(out, "\tl.s $f2, 0($t3)\n");
                    fprintf(out, "\tcvt.d.s $f2, $f2\n");
                }
                if (t2 == DOUBLE) fprintf(out, "\tl.d $f2, 0($t3)\n");
            }
            if (quad->op == add) fprintf(out, "\tadd.d $f4, $f0, $f2\n");
            if (quad->op == sub) fprintf(out, "\tsub.d $f4, $f0, $f2\n");
            if (quad->op == mul) fprintf(out, "\tmul.d $f4, $f0, $f2\n");
            if (quad->op == dvd) fprintf(out, "\tdiv.d $f4, $f0, $f2\n");
            fprintf(out, "\tlw $t3, %s\n", quad->addr3.contents.name+1);
            fprintf(out, "\ts.d $f4, 0($t3)\n");
        }
    }
    if (quad->addr3.kind == Val && getVar(quad->addr3.contents.name, map)) {
        removeStar(quad->addr3.contents.name);
        quad->addr3.kind = String;
    }
    if (quad->addr2.kind == Val && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = String;
        removeStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == Val && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = String;
        removeStar(quad->addr1.contents.name);
    }
}

//生成读入的句子（已支持浮点数）
void genREAD(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# read\n");
    //    保存现场
    //    fprintf(out, "\taddi $sp, $sp, -4\n");
    //    fprintf(out, "\tsw $ra, 0($sp)\n");
    type t = getType(quad->addr1.contents.name, map);
    if (t == INTEGER) {
        fprintf(out, "\tli $v0, 5\n");
        fprintf(out, "\tsyscall\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tsw $v0, 0($t0)\n");
    }
    if (t == FLOAT) {
        fprintf(out, "\tli $v0, 6\n");
        fprintf(out, "\tsyscall\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\ts.s $f0, 0($t0)\n");
    }
    if (t == DOUBLE) {
        fprintf(out, "\tli $v0, 7\n");
        fprintf(out, "\tsyscall\n");
        fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
        fprintf(out, "\ts.d $f0, 0($t0)\n");
    }
    //    恢复现场
    //    fprintf(out, "\tlw $ra, 0($sp)\n");
    //    fprintf(out, "\taddi $sp, $sp, 4\n");
}

//生成输出的句子（已支持浮点数）
void genPRINT(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# print\n");
    //    保存现场
    //    fprintf(out, "\taddi $sp, $sp, -4\n");
    //    fprintf(out, "\tsw $ra, 0($sp)\n");
    
    fprintf(out, "\tlw $t0, %s\n", quad->addr1.contents.name);
    
    type t = getType(quad->addr1.contents.name, map);
    if (t == INTEGER) {
        fprintf(out, "\tlw $a0, 0($t0)\n");
        fprintf(out, "\tli $v0, 1\n");
        fprintf(out, "\tsyscall\n");
    }
    if (t == FLOAT) {
        fprintf(out, "\tl.s $f12, 0($t0)\n");
        fprintf(out, "\tli $v0, 2\n");
        fprintf(out, "\tsyscall\n");
    }
    if (t == DOUBLE) {
        fprintf(out, "\tl.d $f12, 0($t0)\n");
        fprintf(out, "\tli $v0, 3\n");
        fprintf(out, "\tsyscall\n");
    }
    if (quad->op == priln) {
        fprintf(out, "\tla $a0, endl\n");
        fprintf(out, "\tli $v0, 4\n");
        fprintf(out, "\tsyscall\n");
    }
    //    恢复现场
    //    fprintf(out, "\tlw $ra, 0($sp)\n");
    //    fprintf(out, "\taddi $sp, $sp, 4\n");
}

//标一个标签
void genLABEL(Quad* quad) {
    fprintf(out, "%s:\n", quad->addr1.contents.name);
}

//生成if_false跳转的语句
void genFJUMP(Quad* quad) {
    fprintf(out, "\t# if_false jump\n");
    if (strcmp(quad->addr1.contents.name, "$t7")==0) {
        fprintf(out, "\tadd $t1, $t7, $0\n");
    } else {
        fprintf(out, "\tlw $t1, %s\n", quad->addr1.contents.name);
        fprintf(out, "\tlw $t1, 0($t1)\n");
    }
    fprintf(out, "\tbeq $t1, $0, %s\n", quad->addr2.contents.name);
}

//直接goto
void genJUMP(Quad* quad) {
    fprintf(out, "\t# direct jump\n");
    fprintf(out, "\tj %s\n", quad->addr1.contents.name);
}

//生成比较的语句,结果只能为INTEGER？
void genCompare(Quad* quad, VariableMap* map) {
    fprintf(out, "\t# compare\n");
    if (quad->addr3.kind == String && getVar(quad->addr3.contents.name, map)) {
        addStar(quad->addr3.contents.name);
        quad->addr3.kind = Val;
    }
    if (quad->addr2.kind == String && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = Val;
        addStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == String && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = Val;
        addStar(quad->addr1.contents.name);
    }
    type t1 = UNDEFINED, t2 = UNDEFINED, t=UNDEFINED;
    if (quad->addr1.kind==Val) t1 = getType(quad->addr1.contents.name+1, map); else
        switch (quad->addr1.kind) {
            case IntConst: t1 = INTEGER; break;
            case FloatConst: t1 = FLOAT; break;
            default: break;
        }
    if (quad->addr2.kind==Val) t2 = getType(quad->addr2.contents.name+1, map); else
        switch (quad->addr2.kind) {
            case IntConst: t2 = INTEGER; break;
            case FloatConst: t2 = FLOAT; break;
            default: break;
        }
    if (t1==DOUBLE || t2 == DOUBLE)
        t=DOUBLE; else
            if (t1==FLOAT || t2 == FLOAT)
                t = FLOAT; else
                    if (t1==INTEGER && t2==INTEGER)
                        t = INTEGER;
    if (t == INTEGER) { //如果 a = b op c的b和c都是整形
        if (quad->addr1.kind == IntConst) fprintf(out, "\tli $t1, %d\n", quad->addr1.contents.intVal);
        if (quad->addr1.kind == Val) {
            fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
            fprintf(out, "\tlw $t1, 0($t3)\n");
        }
        if (quad->addr2.kind == IntConst) fprintf(out, "\tli $t2, %d\n", quad->addr2.contents.intVal);
        if (quad->addr2.kind == Val) {
            fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
            fprintf(out, "\tlw $t2, 0($t3)\n");
        }
        if (quad->op == sm) fprintf(out, "\tslt $t3, $t1, $t2\n"); //如果c=a<b且a确实小于b则t0=1否则t0=0
        if (quad->op == gt) fprintf(out, "\tslt $t3, $t2, $t1\n");
        if (quad->op == ne) {
            fprintf(out, "\tslt $t4, $t1, $t2\n");
            fprintf(out, "\tslt $t5, $t2, $t1\n");
            fprintf(out, "\tor $t3, $t4, $t5\n");
        }
        if (quad->op == eq) {
            fprintf(out, "\tslt $t4, $t1, $t2\n");
            fprintf(out, "\tslt $t5, $t2, $t1\n");
            fprintf(out, "\tnor $t3, $t4, $t5\n");
            fprintf(out, "\tandi $t3, $t3, 1\n");
        }
    }
    if (t == FLOAT) {
        if (quad->addr1.kind == IntConst) fprintf(out, "\tli.s $f0, %d.0\n", quad->addr1.contents.intVal);
        if (quad->addr1.kind == FloatConst) fprintf(out, "\tli.s $f0, %f\n", quad->addr1.contents.floatVal);
        if (quad->addr1.kind == Val) {
            t1 = getType(quad->addr1.contents.name+1, map);
            fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
            if (t1 == FLOAT) fprintf(out, "\tl.s $f0, 0($t3)\n");
            if (t1 == INTEGER) {
                fprintf(out, "lw $t1, 0($t3)\n");
                fprintf(out, "\tmtc1 $t1, $f0\n");
                fprintf(out, "\tcvt.s.w $f0, $f0\n");
            }
        }
        if (quad->addr2.kind == IntConst) fprintf(out, "\tli.s $f2, %d.0\n", quad->addr2.contents.intVal);
        if (quad->addr2.kind == FloatConst) fprintf(out, "\tli.s $f2, %f\n", quad->addr2.contents.floatVal);
        if (quad->addr2.kind == Val) { //要强制转换类型
            t2 = getType(quad->addr2.contents.name+1, map);
            fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
            if (t2 == FLOAT) fprintf(out, "\tl.s $f2, 0($t3)\n");
            if (t2 == INTEGER) {
                fprintf(out, "\tlw $t2, 0($t3)\n");
                fprintf(out, "\tmtc1 $t2, $f2\n");
                fprintf(out, "\tcvt.s.w $f2, $f2\n");
            }
        }
        if (quad->op == sm) fprintf(out, "\tc.lt.s 0, $f0, $f2\n");
        if (quad->op == gt) fprintf(out, "\tc.lt.s 0, $f2, $f0\n");
        if (quad->op == eq) fprintf(out, "\tc.eq.s 0, $f0, $f2\n");
        if (quad->op == ne) fprintf(out, "\tc.neq.s 0, $f2, $f0\n");
        fprintf(out, "\tli $t5, 1\n");
        fprintf(out, "\tli, $t3, 0\n");
        fprintf(out, "\tmovt $t3, $t5, 0\n");
    }
    if (t == DOUBLE) {
        if (quad->addr1.kind == IntConst) fprintf(out, "\tli.d $f0, %d.0\n", quad->addr1.contents.intVal);
        if (quad->addr1.kind == FloatConst) fprintf(out, "\tli.d $f0, %f\n", quad->addr1.contents.floatVal);
        if (quad->addr1.kind == Val) {
            t1 = getType(quad->addr1.contents.name+1, map);
            fprintf(out, "\tlw $t3, %s\n", quad->addr1.contents.name+1);
            if (t1 == INTEGER) {
                fprintf(out, "\tlw $t1, 0($t3)\n");
                fprintf(out, "\tmtc1 $t1, $f0\n");
                fprintf(out, "\tcvt.s.w $f0, $f0\n");
                fprintf(out, "\tcvt.d.s $f0, $f0\n");
            }
            if (t1 == FLOAT) {
                fprintf(out, "\tl.s $f0, 0($t3)\n");
                fprintf(out, "\tcvt.d.s $f0, $f0\n");
            }
            if (t1 == DOUBLE) fprintf(out, "\tl.d $f0, 0($t3)\n");
        }
        if (quad->addr2.kind == IntConst) fprintf(out, "\tli.d $f2, %d.0\n", quad->addr2.contents.intVal);
        if (quad->addr2.kind == FloatConst) fprintf(out, "\tli.d $f2, %f\n", quad->addr2.contents.floatVal);
        if (quad->addr2.kind == Val) {
            t2 = getType(quad->addr2.contents.name+1, map);
            fprintf(out, "\tlw $t3, %s\n", quad->addr2.contents.name+1);
            if (t2 == INTEGER) {
                fprintf(out, "\tlw $t2, 0($t3)\n");
                fprintf(out, "\tmtc1 $t2, $f2\n");
                fprintf(out, "\tcvt.s.w $f2, $f2\n");
                fprintf(out, "\tcvt.d.s $f2, $f2\n");
            }
            if (t2 == FLOAT) {
                fprintf(out, "\tl.s $f2, 0($t3)\n");
                fprintf(out, "\tcvt.d.s $f2, $f2\n");
            }
            if (t2 == DOUBLE) fprintf(out, "\tl.d $f2, 0($t3)\n");
        }
        if (quad->op == sm) fprintf(out, "\tc.lt.d 0, $f0, $f2\n");
        if (quad->op == gt) fprintf(out, "\tc.lt.d 0, $f2, $f0\n");
        if (quad->op == eq) fprintf(out, "\tc.eq.d 0, $f0, $f2\n");
        if (quad->op == eq) fprintf(out, "\tc.neq.d 0, $f0, $f2\n");
        fprintf(out, "\tli $t5, 1\n");
        fprintf(out, "\tli, $t3, 0\n");
        fprintf(out, "\tmovt $t3, $t5, 0\n");
    }
    if (strcmp(quad->addr3.contents.name, "$t7")==0) {
        fprintf(out, "\tadd $t7, $t3, $0\n");
        return;
    }
    t = getType(quad->addr3.contents.name+1, map);
    fprintf(out, "\tlw $t2, %s\n", quad->addr3.contents.name+1);
    if (t == INTEGER) fprintf(out, "\tsw $t3, 0($t2)\n");
    if (t == FLOAT) {
        fprintf(out, "\tmtc1 $t3, $f0\n");
        fprintf(out, "\tcvt.s.w $f0, $f0\n");
        fprintf(out, "\ts.s $f0, 0($t2)");
    }
    if (t == DOUBLE) {
        fprintf(out, "\tmtc1 $t3, $f0\n");
        fprintf(out, "\tcvt.s.w $f0, $f0\n");
        fprintf(out, "\tcvt.d.s $f0, $f0\n");
        fprintf(out, "\ts.d $f0, 0($t2)\n");
    }
    if (quad->addr3.kind == Val && getVar(quad->addr3.contents.name, map)) {
        removeStar(quad->addr3.contents.name);
        quad->addr3.kind = String;
    }
    if (quad->addr2.kind == Val && getVar(quad->addr2.contents.name, map)) {
        quad->addr2.kind = String;
        removeStar(quad->addr2.contents.name);
    }
    if (quad->addr1.kind == Val && getVar(quad->addr1.contents.name, map)) {
        quad->addr1.kind = String;
        removeStar(quad->addr1.contents.name);
    }
}

#endif
