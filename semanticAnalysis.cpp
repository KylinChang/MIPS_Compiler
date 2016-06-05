//
// Created by Orpine on 6/5/16.
//

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



void constAnalysis(NODE** constList, int constListNum) {
    for (int i = 0; i < constListNum; i++) {
        string identifier = constList[i]->child[0]->name;
        NODE* valNode = constList[i]->child[1];
        Value val;
        switch (valNode->type) {
            case TK_INTEGER:
                val = Value(valNode->ival);
                break;
            case TK_REAL:
                val = Value(valNode->dval);
                break;
            case TK_CHAR:
                val = Value(valNode->ch);
            // TODO: support string
            case TK_STRING:
                break;
            case TK_SYS_CON:
                if (valNode->name)
            default:
                LOGERR(3, "error in", to_string(valNode->lineno), ":", "unsupport data type");

        }
//        Value val = Value(constList[i]->child[1].)
    }
}

void typeAnalysis(NODE* root) {
    if (root == NULL) {
        return;
    }
}

void varAnalysis(NODE* root) {
    if (root == NULL) {
        return;
    }
}

void routineAnalysis(NODE* root) {
    symbolTableList.push_front(new SymbolTable());
    // CONST
    if (root->child[0] != NULL) {
        constAnalysis(root->child[0]->child, root->child[0]->child_number);
    }
    // TYPE
    typeAnalysis(root->child[1]);
    // VAR
    varAnalysis(root->child[2]);
    // ROUTINE
    if (root->child[3]) {
        for (int i = 0; i < root->child_number; i++) {

        }
    }

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