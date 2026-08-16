#include "unistd.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GET_SYS_RETVAL(var)     __asm__ volatile ("" : "=a"(var))
#define START_SYSCALL(n)        __asm__ volatile ( "int $0x80" :: "a"(n),
#define END_SYSCALL             );
#define SYSCALL_NOPARAM(n)      __asm__ volatile ("int $0x80" :: "a"(n));
#define RBX(x)                  "b"(x)
#define RCX(x)                  "c"(x)
#define RDX(x)                  "d"(x)
#define RDI(x)                  "D"(x)

enum syscall_type {
        SYS_WRITE,
        SYS_READ,
        SYS_EXEC,
        SYS_FORK,
        SYS_EXIT,
        SYS_GETPID,
        SYS_WAIT,
        SYS_OPEN,
        SYS_CLOSE,
        SYS_LASTPG,
        SYS_GETCPUTIME,
        SYS_RM
};

/* ------------------------------------------------------------------------------------------------- */
int write(int fd, const void *buf, size_t n)
{
        START_SYSCALL(SYS_WRITE)
                RBX(fd),
                RCX(buf),
                RDX(n)
        END_SYSCALL

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int read(int fd, void *buf, size_t n)
{
        START_SYSCALL(SYS_READ)
                RBX(fd),
                RCX(buf),
                RDX(n)
        END_SYSCALL
        
        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int exec(const char *file, int argc, char **argv, char **envp)
{
        START_SYSCALL(SYS_EXEC)
                RBX(file),
                RCX(argc),
                RDX(argv),
                RDI(envp)
        END_SYSCALL

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
pid_t fork(void)
{
        SYSCALL_NOPARAM(SYS_FORK);

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int exit(void)
{
        SYSCALL_NOPARAM(SYS_EXIT);

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int getpid(void)
{
        SYSCALL_NOPARAM(SYS_GETPID);

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int wait(void)
{
        SYSCALL_NOPARAM(SYS_WAIT);

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int open(const char *path, int flags, ...)
{
        (void)flags;
        START_SYSCALL(SYS_OPEN)
                RBX(path)
        END_SYSCALL

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int close(int fd)
{
        START_SYSCALL(SYS_CLOSE)
                RBX(fd)
        END_SYSCALL

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
void *lastpg(int pages)
{
        START_SYSCALL(SYS_LASTPG)
                RBX(pages)
        END_SYSCALL

        void *ret = NULL;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int64_t getcputime(void)
{
        SYSCALL_NOPARAM(SYS_GETCPUTIME);

        int64_t ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}
/* ------------------------------------------------------------------------------------------------- */

int rm(const char *path)
{
        START_SYSCALL(SYS_RM)
                RBX(path)
        END_SYSCALL

        int ret = 0;
        GET_SYS_RETVAL(ret);
        return ret;
}

#ifdef __cplusplus
}
#endif