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


Type::operator string() {
    assert(!null);
    static string wu[200];
    wu[type_integer * 10 + t_shortint] = "shortint";
    wu[type_integer * 10 + t_smallint] = "smallint";
    wu[type_integer * 10 + t_longint] = "longint";
    wu[type_integer * 10 + t_int64] = "int64";
    wu[type_integer * 10 + t_byte] = "byte";
    wu[type_integer * 10 + t_word] = "word";
    wu[type_integer * 10 + t_dword] = "dword";
    wu[type_integer * 10 + t_qword] = "qword";
	wu[type_real * 10 + t_single] = "single";
	wu[type_real * 10 + t_double] = "double";
	wu[type_real * 10 + t_extended] = "extended";
	wu[type_boolean * 10] = "boolean";
	wu[type_char * 10] = "char";
	wu[type_string * 10] = "string";
    
    if (isSimpleType) {
        switch (this->simpleType->simpleType) {
        case type_integer:
            return wu[this->simpleType->simpleType * 10 + this->simpleType->intType];
            break;
        case type_real:
            return wu[this->simpleType->simpleType * 10 + this->simpleType->realType];
            break;
        case type_boolean: case type_char: case type_string:
            return wu[this->simpleType->simpleType * 10];
            break;
        default:
            assert(0);
        }
    }
    else {  //complexType
    }
}


Type findVar(SymbolTable* symbolTable, const string &varName, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findVar(varName);
        if (!y.null) {
            // root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findType(SymbolTable* symbolTable, const string &varName, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findType(varName);
        if (!y.null) {
            // root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findConstType(SymbolTable* symbolTable, const string &constName, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            // root->symbolTable = x;
            return parseValueType(y);
        }
    }
    return Type();
}

Type findFunc(SymbolTable* symbolTable, const string &varName, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findFunc(varName);
        if (!y.null) {
            // root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Type findFunc(SymbolTable* symbolTable, const string &varName, const vector<Type> &typeList, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findFunc(varName, typeList);
        if (!y.null) {
            // root->symbolTable = x;
            return y;
        }
    }
    return Type();
}

Value findConst(SymbolTable* symbolTable, const string &constName, NODE* root) {
    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
            // root->symbolTable = x;
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