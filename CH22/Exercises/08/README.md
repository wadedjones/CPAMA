#### 8. In previous chapters, we've used the `scanf` format string `" %c"` when we wanted to skip white-space characters and read a nonblank character. Some programmers use `"%1s"` instead. Are the two techniques equivalent? If not, what are the differences?

---

#### Answer: No, not the same. `" %c"` will only store the nonblank char, while "%1s" will store the nonblank char and a null terminating char after.
