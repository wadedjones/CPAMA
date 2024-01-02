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

void add_to_list2(struct node **list, int n) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed add_to_list2\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = *list;
}

void add_to_end(struct node **list, int n) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed add_to_end\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
    return;
  } else {
    struct node *last_node = *list;

    while (last_node->next != NULL) {
      last_node = last_node->next;
    }
    last_node->next = new_node;
  }
}
