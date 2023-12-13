#### 5. Write the following functions. assuming that the `date` structure contains three members: `month`, `day`, and `year` (all of type int).

> (a) `int day_of_year(struct date d);`  
> REturns the day of the year (an integer between 1 and 366) that corresponds to date d.  
> (b) `int compare_dates(struct date d1, struct date d2);`  
> Returns -1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2, and 0 if d1 and d2 are the same.  

#### Answer:

> (a)  

```c
int day_of_year(struct date d) {
    int i, day = 0;
    
    for (i = 1; i < d.month; i++) {
        switch (i) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day += 31;
            break;
        case 4: case 6: case 9: case 11:
            day += 30;
            break;
        case 2:
            if (d.year %400 == 0 || (d.year %100 != 0 && d.year % 4 == 0)) {
                day += 29;
            } else {
                d.day += 28;
            }
        default:
            break;
        }
    }
    
    day += d.day;
    
    return day;
}
}
```

> (b)  

```c
int compare_dates(struct date d1, struct date d2) {
    int total_d1, total_d2;
    total_d1 = d1.day + d1.month + d1.year;
    total_d2 = d2.day + d2.month + d2.year;
    
    if (total_d1 == total_d2) {
        return 0;   
    } else if (total_d1 > total_d2) {
        return 1;
    } else {
        return -1;
    }
}
```
