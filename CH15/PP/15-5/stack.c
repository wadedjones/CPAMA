#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 20

int top = 0;

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == MAX_STACK; }

void stack_overflow(void) {
  printf("Stack Overflow.\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Stack Underflow.\n");
  // exit(EXIT_FAILURE);
}

void push(int i, int *calc_stack) {
  if (is_full()) {
    printf("Stack Overflow");

  } else {
    calc_stack[top++] = i;
  }
}

int pop(int *calc_stack) {
  if (is_empty()) {
    stack_underflow();
  }
  return calc_stack[--top];
}
