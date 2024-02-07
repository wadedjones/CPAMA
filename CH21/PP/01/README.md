#### 1. Write a program that declares the `s` structure (Section 21.4) and prints the sizes and offsets of the `a`, `b`, and `c` members. (Use `sizeof` to find sizes; use `offsetof` to find offsets). Have the program print the size of the entire structure as well. From this information, determine whether or not the structure has any holes. If it does, describe the location and size of each.

---

#### Answer: The `char` variable `a` has a hole of 3.  

```c
#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main() {
    struct s x;
    printf("sizeof a: %ld, offsetof a: %ld\n", sizeof(x.a), offsetof(struct s, a));
    printf("sizeof b: %ld, offsetof b: %ld\n", sizeof(x.b), offsetof(struct s, b));
    printf("sizeof c: %ld, offsetof c: %ld\n", sizeof(x.c), offsetof(struct s, c));
    printf("sizeof x: %ld\n", sizeof(x));

    return 0;
}
```

output:
```c
sizeof a: 1, offsetof a: 0
sizeof b: 8, offsetof b: 4
sizeof c: 4, offsetof c: 12
sizeof x: 16
```
