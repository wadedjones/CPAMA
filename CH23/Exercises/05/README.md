#### 5. Using `isxdigit`, write a function that checks whether a string represents a valid hexadecimal number (it consists solely of hexadecimal digits.) If so, the function returns the value of the number as a `long int`. Otherwise, the function returns -1.

---

#### Answer:

```c
long int check_hex(char *p) {
  char *val = p;

  for (; *val != '\0'; val++) {
    if (!isxdigit(*val)) {
      return -1;
    }
  }

  return strtol(val, NULL, 16);
}
```
