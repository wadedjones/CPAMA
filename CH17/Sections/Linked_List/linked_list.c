/* Examples of linked lists */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

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

// add to list using a pointer to a pointer
void add_to_list2(struct node **list, int n) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list2\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = *list;
  *list = new_node;
  /* add_to_list2(&first, 10); */
}

// add to end of linked list
// requires first call of add_to_end to be assigned to the LL head.
struct node *add_to_end(struct node *list, int n) {

  struct node *new_node = malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Error: malloc failed add_to_list\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = NULL;

  if (list == NULL) {
    list = new_node;
    return list;
  }

  if (list->next == NULL) {
    list->next = new_node;
  } else {
    struct node *cur = list;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = new_node;
  }

  return list;
}

void add_to_end2(struct node **list, int n) {
  struct node *new_node = malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Error: malloc failed add_to_list\n");
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

void delete_from_list2(struct node **list, int n) {
  struct node *prev = *list;

  while (prev) {
    if (prev->value == n) {
      *list = prev->next;
      break;
    }
    list = &prev->next;
    prev = prev->next;
  }
}

// For fun, print list
void print_linked_list(struct node *list) {
  if (list == NULL) {
    printf("list is NULL\n");
    return;
  }
  printf("------------Print Linked List------------\n");
  while (list != NULL) {
    printf("Value: %d\n", list->value);
    list = list->next;
  }
}

struct node *insert_into_ordered_list(struct node *list,
                                      struct node *new_node) {
  struct node *cur = list, *prev = NULL;
  if (cur == NULL) {
    return new_node;
  }
  while (cur->value <= new_node->value) {
    if (cur->next == NULL) {
      cur->next = new_node;
      return list;
    }
    prev = cur;
    cur = cur->next;
  }
  if (prev == NULL) {
    new_node->next = cur;
    return new_node;
  }
  prev->next = new_node;
  new_node->next = cur;
  return list;
}

void insert_into_ordered_list2(struct node **list, struct node *new_node) {
  struct node *p;

  if (*list == NULL || (*list)->value >= new_node->value) {
    new_node->next = *list;
    *list = new_node;
  } else {
    p = *list;
    while (p->next != NULL && p->next->value < new_node->value) {
      p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
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
  struct node *result = NULL;

  while (list != NULL) {
    if (list->value == n) {
      result = list;
    }
    list = list->next;
  }
  return result;
}
