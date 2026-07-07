#pragma once

#include <stddef.h>

int write(const char *file, const void *buf, size_t n);
int read(const char *file, void *buf, size_t n);