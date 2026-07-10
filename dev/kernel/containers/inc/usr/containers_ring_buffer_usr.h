#ifndef __CONTAINERS_RING_BUFFER_USR_H__
#define __CONTAINERS_RING_BUFFER_USR_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Defines the structure for a ring buffer container.
 **********************************************************************/
typedef struct
{
    ptr_t        buffer;        /* Pointer to the buffer memory */
    size_t       capacity;      /* Maximum number of elements the buffer can hold */
    size_t       size;          /* Current number of elements in the buffer */
    size_t       element_size;  /* Size of each element stored in the buffer */
    uint32_t     tail;          /* Index of the first element in the buffer */
    uint32_t     head;          /* Index where the next element will be inserted */
    uint32_t     flag;          /* Reserved for future use */
} ring_buffer_t;


/**********************************************************************
 * @brief Initializes a ring buffer container.
 *
 * @param rb Pointer to the ring buffer container to be initialized.
 * @param buffer Buffer used to store data in ring buffer.
 * @param capacity The maximum number of elements the buffer can hold.
 * @param element_size The size of stored elements.
 * @return None.
 **********************************************************************/
extern void containers_ring_buffer_init(ring_buffer_t *rb, ptr_t buffer, const size_t capacity, const size_t element_size);


/**********************************************************************
 * @brief Pushes an element to the ring buffer.
 *
 * @param rb Ring-buffer to push element to.
 * @param element The new element to store.
 * @return None.
 **********************************************************************/
extern void containers_ring_buffer_push(ring_buffer_t *rb, cptr_t element);


/**********************************************************************
 * @brief Popes an element from the ring buffer.
 *
 * @param rb Ring-buffer to pop element from.
 * @return Popped element, or null pointer if ring buffer is empty.
 **********************************************************************/
extern ptr_t containers_ring_buffer_pop(ring_buffer_t *rb);


/**********************************************************************
 * @brief Popes an element from the ring buffer.
 *
 * @param rb Ring-buffer to pop element from.
 * @return True is ringer is empty, else false.
 **********************************************************************/
extern bool_t containers_ring_buffer_is_empty(const ring_buffer_t *rb);


#endif /* __CONTAINERS_RING_BUFFER_USR_H__ */
