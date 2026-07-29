#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t          pid_t;

int write(int fd, const void *buf, size_t n);
int read(int fd, void *buf, size_t n);
int exec(const char *file);
pid_t fork(void);
int exit(void);
int getpid(void);
int wait(void);
int open(const char *path);
int close(int fd);

#ifdef __cplusplus
}
#endif