Compiler:
	yacc -d syntax.y
	lex scan.l
	gcc lex.yy.c y.tab.c node.c

