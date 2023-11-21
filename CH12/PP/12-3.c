/* Simplify PP 1(b) by taking advantage of the fact that an array name can be
 * used as a pointer. */

// I actually used a pointer for the array name in the first solution OOPS.

#include <stdio.h>

#define LEN 100

int main(void) {
  char a[LEN] = {0};
  char *p = a;
  char c;
  int i = 0;

  printf("Enter a message: ");

  while ((c = getchar()) != '\n') {
    *p++ = c;
  }

  printf("Reversal is: ");
  for (; p >= &a[0]; p--) {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
