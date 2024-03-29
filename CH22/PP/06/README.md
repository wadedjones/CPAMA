#### 6. Write a program that displays the contents of a file as bytes and as characters. Have the user specify the file name on the command line. Here's what the output will look like when the program is used to display the `pun.c` file of Section 2.1:

```
Offset              Bytes              Characters
------  -----------------------------  ----------
     0  23 69 6E 63 6C 75 64 65 20 3C  #include <
    10  73 74 64 69 6F 2E 68 3E OD OA  stdio.h>..
```

#### Each line shows 10 bytes from the file, as hexadecimal numbers and as characters. The number in the `Offset` column indicates the position within the file of the first byte on the line. Only printing characters (as determined by the `isprint` function) are displayed; other characters are shown as periods. Note that the appearance of a text file may vary, depending ont he character set and the operating system. The example above assumes that `pun.c` is a Windows file, so `0D` and `0A` bytes (the ASCII carriage-return and line-feed characters) appear at the end of each line. Hint: Be sure to open the file in "rb" mode.

---

#### Answer: see `bytechar.c`.
