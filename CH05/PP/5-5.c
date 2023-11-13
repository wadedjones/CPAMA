/* write a program that asks user to enter amount of taxable income
* then displays the tax due
*/

#include <stdio.h>

int main(void)
{
	float income, tax;

	printf("Enter income: ");
	scanf("%f", &income);

	if (income < 750)
		printf("$%.2f\n", income * .01f);
	else if (income < 2250)
		printf("$%.2f\n", 7.50f + (.02f * (income - 750.00f)));
	else if (income < 3750)
		printf("$%.2f\n", 37.50f + (.03f * (income - 2250.00f)));
	else if (income < 5250)
		printf("$%.2f\n", 82.50f + (.04f * (income - 3750.00f)));
	else if (income < 7000)
		printf("$%.2f\n", 142.50f + (.05f * (income - 5250.00f)));
	else
		printf("$%.2f\n", 230.00f + (.06f * (income - 7000.00f)));

	return 0;
}
