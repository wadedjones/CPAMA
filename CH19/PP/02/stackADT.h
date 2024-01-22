#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK 20

struct node {
  int value;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

typedef struct stack_type *Stack;

Stack create_stack(void);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, int i);
int pop(Stack s);
void read_rpn(Stack s);

#endif
