/* (a) write a program that reads a message, then prints the reversal of the
 * message: Enter a message: Don't get mad, get even. Reverasal is: .neve teg
 * ,dam teg t'noD
 *
 * Hint: Read the message one character at a time (using getchar) and store the
 * characters in an array. Stop reading when the array is full or the character
 * read is '\n'.
 *
 * (b) Revise the program to use a pointer instead of an integer to keep track
 * of the current position in the array.*/

#include <stdio.h>

#define LEN 100

int main(void) {
  char a[LEN] = {0};
  char *p = a;
  char c;
  int i = 0;

  printf("Enter a message: ");

  // (a)
  /*
        while ((c = getchar()) != '\n') {
                a[i++] = c;
        }
  */
  /*
    printf("Reversal is: ");
    for (i = LEN; i >= 0; i--) {
      printf("%c", a[i]);
    }
  */

  // (b)
  while ((c = getchar()) != '\n') {
    *p++ = c;
  }

  printf("Reversal is: ");
  for (; p >= &a[0]; p--) {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
