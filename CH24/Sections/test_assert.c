#include <stdio.h>

#define NDEBUG
#include <assert.h>

int main(void) {
  int a[10];

  int i = -2;
  for (; i < 10; i++) {
    assert(0 <= i && i < 10);
    a[i] = 666;
  }

  printf("%d\n", a[0]);

  return 0;
}
