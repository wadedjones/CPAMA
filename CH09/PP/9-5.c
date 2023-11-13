/* Modify PP 17 from ch 8 so that it includes the following functions:
 * 1. void create_magic_square(int n, char magic_square[n][n]);
 * 2. void print_magic_square(int n, char magic_square[n][n]);*/

#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void) {
  int i, j, n, row, col;
  int counter = 1;

  printf("This program creates a magic square.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  int a[n][n];

  create_magic_square(n, a);

  print_magic_square(n, a);

  return 0;
}

void create_magic_square(int n, int magic_square[n][n]) {
  int i, j, row, col;
  int counter = 1;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      magic_square[i][j] = 0;
    }
  }

  magic_square[0][(int)n / 2] = counter;
  row = 0;
  col = ((int)n / 2);

  for (i = 0; i < n * n - 1; i++) {
    if (row - 1 < 0 && col + 1 > n - 1) {
      if (magic_square[n - 1][0] == 0) {
        row = n - 1;
        col = 0;
        magic_square[row][col] = ++counter;
      } else {
        row++;
        magic_square[row][col] = ++counter;
      }
    } else if (row - 1 < 0) {
      if (magic_square[n - 1][col + 1] == 0) {
        row = n - 1;
        magic_square[row][++col] = ++counter;
      } else {
        row++;
        magic_square[row][col] = ++counter;
      }
    } else if (col + 1 > n - 1) {
      if (magic_square[row - 1][0] == 0) {
        col = 0;
        magic_square[--row][col] = ++counter;
      } else {
        row < n - 1 ? ++row : 0;
        magic_square[row][col] = ++counter;
      }
    } else {
      if (magic_square[row - 1][col + 1] == 0) {
        --row;
        ++col;
        magic_square[row][col] = ++counter;
      } else {
        row < n - 1 ? ++row : 0;
        magic_square[row][col] = ++counter;
      }
    }
  }
}

void print_magic_square(int n, int magic_square[n][n]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d ", magic_square[i][j]);
    }
    printf("\n");
  }
}
