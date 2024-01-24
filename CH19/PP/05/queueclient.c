#include "queue.h"
#include <stdio.h>

int main(void) {
  Queue q = create_queue();
  int n;

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);

  print_queue(q);

  n = dequeue(q);
  printf("n: %d\n", n);

  print_queue(q);

  printf("Get first: %d\n", get_first(q));
  printf("Get last: %d\n", get_last(q));

  destroy_queue(q);

  return 0;
}
