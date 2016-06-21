#include "common.h"
#include "icg_tac.h"
#include "yy.tab.hpp"
#include "semanticAnalysis.h"
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc<=1) return 0;
	FILE* file = fopen(argv[1], "r");
    yyin = file;

    node_init();
    yyparse();
    semanticAnalysis(ROOT);
	if (semanticAnalysisError) {
		puts("Error occurred, compiling stopped.");
		return 1;
	}

	
	//cout<<(ROOT==NULL)<<endl;
	try {
		genCode(ROOT);
	} catch (Error e) {
		cout<<e.msg<<endl;
	}
	return 0;
}
