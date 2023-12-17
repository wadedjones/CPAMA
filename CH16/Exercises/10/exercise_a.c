/* Function to compute area of r */

#include "exercise.h"

int rect_area(struct rectangle r) {
  int x = r.lower_right.x - r.upper_left.x;
  int y = r.lower_right.y - r.upper_left.y;

  return x * y;
}
