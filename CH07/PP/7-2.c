/* Modify square2.c program so it pauses after every 24 squares and displays the following message:
* "Press Enter to continue..."
*/

#include <stdio.h>

int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);
	getchar();

	for (i = 1; i <= num; i++) {
		printf("%10d%10d\n", i, i * i);
		if (i % 24 == 0) {
			printf("Press Enter to continue...");
			while (getchar() != '\n')
				;
		}
	}

	return 0;
}
