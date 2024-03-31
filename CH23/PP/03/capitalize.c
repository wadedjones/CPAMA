#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  char ch;
  bool is_space = true;

  while ((ch = getchar()) != EOF) {
    if (isspace(ch)) {
      is_space = true;
      putchar(ch);
    } else if (is_space) {
      putchar(toupper(ch));
      is_space = false;
    } else {
      putchar(ch);
    }
  }

  return 0;
}
