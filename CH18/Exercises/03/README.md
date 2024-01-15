#### 3. List the storage duration (static or auto), scope (block or file), and linkage (internal, external, or none) of each variable and parameter in the following file:

```c
extern float a;

void f(register double b) {
    static int c;
    auto char d;
}
```

---

#### Answer: `a` has static storage, file scope, and external linkage. `b` has auto storage, block scope, and no linkage. `c` has static duration, block scope, and no linkage. `d` has auto storage, block scope, and no linkage.
