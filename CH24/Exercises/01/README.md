#### 1. (a) Assertions can be used to test for two kinds of problems: (1) problems that should never occur if the program is correct, and (2) problems that are beyond the control of the program. Explain why `assert` is best suited for problems in the first category.

#### (b) Give three examples of problems that are beyond the control of the program.

---

#### Answer:

> (a) When writing a program, values and types are known by the programmer, making assertions much more precise and clear.  
> (b) Any hardware issue or failure is outside the scope of `assert`. Signals being passed to the program are outside the scope of `assert`. And any operating system failures or updates, or anything that could cause the program to pause or terminate, are outside the scope of `assert`.
