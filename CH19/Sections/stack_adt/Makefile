CC = gcc
OBJECTS = main.o stackADT.o
CFLAGS = -Wall -Werror

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

stackclient.o: main.c stack.h
	$(CC) -c main.c

stackADT.o: stackADT.c stack.h
	$(CC) -c stackADT.c

.PHONY: clean

clean:
	rm $(OBJECTS)
