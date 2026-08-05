#include "time.h"
#include "unistd.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------------------------------- */
clock_t clock(void)
{
        return (clock_t)getcputime();
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif