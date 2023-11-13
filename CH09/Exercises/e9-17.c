/* Rewrite the fact function so it's no longer recursive
 */

int fact_original(int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact_original(n - 1);
}

int fact_non_r(int n) {
  int i, result;
  result = 1;

  for (i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

#include <stdio.h>

int main(void) {
  int n = 10, result, result2;

  result = fact_non_r(n);
  result2 = fact_original(n);

  printf("result: %d\n", result);
  printf("result2: %d\n", result2);

  return 0;
}
