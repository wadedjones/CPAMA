/* write a program that asks the user for 24 hour time, then
* displays it in 12 hour form
*/

#include <stdio.h>

int main(void)
{
	int hour, minute;

	printf("Enter a 24 hour time (hh:mm): ");
	scanf("%d:%d", &hour, &minute);

	if (hour > 13)
		printf("12-hour time: %d:%d PM\n", hour - 12, minute);
	else if (hour == 12)
		printf("12-hour time: %d:%d PM\n", hour, minute);
	else
		printf("12-hour time: %d:%d AM\n", hour, minute);

	return 0;
}
