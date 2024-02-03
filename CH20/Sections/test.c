#include <stdio.h>

typedef unsigned char BYTE;

int main(void) {
  printf("Size of unsigned int: %ld\n", sizeof(unsigned int));
  printf("Size of char *: %ld\n", sizeof(char *));
  printf("Size of BYTE: %ld\n", sizeof(BYTE));

  return 0;
}
