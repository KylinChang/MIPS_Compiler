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

enum IntType {
    t_shortint,
    t_smallint,
    t_longint, // t_integer
    t_int64, // t_comp
    t_byte,
    t_word,
    t_dword, //t_longword, t_cardinal
    t_qword
};

enum RealType {
    t_single,
    t_double, // t_real
    t_extended,
    t_currency
};

enum SimpleTypeEnum {
    type_integer,
    type_real,
    type_boolean,
    type_char,
    type_string
};

enum ComplexTypeEnum {
    type_array,
    type_enum,
    type_record,
    type_range,
    type_func,
    type_proc
};

class Value {
public:
    Value(){invalid = true;}
    Value(int x) {
        invalid = false;
        ival = x;
        type = type_integer;
    }
    Value (double x) {
        invalid = false;
        dval = x;
        type = type_real;
    }
    Value (bool x) {
        invalid = false;
        bval = x;
        type = type_boolean;
    }
    Value (char x) {
        invalid = false;
        cval = x;
        type = type_char;
    }
    Value (string x) {
        invalid = false;
        sval = x;
        type = type_string;
    }
    bool invalid;
    SimpleTypeEnum type;
    int ival;
    double dval;
    bool bval;
    char cval;
    string sval;
};

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
    Type(const map<string, Type> &x);
    Type(const SimpleType &x, const Value &a, const Value &b);
    Type(const vector<Type> &argListType, Type retType, int isFunc = 0);
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
    RecordType(const map<string, Type> &x): attrType(x){}
    map<string, Type> attrType;
};

class ArrayType {
public:
    ArrayType(){}
    ArrayType(int _start, int _end, const Type &_elementType): start(_start), end(_end), elementType(_elementType){}
    int start, end;
    Type elementType;
};

class RangeType {
    // NOTE: here we just check type, do not evaluate value
public:
    RangeType(){}
    RangeType(const SimpleType &_rangeType, const Value &_start, const Value &_end): rangeType(_rangeType), start(_start), end(_end) {}
    SimpleType rangeType;
    Value start, end;
};

class FuncType {
public:
    FuncType(){}
    FuncType(vector<Type> _argListType, Type _retType): argListType(_argListType), retType(_retType){}
    vector<Type> argListType;
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
    ComplexType(const map<string, Type> &x): recordType(x) {
        complexType = type_record;
    }
    ComplexType(const SimpleType &x, const Value &a, const Value &b): rangeType(x, a, b) {
        complexType = type_range;
    }
    ComplexType(const vector<Type> &argListType, Type retType, int isFunc = 0): funcType(argListType, retType) {
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
    unordered_map<string, Value> constSymbolTable;
    unordered_map<string, Type> varSymbolTable;
    unordered_map<string, Type> typeSymbolTable;
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
