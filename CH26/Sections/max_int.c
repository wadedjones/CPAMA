/* function to find max int with variable length args */

#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...) {
  va_list ap;
  int i, current, largest;

  va_start(ap, n);
  largest = va_arg(ap, int);

  for (i = 1; i < n; i++) {
    current = va_arg(ap, int);
    if (current > largest) {
      largest = current;
    }
  }

  va_end(ap);
  return largest;
}

int main(void) {
  int n = max_int(6, 11, 12, 9, 3, 99, 21);

  printf("n: %d\n", n);

  return 0;
}
