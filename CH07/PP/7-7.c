/* modify program so user may add, subtract, multiply or divide
* two fractions by entering either (+, -, *, or /)
*/

#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;
	char op;

	printf("Enter an equation: ");
	scanf("%d/%d %c %d/%d", &num1, &denom1, &op, &num2, &denom2);

	switch (op) {
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			break;
		case '/':
			result_num = num1 * denom2;
			result_denom = num2 * denom1;
			break;
		default:
			printf("Invalid operator.\n");
			return 1;
	}

	int tmp, num_tmp = result_num, gcd = result_denom;
	while (num_tmp > 0) {
		tmp = gcd % num_tmp;
		gcd = num_tmp;
		num_tmp = tmp;
	}

	printf("result_num: %d, result_denom: %d, gcd: %d\n", result_num, result_denom, gcd);

	if (result_num / gcd == result_denom / gcd) {
		printf("Result: %d\n", result_num / gcd);
	} else if (result_num > result_denom) {
		printf("Result: %d %d/%d\n", result_num / result_denom, result_num % result_denom, result_denom);
	} else {
		printf("Result: %d/%d\n", result_num / gcd, result_denom / gcd);
	}


	return 0;
}
