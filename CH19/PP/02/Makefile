CC = gcc
CFLAGS = -Wall -Wextra -Wpendatic
OBJECTS = main.o stackADT.o

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main.o: main.c stackADT.h
	$(CC) -c main.c

stackADT.o: stackADT.c stackADT.h
	$(CC) -c stackADT.c

.PHONY: clean

clean:
	rm $(OBJECTS)
