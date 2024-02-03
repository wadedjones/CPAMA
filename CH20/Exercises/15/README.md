#### 15. (a) Assume that the variable `s` has been declared as follows:

```c
struct {
    int flag: 1;
} s;
```

#### With some compilers, executing the following statements causes 1 to be displayed, but with other compilers, the output is -1. Explain the reason for this behavior.

```c
s.flag = 1;
printf("%d\n", s.flag);
```

#### (b) How can this problem be avoided?

---

#### Answer:

> (a) If a compiler is little endian, the `flag` variable acts as the signed bit (1 for negative numbers).  
> (b) Avoid this problem by declaring `flag` as an `unsigned int`.
