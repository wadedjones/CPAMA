/* Write a program named reverse.c that echoes its command-line arguments in
 * reverse order. Running the program by typing: reverse (13-3) void and null
 * should produce the following output:
 * null and void.*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int i = argc - 1;

  for (; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");

  return 0;
}
