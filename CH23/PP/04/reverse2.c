#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int main(void) {
  char buf[BUFSIZE];
  char *p[BUFSIZE];
  int i = 0;

  printf("Enter: ");
  fgets(buf, BUFSIZE, stdin);
  buf[strcspn(buf, "\n")] = 0;

  if ((p[i] = strtok(buf, " ")) == NULL) {
    return 0;
  }
  i++;

  while ((p[i] = strtok(NULL, " ")) != NULL) {
    i++;
  }

  char **q = p;

  for (i--; i >= 0; i--) {
    printf("%s ", p[i]);
  }
  printf("\n");

  return 0;
}
