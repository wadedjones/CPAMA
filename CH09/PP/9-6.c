/* Write a function that computes the value of the following polynomial:
 * 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */

#include <math.h>
#include <stdio.h>

int poly_func(int n);

int main(void) {
  int n, answer;

  printf("Enter a value for x: ");
  scanf("%d", &n);

  answer = poly_func(n);

  printf("%d\n", answer);

  return 0;
}

int poly_func(int n) {
  return (3 * pow(n, 5) + (2 * pow(n, 4)) - (5 * pow(n, 3)) - (n * n) +
          (7 * n) - 6);
}
