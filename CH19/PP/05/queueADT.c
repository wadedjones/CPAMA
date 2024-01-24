#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct queue_type {
  int items_arr[MAX_ITEMS];
  int count;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create_queue(void) {
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL) {
    terminate("Create queue failed.");
  }
  q->count = 0;
  return q;
}

bool is_empty_q(Queue q) { return q->count == 0; }

bool is_full_q(Queue q) { return q->count == MAX_ITEMS; }

void destroy_queue(Queue q) {
  while (!is_empty_q(q)) {
    dequeue(q);
  }
  free(q);
}

void enqueue(Queue q, Item i) {
  if (is_full_q(q)) {
    terminate("Enqueue failed: queue is full.");
  }
  q->items_arr[q->count++] = i;
}

Item dequeue(Queue q) {
  if (is_empty_q(q)) {
    terminate("Dequeue failed: queue is empty.");
  }
  Item n = q->items_arr[0];
  int i;
  for (i = 0; i < q->count; i++) {
    q->items_arr[i] = q->items_arr[i + 1];
  }
  q->count--;
  return n;
}

Item get_first(Queue q) {
  if (is_empty_q(q)) {
    terminate("Get first failed: queue is empty.");
  }
  return q->items_arr[0];
}

Item get_last(Queue q) {
  if (is_empty_q(q)) {
    terminate("Get last failed: queue is empty.");
  }
  return q->items_arr[q->count - 1];
}

void print_queue(Queue q) {
  int i;
  for (i = 0; i < q->count; i++) {
    printf("Queue Item: %d\n", q->items_arr[i]);
  }
}
