/* Modify PP 14 from chapter 8 so that it stores the words in a two-dimensional
 * char array as it reads the sentence, with each row of the array storing a
 * single word. Assume that the sentence contains no more than 30 words and no
 * word is more than 20 characters long. Be sure to store a null character at
 * the end of each word so that it can be treated as a string. */

/* Write a program that reverses a sentence.
 * Have it stop at the first period/exclamation point/question mark etc */

#include <stdio.h>

#define MAX_LENGTH 30
#define MAX_WORD 20

int get_input(int length, int words, char *term, char s[length][words]);

int main(void) {
  char sentence[MAX_LENGTH][MAX_WORD];
  char c, term;
  int i = 0, j = 0;

  printf("Enter a sentence: ");

  i = get_input(MAX_LENGTH, MAX_WORD, &term, sentence);

  printf("Sentence reversed: ");

  while (i > 0) {
    printf("%s ", sentence[i--]);
  }
  printf("%s%c\n", sentence[i], term);
  return 0;
}

int get_input(int length, int words, char *term, char s[length][words]) {
  char c;
  int i = 0, j = 0;

  while ((c = getchar()) != '\n' && i < length) {
    if (c == ' ' || c == '\t') {
      s[i][j] = 0;
      i++;
      j = 0;
      continue;
    }
    if (c == '.' || c == '!' || c == '?') {
      *term = c;
      s[i][j] = 0;
      break;
    } else if (j < words) {
      s[i][j++] = c;
    }
  }
  return i;
}
