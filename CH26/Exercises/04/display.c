#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

void display(size_t n, ...) {
  va_list ap;

  va_start(ap, n);

  for (int i = 0; i < n; i++) {
    char *s = va_arg(ap, char *);
    while (*s) {
      putchar(*s);
      s++;
    }
    if (i < n - 1) {
      putchar(' ');
    }
  }
  va_end(ap);
}
