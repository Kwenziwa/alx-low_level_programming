#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Jump search algorithm
 * @list: A pointer to the head of the list to search in
 * @size: the number of nodes in list
 * @value: value to search for
 * Return: ix of the number in the array
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t ix, v, j;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	j = (size_t)sqrt((double)size);
	ix = 0;
	v = 0;

	do {
		prev = list;
		v++;
		ix = v * j;

		while (list->next && list->ix < ix)
			list = list->next;

		if (list->next == NULL && ix != list->ix)
			ix = list->ix;

		printf("Value checked at ix [%d] = [%d]\n", (int)ix, list->n);

	} while (ix < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->ix, (int)list->ix);

	for (; prev && prev->ix <= list->ix; prev = prev->next)
	{
		printf("Value checked at ix [%d] = [%d]\n", (int)prev->ix, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
