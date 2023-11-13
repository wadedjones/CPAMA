/* Write a program where user enters name "Wade Jones" and outputs "Jones, W." */

#include <stdio.h>

int main(void)
{
	char c, initial;

	printf("Enter name: ");
	scanf(" %c", &initial);

	printf("Initial: %c\n", initial);

	while ((c = getchar()) != ' ')
		;

	printf("C1: %c\n", c);

	while ((c = getchar()) == ' ')
		;

	printf("C2: %c\n", c);

	do {
		putchar(c);
		printf("C3: %c\n", c);
	} while ((c = getchar()) != '\n' && c != ' ');

	printf(", %c.\n", initial);

	return 0;

}
