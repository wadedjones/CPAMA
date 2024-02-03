#### 9. (a) Write the following function:

```c
int count_ones(unsigned char ch);
```

#### `count_ones` should return the number of 1 bits in `ch`.

#### (b) Write the function in part (a) without using a loop.

---

#### Answer:

> (a)  

```c
int count_ones(unsigned char ch) {
    int count = 0;
    
    while (ch > 0) {
        if (ch % 2 == 1) {
            count ++;
        }
        ch = ch >> 1;
    }
    return count;
}
```

> (b)  

```c
int count_ones(unsigned char ch) {
    if (ch == 0) return 0;

    return count_ones(ch & ch - 1) + 1;
}
```
