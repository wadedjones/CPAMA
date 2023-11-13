/* Condense the fact function the same way we condensed power
 */

// original fact function:
int fact_original(int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact_original(n - 1);
}

int fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }
