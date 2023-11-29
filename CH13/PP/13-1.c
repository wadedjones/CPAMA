/* Write a program that finds the smallest and largest in a series of words.
 * After the user enters the words, the program will determine which words would
 * come first and last if the words were listed in dictionary order. The program
 * must stop accepting input when the user enters a four-letter word. Assume
 * that no word is more than 20 letters long. */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

int read_line(char str[], int n);

int main(void) {
  char smallest_word[MAX] = {0};
  char largest_word[MAX] = {0};
  char new_word[MAX] = {0};

  printf("Enter word: ");
  read_line(new_word, MAX);
  strcpy(smallest_word, new_word);
  strcpy(largest_word, new_word);

  while (true) {
    printf("Enter word: ");
    read_line(new_word, MAX);
    if (strlen(new_word) == 4)
      break;
    if (strcmp(new_word, smallest_word) < 0)
      strcpy(smallest_word, new_word);
    if (strcmp(new_word, largest_word) > 0)
      strcpy(largest_word, new_word);
  }

  printf("Smallest: %s\n", smallest_word);
  printf("Largest: %s\n", largest_word);

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != ' ') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
