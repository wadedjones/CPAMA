#### 1. Write a parameterized macros that compute the following values.

> (a) The cube of x.  
> (b) The remainder when n is divided by 4.  
> (c) 1 if the product of x and y is less than 100, 0 otherwise.  

#### Answer:

> (a) `#define CUBE(x) (x*x*x)`  
> (b) `#define REMAINDER(n) (n%4)`  
> (c) `#define PRODUCT(x,y) (x*y<100?1:0)`

---

#### 2. Write a macro `NELEMS(a)` that computes the number of elements in a one-dimensional array a. *HINT:* See the discussion of the `sizeof` operator in section 8.1.

#### Answer:

```c
#define NELEMS(a) ((int) (sizeof(a)/sizeof(a[0])))
```

---

#### 3. Let `DOUBLE` be the following macro:

```c
#define DOUBLE(x) 2*x
```

> (a) What is the value of DOUBLE(1+2)?  
> (b) What is the value of 4/DOUBLE(2)?  
> (c) Fix the definition of DOUBLE  

#### Answer:

> (a) `4`  
> (b) `4`  
> (c) `#define DOUBLE(x) ((2)*(x))`  

---

#### 4. For each of the following macros, give an example that illustrates a problem with the macro and show how to fix it.

> (a) `#define AVG(x,y) (x+y)/2`  
> (b) `#define AREA(x,y) (x)*(y)`  

#### Answer:

> (a) The parenthesis should also surround the `/2` and each parameter.  
> `#define AVG(x,y) (((x)+(y))/2)`  
> (b) Again, parenthesis around the whole thing and each parameter.  
> `#define AREA(x,y) ((x)*(y))`  

---

#### 5. Let `TOUPPER` be the following macro:

```c
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
```

> Let s be a string and let i be an int variable. Show the output produced by each of the following program fragments.  
> (a)
```c
strcpy(s, "abcd");
i = 0;
putchar(TOUPPER(s[++i]));
```

> (b)
```c
strcpy(s, "0123");
i = 0;
putchar(TOUPPER(s[++i]));
```

#### Answer:

> (a) `D`  
> (b) `2`  

---

#### 6. Write a macro 

> (a) `DISP(f,x)` that expands into a call of `printf` that displays the value of the function `f` when called with argument x.  
> (b) `DISP2(f,x,y)` that's similar to `DISP` but works for functions with two arguments.  

#### Answer:

> (a)  

```c
#define DISP(f,x) printf(#f "(%g) = %g\n", (x), (f(x)))
```

> (b)  

```c
#define DISP2(f,x,y) printf(#f "(%g, %g) = %g\n", (x), (y), (f((x),(y))))
```

---
