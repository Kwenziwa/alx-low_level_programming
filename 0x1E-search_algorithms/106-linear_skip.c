#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: index of the number in the array
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ser;

	if (list == NULL)
		return (NULL);

	ser = list;

	do {
		list = ser;
		ser = ser->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)ser->index, ser->n);
	} while (ser->express && ser->n < value);

	if (ser->express == NULL)
	{
		list = ser;
		while (ser->next)
			ser = ser->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)ser->index);

	while (list != ser->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
