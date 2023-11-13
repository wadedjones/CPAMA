/* Finds the largest and smallest elements in an array */

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void) {
  int b[N], i, big, small;

  return 0;
}

void max_min(int a[], int n, int *max, int *min) {
  int i;

  *max = *min = a[0];

  for (i = 1; i < n; i++) {
    if (a[i] > *max) {
      *max = a[i];
    } else if (a[i] < *min) {
      *min = a[i];
    }
  }
}
