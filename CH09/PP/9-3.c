/* Modify PP 9 from chapter 8 so that it includes the following functions:
 * 1. void generate_random_walk(char walk[10][10])
 * 2. void print_array(char walk[10][10]) */

// ASCII 'A' = 65, 'Z' = 90

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void) {
  char walk[10][10];

  generate_random_walk(walk);
  print_array(walk);

  return 0;
}

void generate_random_walk(char walk[10][10]) {
  int i, j, move;
  char abc = 65;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      walk[i][j] = '.';
    }
  }
  srand((unsigned)time(NULL));
  i = j = 0;
  walk[i][j] = abc;

  for (; abc < 90;) {
    move = rand() % 4;

    if (move == 0 && j > 0 && walk[i][j - 1] == '.') {
      walk[i][--j] = ++abc;
    } else if (move == 1 && i > 0 && walk[i - 1][j] == '.') {
      walk[--i][j] = ++abc;
    } else if (move == 2 && j < MAX - 1 && walk[i][j + 1] == '.') {
      walk[i][++j] = ++abc;
    } else if (move == 3 && i < MAX - 1 && walk[i + 1][j] == '.') {
      walk[++i][j] = ++abc;
    } else if (walk[i - 1][j] != '.' && walk[i + 1][j] != '.' &&
               walk[i][j - 1] != '.' && walk[i][j + 1] != '.') {
      break;
    } else {
      continue;
    }
  }
}

void print_array(char walk[10][10]) {
  int i, j;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf(" %c ", walk[i][j]);
    }
    printf("\n");
  }
}
