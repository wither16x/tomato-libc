#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
#endif

typedef struct imaxdiv {
        intmax_t quot;
        intmax_t rem;
} imaxdiv_t;

intmax_t imaxabs(intmax_t j);
imaxdiv_t imaxdiv(intmax_t number, intmax_t demon);

#ifdef __cplusplus
}
#endif