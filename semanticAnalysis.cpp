//
// Created by Orpine on 6/5/16.
//

#include <assert.h>
#include "semanticAnalysis.h"
#include "symbolTable.h"
#include "common.h"

list<SymbolTable*> symbolTableList;
unordered_map<string, string> typeName;
int semanticAnalysisError;


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
    symbolTableList.front()->insertFunc("abs", Type(vector<Type>{Type("longint")}, Type("longint"), 1));
    symbolTableList.front()->insertFunc("abs", Type(vector<Type>{Type("double")}, Type("double"), 1));
    symbolTableList.front()->insertFunc("chr", Type(vector<Type>{Type("longint")}, Type("char"), 1));
    symbolTableList.front()->insertFunc("ord", Type(vector<Type>{Type("char")}, Type("longint"), 1));
    symbolTableList.front()->insertFunc("odd", Type(vector<Type>{Type("longint")}, Type("boolean"), 1));
    symbolTableList.front()->insertFunc("sqr", Type(vector<Type>{Type("longint")}, Type("double"), 1));
    symbolTableList.front()->insertFunc("sqr", Type(vector<Type>{Type("double")}, Type("double"), 1));
    symbolTableList.front()->insertFunc("sqrt", Type(vector<Type>{Type("longint")}, Type("double"), 1));
    symbolTableList.front()->insertFunc("sqrt", Type(vector<Type>{Type("double")}, Type("double"), 1));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("longint")}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("double")}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("char")}, Type()));
    symbolTableList.front()->insertFunc("read", Type(vector<Type>{Type("string")}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("longint")}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("double")}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("char")}, Type()));
    symbolTableList.front()->insertFunc("readln", Type(vector<Type>{Type("string")}, Type()));
    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("longint")}, Type()));
    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("double")}, Type()));
    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("char")}, Type()));
    symbolTableList.front()->insertFunc("write", Type(vector<Type>{Type("string")}, Type()));
    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("longint")}, Type()));
    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("double")}, Type()));
    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("char")}, Type()));
    symbolTableList.front()->insertFunc("writeln", Type(vector<Type>{Type("string")}, Type()));
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
        if (symbolTableList.front()->insertFunc(identifier, Type(argTypeList, parseType(root->child[2]), 1))) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "duplicate function definition");
        }
//        if (symbolTableList.front()->insertVar(identifier, Type(argTypeList, parseType(root->child[2]), 1))) {
//            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unknown error");
//        }
    } else {
        if (symbolTableList.front()->insertFunc(identifier, Type(argTypeList, Type()))) {
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
        if (symbolTableList.front()->insertVar(identifier, Type(argTypeList, parseType(root->child[2])))) {
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
        auto x = findType(symbolTableList.front(), root->child[0]->name, root->child[0]);
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
        if (b < a) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "illegal range");
        }
        return Type(a.type, a, b);
    } else if (root->type == TK_STD_DD_ID) {
        // NOTE: here a and b must be const
        Value a = findConst(symbolTableList.front(), root->child[0]->name, root->child[0]), b = findConst(symbolTableList.front(), root->child[1]->name, root->child[1]);
        if (a.type != b.type) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "range data type mismatch");
        }
        if (a.type == type_string || a.type == type_real) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "unsupported range data type");
        }
        if (root->child[0]->type == TK_ID_MINUS) {
            a.ival = -a.ival;
        }
        if (root->child[1]->type == TK_ID_MINUS) {
            b.ival = -b.ival;
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
        if (!(findConst(symbolTableList.front(), identifier, typeList[i]->child[0]).invalid) || (symbolTableList.front()->insertType(identifier, val))) {
            // NOTE: here we think type override is legal
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
            if (findConst(symbolTableList.front(), varList[i]->child[0]->child[j]->name, varList[i]->child[0]->child[j]).invalid &&
                findType(symbolTableList.front(), varList[i]->child[0]->child[j]->name, varList[i]->child[0]->child[j]).null &&
                findVar(symbolTableList.front(), varList[i]->child[0]->child[j]->name, varList[i]->child[0]->child[j]).null) {
                symbolTableList.front()->insertVar(varList[i]->child[0]->child[j]->name, nameListType);
            } else {
                LOGERR(4, "error in line", to_string(varList[i]->child[0]->child[j]->lineno).c_str(), ":", "duplicate identifer");
            }
        }
    }
}

