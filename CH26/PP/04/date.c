#include <stdio.h>
#include <time.h>

int main(void) {
  int month, day, year, n;
  printf("Enter a month (1 - 12): ");
  scanf("%d", &month);
  printf("Enter a day (1 - 31): ");
  scanf("%d", &day);
  printf("Enter a year (1900 - 2024): ");
  scanf("%d", &year);
  printf("Enter a number n: ");
  scanf("%d", &n);

  struct tm t;
  t.tm_mday = day;
  t.tm_mon = month - 1;
  t.tm_year = year - 1900;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_isdst = -1;

  t.tm_mday += n;

  mktime(&t);

  printf("%.2d/%.2d/%d\n", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);

  return 0;
}
