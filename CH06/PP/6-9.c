/* Write a program that calculates remaining balnce on a loan after the "n" amount of payments */

#include <stdio.h>

int main(void)
{
	float loan, interest, payment, total, current;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &interest);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	printf("Enter number of payments: ");
	scanf("%f", &total);

	interest = (interest / 12.0f) * .01f;

	for (int i = 0; i < total; i++) {
		current = (loan - payment) + (interest * loan);
		loan = (loan - payment) + (loan * interest);
		printf("Balance remaining after payment %d: $%.2f\n", i + 1, current);
	}

	return 0;
}
