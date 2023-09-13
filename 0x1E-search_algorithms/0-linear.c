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
	int x;

	if (array == NULL)
		return (-1);

	for (x = 0; x < (int)size; x++)
	{
		printf("Value checked array[%u] = [%d]\n", x, array[x]);
		if (value == array[x])
			return (x);
	}
	return (-1);
}
