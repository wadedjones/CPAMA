#### 12. Many versions of `<string.h>` provide additional (nonstandard) functions, such as those listed below. Write each function using only the features of the C standard.

> (a) `strdup(s)` - Returns a pointer to a copy of `s` stored in memory obtained by calling `malloc`. Returns a null pointer if enough memory couldn't be allocated.  
> (b) `stricmp(s1, s2)` - Similar to `strcmp`, but ignores the case of letters.  
> (c) `strlwr(s)` - Converts upper-case letters in `s` to lower case, leaving other characters unchanged; returns `s`.  
> (d) `strrev(s)` - Reverses the characters in `s` (except the null character); returns `s`.  
> (e) `strset(s, ch)` - Fills `s` with copies of the character `ch`; returns `s`.  

#### If you test any of these functions, you may need to alter its name. Functions whose names begin with `str` are reserved by the C standard.

---

#### Answer: see `str_func.c`.
