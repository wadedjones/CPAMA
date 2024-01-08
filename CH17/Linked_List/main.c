#include "linked_list.h"
#include <stdlib.h>

int main(void) {
  struct node *list = NULL;

  insert_into_ordered_list2(&list, &(struct node){10, NULL});
  insert_into_ordered_list2(&list, &(struct node){20, NULL});
  insert_into_ordered_list2(&list, &(struct node){30, NULL});
  insert_into_ordered_list2(&list, &(struct node){15, NULL});

  print_linked_list(list);

  delete_from_list2(&list, 60);

  print_linked_list(list);

  return 0;
}
