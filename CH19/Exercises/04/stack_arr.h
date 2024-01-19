#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create_stack(void);
bool stack_is_empty(Stack s);
bool stack_is_full(Stack s);
void make_stack_empty(Stack s);
void push_stack(Stack s, int value);
int pop_stack(Stack s);
void print_stack(Stack s);

#endif
