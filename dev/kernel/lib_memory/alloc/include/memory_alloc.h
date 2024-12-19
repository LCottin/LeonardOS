#ifndef __MEMORY_ALLOC_H__
#define __MEMORY_ALLOC_H__

#include "types.h"

/* Define alignment to ptr size */
#define MEMORY_ALIGNMENT (sizeof(ptr_t))

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * This function allocates a block of memory of the given size and returns a pointer to the beginning of the allocated block.
 * The memory is not initialized to any specific value.
 *
 * @param size The size of the memory block to allocate in bytes.
 * @return A pointer to the beginning of the allocated memory block. If the allocation fails, returns a null pointer.
 */
extern ptr_t memory_alloc(const size_t size);

/**
 * @brief Allocates a block of memory of the specified size and initializes it to the given value.
 *
 * This function allocates a block of memory of the given size and initializes all bytes in the block to the specified value.
 * It returns a pointer to the beginning of the allocated block.
 *
 * @param size The size of the memory block to allocate in bytes.
 * @param value The value to initialize the memory block with.
 * @return A pointer to the beginning of the allocated memory block. If the allocation fails, returns a null pointer.
 */
extern ptr_t memory_alloc_and_init(const size_t size, const int8_t value);

/**
 * @brief Frees the memory block pointed to by the given pointer.
 *
 * This function releases the memory block pointed to by the given pointer, making it available for future allocations.
 * It does not return any value.
 *
 * @param ptr A pointer to the beginning of the memory block to free.
 * @return None.
 */
extern void memory_free(ptr_t ptr);

/**
 * @brief Initializes the heap for memory allocation.
 *
 * This function initializes the heap for memory allocation. It should be called before any other memory allocation functions.
 * It does not return any value.
 *
 * @param None.
 * @return None.
 */
extern void memory_init_heap(void);

#endif /* __MEMORY_ALLOC_H__ */
