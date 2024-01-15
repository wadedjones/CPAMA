#### 8. Write a complete description of the type of `x` as specified by each of the following declarations.

> (a) `char (*x[10])(int);`  
> (b) `int (*x(int))[5];`  
> (c) `float *(*x(void))(int);`  
> (d) `void (*x(int, void (*y)(int)))(int);`  

---

#### Answer:

> (a) `x` is an array of ten pointers to functions which take an `int` argument and return a `char`.  
> (b) `x` is a function that returns a pointer to an array of five `int`s.  
> (c) `x` is a function that takes no arguments and returns a pointer to a function with an `int` argument that returns a pointer to a `float`.  
> (d) `x` is a function with two arguments. The first is an `int`, the second is another function that takes an `int` argument with no return value. `x` returns a pointer to a function that takes an `int` argument and doesn't return anything.  
