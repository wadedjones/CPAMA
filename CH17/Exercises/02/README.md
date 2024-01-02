#### 2. Write a function named `duplicate` that uses dynamic storage allocation to create a copy of a string. For example, the call `p = duplicate(str);` would allocate space for a string of the same length as `str`, copy the contents of `str` into the new string, and return a pointer to it. Have `duplicate` return a null pointer if the memory allocation fails.

---

#### Answer:

```c
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *str) {
    char *p = malloc(strlen(str) + 1);
    if (p == NULL) {
        return NULL;
    }
    strcpy(p, str);
    return p;
}
```
