/* Modify the repdigit.c program of section 8.1 so that it shows which digits
 * if any were repeated */

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main(void)
{
	bool digit_seen[MAX] = {false};
	int digit, i = 0;
	long n;
	int seen_digits[MAX] = {0};

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			seen_digits[i] = digit;
			i++;
		}
		digit_seen[digit] = true;
		n /= 10;
	}

	if (i > 0) {
		printf("Repeated digit(s):");
		for (; i > 0; i--) {
			printf("% d", seen_digits[i - 1]);
		}
		printf("\n");
	}
	else
		printf("No repeated digit\n");

	return 0;
}
