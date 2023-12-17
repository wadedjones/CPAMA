/* Function: boolean return whether point p is within rectangle */

#include "exercise.h"
#include <stdbool.h>

bool in_rectangle(struct rectangle r, struct point p) {
  return (r.upper_left.x < p.x) && (r.upper_left.y < p.y) &&
         (r.lower_right.x > p.x) && (r.lower_right.y > p.y);
}
