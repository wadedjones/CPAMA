#include "line.h"
#include <stdio.h>
#include <string.h>

// char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(char line[MAX_LINE_LEN + 1]) {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word, char line[MAX_LINE_LEN + 1]) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(FILE *fp, char line[MAX_LINE_LEN + 1]) {
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      fputc(line[i], fp);
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        fputc(' ', fp);
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  fputc('\n', fp);
}

void flush_line(FILE *fp, char line[MAX_LINE_LEN + 1]) {
  if (line_len > 0)
    fputs(line, fp);
}
