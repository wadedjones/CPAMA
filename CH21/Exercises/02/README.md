#### 2. Having located the header files on your system, find a standard header in which a macro hides a function.

---

#### Answer: Inside the `assert.h` header:

```c
#if __DARWIN_UNIX03
#define	assert(e) \
    (__builtin_expect(!(e), 0) ? __assert_rtn(__func__, __ASSERT_FILE_NAME, __LINE__, #e) : (void)0)
```
