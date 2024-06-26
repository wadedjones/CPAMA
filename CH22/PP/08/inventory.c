/* Maintains a parts database (array version) */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define FILENAME_LEN 255
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; /* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump_file(void);
void restore_file(void);

int main(void) {
  char code;

  for (;;) {
    printf(
        "(r)estore, (d)ump, (i)nsert, (s)earch, (u)pdate, (p)rint, (q)uit\n");
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
			case 'd': dump_file();
								break;
			case 'r': restore_file();
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

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  getchar(); /* remove newline from buffer */

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;

  printf("Enter part name: ");
  fgets(inventory[num_parts].name, NAME_LEN, stdin);
  inventory[num_parts].name[strcspn(inventory[num_parts].name, "\n")] = 0;

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

int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}

void dump_file(void) {
  char filename[FILENAME_LEN];
  printf("Enter name of output file: ");
  fgets(filename, FILENAME_LEN, stdin);
  filename[strcspn(filename, "\n")] = 0;

  FILE *fp;

  if ((fp = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "cannot save file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  fwrite(inventory, sizeof(struct part), num_parts, fp);

  fclose(fp);
}

void restore_file(void) {
  char filename[FILENAME_LEN];
  printf("Enter name of input file: ");
  fgets(filename, FILENAME_LEN, stdin);
  filename[strcspn(filename, "\n")] = 0;

  FILE *fp;

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);

  fclose(fp);
}
