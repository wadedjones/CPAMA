#### 7. Suppose that we call `scanf` as follows:

```c
n = scanf("%d%f%d", &i, &x, &j);
```

#### (`i`, `j`, and `n` are `int` variables and `x` is a float variable) Assuming that the input stream contains the characters shown, give the values of `i`, `j`, `n`, and `x` after the call. In addition, indicate which characters were consumed by the call.

> (a) `10 20 30`  
> (b) `1.0 2.0 3.0`  
> (c) `0.1 0.2 0.3`  
> (d) `.1 .2 .3`  

---

#### Answer:

> (a)  
>> `i = 10`  
>> `j = 30`  
>> `n = 3`  
>> `x = 20.000000`  
> (b)  
>> `i = 1`  
>> `j = 2`  
>> `n = 3`  
>> `x = 0.000000`  
> (c)  
>> `i = 0`  
>> `j = 0`  
>> `n = 3`  
>> `x = 0.100000`  
> (d)  
>> `undefeind`  
>> `undefined`  
>> `n = 0`  
>> `undefined`  
