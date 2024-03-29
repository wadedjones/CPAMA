#include <stdio.h>
#include <stdlib.h>

int count_char(const char *filename);

int main(int argc, char **argv) {

  if (argc < 2) {
    fprintf(stderr, "usage: countchar <filename>\n");
    exit(EXIT_FAILURE);
  }

  const char *filename = argv[1];

  int char_count = count_char(filename);

  printf("Character Count: %d\n", char_count);

  return 0;
}

int count_char(const char *filename) {
  FILE *fp;
  int count = 0;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (fgetc(fp) != EOF) {
    count++;
  }

  fclose(fp);

  return count;
}
