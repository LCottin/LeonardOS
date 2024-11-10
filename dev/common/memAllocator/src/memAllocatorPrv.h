#ifndef __MEM_ALLOCATOR_PRV_H__
#define __MEM_ALLOCATOR_PRV_H__

#include "types.h"

#define MEM_BLOCK_SIZE sizeof(MemBlock)

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
    bool_t isFree;
    struct MemBlock *next;
} MemBlock;

extern unsigned long int __heap_start;
extern unsigned long int __heap_size;

#endif
