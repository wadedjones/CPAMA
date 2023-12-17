/* Function to move r by x and y units */

#include "exercise.h"

struct rectangle move_r(struct rectangle r, int x, int y) {
  return (struct rectangle){{r.upper_left.x + x, r.upper_left.y + y},
                            {r.lower_right.x + x, r.lower_right.y + y}};
}
