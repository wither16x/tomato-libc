#pragma once

#include <stddef.h>

int write(const char *file, const void *buf, size_t n);
int read(const char *file, void *buf, size_t n);
int exec(const char *file);
int fork(void);
int exit(void);
int getpid(void);
int wait(void);