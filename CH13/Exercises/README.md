#### The following function calls supposedly write a single new-line character, but some are incorrect. Identify which calls don't work and explain why.

> (a) printf("%c", '\n'); (g) putchar('\n');  
> (b) printf("%c", "\n"); (h) putchar("\n");  
> (c) printf("%s", '\n'); (i) puts('\n');  
> (d) printf("%s", "\n"); (j) puts("\n");  
> (e) pointf('\n'); (k) puts("");  
> (f) printf("\n");  

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

#### Suppose that p has been declared as follows:

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

> (a)
