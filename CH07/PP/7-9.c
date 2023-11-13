/* Write a program so that the user enters 12 hour time and outputs 24 hour time */

#include <stdio.h>

int main(void)
{
	int hour, min;
	char c;

	printf("Enter time: ");
	scanf("%d:%d %c", &hour, &min, &c);

	if (c == 'p' || c == 'P') {
		hour < 12 ? hour += 12 : hour;
	} else {
		hour == 12 ? hour -= 12 : hour;
	}

	printf("%.2d:%d\n", hour, min);

	return 0;
}
