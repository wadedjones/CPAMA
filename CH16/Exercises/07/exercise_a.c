/* Reduce the fraction f to lowest terms */
#include "exercise.h"

int gcd(int n, int d) { return d == 0 ? n : gcd(d, n % d); }

struct fraction reduce_frac(struct fraction f) {
  int n = gcd(f.numerator, f.denominator);
  return (struct fraction){f.numerator / n, f.denominator / n};
}
