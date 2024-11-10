#include "memAllocator.h"
#include "memAllocatorPrv.h"
#include "memory.h"

/* Pointer to the free list (head of heap) */
static MemBlock *freeList = NULL;

/* Indicates whether the heap is initialized */
static bool_t heapInitialized = FALSE;

void initHeap(void)
{
    /* Set pointer to the beginning of the heap */
    freeList = (MemBlock *)&__heap_start;

    /* Initializes the first block of the heap */
    freeList->size   = (size_t)((addr_t)&__heap_size);
    freeList->next   = NULL;
    freeList->isFree = TRUE;

    /* Mark heap as initialized */
    heapInitialized = TRUE;
}

ptr_t memAlloc(const size_t size)
{
    ptr_t ptr = NULL;

    if (heapInitialized == FALSE)
    {
        initHeap();
    }

    if (size > 0)
    {
        /* Aligns the requested size */
        size_t alignedSize = ALIGN(size);
        MemBlock *block    = freeList;

        /* Traverse the free list to find a suitable block */
        while (block != NULL)
        {
            if ((block->isFree == TRUE) && (block->size >= alignedSize))
            {
                /* Check if we can split the block */
                if (block->size > (alignedSize + MEM_BLOCK_SIZE))
                {
                    /* Split the block */
                    MemBlock *newBlock = (MemBlock *)((byte_t *)block + MEM_BLOCK_SIZE + alignedSize);
                    newBlock->size     = block->size - alignedSize - MEM_BLOCK_SIZE;
                    newBlock->isFree   = TRUE;
                    newBlock->next     = block->next;

                    block->size = alignedSize;
                    block->next = newBlock;
                }

                /* Mark block as used */
                block->isFree = FALSE;

                /* Set return pointer */
                ptr = (ptr_t)((byte_t *)block + MEM_BLOCK_SIZE);

                break;
            }

            /* Move to the next block */
            block = block->next;
        }
    }

    return ptr;
}

ptr_t memInitAlloc(const size_t size, const int8_t value)
{
    /* Allocates the memory */
    ptr_t ptr = memAlloc(size);

    if (ptr != NULL)
    {
        /* Initialize memory with the given value */
        memset(ptr, value, size);
    }

    return ptr;
}

void memFree(ptr_t ptr)
{
    if (ptr != NULL)
    {
        MemBlock *block = (MemBlock *)((byte_t *)ptr - MEM_BLOCK_SIZE);
        block->isFree   = TRUE;

        /* Merge adjacent free blocks */
        MemBlock *current = freeList;
        while (current != NULL && current->next != NULL)
        {
            if (current->isFree && current->next->isFree)
            {
                /* Merge the current block with the next free block */
                current->size += MEM_BLOCK_SIZE + current->next->size;
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
    }
}
