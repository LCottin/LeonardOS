#ifndef __TYPES_H__
#define __TYPES_H__

/* Signed types */
typedef char      int8_t;
typedef short     int16_t;
typedef int       int32_t;
typedef long      int64_t;

/* Unsigned types */
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long      uint64_t;

/* Float types */
typedef float  float32_t;
typedef double float64_t;

/* Pointer types */
typedef void*       ptr_t;
typedef const void* cptr_t;

/* Specific types */
typedef uint32_t size_t;
typedef int8_t   char_t;

/* Boolean type */
typedef enum
{
    FALSE,
    TRUE,   /* Other value are considered as true */
} bool_t;

/* Maximum value for types */
#define NULL       0
#define INT8_MAX   0x7F
#define UINT8_MAX  0xFF
#define INT16_MAX  0x7FFF
#define UINT16_MAX 0xFFFF
#define INT32_MAX  0x7FFFFFFF
#define UINT32_MAX 0xFFFFFFFFU
#define INT64_MAX  0x7FFFFFFFFFFFFFFFLL
#define UINT64_MAX 0xFFFFFFFFFFFFFFFFULL

#endif
