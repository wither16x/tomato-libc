# The Tomato C Library

**Tomato** is a C library (libc) targeting C99 developed for [**the Radish Operating System** (RadishOS)](https://github.com/wither16x/radish_os).

## Headers
### [`unistd.h`](include/unistd.h)
- `write()`
- `read()`

### [`stdio.h`](include/stdio.h)
- `fputc()`, `putchar()`
- `fgetc()`, `getchar()`, `fgets()`
- `vfprintf()`, `vprintf()`
- `fprintf()`, `printf()`

### [`string.h`](include/string.h)
- `strlen()`
- `memcpy(), memset(), memmove(), memcmp()`

### [`stdarg.h`](include/stdarg.h)
- `va_list`
- `va_start()`, `va_end()`
- `va_arg()`

### [`stdbool.h`](include/stdbool.h)
- `true`, `false`
- `bool`

### [`stdint.h`](include/stdint.h)
- Signed types
- Fast types
- Least types
- Type macros
- Unsigned types
- Unsigned fast types
- Unsigned least types
- Integer limit macros
- Literal macros