#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

static void stack_underflow(void) {
  printf("Stack Underflow. Invalid.\n");
  exit(EXIT_FAILURE);
}

static void stack_overflow(void) {
  printf("Stack Overflow.\n");
  exit(EXIT_FAILURE);
}

void make_empty(Stack s) { s->top = 0; }

bool is_empty(Stack s) { return s->top == 0; }

bool is_full(Stack s) { return s->top == STACK_SIZE; }

static char peek(Stack s) {
  if (is_empty(s)) {
    stack_underflow();
  }
  return s->contents[s->top - 1];
}

void push(Stack s, char c) {
  if (is_full(s)) {
    stack_overflow();
  } else {
    s->contents[s->top++] = c;
  }
}

char pop(Stack s) {
  if (is_empty(s)) {
    stack_underflow();
  }
  return s->contents[--s->top];
}

void get_input(Stack s) {
  char c;

  while ((c = getchar()) != '\n') {
    if (c == '(' || c == '[' || c == '{') {
      push(s, c);
    } else if (c == ')' && peek(s) == '(') {
      pop(s);
    } else if (c == ']' && peek(s) == '[') {
      pop(s);
    } else if (c == '}' && peek(s) == '{') {
      pop(s);
    }
  }
}
