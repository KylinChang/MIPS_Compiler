typedef struct NODE{
    char* name;
    char* str;
    char ch;
    int type;
    int ival;
    double dval;
    int child_number;
    struct NODE** child;

    struct NODE* attr;
}NODE;

#define NODE_SIZE sizeof(NODE)
#define NODE_POINTER_SIZE sizeof(NODE*)
#define NEWNODE (NODE*)malloc(NODE_SIZE)
#define MALLOC(num) (NODE**)malloc(NODE_POINTER_SIZE*num)
