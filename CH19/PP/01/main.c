#include "stackADT.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Stack s;
  s->top = 0;

  char c, temp;

  printf("Enter brackets: ");
  get_input(s);
  if (is_empty(s)) {
    printf("Valid.\n");
  } else {
    printf("Invalid.\n");
  }

  return 0;
}
