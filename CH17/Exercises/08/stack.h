#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
  int value;
  struct node *next;
};

void make_empty(struct node **top);
bool is_empty(struct node **top);
void stack_overflow(void);
void stack_underflow(void);
bool push(int i, struct node **top);
struct node *pop(struct node **top);

#endif
