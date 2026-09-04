#ifndef __SYSCALL_TYPES_H__
#define __SYSCALL_TYPES_H__

#include "types_usr.h"
#include "strings_utils_usr.h"

/**********************************************************************
 * @brief Structure for printing an integer.
 **********************************************************************/
typedef struct
{
    int32_t              value;  /* Integer value to print */
    strings_utils_base_t base;   /* Base for printing */
} syscall_print_int_t;


#endif /* __SYSCALL_TYPES_H__ */
