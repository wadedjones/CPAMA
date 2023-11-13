/* Write a function gcd(m, n) that calculates the greatest common divisor
 * of the integers m and n. */

int gcd(int m, int n) {
  int tmp;

  while (n > 0) {
    tmp = m % n;
    m = n;
    n = tmp;
  }

  return m;
}
