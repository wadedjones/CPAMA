#### 13. Write the following function:

```c
int line_length(const char *filename, int n);
```

#### The function should return the length of the line `n` in the text file whose name is `filename` (assuming that the first line in the file is line 1). If the line doesn't exist, the function should return 0.

---

#### Answer:

```c
int line_length(const char *filename, int n) {
  FILE *fp;
  char buf[100];

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Error opening %s\n", filename);
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if ((fgets(buf, 100, fp)) == NULL) {
      return 0;
    }
    buf[strcspn(buf, "\n")] = 0;
  }

  fclose(fp);

  return strlen(buf);
}
```
