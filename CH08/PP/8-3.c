/* Modify repdigit.c AGAIN HOLY FUCK so that the user can enter more than
 * one number to be tested for repeated digits. Program exits when the user
 * enters a number less than or equal to zero */

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main(void)
{
	int digit, i;
	long n;
	int seen_digits[MAX] = {0};

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		while (n > 0) {
			digit = n % 10;
			seen_digits[digit]++;
			n /= 10;
		}
		printf("Digit:       0 1 2 3 4 5 6 7 8 9\n");
		printf("Occurrences:");
		for (i = 0; i < MAX; i++) {
			printf(" %d", seen_digits[i]);
		}
		printf("\n");

		for (i = 0; i < MAX; i++)
			seen_digits[i] = 0;

		printf("Enter a number: ");
		scanf("%ld", &n);

	}

	return 0;
}
