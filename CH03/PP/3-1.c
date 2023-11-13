/* Write a program that accepts a date from the user in the form mm/dd/yyy and then
* displays it in the form yyyymmdd
*/

#include <stdio.h>

int main(void)
{
	int m, d, y;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m, &d, &y);

	printf("You entered the date %d%.2d%.2d\n", y, m, d);
	
	return 0;
}
