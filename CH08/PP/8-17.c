/* Write a program that prints an n x n "magic" square */

#include <stdio.h>

int main(void)
{
	int i, j, n, row, col;
	int counter = 1;

	printf("This program creates a magic square.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	int a[n][n];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	a[0][(int) n / 2] = counter;
	row = 0;
	col = ((int) n / 2);

	for (i = 0; i < n * n; i++) {
		if (row - 1 < 0 && col + 1 > n - 1) {
			if (a[n - 1][0] == 0) {
				row = n - 1;
				col = 0;
				a[row][col] = ++counter;
			} else {
				row++;
				a[row][col] = ++counter;
			}
		} else if (row - 1 < 0) {
			if (a[n - 1][col + 1] == 0) {
				row = n - 1;
				a[row][++col] = ++counter;
			} else {
				row++;
				a[row][col] = ++counter;
			}
		} else if (col + 1 > n - 1) {
			if (a[row - 1][0] == 0) {
				col = 0;
				a[--row][col] = ++counter;
			} else {
				row < n - 1 ? ++row : 0;
				a[row][col] = ++counter;
			}
		} else {
			if (a[row - 1][col + 1] == 0) {
				--row;
				++col;
				a[row][col] = ++counter;
			} else {
				row < n - 1 ? ++row : 0;
				a[row][col] = ++counter;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
