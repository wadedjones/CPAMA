/* Maintains a parts database (array version) */

#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX 10

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

struct part *inventory;
int num_parts = 0; /* number of parts currently stored */
int max_parts = MAX;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
  inventory = malloc(sizeof(struct part) * max_parts);
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;
    // clang-format off
    switch (code) {
			case 'i': insert();
								break;
			case 's': search();
								break;
			case 'u': update();
								break;
			case 'p': print();
								break;
			case 'q': return 0;
			default: printf("Illegal code\n");
    }
		printf("\n");
  }
}

// clang-format on

/* find_part: Looks up a part number in the inventory array. Returns the array
 * index if the part number is found. Otherwise returns -1. */

int find_part(int number) {
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/* insert: Prompts user for info about a new part and then inserts the part into
 * the database. Prints an error message and returns prematurely if the part
 * already exists or the database is full. */

void insert(void) {
  int part_number;

  if (num_parts == max_parts) {
    max_parts *= 2;
    struct part *temp = realloc(inventory, (sizeof(struct part) * max_parts));
    if (temp == NULL) {
      printf("No more memory, realloc failed.\n");
      return;
    }
    inventory = temp;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/* search: Prompts user to enter a part number, then looks up the part in the
 * database. If the part exists, prints the name and quantity on hand; if not,
 * prints an error message. */

void search(void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

/* update: Prompts user to enter a part number. Prints an error message if the
 * part doesn't exist; otherwise, prompts the user to enter change in quantity
 * on hand and updates the database. */

void update(void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

/* print: Prints a listing of all parts in the database, showing the part
 * number, part name, and quantity on hand. Parts are printed in the order in
 * which they were entered into the database. */

void print(void) {
  int i;
  printf("Part Number    Part Name            Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d        %-25s%11d\n", inventory[i].number, inventory[i].name,
           inventory[i].on_hand);
}
