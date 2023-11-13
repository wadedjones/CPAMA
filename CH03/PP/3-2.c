/* Write a program that formats product info entered by user */
#include <stdio.h>

int main(void)
{
	int item_num, m, d, y;
	float price;

	printf("Enter item number: ");
	scanf("%d", &item_num);

	printf("Enter unit price: ");
	scanf("%f", &price);

	printf("Enter purchase date: ");
	scanf("%d/%d/%d", &m, &d, &y);

	printf("Item\tUnit\tPurchase\n");
	printf("\tPrice\tDate\n");
	printf("%d\t$%.2f\t%.2d/%.2d/%d\n", item_num, price, m, d, y);

	return 0;
}
