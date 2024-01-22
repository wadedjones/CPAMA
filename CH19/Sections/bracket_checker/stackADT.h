#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char Item;

struct node {
  Item value;
  struct node *next;
};

struct stack_type {
  struct node *contents;
};

typedef struct stack_type *Stack;

Stack create_stack(void);
bool is_empty(Stack s);
void push_stack(Stack s, Item i);
Item pop_stack(Stack s);
void destroy_stack(Stack s);
void make_empty(Stack s);
bool push_char_stack(Stack s, const char *c);
void print_stack(Stack s);

#endif
