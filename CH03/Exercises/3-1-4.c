/* scanf("%d%f%d", &i, &x, &j); input: 10.3 5 6
* what are the values of i, x, and j ?
*/

#include <stdio.h>

int main(void)
{
	int i, j;
	float x;

	scanf("%d%f%d", &i, &x, &j);

	printf("%d, %f, %d\n", i, x, j);

	return 0;
}
