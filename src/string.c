#include "string.h"
#include "stdint.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------------------------------- */
size_t strlen(const char *s)
{
        size_t i = 0;
        while (s[i] != '\0')
                i++;
        return i;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
void *memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
        uint8_t *__restrict pdest = (uint8_t *__restrict)dest;
        const uint8_t *__restrict psrc = (const uint8_t *__restrict)src;

        for (size_t i = 0; i < n; i++)
                pdest[i] = psrc[i];

        return dest;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
void *memset(void *s, int c, size_t n)
{
        uint8_t *p = (uint8_t *)s;

        for (size_t i = 0; i < n; i++)
                p[i] = (uint8_t)c;

        return s;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
void *memmove(void *dest, const void *src, size_t n)
{
        uint8_t *pdest = (uint8_t *)dest;
        const uint8_t *psrc = (const uint8_t *)src;

        if ((uintptr_t)src > (uintptr_t)dest) {
                for (size_t i = 0; i < n; i++)
                        pdest[i] = psrc[i];
        } else if ((uintptr_t)src < (uintptr_t)dest) {
                for (size_t i = n; i > 0; i--)
                        pdest[i-1] = psrc[i-1];
        }

        return dest;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
int memcmp(const void *s1, const void *s2, size_t n)
{
        const uint8_t *p1 = (const uint8_t *)s1;
        const uint8_t *p2 = (const uint8_t *)s2;

        for (size_t i = 0; i < n; i++) {
                if (p1[i] != p2[i])
                        return p1[i] < p2[i] ? -1 : 1;
        }

        return 0;
}
/* ------------------------------------------------------------------------------------------------- */

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

/* ------------------------------------------------------------------------------------------------- */
char *strcpy(char *dest, const char *src)
{
        if (!dest)
                return NULL;

        char *p = dest;

        while (*src != '\0') {
                *dest = *src;
                dest++;
                src++;
        }

        *dest = '\0';

        return p;
}
/* ------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------- */
char *strncpy(char *restrict dest, const char *restrict src, size_t count)
{
        if(!dest)
                return NULL;

        char *p = dest;

        while (*src && count--) {
                *dest = *src;
                dest++;
                src++;
        }

        *dest = '\0';

        return p;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif