/* Practice with pointers! */

#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part);

int main(void) {
  double x, frac_part;
  long int_part;

  x = 3.14159;

  decompose(x, &int_part, &frac_part);

  printf("x: %lf\n", x);
  printf("frac_part: %lf\n", frac_part);
  printf("int_part: %ld\n", int_part);

  return 0;
}

void decompose(double x, long *int_part, double *frac_part) {
  *int_part = (long)x;
  *frac_part = x - *int_part;
}
