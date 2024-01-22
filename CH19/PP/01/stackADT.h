#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

struct stack_type {
  char contents[STACK_SIZE];
  int top;
};

typedef struct stack_type *Stack;

void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, char c);
char pop(Stack s);
void get_input(Stack s);

#endif
