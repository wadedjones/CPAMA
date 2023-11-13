/* Write a program that asks user for a number then reverses the number */

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	do {
		printf("%d", n % 10);
		n /= 10;
	} while (n > 0);
	printf("\n");

	return 0;
}
