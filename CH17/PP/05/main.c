#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int read_line(char *str, int n);
int compare_words(const void *p, const void *q);

int main(void) {
  char **str = malloc(sizeof(char *) * MAX_WORD_LENGTH);
  char *word = NULL;
  int n, num_words = 0, i = 0;

  for (;;) {
    word = malloc(sizeof(char *) + MAX_WORD_LENGTH);
    printf("Enter a word: ");
    n = read_line(word, MAX_WORD_LENGTH);
    if (!n)
      break;
    *(str + i) = word;
    i++;
    num_words++;
    free(word);
  }
  qsort(str, num_words, sizeof(char *), compare_words);

  for (i = 0; i < num_words; i++) {
    printf("Word %d: %s\n", i + 1, *(str + i));
  }
  return 0;
}

int read_line(char str[], int n) {
  int c, i = 0;

  while ((c = getchar()) != '\n' && i < n) {
    str[i++] = c;
  }
  str[i] = '\0';
  return i;
}

int compare_words(const void *p, const void *q) {
  return strcmp(*(char **)p, *(char **)q);
}
