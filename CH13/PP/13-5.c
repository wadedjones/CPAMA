/* Write a program named sum.c (13-5.c) that adds up its command-line arguments,
 * which are assumed to be integers. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, sum = 0;

  for (i = 1; i < argc; i++) {
    sum += atoi(argv[i]);
  }

  printf("Total: %d\n", sum);

  return 0;
}
