/* Write a program that asks the user to enter a series of integers
 * (which it stores in an array), then sorts the integers by calling the
 * function selection_sort. When given an array with n elements, selection_sort
 * must do the follwing:
 * 1. Search the array to find the largest element, then move it to the last
 * 		position in the array.
 * 2. Call itself recursively to sort the first n-1 elements of the array. */

#include <stdio.h>

#define MAX_INTS 20

void selection_sort(int a[], int n);

int main(void) {
  int user_input[MAX_INTS] = {0};
  int i = 0;

  printf("Enter up to 20 integers: ");

  for (i = 0; i < MAX_INTS; i++) {
    scanf("%d", &user_input[i]);
    if ((getchar()) == '\n') {
      i++;
      break;
    }
  }

  selection_sort(user_input, i);

  for (i = 0; i < MAX_INTS; i++) {
    printf("%d ", user_input[i]);
  }

  printf("\n");

  return 0;
}

void selection_sort(int a[], int n) {
  if (n == 0)
    return;

  int largest, temp, i;
  largest = temp = 0;

  for (i = 0; i < n; i++) {
    if (a[i] > a[largest]) {
      largest = i;
    }
  }
  temp = a[largest];
  a[largest] = a[n - 1];
  a[n - 1] = temp;

  selection_sort(a, n - 1);
}
