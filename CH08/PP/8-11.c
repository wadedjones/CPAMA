/* Modify so that the number is "labeled" */
/* Write a program that translates an alphabetic phone number into
* numeric form: CALLATT -> 2255288
* 1-800-CAL-LATT
*/

#include <stdio.h>
#include <ctype.h>

#define NUM 15

int main(void)
{
	int i = 0;
	char phone[NUM] = {0};

	printf("Enter a phone number: ");

	while ((phone[i++] = getchar()) != '\n')
		;

	printf("In numeric form: ");

	for (i = 0; i < NUM; i++) {
		switch (toupper(phone[i])) {
			case 'A': case 'B': case 'C':
				putchar('2');
				break;
			case 'D': case 'E': case 'F':
				putchar('3');
				break;
			case 'G': case 'H': case 'I':
				putchar('4');
				break;
			case 'J': case 'K': case 'L':
				putchar('5');
				break;
			case 'M': case 'N': case 'O':
				putchar('6');
				break;
			case 'P': case 'Q': case 'R': case 'S':
				putchar('7');
				break;
			case 'T': case 'U': case 'V':
				putchar('8');
				break;
			case 'W': case 'X': case 'Y': case 'Z':
				putchar('9');
				break;
			default:
				putchar(phone[i]);
				break;
		}
	}
	printf("\n");

	return 0;

}
