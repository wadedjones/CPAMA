CC = gcc
objects = main.o linked_list.o
flags = -Wall -Werror -v

main: $(objects)
	$(CC) -o main $(objects) $(flags)

main.o: main.c linked_list.h
	$(CC) -c main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c

.PHONY: clean
clean:
	rm $(objects)
