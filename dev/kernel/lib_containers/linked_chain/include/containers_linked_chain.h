#ifndef __CONTAINERS_LINKED_CHAIN_H__
#define __CONTAINERS_LINKED_CHAIN_H__

#include "types.h"

/**
 * @brief Defines a node structure for a linked chain container.
 *
 * This structure represents a single node in a linked chain, containing a pointer
 * to the data stored in the node and a pointer to the next node in the chain.
 */
typedef struct containers_linked_chain_node
{
    ptr_t data;                                /* Pointer to the data stored in this node */
    struct containers_linked_chain_node *next; /* Pointer to the next node in the linked_chain */
} containers_linked_chain_node_t;

/**
 * @brief Defines the structure for a linked chain container.
 *
 * This structure represents a linked chain container, which maintains a pointer
 * to the first node in the chain and keeps track of the total number of elements.
 */
typedef struct containers_linked_chain
{
    containers_linked_chain_node_t *head; /* Pointer to the first node in the linked_chain */
    size_t size;                          /* Number of elements currently in the linked_chain */
} containers_linked_chain_t;

/**
 * @brief Initializes a linked chain container.
 *
 * This function initializes a new linked chain container, setting up its initial state.
 *
 * @param chain Pointer to the linked chain container to be initialized.
 * @return None.
 */
extern void containers_linked_chain_init(containers_linked_chain_t *chain);

/**
 * @brief Checks if the linked chain is empty.
 *
 * This function determines whether the linked chain contains any elements.
 *
 * @param chain Pointer to the linked chain container.
 * @return true if the linked chain is empty, false otherwise.
 */
extern bool_t containers_linked_chain_is_empty(const containers_linked_chain_t *chain);

/**
 * @brief Inserts a new element into the linked chain at the specified index.
 *
 * This function inserts a new element with the given data at the specified index in the linked chain.
 *
 * @param chain Pointer to the linked chain container.
 * @param data Pointer to the data to be inserted.
 * @param index The index at which to insert the new element.
 * @return Pointer to the inserted data on success, or NULL on failure.
 */
extern ptr_t containers_linked_chain_insert(containers_linked_chain_t *chain, ptr_t data, const size_t index);

/**
 * @brief Removes an element from the linked chain at the specified index.
 *
 * This function removes the element at the specified index from the linked chain.
 *
 * @param chain Pointer to the linked chain container.
 * @param index The index of the element to be removed.
 * @return Pointer to the removed data on success, or NULL if the index is out of bounds.
 */
extern ptr_t containers_linked_chain_remove(containers_linked_chain_t *chain, const size_t index);

/**
 * @brief Retrieves the element at the specified index in the linked chain.
 *
 * This function returns the data stored at the specified index in the linked chain.
 *
 * @param chain Pointer to the linked chain container.
 * @param index The index of the element to retrieve.
 * @return Pointer to the data at the specified index, or NULL if the index is out of bounds.
 */
extern ptr_t containers_linked_chain_get(const containers_linked_chain_t *chain, const size_t index);

/**
 * @brief Returns the number of elements in the linked chain.
 *
 * This function returns the current size of the linked chain.
 *
 * @param chain Pointer to the linked chain container.
 * @return The number of elements in the linked chain.
 */
extern size_t containers_linked_chain_size(const containers_linked_chain_t *chain);

/**
 * @brief Destroys the linked chain and frees all associated memory.
 *
 * This function deallocates all memory used by the linked chain and its elements.
 *
 * @param chain Pointer to the linked chain container to be destroyed.
 * @return None.
 */
extern void containers_linked_chain_destroy(containers_linked_chain_t *chain);

#endif /* __CONTAINERS_LINKED_CHAIN_H__ */
