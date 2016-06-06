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
        cerr << va_arg(args, char*);
        cerr << " ";
    }
    cerr << endl;
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
    typeName["string"] = "string";

    // NOTE: we do not support widechar
//    typeName["widechar"] = "widechar";

}


void parseFPType(NODE* root, bool isFunc) {
#ifdef DEBUG
    assert(root->child[0]->type == TK_ID);
    assert(root->child[1] == NULL || root->child[1]->type == TK_PARA_DL);
    assert(!isFunc || root->child[2]->type == TK_TYPE_DECL);
#endif
    string identifier = root->child[0]->name;
    // travel TK_PARA_DL
    vector<Type> argTypeList;
    if (root->child[1] != NULL) {
        for (int i = 0; i < root->child[1]->child_number; i++) {
            auto x = root->child[1]->child[i];
#ifdef DEBUG
            assert(x->type == TK_PARA_TL_VAL || x->type == TK_PARA_TL_VAR);
            assert(x->child[0]->type == TK_NL);
            assert(x->child[1]->type == TK_TYPE_DECL);
#endif
            Type t = parseType(x->child[1]);
            for (int j = 0; j < x->child[0]->child_number; j++) {
                argTypeList.push_back(t);
            }
        }
    }
    if (isFunc) {
        symbolTableList.front()->insertVar(identifier, Type(argTypeList, parseType(root->child[2]), 1));
    } else {
        symbolTableList.front()->insertVar(identifier, Type(argTypeList, Type()));
    }
}


void prepareForFP(NODE* root) {
#ifdef DEBUG
    assert(root->child[0]->type == TK_ID);
    assert(root->child[1] == NULL || root->child[1]->type == TK_PARA_DL);
    assert(!isFunc || root->child[2]->type == TK_TYPE_DECL);
#endif
    if (root->child[1] != NULL) {
        for (int i = 0; i < root->child[1]->child_number; i++) {
            auto x = root->child[1]->child[i];
#ifdef DEBUG
            assert(x->type == TK_PARA_TL_VAL || x->type == TK_PARA_TL_VAR);
            assert(x->child[0]->type == TK_NL);
            assert(x->child[1]->type == TK_TYPE_DECL);
#endif
            Type t = parseType(x->child[1]);
            for (int j = 0; j < x->child[0]->child_number; j++) {
                if (symbolTableList.front()->insertVar(x->child[0]->child[j]->name, t)) {
                    LOGERR(4, "error in line", to_string(x->lineno).c_str(), ":", "duplicate variable name");
                }
            }
        }
    }
}

void parseRecord(unordered_map<string, Type> &nameMap, NODE* root) {

#ifdef DEBUG
    assert(root->type == TK_FIELD_DECL);
    assert(root->child[0]->type == TK_NL);
    assert(root->child[1]->type == TK_TYPE_DECL);
#endif

    Type nameListType = parseType(root->child[1]);
    for (int i = 0; i < root->child[0]->child_number; i++) {
        auto name = root->child[0]->child[i]->name;
        if (nameMap.find(name) != nameMap.end()) {
            LOGERR(4, "error in line", to_string(root->child[0]->child[i]->lineno).c_str(), ":", "duplicate name");
        }
        nameMap[name] = nameListType;
    }
}

Type parseType(NODE* root) {
    // TYPE_DECL->child
    root = root->child[0];
    if (root->type == TK_STD_SYS_TYPE) {
        return Type(typeName[root->child[0]->name]);
    } else if (root->type == TK_STD_ID) {
        auto x = symbolTableList.front()->findType(root->child[0]->name);
        if (x.null) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined type");
        }
        return x;
    } else if (root->type == TK_STD_NL) {
        vector<string> x;
        for (int i = 0; i < root->child[0]->child_number; i++) {
            x.push_back(root->child[0]->child[i]->name);
            if (symbolTableList.front()->insertEnum(root->child[0]->child[i]->name)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate enum item");
            }
        }
        return Type(x);
    } else if (root->type == TK_STD_DD) {
        Value a = root->child[0]->value, b = root->child[1]->value;
        if (a.type != b.type) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range data type mismatch");
        }
        return Type(a.type, a, b);
    } else if (root->type == TK_STD_DD_ID) {
        // NOTE: here a and b must be const
        Value a = symbolTableList.front()->findConst(root->child[0]->name), b = symbolTableList.front()->findConst(root->child[1]->name);
        if (a.type != b.type) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range data type mismatch");
        }
        if (a.type == type_string || a.type == type_real) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unsupported range data type");
        }
        if (b < a) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "lhs value must be smaller than rhs value in range");
        }
        return Type(a.type, a, b);
    } else if (root->type == TK_FIELD_DL) {
//        LOGERR(1, "reach record decl");
        auto nameMap = unordered_map<string, Type>();
        for (int i = 0; i < root->child_number; i++) {
            parseRecord(nameMap, root->child[i]);
        }
        return Type(nameMap);
    } else if (root->type == TK_ARRAY) {
//        LOGERR(1, "reach array decl");
#ifdef DEBUG
        assert(root->child[0]->type == TK_TYPE_DECL);
        assert(root->child[1]->type == TK_TYPE_DECL);
#endif
        Type a = parseType(root->child[0]);
        assert(!a.isSimpleType && a.complexType->complexType == type_range);
        Type b = parseType(root->child[1]);
        return Type(a.complexType->rangeType.start.ival, a.complexType->rangeType.end.ival, b);
    } else {
        LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown type");
    }
}


