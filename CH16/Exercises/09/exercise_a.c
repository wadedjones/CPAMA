/* Write a function that returns a color structure */

#include "exercise.h"

struct color make_color(int red, int green, int blue) {
  return (struct color){.red = red < 0     ? 0
                               : red > 255 ? 255
                                           : red,
                        .green = green < 0     ? 0
                                 : green > 255 ? 255
                                               : green,
                        .blue = blue < 0     ? 0
                                : blue > 255 ? 255
                                             : blue};
}
