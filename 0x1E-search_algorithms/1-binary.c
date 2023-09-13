#include "search_algos.h"

/**
  * binary_search - Searches for a value in a sorted array
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value in the array to search for.
  *
  * Return: -1 if the value is null, Otherwise, the index
  *
  * Description: Prints the [sub]array
  */
int binary_search(int *array, size_t size, int value)
{
	size_t x, lft, rght;

	if (array == NULL)
		return (-1);

	for (lft = 0, rght = size - 1; rght >= lft;)
	{
		printf("Searching in array: ");
		for (x = lft; x < rght; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);

		x = lft + (rght - lft) / 2;
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			rght = x - 1;
		else
			lft = x + 1;
	}

	return (-1);
}
