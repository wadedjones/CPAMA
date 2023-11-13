/* Write a program that reads a 5 x 5 array of integers and then prints
 * the row sums and column sums */

#include <stdio.h>

#define NUM 5

int main(void)
{
	int arr[NUM][NUM];
	int row[NUM] = {0};
	int column[NUM] = {0};
	int i, j, k;

	for (i = 0; i < NUM; i++) {
		printf("Enter row %d: ", i + 1);
		for (j = 0; j < NUM; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0, k = 0; i < NUM; i++, k++) {
		for (j = 0; j < NUM; j++) {
			row[k] += arr[i][j];
			column[k] += arr[j][i];
		}
	}

	printf("Row totals:");
	for (i = 0; i < NUM; i++) {
		printf(" %d", row[i]);
	}
	printf("\n");

	printf("Column totals:");
	for (i = 0; i < NUM; i++) {
		printf(" %d", column[i]);
	}
	printf("\n");

	return 0;
}
