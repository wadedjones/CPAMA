#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

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
