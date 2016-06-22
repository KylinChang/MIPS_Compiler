//
// Created by Orpine on 6/5/16.
//

#include <assert.h>
#include "semanticAnalysis.h"
#include "symbolTable.h"
#include "common.h"

list<SymbolTable*> symbolTableList;
unordered_map<string, string> typeName;
int semanticAnalysisError = 0;


void LOGERR(int cnt, ...) {
    semanticAnalysisError++;
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

    semanticAnalysisError = 0;

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
    // NOTE: we do not support comp and currency
//    typeName["comp"] = "int64";
//    typeName["currency"] = "currency";
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

//    SYS_FUNCT "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
    // finally, MIPS vm do not implement these function, so we do not support them
//    symbolTableList.front()->insertFunc("abs", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("longint"), 1));
//    symbolTableList.front()->insertFunc("abs", Type(vector<Type>{Type("double")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("chr", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("char"), 1));
//    symbolTableList.front()->insertFunc("ord", Type(vector<Type>{Type("char")}, vector<bool>{false}, Type("longint"), 1));
//    symbolTableList.front()->insertFunc("odd", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("boolean"), 1));
//    symbolTableList.front()->insertFunc("sqr", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("sqr", Type(vector<Type>{Type("double")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("sqrt", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("sqrt", Type(vector<Type>{Type("double")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("pred", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("double"), 1));
//    symbolTableList.front()->insertFunc("succ", Type(vector<Type>{Type("longint")}, vector<bool>{false}, Type("double"), 1));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("longint")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("double")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("char")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("string")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("longint")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("double")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("char")}, vector<bool>{true}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("string")}, vector<bool>{true}, Type()));
//    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("longint")}, Type()));
//    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("double")}, Type()));
//    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("char")}, Type()));
//    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("string")}, Type()));
//    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("longint")}, Type()));
//    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("double")}, Type()));
//    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("char")}, Type()));
//    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("string")}, Type()));
////



}

bool typeMatch(const Type &a, const Type &b) {
    if (a.isSimpleType && b.isSimpleType) {
        if (a.simpleType->simpleType == b.simpleType->simpleType) {
            return true;
        } else if ((a.simpleType->simpleType == type_integer || a.simpleType->simpleType == type_real) &&
                   (b.simpleType->simpleType == type_integer || b.simpleType->simpleType == type_real)) {
            return true;
        }
        return false;
    }
    if (!a.isSimpleType && !b.isSimpleType) {
        if (a.complexType->complexType == type_record) {
            // NOTE:
            return a == b;
        } else {
            // NOTE: here we do not check the integer is actually in the enum range
            return a.complexType->complexType == type_enum && b.isSimpleType && b.simpleType->simpleType == type_integer;
        }
    }
    return false;
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
    vector<bool> argVarList;
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
                argVarList.push_back(x->type == TK_PARA_TL_VAR);
            }
        }
    }
    if (isFunc) {
        if (symbolTableList.front()->insertFunc(identifier, Type(argTypeList, argVarList, parseType(root->child[2]), 1))) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate function definition");
        }
//        if (symbolTableList.front()->insertVar(identifier, Type(argTypeList, parseType(root->child[2]), 1))) {
//            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown error");
//        }
    } else {
        if (symbolTableList.front()->insertFunc(identifier, Type(argTypeList, argVarList, Type()))) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate procedure definition");
        }
//        if (symbolTableList.front()->insertVar(identifier, Type(argTypeList, Type()))) {
//            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown error");
//        }
    }
}


