/* Write the following function:
 * void swap(int *p, int *q);
 * When passed the addresses of two variables, swap should exchange the values
 * of the variables. */

void swap(int *p, int *q) {
  int temp;
  temp = *q;
  *q = *p;
  *p = temp;
}
