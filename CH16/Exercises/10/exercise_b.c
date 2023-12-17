/* Function to compute center of r, returning a point value */

#include "exercise.h"

struct point center_r(struct rectangle r) {
  int x = r.lower_right.x - ((r.lower_right.x - r.upper_left.x) / 2);
  int y = r.lower_right.y - ((r.lower_right.y - r.upper_left.y) / 2);

  return (struct point){x, y};
}
