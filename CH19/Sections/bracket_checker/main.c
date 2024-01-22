#include "stackADT.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

int main(void) {
  Stack s;
  s = create_stack();
  char c[MAX_INPUT];

  printf("Enter a bracket notation: ");
  fgets(c, MAX_INPUT, stdin);
  c[strcspn(c, "\n")] = 0;

  bool x = push_char_stack(s, c);

  if (x) {
    printf("brackets are chill.\n");
  } else {
    printf("brackets are wrong.\n");
  }

  return 0;
}
