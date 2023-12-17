/* Function to compute area of s */

#include "exercise.h"

double area_shape(struct shape s) {
  if (s.shape_kind == RECTANGLE) {
    return (s.u.rectangle.width * s.u.rectangle.height);
  }
  return (3.14 * s.u.circle.radius * s.u.circle.radius);
}
