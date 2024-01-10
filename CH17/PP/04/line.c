#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60

struct node {
  struct node *next;
  char word[];
};

// char line[MAX_LINE_LEN + 1];
struct node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
  struct node *temp;

  while (line != NULL) {
    temp = line;
    line = line->next;
    free(temp);
  }
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  struct node *new_word, **p = &line;
  new_word = malloc(sizeof(struct node) + strlen(word) + 1);

  if (new_word == NULL) {
    printf("New word malloc failed, out of memory.\n");
    exit(EXIT_FAILURE);
  }

  strcpy(new_word->word, word);
  new_word->next = NULL;

  while (*p != NULL) {
    p = &(*p)->next;
  }
  *p = new_word;
  line_len += strlen(word);

  if (num_words > 0) {
    line_len++;
  }
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
  int extra_spaces, spaces_to_insert, i, count = 0;
  struct node *word = line;
  extra_spaces = space_remaining();

  while (count < line_len && word != NULL) {
    printf("%s", word->word);
    if (num_words > 1) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (i = 1; i <= spaces_to_insert + 1; i++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
    }
    count += strlen(word->word) + 1;
    num_words--;
    word = word->next;
  }
  putchar('\n');
}

void flush_line(void) {
  int i;
  struct node *word = line;
  if (line_len > 0) {
    for (i = 0; word != NULL; i++, word = word->next) {
      if (i > 0 && word->next != NULL) {
        putchar(' ');
      }
      printf("%s", word->word);
    }
  }
  printf("\n");
  clear_line();
}
