CC = gcc
objects = main.o stack.o

main: $(objects)
	$(CC) -o main $(objects)

main.o: main.c stack.h
	$(CC) -c main.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

.PHONY: clean
clean:
	rm $(objects)
