/* Write a program that asks user for a 3 digit number then reverses the number */

#include <stdio.h>

int main(void)
{
	int i;

	printf("Enter 3 digit number: ");
	scanf("%d", &i);
	// printf("%d%d%d\n", (i % 10), (i % 10) / 10, (i / 100));
	printf("|%d|%d|%d|\n", (i % 10), ((i / 10) % 10), (i / 10) / 10);

	return 0;
}
