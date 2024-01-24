#include "queue.h"
#include <stdio.h>

int main(void) {
  Queue q = create_queue();

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);

  print_queue(q);

  Item n;

  n = dequeue(q);
  printf("n: %d\n", n);
  n = dequeue(q);
  printf("n: %d\n", n);
  n = get_first(q);
  printf("n: %d\n", n);
  n = get_last(q);
  printf("n: %d\n", n);

  print_queue(q);
  n = dequeue(q);
  printf("n: %d\n", n);
  n = dequeue(q);
  printf("n: %d\n", n);
  n = get_first(q);
  printf("n: %d\n", n);
  n = get_last(q);
  printf("n: %d\n", n);

  destroy_queue(q);

  return 0;
}
