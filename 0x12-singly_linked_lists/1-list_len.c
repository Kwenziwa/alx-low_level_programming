#include "lists.h"

/**
 * list_len - list all the nodes
 * @h: the list with a type list_t
 * Return: retunrn the printed value
 */

size_t list_len(const list_t *h)
{
	const list_t *tmp;
	size_t count;

	count = 0;
	for (tmp = h; tmp != NULL; tmp = tmp->next)
	{
		count++;
	}
	return (count);
}
