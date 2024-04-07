#### 6. Modify the following program fragment by replacing as many characters as possible by trigraphs.

```c
while ((orig_char = getchar()) != EOF) {
    new_char = orig_char ^ KEY;
    if (isprint(orig_char) && isprint(new_char))
        putchar(new_char);
    else
        putchar(orig_char);
}
```

---

#### Answer:

```c
while ((orig_char = getchar()) != EOF) ??<
    new_char = orig_char ??' KEY;
    if (isprint(orig_char) && isprint(new_char))
        putchar(new_char);
    else
        putchar(orig_char);
??>
```
