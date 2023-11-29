/* Improve the remind.c program of section 13.5 in the following ways:
 * (a) Have the program print an error message and ignore a reminder if the
 * corresponding day is negative or larger than 31. Hint: use the continue
 * statement. (b) Allow the user to enter a day, a 24-hour time, and a reminder.
 * The printed reminder list should be sorted first by day, then by time. (The
 * original program allows the user to enter a time, but it's treated as part of
 * the reminder.) (c) Have the program print a one-year reminder list. Require
 * the user to enter days in the form month/day. */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void) {
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char day_str[10], hour_str[4], msg_str[MSG_LEN + 1];
  int month, day, hour, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter a reminder (mm/dd hr reminder): ");
    scanf("%2d/ %2d", &month, &day);
    if (day == 0 || month == 0) {
      break;
    } else if (day < 0 || day > 31 || month < 0 || month > 12) {
      printf("Please enter a day between 1 and 31\n");
      printf("and a month between 1 and 12\n");
      printf("or 0 to quit.\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    scanf("%2d", &hour);
    if (hour < 0 || hour > 24) {
      printf("Please enter an hour between 0 and 24\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    sprintf(day_str, "%2d %2d %2d", month, day, hour);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      if (strcmp(day_str, reminders[i]) < 0) {
        break;
      }
    }
    for (j = num_remind; j > i; j--) {
      strcpy(reminders[j], reminders[j - 1]);
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], hour_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nMonth Day Reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf(" %s\n", reminders[i]);
  }

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';
  return i;
}
