#### 12. Suppose that `u` is the following union:

```c
union {
    double a;
    struct {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} u;
```

#### If `char` values occupy one byte, `int` values occupy four bytes, and `double` values occupy eight bytes, how much space will a C compiler allocate fo `u`? (Assume that the compiler leaves no "holes" between members).

---

#### Answer: 16 bytes. The struct `e` contains the most amount of space.
