#include <stdio.h>
#include <stdlib.h>

void call_rand(void);

int main(void) {
  call_rand();
  return 0;
}

void call_rand(void) {
  for (int i = 0; i < 1000; i++) {
    printf("%d\n", rand() & 1);
  }
}
