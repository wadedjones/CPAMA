/* Modify PP 10 from chapter 7 so that it includes the following function:
 * int compute_vowel_count(const char *sentence);
 * The function returns the number of vowels in the string pointed to by the
 * sentence parameter.
 * */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

int read_line(char *input, int n);
int compute_vowel_count(const char *sentence);

int main(void) {
  int count;
  char input[MAX];

  printf("Enter a sentence: ");
  read_line(input, MAX);

  count = compute_vowel_count(input);

  printf("Your sentence contains %d vowels.\n", count);

  return 0;
}

int compute_vowel_count(const char *sentence) {
  int count = 0;

  while (*sentence++) {

    if (toupper(*sentence) == 'A' || toupper(*sentence) == 'E' ||
        toupper(*sentence) == 'I' || toupper(*sentence) == 'O' ||
        toupper(*sentence) == 'U') {
      count++;
    }
  }

  return count;
}

int read_line(char *input, int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n) {
      *input++ = ch;
      i++;
    }
  }
  *input = '\0';
  return i;
}