void prepareForFP(NODE* root, bool isFunc) {
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
    // NOTE: we only insert a var when it is a func
    if (isFunc) {
        if (symbolTableList.front()->insertVar(identifier, parseType(root->child[2]))) {
        // if (symbolTableList.front()->insertVar(identifier, Type(argTypeList, parseType(root->child[2])))) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown error");
        }
    }

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
                if (symbolTableList.front()->insertVar(x->child[0]->child[j]->name, t, true)) {
                    LOGERR(4, "error in line", to_string(x->lineno).c_str(), ":", "duplicate parameter name");
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
            LOGERR(4, "error in line", to_string(root->child[0]->child[i]->lineno).c_str(), ":", "duplicate field name");
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
        auto x = findType(symbolTableList.front(), root->child[0]->name, root->child[0]);
        if (x.null) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined type");
            return Type();
        }
        return x;
    } else if (root->type == TK_STD_NL) {
        vector<string> x;
        for (int i = 0; i < root->child[0]->child_number; i++) {
            x.push_back(root->child[0]->child[i]->name);
            // check name should be undefined
            if (!findType(symbolTableList.front(), root->child[0]->child[i]->name, root->child[0]->child[i]).null) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "invalid enum item identifer");
                return Type();
            }
            auto t = findId(symbolTableList.front(), root->child[0]->child[i]->name);
            if (!t.first.null || !t.second.invalid) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "invalid enum item identifer");
                return Type();
            }
            if (symbolTableList.front()->insertEnum(root->child[0]->child[i]->name)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate enum item");
                return Type();
            }
        }
        return Type(x);
    } else if (root->type == TK_STD_DD) {
        Value a = root->child[0]->value, b = root->child[1]->value;
        if (a.type != b.type) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range data type mismatch");
            return Type();
        }
        if (a.type == type_string || a.type == type_real) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unsupported range data type");
            return Type();
        }
        if (b < a) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "illegal range");
            return Type();
        }
        return Type(a.type, a, b);
    } else if (root->type == TK_STD_DD_ID) {
        // check id is const
        if (!findType(symbolTableList.front(), root->child[0]->name, root->child[0]).null) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range definition must be const");
            return Type();
        }
        auto x = findId(symbolTableList.front(), root->child[0]->name), y = findId(symbolTableList.front(), root->child[1]->name);
        if (!x.first.null || !y.first.null) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range definition must be const");
            return Type();
        }
        // NOTE: here a and b must be const
        Value a = findConst(symbolTableList.front(), root->child[0]->name, root->child[0]), b = findConst(symbolTableList.front(), root->child[1]->name, root->child[1]);
        if (a.invalid || b.invalid) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined const identifier");
            return Type();
        }
        if (a.type != b.type) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range data type mismatch");
            return Type();
        }
        if (a.type == type_string || a.type == type_real) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unsupported range data type");
            return Type();
        }
        if (root->child[0]->type == TK_ID_MINUS) {
            a.ival = -a.ival;
        }
        if (root->child[1]->type == TK_ID_MINUS) {
            b.ival = -b.ival;
        }
        if (b < a) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "illegal range");
            return Type();
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
    }
    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown type");
    return Type();
}

Value parseConst(NODE* root) {
    if (root->type == TK_ID) {
        return findConst(symbolTableList.front(), root->name, root);
    } else {
        return root->value;
    }
}


