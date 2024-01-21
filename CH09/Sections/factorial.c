/* Factorial function */

#include <stdio.h>

int fact(int n);

int main(void) {

  int n = 10;
  printf("%d\n", fact(n));

  return 0;
}

int fact(int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}
