#ifndef __MEMORY_ALLOC_PRV_H__
#define __MEMORY_ALLOC_PRV_H__

#include "types.h"
#include "memory_alloc_lib.h"

#define MEM_BLOCK_SIZE sizeof(MemBlock_t)

/* Define alignment to 8 bytes */
#define ALIGNMENT 8
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

/**
 * @brief Defines the memory block
 *
 */
typedef struct MemBlock
{
    size_t size;
    bool_t is_free;
    struct MemBlock *next;
} MemBlock_t;

extern addr_t __heap_start;
extern addr_t __heap_size;

#endif
