#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void make_empty(struct node **top);
bool is_empty(struct node **top);
void stack_overflow(void);
void stack_underflow(void);
bool push(int i, struct node **top);
struct node *pop(struct node **top);
void print_list(struct node *top);
int count_occurrences(struct node *list, int n);
struct node *find_last(struct node *list, int n);
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

#endif
