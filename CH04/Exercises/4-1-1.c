/* show the output of the following fragments */
#include <stdio.h>

int main(void)
{
	int i, j, k;

	// A
	i = 5;
	j = 3;
	printf("%d %d\n", i / j, i % j);

	// B
	i = 2;
	j = 3;
	printf("%d\n", (i + 10) % j);

	// C
	i = 7;
	j = 8;
	k = 9;
	printf("%d\n", (i + 10) % k / j);

	// D
	i = 1;
	j = 2;
	k = 3;
	printf("%d\n", (i + 5) % (j + 2) / k);

	return 0;
}
