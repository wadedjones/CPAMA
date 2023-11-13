/* re-write project 2 similar to upc.c from 4-1 */

#include <stdio.h>

int main(void)
{
	int i, j, k;

	printf("Enter a three digit number: ");
	scanf("%1d%1d%1d", &i, &j, &k);

	printf("%d%d%d\n", k, j, i);

	return 0;
}
