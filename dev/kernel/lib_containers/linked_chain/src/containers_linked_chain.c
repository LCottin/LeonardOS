#include "containers_linked_chain.h"

void containers_linked_chain_init(containers_linked_chain_t *chain)
{
    chain->head = NULL;
    chain->size = 0;
}

bool_t containers_linked_chain_is_empty(const containers_linked_chain_t *chain)
{
    return (bool_t)(chain->size == 0);
}

ptr_t containers_linked_chain_insert(containers_linked_chain_t *chain, containers_linked_chain_node_t *new_node, ptr_t data, const size_t index)
{
    ptr_t ptr_to_return = NULL;

    if (chain != NULL && (index < chain->size))
    {
        if (new_node!= NULL)
        {
            new_node->data = data;
            new_node->next = NULL;

            if (index == 0)
            {
                new_node->next = chain->head;
                chain->head    = new_node;
            }
            else
            {
                containers_linked_chain_node_t *current_node = chain->head;
                size_t current_index                         = 1U;

                while ((current_node != NULL) && (current_index < index))
                {
                    current_node = current_node->next;
                    current_index++;
                }

                if (current_node != NULL)
                {
                    new_node->next     = current_node->next;
                    current_node->next = new_node;
                }
            }

            chain->size++;
            ptr_to_return = new_node;
        }
    }

    return ptr_to_return;
}

ptr_t containers_linked_chain_remove(containers_linked_chain_t *chain, const size_t index)
{
    ptr_t ptr_to_return = NULL;

    if ((chain != NULL) && (index < chain->size))
    {
        /* Get node to free */
        containers_linked_chain_node_t *node_to_remove = chain->head;

        if (index == 0)
        {
            chain->head    = node_to_remove->next;
            node_to_remove = chain->head;
        }
        else
        {
            containers_linked_chain_node_t *current_node = chain->head;
            size_t current_index                         = 1U;

            while ((current_node != NULL) && (current_index < (index - 1U)))
            {
                current_node = current_node->next;
                current_index++;
            }

            node_to_remove     = current_node->next;
            current_node->next = node_to_remove->next;
        }

        chain->size--;
        ptr_to_return = node_to_remove->data;
    }

    return ptr_to_return;
}

ptr_t containers_linked_chain_get(const containers_linked_chain_t *chain, const size_t index)
{
    ptr_t ptr_to_return = NULL;

    if ((chain!= NULL) && (index < chain->size))
    {
        containers_linked_chain_node_t *current_node = chain->head;
        size_t current_index                         = 0;

        while ((current_node != NULL) && (current_index < index))
        {
            current_node = current_node->next;
            current_index++;
        }

        if (current_node != NULL)
        {
            ptr_to_return = current_node->data;
        }
    }

    return ptr_to_return;
}

size_t containers_linked_chain_size(const containers_linked_chain_t *chain)
{
    return (size_t)chain->size;
}

void containers_linked_chain_destroy(containers_linked_chain_t *chain)
{
    if (chain != NULL)
    {
        while (chain->head != NULL)
        {
            containers_linked_chain_node_t *node_to_remove = chain->head;
            chain->head                                    = node_to_remove->next;
        }

        chain->size = 0;
    }
}
