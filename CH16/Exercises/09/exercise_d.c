/*
> Returns a color structure that represents a brighter version of the color c.
The structure is identical to c, except that each member has been divided by 0.7
(with the result truncated to an int). However, there are three special cases:
(1) If all members of c are zero, the function returns a color whose members all
have the value 3. (2) If any member of c is grater than 0 but less than 3, it is
replaced by 3 before the division by 0.7. (3) If dividing by 0.7 causes a member
to exceed 255, it is reduced to 255.
*/

#include "exercise.h"

struct color brighter(struct color c) {
  if (c.red == 0 && c.green == 0 && c.blue == 0)
    return (struct color){3, 3, 3};

  return (struct color){
      .red = c.red < 3           ? 3 / 0.7
             : c.red / 0.7 > 255 ? 255
                                 : c.red / 0.7,
      .green = c.green < 3           ? 3 / 0.7
               : c.green / 0.7 > 255 ? 255
                                     : c.green / 0.7,
      .blue = c.blue < 3           ? 3 / 0.7
              : c.blue / 0.7 > 255 ? 255
                                   : c.blue / 0.7,
  };
}
