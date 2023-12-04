/* Modify PP 2 from chapter 12 so that it includes the following function:
 * bool is_palindrome(const char *message);
 * The function returns true if the string pointed to by message is a
 * palindrome.*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LEN 50

bool is_palindrome(const char *message);

int main(void) {
  char message[LEN];
  bool result;

  printf("Enter a message: ");

  fgets(message, LEN, stdin);
  message[strcspn(message, "\n")] = 0;

  result = is_palindrome(message);

  printf("%s\n", result ? "Palindrome" : "Not Palindrome");

  return 0;
}

bool is_palindrome(const char *message) {
  const char *p = message;
  const char *q = message + strlen(message) - 1;

  while (*p) {
    if (!isalpha(*p))
      p++;
    if (!isalpha(*q))
      q--;
    if (isalpha(*p) && isalpha(*q) && toupper(*p++) != toupper(*q--))
      return false;
  }

  return true;
}
