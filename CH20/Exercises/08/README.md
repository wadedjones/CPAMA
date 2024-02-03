#### 8. Let `f` be the following function:

```c
unsigned int f(unsigned int i, int m, int n) {
    return (i >> (m + 1 - n)) & ~(~0 << n);
}
```

> (a) What is the value of `~(~0 << n);`  
> (b) What does this function do?  

---

#### Answer:

> (a) Returns the right most `n` bits set to 1;  
> (b) Returns `n` bits starting at `m` inside `i`.  
