#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create_queue(void);
void destroy_queue(Queue q);
bool is_empty_q(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
void print_queue(Queue q);

#endif
