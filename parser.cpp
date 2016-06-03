#include "common.h"

extern void yyparse();
extern int DEBUG;
extern NODE* ROOT;

void preorder(NODE* root){
    int i;
    printf("TYPE:%d; CHILDREN:%d\n", root->type, root->child_number);
    for(i=0;i<root->child_number;i++){
        preorder(root->child[i]);
    }
}

int main(){
    char FILENAME[100];
    printf("Please input the test file: ");
    scanf("%s", FILENAME);
    FILE* file = fopen(FILENAME, "r");
    yyin = file;

    yyparse();

    if(DEBUG){
     preorder(ROOT);
    }

    return 0;
}