#### 12. Write a function that, when passed a year, returns a `time_t` value representing 12:00 a.m. on the first day of that year.

---

#### Answer:

```c
time_t first_day(int year) {
    struct tm result;

    result.tm_mday = 1;
    result.tm_mon = 0;
    result.tm_year = year - 1900;
    result.tm_sec = 0;
    result.tm_min = 0;
    result.tm_hour = 12;
    result.tm_isdst = -1;

    return mktime(&result);
}
```
