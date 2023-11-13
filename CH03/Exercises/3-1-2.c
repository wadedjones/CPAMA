/* Write print calls in the following formats */

#include <stdio.h>

int main(void)
{
	float x = 3.456f;
	// Exponential notation; left-justified of size 8; one digit after the decimal point
	printf("%-8.1e\n", x);

	// Exponential notation; right-justified size 10; 6 digits after decimal point
	printf("%10.6e\n", x);

	// Fixed decimal notation; left-justified size 8; 3 digits after decimal point
	printf("%-8.3f\n", x);

	// Fixed decimal notation; right-justified size 6; no digits after decimal point
	printf("%6.0f\n", x);

	return 0;
}
