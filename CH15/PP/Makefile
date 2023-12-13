CC=gcc

justify: justify.o word.o line.o
	$(CC) -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	$(CC) -c justify.c

word.o: word.c word.h
	$(CC) -c word.c

line.o: line.c line.h
	$(CC) -c line.c
