#include <stdarg.h>

char *max_pair(int num_pairs, ...) {
  va_list ap;
  int largest = 0;
  int current = 0;

  va_start(ap, num_pairs);

  char *ptr;

  for (int i = 0; i < num_pairs; i++) {
    current = va_arg(ap, int);
    if (current > largest) {
      largest = current;
    }
    ptr = va_arg(ap, char *);
  }
  va_end(ap);
  va_start(ap, num_pairs);

  for (int i = 0; i < num_pairs; i++) {
    current = va_arg(ap, int);
    if (current == largest) {
      ptr = va_arg(ap, char *);
      break;
    }
    ptr = va_arg(ap, char *);
  }

  va_end(ap);
  return ptr;
}
