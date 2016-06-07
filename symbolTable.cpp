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

bool Type::operator <(const Type &o) const {
    // NOTE: here we just check for simple type
    assert(this->isSimpleType && o.isSimpleType && this->simpleType->simpleType == o.simpleType->simpleType);
    /* integer:
     * byte <= short < word <= small < dword <= longint < qword <= int64
     * real:
     * single < double < extended
     * */
    if (this->simpleType->simpleType == type_integer) {
        return this->simpleType->intType < o.simpleType->intType;
    } else if (this->simpleType->simpleType == type_real) {
        return this->simpleType->realType < o.simpleType->realType;
    } else {
        return false;
    }
}

bool Type::operator ==(const Type &o) const {
    // NOTE: we use == to match function signature
    if (null && o.null) {
        return true;
    }
    if (null || o.null) {
        return false;
    }
    if (isSimpleType && o.isSimpleType) {
        return simpleType->simpleType == o.simpleType->simpleType;
    } else if (!isSimpleType && !o.isSimpleType) {
        if (complexType->complexType != o.complexType->complexType) {
            return false;
        }
        switch (complexType->complexType) {
            case type_array:
            case type_enum:
            case type_range:
                return false;
            case type_record:
                return complexType->recordType == o.complexType->recordType;
            case type_func:
            case type_proc:
                return complexType->fpType == complexType->fpType;
            default:
                assert(0);
        }
    } else {
        return false;
    }
}



Type findVar(SymbolTable* symbolTable, const string &varName, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findVar(varName);
        if (!y.null) {
            root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findType(SymbolTable* symbolTable, const string &varName, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findType(varName);
        if (!y.null) {
            root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findConstType(SymbolTable* symbolTable, const string &constName, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            root->symbolTable = x;
            return parseValueType(y);
        }
    }
    return Type();
}

Type findFunc(SymbolTable* symbolTable, const string &varName, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findFunc(varName);
        if (!y.null) {
            root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findFunc(SymbolTable* symbolTable, const string &varName, const vector<Type> &typeList, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findFunc(varName, typeList);
        if (!y.null) {
            root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Value findConst(SymbolTable* symbolTable, const string &constName, NODE* root) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            root->symbolTable = x;
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