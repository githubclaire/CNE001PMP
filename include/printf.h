#ifndef __LIB_PRINTF_H
#define __LIB_PRINTF_H

#include <stdarg.h>
#include "types.h"

#if defined(__cplusplus)
extern "C" {
#endif



#ifdef DEBUG
//int printf(const char *fmt, ...);
int printf(const char *fmt, ...);
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
static inline int printf(const char *fmt, ...)
{
	return 0;
}
#define pr_debug(fmt, ...)
#endif

#if defined(__cplusplus)
}
#endif

#endif
