#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @ps: pointer to the list.
 **/
void free_dlistint(dlistint_t *ps)
{
	dlistint_t *current_node;
	dlistint_t *ff_node;

	if (ps)
	{
		current_node = ps;
		ff_node = ps->next;
		while (ff_node)
		{
			free(current_node);
			current_node = ff_node;
			ff_node = ff_node->next;
		}
		free(current_node);
	}
}
