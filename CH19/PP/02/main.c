#include "stackADT.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 20

int main(void) {
  Stack s = create_stack();

  for (;;) {
    printf("Enter an RPN expression: ");
    read_rpn(s);
  }
  return 0;
}
