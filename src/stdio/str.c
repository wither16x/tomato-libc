#include "stdio.h"
#include "string.h"
#include "unistd.h"

#ifdef __cplusplus
extern "C"
#endif

/* ------------------------------------------------------------------------------------------------- */
int puts(const char *s)
{
        const char *newline = "\n";

        write(stdout->fd, (const void *)s, strlen(s));
        write(stdout->fd, (const void *)newline, strlen(newline));

        return 0;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif