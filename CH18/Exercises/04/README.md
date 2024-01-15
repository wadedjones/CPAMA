#### 4. Let `f` be the following function. What will be the value of `f(10)` if `f` has never been called before? What will be the value of `f(10)` if `f` has been called five times previously?

```c
int f(int i) {
    static int j = 0;
    return i * j++;
}
```

---

#### Answer: The first call of `f(10)` will be `0`. After five calls, the result will be `50`.
