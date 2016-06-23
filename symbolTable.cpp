//
// Created by Orpine on 6/5/16.
//

#include "symbolTable.h"

bool Value::operator<(const Value &b) const {
    // NOTE: here we assume a and b are the same type
    if (type == type_integer) {
        return ival < b.ival;
    } else if (type == type_real) {
        return dval < b.dval;
    } else if (type == type_boolean) {
        return !bval && b.bval;
    } else if (type == type_char) {
        return cval < b.cval;
    }
    assert(0);
    return false;
}

SimpleType::SimpleType(const string &x) {
    if (x == "shortint") {
        simpleType = type_integer;
        intType = t_shortint;
    } else if (x == "smallint") {
        simpleType = type_integer;
        intType = t_smallint;
    } else if (x == "longint") {
        simpleType = type_integer;
        intType = t_longint;
    } else if (x == "int64") {
        simpleType = type_integer;
        intType = t_int64;
    } else if (x == "byte") {
        simpleType = type_integer;
        intType = t_byte;
    } else if (x == "word") {
        simpleType = type_integer;
        intType = t_word;
    } else if (x == "dword") {
        simpleType = type_integer;
        intType = t_dword;
    } else if (x == "qword") {
        simpleType = type_integer;
        intType = t_qword;
    }

    if (x == "single") {
        simpleType = type_real;
        realType = t_single;
    } else if (x == "double") {
        simpleType = type_real;
        realType = t_double;
    } else if (x == "extended") {
        simpleType = type_real;
        realType = t_extended;
//		} else if (x == "currency") {
//			simpleType = type_real;
//			realType = t_currency;
    }

    if (x == "boolean") {
        simpleType = type_boolean;
    }
    if (x == "char") {
        simpleType = type_char;
    }

    if (x == "string") {
        simpleType = type_string;
    }
}

int SimpleType::size() {
    switch (simpleType) {
        case type_integer:
            switch (intType) {
                case t_shortint:
                case t_byte:
                    return 1;
                case t_smallint:
                case t_word:
                    return 2;
                case t_longint:
                case t_dword:
                    return 4;
                case t_int64:
                case t_qword:
                    return 8;
            }
        case type_real:
            switch (realType) {
                case t_single:
                    return 4;
                case t_double:
                    return 8;
                case t_extended:
                    return 12;
            }
        case type_boolean:
            return 1;
        case type_char:
            return 1;
        case type_string:
            // NOTE: here we return a pointer size
            return 12;
            LOGERR(1, "error: cannot determine string's size in semantic analysis phase");
//            assert(0);
//            break;
    }
}

RecordType::RecordType(const unordered_map<string, Type> &x): attrType(x) {
    int o = 0;
    for (const auto &t: attrType) {
        offset[t.first] = o;
        // NOTE: since we only support id.id, we just calculate t.second.`simpleType`
        o += t.second.simpleType->size();
    }
}

bool RecordType::operator==(const RecordType &o) const {
    if (this->attrType.size() != o.attrType.size()) {
        return false;
    }
    for (const auto &x: this->attrType) {
        auto y = o.attrType.find(x.first);
        if (y == o.attrType.end() || !(y->second == x.second)) {
            return false;
        }
    }
    return true;
}

ArrayType::ArrayType(int _start, int _end, const Type &_elementType) : start(_start), end(_end), elementType(_elementType) {
    assert(elementType.isSimpleType);
    elementSize = elementType.simpleType->size();
}

bool FPType::operator==(const FPType &o) const {
    if (argTypeList.size() != o.argTypeList.size()) {
        return false;
    }
    for (int i = 0; i < argTypeList.size(); i++) {
        // we allow o.argTypeList automatic upcast
        if (argTypeList[i] < o.argTypeList[i]) {
            return false;
        }
    }
    return true;
}


int ComplexType::size() {
    int ret = 0;
    switch (complexType) {
        case type_array:
            return arrayType.elementSize * (arrayType.end - arrayType.start + 1);
        case type_record:
            for (auto &x: recordType.attrType) {
                ret += x.second.size();
            }
            return ret;
        case type_func:
            return fpType.retType.size();
        case type_range:
        case type_enum:
        case type_proc:
            assert(0);
    }
    return 0;
}

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
Type::Type(const vector<Type> &argTypeList, const vector<bool> &argVarList, const Type &retType, int isFunc) {
    null = false;
    isSimpleType = false;
    complexType = new ComplexType(argTypeList, argVarList, retType, isFunc);
}

bool Type::operator <(const Type &o) const {
    // NOTE: here we just check for simple type
    assert(this->isSimpleType && o.isSimpleType);
    if (this->simpleType->simpleType == type_integer && o.simpleType->simpleType == type_real) {
        return true;
    }
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
        if ((complexType->complexType == type_func || complexType->complexType == type_proc) && (o.complexType->complexType == type_func || o.complexType->complexType == type_proc)) {
            return complexType->fpType == o.complexType->fpType;
        }
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
            default:
                assert(0);
        }
    } else {
        return false;
    }
}

int Type::size() {
    assert(!null);
    return isSimpleType ? simpleType->size() : complexType->size();
}


Type::operator string() {
    assert(!null);
    static string wu[200];
    wu[type_integer * 10 + t_shortint] = "shortint";
    wu[type_integer * 10 + t_smallint] = "smallint";
    wu[type_integer * 10 + t_longint] = "int";
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
        cerr<<"Can't be complexType"<<endl;
        assert(0);
    }
}


Type findVar(SymbolTable* symbolTable, const string &varName, NODE* root) {
    // NOTE: here we assign current symbolTable to root->symbolTable for icg's convenience
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
//    root->symbolTable = symbolTable;
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
//    root->symbolTable = symbolTable;
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
//    root->symbolTable = symbolTable;
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
//    root->symbolTable = symbolTable;
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
//    root->symbolTable = symbolTable;
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findConst(constName);
        if (!y.invalid) {
             root->symbolTable = x;
            return y;
        }
    }
    return Value();
}

pair<Type, Value> findId(SymbolTable* symbolTable, const string &name) {
    for (auto x = symbolTable; x != nullptr; x = x->nextSymbolTable) {
        auto y = x->findVar(name);
        auto z = x->findConst(name);
        if (!y.null || !z.invalid) {
            return make_pair(y, z);
        }
    }
    return make_pair(Type(), Value());
};

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