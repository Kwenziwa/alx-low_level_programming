#include "lists.h"

/**
 * add_node_end - Add a node to the begining
 * @head: the pointer
 * @str: the string
 * Return: retunrn the printed value
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *tmp, *traverse;
	int len = 0;

	while (str[len])
	{
		len++;
	}
	tmp =  malloc(sizeof(list_t));
	if (tmp == NULL)
		return (NULL);
	tmp->len = len;
	tmp->str = strdup(str);
	tmp->next = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return (*head);
	}
	for (traverse = *head; traverse != NULL; traverse = traverse->next)
	{
		if (traverse->next == NULL)
		{
			traverse->next = tmp;
			break;
		}
	}
	return (*head);
}
