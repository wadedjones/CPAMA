/* Prints a table of squares using a for statement */
/* find smallest number that exceeds maximum int value */
/* 46340 for int */
/* 181 for short */
/* idk over 10,000,000 for long */

#include <stdio.h>

int main(void)
{
	long i, n, k;

	printf("This program prints a table of squres.\n");
	printf("Enter number of entries in table: ");
	scanf("%ld", &n);

	for (i = 1; i <= n; i++) {
		k = i * i;
		if (k < 0)
			break;
		else
			printf("%20ld%20ld\n", i, k);
	}

	return 0;
}