void constAnalysis(NODE** constList, int constListNum) {
    for (int i = 0; i < constListNum; i++) {
        string identifier = constList[i]->child[0]->name;
        Value val = constList[i]->child[1]->value;
        if ((symbolTableList.front()->insertConst(identifier, val))) {
            LOGERR(4, "error in line", to_string(constList[i]->child[0]->lineno).c_str(), ":", "duplicate identifer");
        }
    }
}

void typeAnalysis(NODE** typeList, int typeListNum) {
    for (int i = 0; i < typeListNum; i++) {
#ifdef DEBUG
        assert(typeList[i]->type == TK_DEF);
        assert(typeList[i]->child[0]->type == TK_ID);
        assert(typeList[i]->child[1]->type == TK_TYPE_DECL);
#endif
        string identifier = typeList[i]->child[0]->name;
        Type val = parseType(typeList[i]->child[1]);
        if ((symbolTableList.front()->insertType(identifier, val))) {
            // NOTE: here we think type override is legal
//            LOGERR(4, "error in line", to_string(typeList[i]->child[0]->lineno).c_str(), ":", "duplicate identifer");
        }
    }
}

void varAnalysis(NODE** varList, int varListNum) {
    for (int i = 0; i < varListNum; i++) {
#ifdef DEBUG
        assert(varList[i]->type == TK_VAR_DECL);
        assert(varList[i]->child[0]->type == TK_NL);
        assert(varList[i]->child[1]->type == TK_TYPE_DECL);
#endif
        Type nameListType = parseType(varList[i]->child[1]);
        for (int j = 0; j < varList[i]->child[0]->child_number; j++) {
            symbolTableList.front()->insertVar(varList[i]->child[0]->child[j]->name, nameListType);
        }
    }
}

void routineAnalysis(NODE* root) {
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
    if (routineHead->child[2]) {
        varAnalysis(routineHead->child[2]->child, routineHead->child[2]->child_number);
    }
    // ROUTINE
    if (routineHead->child[3]) {
        for (int i = 0; i < routineHead->child[3]->child_number; i++) {
            NODE* routineNode = routineHead->child[3]->child[i];
#ifdef DEBUG
            assert(routineNode->type == TK_PROC_DECL || routineNode->type == TK_FUNC_DECL);
            assert(routineNode->child[0]->type == TK_PROC_HEAD || routineNode->child[0]->type == TK_FUNC_HEAD);
            assert(routineNode->child[1]->type == TK_ROUTINE);
#endif
            parseFPType(routineNode->child[0], routineNode->type == TK_FUNC_DECL);
            symbolTableList.push_front(new SymbolTable(symbolTableList.front()));
            prepareForFP(routineNode->child[0]);
            routineAnalysis(routineNode->child[1]);
            symbolTableList.pop_front();
        }
    }
    // routineBody
    NODE* routineBody = root->child[1];


}


void semanticAnalysis(NODE* ROOT) {
    if (ROOT != NULL) {
        sa_init();
        symbolTableList.push_front(nullptr);
        symbolTableList.push_front(new SymbolTable(symbolTableList.front()));
        routineAnalysis(ROOT->child[1]);
        symbolTableList.pop_front();
    }
}

int main(int argc, char** argv){
//    char FILENAME[100];
//    printf("Please input the test file: ");
//    scanf("%s", FILENAME);

    FILE* file = fopen("./TestCases/test9.pas", "r");
    yyin = file;

    node_init();
    yyparse();

    semanticAnalysis(ROOT);

    return 0;
}