void constAnalysis(NODE** constList, int constListNum) {
    for (int i = 0; i < constListNum; i++) {
        string identifier = constList[i]->child[0]->name;
        Value val = constList[i]->child[1]->value;
        if (!symbolTableList.front()->findVar(identifier).null || symbolTableList.front()->insertConst(identifier, val)) {
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
        if (!symbolTableList.front()->findConst(identifier).invalid || (symbolTableList.front()->insertType(identifier, val))) {
            LOGERR(4, "error in line", to_string(typeList[i]->child[0]->lineno).c_str(), ":", "duplicate identifer");
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
            if (!symbolTableList.front()->findConst(varList[i]->child[0]->child[j]->name).invalid ||
                !symbolTableList.front()->findType(varList[i]->child[0]->child[j]->name).null ||
                symbolTableList.front()->insertVar(varList[i]->child[0]->child[j]->name, nameListType)) {
                LOGERR(4, "error in line", to_string(varList[i]->child[0]->child[j]->lineno).c_str(), ":", "duplicate identifer");
            }
        }
    }
}

Type upcast(const Type &a, const Type &b) {
    if (a.isSimpleType && b.isSimpleType) {
        if (a.simpleType->simpleType == type_string && b.simpleType->simpleType == type_string) {
            return Type("string");
        }
        if (a.simpleType->simpleType == type_char && b.simpleType->simpleType == type_char) {
            return Type("char");
        }
        if (a.simpleType->simpleType == type_integer && b.simpleType->simpleType == type_integer) {
            if (a.simpleType->intType == t_int64 || a.simpleType->intType == t_qword ||
                b.simpleType->intType == t_int64 || b.simpleType->intType == t_qword) {
                return Type("int64");
            }
            if (a.simpleType->intType == t_longint || a.simpleType->intType == t_dword ||
                b.simpleType->intType == t_longint || b.simpleType->intType == t_dword) {
                return Type("longint");
            }
            if (a.simpleType->intType == t_smallint || a.simpleType->intType == t_word ||
                b.simpleType->intType == t_smallint || b.simpleType->intType == t_word) {
                return Type("smallint");
            }
            if (a.simpleType->intType == t_shortint || a.simpleType->intType == t_byte ||
                b.simpleType->intType == t_shortint || b.simpleType->intType == t_byte) {
                return Type("shortint");
            }
        }
        if (a.simpleType->simpleType == type_real) {
            if ((a.simpleType->realType == t_extended) ||
                (b.simpleType->simpleType == type_real && b.simpleType->realType == t_extended)) {
                return Type("extended");
            }
            if ((a.simpleType->realType == t_double) ||
                (b.simpleType->simpleType == type_real && b.simpleType->realType == t_double)) {
                return Type("double");
            }
            if ((a.simpleType->realType == t_single) ||
                (b.simpleType->simpleType == type_real && b.simpleType->realType == t_single)) {
                return Type("single");
            }
        }
    } else if (!a.isSimpleType && b.isSimpleType) {
        // enum type
        if (a.complexType->complexType == type_enum && b.simpleType->simpleType == type_integer) {
            return Type("longint");
        }
    } else if (!a.isSimpleType && !b.isSimpleType) {
        // record type
        return a;
    }
    return b;
}


Type factorAnalysis(NODE* root) {
    Type lhst, rhst;
    Value v;
    unordered_map<string, Type>::iterator tmp;
    vector<Type> typeList;
    pair<Type, Value> t;
    switch (root->type) {
        case TK_FACTOR_ID:
            // to simplify our implementation, we set priority, first we check Var&Const, then we check function
            t = findId(symbolTableList.front(), root->child[0]->name);
            if (!t.first.null) {
                lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            } else if (!t.second.invalid) {
                lhst = findConstType(symbolTableList.front(), root->child[0]->name, root->child[0]);
            } else {
                lhst = findFunc(symbolTableList.front(), root->child[0]->name, root->child[0]);
                if (!lhst.null) {
                    lhst = lhst.complexType->fpType.retType;
                }
            }
            if (lhst.null) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined variable or const or function");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_FACTOR_ID_ARGS:
        case TK_FACTOR_SYS_FUNCT:
            typeList = expressionListAnalysis(root->child[1]);
            lhst = findFunc(symbolTableList.front(), root->child[0]->name, typeList, root->child[0]);
            if (lhst.null) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined function");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_FACTOR_CONST:
            v = parseConst(root->child[0]);
            root->dataType = parseValueType(v);
            break;
        case TK_FACTOR_EXP:
            root->dataType = expressionAnalysis(root->child[0]);
            break;
        case TK_FACTOR_NOT:
            lhst = factorAnalysis(root->child[0]);
            if (!lhst.isSimpleType || lhst.simpleType->simpleType != type_boolean) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for not");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_FACTOR_MINUS:
            lhst = factorAnalysis(root->child[0]);
            if (!lhst.isSimpleType || (lhst.simpleType->simpleType != type_integer && lhst.simpleType->simpleType != type_real)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for -");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_FACTOR_ID_EXP:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.isSimpleType || lhst.complexType->complexType != type_array) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not an array");
                break;
            }
            rhst = expressionAnalysis(root->child[1]);
            if (!rhst.isSimpleType || rhst.simpleType->simpleType != type_integer) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), "index must be integer");
                break;
            }
            root->dataType = lhst.complexType->arrayType.elementType;
            break;
        case TK_FACTOR_DD:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.isSimpleType || lhst.complexType->complexType != type_record) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not a record");
                break;
            }
            tmp = lhst.complexType->recordType.attrType.find(root->child[0]->record->name);
            if (tmp == lhst.complexType->recordType.attrType.end()) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "invalid attribute", root->child[0]->record->name.c_str());
                break;
            }
            rhst = tmp->second;
            root->dataType = rhst;
            break;
        default:
            printf("%d", root->lineno);
            assert(0);
    }

    // special case: when return a func, we return its retType
    if (!root->dataType.isSimpleType && root->dataType.complexType->complexType == type_func) {
        return root->dataType.complexType->fpType.retType;
    }
    return root->dataType;
}

