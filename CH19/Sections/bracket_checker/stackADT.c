#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

static Item peek_stack(Stack s) {
  if (is_empty(s)) {
    terminate("Peek failed: stack is empty.");
  }
  return s->contents->value;
}

Stack create_stack(void) {
  Stack new_stack = malloc(sizeof(struct stack_type));
  if (new_stack == NULL) {
    terminate("Create stack failed: out of memory.");
  }
  new_stack->contents = NULL;
  return new_stack;
}

bool is_empty(Stack s) { return s->contents == NULL; }

void make_empty(Stack s) {
  while (!is_empty(s)) {
    pop_stack(s);
  }
}

void destroy_stack(Stack s) { make_empty(s); }

bool push_char_stack(Stack s, const char *c) {
  int i, n = strlen(c);
  for (i = 0; i < n; i++) {
    if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
      push_stack(s, c[i]);
    } else if (c[i] == ')' && peek_stack(s) == '(') {
      pop_stack(s);
    } else if (c[i] == ']' && peek_stack(s) == '[') {
      pop_stack(s);
    } else if (c[i] == '}' && peek_stack(s) == '{') {
      pop_stack(s);
    }
  }
  return is_empty(s);
}

void push_stack(Stack s, Item i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    terminate("Push failed: out of memory.");
  }
  new_node->value = i;
  if (is_empty(s)) {
    s->contents = new_node;
    return;
  }
  new_node->next = s->contents;
  s->contents = new_node;
}

Item pop_stack(Stack s) {
  if (is_empty(s)) {
    terminate("Pop failed: stack is empty.");
  }
  struct node *old_node = s->contents;
  int i = old_node->value;
  s->contents = old_node->next;
  free(old_node);
  return i;
}

void print_stack(Stack s) {
  if (is_empty(s)) {
    terminate("Nothing to print, stack is empty.");
  }
  struct node *ptr = s->contents;

  while (ptr != NULL) {
    printf("Value: %c\n", ptr->value);
    ptr = ptr->next;
  }
}
