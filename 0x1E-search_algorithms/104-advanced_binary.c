#include "search_algos.h"

/**
 * rec_search - Binary search algorithm
 * @array: input array
 * @size: size ofthe elements in the array
 * @value: value to search for
 * Return: index of the number in the array
 */
int rec_search(int *array, size_t size, int value)
{
	size_t part = size / 2;
	size_t x;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (x = 0; x < size; x++)
		printf("%s %d", (x == 0) ? ":" : ",", array[x]);

	printf("\n");

	if (part && size % 2 == 0)
		part--;

	if (value == array[part])
	{
		if (part > 0)
			return (rec_search(array, part + 1, value));
		return ((int)part);
	}

	if (value < array[part])
		return (rec_search(array, part + 1, value));

	part++;
	return (rec_search(array + part, size - part, value) + part);
}

/**
 * advanced_binary - return the index of the number
 * @array: input array
 * @size: size of the elements in the array
 * @value: value to search for
 * Return: index of the number in the array
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
