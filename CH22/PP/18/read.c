#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000
#define BUFSIZE 100

int compare_int(const void *a, const void *b);

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: read <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char buf[BUFSIZE];
  int nums[MAX_NUMS] = {0};
  char ch;
  int i = 0;
  int mult = 0;
  int total = 0;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isdigit(ch) && ch != ' ' && ch != '\n') {
      if (mult == 0) {
        i = total;
        nums[i] = atoi(&ch);
        mult = 10;
        total++;
      } else {
        nums[i] *= mult;
        nums[i] += atoi(&ch);
      }
    } else {
      mult = 0;
    }
  }

  qsort(nums, total, sizeof(nums[0]), compare_int);

  int low = nums[0];
  int high = nums[total - 1];
  int median;

  if (total % 2 == 0) {
    median = (nums[total / 2] + nums[(total / 2) - 1]) / 2;
  } else {
    median = nums[total / 2];
  }

  printf("Low: %d\n", low);
  printf("Median: %d\n", median);
  printf("High: %d\n", high);

  return 0;
}

int compare_int(const void *a, const void *b) {
  return *((int *)a) - *((int *)b);
}
