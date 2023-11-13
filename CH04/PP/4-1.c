/* Write a program that asks user for a 2 digit number then reverses the number */

#include <stdio.h>

int main(void)
{
	/*
	int i, j;

	printf("Enter 2 digit number: ");
	scanf("%1d%1d", &i, &j);

	printf("%d%d\n", j, i);
	*/
	int k;

	printf("Enter 2 digit number: ");
	scanf("%d", &k);
	printf("%d%d\n", (k % 10), (k / 10));

	return 0;
}
