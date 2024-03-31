#include <math.h>
#include <stdio.h>

#define EULER 2.718281

double calc_interest(double deposit, double interest, size_t years);

int main(void) {
  double deposit;
  double interest;
  int years;

  printf("Enter deposit amount: ");
  scanf("%lf", &deposit);
  printf("Enter interest rate: ");
  scanf("%lf", &interest);
  printf("Enter total years: ");
  scanf("%d", &years);

  interest *= .01;

  double total = calc_interest(deposit, interest, years);
  printf("Total: $%.2lf\n", total);

  return 0;
}

double calc_interest(double deposit, double interest, size_t years) {
  double total = deposit;
  total *= exp(interest * years);
  return total;
}