Type upcast(const Type &a, const Type &b) {
    // assume a and b are both simple type
    if (a.simpleType->simpleType == type_string && b.simpleType->simpleType == type_string) {
        return Type("string");
    }
    if (a.simpleType->simpleType == type_char && b.simpleType->simpleType == type_char) {
        return Type("char");
    }
    if (a.simpleType->simpleType == type_integer && b.simpleType->simpleType == type_integer) {
        if (a.simpleType->intType == t_int64 || a.simpleType->intType == t_qword || b.simpleType->intType == t_int64 || b.simpleType->intType == t_qword) {
            return Type("int64");
        }
        if (a.simpleType->intType == t_longint || a.simpleType->intType == t_dword || b.simpleType->intType == t_longint || b.simpleType->intType == t_dword) {
            return Type("longint");
        }
        if (a.simpleType->intType == t_smallint || a.simpleType->intType == t_word || b.simpleType->intType == t_smallint || b.simpleType->intType == t_word) {
            return Type("smallint");
        }
        if (a.simpleType->intType == t_shortint || a.simpleType->intType == t_byte || b.simpleType->intType == t_shortint || b.simpleType->intType == t_byte) {
            return Type("shortint");
        }
    } else {
        if ((a.simpleType->simpleType == type_real && a.simpleType->realType == t_extended) || (b.simpleType->simpleType == type_real && b.simpleType->realType == t_extended)) {
            return Type("extended");
        }
        if ((a.simpleType->simpleType == type_real && a.simpleType->realType == t_double) || (b.simpleType->simpleType == type_real && b.simpleType->realType == t_double)) {
            return Type("double");
        }
        if ((a.simpleType->simpleType == type_real && a.simpleType->realType == t_single) || (b.simpleType->simpleType == type_real && b.simpleType->realType == t_single)) {
            return Type("single");
        }
    }
    return Type();
}


Type factorAnalysis(NODE* root) {
    Type lhst, rhst;
    Value v;
    unordered_map<string, Type>::iterator tmp;
    vector<Type> typeList;
    switch (root->type) {
        case TK_FACTOR_ID:
            lhst = findVar(symbolTableList.front(), root->child[0]->name, root->child[0]);
            if (lhst.null) {
                lhst = findConstType(symbolTableList.front(), root->child[0]->name, root->child[0]);
            }
            if (lhst.null) {
                lhst = findFunc(symbolTableList.front(), root->child[0]->name, root->child[0]);
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
            root->dataType = lhst.complexType->fpType.retType;
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
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for minus");
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
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "invalid attribute");
                break;
            }
            rhst = tmp->second;
            root->dataType = rhst;
            break;
        default:
            printf("%d", root->lineno);
            assert(0);
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
                LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch for *");
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
        if (!lhst.isSimpleType && (lhst.complexType->complexType == type_range || lhst.complexType->complexType == type_proc)) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "unsupport assignment operator");
            return;
        }
        Type index, t;
        unordered_map<string, Type>::iterator tmp;
        switch (root->type) {
            case TK_ASSIGN_ID:
                rhst = expressionAnalysis(root->child[1]);
                if (!lhst.isSimpleType && lhst.complexType->complexType == type_func) {
                    // NOTE: special case: if a is a func, a can be assigned to a value
                    if (!typeMatch(lhst.complexType->fpType.retType, rhst)) {
                        LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    }

                    rhst = upcast(lhst.complexType->fpType.retType, rhst);
                    if (lhst.complexType->fpType.retType < rhst) {
                        LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically");
                    } else if (rhst < lhst.complexType->fpType.retType) {
                        root->child[1]->dataType = lhst.complexType->fpType.retType;
                    }
                } else {
                    if (!typeMatch(lhst, rhst)) {
                        LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                        break;
                    }
                    rhst = upcast(lhst, rhst);

                    if (lhst < rhst) {
                        LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically");
                    } else if (rhst < lhst) {
                        root->child[1]->dataType = lhst;
                    }
                }
                break;
            case TK_ASSIGN_ID_EXPR:
                // NOTE: we do not do range check in semantic analysis phase
                if (lhst.isSimpleType || lhst.complexType->complexType != type_array) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not an array");
                }
                index = exprAnalysis(root->child[1]);
                rhst = expressionAnalysis(root->child[2]);
                if (!index.isSimpleType || index.simpleType->simpleType != type_integer) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), "index must be integer");
                    break;
                }
                if (!typeMatch(lhst.complexType->arrayType.elementType, rhst)) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    break;
                }
                rhst = upcast(lhst.complexType->arrayType.elementType, rhst);
                if (lhst.complexType->arrayType.elementType < rhst) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically");
                } else if (rhst < lhst.complexType->arrayType.elementType) {
                    root->child[2]->dataType = lhst.complexType->arrayType.elementType;
                }
                break;
            case TK_ASSIGN_DD:
                if (lhst.isSimpleType || lhst.complexType->complexType != type_record) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), root->child[0]->name.c_str(), "is not a record");
                    break;
                }
                rhst = expressionAnalysis(root->child[1]);
                tmp = lhst.complexType->recordType.attrType.find(root->child[0]->record->name);
                if (tmp == lhst.complexType->recordType.attrType.end()) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "invalid attribute");
                    break;
                }
                t = tmp->second;
                if (!typeMatch(t, rhst)) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "type mismatch between assignment operator");
                    break;
                }
                rhst = upcast(t, rhst);
                if (t < rhst) {
                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically");
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
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined procedure", root->child[0]->name.c_str());
                    return;
                }
                break;
            case TK_PROC_ID_ARGS:
            case TK_PROC_SYS_ARGS:
                typeList = expressionListAnalysis(root->child[1]);
                fpType = findFunc(symbolTableList.front(), root->child[0]->name, typeList, root->child[0]);
                if (fpType.null) {
                    LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", "undefined function or procedure", root->child[0]->name.c_str());
                    break;
                }
