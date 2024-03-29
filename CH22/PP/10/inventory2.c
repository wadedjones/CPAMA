/* Maintains a parts database (linked list version) */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

/* Function Prototypes */
struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int read_line(char str[], int n);
void restore_file(void);
void dump_file(void);

int main(void) {
  char code;

  for (;;) {
    printf(
        "(r)estore, (d)ump, (i)nsert, (s)earch, (u)pdate, (p)rint, (q)uit\n");
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;
    switch (code) {
    case 'r':
      restore_file();
      break;
    case 'd':
      dump_file();
      break;
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'u':
      update();
      break;
    case 'p':
      print();
      break;
    case 'q':
      return 0;
    default:
      printf("Illegal code\n");
    }
  }

  return 0;
}

struct part *find_part(int number) {
  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next)
    ;
  if (p != NULL && number == p->number) {
    return p;
  }
  return NULL;
}

void insert(void) {
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    fprintf(stderr, "cannot add more parts, out of memory\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;

  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL) {
    inventory = new_node;
  } else {
    prev->next = new_node;
  }
}

void search(void) {
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update(void) {
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print(void) {
  struct part *p;

  printf("Part Number    Part Name                "
         "Quantity on hand\n");
  for (p = inventory; p != NULL; p = p->next) {
    printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
  }
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

void restore_file(void) {
  FILE *fp;
  char *filename;
  struct part *new_node, *cur, part;
  int num_read;

  printf("Enter name of input file: ");
  fgets(filename, 255, stdin);
  filename[strcspn(filename, "\n")] = 0;

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "Cannot open file %s\n", filename);
    return;
  }

  num_read = fread(&part, sizeof(struct part), 1, fp);

  while (num_read == 1) {
    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
      fprintf(stderr, "error importing part.\n");
      exit(EXIT_FAILURE);
    }
    strcpy(new_node->name, part.name);
    new_node->number = part.number;
    new_node->on_hand = part.on_hand;
    new_node->next = NULL;

    if (inventory == NULL) {
      inventory = new_node;
    } else {
      cur = inventory;
      while (cur->next != NULL) {
        cur = cur->next;
      }
      cur->next = new_node;
    }
    num_read = fread(&part, sizeof(struct part), 1, fp);
  }

  fclose(fp);
}

void dump_file(void) {
  FILE *fp;
  char *filename;
  struct part *p, part;

  printf("Enter name of output file: ");
  fgets(filename, 255, stdin);
  filename[strcspn(filename, "\n")] = 0;

  if ((fp = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "Cannot save file %s\n", filename);
    return;
  }

  for (p = inventory; p != NULL; p = p->next) {
    if (p != NULL) {
      part = *p;
      fwrite(&part, sizeof(struct part), 1, fp);
    }
  }

  fclose(fp);
}
