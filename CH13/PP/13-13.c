/* Modify PP 15 from chapter 8 so that it includes the following function:
 * void encrypt(char *message, int shift);
 * The function expects message to point to a string containing the message to
 * be encrypted; shift represents the amount by which each letter in the message
 * is to be shifted.*/

#include <stdio.h>
#include <string.h>

#define MAX 50

void encrypt(char *message, int shift);

int main(void) {
  char s[MAX], c;
  int i, n;

  printf("Enter a message to be encrypted: ");

  i = 0;

  fgets(s, MAX, stdin);
  s[strcspn(s, "\n")] = 0;

  printf("Enter shift amount: ");
  scanf(" %d", &n);

  printf("Encrypted message: ");

  encrypt(s, n);

  return 0;
}

void encrypt(char *message, int shift) {
  while (*message) {
    if (*message >= 'a' && *message <= 'z')
      printf("%c", (((*message++ - 'a') + shift) % 26 + 'a'));
    else if (*message >= 'A' && *message <= 'Z')
      printf("%c", (((*message++ - 'A') + shift) % 26 + 'A'));
    else
      printf("%c", *message++);
  }
  printf("\n");
}
