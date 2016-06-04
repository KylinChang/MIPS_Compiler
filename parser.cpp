#include "common.h"

extern int yyparse();
extern int DEBUG;
extern NODE* ROOT;

void preorder(NODE* root){
    if(root==NULL) return;
    int i;
    printf("TYPE:%d; CHILDREN:%d\n", root->type, root->child_number);
    for(i=0;i<root->child_number;i++){
        preorder(root->child[i]);
    }
}

int main(int argc, char** argv){
    char FILENAME[100];
    printf("Please input the test file: ");
    scanf("%s", FILENAME);

    FILE* file = fopen(FILENAME, "r");
    yyin = file;

    init();
    yyparse();

    if(DEBUG){
        NODE* tmp = ROOT;
        preorder(ROOT);
    }

    return 0;
}