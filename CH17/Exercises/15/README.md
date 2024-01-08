#### 15. Show the output of the following program and explain what it does.

```c
#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void) {
  printf("Answer: %d\n", f1(f2));
  return 0;
}

int f1(int (*f)(int)) {
  int n = 0;
  while ((*f)(n)) {
    printf("n: %d\n", n);
    n++;
  }
  return n;
}

int f2(int i) { return i * i + i - 12; }
```

---

#### Answer: The result is 3. `f1` calls the pointer to `f2` and runs the while loop until `f2` returns 0, and `n` is equal to 3.
