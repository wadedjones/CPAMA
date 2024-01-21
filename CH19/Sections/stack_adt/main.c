#include "stack.h"
#include <stdio.h>

int main(void) {
  Stack s = create();

  push(s, 10);
  push(s, 20);
  push(s, 30);
  push(s, 40);
  push(s, 50);

  int i, n;

  for (i = 0; i < s->top; i++) {
    printf("i: %d, value: %d\n", i, s->contents[i]);
  }

  n = peek(s);

  printf("n: %d\n", n);

  return 0;
}
