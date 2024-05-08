#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_1 1000
#define NUM_2 10000
#define NUM_3 100000

void clock_func(int num, int arr[num]);

int main(void) {
  int num1[NUM_1];
  int num2[NUM_2];
  int num3[NUM_3];

  for (int i = NUM_1, j = 0; i > 0; i--, j++) {
    num1[j] = i;
  }
  for (int i = NUM_2, j = 0; i > 0; i--, j++) {
    num2[j] = i;
  }
  for (int i = NUM_3, j = 0; i > 0; i--, j++) {
    num3[j] = i;
  }

  clock_func(NUM_1, num1);
  clock_func(NUM_2, num2);
  clock_func(NUM_3, num3);

  return 0;
}

int compare_nums(const void *n1, const void *n2) {
  return *((int *)n1) - *((int *)n2);
}

void clock_func(int num, int arr[num]) {
  clock_t start_clock = clock();
  qsort(arr, num, sizeof(arr[0]), compare_nums);
  printf("Processor time used: %g sec.\n",
         (clock() - start_clock) / (double)CLOCKS_PER_SEC);
}
