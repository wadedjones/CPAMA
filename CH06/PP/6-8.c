/* Write a program that prints a one-month calendar. The user specifies the number of days
* in the month and the day of the week on which the month begins
*/

#include <stdio.h>

int main(void)
{
	int month, week;
	int i, j, week_day = 0;

	printf("Enter number of days in month: ");
	scanf("%d", &month);
	printf("Enter starting day of week (1=Sun, 7=Sat): ");
	scanf("%d", &week);

	week_day += week;
	i = 2 - week;

	printf("  S   M   T   W   T   F   S \n");

	for (; i <= month; i++) {
		if (i < 1) {
			printf("    ");
			continue;
		}
		if (week_day > 7) {
			printf("\n");
			week_day = 1;
		}
		printf("%3d ", i);
		week_day++;
	}
	printf("\n");

	return 0;
}
