CC = g++ -std=c++11


Compiler:
	bison -yd --output=yy.tab.cpp syntax.y
	flex --outfile=lex.yy.cpp scan.l
	g++ -std=c++11 lex.yy.cpp yy.tab.cpp node.cpp parser.cpp semanticAnalysis.cpp symbolTable.cpp icg_tac.cpp icg_test.cpp

ICG: icg_tac.cpp icg_test.cpp icg_tac.h
	g++ -std=c++11 lex.yy.o yy.tab.o node.o semanticAnalysis.o symbolTable.o icg_tac.cpp icg_test.cpp
ICG-yilai:
	bison -yd --output=yy.tab.cpp syntax.y
	flex --outfile=lex.yy.cpp scan.l
	g++ -std=c++11 -c lex.yy.cpp yy.tab.cpp node.cpp parser.cpp semanticAnalysis.cpp symbolTable.cpp

#参考：http://blog.csdn.net/wtz1985/article/details/3862141

run:
	./a.out TestCases/icg_test1.in >TestCases/icg_test1.i
	./a.out TestCases/icg_test2.in >TestCases/icg_test2.i
	./a.out TestCases/icg_test3.in >TestCases/icg_test3.i
	./a.out TestCases/icg_test4.in >TestCases/icg_test4.i
runtest:
	./a.out TestCases/test1.pas >TestCases/test1.i
	./a.out TestCases/test2.pas >TestCases/test2.i
	./a.out TestCases/test3.pas >TestCases/test3.i
	./a.out TestCases/test4.pas >TestCases/test4.i
	./a.out TestCases/test5.pas >TestCases/test5.i
	./a.out TestCases/test6.pas >TestCases/test6.i
	./a.out TestCases/test7.pas >TestCases/test7.i
	./a.out TestCases/test8.pas >TestCases/test8.i
	./a.out TestCases/test9.pas >TestCases/test9.i
	./a.out TestCases/test10.pas >TestCases/test10.i
	./a.out TestCases/test11.pas >TestCases/test11.i
	./a.out TestCases/sa_error_test.pas >TestCases/sa_error_test.i

