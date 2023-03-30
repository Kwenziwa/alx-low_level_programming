#include "lists.h"

/**
 * free_list - Free all the list with return NULL
 * @head: the head pointer
 * Return: retunrn the printed value
 */

void free_list(list_t *head)
{
	if (head != NULL)
	{
		if (head->str != NULL)
			free(head->str);
		free_list(head->next);
		free(head);
	}

}
