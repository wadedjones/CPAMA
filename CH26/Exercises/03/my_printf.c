#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *str, ...) {
  va_list ap;
  int count = 0;

  va_start(ap, str);

  while (*str) {
    if (*str == '%') {
      str++;
      if (*str == 'd') {
        int i = va_arg(ap, int);
        if (i < 0) {
          i = -i;
          putchar('-');
        }

        int temp = i;
        int pow = 1;
        while (temp > 9) {
          temp /= 10;
          pow *= 10;
        }
        do {
          temp = i / pow;
          putchar(temp + '0');
          i -= temp * pow;
          pow /= 10;
        } while (i > 0);
        str++;
      } else if (*str == 's') {
        char *s = va_arg(ap, char *);
        while (*s) {
          putchar(*s++);
        }
        str++;
      }
    }
    putchar(*str++);
  }

  va_end(ap);
  return count;
}
