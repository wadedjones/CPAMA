#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

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
  struct node *prev = NULL;

  for (; *list != NULL; prev = *list, *list = (*list)->next)
    ;
  if (prev == NULL) {
    *list = (*list)->next;
  } else {
    prev->next = (*list)->next;
  }
}
