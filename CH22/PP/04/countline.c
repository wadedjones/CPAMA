#include <stdio.h>
#include <stdlib.h>

int count_line(const char *filename);

int main(int argc, char **argv) {

  if (argc < 2) {
    fprintf(stderr, "usage: countline <filename>\n");
    exit(EXIT_FAILURE);
  }

  const char *filename = argv[1];

  int line_count = count_line(filename);

  printf("Line Count: %d\n", line_count);

  return 0;
}

int count_line(const char *filename) {
  FILE *fp;
  int count = 0;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  char ch;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      count++;
    }
  }

  fclose(fp);

  return count;
}
