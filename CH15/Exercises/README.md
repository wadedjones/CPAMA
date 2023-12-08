#### 1. Section 15.1 listed several advantages of dividing a program into multiple source files.

> (a) Describe several other advantages.  
> (b) Describe some disadvantages.  

#### Answer:

> (a) Easier to debug files. Easier to make small changes to functions etc...  
> (b) Complexity can increase. Bad file management can cause confusion.

---

#### 2. Which of the following should not be put in a header file? Why not?

> (a) Function prototypes  
> (b) Function definitions  
> (c) Macro definitions  
> (d) Type definitions  

#### Answer:

> (b) Functions definitions should not be in a header file. If two files use the function, the linker might think the function is defined twice, and the files cannot be linked.  

---

#### 3. We saw that writing `#include <file>` instead of `#include "file"` may not work if the file is one that we've written. Would there be any problem with writing `#include "file"` instead of `#include <file>` if the file is a system header?

#### Answer:

> There should be no issue, as after the compiler searches for what it thinks is our file, it will then search the system files.  

---

#### 4. Assume that `debug.h` is a header file with the following contents:

```c
#ifdef DEBUG
#define PRINT_DEBUG(n) printf("VAlue of " #n ": %d\n", n)
#else
#define PRINT_DEBUG(n)
#endif
```

#### Let `testdebug.c` be the following source file:

```c
#include <stdio.h>

#define DEBUG
#include "debug.h"

int main(void) {
    int i = 1, j = 2, k = 3;

    #ifdef DEBUG
    printf("Output if DEBUG is defined:\n");
    #else
    printf("Output if DEBUG is not defined:\n");
    #endif

    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i + j);
    PRINT_DEBUG(2 * i + j - k);

    return 0;
}
```

> (a) What is the output when the program is executed?  
> (b) What is the output if the `#define` directive is removed from `testdebug.c`?  
> (c) Explain why the output is different in parts (a) and (b).  
> (d) Is it necessary for the `DEBUG` macro to be defined *before* `debug.h` is included in order for `PRINT_DEBUG` to have the desired effect?  

#### Answer:

> (a)  
```c
Output if DEBUG is defined:
Value of i: 1
Value of j: 2
Value of k: 3
Value of i + j: 3
Value of 2 * i + j - k: 1
```
> (b)  
```c
Output if DEBUG is not defined:
```
> (c) When debug is defined, the first if statement in the header file executes, otherwise, the second statement executes.  
> (d) If the macro is defined after, the header file doesn't know about the define, and the `else` statement will be executed.  

---

#### 5. Suppose that a program consists of three source files--`main.c`, `f1.c`, and `f2.c`--plus two header files, `f1.h` and `f2.h`. All three soure files include `f1.h`, but only `f1.c` and `f2.c` include `f2.h`. Write a makefile for this program, assuming that the compmiler is `gcc` and that the executable file is to be named `demo`.

#### Answer: See Makefile

---

#### 6. The following questions refer to the program described in Exercise 5.

> (a) Which files need to be compiled when the program is built for the first time?  
> (b) If `f1.c` is changed after the program has been built, which files need to be recompiled?  
> (c) If `f1.h` is changed after the program has been built, which files need to be recompiled?  
> (d) If `f2.h` is changed after the program has been built, which files need to be recompiled?  

#### Answer:

> (a) `main.c`, `f1.c`, and `f2.c` need to be compiled.  
> (b) `f1.c` is the only file to be recompiled.  
> (c) All three files need recompiling.  
> (d) Only `f1.c` and `f2.c` need recompiling.  
