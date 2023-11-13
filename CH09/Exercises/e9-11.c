/* Write the following function:
 * float compute_GPA(char grades[], int n);
 * The grades array will contain letter grades (A, B, C, D, or F, upper
 * or lower case). n is the length of the array. The function should
 * return the average fo the grades. (assume that A=4, B=3, C=2, D=1, F= 0)*/

#include <ctype.h>
#include <stdio.h>

float compute_GPA(char grades[], int n) {
  int total = 0, i;
  for (i = 0; i < n; i++) {
    switch (toupper(grades[i])) {
    case 'A':
      total += 4;
      break;
    case 'B':
      total += 3;
      break;
    case 'C':
      total += 2;
      break;
    case 'D':
      total += 1;
      break;
    case 'F':
      break;
    default:
      break;
    }
  }
  return (float)total / n;
}

int main(void) {
  char grades[] = {'A', 'B', 'A', 'D', 'C', 'f', 'a', 'b', 'c', 'f'};
  int n = 10;

  printf("average of grades: %.2f\n", compute_GPA(grades, n));
  return 0;
}
