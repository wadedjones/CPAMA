#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 1024

int main(void) {
  char buf[BUFSIZE];
  int i;

  printf("Enter a sentence: ");
  fgets(buf, BUFSIZE, stdin);

  for (i = 0; buf[i] != 0; i++) {
    if (buf[i] != '\n' && iscntrl(buf[i])) {
      printf("?");
    } else {
      printf("%c", buf[i]);
    }
  }

  return 0;
}
