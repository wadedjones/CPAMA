#### 4. (a) Write a "wrapper" function named `try_math_fcn` that calls a math function (assumed to have a `double` argument and return a `double` value) and then checks whether the call succeeded. Here's how we might use `try_math_fcn`:

```c
y = try_math_fcn(sqrt, x, "Error in call of sqrt");
```

#### If the call `sqrt(x)` is successful, `try_math_fcn` returns the value computed by `sqrt`. If the call fails, `try_math_fcn` calls `perror` to print the message "Error in call of sqrt", then calls `exit` to terminate the program.

#### (b) Write a macro that has the same effect as `try_math_fcn` but builds the error message from the function's name:

```c
y = TRY_MATH_FNC(sqrt, x);
```

#### If the call of `sqrt` fails, the message will be "Error in call of sqrt".

---

#### Answer:

> (a)  

```c
double try_math_fnc(double (*func)(double), double x, char *msg) {
    errno = 0;
    double result = (*func)(x);
    if (errno != 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    } else {
        return result;
    }
}
```

> (b)  

```c
#define TRY_MATH_FCN(f, x) try_math_func(f, x, "Error in call of " #f)
```
