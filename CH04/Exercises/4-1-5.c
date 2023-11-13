/* value of each of the following expressions in C89 and C99 */

#include <stdio.h>

int main(void)
{
	printf("%d\n", 8 % 5);
	printf("%d\n", -8 % 5);
	printf("%d\n", 8 % -5);
	printf("%d\n", -8 % -5);
	
	// C89: 3, -3, 3, -3
	// C99: 3, -3, 3, -3 again what the hell its the same??

	return 0;
}
