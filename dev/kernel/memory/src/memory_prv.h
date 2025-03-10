#ifndef __MEMORY_PRV_H__
#define __MEMORY_PRV_H__

#include "memory.h"
#include "types_usr.h"

/**
 * @brief Size of a memory block structure.
 */
#define MEMORY_BLOCK_SIZE (sizeof(memory_block_t))

/**
 * @brief Aligns a size to the nearest memory alignment boundary.
 *
 * @param size The size to align.
 * @return The aligned size.
 */
#define MEMORY_ALIGN(size) (((size) + (MEMORY_ALIGNMENT - 1)) & ~(MEMORY_ALIGNMENT - 1))

/**
 * @brief Defines the memory block structure.
 *
 * This structure represents a block of memory in the heap. It contains
 * the size of the block, a flag indicating whether the block is free,
 * and a pointer to the next block in the heap.
 */
typedef struct memory_block
{
    size_t size;               /* Size of the memory block */
    bool_t is_free;            /* Flag indicating if the block is free */
    struct memory_block *next; /* Pointer to the next memory block */
} memory_block_t;

/**
 * @brief Start address of the heap.
 */
extern addr_t __heap_start;

/**
 * @brief Size of the heap.
 */
extern addr_t __heap_size;

#endif /* __MEMORY_PRV_H__ */
