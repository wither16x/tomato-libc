#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t new_size);

void free(void *ptr);

double strtod(const char *str, char **str_end);

#ifdef __cplusplus
}
#endif