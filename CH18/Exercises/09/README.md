#### 9. Use a series of type definitions to simplifiy each of the declarations in Exercise 8.

---

#### Answer:

> (a)  

```c
typedef char fx(int);
typedef fx *fx_ptr;
typedef fx_ptr fx_ptr_array[10];

fx_ptr_array x;
```

> (b)  

```c
typedef int fx_array[5];
typedef fx_array *fx_ptr(int);

fx_ptr x;
```

> (c)  

```c
typedef float *fx_ptr(int);
typedef fx_ptr *fx_inner(void);

fx_inner x;
```

> (d)  

```c
typedef void fx_outer(int);
typedef void *fx_arg(int);
typedef fx_outer *fx_inner(int, fx_arg);

fx_inner x;
```
