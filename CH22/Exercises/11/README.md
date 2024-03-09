#### 11. The following loop appears in the `fcopy.c` program:

```c
while ((ch = getc(source_fp)) != EOF)
    putc(ch, dest_fp);
```

#### Suppose that we neglected to put parentheses around `ch = getc(source_fp)`:

```c
while (ch = getc(source_fp) != EOF)
    putc(ch, dest_fp);
```

#### Would the program compile without an error? If so, what would the program do when it's run?

---

#### Answer: `!=` has precedence over assignment `=`, so `ch` should evaluate to `true` (1) for each character in `source_fp`.
