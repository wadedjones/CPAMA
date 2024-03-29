#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* (a) strdup(s) */
char *my_strdup(const char *s) {
  char *p = malloc(sizeof(s));
  memcpy(p, s, (int)sizeof(s));

  return p;
}

/* (b) stricmp(s1, s2) */
int my_stricmp(const char *s1, const char *s2) {
  int result = 0;
  while (result == 0 && *s1 && *s2) {
    result += (tolower(*s1)) - (tolower(*s2));
    s1++;
    s2++;
  }
  return result;
}

/* (c) strlwr(s) */
char *my_strlwr(char *s) {
  while (*s) {
    *s = tolower(*s);
    s++;
  }
  return s;
}

/* (d) strrev(s) */
char *my_strrev(char *s) {
  char *p = s + strlen(s) - 1;
  char *temp;

  while (s < p) {
    *temp = *s;
    *s = *p;
    *p = *temp;
    s++;
    p--;
  }

  return s;
}

/* (e) strset(s, ch) */
char *my_strset(char *s, const char ch) {
  while (*s) {
    *s = ch;
    s++;
  }
  return s;
}
