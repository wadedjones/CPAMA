#### 12. The following function supposedly combines two bytes to form an unsigned short integer. Explain why the function doesn't work and show how to fix it.

```c
unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte) {
    return high_byte << 8 + low_byte;
}
```

---

#### Answer: The `+` operator has higher precedence than the `<<` operator. Adding parenthesis fixes the issue.

```c
unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte) {
    return (high_byte << 8) + low_byte;
}
```
