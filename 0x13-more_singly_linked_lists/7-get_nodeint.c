#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the list.
 * @index: nth node.
 * Return: nth node, if the node doesn't exist, returns NULL.
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int i)
{
	listint_t *node = head;
	unsigned int cont = 0;

	while (node && cont != i)
	{
		cont++;
		node = node->next;
	}
	if (node && cont == i)
		return (node);
	return (NULL);
}
