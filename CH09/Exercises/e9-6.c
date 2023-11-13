/* Write a function digit(n, k) that returns the kth digit (from the right)
 * in n (a positive int). For example, digit(829, 1) returns 9, digit(829, 2)
 * returns 2, and digit(829, 3), returns 8. If k is greater than the number
 * of digits in n, return 0. */

#include <stdio.h>

int digit(int n, int k) {
  int value;
  while (k > 1) {
    n /= 10;
    k--;
  }
  n %= 10;

  return n;
}

int main(void) {
  int n = 829;

  printf("%d\n", digit(829, 1));
  printf("%d\n", digit(2034, 3));
  printf("%d\n", digit(345, 2));
  printf("%d\n", digit(456789, 4));

  return 0;
}
