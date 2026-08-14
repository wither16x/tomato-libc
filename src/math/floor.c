#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------------------------------- */
double floor(double arg)
{
        long long n = (long long)arg;
        double d = (double)n;

        if (d == arg || arg >= 0)
                return d;
        else
                return d - 1;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif