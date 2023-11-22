/* Example of functions with strings */

// First example using subscripting

int count_spaces_1(const char s[]) {
  int count, i;
  count = 0;

  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ') {
      count++;
    }
  }
  return count;
}

// Second example using pointer arithmetic

int count_spaces_2(const char *s) {
  int count = 0;
  for (; *s != '\0'; s++) {
    if (*s == ' ') {
      count++;
    }
  }
  return count;
}
