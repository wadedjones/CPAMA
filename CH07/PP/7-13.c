/* Write a program that calculates the average word length for a sentence */

#include <stdio.h>

int main(void)
{
	char c;
	int i = 0, j = 1;

	while ((c = getchar()) != '\n') {
		if (c != ' ')
			i++;
		else
			j++;
	}

	printf("%.1f\n", (float) i / (float) j);

	return 0;
}
