/* Write functions that return the following values. (Assume that a and n are
 * parameters, where a is an array of int values and n is the length of a) */

// (a) the largest element of a.
// (b) the average of all elements in a.
// (c) the number of positive elements in a.

#include <stdio.h>

// (a)
int largest(int n, int a[n]) {
  int i, tmp;
  tmp = a[0];
  for (i = 0; i < n; i++) {
    if (a[i] > tmp) {
      tmp = a[i];
    }
  }
  return tmp;
}

// (b)
float average(int n, int a[n]) {
  int total = 0, i;
  for (i = 0; i < n; i++) {
    total += a[i];
  }
  return (float)total / n;
}

// (c)
int pos_e(int n, int a[n]) {
  int i, total = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > 0) {
      total++;
    }
  }
  return total;
}

int main(void) {
  int a[] = {1, 3, -2, 6, -5, 9, 8};
  int n = 7;

  printf("largest: %d\n", largest(n, a));
  printf("average: %.2f\n", average(n, a));
  printf("positive: %d\n", pos_e(n, a));

  return 0;
}
