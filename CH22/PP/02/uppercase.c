#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Usage: uppercase <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int ch;

  while ((ch = getc(fp)) != EOF) {
    putc(toupper(ch), stdout);
  }

  fclose(fp);

  return 0;
}
