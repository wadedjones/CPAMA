/* Create a Ceasar Cipher */

#include <stdio.h>

#define MAX 50

int main(void)
{
	char s[MAX], c;
	int i, n;

	printf("Enter a message to be encrypted: ");

	i = 0;

	while ((c = getchar()) != '\n') {
		s[i++] = c;
	}

	printf("Enter shift amount: ");
	scanf("%d", &n);

	printf("Encrypted message: ");
	for (i = 0; s[i] != 0; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			printf("%c", (((s[i] - 'a') + n) % 26 + 'a'));
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			printf("%c", (((s[i] - 'A') + n) % 26 + 'A'));
		} else {
			printf("%c", s[i]);
		}
	}
	printf("\n");

	return 0;
}
