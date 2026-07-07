#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"
#include <stddef.h>

static int fprints(const char *s, const char *stream)
{
        return write(stream, (const void *)s, strlen(s));
}

static void strreverse(char *str, int length)
{
        int start = 0;
        int end = length - 1;

        while (start < end) {
                char tmp = str[start];
                str[start] = str[end];
                str[end] = tmp;
                end--;
                start++;
        }
}

static char *itoa(int num, char *buf, int base)
{
        int i = 0;
        bool is_negative = false;

        if (num == 0) {
                buf[i++] = '0';
                buf[i] = '\0';
                return buf;
        }

        if (num < 0 && base == 10) {
                is_negative = true;
                num = -num;
        }

        while (num != 0) {
                int remaining = num % base;
                buf[i++] = (remaining > 9) ? (remaining - 10) + 'a' : remaining + '0';
                num = num / base;
        }

        if (is_negative)
                buf[i++] = '-';

        buf[i] = '\0';

        strreverse(buf, i);

        return buf;
}

static char *utoa(size_t n, char *buf, int base)
{
        if (base < 2 || base > 36) {
                buf[0] = '\0';
                return buf;
        }

        char* p = buf;

        do {
                *p++ = "0123456789abcdefghijklmnopqrstuvwxyz"[n % base];
                n /= base;
        } while (n);

        *p = '\0';

        char* start = buf;
        char* end = p - 1;

        while (start < end) {
                char tmp = *start;
                *start++ = *end;
                *end-- = tmp;
        }

        return buf;
}

int fputc(int c, const char *stream)
{
        return write(stream, (const void *)&c, 1);
}

int putchar(int c)
{
        return write("D:/console", (const void *)&c, 1);
}

int vfprintf(const char *restrict stream, const char *restrict format, va_list arg)
{
        char buf[65];
        int res = 0;

        while (*format) {
                if (*format != '%') {
                        res = write(stream, &*format, sizeof(*format));
                        if (res < 0)
                                return res;
                        format++;
                        continue;
                }

                format++;          // eat the '%'
                switch(*format) {
                case 'c': {
                        int ch = va_arg(arg, int);
                        res = fputc(ch, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'b': {
                        size_t n = va_arg(arg, size_t);
                        utoa(n, buf, 2);
                        res = fprints(buf, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'o': {
                        size_t n = va_arg(arg, size_t);
                        utoa(n, buf, 8);
                        res = fprints(buf, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'd': {
                        int n = va_arg(arg, int);
                        itoa(n, buf, 10);
                        res = fprints(buf, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'u': {
                        size_t n = va_arg(arg, size_t);
                        utoa(n, buf, 10);
                        res = fprints(buf, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'x': {
                        size_t n = va_arg(arg, size_t);
                        utoa(n, buf, 16);
                        res = fprints(buf, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 's': {
                        const char *s = va_arg(arg, const char *);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                default:
                        break;
                }

                format++;
        }

        return 0;
}

int vprintf(const char *restrict format, va_list arg)
{
        int res = vfprintf("D:/console", format, arg);
        return res;
}

int fprintf(const char *restrict stream, const char *restrict format, ...)
{
        va_list args;
        va_start(args, format);
        int res = vfprintf(stream, format, args);
        va_end(args);
        return res;
}

int printf(const char *restrict format, ...)
{
        va_list args;
        va_start(args, format);
        int res = vprintf(format, args);
        va_end(args);
        return res;
}