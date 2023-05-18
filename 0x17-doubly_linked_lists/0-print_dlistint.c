#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @p_l: pointer to the list.
 * Return: number of nodes.
 **/
size_t print_dlistint(const dlistint_t *p_l)
{
	const dlistint_t *node = p_l;
	size_t count = 0;

	while (node)
	{
		printf("%i\n", node->n);
		count++;
		node = node->next;
	}

	return (count);
}
