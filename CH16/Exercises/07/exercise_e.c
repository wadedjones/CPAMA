/* Divide the fraction f1 by f2 */

#include "exercise.h"

struct fraction div_frac(struct fraction f1, struct fraction f2) {
  struct fraction f3 = {.numerator = f1.numerator * f2.denominator,
                        .denominator = f1.denominator * f2.numerator};

  return reduce_frac(f3);
}