Type termAnalysis(NODE* root) {
    Type lhst, rhst;
    switch (root->type) {
        case TK_MUL:
            lhst = termAnalysis(root->child[0]);
            rhst = factorAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType ||
                (lhst.simpleType->simpleType == type_string || rhst.simpleType->simpleType == type_string) ||
                (lhst.simpleType->simpleType == type_char || rhst.simpleType->simpleType == type_char)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for *");
                break;
            }
            root->dataType = upcast(lhst, rhst);
            break;
        case TK_REM:
            lhst = termAnalysis(root->child[0]);
            rhst = factorAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType ||
                (lhst.simpleType->simpleType == type_string || rhst.simpleType->simpleType == type_string) ||
                (lhst.simpleType->simpleType == type_char || rhst.simpleType->simpleType == type_char)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for /");
                break;
            }
            root->dataType = Type("double");
            break;
        case TK_DIV:
        case TK_MOD:
            lhst = termAnalysis(root->child[0]);
            rhst = factorAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType || lhst.simpleType->simpleType != type_integer || rhst.simpleType->simpleType != type_integer) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for div and mod");
                break;
            }
            root->dataType = upcast(lhst, rhst);
            break;
        case TK_AND:
            lhst = termAnalysis(root->child[0]);
            rhst = factorAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType || lhst.simpleType->simpleType != type_boolean || rhst.simpleType->simpleType != type_boolean) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for and");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_TERM:
            lhst = factorAnalysis(root->child[0]);
            root->dataType = lhst;
            break;
        default:
            assert(0);
    }
    return root->dataType;
}


Type exprAnalysis(NODE* root) {
    Type lhst, rhst;
    switch (root->type) {
        case TK_PLUS:
        case TK_MINUS:
            lhst = exprAnalysis(root->child[0]);
            rhst = termAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType ||
                (lhst.simpleType->simpleType == type_string || rhst.simpleType->simpleType == type_string) ||
                (lhst.simpleType->simpleType == type_char || rhst.simpleType->simpleType == type_char)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for + and -");
                break;
            }
            root->dataType = upcast(lhst, rhst);
            break;
        case TK_OR:
            lhst = exprAnalysis(root->child[0]);
            rhst = termAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType || lhst.simpleType->simpleType != type_boolean || rhst.simpleType->simpleType != type_boolean) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for or");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_EXPR:
            lhst = termAnalysis(root->child[0]);
            root->dataType = lhst;
            break;
        default:
            assert(0);
    }
    return root->dataType;
}

