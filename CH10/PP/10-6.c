/* Write a program that evaluates RPN expressions
 * 1 2 3 * + =
 * result: 7 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 20

/* external variables */
int top = 0;
int calc_stack[MAX_STACK];

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(int i);
int pop(void);
void read_rpn(int n, int calc_stack[n]);

int main(void) {
  for (;;) {
    printf("Enter an RPN expression: ");
    read_rpn(MAX_STACK, calc_stack);
  }
  return 0;
}

void read_rpn(int n, int calc_stack[n]) {
  char c;
  int tmp1, tmp2;
  make_empty();

  while ((c = getchar()) != '\n') {
    if (isdigit(c)) {
      push(c - '0');
    } else {
      // clang-format off
			switch (c) {
				case '*':
					tmp2 = pop();
					tmp1 = pop();
					push((tmp1 * tmp2));
					break;
				case '/':
					tmp2 = pop();
					tmp1 = pop();
					if (tmp2 == 0) {
						printf("Can't divide by zero.\n");
						break;
					}
					push((tmp1 / tmp2));
					break;
				case '+':
					tmp2 = pop();
					tmp1 = pop();
					push((tmp1 + tmp2));
					break;
				case '-':
					tmp2 = pop();
					tmp1 = pop();
					push((tmp1 - tmp2));
					break;
				case 'q':
					exit(EXIT_SUCCESS);
					break;
				case ' ':
					break;
				case '=':
					printf("Result: %d\n", pop());
					break;
				default:
					exit(EXIT_FAILURE);
					break;
			}
		}
	}
}

/* Functions for a simple Stack structure */

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

void push(int i) {
  if (is_full()) {
    printf("Stack Overflow");

  } else {
    calc_stack[top++] = i;
  }
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
  }
  return calc_stack[--top];
}
