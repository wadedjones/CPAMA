/* Modify PP 14 from chapter 8 so that it uses a pointer instead of an integer
 * to keep track of the current position in the array that contains the
 * sentence. */

/* Write a program that reverses a sentence.
 * Have it stop at the first period/exclamation point/question mark etc */

#include <stdio.h>

#define MAX_S 100

int main(void) {
  char s[MAX_S] = {0};
  char *p, *q;
  char c, terminator;
  p = s;

  printf("Enter a sentence: ");
  while ((c = getchar()) != '\n') {
    if (c == '.' || c == '?' || c == '!')
      break;
    *p++ = c;
  }
  terminator = c;

  while (p > s) {
    while (*(--p) != ' ' && p != s)
      ;
    q = p == s ? s : p + 1;
    while (*q != ' ' && *q != 0) {
      putchar(*(q++));
    }
    if (p > s) {
      putchar(' ');
    }
  }

  printf("%c\n", terminator);
  return 0;
}
