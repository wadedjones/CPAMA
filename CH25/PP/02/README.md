#### 2. Write a program that obtains the name of a locale from the command line and then displays the values stored in the corresponding `lconv` structure. For example, if the locale is "fi_FI" (Finland), the output of the program might look like this:

`
decimal_point = ","
thousands_sep = " "
grouping = 3
mon_decimal_point = ","
...
...
...
int_n_sign_posn = 1
`

#### For readability, the characters in `grouping` and `mon_grouping` should be displayed as decimal numbers.

---

#### Answer: see `locale_info.c`.
