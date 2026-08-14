#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------------------------------- */
int strcmp(const char *lhs, const char *rhs)
{
        while (*lhs && (*lhs == *rhs)) {
                lhs++;
                rhs++;
        }
        return *(unsigned char *)lhs - *(unsigned char *)rhs;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int strncmp(const char *lhs, const char *rhs, size_t count)
{
        while (count &&  *lhs && (*lhs == *rhs)) {
                ++lhs;
                ++rhs;
                --count;
        }

        if (count == 0)
                return 0;

        return *(unsigned char *)lhs - *(unsigned char *)rhs;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif