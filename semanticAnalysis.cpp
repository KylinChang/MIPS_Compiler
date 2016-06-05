//
// Created by Orpine on 6/5/16.
//

#include <assert.h>
#include "semanticAnalysis.h"
#include "symbolTable.h"

list<SymbolTable*> symbolTableList;

void LOGERR(int cnt, ...) {
    va_list args;
    va_start(args, cnt);
    while (cnt--) {
        cout << va_arg(args, char*);
        cout << + " ";
    }
    cout << endl;
    va_end(args);
}

void sa_init() {
    // integer:
    typeName["byte"] = "byte";
    typeName["shortint"] = "shortint";
    typeName["smallint"] = "smallint";
    typeName["word"] = "word";
    typeName["integer"] = "longint";
    typeName["longint"] = "longint";
    typeName["cardinal"] = "dword";
    typeName["longword"] = "dword";
    typeName["dword"] = "dword";
    typeName["int64"] = "int64";
    typeName["qword"] = "qword";
    typeName["real"] = "real";
    typeName["real"] = "double";
    typeName["single"] = "single";
    typeName["double"] = "double";
    typeName["extended"] = "extended";
    typeName["comp"] = "int64";
    typeName["currency"] = "currency";
    typeName["boolean"] = "boolean";
    // NOTE: we do not support bytebool, wordbool and longbool
    typeName["char"] = "ansichar";
    typeName["ansichar"] = "ansichar";
    typeName["true"] = "boolean";
    typeName["false"] = "boolean";
    typeName["maxlongint"] = "longint";
    typeName["maxint"] = "longint";

    // NOTE: we do not support widechar and string
//    typeName["widechar"] = "widechar";
//    typeName["string"] = "string"

}

Type parseType(NODE* root) {
    assert(root->type == TK_TYPE_DECL);
    root = root->child[0];
    if (root->child[0]->type == TK_STD_SYS_TYPE) {
        return Type(root->child[0]->child[0]->name);
    } else if (root->child[0]->type == TK_STD_ID) {
        auto x = symbolTableList.front()->findType(root->child[0]->child[0]->name);
        if (x.null) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined type");
        }
    }
}


void constAnalysis(NODE** constList, int constListNum) {
    for (int i = 0; i < constListNum; i++) {
        string identifier = constList[i]->child[0]->name;
        Value val = *(constList[i]->child[1]->value);
        if (!(symbolTableList.front()->insertConst(identifier, val))) {
            LOGERR(4, "error in line", to_string(constList[i]->child[0]->lineno).c_str(), ":", "duplicate identifer");
        }
    }
}

void typeAnalysis(NODE** typeList, int typeListNum) {
    for (int i = 0; i < typeListNum; i++) {
        string identifier = typeList[i]->child[0]->name;
        Type val = parseType(typeList[i]->child[1]);
        if (!(symbolTableList.front()->insertType(identifier, val))) {
            LOGERR(4, "error in line", to_string(typeList[i]->child[0]->lineno).c_str(), ":", "duplicate identifer");
        }
    }
}

void varAnalysis(NODE* root) {
    if (root == NULL) {
        return;
    }
}

void routineAnalysis(NODE* root) {
    symbolTableList.push_front(new SymbolTable());
    // routineHead
    NODE* routineHead = root->child[0];
    // CONST
    if (routineHead->child[0]) {
        constAnalysis(routineHead->child[0]->child, routineHead->child[0]->child_number);
    }
    // TYPE
    if (routineHead->child[1]) {
        typeAnalysis(routineHead->child[1]->child, routineHead->child[1]->child_number);
    }
    // VAR
    varAnalysis(routineHead->child[2]);
    // ROUTINE
    if (routineHead->child[3]) {

        for (int i = 0; i < routineHead->child[3]->child_number; i++) {
            NODE* routineNode = routineHead->child[3]->child[i];
            if (routineNode->type == TK_PROC_DECL) {
                NODE* funcHead = routineNode->child[0];

            } else if (routineNode->type == TK_FUNC_DECL) {

            } else {
                LOGERR(4, "error in", to_string(routineNode->lineno).c_str(), ":", "unsupported token");
            }
        }
    }
    // routineBody
    NODE* routineBody = root->child[1];


    symbolTableList.pop_front();
}

int main(int argc, char** argv){
//    char FILENAME[100];
//    printf("Please input the test file: ");
//    scanf("%s", FILENAME);

    FILE* file = fopen("./TestCases/test8.pas", "r");
    yyin = file;

    node_init();
    yyparse();

    sa_init();
    routineAnalysis(ROOT->child[1]);

    return 0;
}