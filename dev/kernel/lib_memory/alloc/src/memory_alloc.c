#include "memory_alloc.h"
#include "memory_alloc_prv.h"
#include "memory_ops.h"

/* Pointer to the free list (head of heap) */
static MemoryBlock_t *g_p_free_list = NULL;

/* Indicates whether the heap is initialized */
static bool_t g_is_heap_initialized = FALSE;

void memory_init_heap(void)
{
    /* Set pointer to the beginning of the heap */
    g_p_free_list = (MemoryBlock_t *)&__heap_start;

    /* Initializes the first block of the heap */
    g_p_free_list->size    = (size_t)((addr_t)&__heap_size);
    g_p_free_list->next    = NULL;
    g_p_free_list->is_free = TRUE;

    /* Mark heap as initialized */
    g_is_heap_initialized = TRUE;
}

ptr_t memory_alloc(const size_t size)
{
    ptr_t ptr = NULL;

    if (g_is_heap_initialized == FALSE)
    {
        memory_init_heap();
    }

    if (size > 0)
    {
        /* Aligns the requested size */
        size_t aligned_size          = MEMORY_ALIGN(size);
        MemoryBlock_t *current_block = g_p_free_list;

        /* Traverse the free list to find a suitable block */
        while (current_block != NULL)
        {
            if ((current_block->is_free == TRUE) && (current_block->size >= aligned_size))
            {
                /* Check if we can split the block */
                if (current_block->size > (aligned_size + MEMORY_BLOCK_SIZE))
                {
                    /* Split the block */
                    MemoryBlock_t *new_block = (MemoryBlock_t *)((byte_t *)current_block + MEMORY_BLOCK_SIZE + aligned_size);
                    new_block->size          = current_block->size - aligned_size - MEMORY_BLOCK_SIZE;
                    new_block->is_free       = TRUE;
                    new_block->next          = current_block->next;

                    current_block->size = aligned_size;
                    current_block->next = new_block;
                }

                /* Mark block as used */
                current_block->is_free = FALSE;

                /* Set return pointer */
                ptr = (ptr_t)((byte_t *)current_block + MEMORY_BLOCK_SIZE);

                break;
            }

            /* Move to the next block */
            current_block = current_block->next;
        }
    }

    return ptr;
}

ptr_t memory_alloc_and_init(const size_t size, const int8_t value)
{
    /* Allocates the memory */
    ptr_t ptr = memory_alloc(size);

    if (ptr != NULL)
    {
        /* Initialize memory with the given value */
        memory_ops_set(ptr, value, size);
    }

    return ptr;
}
void memory_free(ptr_t ptr)
{
    if (ptr != NULL)
    {
        MemoryBlock_t *block = (MemoryBlock_t *)((byte_t *)ptr - MEMORY_BLOCK_SIZE);
        block->is_free       = TRUE;

        /* Merge adjacent free blocks */
        MemoryBlock_t *current_block = g_p_free_list;
        while (current_block != NULL)
        {
            /* If the current block and the next one are both free, merge them */
            if ((current_block->next != NULL) && (current_block->is_free == TRUE) && (current_block->next->is_free == TRUE))
            {
                current_block->size += current_block->next->size + MEMORY_BLOCK_SIZE;
                current_block->next  = current_block->next->next;
            }
            else
            {
                /* Move to the next block in the free list */
                current_block = current_block->next;
            }
        }
    }
}
