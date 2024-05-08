#include <stdio.h>
#include <time.h>

int main(void) {
  struct tm t1, t2;

  printf("Enter two dates to compare: \n\n");
  printf("Enter a month (1 - 12): ");
  scanf("%d", &t1.tm_mon);
  printf("Enter a day (1 - 31): ");
  scanf("%d", &t1.tm_mday);
  printf("Enter a year (1900 - 2024): ");
  scanf("%d", &t1.tm_year);
  t1.tm_mon--;
  t1.tm_year -= 1900;
  t1.tm_min = 0;
  t1.tm_sec = 0;
  t1.tm_hour = 0;
  t1.tm_isdst = -1;

  printf("Enter a month (1 - 12): ");
  scanf("%d", &t2.tm_mon);
  printf("Enter a day (1 - 31): ");
  scanf("%d", &t2.tm_mday);
  printf("Enter a year (1900 - 2024): ");
  scanf("%d", &t2.tm_year);
  t2.tm_mon--;
  t2.tm_year -= 1900;
  t2.tm_min = 0;
  t2.tm_sec = 0;
  t2.tm_hour = 0;
  t2.tm_isdst = -1;

  int result = (int)difftime(mktime(&t1), mktime(&t2)) / 60 / 60 / 24;

  printf("Days between: %d\n", result < 0 ? result * -1 : result);
}
