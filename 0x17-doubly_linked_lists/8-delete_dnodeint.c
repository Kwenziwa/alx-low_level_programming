#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at indx of a dlistint_t list.
 * @pl: pointer to the list.
 * @indx: position of the node to delete.
 * Return: 1 if it succeeded, -1 if it failed.
 **/
int delete_dnodeint_at_index(dlistint_t **pl, unsigned int indx)
{
	dlistint_t *auxnode = *pl;
	dlistint_t *node_delete = *pl;
	unsigned int ix;
	unsigned int count = 0;

	/* border case for empty list */
	if (!(*pl))
		return (-1);

	/* border case for delete at the beginning */
	if (indx == 0)
	{
		*pl = node_delete->next;
		free(node_delete);
		if (*pl)
			(*pl)->prev = NULL;
		return (1);
	}

	/* search of position to delete */
	ix = indx - 1;
	while (auxnode && count != ix)
	{
		count++;
		auxnode = auxnode->next;
	}

	/* general case */
	if (count == ix && auxnode)
	{
		node_delete = auxnode->next;
		if (node_delete->next)
		node_delete->next->prev = auxnode;
		auxnode->next = node_delete->next;
		free(node_delete);
		return (1);
	}

	return (-1);
}
