/* Modify Scrabble so that the value of letters is stored in an array */


/* Write a program that computes total scrabble scores from input */
/* 1: AEILNORSTU
*  2: DG
*  3: BCMP
*  4: FHVWY
*  5: K
*  8: JX
*  10: QZ
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	// 								A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
	int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
	char c;
	int sum;
	sum = 0;

	printf("Enter a word: ");

	while ((c = getchar()) != '\n') {
		sum += scores[toupper(c) - 'A'];
	}
	printf("Total score is %d\n", sum);

	return 0;
}
