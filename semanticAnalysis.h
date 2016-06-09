//
// Created by Orpine on 6/5/16.
//

#ifndef MIPS_COMPILER_SEMENTICANALYSIS_H
#define MIPS_COMPILER_SEMENTICANALYSIS_H

#include "common.h"
#include "yy.tab.hpp"
#include "symbolTable.h"
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

extern unordered_map<string, string> typeName;

extern int semanticAnalysisError;

void sa_init();
void parseRecordType(unordered_map<string, Type> &nameMap, NODE* root);
Type parseType(NODE* root);

bool typeMatch(const Type &a, const Type &b);
void parseFPType(NODE* root, bool isFunc);
void prepareForFP(NODE* root);
void parseRecord(unordered_map<string, Type> &nameMap, NODE* root);
Type parseType(NODE* root);
void constAnalysis(NODE** constList, int constListNum);
void typeAnalysis(NODE** typeList, int typeListNum);
void varAnalysis(NODE** varList, int varListNum);
Type expressionAnalysis(NODE* root);
void statementAnalysis(NODE* root);
void statementListAnalysis(NODE* statementList);
void routineAnalysis(NODE* root);
vector<Type> expressionListAnalysis(NODE* root);

void semanticAnalysis(NODE* ROOT);

#endif //MIPS_COMPILER_SEMENTICANALYSIS_H
