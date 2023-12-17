#### 13. Suppose that `s` is the following structure (`point` is a structure tag declared in Exercise 10):

```c
struct point {
    int x, y;
};

struct shape {
    int shape_kind;      /* rectangle or circle */
    struct point center; /* coordinates of center */
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;
```

#### If the value of `shape_kind` is `RECTANGLE` the `height` and `width` members store the dimensions of a rectangle. If the value of `shape_kind` is `CIRCLE`, the `radius` member stores the radius of a circle. Indicate which of the following statements are legal, and show how to repair the ones that aren't:

> (a) `s.shape_kind = RECTANGLE;`  
> (b) `s.center.x = 10;`  
> (c) `s.height = 25;`  
> (d) `s.u.rectangle.width = 8;`  
> (e) `s.u.circle = 5;`  
> (f) `s.u.radius = 5;`  

#### Answer:

> (a) Legal.  
> (b) Legal.  
> (c) Illegal. `s.u.rectangle.height = 25;`  
> (d) Legal.  
> (e) Illegal. `s.u.circle.radius = 5;`  
> (f) Illegal. `s.u.circle.radius = 5;`  
