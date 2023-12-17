#### 10. The following structures are designed to store information about objects on a graphics screen:

```c
struct point { int x, y;};
struct rectangle { struct point upper_left, lower_right; };
```

#### A `point` structure stroes the `x` and `y` coordinates of a point on the screen. A `rectangle` structure stores the upper left and lower right corners of a rectangle. Write functions that perform the following operations on a `rectangle` structure `r` passed as an argument:

> (a) Compute the area of `r`.  
> (b) Compute the center of `r`, returning it a s `point` value. If either the `x` or `y` coordinate of the center isn't an integer, store its truncated value in the `point` structure.  
> (c) Move `r` by `x` units in the `x` direction and `y` units in the `y` direction, returning the modified version of `r`.  
> (d) Determine whether a point `p` lies within `r` returning `true` or `false`.  

---

#### Answer: See exercise\_a.c - exercise\_d.c 
