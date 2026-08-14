#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void tomato_end();

void abort(void)
{
        tomato_end();
}

#ifdef __cplusplus
}
#endif