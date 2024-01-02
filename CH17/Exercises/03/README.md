#### 3. Write the following function:

```c
int *create_array(int n, int initial_value);
```

#### The function should return a pointer to a dynamically allocated `int` array with `n` members, each of which is initialized to `initial_value`. The return value should be `NULL` if the array can't be allocated.

---

#### Answer:

```c
#include <stdlib.h>

int *create_array(int n, int initial_value) {
    int *p = malloc(n * sizeof(int));

    if (p == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < n; i++) {
        p[i] = initial_value;
    }
    return p;
}
```
