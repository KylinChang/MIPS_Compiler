Compiler:
	bison -yd --output=yy.tab.cpp syntax.y
	flex --outfile=lex.yy.cpp scan.l
	g++ -std=c++11 lex.yy.cpp yy.tab.cpp node.cpp parser.cpp semanticAnalysis.cpp symbolTable.cpp


Compiler0:
	yacc -d syntax.y --language=c++ --defines=yy.tab.hpp -o yy.tab.cpp && lex scan.l && g++ lex.yy.c yy.tab.cpp node.cpp parser.cpp

CC = g++ -std=c++11
OBJS = lex.yy.o yy.tab.o node.o parser.o semanticAnalysis.o symbolTable.o icg_tac.o icg_test.o
ICG: icg_tac.cpp icg_test.cpp icg_tac.h
	g++ -std=c++11 lex.yy.o yy.tab.o node.o semanticAnalysis.o symbolTable.o icg_tac.cpp icg_test.cpp
ICG-yilai: syntax.y scan.l lex.yy.cpp yy.tab.cpp node.cpp semanticAnalysis.cpp symbolTable.cpp common.h yy.tab.hpp symbolTable.h semanticAnalysis.h
	bison -yd --output=yy.tab.cpp syntax.y
	flex --outfile=lex.yy.cpp scan.l
	g++ -std=c++11 -c lex.yy.cpp yy.tab.cpp node.cpp semanticAnalysis.cpp symbolTable.cpp
lex.yy.o: lex.yy.cpp common.h
	$(CC) -c $<
yy.tab.o: yy.tab.cpp yy.tab.hpp common.h
	$(CC) -c $<
node.o: node.cpp yy.tab.hpp common.h
	$(CC) -c $<
lex.yy.cpp: scan.l yy.tab.hpp common.h
	flex --outfile=lex.yy.cpp scan.l
yy.tab.cpp: syntax.y common.h
	bison -yd --output=yy.tab.cpp syntax.y

#参考：http://blog.csdn.net/wtz1985/article/details/3862141

clean:
	rm *.o

run:
	./a.out TestCases/icg_test1.in >TestCases/icg_test1.i
	./a.out TestCases/icg_test2.in >TestCases/icg_test2.i
	./a.out TestCases/icg_test3.in >TestCases/icg_test3.i
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

