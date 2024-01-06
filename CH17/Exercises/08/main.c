#include "stack.h"

int main(void) {
  struct node *top = NULL;
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = 50;
  new_node->next = NULL;
  int count;

  push(10, &top);
  push(20, &top);
  push(30, &top);
  push(40, &top);
  push(70, &top);

  print_list(top);

  insert_into_ordered_list(top, new_node);

  print_list(top);

  return 0;
}
