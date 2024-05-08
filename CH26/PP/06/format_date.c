#include <stdio.h>
#include <time.h>

void time1(void);
void time2(void);
void time3(void);

int main(void) {

  time1();
  time2();
  time3();

  return 0;
}

void time1(void) {
  time_t current = time(NULL);
  struct tm *ptr;
  char date_time[37];

  ptr = localtime(&current);
  strftime(date_time, sizeof(date_time), "%A, %B %d, %Y  %I:%M", ptr);
  printf("%s%c\n", date_time, ptr->tm_hour <= 11 ? 'a' : 'p');
}

void time2(void) {
  time_t current = time(NULL);
  char date_time[22];

  strftime(date_time, sizeof(date_time), "%a, %d %b %y  %H:%M",
           localtime(&current));
  puts(date_time);
}

void time3(void) {
  time_t current = time(NULL);
  struct tm *ptr;
  char date[9], time[12];

  ptr = localtime(&current);
  strftime(date, sizeof(date), "%m/%d/%y", ptr);
  strftime(time, sizeof(time), "%I:%M:%S %p", ptr);

  /* print date and time, suppressing leading zero in hours */
  printf("%s  %s\n", date, time[0] == '0' ? &time[1] : time);
}
