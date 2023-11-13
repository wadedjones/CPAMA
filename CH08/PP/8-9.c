/* Write a program that generates a "random walk" across a 10 x 10 array.
 * The array will contain characters (all '.' initially). The program must
 * randomly "walk" from element to element, always going up, down, left, right by one element.
 */

// ASCII 'A' = 65, 'Z' = 90

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 10

int main(void)
{
	char grid[MAX][MAX] = {{'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'},
												 {'.','.','.','.','.','.','.','.','.','.'}};
	char abc = 65;
	int i, j, move;
	bool flag = true;

	srand((unsigned) time(NULL));
/*
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf(" %c", grid[i][j]);
		}
		printf("\n");
	}
*/

	i = j = 0;
	grid[i][j] = abc;

	for (;abc < 90;) {
		move = rand() % 4;

		if (move == 0 && j > 0 && grid[i][j - 1] == '.') {
			grid[i][--j] = ++abc;
		} else if (move == 1 && i > 0 && grid[i - 1][j] == '.') {
			grid[--i][j] = ++abc;
		} else if (move == 2 && j < MAX - 1 && grid[i][j + 1] == '.') {
			grid[i][++j] = ++abc;
		} else if (move == 3 && i < MAX - 1 && grid[i + 1][j] == '.') {
			grid[++i][j] = ++abc;
		} else if (grid[i - 1][j] != '.' &&
				grid[i + 1][j] != '.' &&
				grid[i][j - 1] != '.' &&
				grid[i][j + 1] != '.') {
			break;
		} else {
			continue;
		}
	}

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf(" %c", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}
