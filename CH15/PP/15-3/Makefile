CC=gcc

qsort: qsort.o quicksort.o
	$(CC) -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	$(CC) -c qsort.c

quicksort.o: quicksort.c quicksort.h
	$(CC) -c quicksort.c
