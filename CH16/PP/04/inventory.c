/* Maintains a parts database (array version) */

#include "inventory.h"
#include "readline.h"
#include <stdio.h>

int find_part(struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

int main(void) {
  char code;
  struct part inventory[MAX_PARTS];

  int num_parts = 0; /* number of parts currently stored */

  for (;;) {
    printf("i(nsert) s(earch) u(pdate) p(rint) q(uit)\n\n");
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;
    // clang-format off
    switch (code) {
			case 'i': insert(inventory, &num_parts);
								break;
			case 's': search(inventory, num_parts);
								break;
			case 'u': update(inventory, num_parts);
								break;
			case 'p': print(inventory, num_parts);
								break;
			case 'q': return 0;
			defualt: printf("Illegal code\n");
    }
		printf("\n");
  }
}

// clang-format on

/* find_part: Looks up a part number in the inventory array. Returns the array
 * index if the part number is found. Otherwise returns -1. */

int find_part(struct part inventory[], int num_parts, int number) {
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/* insert: Prompts user for info about a new part and then inserts the part into
 * the database. Prints an error message and returns prematurely if the part
 * already exists or the database is full. */

void insert(struct part inventory[], int *num_parts) {
  int part_number;

  if (*num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(inventory, *num_parts, part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[*num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[*num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[*num_parts].on_hand);
  printf("Enter price: ");
  scanf("%lf", &inventory[*num_parts].price);
  (*num_parts)++;
}

/* search: Prompts user to enter a part number, then looks up the part in the
 * database. If the part exists, prints the name and quantity on hand; if not,
 * prints an error message. */

void search(struct part inventory[], int num_parts) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(inventory, num_parts, number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
    printf("Price: %.2lf\n", inventory[i].price);
  } else {
    printf("Part not found.\n");
  }
}

/* update: Prompts user to enter a part number. Prints an error message if the
 * part doesn't exist; otherwise, prompts the user to enter change in quantity
 * on hand and updates the database. */

void update(struct part inventory[], int num_parts) {
  int i, number, change;
  double price;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(inventory, num_parts, number);
  if (i >= 0) {
    printf("Part Number: %d\n", inventory[i].number);
    printf("Part Name: %s\n", inventory[i].name);
    printf("Part Quantity: %d\n", inventory[i].on_hand);
    printf("Part Price: %.2lf\n", inventory[i].price);
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
    printf("Enter change in price: (0 to keep price) ");
    scanf("%lf", &price);
    if (!price) {
      return;
    } else {
      inventory[i].price = price;
    }
  } else {
    printf("Part not found.\n");
  }
}

/* print: Prints a listing of all parts in the database, showing the part
 * number, part name, and quantity on hand. Parts are printed in the order in
 * which they were entered into the database. */

void print(struct part inventory[], int num_parts) {
  int i;

  quicksort(inventory, 0, num_parts - 1);

  printf("Part Number    Part Name            Quantity on Hand   Price\n");
  for (i = 0; i < num_parts; i++)
    printf("%11d    %-25s%12d   $%8.2lf\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand, inventory[i].price);
}
