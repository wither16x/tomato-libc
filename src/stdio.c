#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------------------------------- */
static int fprints(const char *s, FILE *stream)
{
        return write(stream->fd, (const void *)s, strlen(s));
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------------------------------- */

char *ftoa(double n, char *buf)
{
        size_t DECIMALS = 6;

        char before_point_buf[65];
        char after_point_buf[65];
        char padded[DECIMALS + 1];

        bool negative = n < 0;
        double abs_n = negative ? -n : n;

        int64_t before_point = (int64_t)abs_n;
        char *before_point_str = itoa(before_point, before_point_buf, 10);

        double after_point_f = (abs_n - before_point) * pow(10, DECIMALS);
        int64_t after_point = (int64_t)after_point_f;
        char *after_point_str = itoa(after_point, after_point_buf, 10);

        size_t length = strlen(after_point_str);
        size_t padding = (length < DECIMALS) ? (DECIMALS - length) : 0;

        size_t i = 0;
        for(; i < padding; i++)
                padded[i] = '0';
        memcpy(padded + i, after_point_str, length < DECIMALS ? length : DECIMALS);
        padded[DECIMALS] = '\0';

        size_t pos = 0;
        if (negative)
                buf[pos++] = '-';

        size_t bp_length = strlen(before_point_str);
        memcpy(buf + pos, before_point_str, bp_length);
        pos += bp_length;

        buf[pos++] = '.';

        memcpy(buf + pos, padded, DECIMALS);
        pos += DECIMALS;

        buf[pos] = '\0';

        return buf;
}

/* ------------------------------------------------------------------------------------------------- */
FILE *fdopen(int fd)
{
        FILE *f = (FILE *)malloc(sizeof(*f));
        if (!f)
                return NULL;
        f->fd = fd;
        f->buf = (char *)malloc(sizeof(*f->buf));

        return f;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
FILE *fopen(const char *restrict path)
{
        int fd = open(path);
        FILE *f = fdopen(fd);
        return f;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int fclose(FILE *stream)
{
        if (!stream)
                return -1;
        int result = close(stream->fd);
        free(stream);
        return result;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
size_t fwrite(const void *restrict buffer, size_t size, size_t count, FILE *restrict stream)
{
        (void)size;
        memcpy(stream->buf, buffer, size * count);
        return 0;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int fputc(int c, FILE *stream)
{
        return write(stream->fd, (const void *)&c, 1);
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int putchar(int c)
{
        return write(stdout->fd, (const void *)&c, 1);
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int fgetc(FILE *stream)
{
        int c = 0;
        if (read(stream->fd, &c, 1) < 0)
                return -1;
        return c;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int getchar(void)
{
        return fgetc(stdin);
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
char *fgets(char *restrict str, int count, FILE *stream)
{
        int ch = 0;
        int i = 0;

        if (count <= 0)
                return str;

        while (i < count - 1) {
                ch = fgetc(stream);

                if (ch < 0)
                        break;

                str[i++] = ch;
                
                if (ch == '\n')
                        break;
        }
        str[i] = '\0';

        if (i > 0)
                return str;
        return NULL;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int vfprintf(FILE *stream, const char *restrict format, va_list arg)
{
        char buf[65];
        int res = 0;

        while (*format) {
                if (*format != '%') {
                        res = write(stream->fd, &*format, sizeof(*format));
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
                        char *s = utoa(n, buf, 2);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'o': {
                        size_t n = va_arg(arg, size_t);
                        char *s = utoa(n, buf, 8);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'd': {
                        int n = va_arg(arg, int);
                        char *s = itoa(n, buf, 10);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'u': {
                        size_t n = va_arg(arg, size_t);
                        char *s = utoa(n, buf, 10);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'x': {
                        size_t n = va_arg(arg, size_t);
                        char *s = utoa(n, buf, 16);
                        res = fprints(s, stream);
                        if (res < 0)
                                return res;
                        break;
                }

                case 'f': {
                        double n = va_arg(arg, double);
                        char *s = ftoa(n, buf);
                        res = fprints(s, stream);
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
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int vprintf(const char *restrict format, va_list arg)
{
        int res = vfprintf(stdout, format, arg);
        return res;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int fprintf(FILE *stream, const char *restrict format, ...)
{
        va_list args;
        va_start(args, format);
        int res = vfprintf(stream, format, args);
        va_end(args);
        return res;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int printf(const char *restrict format, ...)
{
        va_list args;
        va_start(args, format);
        int res = vprintf(format, args);
        va_end(args);
        return res;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int fflush(FILE *stream)
{
        (void)stream;
        return -1;
}
/* ------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------- */
int puts(const char *s)
{
        fprints(s, stdout);
        fprints("\n", stdout);

        return 0;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif