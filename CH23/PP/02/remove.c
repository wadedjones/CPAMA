#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  char ch;
  bool ch_seen = false;

  while ((ch = getchar()) != EOF) {
    if (ch_seen) {
      putchar(ch);
    } else if (!isspace(ch)) {
      ch_seen = true;
      putchar(ch);
    }
    if (ch == '\n') {
      ch_seen = false;
    }
  }

  return 0;
}
