#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: pointer to the list.
 * Return: number of nodes.
 **/

size_t print_listint(const listint_t *h)
{
	const listint_t *node_num = h;
	size_t cont = 0;

	while (node_num)
	{
		printf("%i\n", node_num->n);
		cont++;
		node_num = node_num->next;
	}

	return (cont);
}
