/* Write a program that checks if two words are anagrams */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a[26] = {0};
	char c;
	int i;

	printf("Enter first word: ");
	while ((c = getchar()) != '\n') {
		if (!isalpha(c)) {
			continue;
		}
		a[(int) (tolower(c) - 'a')]++;
	}

	printf("Enter second word: ");
	while ((c = getchar()) != '\n') {
		a[(int) (tolower(c) - 'a')]--;
	}

	for (i = 0; i < 26; i++) {
		printf("%d", a[i]);
	}
	printf("\n");

	for (i = 0; i < 26; i++) {
		if (a[i] > 0) {
			printf("The words are not anagrams.");
			break;
		} else if (i == 25) {
			printf("The words are anagrams.");
			break;
		}
	}
	printf("\n");

	return 0;
}
