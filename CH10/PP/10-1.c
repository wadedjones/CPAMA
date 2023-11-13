#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_underflow(void);
void stack_overflow(void);

int main(void) {
  char c, temp;
  printf("Enter brackets: ");
  while ((c = getchar()) != '\n') {
    if (c == '(' || c == '[' || c == '{') {
      push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      pop();
    }
  }
  if (is_empty()) {
    printf("Valid.\n");
  } else {
    printf("Invalid.\n");
  }

  return 0;
}

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

void push(char c) {
  if (is_full()) {
    stack_overflow();
  } else {
    contents[top++] = c;
  }
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
  }
  return contents[--top];
}

void stack_underflow(void) {
  printf("Stack Underflow. Invalid.\n");
  exit(1);
}

void stack_overflow(void) {
  printf("Stack Overflow.\n");
  exit(1);
}
