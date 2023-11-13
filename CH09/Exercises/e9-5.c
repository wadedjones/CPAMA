/* Write a function num_digits(n) that returns the number of digits in n
 * (a positive integer) HINT: divide by 10 repeatedly */

#include <stdio.h>

int num_digits(int n) {
  int digits = 0;
  while (n > 0) {
    digits++;
    n /= 10;
  }
  return digits;
}

int main(void) {
  printf("%d\n", num_digits(2112));
  return 0;
}
