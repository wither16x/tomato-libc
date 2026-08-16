#pragma once

#include <stdarg.h>
#include <stddef.h>

#define EOF             (-1)
#define stderr          stdout

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FILE {
        size_t fd;
        char *buf;
} FILE;

int feof(FILE *stream);
int ferror(FILE *stream);
FILE *fdopen(int fd);
FILE *fopen(const char *__restrict path);
int fclose(FILE *stream);
size_t fwrite( const void* __restrict buffer, size_t size, size_t count, FILE* __restrict stream );
int fileno(FILE *stream);
int remove(const char *pathname);

int fputc(int c, FILE *stream);
int putchar(int c);
int fputs(const char *__restrict s, FILE *__restrict stream);

int fgetc(FILE *stream);
int getchar(void);
char *fgets(char *__restrict str, int count, FILE *stream);

int vfprintf(FILE *stream, const char *__restrict format, va_list arg);
int vprintf(const char *__restrict format, va_list arg);
int fprintf(FILE *stream, const char *__restrict format, ...);
int printf(const char *__restrict format, ...);

int fflush(FILE *stream);

int puts(const char *s);

int vsprintf(char *__restrict buffer, const char *__restrict format, va_list vlist);
int vsnprintf(char *__restrict buffer, size_t bufsz, const char *__restrict format, va_list vlist);
int sprintf(char *__restrict buffer, const char *__restrict format, ...);
int snprintf(char *__restrict buffer, size_t bufsz, const char *__restrict format, ...);

int isatty(int fd);

extern FILE *stdin;
extern FILE *stdout;

#ifdef __cplusplus
}
#endif