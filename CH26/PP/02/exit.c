#include <stdio.h>
#include <stdlib.h>

void print1(void);
void print2(void);

int main(void) {
  atexit(print2);
  atexit(print1);

  return 0;
}

void print1(void) { printf("That's all, "); }

void print2(void) { printf("folks!\n"); }
