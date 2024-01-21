/* function to read one char at a time. */
#include <stdio.h>

#define N 50

int read_line(char str[], int n);

int main(void) {
  char str[N];

  printf("Enter a sentence: ");

  read_line(str, N);

  printf("%s\n", str);

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';
  return i;
}
