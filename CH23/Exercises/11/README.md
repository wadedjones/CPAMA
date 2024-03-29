#### 11. Write a call of `memset` that replaces the last `n` characters in a null-terminated string `s` with `!` characters.

---

#### Answer:

```c
memset(str + n, '!', sizeof(str) - n - 1);
```
