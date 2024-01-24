#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Item data;
  struct node *next;
};

struct queue_type {
  struct node *head, *last;
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
  q->head = NULL;
  q->last = NULL;
  return q;
}

bool is_empty_q(Queue q) { return q->head == NULL; }

void destroy_queue(Queue q) {
  while (!is_empty_q(q)) {
    dequeue(q);
  }
  free(q);
}

void enqueue(Queue q, Item i) {
  struct node *temp, *n = malloc(sizeof(struct node));
  if (n == NULL) {
    terminate("Enqueue failed: malloc is NULL.");
  }
  n->data = i;
  if (is_empty_q(q)) {
    q->head = n;
    q->last = n;
    return;
  }
  temp = q->last;
  temp->next = n;
  q->last = n;
  n->next = NULL;
}

Item dequeue(Queue q) {
  if (is_empty_q(q)) {
    terminate("Dequeue failed: queue is empty.");
  }
  struct node *p = q->head;
  Item i = p->data;
  q->head = q->head->next;
  free(p);
  return i;
}

Item get_first(Queue q) {
  if (is_empty_q(q)) {
    terminate("Get first failed: queue is empty.");
  }
  return q->head->data;
}

Item get_last(Queue q) {
  if (is_empty_q(q)) {
    terminate("Get last failed: queue is empty.");
  }
  return q->last->data;
}

void print_queue(Queue q) {
  struct node *p = q->head;
  if (p == NULL) {
    printf("Queue is empty.\n");
    return;
  }
  while (p != NULL) {
    printf("Value: %d\n", p->data);
    p = p->next;
  }
}
