#### 1. Suppose that the following declarations are in effect:

```c
int a[] = {5, 15, 24, 54, 14, 2, 52, 72};
int *p = &a[1], *q = &a[5];
```

> (a) What is the value of *(p+3) ?  
> (b) What is the value of *(q-3) ?  
> (c) What is the value of q - p?  
> (d) Is the condition p < q true or false?  
> (e) Is the condition *p < *q true or false?  

#### Answer:

> (a) 14  
> (b) 24  
> (c) 4  
> (d) true  
> (e) false  

---

#### 2. Suppose that high, low, and middle are all pointer variables of the same type, and that low and high point to elements of an array. Why is the following statement illegal, and how could it be fixed?

```c
middle = (low + high) / 2;
```

#### Answer:  

> The statement is illegal because you cannot add pointers. The legal statement would be:

```c
middle = low + (high - low) / 2;
```

---

#### 3. What will be the contents of the a array after the following statements are executed?

```c
#define N 10

int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &a[0], *q = &a[N-1], temp;

while (p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
}
```

#### Answer:

> The array is reversed:

```c
{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
```
  
---

#### 4. Rewrite the make\_empty, is\_empty, and is\_full functions of section 10.2 to use the pointer variable top\_ptr instead of the integer variable top.  

#### Answer:

```c
int *top_ptr = &contents[0];

void make_empty(void) {
    *top_ptr = &contents[0];
}

bool is_empty(void) {
    return *top_ptr == &contents[0];
}

bool is_full(void) {
    return *top_ptr == &contents[STACK_SIZE];
}
```
  
---

#### 5. Suppose that a is a one-dimensional array and p is a pointer variable. Assuming that the assignment p = a has just been performed, which of the following expressions are illegal because of mismatched types? Of the remaining expressions, which are true (have a nonzero value)?

> (a) p == a[0]  
> (b) p == &a[0]  
> (c) \*p == a[0]  
> (d) p[0] == a[0]  

#### Answer:

> (a) illegal: int * compared to int  
> (b) true  
> (c) true  
> (d) true  

---

#### 6. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as possible.

```c
int sum_array(const int a[], int n) {
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}
```

#### Answer:

```c
int sum_array(const int a[], int n) {
    int *p, sum = 0;

    for (p = a; p < a + n; p++) {
        sum += *p;
    }
    return sum;
}
```

---

#### 7. Write the following function:

```c
bool search(const int a[], int n, int key);
```

> a is an array to be searched, n is the number of elements in the array, and key is the search key. search should return true if key matches some element of a, and false if it doesn't. Use pointer arithmetic-not subscripting- to visit array elements.

#### Answer:

```c
bool search(const int a[], int n, int key) {
    int *p;

    for (p = a; p < a + n; p++) {
        if (*p == key) {
            return true;
        }
    }
    return false;
}

// compiler throws error assigning p = a, here is another solution:

bool search(const int a[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (*a++ == key) {
            return true;
        }
    }
    return false;
}

```

---

#### 8. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as possible.

```c
void store_zeros(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = 0;
    }
}
```

#### Answer:

```c
void store_zeros(int a[], int n) {
    int *p;
    for (p = a, p < a + n; p++) {
        *p = 0;
    }
}
```

---

#### 9. Write the following function:

```c
double inner_product(const double *a, const double *b, int n);
```

#### a and b both point to arrays of length n. The function should return a[0] * b[0] + a[1] * b[1] + ... a[n-1] * b[n-1]. Use pointer arithmetic-not subscripting-to visit array elements.

#### Answer:

```c
double inner_product(const double *a, const double *b, int n) {
    double *p, *q, sum = 0;
        
        for (p = a, q = b; p < a + n; p++, q++) {
            sum += *p * *q;
        }
        return sum;
}
// compiler has warnings when assigning pointer to const array
// here is a version with no warnings:

double inner_product(const double *a, const double *b, int n) {
    int i = 0;
    double sum = 0;
    
    while (i++ < n) {
        sum += *a++ * *b++;
    }
}
```

---

