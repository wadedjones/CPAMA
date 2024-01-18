#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct queue;
typedef int Item;

void enqueue(struct queue *q);
Item dequeue(struct queue *q);
Item get_first(struct queue *q);
Item get_last(struct queue *q);
bool is_empty_q(struct queue *q);

#endif
