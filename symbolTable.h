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
    Type() {
        null = true;
        simpleType = nullptr;

    }
    Type(string x) {
        isSimpleType = true;
//        simpleType = SimpleType(x);
    }
    bool null;
    bool isSimpleType;
    SimpleType *simpleType;
    ComplexType *complexType;
};

enum IntType {
    t_shortint,
    t_smallint,
    t_integer, //t_longint,
    t_int64,
    t_byte,
    t_word,
    t_dword, //t_longword, t_cardinal
    t_qword
};

enum RealType {
    t_real,
    t_comp,
    t_single,
    t_double,
    t_extended
};

enum SimpleTypeEnum {
    type_integer,
    type_real,
    type_boolean,
    type_char,
};

enum ComplexTypeEnum {
    type_array,
    type_enum,
    type_record,
    type_range,
    type_func,
    type_proc
};


class EnumType {
    // NOTE: one enum item cannot be in different enumType
    set<string> enumList;
};

class RecordType {
    map<string, Type> attrType;
};

class ArrayType {
    int start, end;
    Type elementType;
};

class RangeType {
    // NOTE: here we just check type, do not evaluate value
    Type startType, endType;
};

class FuncType {
    vector<Type> argType;
    Type retType;
};




class SimpleType {
    SimpleTypeEnum simpleType;
    IntType intType;
    RealType realType;
};

class ComplexType {
    ComplexTypeEnum complexType;
    EnumType enumType;
    RecordType recordType;
    ArrayType arrayType;
    RangeType rangeType;
    // NOTE: here we use functype to represent func and proc
    FuncType funcType;
};



class SymbolTable {
    unordered_map<string, Type> varSymbolTable;
    unordered_map<string, Type> typeSymbolTable;
//    Type* findVarType(const string &x) {
//        auto y = typeSymbolTable.find(x);
//        if (y != typeSymbolTable.end()) {
//            return
//        } else {
//            return NULL;
//        }
//    }
};

//class varSymbolTable: symbolTable {
//
//};
//
//class constSymbolTable: symbolTable {
//
//};

class tableItem {

};

void findVar(list<SymbolTable*> symbolTable) {
    for (auto &x: symbolTable) {
//        if (x->)
    }
}


#endif //MIPS_COMPILER_SYMBOLTABLE_H
