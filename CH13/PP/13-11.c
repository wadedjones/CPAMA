/* Modify PP 13 from chapter 7 so that it includes the following function:
 * double compute_average_word_length(const char *sentence);
 * The function returns the average length of the words in the string pointed to
 * by sentence.*/

/* Write a program that calculates the average word length for a sentence */

#include <stdio.h>
#include <string.h>

#define MAX 100

double compute_average_word_length(const char *sentence);

int main(void) {
  char sentence[MAX];
  double average;

  printf("Enter a sentence: ");

  fgets(sentence, sizeof(sentence), stdin);
  sentence[strcspn(sentence, "\n")] = 0;

  average = compute_average_word_length(sentence);

  printf("Average word length: %.2lf\n", average);

  return 0;
}

double compute_average_word_length(const char *sentence) {
  const char *p = sentence;
  int i = 0, j = 1;

  while (*p++) {
    if (*p != ' ')
      i++;
    else
      j++;
  }

  return (float)i / (float)j;
}
