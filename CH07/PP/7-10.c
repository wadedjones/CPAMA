/* Write a program that counts vowels in input */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int count = 0;
	char c;

	printf("Enter a sentence: ");

	while ((c = getchar()) != '\n') {
		if (toupper(c) == 'A' || toupper(c) == 'E'
				|| toupper(c) == 'I' || toupper(c) == 'O'
				|| toupper(c) == 'U') {
			count++;
		}
	}

	printf("Your sentence contains %d vowels.\n", count);

	return 0;
}
