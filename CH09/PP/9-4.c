/* Modify PP 16 from ch 8 so that it includes the following functions:
 * 1. void read_word(int counts[26]);
 * 2. bool equal_array(int counts1[26], int counts2[26]); */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void) {
  int a[26] = {0};
  int b[26] = {0};
  int i;
  bool result;

  printf("Enter first word: ");
  read_word(a);

  printf("Enter second word: ");
  read_word(b);

  for (i = 0; i < 26; i++) {
    printf("%d", a[i]);
  }
  printf("\n");

  for (i = 0; i < 26; i++) {
    printf("%d", b[i]);
  }
  printf("\n");

  result = equal_array(a, b);

  if (result)
    printf("Anagram.\n");
  else
    printf("Not Anagram.\n");

  return 0;
}

void read_word(int counts[26]) {
  char c;
  while ((c = getchar()) != '\n') {
    if (!isalpha(c)) {
      continue;
    }
    counts[(int)(tolower(c) - 'a')]++;
  }
}

bool equal_array(int counts1[26], int counts2[26]) {
  int i;
  for (i = 0; i < 26; i++) {
    if (counts1[i] != counts2[i])
      return false;
  }
  return true;
}