Type expressionAnalysis(NODE* root) {
    Type lhst, rhst;
    switch (root->type) {
        case TK_GE:
        case TK_GT:
        case TK_LE:
        case TK_LT:
        case TK_EQUAL:
        case TK_UNEQUAL:
            lhst = expressionAnalysis(root->child[0]);
            rhst = exprAnalysis(root->child[1]);
            if (!lhst.isSimpleType || !rhst.isSimpleType ||
                (lhst.simpleType->simpleType == type_string || rhst.simpleType->simpleType == type_string) ||
                (lhst.simpleType->simpleType == type_char && rhst.simpleType->simpleType != type_char) ||
                (lhst.simpleType->simpleType != type_char && rhst.simpleType->simpleType == type_char)) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for cmp operator");
                break;
            }
            root->dataType = Type("boolean");
            break;
        case TK_EXP:
            lhst = exprAnalysis(root->child[0]);
            root->dataType = lhst;
            break;
        default:
            assert(0);
    }
    return root->dataType;
}

vector<Type> expressionListAnalysis(NODE* root) {
    vector<Type> ret;
    for (int i = 0; i < root->child_number; i++) {
        ret.push_back(expressionAnalysis(root->child[i]));
    }
    return ret;
}

bool checklvalue(NODE* root) {
    // just like factor analysis, but we only check lvalue
    if (root->type == TK_EXP || root->type == TK_EXPR || root->type == TK_TERM) {
        return checklvalue(root->child[0]);
    }
    Type lhst, rhst;
    unordered_map<string, Type>::iterator tmp;
    switch (root->type) {
        case TK_FACTOR_ID:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.null) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "undefined variable");
                break;
            }
            root->dataType = lhst;
            break;
        case TK_FACTOR_ID_EXP:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.isSimpleType || lhst.complexType->complexType != type_array) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not an array");
                break;
            }
            rhst = expressionAnalysis(root->child[1]);
            if (!rhst.isSimpleType || rhst.simpleType->simpleType != type_integer) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), "index must be integer");
                break;
            }
            root->dataType = lhst.complexType->arrayType.elementType;
            break;
        case TK_FACTOR_DD:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.isSimpleType || lhst.complexType->complexType != type_record) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not a record");
                break;
            }
            tmp = lhst.complexType->recordType.attrType.find(root->child[0]->record->name);
            if (tmp == lhst.complexType->recordType.attrType.end()) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "invalid attribute", root->child[0]->record->name.c_str());
                break;
            }
            rhst = tmp->second;
            root->dataType = rhst;
            break;
        default:
            return false;
    }
    return true;
}

