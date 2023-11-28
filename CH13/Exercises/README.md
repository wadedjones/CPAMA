#### 1. The following function calls supposedly write a single new-line character, but some are incorrect. Identify which calls don't work and explain why.

> (a) printf("%c", '\n');  
> (b) printf("%c", "\n");   
> (c) printf("%s", '\n');   
> (d) printf("%s", "\n");  
> (e) pointf('\n');  
> (f) printf("\n");  
> (g) putchar('\n');  
> (h) putchar("\n");  
> (i) puts('\n');  
> (j) puts("\n");  
> (k) puts("");  

#### Answer:

> (a) Works. Print a char, '\n' is a char.  
> (b) Doesn't Work. Print a char and arg is a string.  
> (c) Doesn't Work. Print a str and arg is a char.  
> (d) Works. Print a str, arg is a str.  
> (e) Doesn't Work. First printf arg must be a str.  
> (f) Works. First printf arg is a str.  
> (g) Works. putchar "puts" a char.  
> (h) Doesn't Work. putchar "puts" a str instead of a char.  
> (i) Doesn't Work. puts "puts" a char instead of a str.  
> (j) Works. puts "puts" a str.  
> (k) Works. puts "puts" a str (empty str).  

---

#### 2. Suppose that `p` has been declared as follows:

```c
char *p = "abc";
```

> Which of the following function calls are legal? Show the output produced by each legal call, and explain why the others are illegal.  
>  
> (a) putchar(p);  
> (b) putchar(*p);  
> (c) puts(p);  
> (d) puts(*p);  

#### Answer:

> (a) "Incompatible pointer to integer conversion passing 'char *' to parameter of type 'int'"  
> (b) Prints: a // With no new line  
> (c) Prints: abc // With a new line  
> (d) "Incompatible integer to pointer conversion passing 'char' to parameter of type 'const char *'"  

---

#### 3. Suppose that we call `scanf` as follows:

```c
scanf("%d%s%d", &i, s, &j);
```

> If the user enters `12abc34 56def78`, what will be the values of `i`, `s`, and `j` after the call?  
> (assume that `i` and `j` are int variables and `s` is an array of chars.)

#### Answer:

> `i` is equal to 12  
> `s` is equal to abc34  
> `j` is equal to 56  

---

#### 4. Modify the `read_line` function in each of the following ways:

> (a) Have it skip white space before beginning to store input characters.  
> (b) Have it stop reading at the first white-space character. *Hint:* To determine whether or not a character is white space, call the isspace function.  
> (c) Have it stop reading at the first new-line character, then store the new-line character in the string.  
> (d) Have it leave behind characters that it doesn't have room to store.  

#### Answer:

> (a)  

```c
int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i == 0 && isspace(ch))
      ;
    else if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';
  return i;
}
```

> (b)  

```c
int read_line(char str[], int n) {
  int ch, i = 0;

  while (!isspace(ch = getchar())) {
    if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';
  return i;
}
```

> (c)  

```c
int read_line(char str[], int n) {
  int ch, i = 0;

  do {
    ch = getchar();
    if (i < n) {
      str[i++] = ch;
    }
  } while (ch != '\n');
  str[i] = '\0';
  return i;
}
```

> (d)  
```c
int read_line(char str[], int n) {
  int ch, i;

  for (i = 0; i < n; i++) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    str[i] = ch;
  }
  str[i] = '\0';
  return i;
}
```

---

#### 5. (a) Write a function named `capitalize` that capitalizes all letters in its argument. The argument will be a null-terminated string containing arbitrary charactes, not just letters. Use array subscripting to access the characters in the string. *Hint:* Use the `toupper` function to convert each character to upper-case.

#### (b) Rewrite the `capitalize` function, this time using pointer arithmetic to access the characters in the string.

#### Answer:
> (a)  

```c
void capitalize(char s[]) {
    int i = 0;
    
    while (s[i++] != '\0') {
        if (isalpha(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}
```

> (b)  

```c
void capitalize(char *s) {
    while (*s++) {
        if (isalpha(*s)) {
            *s = toupper(*s);
        }
    }
}
```

---

#### 6. Write a function named `censor` that modifies a string by replacing every occurence of `foo` by `xxx`. For example, the string `"food fool"` would become `"xxxd xxxl"`. Make the function as short as possible without sacrificing clarity.

#### Answer:

```c
// using subscripting
void censor(char s[]) {
    int i;
    
    for (i = 0; s[i] !='\0'; i++)
        if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'o')
            s[i] = s[i + 1] = s[i + 2] = 'x';
}

// using pointer arithmetic
void censor(char *s) {
    while (*s++) {
        if (*s == 'f' && *(s + 1) == 'o' && *(s + 2) == 'o')
            *(s) = *(s + 1) = *(s + 2) = 'x';
    }
}
```

---

#### 7. Suppose that `str` is an array of characters. Which one of the following statements is not equivalent to the other three?

> (a) *str = 0;  
> (b) str[0] = '\0';  
> (c) strcpy(str, "");  
> (d) strcat(str, "");  

