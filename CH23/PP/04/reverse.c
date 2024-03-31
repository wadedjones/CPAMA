#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int main(void) {
  char buf[BUFSIZE];
  char words[BUFSIZE][25];
  char *p;
  int i = 0;

  printf("Enter a series of words: ");
  fgets(buf, BUFSIZE, stdin);
  buf[strcspn(buf, "\n")] = 0;

  p = strtok(buf, " \n\t\0");

  while (p != NULL) {
    strcpy(words[i], p);
    i++;
    p = strtok(NULL, " \n\t\0");
  }
  i--;

  for (; i >= 0; i--) {
    if (i > 0) {
      printf("%s ", words[i]);
    } else {
      printf("%s\n", words[i]);
    }
  }

  return 0;
}
