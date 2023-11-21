/* Simplify PP 2(b) by taking advantage of the fact that an array name can be
 * used as a pointer. */

// Again, I already used an array name as a pointer in the first solution
// WHOOPS.

#include <ctype.h>
#include <stdio.h>

#define LEN 50

int main(void) {
  char a[LEN] = {0};
  char *p = a, *q;
  char c;

  while ((c = getchar()) != '\n') {
    if (isalpha(c)) {
      *p++ = toupper(c);
    }
  }
  p--;

  for (q = a; q < p; q++, p--) {
    if (*q != *p) {
      printf("Not a Palindrome\n");
      return 0;
    }
  }
  printf("Palindrome\n");

  return 0;
}
