#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data (n)
 *                    of a dlistint_t linked list.
 * @head: pointer to firts node.
 * Return: the sum of all the data (n) of a dlistint_t linked list.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *aux = NULL;
    dlistint_t *node = NULL;
    unsigned int index = 0;

    node = malloc(sizeof(dlistint_t));
    if (node == NULL)
    {
        return (NULL);
    }
    aux = *h;
    node->n = n;
    while (index < idx)
    {
        aux = aux->next;
        index++;
    }
    if (aux->next == NULL)
    {
        return (add_dnodeint_end(h, n));
    }
    node->next = aux;
    node->prev = aux->prev;
    aux->prev->next = node;
    aux->prev = node;
    return (node);
}