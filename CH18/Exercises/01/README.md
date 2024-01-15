#### 1. For each of the following declarations, identify the storage class, type qualifiers, type specifiers, declarators, and initializers.

> (a) `static char **lookup(int level);`  
> (b) `volatile unsigned long io_flags;`  
> (c) `extern char *file_name[MAX_FILES], path[];`  
> (d) `static const char token_buf[] = "";`  

---

#### Answer:

> (a)  
> Storage: `static`  
> Type Qualifiers: n/a  
> Type Specifiers: `char **`  
> Declarators: `lookup(int level)`  
> Initializers: n/a  

> (b)  
> Storage: n/a  
> Type Qualifiers: `volatile`  
> Type Specifiers: `unsigned long`  
> Declarators: `io_flags`  
> Initializers: n/a  

> (c)  
> Storage: `extern`  
> Type Qualifiers: n/a  
> Type Specifiers: `char * []`  
> Declarators: `file_name, path`  
> Initializers: n/a  

> (d)  
> Storage: `static`  
> Type Qualifiers: `const`  
> Type Specifiers: `char []`  
> Declarators: `token_buf`  
> Initializers: `""`  
