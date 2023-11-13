/* just throwing all the exercises in here y'all */

#include <stdio.h>

int main(void)
{
	/*
	// 6.1
	int i = 1;
	while (i <= 128) {
		printf("%d ", i);
		i *= 2;
	}
	*/

	/*
	// 6.2
	int i = 9384;
	do {
		printf("%d ", i);
		i /= 10;
	} while (i > 0);
	*/

	/*
	// 6.3
	int i, j;
	for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
		printf("%d ", i);
	*/

	/*
	// 6.4
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i < 10; ++i)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i++ < 10;)
		printf("%d ", i);
	printf("\n");
	*/

	/*
	// 6.6
	int i;
	for (i = 1; i <= 128; i *= 2)
		printf("%d ", i);
	*/

	/*
	// 6.7
	int i;
	for (i = 9384; i > 0; i /= 10)
		printf("%d ", i);
	*/

	// 6.8
	int i;
	for (i = 10; i >= 1; i /= 2) // infinite loop with the >=
		printf("%d ", i++);

	return 0;
}
