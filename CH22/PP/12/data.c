#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_INPUT 1024

struct item {
  int number;
  float price;
  char date[11];
};

void print_info(struct item *item_list, int total_items);
void get_data(FILE *fp, struct item *item_list, char *buf, int *total_items);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: data <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char *filename = argv[1];
  struct item item_list[MAX_ITEMS] = {0};
  char buf[MAX_INPUT];
  int total_items = 0;

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  get_data(fp, item_list, buf, &total_items);

  print_info(item_list, total_items);

  return 0;
}

void print_info(struct item *item_list, int total_items) {
  printf("Item\t\tUnit\t\tPurchase\n");
  printf("    \t\tPrice\t\tDate\n");
  for (int i = 0; i < total_items; i++) {
    printf("%d\t\t", item_list[i].number);
    printf("$%7.2f\t", item_list[i].price);
    printf("%s\n", item_list[i].date);
  }
}

void get_data(FILE *fp, struct item *item_list, char *buf, int *total_items) {

  int i = 0;

  while (fgets(buf, MAX_INPUT, fp)) {
    buf[strcspn(buf, "\n")] = 0;
    sscanf(buf, "%d%*[,]%f%*[,]%[0-9/0-9/0-9]", &item_list[i].number,
           &item_list[i].price, item_list[i].date);
    i++;
    (*total_items)++;
  }
}
