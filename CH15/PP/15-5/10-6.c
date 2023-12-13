/* Write a program that evaluates RPN expressions
 * 1 2 3 * + =
 * result: 7 */

#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 20

/* external variables */
int calc_stack[MAX_STACK];

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
      push(c - '0', calc_stack);
    } else {
      // clang-format off
			switch (c) {
				case '*':
					tmp2 = pop(calc_stack);
					tmp1 = pop(calc_stack);
					push((tmp1 * tmp2), calc_stack);
					break;
				case '/':
					tmp2 = pop(calc_stack);
					tmp1 = pop(calc_stack);
					if (tmp2 == 0) {
						printf("Can't divide by zero.\n");
						break;
					}
					push((tmp1 / tmp2), calc_stack);
					break;
				case '+':
					tmp2 = pop(calc_stack);
					tmp1 = pop(calc_stack);
					push((tmp1 + tmp2), calc_stack);
					break;
				case '-':
					tmp2 = pop(calc_stack);
					tmp1 = pop(calc_stack);
					push((tmp1 - tmp2), calc_stack);
					break;
				case 'q':
					exit(EXIT_SUCCESS);
					break;
				case ' ':
					break;
				case '=':
					printf("Result: %d\n", pop(calc_stack));
					break;
				default:
					exit(EXIT_FAILURE);
					break;
			}
		}
	}
}

