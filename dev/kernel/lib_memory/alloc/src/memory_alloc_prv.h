#ifndef __MEMORY_ALLOC_PRV_H__
#define __MEMORY_ALLOC_PRV_H__

#include "memory_alloc.h"
#include "types.h"

#define MEMORY_BLOCK_SIZE (sizeof(memory_block_t))

#define MEMORY_ALIGN(size) (((size) + (MEMORY_ALIGNMENT - 1)) & ~(MEMORY_ALIGNMENT - 1))

/**
 * @brief Defines the memory block
 *
 */
typedef struct memory_block
{
    size_t size;
    bool_t is_free;
    struct memory_block *next;
} memory_block_t;

extern addr_t __heap_start;
extern addr_t __heap_size;

#endif /* __MEMORY_ALLOC_PRV_H__ */
