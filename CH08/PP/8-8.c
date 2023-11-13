/* Modify Project 7 so that it prompts for five quiz grades for each
 * of five students and computes the total score and average score
 * for each student, and teh average score, high score, and low score
 * for each quiz */

#include <stdio.h>

#define NUM 5

int main(void)
{
	int arr[NUM][NUM];
	int row[NUM] = {0};
	int column[NUM] = {0};
	int i, j, k;
	float average, high, low, tmp;

	for (i = 0; i < NUM; i++) {
		printf("Enter student %d: ", i + 1);
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

	printf("\n");

	printf("Student totals:");
	for (i = 0; i < NUM; i++) {
		printf(" %d> %.2f", i + 1, (float) row[i]);
	}
	printf("\n");

	printf("Student average:");
	for (i = 0; i < NUM; i++) {
		printf(" %d> %.2f", i + 1, (float) row[i] / NUM);
	}
	printf("\n\n");

	high = low = arr[0][0];

	for (i = 0; i < NUM; i++) {
		for (j = 0; j < NUM; j++) {
			tmp = arr[i][j];
			if (high < tmp)
				high = tmp;
			tmp = arr[i][j];
			if (low > tmp)
				low = tmp;
		}
	}

	printf("Student high: %.2f\nStudent low: %.2f", high, low);
	printf("\n\n");

	printf("Average quiz score:");
	for (i = 0; i < NUM; i++) {
		printf(" %d> %.2f", i + 1, (float) column[i] / NUM);
	}

	printf("\n");

	return 0;
}
