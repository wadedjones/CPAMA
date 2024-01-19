#include "stack_arr.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct stack_type {
  int contents[MAX_STACK_SIZE];
  int top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create_stack(void) {
  Stack new_stack = malloc(sizeof(Stack));
  if (new_stack == NULL) {
    terminate("Create Stack failed.\n");
  }
  new_stack->top = 0;
  return new_stack;
}

bool stack_is_empty(Stack s) { return s->top == 0; }

bool stack_is_full(Stack s) { return s->top == MAX_STACK_SIZE; }

void make_stack_empty(Stack s) { s->top = 0; }

void push_stack(Stack s, int value) {
  if (stack_is_full(s)) {
    terminate("Push failed: stack is full.");
  }
  s->contents[s->top++] = value;
}

int pop_stack(Stack s) {
  if (stack_is_empty(s)) {
    terminate("Pop failed: stack is empty.");
  }
  return s->contents[--s->top];
}

void print_stack(Stack s) {
  if (stack_is_empty(s)) {
    printf("Stack is empty...\n");
  }
  int i;
  for (i = 0; i < s->top; i++) {
    printf("Item #%d: %d\n", i + 1, s->contents[i]);
  }
}
