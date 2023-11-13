/* Write a program that prompts the user for a number then displays the number
 * using characters to simulate a seven-segment display
 *
 *      _       _  _       _   _  _   _   _
 *     | |   |  _| _| |_| |_  |_   | |_| |_|
 *     |_|   | |_  _|   |  _| |_|  | |_|  _|
 *
 *      0
 *     5 1
 *     	6
 *     4 2
 *      3
 * */

#include <stdio.h>

#define MAXDIGITS 10

/* external variables */
int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                       {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                       {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                       {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
char digits[4][MAXDIGITS * 4];

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
  int i, j, position;

  int user_digits[MAXDIGITS] = {3, 4, 5, 6, 7};

  clear_digits_array();

  position = 0;
  for (i = 0; i < MAXDIGITS; i++) {
    process_digit(user_digits[i], position);
    position += 4;
  }
  print_digits_array();

  return 0;
}

void clear_digits_array(void) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < MAXDIGITS * 4; j++) {
      digits[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int position) {
  // clang-format off
	int digit_placement[7][2] = {
	{0, 1},
	{1, 2},
	{2, 2},
	{2, 1},
	{2, 0},
	{1, 0},
	{1, 1}
	};
	int i, col, row;

	for (i = 0; i < 7; i++) {
		if (segments[digit][i]) {
			row = digit_placement[i][0];
			col = digit_placement[i][1] + position;
			digits[row][col] = i % 3 == 0 ? '_' : '|';
		}
	}
}

void print_digits_array(void) {
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < MAXDIGITS * 4; j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}
