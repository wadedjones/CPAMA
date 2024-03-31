#include <stdio.h>
#include <string.h>

int main(void) {
  char ch;
  int count = 0;

  while ((ch = getchar()) != EOF) {
    if (strchr(".?!", ch) != NULL) {
      count++;
    }
  }

  printf("Count: %d\n", count);

  return 0;
}
