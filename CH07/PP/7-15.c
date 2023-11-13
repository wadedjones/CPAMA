/* Write a program that computes the factorial of a positive integer */

#include <stdio.h>

int main(void)
{
	int num, i, j = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		j *= i;
	}

	printf("%d\n", j);

	return 0;
}
