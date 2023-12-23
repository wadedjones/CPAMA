#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *add_to_list(struct node *list, int n) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = list;
  return new_node;
}
