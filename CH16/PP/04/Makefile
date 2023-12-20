CC = gcc
objects = inventory.o readline.o quicksort.o

inventory: $(objects)
	$(CC) -o inventory $(objects)

inventory.o: inventory.c inventory.h readline.h
	$(CC) -c inventory.c

quicksort.o: quicksort.c inventory.h
	$(CC) -c quicksort.c

readline.o: readline.c readline.h
	$(CC) -c readline.c

.PHONY : clean
clean :
	-rm $(objects)
