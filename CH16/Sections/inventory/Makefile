CC = gcc
objects = inventory.o readline.o

inventory : $(objects)
	gcc -o inventory $(objects)

inventory.o : inventory.c readline.h
	gcc -c inventory.c

readline.o : readline.c readline.h
	gcc -c readline.c

.PHONY : clean
clean :
	-rm $(objects)
