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
#include <string>
using namespace std;


class SymbolTable {
public:
    SymbolTable* nextSymbolTable;
    unordered_map<string, Value> constSymbolTable;
    unordered_map<string, Type> varSymbolTable;
    unordered_map<string, Type> typeSymbolTable;
    unordered_map<string, vector<Type>> funcSymbolTable;
    // the following data structures are used to check goto labels' validity
    unordered_map<int, int> labelRef;
    unordered_map<int, NODE*> labelMap;

    int enumCount;
//    set<string> enumSet;
    SymbolTable(SymbolTable* _next = nullptr) {nextSymbolTable = _next; enumCount = 0;}
    int insertType(string identifier, const Type &x) {
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
    bool insertVar(const string &identifier, const Type &x) {
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
    bool insertLabel(int label, NODE* node) {
        if (labelMap.find(label) != labelMap.end()) {
            return false;
        }
        labelMap[label] = node;
        return true;
    }
    bool insertFunc(const string &identifier, const Type &x) {
        auto it = funcSymbolTable.find(identifier);
        if (it == funcSymbolTable.end()) {
            funcSymbolTable[identifier] = vector<Type>();
            funcSymbolTable[identifier].push_back(x);
        } else {
            for (const auto &y: it->second) {
                if (x == y) {
                    return true;
                }
            }
        }
        return false;
    }
    void insertLabelRef(int label, int lineno) {
        // NOTE: it is unnecessary to record all goto reference
        labelRef[label] = lineno;
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
    Type findFunc(const string &x) {
        auto y = funcSymbolTable.find(x);
        if (y != funcSymbolTable.end()) {
            auto type = Type(vector<Type>(), Type());
            for (const auto &t: y->second) {
                if (t == type) {
                    return t;
                }
            }
        }
        return Type();
    }
    Type findFunc(const string &x, const vector<Type> &typeList) {
        auto y = funcSymbolTable.find(x);
        if (y != funcSymbolTable.end()) {
            auto type = Type(typeList, Type());
            for (const auto &t: y->second) {
                if (t == type) {
                    return t;
                }
            }
        }
        return Type();
    }
    Value findConst(const string &x) {
        auto y = constSymbolTable.find(x);
        if (y != constSymbolTable.end()) {
            return y->second;
        } else {
            return Value();
        }
    }
    void checkLabelRef() {
        for (auto &x: labelRef) {
            if (labelMap.find(x.first) == labelMap.end()) {
                LOGERR(4, "error in line", to_string(x.second).c_str(), ":", "use a unavailable label");
            }
        }
    }
};

Type findVar(SymbolTable* symbolTable, const string &varName, NODE* root);

Type findType(SymbolTable* symbolTable, const string &varName, NODE* root);

Type findConstType(SymbolTable* symbolTable, const string &varName, NODE* root);

Type findFunc(SymbolTable* symbolTable, const string &varName, NODE* root);

Type findFunc(SymbolTable* symbolTable, const string &varName, const vector<Type> &typeList, NODE* root);

Value findConst(SymbolTable* symbolTable, const string &constName, NODE* root);

#endif //MIPS_COMPILER_SYMBOLTABLE_H