#### 10. Modify the find\_middle function of section 11.5 so that it uses pointer arithmetic to calculate the return value.

```c
int *find_middle(int a[], int n) {
    return &a[n/2];
}
```

#### Answer:

```c
int *find_middle(int a[], int n) {
    return a + n / 2;
}
```

---

#### 11. Modify the find\_largest function so that it uses pointer arithmetic-not subscripting-to visit array elements.

```c
int *find_largest(int a[], int n) {
    int i, largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[largest]) {
            largest = i;
        }
    }
    return &a[largest];
}
```

#### Answer:

```c
int *find_largest(int a[], int n) {
    int i, *largest = a;

    for (i = 0; i < n; i++) {
        if (*++a > *largest) {
            largest = a;
        }
    }
    return largest;
}
```

---

#### 12. Write the following function:

```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest);
```

> a points to an array of length n. The function searches the array for its largest and second largest elements, storing them in the variables pointed to by largest and second\_largest, respectively. Use pointer arithmetic-not subscripting-to visit array elements.

#### Answer:

```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    int i;
    *largest = *a;
    *second_largest = *a;
    
    for (i = 1; i < n; i++) {
        if (*++a > *largest) {
            *largest = *a;
        }
    }
    
    for (i = n - 1; i > 0; i--) {
        if (*--a > *second_largest && *a < *largest) {
            *second_largest = *a;
        }
    }
}
```

---

#### 13. Section 8.2 had a program fragment in which two nested for loops initialized the array ident for use as an identity matrix. Rewrite this code, using a single pointer to step through the array one element at a time. *Hint:* Since we won't be using row and col index variables, it won't be easy to tell where to store 1. Instead, we can use the fact that the first element of the array should be 1, the next N elements should be 0, the next element should be 1, and so forth. Use a variable to keep track of how many consecutive 0s have been stored; when the count reaches N, it's time to store 1.

#### Answer:

```c
int ident[N][N];
    int row, col;
    int *p;
    
    int i = 0;
    
    for (p = ident[0]; p < ident[0] + N * N; p++, i++) {
        if (i % 11 == 0) {
            *p = 1;
        } else {
            *p = 0;
        }
    }
```

---

#### 14. Assume that the following array contains a week's worth of hourly temperature readings, with each row containing the readings for one day:

```c
int temperatures[7][24];
```

> Write a statement that uses the search function (exercise 7) to search the entire temperatures array for the value 32.

#### Answer:

```c
search(temperatures, 7 * 24, 32);
```

---

#### 15. Write a loop that prints all temperature readings stored in row i of the temperatures array (exercise 14). Use a pointer to visit each element of the row.

#### Answer:

```c
int *p;
int i;

for (p = temperatures[i]; p < temperatures[i + 1]; p++) {
    printf("%d", *p);
}
```

---

#### 16. Write a loop that prints the highest temperature in the temperatures array (exercise 14) for each day of the week. The loop body should call the find\_largest function, passing it one row of the array at a time.

#### Answer:

```c
int i;

for (i = 0; i < 7; i++) {
    find_largest(temperatures[i], 24);
}
```

---

#### 17. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variables i and j and all uses of the [] operator.) Use a single loop instead of nested loops.

```c
int sum_two_dimensional_array(const int a[][LEN], int n) {
    int i, j, sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < LEN; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
```

#### Answer:

```c
int sum_two_dimensional_array(const int a[][LEN], int n) {
    const int *p = *a;
    int sum = 0;
    
    for (; p < *a + n * LEN; p++) {
        sum += *p;
    }
    return sum;
}
```

---

#### 18. Write the evaluate\_position function described in exercise 13 of chapter 9. Use pointer arithmetic-not subscripting-to visit array elements. Use a single loop instead of nested loops.

#### Answer:

```c
int evaluate_position(char board[8][8]) {
    int *p;
    int white, black;
    white = black = 0;

    for (p = board; p < board + 8 * 8; p++) {
        switch (*p) {
            // a bunch of switch statements...
        }
    }
    return white - black;
}
```
