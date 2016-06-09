#include "icg_tac.cpp"

NODE *bt;
int main() {
	bt = new NODE();
	bt->type = TK_PLUS;
	bt->child = MALLOC(bt,2);

	bt->child[0] = new NODE();
	bt->type = TK_PLUS;
	return 0;
}
