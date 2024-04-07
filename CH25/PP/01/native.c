#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *locale;
  char *C_locale;

  locale = setlocale(LC_ALL, NULL);

  if (locale == NULL) {
    fprintf(stderr, "local info is not available\n");
    exit(EXIT_FAILURE);
  }

  C_locale = malloc(strlen(locale) + 1);

  if (C_locale == NULL) {
    fprintf(stderr, "cannot allocate C_locale\n");
    exit(EXIT_FAILURE);
  }

  strcpy(C_locale, locale);

  locale = setlocale(LC_ALL, "");

  if (locale == NULL) {
    fprintf(stderr, "local info is not available\n");
    exit(EXIT_FAILURE);
  }

  if (strcmp(locale, C_locale) == 0) {
    printf("Native locale is the same as \"C\" locale.\n");
  } else {
    printf("Native locale is not the same as \"C\" locale.\n");
  }

  printf("locale: %s\n", locale);
  printf("C_locale: %s\n", C_locale);

  return 0;
}
