#include "lists.h"

/**
 * add_node - Add a node to the begining
 * @head: the pointer
 * @str: the string
 * Return: retunrn the printed value
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *tmp;
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
	tmp->next = *head;
	*head = tmp;
	return (*head);
}
