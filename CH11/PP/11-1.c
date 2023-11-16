/* Modify PP 7 from chapter 2 so that it includes the following function:
 *
 * void pay_amount (int dollars, int *twenties, int *tens, int *fives, int
 * *ones)
 *
 * The function determines the smallest number of $20, $10, $5, and $1 bills
 * necessary to pay the amount represented by the dollars parameter. The
 * twenties parameter points to a variable in which the function will store the
 * number of $20 bills required. The tens, fives, and ones parameters are
 * similar. */

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
  int dollars, twenties, tens, fives, ones;
  twenties = tens = fives = ones = 0;

  dollars = 58;

  pay_amount(dollars, &twenties, &tens, &fives, &ones);

  printf("20: %d, 10: %d, 5: %d, 1: %d\n", twenties, tens, fives, ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / 20;
  *tens = (dollars - (*twenties * 20)) / 10;
  *fives = (dollars - (*twenties * 20) - (*tens * 10)) / 5;
  *ones = (dollars - (*twenties * 20) - (*tens * 10)) - (*fives * 5);
}
