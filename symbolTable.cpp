//
// Created by Orpine on 6/5/16.
//

#include "symbolTable.h"


Type::Type(const Type &o) {
    null = o.null;
    isSimpleType = o.isSimpleType;
    simpleType = o.simpleType;
    complexType = o.complexType;
}

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
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findVar(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Type findType(SymbolTable* symbolTable, const string &varName) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findType(varName);
        if (!y.null) {
            return y;
        }
    }
    return Type();
}

Type findConstType(SymbolTable* symbolTable, const string &constName) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            return parseValueType(y);
        }
    }
    return Type();
}

Value findConst(SymbolTable* symbolTable, const string &constName) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            return y;
        }
    }
    return Value();
}

Type parseValueType(const Value &x) {
    switch (x.type) {
        case type_integer:
            return Type("longint");
        case type_real:
            return Type("double");
        case type_boolean:
            return Type("boolean");
        case type_char:
            return Type("char");
        case type_string:
            return Type("string");
    }
    assert(0);
    return Type();
}