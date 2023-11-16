/* Modify PP 3 from chapter 6 so that it includes the following function:
 *
 * void reduce(int numerator, int denominator,
 * 						 int *reduced_numerator,
 * 						 int *reduced_denominator)
 *
 * numerator and denominator are the numerator and denominator of a fraction.
 * reduced_numerator and reduced_denominator are pointers to variables in which
 * the function will store the numerator and denominator of the fraction once
 * it has been reduced to lowest terms. */

#include <math.h>
#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator);

int main(void) {
  int n, d, tmpn, tmpd;

  printf("Enter a fraction: ");
  scanf("%d/%d", &n, &d);

  tmpn = n;
  tmpd = d;

  reduce(tmpn, tmpd, &n, &d);

  printf("%d/%d\n", n, d);

  return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator) {
  int remainder;

  while (numerator > 0) {
    remainder = denominator % numerator;
    denominator = numerator;
    numerator = remainder;
  }
  *reduced_numerator /= denominator;
  *reduced_denominator /= denominator;
}
