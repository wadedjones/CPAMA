/* Write a program that reverses a sentence.
 * Have it stop at the first period/exclamation point/question mark etc */

/* 9 8 7 6 5 4 3 2 1 0
 * 0 1 2 3 4 5 6 7 8 9 */

#include <stdio.h>

#define MAX_S 100

int main(void)
{
	char s[MAX_S], t[MAX_S];
	char c, terminator;
	int i = 0, j = 0, k = 0, l = 0;

	printf("Enter a sentence: ");
	while ((c = getchar()) != '\n') {
		if (c == '.' || c == '?' || c == '!')
			break;
		s[i++] = c;
	}
	terminator = c;
	i--;

	for (; i >= 0; i--) {
		if (s[i] != ' ')
			j++;
		if (s[i] == ' ') {
			for (l = 1; l <= j; l++, k++) {
				t[k] = s[i + l];
			}
			t[k++] = ' ';
			j = 0;
		}
		if (i == 0) {
			for (l = 0; l < j; l++, k++) {
				t[k] = s[i + l];
			}
			j = 0;
		}
	}

	for (i = 0; t[i] != 0; i++) {
		printf("%c", t[i]);
	}

	printf("%c\n", terminator);

	return 0;
}
