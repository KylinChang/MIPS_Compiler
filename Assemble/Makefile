CC = gcc

main : main.o gen.o
	$(CC) -o $@ $^
main.o : main.c gen.h
	$(CC) -c $<
gen.o : gen.c gen.h
	$(CC) -c $<

clean :
	rm *.o
generate:

