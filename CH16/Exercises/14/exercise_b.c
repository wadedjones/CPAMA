/* Function to move s by x and y units */

#include "exercise.h"

struct shape move_shape(struct shape s, int x, int y) {
  struct shape new_shape = s;

  new_shape.center.x += x;
  new_shape.center.y += y;

  return new_shape;
}
