#### 1. If i is a variable and p points to i, which of the following expressions are aliases for i?

&ensp; (a) \*p &ensp; (c) \*\&p &ensp; (e) \*i &ensp; (g) \*\&i  
&ensp; (b) \&p &ensp;(d) \&\*p &ensp; (f) \&i &ensp; (h) \&\*i  
  
#### Answer: (a) and (g)  
-----
  
#### 2. If i is an int variable and p and q are pointers to int, which of the following assignments are legal?  
  
&ensp; (a) p = i; &ensp; &ensp; &nbsp;(d) p = \&q; &ensp; (g) p = \*q;  
&ensp; (b) \*p = \&i; &ensp; (e) p = \*\&q; &ensp; (h) \*p = q;  
&ensp; (c) \&p = q; &ensp; &nbsp;(f) p = q; &ensp; (i) \*p = \*q;
  
#### Answer:  
-----
  
#### 3. The following function supposedly computes the sum and average of the numbers in the array a, which has length n. avg and sum point to variables that the function should modify. Unfortunately, the function contains several errors; find and correct them.  

```c
void avg_sum(double a[], int n, double *avg, double *sum) {
	int i;
    sum = 0.0;
    for (i = 0; i < n; i++)
    	sum += a[i];
    avg = sum / n;
}
```  

#### Answer:
```c
void avg_sum(double a[], int n, double *avg, double *sum) {
	int i;
    *sum = 0.0;
    for (i = 0; i < n; i++)
    	*sum += a[i];
    *avg = *sum / n;
}
```
