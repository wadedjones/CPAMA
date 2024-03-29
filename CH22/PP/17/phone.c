#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 20

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: phone <file>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char buf[BUFSIZE];
  char area[4], prefix[4], line[5];
  int ch;
  int i = 0;

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isdigit(ch) && i < 3) {
      area[i++] = ch;
    } else if (isdigit(ch) && i < 6) {
      prefix[(i++) - 3] = ch;
    } else if (isdigit(ch) && i < 10) {
      line[(i++) - 6] = ch;
    } else if (i == 10) {
      area[3] = '\0';
      prefix[3] = '\0';
      line[4] = '\0';

      printf("(%s) %s-%s\n", area, prefix, line);
      i = 0;
    }
  }

  fclose(fp);

  return 0;
}
