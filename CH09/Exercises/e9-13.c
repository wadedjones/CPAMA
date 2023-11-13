/* Write the following function, which evaluates a chess position:
 * int evaluate_position(char board[8][8]);
 */

#include <stdio.h>

int evaluate_position(char board[8][8]);

int main(void) {
  char board[8][8] = {
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
  };

  char board_2[8][8] = {
      {'R', '0', '0', 'Q', 'K', 'B', 'N', 'R'},
      {'P', '0', '0', 'P', 'P', 'P', 'P', 'P'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', 'P', '0', '0', '0', 'p', '0'},
      {'0', 'p', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', 'p', 'p', '0', '0', 'p'},
      {'0', '0', '0', 'q', 'k', '0', 'n', 'r'},
  };

  int result;

  result = evaluate_position(board_2);

  printf("%d\n", result);

  return 0;
}

int evaluate_position(char board[8][8]) {
  int i, j;
  int white, black;
  white = black = 0;

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      switch (board[i][j]) {
      case 'Q':
        white += 9;
        break;
      case 'q':
        black += 9;
        break;
      case 'R':
        white += 5;
        break;
      case 'r':
        black += 5;
        break;
      case 'B':
      case 'N':
        white += 3;
        break;
      case 'b':
      case 'n':
        black += 3;
        break;
      case 'P':
        white += 1;
        break;
      case 'p':
        black += 1;
        break;
      default:
        break;
      }
    }
  }
  return white - black;
}
