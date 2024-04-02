CC = gcc
OBJECTS = stackclient.o stackADT2.o
CFLAGS = -Wall -Werror

stack: $(OBJECTS)
	$(CC) -o stack $(OBJECTS) $(CFLAGS)

stackclient.o: stackclient.c stackADT2.h
	$(CC) -c stackclient.c

stackADT2.o: stackADT2.c stackADT2.h
	$(CC) -c stackADT2.c

.PHONY: clean

clean:
	rm $(OBJECTS)
