#### 7. Explain the meaning of the following statement, assuming that `value` is a variable of type `long int` and `p` is a variable of type `char *`:

```c
value = strtol(p, &p, 10);
```

---

#### Answer: `strtol` points to `p` and converts it from `char *` to base 10 `long int` and stores it in `value`.
