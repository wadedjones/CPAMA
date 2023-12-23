#include <stdio.h>

struct date {
  int month, day, year;
};

int compare_dates(struct date date1, struct date date2);

int main(void) {
  struct date date1, date2;
  int result;

  printf("Compare two dates.\n");
  printf("Enter first date (mm/dd/yy): ");
  scanf(" %d/ %d/ %d", &date1.month, &date1.day, &date1.year);
  printf("Enter second date (mm/dd/yy): ");
  scanf(" %d/ %d/ %d", &date2.month, &date2.day, &date2.year);

  result = compare_dates(date1, date2);

  if (!result) {
    printf("The dates are the same.\n");
  } else if (result == 1) {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", date2.month, date2.day,
           date2.year, date1.month, date1.day, date1.year);
  } else if (result == -1) {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", date1.month, date1.day,
           date1.year, date2.month, date2.day, date2.year);
  } else {
    printf("Who knows what went wrong?\n");
  }

  return 0;
}

int compare_dates(struct date date1, struct date date2) {
  if ((date1.day + date1.month + date1.year) ==
      (date2.day + date2.month + date2.year)) {
    return 0;
  } else if ((date1.day + date1.month + date1.year) >
             (date2.day + date2.month + date2.year)) {
    return 1;
  } else {
    return -1;
  }
}
