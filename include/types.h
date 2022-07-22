#ifndef __TYPES_H__
#define __TYPES_H__

#include <stddef.h>
#include <limits.h>
#include <stdint.h>

#ifndef NULL
# define NULL 0
#endif

#define BIT0                    0x00000001
#define BIT1                    0x00000002
#define BIT2                    0x00000004
#define BIT3                    0x00000008
#define BIT4                    0x00000010
#define BIT5                    0x00000020
#define BIT6                    0x00000040
#define BIT7                    0x00000080
#define BIT8                    0x00000100
#define BIT9                    0x00000200
#define BIT10                   0x00000400
#define BIT11                   0x00000800
#define BIT12                   0x00001000
#define BIT13                   0x00002000
#define BIT14                   0x00004000
#define BIT15                   0x00008000
#define BIT16                   0x00010000
#define BIT17                   0x00020000
#define BIT18                   0x00040000
#define BIT19                   0x00080000
#define BIT20                   0x00100000
#define BIT21                   0x00200000
#define BIT22                   0x00400000
#define BIT23                   0x00800000
#define BIT24                   0x01000000
#define BIT25                   0x02000000
#define BIT26                   0x04000000
#define BIT27                   0x08000000
#define BIT28                   0x10000000
#define BIT29                   0x20000000
#define BIT30                   0x40000000
#define BIT31                   0x80000000


#define STATUS_PASS 0
#define STATUS_FAIL 1
#define STATUS_HANG 2

typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;

/* bsd */
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

/* sysv */
typedef unsigned char unchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef unsigned char uchar;


#define cpu_to_le32(x) x //__cpu_to_le32
#define le32_to_cpu(x) x //__le32_to_cpu

typedef unsigned short __u16;
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

typedef        u8 uint8_t;
typedef        u16 uint16_t;
typedef        u32 uint32_t;

#define cpu_to_le16(x) ((u16)(x))


#ifndef _SIZE_T_DEFINED_
typedef unsigned long size_t;
#endif
typedef long ssize_t;
typedef long long off_t;

typedef int status_t;

typedef uintptr_t addr_t;
typedef uintptr_t vaddr_t;
typedef uintptr_t paddr_t;

typedef enum _bool { false, true } bool;

typedef void (*app_entry)(void *);
typedef void (*app_no_args)(void);

#endif //__TYPES_H__

