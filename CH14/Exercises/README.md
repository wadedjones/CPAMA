#### 1. Write a parameterized macros that compute the following values.

> (a) The cube of x.  
> (b) The remainder when n is divided by 4.  
> (c) 1 if the product of x and y is less than 100, 0 otherwise.  

#### Answer:

> (a) `#define CUBE(x) ((x)*(x)*(x))`  
> (b) `#define REMAINDER(n) ((n)%4)`  
> (c) `#define PRODUCT(x,y) ((x)*(y)<100?1:0)`

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

> (a) What is the value of `DOUBLE(1+2)`?  
> (b) What is the value of `4/DOUBLE(2)`?  
> (c) Fix the definition of `DOUBLE`  

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

#### 7. Let `GENERIC_MAX` be the following macro:

```c
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}                               \
```

> (a) Show the preprocessor's expansion of `GENERIC_MAX(long)`.  
> (b) Explain why `GENERIC_MAX` doesn't work for basic types such as `unsigned long`.  
> (c) Describe a technique that would allow us to use `GENERIC_MAX` with basic types such as `unsigned long`. *Hint:* Don't change the definithion of `GENERIC_MAX`.  

#### Answer:

> (a)  

```c
long long_max(long x, long y) {
    return x > y ? x : y;
}
```

> (b) Unsigned long requires two words, which would prevent us from using the correct function name.  
> (c)  Create a `typedef unsigned long ULONG;` resulting in `GENERIC_MAX(ULONG)`  

---

#### 8. Suppose we want a macro that expands into a string containing the current line number and file name. In other words, we'd like to write:  

`const char *str = LINE_FILE;`  

#### and have it expand into

`const char *str = "Line 10 of file foo.c";`

#### Where `foo.c` is the file containing the program and `10` is the line on which the invocation of `LINE_FILE` appears. *Warning:* This exercise is for experts only. Be sure to read Q&A before attempting!

#### Answer:

```c
#define STRINGIZE(x) #x
#define EXPAND(x) STRINGIZE(x)
#define LINE_FILE ("Line " EXPAND(__LINE__) " of file " __FILE__)
```

---

#### 9. Write the following parameterized macros.

> (a) `CHECK(x,y,n)` - Has the value 1 if both x and y fall between 0 and n - 1, inclusive.  
> (b) `MEDIAN(x,y,z)` - Finds the median of x, y, and z.  
> (c) `POLYNOMIAL(x)` - Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6.  

#### Answer:

> (a)  

```c
#define CHECK(x,y,n) ((x)>0&&(x)<(n)-1&&(y)>0&&(y)<(n)-1?1:0)
```

> (b)  

```c
#define MEDIAN(x,y,z) ((x)<(y)&&(y)<(z)?(y): \
                       (x)<(z)&&(z)<(y)?(z): \
                       (y)<(x)&&(x)<(z)?(x): \
                       (y)<(z)&&(z)<(x)?(z): \
                       (z)<(x)&&(x)<(y)?(x): (y))
```

> (c)  

```c
#define POLYNOMIAL(x) ((3*((x)*(x)*(x)*(x)*(x))) + \
                       (2*((x)*(x)*(x)*(x))) - \
                       (5*((x)*(x)*(x))) - \
                       ((x)*(x)) + \
                       (7*(x)) - 6)
```

---

#### 10. Functions can often--but not always--be written as parameterized macros. Discuss what characteristics of a function would make it unsuitable as a macro.  

#### Answer: Recursive functions, and functions which have side effects, are not suitable as macros.

---

#### 11. (C99) C programmers often use the `fprintf` function to write error messages:

```c
fprintf(stderr, "Range error: index = %d\n", index);
```

#### `stderr` is C's "standard error" stream; the remaining arguments are the same as those for printf, starting with the format string. Write a macro named `ERROR` that generates the call of `fprintf` shown above when given a format string and the items to be displayed:

```c
ERROR("Range error: index = %d\n", index);
```

#### Answer:

```c
#define ERROR(s,...) (fprintf(stderr, (s), __VA_ARGS__))
```

---

#### 12. Suppose that the macro `M` has been defined as follows:

```c
#define M 10
```

#### Which of the following tests will fail?  

> (a) `#if M`  
> (b) `#ifdef M`  
> (c) `#ifndef M`  
> (d) `#if defined(M)`  
> (e) `#if !defined(M)`  

#### Answer:

> Both (c) and (e) will fail, since `M` is defined.  

---

#### 13.
#### (a) Show what the following program will look like after preprocessing. You may ignore any lines added to the program as a result of including the `<stdio.h>` header.

```c
#include <stdio.h>

#define N 100

void f(void);

int main(void) {
    f();
    #ifdef N
    #undef N
    #endif
    return 0;
}

void f(void) {
    #if defined(N)
    printf("N is %d\n", N);
    #else
    printf("N is undefined\n");
    #endif
}
```

#### (b) What will be the output of this program?

#### Answer:

> (a)  

```c
void f(void);

int main(void) {
    f();
    return 0;
}

void f(void) {
    printf("N is undefined\n");
}
```

> (b) The output is `N is undefined`  

---
