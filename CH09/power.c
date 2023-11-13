/* Power function */

#include <stdio.h>

int power(int x, int n);

int main(void) {
  int x = 5, n = 3;

  printf("%d\n", power(x, n));

  return 0;
}

int power(int x, int n) { return n == 0 ? 1 : x * power(x, n - 1); }
