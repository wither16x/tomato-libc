#include "stdlib.h"
#include "ctype.h"
#include "math.h"

#ifdef __cplusplus
extern "C"
#endif

/* ------------------------------------------------------------------------------------------------- */
double strtod(const char *str, char **str_end)
{
        const char *p = str;
        while (isspace((unsigned char)*p))
                p++;

        int sign = 1;
        if (*p == '+' || *p == '-') {
                if (*p == '-')
                        sign = -1;
                p++;
        }

        double mantissa = 0.0;
        int any_digits = 0;

        while (isdigit((unsigned char)*p)) {
                mantissa = mantissa * 10.0 + (*p - '0');
                p++;
                any_digits = 1;
        }

        if (*p == '.') {
                p++;
                double frac = 0.1;
                while (isdigit((unsigned char)*p)) {
                        mantissa += (*p - '0') * frac;
                        frac *= 0.1;
                        p++;
                        any_digits = 1;
                }
        }

        if (!any_digits) {
                if (str_end)
                        *str_end = (char *)str;
                return 0.0;
        }

        int exponent = 0;
        if (*p == 'e' || *p == 'E') {
                const char *exp_start = p;
                p++;

                int exp_sign = 1;
                if (*p == '+' || *p == '-') {
                        if (*p == '-')
                                exp_sign = -1;
                        p++;
                }
                if (isdigit((unsigned char)*p)) {
                        int exp_val = 0;
                        while (isdigit((unsigned char)*p)) {
                                exp_val = exp_val * 10 + (*p - '0');
                                p++;
                        }
                        exponent = exp_sign * exp_val;
                } else {
                        p = exp_start;
                }
        }

        double result = sign * mantissa;
        if (exponent != 0)
                result *= pow(10.0, exponent);

        if (str_end)
                *str_end = (char *)p;

        return result;
}
/* ------------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif