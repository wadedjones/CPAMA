#### 2. (a) Declare structure variables named `c1`, `c2`, and `c3`, each having members `real` and `imaginary` of type `double`.

#### 2. (b) Modify the declaration in part (a) so that c1's members initially have the values 0.0 and 1.0, while c2's members are 1.0 and 0.0 initially. (c3 is not initialized).

#### 2. (c) Write statements that copy the members of c2 into c1. Can this be done in one statement, or does it require two?

#### 2. (d) Write statements that add the corresponding members of c1 and c2, storing the result in c3.

---

#### Answer:

#### (a)

```c
struct {
    double real;
    double imaginary;
} c1, c2, c3;
```

#### (b)

```c
struct {
    double real;
    double imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
```

#### (c)

```c
c1 = c2;
```

#### (d)

```c
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;
```
