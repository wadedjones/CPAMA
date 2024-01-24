#include "stackADT3.h"
#include <stdio.h>

int main(void) {
  Stack s1, s2;
  int n;

  s1 = create();
  s2 = create();

  push(s1, 1);
  printf("Stack s1 len: %d\n", length(s1));
  push(s1, 2);
  printf("Stack s1 len: %d\n", length(s1));

  n = pop(s1);
  printf("Popped %d from s1\n", n);
  printf("Stack s1 len: %d\n", length(s1));
  push(s2, n);
  printf("Stack s2 len: %d\n", length(s2));
  n = pop(s1);
  printf("Popped %d from s1\n", n);
  printf("Stack s1 len: %d\n", length(s1));
  push(s2, n);
  printf("Stack s2 len: %d\n", length(s2));

  destroy(s1);

  while (!is_empty(s2)) {
    printf("Popped %d from s2\n", pop(s2));
    printf("Stack s2 len: %d\n", length(s2));
  }

  push(s2, 3);
  printf("Stack s2 len: %d\n", length(s2));
  make_empty(s2);
  if (is_empty(s2)) {
    printf("s2 is empty\n");
  } else {
    printf("s2 is not empty\n");
  }

  destroy(s2);

  s1 = create();

  push(s1, 10);
  push(s1, 20);
  push(s1, 30);

  int x = peek(s1);

  printf("x: %d\n", x);

  return 0;
}
