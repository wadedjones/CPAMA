#### 3. (a) Show how to declare a tag named `complex` for a structure with tow members, `real` and `imaginary` of type `double`.

#### 3. (b) Use the complex tag to declare variables named c1, c2, and c3.

#### 3. (c) Write a function named `make_complex` that stores its two arguments (both of type double) in a complex structure, then returns the structure.

#### 3. (d) Write a function named `add_complex` that adds the corresponding members of its arguments (both clemplex structures), then returns the result (another complex structure).

---

#### Answer:

#### (a)

```c
struct complex {
    double real;
    double imaginary;
}
```

#### (b)

```c
struct complex c1, c2, c3;
```

#### (c)

```c
struct complex make_complex(double real, double imaginary) {
    return (struct complex) {real, imaginary};
}
```

#### (d)

```c
struct complex add_complex(struct complex a, struct complex b) {
    return (struct complex) {a.real + b.real, a.imaginary + b.imaginary};
}
```
