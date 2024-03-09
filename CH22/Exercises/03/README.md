#### 3. Find the error in the following program fragment and show how to fix it.

```c
FILE *fp;
if (fp = fopen(filename, "r")) {
    // read characters until end of file
}

fclose(fp);
```

---

#### Answer:

```c
FILE *fp;
if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error");
    exit(EXIT_FAILURE);
}

fclose(fp);
```
