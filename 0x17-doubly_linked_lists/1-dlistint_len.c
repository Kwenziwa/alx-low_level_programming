#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @p_l: pointer to the list.
 * Return: number of nodes.
 **/
size_t dlistint_len(const dlistint_t *p_l)
{
	const dlistint_t *nd = p_l;
	size_t count = 0;

	while (nd)
	{
		count++;
		nd = nd->next;
	}

	return (count);
}
