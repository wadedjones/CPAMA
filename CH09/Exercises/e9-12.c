/* Write the following function:
 * double inner_product(double a[], double[b], int n);
 * returns: a[0] * b[0] + a[1] * b[1] ... + a[n - 1] * b[n - 1];
 */

#include <stdio.h>

#define MAX 10

double inner_product(double a[], double b[], int n);

int main(void) {
  int n = MAX;
  int i, k = 1;
  double a[n], b[n], result;

  for (i = 0; i < n; i++) {
    a[i] = k;
    b[i] = k;
    k++;
  }

  result = inner_product(a, b, n);

  printf("%lf\n", result);

  return 0;
}

double inner_product(double a[], double b[], int n) {
  if (n <= 0) {
    return 1;
  } else {
    return a[n] * b[n] + inner_product(a, b, n - 1);
  }
}
