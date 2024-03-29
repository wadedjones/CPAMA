/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring {
  int len;
  char str[];
};

int read_line(char str[], int n);

int main(void) {
  struct vstring *reminders[MAX_REMIND];
  char day_str[3];
  char msg[MSG_LEN];
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf(" %2d", &day);
    sprintf(day_str, "%2d", day);
    if (day == 0)
      break;
    read_line(msg, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]->str) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j - 1];

    reminders[i] = malloc(sizeof(struct vstring) + 2 + strlen(msg) + 1);
    if (reminders[i] == NULL) {
      printf("-- No space left--");
      break;
    }

    strcpy(reminders[i]->str, day_str);
    strcat(reminders[i]->str, msg);
    reminders[i]->len = strlen(reminders[i]->str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]->str);

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
