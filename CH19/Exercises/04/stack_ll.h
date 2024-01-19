#ifndef STACK_LL_H
#define STACK_LL_H

#include <stdbool.h>

struct node {
  int value;
  struct node *next;
};

typedef struct node *Stack_ll;

bool ll_stack_is_empty(Stack_ll *s);
void push_ll(Stack_ll *s, int i);
int pop_ll(Stack_ll *s);
void make_empty_ll(Stack_ll *s);
void print_ll(Stack_ll s);

#endif
