#include <stdio.h>

union {
  float value;
  struct {
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } field;
} f;

int main(void) {
  f.field.fraction = 0;
  f.field.exponent = 128;
  f.field.sign = 1;

  printf("%.1f\n", f.value);

  return 0;
}
