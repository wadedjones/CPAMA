#### 2. (C99) Write the following function:

```c
double evaluate_polynomial(double a[], int n, double x);
```

#### The function should return the value of the polynomial `a[n]x^n + a[n-1]x^n-1 + ... + a[0]` where the `a[i]`s are stored in corresponding elements of the array `a`, which has length `n + 1`. Have the function use Horner's Rule to compute the value of the polynomial:

`((...((a[n]x + a[n-1])x + a[n-2])x + ...)x + a[1])x + a[0]`

#### Use the `fma` function to perform the multiplications and additions.

---

#### Answer: lol

```c
double evaluate_polynomial(double a[], int n, double x) {
  int i;
  double sum = fma(a[n], x, a[n - 1]);
  for (i = n - 1; i >= 0; i--) {
    sum += fma(sum, x, a[i]);
  }

  return sum;
}
```
