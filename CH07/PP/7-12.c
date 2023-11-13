/* Write a program that evaluates an expresssion:
* Enter an expression: 1+2.5*3
*/

#include <stdio.h>

int main(void)
{
	float f1, f2, f3, r1, r2;
	char op1, op2;

	printf("Enter an expresssion: ");
	scanf("%f%c%f%c%f", &f1, &op1, &f2, &op2, &f3);

	switch (op1) {
		case '+':
			r1 = f1 + f2;
			break;
		case '-':
			r1 = f1 - f2;
			break;
		case '*':
			r1 = f1 * f2;
			break;
		case '/':
			if (f1 != 0 && f2 != 0)
				r1 = f1 / f2;
			else
				printf("Can't divide by zero!\n");
			break;
		default:
			printf("Operator not valid.\n");
			break;
	}

	switch (op2) {
		case '+':
			r2 = r1 + f3;
			break;
		case '-':
			r2 = r1 - f3;
			break;
		case '*':
			r2 = r1 * f3;
			break;
		case '/':
			if (r1 != 0 && f3 != 0)
				r2 = r1 / f3;
			else
				printf("Can't divide by zero!\n");
			break;
		default:
			printf("Operator not valid.\n");
			break;
	}

	printf("Value of expression: %.2f\n", r2);

	return 0;
}
