CC = gcc
OBJECTS = stackclient.o stackADT.o
CFLAGS = -Wall -Werror

stack: $(OBJECTS)
	$(CC) -o stack $(OBJECTS) $(CFLAGS)

stackclient.o: stackclient.c stack.h
	$(CC) -c stackclient.c

stackADT.o: stackADT.c stack.h
	$(CC) -c stackADT.c

.PHONY: clean

clean:
	rm $(OBJECTS)
