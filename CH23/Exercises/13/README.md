#### 13. Use `strtok` to write the following function:

```c
int count_words(char *sentence);
```

#### `count_words` returns the number of words in the string `sentence`, where a "word" is any sequence of non-white-space characters. `count_words` is allowed to modify the string.

---

#### Answer:

```c
int count_words(char *sentence) {
  int count = 0;
  char *p = strtok(sentence, " \t\n");

  while (p != NULL) {
    count++;
    p = strtok(NULL, " \t\n");
  }

  return count;
}

```
