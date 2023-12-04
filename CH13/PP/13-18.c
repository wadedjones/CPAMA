/* Write a program that accepts a date from the user in the form mm/dd/yyyy and
 * then displays it in the form month dd, yyy, where month is the name of the
 * month:
 *
 * Enter a date (mm/dd/yyyy) : 2/17/2011
 * You entered the date February 17, 2011
 *
 * Store the month names in an array that contains pointers to strings.*/

#include <stdio.h>

int main(void) {
  int day, month, year;
  char *months[] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

  printf("Enter a date (mm/dd/yyyy) : ");
  scanf(" %2d/ %2d/ %4d", &month, &day, &year);

  printf("You entered the date ");
  printf("%s %d, %d\n", months[month - 1], day, year);

  return 0;
}
