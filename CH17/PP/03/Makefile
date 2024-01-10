CC = gcc
objects = inventory2.o readline.o

inventory: $(objects)
	$(CC) -o inventory $(objects)

inventory2.o: inventory2.c readline.h
	$(CC) -c inventory2.c

readline.o: readline.c readline.h
	$(CC) -c readline.c

.PHONY: clean
clean :
	rm $(objects)
