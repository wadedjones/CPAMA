#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
  int value;
  struct node *next;
};

struct node *add_to_list(struct node *list, int n);
void add_to_list2(struct node **list, int n);
struct node *add_to_end(struct node *list, int n);
void add_to_end2(struct node **list, int n);
struct node *search_list_a(struct node *list, int n);
struct node *search_list_b(struct node *list, int n);
struct node *search_list_c(struct node *list, int n);
struct node *search_list_d(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
void delete_from_list2(struct node **list, int n);
void print_linked_list(struct node *list);
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);
int count_occurrences(struct node *list, int n);
struct node *find_last(struct node *list, int n);
void insert_into_ordered_list2(struct node **list, struct node *new_node);
#endif
