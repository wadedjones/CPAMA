#### 15.

> (a) Declare a tag for an enumeration whose values represent the seven days of the week.  
> (b) Use `typedef` to define a name for the enumeration of part (a)  

---

#### Answer:

> (a)  

```c
enum week_days {
    MON, TUE, WED, THU, FRI, SAT, SUN
};
```

> (b)  

```c
typedef enum {
    MON, TUE, WED, THU, FRI, SAT, SUN
} Week_days;
```
