CC=gcc

rpn: 10-6.o stack.o
	$(CC) -o rpn 10-6.o stack.o

10-6.o: 10-6.c stack.h
	$(CC) -c 10-6.c

stack.o: stack.c stack.h
	$(CC) -c stack.c
