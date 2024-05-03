/* function to find max int with variable length args */

#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...) {
  va_list ap;
  int total_nums = 1;
  int current, largest;

  va_start(ap, n);
  while ((current = va_arg(ap, int)) != 0) {
    total_nums++;
  }

  va_start(ap, n);
  largest = va_arg(ap, int);

  for (int i = 1; i < total_nums; i++) {
    current = va_arg(ap, int);
    if (current > largest) {
      largest = current;
    }
  }

  va_end(ap);
  return largest;
}

int main(void) {
  int n = max_int(98, 11, 12, 90, 3, 99, 21, 45, 103, 23, 0);

  printf("n: %d\n", n);

  return 0;
}
