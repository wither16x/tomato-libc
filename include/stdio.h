#pragma once

#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FILE {
        size_t fd;
} FILE;

FILE *fopen(const char *restrict path);
int fclose(FILE *stream);

int fputc(int c, FILE *stream);
int putchar(int c);

int fgetc(FILE *stream);
int getchar();
char *fgets(char *restrict str, int count, FILE *stream);

int vfprintf(FILE *stream, const char *restrict format, va_list arg);
int vprintf(const char *restrict format, va_list arg);
int fprintf(FILE *stream, const char *restrict format, ...);
int printf(const char *restrict format, ...);

extern FILE *stdin;
extern FILE *stdout;

#ifdef __cplusplus
}
#endif