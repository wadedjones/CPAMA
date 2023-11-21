/* (a) Write a program that reads a message, then checks whether it's a
 * palindrome (the letters in the message are the same from left to right as
 * from right to left):
 *
 * Enter a message: He lived as a devil, eh?
 * Palindrome
 *
 * Enter a message: Madam, I am Adam.
 * Not a Palindrome
 *
 * Ignore all characters that aren't letters. Use integer variables to keep
 * track of positions in the array.
 *
 * (b) Revise the program to use pointers instead of integers to keep track of
 * the positions in the array. */

#include <ctype.h>
#include <stdio.h>

#define LEN 50

int main(void) {
  // (a)
  /*
char a[LEN] = {0};
char c;
int i = 0, j;

while ((c = getchar()) != '\n') {
if (isalpha(c)) {
a[i++] = toupper(c);
}
}
j = i - 1;

for (i = 0; a[i] != 0; i++, j--) {
if (a[i] != a[j]) {
printf("Not a Palindrome\n");
return 0;
}
}
printf("Palindrome\n");
  */

  // (b)
  char a[LEN] = {0};
  char *p = a, *q;
  char c;

  while ((c = getchar()) != '\n') {
    if (isalpha(c)) {
      *p++ = toupper(c);
    }
  }
  p--;

  for (q = a; q < p; q++, p--) {
    if (*q != *p) {
      printf("Not a Palindrome\n");
      return 0;
    }
  }
  printf("Palindrome\n");

  return 0;
}
