# The Tomato C Library

**Tomato** is a C library (libc) targeting C99 developed for [**the Radish Operating System** (RadishOS)](https://github.com/wither16x/radish_os).

## How to build
**Step 1:** clone the repository
```sh
git clone https://github.com/wither16x/tomato-libc
```
**Step 2:** build the sources
```sh
make # run make clean before if it does not work
```
**Step 3:** create the sysroot
```sh
./mksysroot.sh
```
**Step 4 (optional):** install the sysroot somewhere
```sh
# Note that the target directory must contain:
# * ./usr/
# * ./usr/include/
# * ./usr/lib
./install.sh <directory>
```

## Headers
### [`unistd.h`](include/unistd.h)
- `pid_t`
- `write()`, `read()`
- `exec()`, `fork()`, `exit()`, `wait()`, `getpid()`

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