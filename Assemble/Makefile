CC = g++

main : main.o gen.o
	$(CC) -o $@ $^
main.o : main.cpp gen.h
	$(CC) -c $<
gen.o : gen.cpp gen.h
	$(CC) -c $<

clean :
	rm *.o
generate:

