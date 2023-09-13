#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  * @array: First array element's pointer
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: -1 if the array is NULL, Otherwise, the index of the value
  * Description: Prints the [sub]array
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t v;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (v = left; v < right; v++)
			printf("%d, ", array[v]);
		printf("%d\n", array[v]);

		v = left + (right - left) / 2;
		if (array[v] == value)
			return (v);
		if (array[v] > value)
			right = v - 1;
		else
			left = v + 1;
	}

	return (-1);
}

/**
  * exponential_search - Searches for a value in a sorted array
  * @array: First array element's pointer
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: -1 if the array is NULL, Otherwise, the index of the value
  * Description: Prints compared value in the array.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t v = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (v = 1; v < size && array[v] <= value; v = v * 2)
			printf("Value checked array[%ld] = [%d]\n", v, array[v]);
	}

	right = v < size ? v : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", v / 2, right);
	return (_binary_search(array, v / 2, right, value));
}
