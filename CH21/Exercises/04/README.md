#### 4. Make a list of all reserved identifiers in the "future library directions" section of the C99 standard. Distinguish between identifiers that are reserved for use only when a specific header is included versus identifiers that are reserved for use as external names.

---

#### Answer:

> #### Complex Arithmetic `<complex.h>`  
```c
cerf
cerfc
cexp2
cexpm1
clog10
clog1p
clog2
clgamma
ctgamma
```
> and the same names suffixed with `f` or `l` may be added to the declarations in the `<complex.h>` header.  

> #### Character handling `<ctype.h>`
> Function names that begin with either `is` or `to`, and a lowercase letter may be added to the declarations in the `<ctype.h>` header.  

> #### Errors `<errno.h>`  
> Macros that begin with `E` and a digit or `E` and an uppercase letter may be added to the declarations in the `<errno.h>` header.  

> #### Format conversion of integer types `<inttypes.h>`  
> Macro names beginning with `PRI` or `SCN` followed by any lowercase letter or `X` may be added to the macros defined in the `<inttypes.h>` header.  

> #### Localization `<locale.h>`  
> Macros that begin with `LC_` and an uppercase letter may be added to the definitions in the `<locale.h>` header.  

> #### Signal handling `<signal.h>`  
> Macros that begin with either `SIG` and an uppercase letter or `SIG_` and an uppercase letter may be added to the definitions in the `<signal.h>` header.  

> #### Boolean type and values `<stdbool.h>`  
> The ability to undefine and perhaps then redefine the macros `bool`, `true`, and `false` is an obsolescent feature.  

> #### Integer types `<stdint.h>`  
> Typedef names beginning with `int` or `uint` and ending with `_t` may be added to the types defined in the `<stdint.h>` header. Macro names beginning with `INT` or `UINT` and ending with `_MAX`, `_MIN`, or `_C` may be added to the macros defined in the `<stdint.h>` header.  

> ####  Input/output `<stdio.h>`  
> Lowercase letters may be added to the conversion specifiers and length modifiers in `fprintf` and `fscanf`. Other characters may be used in extensions.  
> The `gets` function is obsolescent, and is deprecated.  
> The use of `ungetc` on a binary stream where the file position indicator is zero prior to the call is an obsolescent feature.  

> #### General utilities `<stdlib.h>`  
> Function names that begin with `str` and a lowercase letter may be added to the declarations in the `<stdlib.h>` header.  

> #### String handling `<string.h>`  
> Function names that begin with `str`, `mem`, or `wcs` and a lowercase letter may be added to the declarations in the `<string.h>` header.  

> #### Extended multibyte and wide character utilities `<wchar.h>`  
> Function names that begin with `wcs` and a lowercase letter may be added to the declarations in the `<wchar.h>` header.  
> Lowercase letters may be added to the conversion specifiers and length modifiers in `fwprintf` and `fwscanf`. Other characters may be used in extensions.  

> #### Wide character classification and mapping utilities `<wctype.h>`  
> Function names that begin with `is` or `to` and a lowercase letter may be added to the declarations in the `<wctype.h>` header.  
