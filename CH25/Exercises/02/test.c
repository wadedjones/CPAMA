#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int mbcheck(const char *s);

int main(void) {
  setlocale(LC_ALL, "ja_JP.SJIS");

  char *a = "\x05\x87\x80\x36\xed\xaa";
  char *b = "\x20\xe4\x50\x88\x3f";
  char *c = "\xde\xad\xbe\xef";
  char *d = "\x8a\x60\x92\x74\x41";

  int aa = mbcheck(a);
  int bb = mbcheck(b);
  int cc = mbcheck(c);
  int dd = mbcheck(d);

  printf("a: %d, b: %d\nc: %d, d: %d\n", aa, bb, cc, dd);

  return 0;
}

int mbcheck(const char *s) {
  int n;

  for (mblen(NULL, 0);; s += n) {
    if ((n = mblen(s, MB_CUR_MAX)) <= 0) {
      return n;
    }
  }
}
