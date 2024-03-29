#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int count_word(const char *filename);

int main(int argc, char **argv) {

  if (argc < 2) {
    fprintf(stderr, "usage: countword <filename>\n");
    exit(EXIT_FAILURE);
  }

  const char *filename = argv[1];

  int word_count = count_word(filename);

  printf("Word Count: %d\n", word_count);

  return 0;
}

int count_word(const char *filename) {
  FILE *fp;
  int ch, count = 0;
  bool in_word = false;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isspace(ch)) {
      in_word = false;
    } else if (!in_word) {
      in_word = true;
      count++;
    }
  }

  fclose(fp);

  return count;
}
