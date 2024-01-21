/* Idioms and styles when writing c functions, particularly for strings */
/* Writing out standard string functions */

// (1.a) Searching for the end of a string: strlen

#include <stddef.h>
size_t a_strlen(const char *s) {
  size_t n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

// (1.b)
// Initialize n when declared
size_t b_strlen(const char *s) {
  size_t n = 0;

  for (; *s != '\0'; s++)
    n++;
  return n;
}

// (1.c)
// *s != '\0' is the same as *s != 0, which is the same as *s;
size_t c_strlen(const char *s) {
  size_t n = 0;
  for (; *s; s++)
    n++;
  return n;
}

// (1.d)
// I'ts possible to increment and test *s in the same expression;
size_t d_strlen(const char *s) {
  size_t n = 0;
  for (; *s++;)
    n++;
  return n;
}

// (1.e)
// Replacing for with a while;
size_t e_strlen(const char *s) {
  size_t n = 0;

  while (*s++)
    n++;
  return n;
}

// (1.f)
// Although we've condensed strlen quite a bit, it doesn't run faster;
// Here is a version that does run faster;
// The increase in speed comes from not having to increment n inside the while
// loop;
size_t f_strlen(const char *s) {
  const char *p = s;

  while (*s)
    s++;
  return s - p;
}

/*
 * while (*s)
 * 	s++;
 *
 * while (*s++)
 *	;
 *
 * Both search for the null character at the end of the string. But the first
 *version has the pointer pointing to the null char at the end of the loop. The
 *second version has the pointer pointing just past the null char.*/
