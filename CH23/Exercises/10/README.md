#### 10. Replace the test condition in the following `if` statement by a single call of `strstr`:

```c
if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 || strcmp(str, "baz") == 0)
```

---

#### Answer:

```c
if (strstr("foo#bar#baz", str) != NULL)
```
