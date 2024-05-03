#### 9. Write a function that returns a random `double` value `d` in the range 0.0 <= `d` < 1.0.

---

#### Answer:

```c
double random_double(void) {
    return (double)(rand() % 100) * .01;
}
```
