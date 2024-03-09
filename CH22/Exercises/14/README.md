#### 14. (a) Wrtie your own version of the `fgets` function. Make it behave as much like the real `fgets` function as possible; in particular, make sure that it has the proper return value. To avoid conflicts with the standard library, don't name your function `fgets`.

#### (b) Write your own version of `fputs`, following the same rules as in part (a).

---

#### Answer:

> (a)  

```c
char *my_fgets(char *str, int size, FILE *stream) {
  int ch;
  int i = 0;
  while (i < size - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (i == 0 || ferror(stream)) {
        return NULL;
      }
      break;
    }
    str[i++] = ch;
    if (ch == '\n') {
      break;
    }
  }
  str[i] = '\0';
  return str;
}
```

> (b)  

```c
int my_fputs(const char *str, FILE *stream) {
  while (*str != '\0') {
    if (putc(*str, stream) == EOF) {
      return EOF;
    }
    str++;
  }
  return 0;
}
```
