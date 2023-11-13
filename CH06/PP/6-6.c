/* Write a program that rpompts the user to enter a number, then prints
* all even squares between 1 and n.
*/

#include <stdio.h>

int main(void)
{
	int n, m;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (m = 2; (m * m) <= n; m += 2) {
		printf("%d\n", m * m);
	}

	return 0;
}
