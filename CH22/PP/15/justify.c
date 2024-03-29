/* Formats a file of text */

#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LEN 20

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stderr, "usage: justify <filename1> <filename2>\n");
    exit(EXIT_FAILURE);
  }

  FILE *in_fp, *out_fp;

  if ((in_fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((out_fp = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "cannot save file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE_LEN + 1];
  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line(line);
  for (;;) {
    word_len = read_word(in_fp, word, MAX_WORD_LEN + 1);
    if (word_len == 0) {
      flush_line(out_fp, line);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(out_fp, line);
      clear_line(line);
    }
    add_word(word, line);
  }
}
