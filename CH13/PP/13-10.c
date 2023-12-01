/* Modify PP 11 from chapter 7 so that it includes the following function:
 * void reverse_name(char *name);
 * The function expects name to point to a string containing a first name
 * followed by a last name. It modifies the string so that the last name comes
 * first, followed by a comma, a space, the first initial, and a period. The
 * original string may contain extra spaces before the first name, between the
 * first and last names, and after the last name.*/

/* Write a program where user enters name "Wade Jones" and outputs "Jones, W."
 */

#include <stdio.h>
#include <string.h>

#define MAX 25

void reverse_name(char *name);

int main(void) {
  char name[MAX];

  printf("Enter your first and last name: ");
  fgets(name, sizeof(name), stdin);

  reverse_name(name);

  return 0;
}

void reverse_name(char *name) {
  char *p = name, initial;

  while (*p == ' ')
    p++;

  initial = *p++;

  while (*p && *p++ != ' ')
    ;

  while (*p && *p != '\n')
    putchar(*p++);
  printf(", %c.\n", initial);
}
