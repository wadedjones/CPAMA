#include "word.h"
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20

int read_char(void) {
  int ch = getchar();

  return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

int read_word(char *word, int len) {
  int ch, pos = 0;

  while ((ch = read_char()) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }
  word[pos] = '\0';
  if (strlen(word) > MAX_WORD_LEN)
    word[MAX_WORD_LEN] = '*';
  return pos;
}
