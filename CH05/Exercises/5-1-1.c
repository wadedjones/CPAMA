/* the following program fragments illustrate the relational and equality
* operators. Show the output produced by each 
*/

#include <stdio.h>

int main(void)
{
	int i, j, k;

	// A
	i = 2; j = 3; k = i * j == 6;
	printf("%d\n", k);

	// B
	i = 5; j = 10; k = 1;
	printf("%d\n", k > i < j);

	// C
	i = 3; j = 2; k = 1;
	printf("%d\n", i < j == j < k);

	// C
	i = 3; j = 4; k = 5;
	printf("%d\n", i % j + i < k);

	return 0;
}
