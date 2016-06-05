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
Type::Type(const map<string, Type> &x) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(x);
}
Type::Type(const SimpleType &x, const Value &a, const Value &b) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(x, a, b);
}
Type::Type(const vector<Type> &argListType, Type retType, int isFunc) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(argListType, retType, isFunc);
}

Type findVar(list<SymbolTable*> symbolTable, string varName) {
    for (auto &x: symbolTable) {
        auto y = x->findVar(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Type findType(list<SymbolTable*> symbolTable, string varName) {
    for (auto &x: symbolTable) {
        auto y = x->findType(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Value findConst(list<SymbolTable*> symbolTable, string constName) {
    for (auto &x: symbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            return y;
        }
    }
    return Value();
}
