#include "lists.h"

/**
 * print_list - Print all the list of a link
 * @h: the list with a type list_t
 * Return: retunrn the printed value
 */

size_t print_list(const list_t *h)
{
	const list_t *tmp;
	size_t count;

	count = 0;
	for (tmp = h; tmp != NULL; tmp = tmp->next)
	{
		count++;
		if (tmp->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", tmp->len, tmp->str);
	}
	return (count);
}
