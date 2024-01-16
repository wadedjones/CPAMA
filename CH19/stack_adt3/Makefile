CC = gcc
OBJECTS = stackclient.o stackADT3.o
CFLAGS = -Wall -Werror

stack: $(OBJECTS)
	$(CC) -o stack $(OBJECTS) $(CFLAGS)

stackclient.o: stackclient.c stack3.h
	$(CC) -c stackclient.c

stackADT3.o: stackADT3.c stack3.h
	$(CC) -c stackADT3.c

.PHONY: clean

clean:
	rm $(OBJECTS)
