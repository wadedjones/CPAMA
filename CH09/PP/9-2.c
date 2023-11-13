/* Modify PP 5 from chapter 5 so that it uses a function to compute the amount
 * of income tax. */

#include <stdio.h>

float income_calc(float income);

int main(void) {
  float income, tax;

  printf("Enter income: ");
  scanf("%f", &income);

  tax = income_calc(income);

  printf("Taxes due: $%.2f\n", tax);

  return 0;
}

float income_calc(float income) {
  float tax_inc = 0.0;

  if (income < 750)
    tax_inc = income * 0.01f;
  else if (income < 2250)
    tax_inc = 7.50f + (0.02f * (income - 750.00f));
  else if (income < 3750)
    tax_inc = 37.50 + (0.03f * (income - 2250.00f));
  else if (income < 5250)
    tax_inc = 82.50f + (0.04f * (income - 3750.00f));
  else if (income < 7000)
    tax_inc = 142.50f + (0.05f * (income - 5250.00f));
  else
    tax_inc = 230.00f + (0.06f * (income - 7000.00f));

  return tax_inc;
}
