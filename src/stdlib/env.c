#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
        There is no shell environment for now.
*/
char *getenv(const char *name)
{
        (void)name;
        return NULL;
}

#ifdef __cplusplus
}
#endif