void statementAnalysis(NODE* root) {

    if (root->type == TK_STMT_LABEL) {
        if (!symbolTableList.front()->insertLabel(root->child[0]->value.ival, root)) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate label");
        }
        root = root->child[1];
    } else {
        root = root->child[0];
    }

    if (root->type == TK_STMT_ASSIGN) {
        root = root->child[0];
        Type lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]), rhst;
        if (lhst.null) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined variable", root->child[0]->name.c_str());
            return;
        }
        if (!lhst.isSimpleType && (lhst.complexType->complexType != type_record && lhst.complexType->complexType != type_enum && lhst.complexType->complexType != type_array)) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "unsupport assignment operator");
            return;
        }
        Type index, t;
        unordered_map<string, Type>::iterator tmp;
        switch (root->type) {
            case TK_ASSIGN_ID:
                rhst = expressionAnalysis(root->child[1]);
                if (!typeMatch(lhst, rhst)) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    break;
                }
                rhst = upcast(lhst, rhst);
                if (lhst < rhst) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot downcast data type automatically");
                } else if (rhst < lhst) {
                    root->child[1]->dataType = lhst;
                }
                break;
            case TK_ASSIGN_ID_EXPR:
                // NOTE: we do not do range check in semantic analysis phase
                if (lhst.isSimpleType || lhst.complexType->complexType != type_array) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "is not an array");
                    break;
                }
                index = exprAnalysis(root->child[1]);
                rhst = expressionAnalysis(root->child[2]);
                if (!index.isSimpleType || index.simpleType->simpleType != type_integer) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "index must be integer");
                    break;
                }
                if (!typeMatch(lhst.complexType->arrayType.elementType, rhst)) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    break;
                }
                rhst = upcast(lhst.complexType->arrayType.elementType, rhst);
                if (lhst.complexType->arrayType.elementType < rhst) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot downcast data type automatically");
                } else if (rhst < lhst.complexType->arrayType.elementType) {
                    root->child[2]->dataType = lhst.complexType->arrayType.elementType;
                }
                break;
            case TK_ASSIGN_DD:
                if (lhst.isSimpleType || lhst.complexType->complexType != type_record) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "is not a record");
                    break;
                }
                rhst = expressionAnalysis(root->child[1]);
                tmp = lhst.complexType->recordType.attrType.find(root->child[0]->record->name);
                if (tmp == lhst.complexType->recordType.attrType.end()) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "invalid attribute", root->child[0]->record->name.c_str());
                    break;
                }
                t = tmp->second;
                if (!typeMatch(t, rhst)) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    break;
                }
                rhst = upcast(t, rhst);
                if (t < rhst) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot downcast data type automatically");
                } else if (rhst < t) {
                    root->child[1]->dataType = t;
                }
                break;
            default:
                assert(0);
        }
    } else if (root->type == TK_STMT_PROC) {
        root = root->child[0];
        Type fpType;
        vector<Type> typeList;
        switch (root->type) {
            case TK_PROC_ID:
            case TK_SYS_PROC:
                fpType = findFunc(symbolTableList.front(), root->child[0]->name, root->child[0]);
                if (fpType.null || fpType.isSimpleType || (fpType.complexType->complexType != type_func && fpType.complexType->complexType != type_proc)) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined function or procedure", root->child[0]->name.c_str());
                    return;
                }
                break;
            case TK_PROC_ID_ARGS:
                typeList = expressionListAnalysis(root->child[1]);
                fpType = findFunc(symbolTableList.front(), root->child[0]->name, typeList, root->child[0]);
                if (fpType.null) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined function or procedure", root->child[0]->name.c_str());
                    break;
                }
                for (int i = 0; i < root->child[1]->child_number; i++) {
                    if (fpType.complexType->fpType.argVarList[i] && !checklvalue(root->child[1]->child[i])) {
                        LOGERR(5, "error in line", to_string(root->child[1]->lineno).c_str(), ":", root->child[0]->name.c_str(),"needs a lvalue");
                    }
                }
                if (root->child[0]->name == "read") {
                    root->type = TK_PROC_READ;
                } else if (root->child[0]->name == "readln") {
                    root->type = TK_PROC_READLN;
                }

