#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...) {
  va_list ap;
  size_t len = 0;

  va_start(ap, first);

  char *ptr;
  while ((ptr = va_arg(ap, char *)) != ((char *)NULL)) {
    len += strlen(ptr);
  }

  va_end(ap);
  va_start(ap, first);

  char *result;
  if ((result = malloc(len)) == NULL) {
    va_end(ap);
    return NULL;
  }

  while ((ptr = va_arg(ap, char *)) != ((char *)NULL)) {
    strcat(result, ptr);
  }

  va_end(ap);

  return result;
}
