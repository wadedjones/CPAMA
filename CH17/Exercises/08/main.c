#include "stack.h"
#include <stdio.h>

void print_list(struct node *top);

int main(void) {
  struct node *top = NULL;

  push(10, &top);
  push(20, &top);
  push(30, &top);
  push(40, &top);

  print_list(top);

  make_empty(&top);

  push(69, &top);
  push(13, &top);
  push(420, &top);

  print_list(top);

  struct node *n = pop(&top); // 420
  printf("n: %d\n", n->value);

  pop(&top); // 13
  pop(&top); // 69
  pop(&top); // NULL

  print_list(top);

  return 0;
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
