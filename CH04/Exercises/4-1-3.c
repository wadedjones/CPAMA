/* value of each of the following expressions in C89 */

#include <stdio.h>

int main(void)
{
	printf("%d\n", 8 / 5);
	printf("%d\n", -8 / 5);
	printf("%d\n", 8 / -5);
	printf("%d\n", -8 / -5);
	// C89: 1, -1, -1, 1
	// C99: 1, -1, -1, 1 umm what the hell

	return 0;
}
