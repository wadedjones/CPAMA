#### 9. Replace the test condition in the following `if` statement by a single call of `strchr`:

```c
if (ch == 'a' || ch == 'b' || ch == 'c')
```

---

#### Answer:

```c
if (strchr("abc", ch) != NULL)
```
