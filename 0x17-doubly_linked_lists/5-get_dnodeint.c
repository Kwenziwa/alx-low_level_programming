#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @hl: pointer to the list.
 * @entry: nth node.
 * Return: nth node, if the node doesn't exist, returns NULL.
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *hl, unsigned int entry)
{
	dlistint_t *node = hl;
	unsigned int count = 0;

	while (node && count != entry)
	{
		count++;
		node = node->next;
	}
	if (node && count == entry)
		return (node);
	return (NULL);
}
