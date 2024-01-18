#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

struct queue_ll *ll_create_q(void) {
  struct queue_ll *new_queue = malloc(sizeof(struct queue_ll));
  if (new_queue == NULL) {
    terminate("Create new queue failed: out of memory.");
  }
  new_queue->first = NULL;
  new_queue->last = NULL;
  return new_queue;
}

void ll_enqueue(struct queue_ll *q, Item i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    terminate("Enqueue failed: out of memory.");
  }
  new_node->value = i;
  if (ll_is_empty_q(q)) {
    q->first = new_node;
    q->last = new_node;
    return;
  } else {
    q->last->next = new_node;
    q->last = q->last->next;
    return;
  }
}

Item ll_dequeue(struct queue_ll *q) {
  if (ll_is_empty_q(q)) {
    printf("Queue is empty: returning 0.\n");
    return 0;
  }
  struct node *node = malloc(sizeof(struct node));
  if (node == NULL) {
    terminate("Dequeue failure: malloc failed.");
  }
  node = q->first;
  Item value = node->value;
  if (q->first == q->last) {
    q->first = NULL;
    q->last = NULL;
    free(node);
    return value;
  }
  q->first = node->next;
  free(node);
  return value;
}

Item ll_get_first(struct queue_ll *q) {
  if (ll_is_empty_q(q)) {
    printf("Queue is empty: returning 0.\n");
    return 0;
  } else {
    return q->first->value;
  }
}

Item ll_get_last(struct queue_ll *q) {
  if (ll_is_empty_q(q)) {
    printf("Queue is empty: returning 0.\n");
    return 0;
  } else {
    return q->last->value;
  }
}

bool ll_is_empty_q(struct queue_ll *q) { return q->first == NULL; }
