#### 12. (a) Write a complete description of the type of the function `f`, assuming that it's declared as follows:

```c
int (*f(float (*)(long), char *))(double);
```

#### (b) Give an example showing how `f` would be called.

---

#### Answer:

> (a) `f` is a pointer to a function that takes two arguments. A pointer to a function that takes `long` as an argument and returns a `float`, and a pointer to a char. The function returns a pointer to a function that takes `double` as an argument and returns `int`.    

> (b) `int n = *f(long, &char)(double);`  
