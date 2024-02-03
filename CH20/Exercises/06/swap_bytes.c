#include <stdio.h>

unsigned short swap_bytes(unsigned short i);
unsigned short swap_bytes2(unsigned short i);

int main(void) {
  unsigned short i, j;

  printf("Enter a hexadecimal number (up to four digits): ");
  scanf("%hx", &i);

  j = swap_bytes2(i);

  printf("Number with bytes swapped: %hx\n", j);

  return 0;
}

unsigned short swap_bytes(unsigned short i) {
  unsigned short j, k;
  j = i << 8;
  k = i >> 8;
  return j |= k;
}

unsigned short swap_bytes2(unsigned short i) { return (i << 8) | (i >> 8); }
