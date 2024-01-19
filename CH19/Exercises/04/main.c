#include "stack_arr.h"
#include "stack_ll.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Stack_ll s = NULL;

  push_ll(&s, 10);
  push_ll(&s, 20);
  push_ll(&s, 30);
  push_ll(&s, 40);
  push_ll(&s, 50);

  print_ll(s);

  int i;

  i = pop_ll(&s);
  printf("i: %d\n", i);

  make_empty_ll(&s);
  print_ll(s);

  return 0;
}
