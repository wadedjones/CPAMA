/* write a program that calculates how many digits a number contains (<= 4) */

#include <stdio.h>

int main(void)
{
	int i;
	
	printf("Enter a 1 - 4 digit number: ");
	scanf("%d", &i);

	if (i < 10)
		printf("1 digit\n");
	else if (i < 100)
		printf("2 digits\n");
	else if (i < 1000)
		printf("3 digits\n");
	else
		printf("4 digits\n");

	return 0;
}
