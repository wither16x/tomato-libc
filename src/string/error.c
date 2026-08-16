#include "string.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

char *strerror(int errnum)
{
        // TODO: add a message table instead of... this...
        static char buf[32];
        snprintf(buf, sizeof(buf), "error %d", errnum);
        return buf;
}

#ifdef __cplusplus
}
#endif