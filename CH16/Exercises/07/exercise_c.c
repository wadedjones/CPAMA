/* Subtract the fraction f2 from f1 */

#include "exercise.h"

struct fraction sub_frac(struct fraction f1, struct fraction f2) {
  struct fraction f3 = {.numerator = (f1.numerator * f2.denominator) -
                                     (f2.numerator * f1.denominator),
                        .denominator = (f1.denominator) * (f2.denominator)};

  return reduce_frac(f3);
}
