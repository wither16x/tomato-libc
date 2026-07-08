#pragma once

#include <stdarg.h>

/// We use const char * for streams since RadishOS does not have complex
/// file structures yet, and no streams/file descriptors support.

int fputc(int c, const char *stream);
int putchar(int c);

int fgetc(const char *stream);
int getchar();
char *fgets(char *restrict str, int count, const char *restrict stream);

int vfprintf(const char *restrict stream, const char *restrict format, va_list arg);
int vprintf(const char *restrict format, va_list arg);
int fprintf(const char *restrict stream, const char *restrict format, ...);
int printf(const char *restrict format, ...);