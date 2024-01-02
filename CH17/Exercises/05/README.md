#### 5. Suppose that `f` and `p` are declared as follows:

```c
struct {
    union {
        char a, b;
        int c;
    } d;
    int e[5];
} f, *p = &f;
```

#### Which of the following statements are legal?

> (a) `p->b = ' ';`  
> (b) `p->e[3] = 10;`  
> (c) `(*p).d.a = '*';`  
> (d) `p->d->c = 20;`  

---

#### Answer:

> (a) Illegal. `p->d.b = ' ';`  
> (b) Legal.  
> (c) Legal.  
> (d) Illegal. `p->d.c = 20;`  
