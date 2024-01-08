#### 18. Modify the `compare_parts` function so that parts are sorted with their numbers in descending order.

---

#### Answer:

```c
int compare_parts2(const void *p, const void *q) {
  if (((struct part *)p)->number < ((struct part *)q)->number) {
    return 1;
  } else if (((struct part *)p)->number == ((struct part *)q)->number) {
    return 0;
  } else {
    return -1;
  }
}

// Or if all part numbers are POSITIVE

int compare_parts3(const void *p, const void *q) {
  return ((struct part *)q)->number - ((struct part *)p)->number;
}
```
