#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_STACK 100

typedef int Item;

struct queue {
  int insert, remove, count;
  Item items[MAX_STACK];
};

struct node {
  Item value;
  struct node *next;
};

struct queue_ll {
  struct node *first, *last;
};

struct queue *create_q(void);
void enqueue(struct queue *q, Item i);
Item dequeue(struct queue *q);
Item get_first(struct queue *q);
Item get_last(struct queue *q);
bool is_empty_q(struct queue *q);

struct queue_ll *ll_create_q(void);
void ll_enqueue(struct queue_ll *q, Item i);
Item ll_dequeue(struct queue_ll *q);
Item ll_get_first(struct queue_ll *q);
Item ll_get_last(struct queue_ll *q);
bool ll_is_empty_q(struct queue_ll *q);

#endif
