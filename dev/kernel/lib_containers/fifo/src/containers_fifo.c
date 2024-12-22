#include "containers_fifo.h"

void containers_fifo_init(containers_fifo_t *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

bool_t containers_fifo_is_empty(const containers_fifo_t *queue)
{
    return (bool_t)(queue->size == 0);
}

ptr_t containers_fifo_enqueue(containers_fifo_t *queue, containers_fifo_node_t *new_node, ptr_t data)
{
    ptr_t ptr_to_return = NULL;

    if (queue != NULL)
    {
        if (new_node != NULL)
        {
            new_node->data = data;
            new_node->next = NULL;

            if (queue->size == 0)
            {
                queue->head = new_node;
            }
            else
            {
                queue->tail->next = new_node;
            }

            queue->tail = new_node;
            queue->size++;
            ptr_to_return = new_node;
        }
    }

    return ptr_to_return;
}

ptr_t containers_fifo_dequeue(containers_fifo_t *queue)
{
    ptr_t ptr_to_return = NULL;

    if ((queue != NULL) && (queue->size > 0))
    {
        /* Get the node to remove */
        containers_fifo_node_t *node_to_remove = queue->head;

        /* Update the head of the queue */
        queue->head = node_to_remove->next;

        if (queue->size == 1U)
        {
            queue->tail = NULL;
        }

        queue->size--;
        ptr_to_return = queue->head;
    }

    return ptr_to_return;
}

void containers_fifo_destroy(containers_fifo_t *queue)
{
    if (queue != NULL)
    {
        while (queue->size > 0)
        {
            containers_fifo_dequeue(queue);
        }
    }
}
