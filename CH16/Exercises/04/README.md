#### 4. Repeat exercise 3, but this time using a `type` named `Complex`.

---

#### Answer:

#### (a)

```c
typedef struct {
    double real;
    double imaginary;
} Complex;
```

#### (b)

```c
Complex c1, c2, c3;
```

#### (c)

```c
Complex make_complex(double real, double imaginary) {
return (Complex) {real, imaginary};
}
```

#### (d)

```c
Complex add_complex(Complex a, Complex b) {
    return (Complex) {a.real + b.real, a.imaginary + b.imaginary};
}
```
