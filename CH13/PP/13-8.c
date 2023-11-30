/* Modify PP 5 from chapter 7 so that it includes the following function:
 * int compute_scrabble_value(const char *word);
 * The function returns the SCRABBLE value of the string pointed to bye word.*/

/* Write a program that computes total scrabble scores from input */
/* 1: AEILNORSTU
 *  2: DG
 *  3: BCMP
 *  4: FHVWY
 *  5: K
 *  8: JX
 *  10: QZ
 */

#include <ctype.h>
#include <stdio.h>

int compute_scrabble_value(const char *word);
int read_line(char *str, int n);

int main(void) {
  char c;
  int sum;
  sum = 0;
  char word[50];

  printf("Enter a word: ");
  read_line(word, 50);
  sum = compute_scrabble_value(word);

  printf("Total score is %d\n", sum);

  return 0;
}

int compute_scrabble_value(const char *word) {
  int sum = 0;

  for (; *word; word++) {
    switch (toupper(*word)) {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      sum += 1;
      break;
    case 'D':
    case 'G':
      sum += 2;
      break;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
      sum += 3;
      break;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      sum += 4;
      break;
    case 'K':
      sum += 5;
      break;
    case 'J':
    case 'X':
      sum += 8;
      break;
    case 'Q':
    case 'Z':
      sum += 10;
      break;
    default:
      break;
    }
  }

  return sum;
}

int read_line(char *str, int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
