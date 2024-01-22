#include "stackADT.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create_stack(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    terminate("Create stack failed.");
  }
  s->top = NULL;
  return s;
}

void read_rpn(Stack s) {
  char c;
  int tmp1, tmp2;
  make_empty(s);

  while ((c = getchar()) != '\n') {
    if (isdigit(c)) {
      push(s, c - '0');
    } else {
      // clang-format off
			switch (c) {
				case '*':
					tmp2 = pop(s);
					tmp1 = pop(s);
					push(s, (tmp1 * tmp2));
					break;
				case '/':
					tmp2 = pop(s);
					tmp1 = pop(s);
					if (tmp2 == 0) {
						printf("Can't divide by zero.\n");
						break;
					}
					push(s, (tmp1 / tmp2));
					break;
				case '+':
					tmp2 = pop(s);
					tmp1 = pop(s);
					push(s, (tmp1 + tmp2));
					break;
				case '-':
					tmp2 = pop(s);
					tmp1 = pop(s);
					push(s, (tmp1 - tmp2));
					break;
				case 'q':
					exit(EXIT_SUCCESS);
					break;
				case ' ':
					break;
				case '=':
					printf("Result: %d\n", pop(s));
					break;
				default:
					exit(EXIT_FAILURE);
					break;
			}
		}
	}
}

void make_empty(Stack s) {
	while (!is_empty(s)) {
		pop(s);
	}
}

bool is_empty(Stack s) { return s->top == NULL; }

void push(Stack s, int i) {
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Push failed: out of memory.");
	}
	if (s == NULL) {
		s->top = new_node;
	}
	new_node->value = i;
	new_node->next = s->top;
	s->top = new_node;
}

int pop(Stack s) {
  if (is_empty(s)) {
		terminate("Pop failed, stack is empty.");
  }
	struct node *old_node = s->top;
	int i = old_node->value;
	s->top = old_node->next;
	free(old_node);
	return i;
}
