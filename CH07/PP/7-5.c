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
	char c;
	int sum;
	sum = 0;

	printf("Enter a word: ");

	while ((c = getchar()) != '\n') {
		switch (toupper(c)) {
			case 'A': case 'E': case 'I':
			case 'L': case 'N': case 'O':
			case 'R': case 'S': case 'T': case 'U':
				sum += 1;
				break;
			case 'D': case 'G': 
				sum += 2;
				break;
			case 'B': case 'C': case 'M': case 'P':
				sum += 3;
				break;
			case 'F': case 'H': case 'V': case 'W': case 'Y':
				sum += 4;
				break;
			case 'K':
				sum += 5;
				break;
			case 'J': case 'X':
				sum += 8;
				break;
			case 'Q': case 'Z':
				sum += 10;
				break;
			default:
				break;
		}
	}
	printf("Total score is %d\n", sum);

	return 0;
}
