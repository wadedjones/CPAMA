/* following fragments illustrate the logical operators */

#include <stdio.h>

int main(void)
{
	int i, j, k;

	// A
	i = 10; j = 5;
	printf("%d\n", !i < j);

	// B
	i = 2; j = 1;
	printf("%d\n", !!i + !j);

	// C
	i = 5; j = 0; k = -5;
	printf("%d\n", i && j || k);

	// D
	i = 1; j = 2; k = 3;
	printf("%d\n", i < j || k);

	return 0;
}
