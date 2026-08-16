#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct div {
        int quot;
        int rem;
} div_t;

typedef struct ldiv {
        long quot;
        long rem;
} ldiv_t;

typedef struct lldiv {
        long long quot;
        long long rem;
} lldiv_t;

div_t div(int x, int y);
ldiv_t ldiv(long x, long y);
lldiv_t lldiv(long long x, long long y);

void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t new_size);
void *aligned_alloc(size_t alignment, size_t size);

void free(void *ptr);

double strtod(const char *str, char **str_end);

void abort(void);

char *getenv(const char *name);

#ifdef __cplusplus
}
#endif