#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef int Item;
struct queue {
  Item contents[MAX_QUEUE_SIZE];
};
typedef struct queue *Queue;

void enqueue(Queue q);
Item dequeue(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
bool is_empty_q(Queue q);

#endif
