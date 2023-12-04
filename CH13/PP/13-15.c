/* Modify PP 6 from chapter 10 so that it includes the following function:
 * int evaluate_RPN_expression(const char *expression);
 * The function returns the value of the RPN expression pointed to by
 * expression.*/

/* Write a program that evaluates RPN expressions
 * 1 2 3 * + =
 * result: 7 */

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int evaluate_RPN_expression(const char *expression);

int main(void) {
  char expression[MAX_STACK];
  int result;

  for (;;) {
    printf("Enter an RPN expression: ");

    fgets(expression, MAX_STACK, stdin);
    expression[strcspn(expression, "\n")] = 0;

    result = evaluate_RPN_expression(expression);

    printf("%d\n", result);
  }
  return 0;
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
  exit(EXIT_FAILURE);
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

int evaluate_RPN_expression(const char *expression) {
  const char *p = expression;
  int tmp1, tmp2;
  make_empty();

  while (*p) {
    if (isdigit(*p)) {
      push(*p++ - '0');
    } else {
      // clang-format off
			switch (*p++) {
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
					break;
				default:
					exit(EXIT_FAILURE);
					break;
			}
		}
	}
	return pop();
}
