/* Modify PP 16 from chapter 8 so that it includes the following function:
 * bool are_anagrams(const char *word1, const char *word2);
 * The function returns true if the strings pointed to by word1 and word2 are
 * anagrams.*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 25

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
  char word1[MAX];
  char word2[MAX];
  bool result;

  printf("Enter first word: ");

  fgets(word1, MAX, stdin);
  word1[strcspn(word1, "\n")] = 0;

  printf("Enter second word: ");

  fgets(word2, MAX, stdin);
  word2[strcspn(word2, "\n")] = 0;

  result = are_anagrams(word1, word2);

  printf("%s", result ? "Anagrams\n" : "Not anagrams\n");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
  const char *p = word1;
  const char *q = word2;
  q += strlen(word2) - 1;

  while (*p) {
    if (*p++ != *q--)
      return false;
  }

  return true;
}
