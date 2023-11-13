/* Modify project 11 from chapter 7 so the output is "labeled" */

/* Write a program where user enters name "Wade Jones" and outputs "Jones, W." */

#include <stdio.h>

int main(void)
{
	char c, initial;
	char last_name[20] = {0};
	int i = 0;

	printf("Enter name: ");
	scanf(" %c", &initial);

	while ((c = getchar()) != ' ')
		;

	for (i = 0; (c = getchar()) != '\n'; i++) {
		last_name[i] = c;
	}

	for (i = 0; last_name[i] != 0; i++) {
		putchar(last_name[i]);
	}

	printf(", %c.\n", initial);

	return 0;

}
