/* Write a program that converts input to "B1FF" speak */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
	char user_input[MAX] = {0};
	int c, i, j;
	i = 0;

	printf("Enter message: ");
	while ((c = getchar()) != '\n' && i < MAX) {
		user_input[i] = c;
		i++;
	}

	printf("In B1FF-speak: ");
	
	i = 0;
	while (user_input[i] != 0) {
		switch (toupper(user_input[i])) {
			case 'A':
				user_input[i] = '4';
				break;
			case 'B':
				user_input[i] = '8';
				break;
			case 'E':
				user_input[i] = '3';
				break;
			case 'I':
				user_input[i] = '1';
				break;
			case 'O':
				user_input[i] = '0';
				break;
			case 'S':
				user_input[i] = '5';
				break;
			default:
				user_input[i] = toupper(user_input[i]);
				break;
		}
		i++;
	}
	for (j = 0; j < 10; j++, i++) {
		user_input[i] = '!';
	}

	i = 0;
	while (user_input[i] != 0) {
		printf("%c", user_input[i]);
		i++;
	}
	printf("\n");

	return 0;
}
