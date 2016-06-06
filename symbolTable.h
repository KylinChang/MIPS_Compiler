//
// Created by Orpine on 6/5/16.
//

#ifndef MIPS_COMPILER_SYMBOLTABLE_H
#define MIPS_COMPILER_SYMBOLTABLE_H

#include "common.h"
#include <set>
#include <list>
#include <vector>
#include <unordered_map>


class SimpleType;
class ComplexType;

class Type {
public:
    Type(){
        null = true;
        simpleType = nullptr;
        complexType = nullptr;
    }
    Type(const string &x);
    Type(const vector<string> &x);
    Type(int start, int end, const Type &elementType);
    Type(const unordered_map<string, Type> &x);
    Type(const SimpleTypeEnum &x, const Value &a, const Value &b);
    Type(const vector<Type> &argTypeList, const Type &retType, int isFunc = 0);
    bool null;
    bool isSimpleType;
    SimpleType *simpleType;
    ComplexType *complexType;
};

class SimpleType {

public:
    SimpleType(){}
    SimpleType(const string &x) {
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
        } else if (x == "currency") {
            simpleType = type_real;
            realType = t_currency;
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
    SimpleTypeEnum simpleType;
    IntType intType;
    RealType realType;
};

class EnumType {
    // NOTE: one enum item cannot be in different enumType
public:
    EnumType(){}
    EnumType(const vector<string> &x): enumList(x.begin(), x.end()){}
    set<string> enumList;
};

class RecordType {
public:
    RecordType(){}
    RecordType(const unordered_map<string, Type> &x): attrType(x){}
    unordered_map<string, Type> attrType;
};

class ArrayType {
public:
    ArrayType(){}
    ArrayType(int _start, int _end, const Type &_elementType): start(_start), end(_end), elementType(_elementType){}
    int start, end;
    Type elementType;
};

class RangeType {
    // NOTE: we assume we can determine the value in semantic analysis phase
public:
    RangeType(){}
    RangeType(const SimpleTypeEnum &_rangeType, const Value &_start, const Value &_end): rangeType(_rangeType), start(_start), end(_end) {}
    SimpleTypeEnum rangeType;
    Value start, end;
};

class FuncType {
public:
    FuncType(){}
    FuncType(vector<Type> _argTypeList, Type _retType): argTypeList(_argTypeList), retType(_retType){}
    vector<Type> argTypeList;
    Type retType;
};

class ComplexType {
public:
    ComplexType(const vector<string> &x): enumType(x) {
        complexType = type_enum;
    }
    ComplexType(int start, int end, Type elementType): arrayType(start, end, elementType) {
        complexType = type_array;
    }
    ComplexType(const unordered_map<string, Type> &x): recordType(x) {
        complexType = type_record;
    }
    ComplexType(const SimpleTypeEnum &x, const Value &a, const Value &b): rangeType(x, a, b) {
        complexType = type_range;
    }
    ComplexType(const vector<Type> &argTypeList, Type retType, int isFunc = 0): funcType(argTypeList, retType) {
        complexType = isFunc ? type_func : type_proc;
    }
    ComplexTypeEnum complexType;
    EnumType enumType;
    RecordType recordType;
    ArrayType arrayType;
    RangeType rangeType;
    // NOTE: here we use functype to represent func and proc
    FuncType funcType;
};

class SymbolTable {
public:
    SymbolTable* nextSymbolTable;
    unordered_map<string, Value> constSymbolTable;
    unordered_map<string, Type> varSymbolTable;
    unordered_map<string, Type> typeSymbolTable;
    int enumCount;
//    set<string> enumSet;
    SymbolTable(SymbolTable* _next = nullptr) {nextSymbolTable = _next; enumCount = 0;}
    int insertType(string identifier, Type x) {
        // NOTE: here we treat type override is legal
//        if (typeSymbolTable.find(identifier) != typeSymbolTable.end()) {
//            return 1;
//        }
        typeSymbolTable[identifier] = x;
//        if (!x.null && !x.isSimpleType && x.complexType->complexType == type_enum) {
//            int pre = enumSet.size();
//            enumSet.insert(x.complexType->enumType.enumList.begin(), x.complexType->enumType.enumList.end());
//            if (enumSet.size() != pre + x.complexType->enumType.enumList.size()) {
//                return 2;
//            }
//        }
        return 0;
    }
    bool insertEnum(const string &identifier) {
        return insertConst(identifier, ++enumCount);
    }
    bool insertVar(const string &identifier, Type x) {
        if (varSymbolTable.find(identifier) != varSymbolTable.end()) {
            return true;
        }
        varSymbolTable[identifier] = x;
        return false;
    }
    bool insertConst(const string &identifier, Value x) {
        if (constSymbolTable.find(identifier) != constSymbolTable.end()) {
            return true;
        }
        constSymbolTable[identifier] = x;
        return false;
    }
    Type findVar(const string &x) {
        auto y = varSymbolTable.find(x);
        if (y != varSymbolTable.end()) {
            return y->second;
        } else {
            return Type();
        }
    }
    Type findType(const string &x) {
        auto y = typeSymbolTable.find(x);
        if (y != typeSymbolTable.end()) {
            return y->second;
        } else {
            return Type();
        }
    }
    Value findConst(const string &x) {
        auto y = constSymbolTable.find(x);
        if (y != constSymbolTable.end()) {
            return y->second;
        } else {
            return Value();
        }
    }
};

//class varSymbolTable: symbolTable {
//
//};
//
//class constSymbolTable: symbolTable {
//
//};


#endif //MIPS_COMPILER_SYMBOLTABLE_H
