/* Modify PP 1 from chapter 12 so that it includes the following function:
 * void reverse(char *message);
 * The function reverses the string pointed to by message. Hint: Use two
 * pointers, one initially pointing to the first character of the string and the
 * other initially pointing to the last character. Have the function reverse
 * these characters and then move the pointers toward each other, repeating the
 * process until the pointers meet.*/

#include <stdio.h>
#include <string.h>

#define LEN 100

void reverse(char *message);

int main(void) {
  char message[LEN];

  printf("Enter a message: ");

  fgets(message, LEN, stdin);
  message[strcspn(message, "\n")] = 0;

  reverse(message);

  printf("Message reversed: %s\n", message);

  return 0;
}

void reverse(char *message) {
  char *p = message;
  char *q = message + strlen(message) - 1;
  char tmp;

  while (p != q) {
    if (p > q)
      break;
    tmp = *p;
    *p++ = *q;
    *q-- = tmp;
  }
}
