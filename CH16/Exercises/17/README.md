#### 17. Suppose that `b` and `i` are declared as follows:

```c
enum {FALSE, TRUE} b;
int i;
```

#### Which of the following statements are legal? Which ones are "safe" (always yield a meaningful result)?

> (a) b = FALSE;  
> (b) b = i;  
> (c) b++;  
> (d) i = b;  
> (e) i = 2 * b + 1;  

---

#### Answer:

> (a) Legal and safe.  
> (b) Legal, but if `i` were larger than 1, result would not be meaningful.  
> (c) Legal, but if `b` were incremented passed 1, result would not be meaningful.  
> (d) Legal and safe.  
> (e) Legal and safe.  
