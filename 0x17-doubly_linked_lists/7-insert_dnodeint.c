#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to firts node.
 * @idx: number of node to add.
 * @n: number.
 * Return:  the address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *aux = NULL;
dlistint_t *node = NULL;
unsigned int index = 0;


aux = *h;
if (idx == 0)
{
return (add_dnodeint(h, n));
}
while (aux->next != NULL && index < idx)
{
aux = aux->next;
index++;
if (aux == NULL)
{
return (NULL);
}
}
node = malloc(sizeof(dlistint_t));
if (node == NULL)
{
return (NULL);
}
node->n = n;
if (aux->next == NULL && index == idx)
{
return (add_dnodeint_end(h, n));
}
node->next = aux;
node->prev = aux->prev;
aux->prev->next = node;
aux->prev = node;
return (node);
}
