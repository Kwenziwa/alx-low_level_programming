#include "lists.h"

/**
 * add_dnodeint - adds a newn node at the beginning of a dlistint_t list.
 * @head: pointer to the first element of the list.
 * @n: int to set in the newn node.
 * Return: address of the newn element, or NULL if it failed
 **/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newn;

	newn = malloc(sizeof(dlistint_t));
	if (newn == NULL)
		return (NULL);

	newn->n = n;
	newn->prev = NULL;
	newn->next = *head;
	if (*head)
		(*head)->prev = newn;
	*head = newn;

	return (newn);
}
