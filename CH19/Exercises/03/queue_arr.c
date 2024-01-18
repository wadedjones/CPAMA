#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct queue *create_q(void) {
  struct queue *q = malloc(sizeof(struct queue));
  q->count = 0;
  q->remove = 0;
  q->insert = 0;

  for (int i = 0; i < MAX_STACK; i++) {
    q->items[i] = 0;
  }
  return q;
}

void enqueue(struct queue *q, Item i) {
  if (q->insert == MAX_STACK) {
    q->insert = 0;
  }
  if (q->remove == MAX_STACK) {
    q->remove = 0;
  }
  if (q->count == MAX_STACK) {
    printf("Queue is full.\n");
    return;
  }
  q->items[q->insert] = i;
  q->count++;
  q->insert++;
}

Item dequeue(struct queue *q) {
  if (q->count == 0) {
    printf("Queue is empty.\n");
    return 0;
  }
  int i = q->items[q->remove];
  q->items[q->remove] = 0;
  q->remove++;
  q->count--;
  return i;
}

Item get_first(struct queue *q) { return q->items[q->remove]; }

Item get_last(struct queue *q) { return q->items[q->count - 1]; }

bool is_empty_q(struct queue *q) { return q->count == 0; }
