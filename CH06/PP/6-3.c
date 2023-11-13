/* Write a program that asks the user to enter a fraction, then
* reduces the fraction to lowest terms
*/

#include <stdio.h>

int main(void)
{
	int n, d, remainder, tmpn, tmpd;

	printf("Enter a fraction: ");
	scanf("%d/%d", &n, &d);

	tmpn = n;
	tmpd = d;

	while (tmpn > 0) {
		remainder = tmpd % tmpn;
		tmpd = tmpn;
		tmpn = remainder;
	}

	n /= tmpd;
	d /= tmpd;

	printf("%d/%d\n", n, d);

	return 0;
}
