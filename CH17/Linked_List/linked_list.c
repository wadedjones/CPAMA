/* Examples of linked lists */

#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *add_to_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
void print_linked_list(struct node *list);

int main(void) {
  // Initialize the list
  struct node *first = NULL;

  /* Creating a node requires three steps:
   * 1. Allocate memory for the node.
   * 2. Store data in the node.
   * 3. Insert node into the list. */
  struct node *new_node = malloc(sizeof(struct node));
  //(*new_node).value = 10;
  new_node->value = 10;
  new_node->next = first;
  first = new_node;

  // Or use a function to add a new node
  first = add_to_list(first, 20);
  first = add_to_list(first, 32);
  first = add_to_list(first, 69);
  first = add_to_list(first, 4);

  print_linked_list(first);

  delete_from_list(first, 32);

  print_linked_list(first);

  return 0;
}

// Simple function to add to linked list.
// Numbers will be in reverse order though. WHOMP
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

/* 4 Variations of searching a linked list */

struct node *search_list_a(struct node *list, int n) {
  struct node *p;

  for (p = list; p != NULL; p = p->next) {
    if (p->value == n) {
      return p;
    }
  }
  return NULL;
}

struct node *search_list_b(struct node *list, int n) {
  for (; list != NULL; list = list->next) {
    if (list->value == n) {
      return list;
    }
  }
  return NULL;
}

struct node *search_list_c(struct node *list, int n) {
  for (; list != NULL && list->value != n; list = list->next)
    ;
  return list;
}

struct node *search_list_d(struct node *list, int n) {
  while (list != NULL && list->value != n) {
    list = list->next;
  }
  return list;
}

/* Deleting a node involves three steps:
 * 1. Locate the node to be deleted.
 * 2. Alter the previous node so that it "bypasses" the deleted node.
 * 3. Call free to reclaim the space occupied by the deleted node. */

struct node *delete_from_list(struct node *list, int n) {
  struct node *cur, *prev;

  for (cur = list, prev = NULL; cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;
  if (cur == NULL) {
    return list; // n was not found
  }
  if (prev == NULL) {
    list = list->next; // n is in the first node
  } else {
    prev->next = cur->next; // n is in some other node
  }
  free(cur);
  return list;
}

// For fun, print list
void print_linked_list(struct node *list) {
  for (; list != NULL; list = list->next) {
    printf("Value: %d\n", list->value);
  }
}
