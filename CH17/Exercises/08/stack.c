#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

void make_empty(struct node **top) {
  struct node *temp;

  while (*top != NULL) {
    temp = *top;
    *top = (*top)->next;
    free(temp);
  }
}

bool is_empty(struct node **top) { return *top == NULL; }

bool push(int i, struct node **top) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    return false;
  } else {
    new_node->value = i;
    new_node->next = *top;
    *top = new_node;
    return true;
  }
}

struct node *pop(struct node **top) {
  if (is_empty(top)) {
    return NULL;
  }
  struct node *temp;
  temp = *top;
  *top = (*top)->next;
  return temp;
}
