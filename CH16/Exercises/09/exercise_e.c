/* Identical to exercise d, but each member is multiplied by 0.7 */

#include "exercise.h"

struct color darker(struct color c) {
  if (c.red == 0 && c.green == 0 && c.blue == 0)
    return (struct color){3, 3, 3};

  return (struct color){
      .red = c.red < 3           ? 3 * 0.7
             : c.red * 0.7 > 255 ? 255
                                 : c.red * 0.7,
      .green = c.green < 3           ? 3 * 0.7
               : c.green * 0.7 > 255 ? 255
                                     : c.green * 0.7,
      .blue = c.blue < 3           ? 3 * 0.7
              : c.blue * 0.7 > 255 ? 255
                                   : c.blue * 0.7,
  };
}
