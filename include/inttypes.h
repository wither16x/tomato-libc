#pragma once

#include <stdint.h>

#define PRIdMAX "lld"
#define PRIiMAX "lld"
#define PRIoMAX "llo"
#define PRIuMAX "llu"
#define PRIxMAX "llx"
#define PRIXMAX "llX"

#define PRId8   "hhd"
#define PRId16  "hd"
#define PRId32  "d"
#define PRId64  "lld"

#define PRIu8   "hhu"
#define PRIu16  "hu"
#define PRIu32  "u"
#define PRIu64  "llu"

#define PRIx8   "hhx"
#define PRIx16  "hx"
#define PRIx32  "x"
#define PRIx64  "llx"

#ifdef __cplusplus
extern "C" {
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