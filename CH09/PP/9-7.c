/* Rewrite the power function to be recursive */

#include <stdio.h>

int power(int x, int n);

int main(void) {
  int x, n;

  printf("Enter a number: ");
  scanf("%d", &x);
  printf("Enter a power: ");
  scanf("%d", &n);

  printf("%d\n", power(x, n));

  return 0;
}

int power(int x, int n) {
  int i;
  if (n == 0)
    return 1;
  if (n % 2 == 0) {
    i = power(x, n / 2);
    return i * i;
  } else {
    return x * power(x, n - 1);
  }
}
