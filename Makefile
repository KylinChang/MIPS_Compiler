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

newrun:
	./a.out Assemble/1.pas >Assemble/1.in
	./a.out Assemble/2.pas >Assemble/2.in
	./a.out Assemble/3.pas >Assemble/3.in
	./a.out Assemble/4.pas >Assemble/4.in
	./a.out Assemble/5.pas >Assemble/5.in
	./a.out Assemble/6.pas >Assemble/6.in
	./a.out Assemble/7.pas >Assemble/7.in
	./a.out Assemble/8.pas >Assemble/8.in
gen:
	./Assemble/main 1.in 1.asm
	./Assemble/main 2.in 2.asm
	./Assemble/main 3.in 3.asm
	./Assemble/main 4.in 4.asm
	./Assemble/main 5.in 5.asm
	./Assemble/main 6.in 6.asm
	./Assemble/main 7.in 7.asm
	./Assemble/main 8.in 8.asm

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

