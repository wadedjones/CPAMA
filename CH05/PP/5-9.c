/* Write a program that prompts the user to enter two dates adn then indicates
 * which date comes earlier */

#include <stdio.h>

int main(void) {
  int m1, d1, y1, m2, d2, y2;

  printf("Compare two dates.\n");
  printf("Enter first date (mm/dd/yy): ");
  scanf(" %d/ %d/ %d", &m1, &d1, &y1);
  printf("Enter second date (mm/dd/yy): ");
  scanf(" %d/ %d/ %d", &m2, &d2, &y2);

  if ((m1 + d1 + y1) < (m2 + d2 + y2)) {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
  } else {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
  }

  return 0;
}
