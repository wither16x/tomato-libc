#include "unistd.h"
#include <stddef.h>

int write(const char *file, const void *buf, size_t n)
{
        __asm__ volatile (
                "int $0x80"
                ::
                "a"(0), "b"(file), "c"(buf), "d"(n)
        );

        int ret = 0;
        __asm__ volatile ("" : "=a"(ret));
        return ret;
}

int read(const char *file, void *buf, size_t n)
{
        __asm__ volatile (
                "int $0x80"
                ::
                "a"(1), "b"(file), "c"(buf), "d"(n)
        );

        int ret = 0;
        __asm__ volatile ("" : "=a"(ret));
        return ret;
}