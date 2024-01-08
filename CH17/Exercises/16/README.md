#### 16. Write the following function. The call `sum(g, i, j)` should return `g(i) + ... + g(j)`.

```c
int sum(int (*f)(int), int start, int end);
```

---

#### Answer:

```c
int sum(int (*f)(int), int start, int end) {
    int sum = 0;
    while (start <= end) {
        sum += (*f)(start);
        start++;
    }
    return sum;
}
```
