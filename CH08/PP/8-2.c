/* Modify repdigit.c program so that it prints a table showing how
 * many times each digit appears in the number */

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


	return 0;
}
