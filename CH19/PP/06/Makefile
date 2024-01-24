CC = gcc
CFLAGS = -Wall -Werror -Wpedantic
OBJECTS = queueclient.o queueADT.o

queue: $(OBJECTS)
	$(CC) -o queue $(OBJECTS) $(CFLAGS)

queueclient.o: queueclient.c queue.h
	$(CC) -c queueclient.c

queueADT.o: queueADT.c queue.h
	$(CC) -c queueADT.c

.PHONY: clean

clean:
	rm $(OBJECTS)
