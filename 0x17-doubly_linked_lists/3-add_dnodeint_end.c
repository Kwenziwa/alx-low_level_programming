#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @p_e: pointer to the first element of the list.
 * @n: int to set in the new node.
 * Return: address of the new element, or NULL if it failed
 **/
dlistint_t *add_dnodeint_end(dlistint_t **p_e, const int n)
{
	dlistint_t *new_n, *ax = *p_e;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);
	new_n->n = n;
	new_n->next = NULL;

	if (ax)
	{
		while (ax->next)
			ax = ax->next;
		new_n->prev = ax;
		ax->next = new_n;
	}
	else
	{
		*p_e = new_n;
		new_n->prev = NULL;
	}

	return (new_n);
}
