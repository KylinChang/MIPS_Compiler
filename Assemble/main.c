#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gen.h"

FILE* fp;
FILE* out;
int stackoffset = 0;
VariableMap map;
QuadTable text;
LabelTable lb;

int getElement(char* src, int* head, char* dst);
void addVariable(VariableMap* map, char* name, type vartype, char* initval);
void addArray(VariableMap* map, char* name, int space);
void addLabel(char* name, LabelTable* lb);
AddrKind getKind(char* name);
type getType(char* name, VariableMap* map);
void changeType(Quad* quad, VariableMap* map);
void changeVar(Quad* quad, VariableMap* map);
void genASN(Quad* quad, VariableMap* map);
void genCAL(Quad* quad, VariableMap* map);
void genPRINT(Quad* quad, VariableMap* map);
void genREAD(Quad* quad, VariableMap* map);
void genLABEL(Quad* quad);
void genFJUMP(Quad* quad);
void genJUMP(Quad* quad);
void genFUNC(Quad* quad);
void genCALL(Quad* quad);
void genRET(Quad* quad);
void genARG(Quad* quad, VariableMap* map);
void genVAR(Quad* quad, VariableMap* map);
void genCompare(Quad* quad, VariableMap* map);
void declareVariable(VariableMap* map);

int main() {
    char code[100];
    char elements[10][100];
    int i;
    memset(code, 0, sizeof(code));
    fp = fopen("/Users/petertam/Desktop/in.txt","r");
    out = fopen("/Users/petertam/Desktop/out.asm", "w");
    //定义变量 提取语句
    while (fgets(code, 100, fp) != NULL) {
        code[strlen(code)-1]='\0';
        int p = 0;
        int cnt = 0;
        memset(elements, 0, sizeof(elements));
        while (getElement(code, &p, elements[cnt]) > 0) cnt++;
        Quad quad;
        //如果三地址码定义了一个int
        if (strcmp(elements[0], "int")==0) {
            addVariable(&map, elements[1], INTEGER, elements[2]);
        }
        //如果三地址码定义了一个float
        if (strcmp(elements[0], "float")==0) {
            addVariable(&map, elements[1], FLOAT, elements[2]);
        }
        //如果三地址码定义了一个string
        if (strcmp(elements[0], "string")==0) {
            addVariable(&map, elements[1], STRING, elements[2]);
        }
        //如果三地址码定义了一个double
        if (strcmp(elements[0], "double")==0) {
            addVariable(&map, elements[1], DOUBLE, elements[2]);
        }
        //如果三地址码第一个元素是malloc
        if (strcmp(elements[0], "malloc")==0) {
            addArray(&map, elements[1], atoi(elements[2]));
        }
        if (strcmp(elements[0], "call")==0) {
            strcpy(quad.addr1.contents.name, elements[1]);
            quad.addr1.kind = String;
            quad.op = call;
            text.quad[text.num] = quad;
            text.num++;
        }
        //如果三地址码第一个元素是read
        if (strcmp(elements[0], "read")==0) {
            strcpy(quad.addr1.contents.name, elements[1]);
            quad.addr1.kind = getKind(elements[0]);
            quad.op = rd;
            text.quad[text.num] = quad;
            text.num++;
        }
        if (strcmp(elements[0], "var")==0) {
            quad.op = var;
            quad.addr1.kind = String;
            quad.addr1.kind = String;
            strcpy(quad.addr1.contents.name, elements[1]);
            strcpy(quad.addr2.contents.name, elements[2]);
            text.quad[text.num] = quad;
            text.num++;
        }
        //如果三地址码第一个元素是print
        if (strcmp(elements[0], "print")==0) {
            //***有可能输出常量***记得补充
            strcpy(quad.addr1.contents.name, elements[1]);
            quad.addr1.kind = getKind(elements[1]);
            quad.op = pri;
            text.quad[text.num] = quad;
            text.num++;
        }
        //如果三地址码第一个元素是println
        if (strcmp(elements[0], "println")==0) {
            //***有可能输出常量***记得补充
            strcpy(quad.addr1.contents.name, elements[1]);
            quad.addr1.kind = getKind(elements[1]);
            quad.op = priln;
            text.quad[text.num] = quad;
            text.num++;
        }
        //判断语句
        if (strcmp(elements[0], "if_false")==0) {
            quad.addr1.kind = String;
            quad.addr2.kind = String;
            strcpy(quad.addr1.contents.name, elements[1]);
            strcpy(quad.addr2.contents.name, elements[3]);
            quad.op = if_f;
            text.quad[text.num] = quad;
            text.num++;
        }
        //添加一个标签
        if (strcmp(elements[0], "label")==0) {
            addLabel(elements[1], &lb);
            quad.op = lab;
            quad.addr1.kind = String;
            strcpy(quad.addr1.contents.name, elements[1]);
            text.quad[text.num] = quad;
            text.num++;
        }
        //改变指针类型
        if (strcmp(elements[0], "point")==0) {
            quad.op = dec;
            quad.addr1.kind = String;
            quad.addr2.kind = String;
            strcpy(quad.addr1.contents.name, elements[1]);
            strcpy(quad.addr2.contents.name, elements[2]);
            text.quad[text.num] = quad;
            text.num++;
        }
        //直接跳转语句
        if (strcmp(elements[0], "goto")==0) {
            quad.op = jump;
            strcpy(quad.addr1.contents.name, elements[1]);
            text.quad[text.num] = quad;
            text.num++;
        }
        //如果是函数名（那最好有个main)
        if (strcmp(elements[0], "entry")==0) {
            quad.op = func;
            strcpy(quad.addr1.contents.name, elements[1]);
            text.quad[text.num] = quad;
            text.num++;
        }
        //返回地址
        if (strcmp(elements[0], "ret")==0) {
            quad.op = ret;
            text.quad[text.num] = quad;
            text.num++;
        }
        //如果是sp
        if (strcmp(elements[0], "sp")==0) {
            if (strcmp(elements[3], "+")==0) quad.op = add;
            if (strcmp(elements[3], "-")==0) quad.op = sub;
            strcpy(quad.addr1.contents.name, "sp");
            quad.addr2.contents.intVal = atoi(elements[4]);
            text.quad[text.num] = quad;
            text.num++;
            continue;
        }
        //判断 + 跳转语句 if a == b then goto label 关键是拆成两句话
        if (strcmp(elements[0], "if")==0) {
            //先比较
            //eq赋值为相同
            if (strcmp(elements[2], "==")==0) quad.op = eq;
            if (strcmp(elements[2], "!=")==0) quad.op = ne;
            //gt赋值为大于
            if (strcmp(elements[2], ">")==0) quad.op = gt;
            //gt赋值为小于
            if (strcmp(elements[2], "<")==0) quad.op = sm;
            quad.addr1.kind = getKind(elements[1]);
            quad.addr2.kind = getKind(elements[3]);
            quad.addr3.kind = String;
            if (quad.addr1.kind == IntConst) quad.addr1.contents.intVal = atoi(elements[1]);
            if (quad.addr1.kind == FloatConst) quad.addr1.contents.doubleVal = atof(elements[1]);
            if (quad.addr1.kind != IntConst && quad.addr1.kind != FloatConst) strcpy(quad.addr1.contents.name, elements[1]);

            if (quad.addr2.kind == IntConst) quad.addr2.contents.intVal = atoi(elements[3]);
            if (quad.addr2.kind == FloatConst) quad.addr2.contents.doubleVal = atof(elements[3]);
            if (quad.addr2.kind != IntConst && quad.addr2.kind != FloatConst) strcpy(quad.addr2.contents.name, elements[3]);
            strcpy(quad.addr3.contents.name, "$t7");
            text.quad[text.num] = quad;
            text.num++;
            //再跳转
            memset(&quad, 0, sizeof(Quad));
            quad.addr1.kind = String;
            quad.addr2.kind = String;
            strcpy(quad.addr1.contents.name, "$t7");
            strcpy(quad.addr2.contents.name, elements[6]);
            quad.op = if_f;
            text.quad[text.num] = quad;
            text.num++;
        }
        if (strcmp(elements[0], "arg")==0) {
            quad.op = arg;
            if (elements[1][0]=='*')
                strcpy(quad.addr1.contents.name, elements[1]+1);
            else
                strcpy(quad.addr1.contents.name, elements[1]);
            quad.op = arg;
            text.quad[text.num] = quad;
            text.num++;
        }
        //赋值语句
        if (strcmp(elements[1], "=")==0) {
            quad.addr1.kind = getKind(elements[2]);
            quad.addr2.kind = getKind(elements[4]);
            if (quad.addr1.kind == IntConst) quad.addr1.contents.intVal = atoi(elements[2]);
            if (quad.addr1.kind == FloatConst) quad.addr1.contents.floatVal = atof(elements[2]);
            if (quad.addr1.kind != IntConst && quad.addr1.kind != FloatConst) strcpy(quad.addr1.contents.name, elements[2]);
            if (quad.addr2.kind == IntConst) quad.addr2.contents.intVal = atoi(elements[4]);
            if (quad.addr2.kind == FloatConst) quad.addr2.contents.floatVal = atof(elements[4]);
            if (quad.addr2.kind != IntConst && quad.addr2.kind != FloatConst) strcpy(quad.addr2.contents.name, elements[4]);
            //eq赋值为相同
            if (strcmp(elements[3], "==")==0) quad.op = eq;
            if (strcmp(elements[3], "!=")==0) quad.op = ne;
            //gt赋值为大于
            if (strcmp(elements[3], ">")==0) quad.op = gt;
            //gt赋值为小于
            if (strcmp(elements[3], "<")==0) quad.op = sm;
            //mul乘法
            if (strcmp(elements[3], "*")==0) quad.op = mul;
            //add加法
            if (strcmp(elements[3], "+")==0) quad.op = add;
            //sub减法
            if (strcmp(elements[3], "-")==0) quad.op = sub;
            //dvd除法
            if (strcmp(elements[3], "/")==0) quad.op = dvd;
            //单纯赋值 根本没有计算
            if (strlen(elements[3]) == 0) {
                quad.op = asn;
                quad.addr2.kind = getKind(elements[0]);
                strcpy(quad.addr2.contents.name, elements[0]);
            }
            if (quad.op != asn) {
                quad.addr3.kind = getKind(elements[0]);
                strcpy(quad.addr3.contents.name, elements[0]);
            }
            text.quad[text.num] = quad;
            text.num++;
        }
    }
    //输出变量的MIPS
    declareVariable(&map);
    //处理开头
    fprintf(out, ".text\n");
    //处理语句
    for (i=0; i<text.num; i++) {
        if (text.quad[i].op == asn) genASN(text.quad+i, &map);
        if (text.quad[i].op == pri || text.quad[i].op == priln) genPRINT(text.quad+i, &map);
        if (text.quad[i].op == rd) genREAD(text.quad+i, &map);
        if (text.quad[i].op == add || text.quad[i].op == mul || text.quad[i].op == sub || text.quad[i].op == dvd) genCAL(text.quad+i, &map);
        if (text.quad[i].op == gt || text.quad[i].op == sm || text.quad[i].op == eq || text.quad[i].op == ne) genCompare(text.quad+i, &map);
        if (text.quad[i].op == lab) genLABEL(text.quad+i);
        if (text.quad[i].op == if_f) genFJUMP(text.quad+i);
        if (text.quad[i].op == dec) changeType(text.quad+i, &map);
        if (text.quad[i].op == var) genVAR(text.quad+i, &map);
        if (text.quad[i].op == jump) genJUMP(text.quad+i);
        if (text.quad[i].op == func) genFUNC(text.quad+i);
        if (text.quad[i].op == ret) genRET(text.quad+i);
        if (text.quad[i].op == call) genCALL(text.quad+i);
        if (text.quad[i].op == arg) genARG(text.quad+i, &map);
    }
    //退出主程序
    fprintf(out, "\tjr $ra\n");
    fclose(fp);
    fclose(out);
    return 0;
}