//                if (fpType.complexType->fpType.argTypeList.size() != root->child[1]->child_number) {
//                    LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "argument number mismatch");
//                    break;
//                }
                for (int i = 0; i < root->child[1]->child_number; i++) {
                    if (!typeMatch(fpType.complexType->fpType.argTypeList[i], typeList[i])) {
                        LOGERR(6, "error in line", to_string(root->lineno).c_str(), ":", "argument", to_string(i).c_str(), "type mismatch");
                    }
                    if (fpType.complexType->fpType.argTypeList[i] < typeList[i]) {
                        LOGERR(6, "error in line", to_string(root->lineno).c_str(), ":", "cannot automatic downcast data type automatically", "for argument", to_string(i).c_str());
                    }
                }
                break;
            case TK_PROC_READ:
            case TK_PROC_READLN:
                factorAnalysis(root->child[1]);
                break;
            default:
                assert(0);
        }
    } else if (root->type == TK_STMT_CP) {
        statementListAnalysis(root->child[0]);
    } else if (root->type == TK_IF) {
        Type cond = expressionAnalysis(root->child[0]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementAnalysis(root->child[1]);
        if (root->child[2]) {
            statementAnalysis(root->child[2]);
        }
    } else if (root->type == TK_REPEAT) {
        Type cond = expressionAnalysis(root->child[1]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementListAnalysis(root->child[0]);
    } else if (root->type == TK_WHILE) {
        Type cond = expressionAnalysis(root->child[0]);
        if (!cond.isSimpleType || cond.simpleType->simpleType != type_boolean) {
            LOGERR(4, "error in line", to_string(root->lineno).c_str(), ":", "the type of condition clause must be boolean");
        }
        statementAnalysis(root->child[1]);
    } else if (root->type == TK_FOR) {
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
        root->child[1]->dataType = Type("longint");
        root->child[3]->dataType = Type("longint");
        statementAnalysis(root->child[4]);
    } else if (root->type == TK_CASE) {
        Type lhst = expressionAnalysis(root->child[0]);
        if (!lhst.isSimpleType || (lhst.simpleType->simpleType != type_integer && lhst.simpleType->simpleType != type_char && lhst.simpleType->simpleType != type_boolean)) {
            LOGERR(5, "error in line", to_string(root->lineno).c_str(), ":", root->child[0]->name.c_str(), "must be integer or char");
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

//      FILE* file = fopen("./TestCases/test10.pas", "r");
//      yyin = file;

//      node_init();
//      yyparse();

//      semanticAnalysis(ROOT);

//      return 0;
//  }
