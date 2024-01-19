#include "stack_ll.h"
#include <stdio.h>
#include <stdlib.h>

static void terminate_ll(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

bool ll_stack_is_empty(Stack_ll *s) { return *s == NULL; }

void push_ll(Stack_ll *s, int i) {
  Stack_ll new_node = malloc(sizeof(Stack_ll));
  if (new_node == NULL) {
    terminate_ll("Push failed: out of memory.");
  }

  if (s == NULL) {
    printf("s == NULL\n");
    s = &new_node;
    (*s)->next = NULL;
    return;
  }

  new_node->value = i;
  new_node->next = *s;
  (*s) = new_node;
}

int pop_ll(Stack_ll *s) {
  if (ll_stack_is_empty(s)) {
    printf("Stack is empty, returning 0.\n");
    return 0;
  }

  Stack_ll old_node = *s;
  if (old_node == NULL) {
    terminate_ll("Pop failed: malloc issue.");
  }

  int i = old_node->value;
  (*s) = (*s)->next;
  free(old_node);

  return i;
}

void make_empty_ll(Stack_ll *s) {
  while (!ll_stack_is_empty(s)) {
    pop_ll(s);
  }
}

void print_ll(Stack_ll s) {
  if (ll_stack_is_empty(&s)) {
    printf("Stack is empty...\n");
  }

  Stack_ll ptr = s;

  while (ptr != NULL) {
    printf("%d\n", ptr->value);
    ptr = ptr->next;
  }
}
