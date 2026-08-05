#pragma once

#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FILE {
        size_t fd;
        char *buf;
} FILE;

FILE *fdopen(int fd);
FILE *fopen(const char *restrict path);
int fclose(FILE *stream);
size_t fwrite( const void* restrict buffer, size_t size, size_t count, FILE* restrict stream );

int fputc(int c, FILE *stream);
int putchar(int c);

int fgetc(FILE *stream);
int getchar(void);
char *fgets(char *restrict str, int count, FILE *stream);

int vfprintf(FILE *stream, const char *restrict format, va_list arg);
int vprintf(const char *restrict format, va_list arg);
int fprintf(FILE *stream, const char *restrict format, ...);
int printf(const char *restrict format, ...);

int fflush(FILE *stream);

int puts(const char *s);

extern FILE *stdin;
extern FILE *stdout;

#ifdef __cplusplus
}
#endif