/* Write a program that asks the user to enter two integers, then calculates
* their greatest common divisor (GCD)
*/

#include <stdio.h>

int main(void)
{
	int a, b, remainder;

	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	printf("%d, %d\n", a, b);

	/*
	for (; a > 0;)
		remainder = a % b;
		b = a;
		a = remainder;
		printf("a: %d, b: %d, remainder: %d\n", a, b, remainder);
	*/

	while (a > 0) {
		remainder = b % a;
		b = a;
		a = remainder;
		printf("%d, %d, %d\n", a, b, remainder);
	}

	printf("GCD: %d\n", b);

	return 0;
}