//                if (fpType.complexType->fpType.argTypeList.size() != root->child[1]->child_number) {
//                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "argument number mismatch");
//                    break;
//                }
//                for (int i = 0; i < root->child[1]->child_number; i++) {
//                    if (!typeMatch(fpType.complexType->fpType.argTypeList[i], typeList[i])) {
//                        LOGERR(6, "error in line", to_string(root->lineno).c_str(), ":", "argument", to_string(i).c_str(), "type mismatch");
//                    }
//                    if (fpType.complexType->fpType.argTypeList[i] < typeList[i]) {
//                        LOGERR(6, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically", "for argument", to_string(i).c_str());
//                    }
//                }
                break;
            case TK_PROC_SYS_ARGS:
                typeList = expressionListAnalysis(root->child[1]);
                break;
            default:
                assert(0);
        }
    } else if (root->type == TK_STMT_CP) {
        statementListAnalysis(root->child[0]);
    } else if (root->type == TK_IF) {
        Type cond = expressionAnalysis(root->child[0]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->child[0]->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementAnalysis(root->child[1]);
        if (root->child[2]) {
            statementAnalysis(root->child[2]);
        }
    } else if (root->type == TK_REPEAT) {
        Type cond = expressionAnalysis(root->child[1]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->child[1]->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementListAnalysis(root->child[0]);
    } else if (root->type == TK_WHILE) {
        Type cond = expressionAnalysis(root->child[0]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->child[0]->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementAnalysis(root->child[1]);
    } else if (root->type == TK_FOR) {
        // check lhst is var
        auto x = findId(symbolTableList.front(), root->child[0]->name);
        if (!x.second.invalid) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "must be a variable");
        } else {
            Type lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            Type start = expressionAnalysis(root->child[1]);
            Type end = expressionAnalysis(root->child[3]);
            if (lhst.null) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined variable", root->child[0]->name.c_str());
                return;
            }
            if (!lhst.isSimpleType || lhst.simpleType->simpleType != type_integer) {
                LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "must be integer");
            }
            if (!start.isSimpleType || !end.isSimpleType || start.simpleType->simpleType != end.simpleType->simpleType || start.simpleType->simpleType != type_integer) {
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "for loop require integer type");
            }
        }
        root->child[1]->dataType = Type("longint");
        root->child[3]->dataType = Type("longint");
        statementAnalysis(root->child[4]);
    } else if (root->type == TK_CASE) {
        Type lhst = expressionAnalysis(root->child[0]);
        if (!lhst.isSimpleType || (lhst.simpleType->simpleType != type_integer && lhst.simpleType->simpleType != type_char && lhst.simpleType->simpleType != type_boolean)) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "case variable", "must be integer or char");
        }
        for (int i = 0; i < root->child[1]->child_number; i++) {
            Value c = parseConst(root->child[1]->child[i]->child[0]);
            if (c.type != lhst.simpleType->simpleType) {
                LOGERR(4, "error in line", to_string(root->child[1]->child[i]->lineno).c_str(), ":", "label type mismatch");
                continue;
            }
            statementAnalysis(root->child[1]->child[i]->child[1]);
        }
    } else if (root->type == TK_GOTO) {
        symbolTableList.front()->insertLabelRef(root->value.ival, root->lineno);
    }
}

void statementListAnalysis(NODE* statementList) {
    if (statementList != NULL) {
        for (int i = 0; i < statementList->child_number; i++) {
            statementAnalysis(statementList->child[i]);
        }
    }
}

void routineAnalysis(NODE* root) {
    root->symbolTable = symbolTableList.front();
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
            routineNode->child[1]->name = routineNode->type == TK_FUNC_DECL ? "FUNC" : "PROC";
            parseFPType(routineNode->child[0], routineNode->type == TK_FUNC_DECL);
            symbolTableList.push_front(new SymbolTable(symbolTableList.front(), routineNode->child[0]->child[0]->name));
            prepareForFP(routineNode->child[0], routineNode->type == TK_FUNC_DECL);
            routineAnalysis(routineNode->child[1]);
            symbolTableList.pop_front();
        }
    }
    // routineBody

    if (root->child[1]) {
        statementListAnalysis(root->child[1]);
        symbolTableList.front()->checkLabelRef();
    }

}


void semanticAnalysis(NODE* ROOT) {
    if (ROOT != NULL) {
        symbolTableList.push_front(nullptr);
        symbolTableList.push_front(new SymbolTable(symbolTableList.front(), "__root__"));
        sa_init();
        routineAnalysis(ROOT->child[1]);
        symbolTableList.pop_front();
    }
}

//  int main(int argc, char** argv){
//  //    char FILENAME[100];
//  //    printf("Please input the test file: ");
//  //    scanf("%s", FILENAME);
//
//      FILE* file = fopen("./TestCases/test9.pas", "r");
//      yyin = file;
//
//      node_init();
//      yyparse();
//
//      semanticAnalysis(ROOT);
//
//      return 0;
//  }
