/* Idioms and styles when writing c functions, particularly for strings */
/* Writing out standard string functions */

// (1.a) Concatenate a string: strcat
char *a_strcat(char *s1, const char *s2) {
  char *p = s1;

  while (*p != '\0')
    p++;
  while (*s2 != '\0') {
    *p = *s2;
    p++;
    s2++;
  }

  *p = '\0';
  return s1;
}

// (1.b) Condensed version
char *b_strcat(char *s1, const char *s2) {
  char *p = s1;

  while (*p)
    p++;
  while ((*p++ = *s2++))
    ;
  return s1;
}

#include <stdio.h>

int main(void) {
  char s1[7] = "abc";
  char s2[7] = "def";

  b_strcat(s1, s2);

  printf("%s\n", s1);

  return 0;
}
