#include "common.h"


void preorder(NODE* root){
    if(root==NULL) return;
    int i;
    printf("TYPE:%d; CHILDREN:%d\n", root->type, root->child_number);
    for(i=0;i<root->child_number;i++){
        preorder(root->child[i]);
    }
}
//int main(int argc, char** argv){
////    char FILENAME[100];
////    printf("Please input the test file: ");
////    scanf("%s", FILENAME);
//
//    FILE* file = fopen("./TestCases/test10.pas", "r");
////    FILE* file = fopen("./TestCases/test8.pas", "r");
//    yyin = file;
//
//    node_init();
//    yyparse();
//
//
//    NODE* tmp = ROOT;
//    printf("IS SYNTAX ERROR: %d\n", IS_SYNTAX_ERROR);
//
//
//    return 0;
//}

