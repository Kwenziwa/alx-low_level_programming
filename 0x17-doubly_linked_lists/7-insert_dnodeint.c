#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node node at a given position
 * in a dlistint_t list.
 * @p: pointer to the list.
 * @ind: position to add the node.
 * @n: data for the new node.
 * Return: the address of the new node, or NULL if it failed
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **p, unsigned int ind, int n)
{
	dlistint_t *auxnode = *p, *nw_node;
	unsigned int indx, count = 0;

	/* create node */
	nw_node = malloc(sizeof(dlistint_t));
	if (nw_node == NULL)
		return (NULL);
	nw_node->n = n;

	/* border case for insert at the beginning */
	if (ind == 0)
	{
		nw_node->prev = NULL;
		nw_node->next = *p;
		if (*p)
			(*p)->prev = nw_node;
		*p = nw_node;
		return (*p);
	}

	/* search of position to insert */
	indx = ind - 1;
	while (auxnode && count != indx)
	{
		count++;
		auxnode = auxnode->next;
	}

	/* general case */
	if (count == indx && auxnode)
	{
		nw_node->prev = auxnode;
		nw_node->next = auxnode->next;
		if (auxnode->next)
			auxnode->next->prev = nw_node;
		auxnode->next = nw_node;
		return (nw_node);
	}
	free(nw_node);
	return (NULL);
}
