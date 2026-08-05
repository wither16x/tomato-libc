#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCKS_PER_SEC          1000

typedef int64_t         clock_t;

clock_t clock(void);

#ifdef __cplusplus
}
#endif