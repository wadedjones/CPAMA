/* Excercises 8.1 - 8.11 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// 8.1
	// sizeof(a) / sizeof(a[0]) is better than sizeof(type(a[0]))

	// 8.2
	// letter as a subscript: a[d - '0']

	// 8.3
	// write a declaration named weekend containing seven bool values
	// first and last values: true, all others: false
	bool weekend[] = {true, false, false, false, false, false, true};

	// 8.4
	// repeat 8.3 with a designated initializer, as short as possible
	bool weekend2[7] = {[0] = true, [6] = false};

	// 8.5
	// fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13...
	// write a program fragment that declares an array named fib_numbers of length
	// 40 and fills the array with the first 40 fib numbers.
	int fib_numbers[40] = {0, 1};
	printf("1: \n");
	for (int k = 0; k < 40; k++)
		printf("%d ", fib_numbers[k]);
	printf("\n");

	for (int i = 2; i < 40; i++) {
		fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
	}
	printf("2: \n");
	for (int j = 0; j < 40; j++)
		printf("%d ", fib_numbers[j]);
	printf("\n");

	// 8.6
	// set up an array of numbers which segments should be on for "watch" style digits
	//   _
	//  | |
	//   -
	//  |_|
	const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
															 {0, 1, 1, 0, 0, 0, 0},
															 {1, 1, 0, 1, 1, 0, 1},
															 {1, 1, 1, 1, 0, 0, 1},
															 {0, 1, 1, 0, 0, 1, 1},
															 {1, 0, 1, 1, 0, 1, 1},
															 {1, 0, 1, 1, 1, 1, 1},
															 {1, 1, 1, 0, 0, 0, 0},
															 {1, 1, 1, 1, 1, 1, 1},
															 {1, 1, 1, 1, 0, 1, 1},
	};

	// 8.7
	// using shortcuts described in 8.2, shrink the initializer as much as you can
	const int segments2[10][7] = {{1, 1, 1, 1, 1, 1},
															 {0, 1, 1},
															 {1, 1, 0, 1, 1, 0, 1},
															 {1, 1, 1, 1, 0, 0, 1},
															 {0, 1, 1, 0, 0, 1, 1},
															 {1, 0, 1, 1, 0, 1, 1},
															 {1, 0, 1, 1, 1, 1, 1},
															 {1, 1, 1},
															 {1, 1, 1, 1, 1, 1, 1},
															 {1, 1, 1, 1, 0, 1, 1},
	}; 
	
	// 8.8 Write a declaration for a two-dimensional array named temperature_readings
	// that stores one month of hourly tempterature readings. (assume a month has
	// 30 days) rows represent days, columns represent hours
	float temperature_readings[30][24];

	// 8.9 using the array of exercise 8, write a program fragment that
	// computes the average temperature for a month
	srand((unsigned) time(NULL));
	float hourly_temp = 0, total = 0;

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 24; j++) {
			temperature_readings[i][j] = rand() % 10 * 10;
		}
	}

	for (int k = 0; k < 30; k++) {
		for (int l = 0; l < 24; l++) {
			hourly_temp += temperature_readings[k][l];
		}
	}
	total = hourly_temp / 24 / 30;
	printf("%.2f\n", total);

	// 8.10
	// Write a declaration for an 8 x 8 char array named chess_board
	char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
														{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
														{' ', '*', ' ', '*', ' ', '*', ' ', '*'},
														{'*', ' ', '*', ' ', '*', ' ', '*', ' '},
														{' ', '*', ' ', '*', ' ', '*', ' ', '*'},
														{'*', ' ', '*', ' ', '*', ' ', '*', ' '},
														{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
														{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
														};

	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) {
			printf("%c ", chess_board[i][k]);
		}
		printf("\n");
	}

	// 8.11
	// Write a program fragment that declares an 8x8 char array named
	// checker_board using a loop to store the data
	char checker_board[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			checker_board[i][j] = ((i + j) % 2 == 0) ? 'B' : 'R';
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c ", checker_board[i][j]);
		}
		printf("\n");
	}


	return 0;
}
