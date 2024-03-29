#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 10000

int compare_nums(const void *a, const void *b);

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: read <filename>");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  int nums[BUFSIZE];
  int total, high, median, low;

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  total = 0;

  while (!feof(fp)) {
    fscanf(fp, " %d", &nums[total++]);
  }

  total--;

  qsort(nums, total, sizeof(int), compare_nums);

  if (total % 2 == 0) {
    median = (nums[(total - 1) / 2] + nums[((total - 1) / 2) + 1]) / 2;
  } else {
    median = nums[(total - 1) / 2];
  }

  printf("High: %d\nMedian: %d\nLow: %d\n", nums[total - 1], median, nums[0]);

  return 0;
}

int compare_nums(const void *a, const void *b) {
  return *((int *)a) - *((int *)b);
}
