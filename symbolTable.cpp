//
// Created by Orpine on 6/5/16.
//

#include "symbolTable.h"


Type::Type(const string &x) {
    null = false;
    isSimpleType = true;
    simpleType = new SimpleType(x);
}
Type::Type(const vector<string> &x) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(x);
}
Type::Type(int start, int end, const Type &elementType) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(start, end, elementType);
}
Type::Type(const unordered_map<string, Type> &x) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(x);
}
Type::Type(const SimpleTypeEnum &x, const Value &a, const Value &b) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(x, a, b);
}
Type::Type(const vector<Type> &argListType, const Type &retType, int isFunc) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(argListType, retType, isFunc);
}

Type findVar(SymbolTable* symbolTable, const string &varName) {
    for (auto x = symbolTable; x->nextSymbolTable != nullptr; x = x->nextSymbolTable) {
        auto y = x->findVar(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Type findType(SymbolTable* symbolTable, const string &varName) {
    for (auto x = symbolTable; x->nextSymbolTable != nullptr; x = x->nextSymbolTable) {
        auto y = x->findType(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Value findConst(SymbolTable* symbolTable, const string &constName) {
    for (auto x = symbolTable; x->nextSymbolTable != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            return y;
        }
    }
    return Value();
}
