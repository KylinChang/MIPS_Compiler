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
	./a.out Assemble/9.pas >Assemble/9.in
	./a.out Assemble/10.pas >Assemble/10.in
	./a.out Assemble/11.pas >Assemble/11.in
	./a.out Assemble/12.pas >Assemble/12.in
gen:
	./Assemble/main Assemble/1.in Assemble/1.asm
	./Assemble/main Assemble/2.in Assemble/2.asm
	./Assemble/main Assemble/3.in Assemble/3.asm
	./Assemble/main Assemble/4.in Assemble/4.asm
	./Assemble/main Assemble/5.in Assemble/5.asm
	./Assemble/main Assemble/6.in Assemble/6.asm
	./Assemble/main Assemble/7.in Assemble/7.asm
	./Assemble/main Assemble/8.in Assemble/8.asm
	./Assemble/main Assemble/9.in Assemble/9.asm
	./Assemble/main Assemble/10.in Assemble/10.asm
	./Assemble/main Assemble/11.in Assemble/11.asm
	./Assemble/main Assemble/12.in Assemble/12.asm

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

