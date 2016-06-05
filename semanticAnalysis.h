//
// Created by Orpine on 6/5/16.
//

#ifndef MIPS_COMPILER_SEMENTICANALYSIS_H
#define MIPS_COMPILER_SEMENTICANALYSIS_H

#include "common.h"
#include "yy.tab.hpp"
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>
#include <cstdarg>

using namespace std;

void LOGERR(string x, ...);


unordered_map<string, string> typeName;



void sa_init();

#endif //MIPS_COMPILER_SEMENTICANALYSIS_H
