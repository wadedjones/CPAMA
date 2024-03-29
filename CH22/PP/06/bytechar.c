#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: bytechar <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  const char *filename = argv[1];

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s", filename);
  }

  char buf[10];
  int offset, n, i;

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  for (offset = 0;; offset += 10) {
    n = fread(buf, 1, 10, fp);
    if (n == 0) {
      break;
    }

    printf("%6d  ", offset);
    for (i = 0; i < n; i++) {
      printf("%.2X ", buf[i]);
    }
    for (; i < 10; i++) {
      printf("   ");
    }
    printf(" ");
    for (i = 0; i < n; i++) {
      if (!isprint(buf[i])) {
        buf[i] = '.';
      }
      printf("%c", buf[i]);
    }
    printf("\n");
  }

  return 0;
}
