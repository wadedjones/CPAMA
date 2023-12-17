/* Function to scale s by c */

#include "exercise.h"

struct shape scale_shape(struct shape s, double c) {
  struct shape new_shape = s;

  if (s.shape_kind == RECTANGLE) {
    s.u.rectangle.height *= c;
    s.u.rectangle.width *= c;
  } else {
    s.u.circle.radius *= c;
  }
  return new_shape;
}
