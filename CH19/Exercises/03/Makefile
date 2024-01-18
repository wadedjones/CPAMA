main: main.o queue_ll.o
	gcc -o main main.o queue_ll.o

main.o: main.c queue.h
	gcc -c main.c

queue_ll.o: queue_ll.c queue.h
	gcc -c queue_ll.c

.PHONY: clean

clean: 
	rm *.o