#### Answer:

> (d) strcat is not equivalent.

---

#### 8. What will be the value of the string `str` after the following statements have been executed?

> `strcpy(str, "tire-bouchon");`  
> `strcpy(&str[4], "d-or-wi");`  
> `strcat(str, "red?");`  

#### Answer:

```c
"tired-or-wired";
```

---

#### 9. What will be the value of the string `s1` after the following statements have been executed?

```c
strcpy(s1, "computer");
strcpy(s2, "science");
if (strcmp(s1, s2) < 0)
    strcat(s1, s2);
else
    strcat(s2, s1);
s1[strlen(s1) - 6] = '\0';
```

#### Answer:

> `"computers"`  

---

#### 10. The following function supposedly creates an identical copy of a string. What's wrong with the function?

```c
char *duplicate(const char*p) {
    char *q;

    strcpy(q, p);
    return q;
}
```

#### Answer:

> The value of `q` is undefined, so `strcpy` attempts to copy the string into some unknown part of memory.

---

#### 11. The Q&A section at the end of this chapter shows how the `strcmp` function might be written using array subscripting. Modify the function to use pointer arithmetic instead.

```c
// using subscripting

int strcmp(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
```

#### Answer:

```c
int n_strcmp(char *s, char *t) {
    while (*s++ == *t++)
        ;
    return *s == 0 ? 0 : (*(--s) - *(--t));
}
```

---

#### 12. Write the following function:

```c
void get_extension(const char *file_name, char *extension);
```

> `file_name` points to a string containing a file name. The function should store the extension on the file name in the string pointed to by `extension`. For example, if the file name is "memo.txt", the function wil store "txt" in the string pointed to by `extension`. If the file name doesn't have an extension, the function should store an empty string (a single null character) in the string pointed to by `extension`. Keep the function as simple as possible by having it use the `strlen` and `strcpy` functions.

#### Answer:

```c
// one example
void get_extension(const char *file_name, char *extension) {
    const char *p = file_name + (strlen(file_name) - 1);

    while (isalpha(*(p--)) && p != file_name)
        ;

    if (p == file_name) {
        strcpy(extension, "");
        return;
    } else {
        p++;
        while (*(p++)) {
            strcpy(extension++, p);
        }
    }
    
}

// another example

void get_extension(const char *file, char *extension) {
    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }
    strcpy(extension, "");
}
```

---

#### 13. Write the following function:

```c
void build_index_url(const char *domain, char *index_url);
```

> `domain` points to a string containing an internet domain, such as "knking.com". The function should add "http://www." to the beginning of this string and "/index.html" to the end of the string, storing the result in the string pointed to by `index_url`. (In this example, the result will be "http://www.knking.com/index.html".) You may assume that `index_url` points to a variable that is long enough to hold the resulting string. Keep the function as simple as possible by having it use the strcat and strcpy functions.

#### Answer:

```c
void build_index_url(const char *domain, char *index_url) {
    char https[] = "https://www.";
    char index[] = "/index.html";
    strcat(strcat(strcpy(index_url, https), domain), index);
}
```

---

#### 14. What does the following program print?

```c
#include <stdio.h>

int main(void) {
    char s[] = "Hsjodi", *p;

    for (p = s; *p; p++)
        --*p;
    puts(s);
    return 0;
}
```

#### Answer:

> The program prints `Grinch`  

---

#### 15. Let f be the following function:

```c
int f(char *s, char *t) {
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}
```

> (a) What is the value of `f("abcd", "babc")?`  
> (b) What is the value of `f("abcd", "bcd")?`  
> (c) In general, what value does f return when passed two strings s and t?

#### Answer:

> (a) returns `3`  
> (b) returns `0`  
> (c) the amount of chars in s that exist in t, prefixed (if the first value is not in t, return 0, and so on).

---

#### 16. Use the techniques of Section 13.6 to condense the `count_spaces` function of Section 13.4. In particular, replace the `for` statement by a `while` loop.

> Original `count_spaces` function:

```c
int count_spaces(const char *s) {
    int count = 0;
    for (; *s != '\0'; s++) {
        if (*s == ' ') {
            count++;
        }
    }
    return count;
}
```

#### Answer:

```c
int count_spaces(const char *s) {
    int count = 0;

    while (*s) {
       if (*s++ == ' ') 
            count++;
    }
    return count;
}
```

---

#### 17. Write the following function:

```c
bool test_extension(const char *filename, const char *extension);
```

> `file_name` points to a string containing a file name. The function should return `true` if the file's extension matches the string pointed to by `extension`, ignoring the case of letters. For example, the call `test_extension("memo.text", "TXT")` would return `true`. Incorporate the "search for the end of a string" idiom into your function. *Hint:* Use the `toupper` function to convert characters to upper-case before comparing them.

#### Answer:

```c
bool test_extension(const char *file_name, const char *extension) {
    const char *p = file_name + (strlen(file_name)) - strlen(extension);
    while (*p) {
        if (toupper(*p++) != toupper(*extension++))
            return false;
    }
    return true;
}
```
