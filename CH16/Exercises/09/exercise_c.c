/* Write a function that returns true if both colors are equal, else false. */

#include "exercise.h"
#include <stdbool.h>

bool equal_color(struct color color1, struct color color2) {
  return (color1.red == color2.red && color1.green == color2.green &&
          color1.blue == color2.blue);
}
