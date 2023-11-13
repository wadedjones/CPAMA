/* The following function is supposed to return true if any element of the array
 * a has the value 0, and false if all elements are nonzero. Sadly, it contains
 * an error: fix it.
 */

#include <stdbool.h>

bool has_zero_ERR(int a[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (a[i] == 0) {
      return true;
    } else {
      return false;
    }
  }
}

bool has_zero(int a[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (a[i] == 0) {
      return true;
    }
  }
  return false;
}
