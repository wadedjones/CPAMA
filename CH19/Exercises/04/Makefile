CC = gcc
OBJECTS = main.o stack_ll.o
CFLAGS = -Wall -Werror

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main.o: main.c stack_ll.h
	$(CC) -c main.c

stack_arr.o: stack_ll.c stack_ll.h
	$(CC) -c stack_ll.c

.PHONY: clean

clean:
	rm $(OBJECTS)
