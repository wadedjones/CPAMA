/* Write a recursive version of the gcd function from exercise 3.
 */

int gcd_non_r(int m, int n) {
  int tmp;

  while (n > 0) {
    tmp = m % n;
    m = n;
    n = tmp;
  }

  return m;
}

int gcd_r(int m, int n) { return n == 0 ? m : gcd_r(n, m % n); }

#include <stdio.h>

int main(void) {
  int m, n, result1, result2;
  m = 24;
  n = 346;

  result1 = gcd_non_r(m, n);
  result2 = gcd_r(m, n);

  printf("result1: %d\n", result1);
  printf("result2: %d\n", result2);

  return 0;
}
