#include <stdio.h>

void selection_sort(int n, int m, int arr[n][m]);

int main(void) {
  int i, j, n = 5, m = 2;
  int arr[5][2] = {{0, 2}, {4, 3}, {9, 2}, {2, 1}, {5, 0}};

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  selection_sort(n, m, arr);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void selection_sort(int n, int m, int arr[n][m]) {
  int i, j, smallest, temp_r, temp_c;
  for (i = 0; i < n - 1; i++) {
    smallest = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j][0] < arr[i][0]) {
        temp_r = arr[i][0];
        temp_c = arr[i][1];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[j][0] = temp_r;
        arr[j][1] = temp_c;
      }
    }
  }
}
