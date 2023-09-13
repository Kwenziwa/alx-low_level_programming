#include "search_algos.h"

/**
 * linear_search - searches for integers in an algorithm
 *
 * @array: input array
 * @size: size of elements in the array
 * @value: value to search in an array
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int v;

	if (array == NULL)
		return (-1);

	for (v = 0; v < (int)size; v++)
	{
		printf("Value checked array[%u] = [%d]\n", v, array[v]);
		if (value == array[v])
			return (v);
	}
	return (-1);
}
