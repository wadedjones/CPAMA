/* Write a program that finds the largest in a series of numbers entered
* by the user
*/

#include <stdio.h>

int main(void)
{
	float largest = 0.0f, tmp;

	printf("Enter a number (0 to stop): ");
	scanf("%f", &tmp);
	while (tmp != 0) {
		if (tmp > largest)
			largest = tmp;
		printf("Enter a number (0 to stop): ");
		scanf("%f", &tmp);
	}

	printf("The largest number entered was %f\n", largest);

	return 0;
}
