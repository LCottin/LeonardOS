#ifndef __CONTAINERS_FIFO_H__
#define __CONTAINERS_FIFO_H__

#include "types_usr.h"

/**
 * @brief Represents a node in a FIFO (First-In-First-Out) container.
 *
 * This structure defines a node for use in a FIFO container. Each node
 * contains a pointer to data and a pointer to the next node in the FIFO.
 */
typedef struct containers_fifo_node
{
    ptr_t data;                         /* Pointer to the data stored in this node */
    struct containers_fifo_node *next;  /* Pointer to the next node in the FIFO */
} containers_fifo_node_t;

/**
 * @brief Represents a FIFO (First-In-First-Out) container.
 *
 * This structure defines a FIFO container that manages a linked list of nodes.
 * It keeps track of the head and tail of the list, as well as the total number
 * of elements in the FIFO.
 */
typedef struct containers_fifo
{
    containers_fifo_node_t *head;           /* Pointer to the first node in the FIFO */
    containers_fifo_node_t *tail;           /* Pointer to the last node in the FIFO */
    size_t                  size;           /* Number of elements currently in the FIFO */
    uint8_t                 padding[4];     /* Padding */
} containers_fifo_t;

/**
 * @brief Initializes a FIFO container.
 *
 * This function initializes a FIFO container, setting its head and tail to NULL
 * and its size to 0.
 *
 * @param queue Pointer to the FIFO container to be initialized.
 * @return None.
 */
extern void containers_fifo_init(containers_fifo_t *queue);

/**
 * @brief Checks if a FIFO container is empty.
 *
 * This function checks whether the given FIFO container has any elements.
 *
 * @param queue Pointer to the FIFO container to be checked.
 * @return bool_t Returns TRUE if the FIFO is empty, FALSE otherwise.
 */
extern bool_t containers_fifo_is_empty(const containers_fifo_t *queue);

/**
 * @brief Adds an element to the end of the FIFO container.
 *
 * This function adds a new element to the tail of the FIFO container.
 *
 * @param queue Pointer to the FIFO container.
 * @param new_node Pointer to the node to be added to the FIFO.
 * @param data Pointer to the data to be added to the FIFO.
 * @return ptr_t Pointer to the element added, or NULL if the fifo is not allocated.
 */
extern ptr_t containers_fifo_enqueue(containers_fifo_t *queue, containers_fifo_node_t *new_node, ptr_t data);

/**
 * @brief Removes and returns the first element from the FIFO container.
 *
 * This function removes the element at the head of the FIFO container and returns it.
 *
 * @param queue Pointer to the FIFO container.
 * @return ptr_t Pointer to the last element, or NULL if the FIFO is empty.
 */
extern ptr_t containers_fifo_dequeue(containers_fifo_t *queue);

/**
 * @brief Destroys a FIFO container.
 *
 * This function frees all memory associated with the FIFO container,
 * including all nodes and their data.
 *
 * @param queue Pointer to the FIFO container to be destroyed.
 * @return None.
 */
extern void containers_fifo_destroy(containers_fifo_t *queue);

#endif /* __CONTAINERS_FIFO_H__ */
