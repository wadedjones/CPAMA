#### 4. Suppose that the following declarations are in effect:

```c
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;
```

#### Assume that we want `p` to point to a `rectangle` structure whose upper left corner is at (10, 25) and whos lower right corner is at (20, 15). Write a series of statements that allocate such a structure and initialize it as indicated.  

---

#### Answer:  

```c
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p = (struct rectangle *)malloc(sizeof(struct rectangle));

p->upper_left = (struct point){10, 25};
p->lower_right = (struct point){20, 15};
```
