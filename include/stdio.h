#pragma once

#include <stdarg.h>

int fputc(int c, const char *stream);
int putchar(int c);

int vfprintf(const char *restrict stream, const char *restrict format, va_list arg);
int vprintf(const char *restrict format, va_list arg);
int fprintf(const char *restrict stream, const char *restrict format, ...);
int printf(const char *restrict format, ...);