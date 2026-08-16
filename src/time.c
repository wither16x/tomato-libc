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

time_t time(time_t *tloc)
{
        (void)tloc;
        return -1;
}

int clock_gettime(int clk_id, struct timespec *tp)
{
        (void)clk_id;
        (void)tp;
        return -1;
}

int gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz)
{
        (void)tv;
        (void)tz;
        return -1;
}

#ifdef __cplusplus
}
#endif