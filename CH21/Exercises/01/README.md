#### 1. Locate where the header files are kept on your system. Find the nonstandard headers and determine the purpose of each.

---

#### Answer: According to gcc, typing `cpp -v /dev/null -o /dev/null` outputs where the compiler looks for header files. One of the main directories is: `/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include`.
