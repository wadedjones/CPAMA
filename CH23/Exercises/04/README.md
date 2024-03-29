#### 4. Using `isalpha` and `isalnum`, write a function that checks whether a string has the syntax of a C identifier (it consists of letters, digits, and underscores, with a letter or underscore at the beginning).

---

#### Answer:

```c
bool c_identify(char *var) {
  if (!isalpha(*var) && *var != '_') {
    return false;
  }
  var++;

  for (; *var != '\0'; var++) {
    if (!isalnum(*var) && *var != '_') {
      return false;
    }
  }

  return true;
}
```
