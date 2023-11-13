/* Write a program that simulates the game of craps. */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wctype.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
  srand((unsigned)time(NULL));
  int wins, losses;
  char play;

  wins = losses = 0;

  printf("A Game of Craps!\n");
  printf("Your roll...\n");

  while (true) {
    if (play_game()) {
      wins++;
    } else {
      losses++;
    }
    printf("Play again? ");
    scanf(" %c", &play);
    if (play != 'y' && play != 'Y') {
      break;
    } else {
      continue;
    }
  }

  printf("Wins: %d, Losses: %d\n", wins, losses);

  return 0;
}

int roll_dice(void) {
  int num1, num2;
  num1 = rand() % 6 + 1;
  num2 = rand() % 6 + 1;

  return num1 + num2;
}

bool play_game(void) {
  bool game = false;
  int dice_roll, point_roll;

  dice_roll = roll_dice();
  point_roll = 0;
  printf("You rolled: %d\n", dice_roll);
  printf("Your point is %d\n", dice_roll);

  if (dice_roll == 7 || dice_roll == 11) {
    printf("You win!\n");
    game = true;
    return game;
  } else if (dice_roll == 2 || dice_roll == 3 || dice_roll == 12) {
    printf("You lose!\n");
    game = false;
    return game;
  } else {
    while (true) {
      point_roll = roll_dice();
      printf("You rolled: %d\n", point_roll);
      if (point_roll == dice_roll) {
        printf("You win!\n");
        game = true;
        break;
      } else if (point_roll == 7) {
        printf("You lose!\n");
        game = false;
        break;
      }
    }
  }

  return game;
}
