#include "stack.h"

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

void print_list(struct node *top) {
  struct node *p = top;

  if (p == NULL) {
    printf("List empty\n");
  }

  while (p != NULL) {
    printf("Value: %d\n", p->value);
    p = p->next;
  }
}

int count_occurrences(struct node *list, int n) {
  int count = 0;

  while (list != NULL) {
    if (list->value == n) {
      count++;
    }
    list = list->next;
  }
  return count;
}

struct node *find_last(struct node *list, int n) {
  struct node *temp = NULL;

  while (list != NULL) {
    if (list->value == n) {
      temp = list;
    }
    list = list->next;
  }
  return temp;
}

struct node *insert_into_ordered_list(struct node *list,
                                      struct node *new_node) {
  struct node *cur = list, *prev = NULL;
  while (cur->value <= new_node->value) {
    prev = cur;
    cur = cur->next;
  }
  prev->next = new_node;
  new_node->next = cur;
  return list;
}
