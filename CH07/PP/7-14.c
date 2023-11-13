/* Write a program that uses Newton's method to compute the square root
* of a positive floating point number
*/

#include <stdio.h>
#include <math.h>

/*
int main(void)
{
	double x, y, average, product;
	y = 1;
	product = 0.00001;

	printf("Enter a number: ");
	scanf("%lf", &x);

	average = (x / y + y) / 2;

	do {
		y = average;
		average = (x / y + y) / 2;
	} while (fabs(y) > fabs(average));

	printf("average: %lf", fabs(average));

	return 0;
}
*/

// Different version (simpler)

int main(void)
{
	double x, y = 1;

	printf("Enter a number: ");
	scanf("%lf", &x);

	while (fabs((x / y + y) / 2 - y) > 0.00001 * y) {
		y = (x / y + y) / 2;
	}

	printf("average: %lf\n", y);

	return 0;
}
