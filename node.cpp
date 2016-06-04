#include "common.h"

NODE* NEWNODE(int type){
	NODE* node = (NODE*)malloc(NODE_SIZE);
	node->type = type;
	node->child_number = 0;
	node->child = NULL;
	return node;
} 

void cpString(char** str1, char** str2){
	*str1 = (char*)malloc(sizeof(char) * (strlen(*str2) + 1));
	strcpy(*str1, *str2);
}
