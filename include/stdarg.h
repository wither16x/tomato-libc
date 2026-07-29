#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define va_list                 __builtin_va_list
#define va_start(ap, args)      __builtin_va_start(ap, args)
#define va_end(args)            __builtin_va_end(args)
#define va_arg(ap, t)           __builtin_va_arg(ap, t)

#ifdef __cplusplus
}
#endif