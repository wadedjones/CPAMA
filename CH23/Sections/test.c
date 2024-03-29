#include <float.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  // todo

  printf("%d\n", FLT_MANT_DIG);
  printf("%d\n", DBL_MANT_DIG);
  printf("%d\n", LDBL_MANT_DIG);

  char *p;
  char str[] = "Form follows function.";

  p = strchr(str, 'f');

  printf("%p\n", str);
  printf("%p\n", p);
  int idx = p - str;

  printf("%d\n", idx);

  printf("%c\n", str[idx]);

  char cal[] = " April  28,1998\0";

  char *q;
  q = strtok(cal, " \t");
  printf("%s\n", q);

  q = strtok(NULL, " \t,");
  printf("%s\n", q);

  q = strtok(NULL, " \t");
  printf("%s\n", q);
  return 0;
}
